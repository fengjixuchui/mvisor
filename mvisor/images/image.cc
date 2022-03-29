/* 
 * MVisor
 * Copyright (C) 2021 Terrence <terrence@tenclass.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "disk_image.h"
#include <cstdlib>
#include "logger.h"
#include "utilities.h"
#include "device_manager.h"
#include "qcow2.h"

DiskImage::DiskImage() {
}

DiskImage::~DiskImage()
{
  if (!finalized_) {
    Finalize();
  }
}

DiskImage* DiskImage::Create(Device* device, std::string path, bool readonly) {
  DiskImage* image;
  if (path.find(".qcow2") != std::string::npos) {
    image = dynamic_cast<DiskImage*>(Object::Create("qcow2-image"));
    /* If snapshot is on, create a new image and the original one is readonly */
    bool image_snapshot = device->has_key("snapshot") && std::get<bool>((*device)["snapshot"]);
    if (image_snapshot) {
      image->snapshot_ = true;
      std::string backing_filepath = path;
      path = std::tmpnam(nullptr);
      path += ".qcow2";
      Qcow2Image::CreateImageWithBackingFile(path, backing_filepath);
    }
  } else {
    image = dynamic_cast<DiskImage*>(Object::Create("raw-image"));
  }
  MV_ASSERT(image);
  image->filepath_ = path;
  image->readonly_ = readonly;
  image->device_ = device;
  image->Initialize();
  
  image->io_ = device->manager()->io();
  image->worker_thread_ = std::thread(&DiskImage::WorkerProcess, image);
  return image;
}

void DiskImage::Connect() {
  if (!initialized_) {
    initialized_ = true;
    std::string path = std::get<std::string>(key_values_["path"]);
    readonly_ = std::get<bool>(key_values_["readonly"]);
    Initialize();
  }
}

ssize_t DiskImage::Discard(off_t position, size_t length, bool write_zeros) {
  return 0;
}

void DiskImage::Finalize() {
  finalized_ = true;

  if (worker_thread_.joinable()) {
    worker_cv_.notify_all();
    worker_thread_.join();
  }

  if (snapshot_) {
    remove(filepath_.c_str());
  }
}


void DiskImage::WorkerProcess() {
  SetThreadName("mvisor-disk");
  
  io_->RegisterDiskImage(this);

  while (!finalized_) {
    std::unique_lock<std::mutex> lock(worker_mutex_);
    worker_cv_.wait(lock, [this]() {
      return !worker_queue_.empty() || finalized_;
    });

    if (worker_queue_.empty()) {
      break;
    }
    auto callback = worker_queue_.front();
    lock.unlock();
  
    callback();

    /* Only remove item after job is done.
     * Remember to lock mutex again when operating on worker_queue_
     */
    lock.lock();
    worker_queue_.pop_front();
  }
  
  io_->UnregisterDiskImage(this);
}

void DiskImage::ReadAsync(void *buffer, off_t position, size_t length, IoCallback callback) {
  worker_mutex_.lock();
  worker_queue_.push_back([this, buffer, position, length, callback]() {
    auto ret = Read(buffer, position, length);
    io_->Schedule([=]() { callback(ret); });
  });
  worker_mutex_.unlock();
  worker_cv_.notify_all();
}

void DiskImage::WriteAsync(void *buffer, off_t position, size_t length, IoCallback callback) {
  if (readonly_) {
    return callback(0);
  }

  worker_mutex_.lock();
  worker_queue_.push_back([this, buffer, position, length, callback]() {
    auto ret = Write(buffer, position, length);
    io_->Schedule([=]() { callback(ret); });
  });
  worker_mutex_.unlock();
  worker_cv_.notify_all();
}

void DiskImage::DiscardAsync(off_t position, size_t length, bool write_zeros, IoCallback callback) {
  if (readonly_) {
    return callback(0);
  }

  worker_mutex_.lock();
  worker_queue_.push_back([this, position, length, write_zeros, callback]() {
    auto ret = Discard(position, length, write_zeros);
    io_->Schedule([=]() { callback(ret); });
  });
  worker_mutex_.unlock();
  worker_cv_.notify_all();
}

void DiskImage::FlushAsync(IoCallback callback) {
  worker_mutex_.lock();
  worker_queue_.push_back([this, callback]() {
    auto ret = Flush();
    io_->Schedule([=]() {
      callback(ret);
    });
  });
  worker_mutex_.unlock();
  worker_cv_.notify_all();
}

bool DiskImage::busy() {
  std::lock_guard<std::mutex> lock(worker_mutex_);
  return !worker_queue_.empty();
}
