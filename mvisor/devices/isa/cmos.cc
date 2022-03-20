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

#include <cstring>
#include <ctime>
#include "logger.h"
#include "device_manager.h"
#include "states/cmos.pb.h"

#define RTC_BASE_ADDRESS 0x70

/*
 * MC146818 RTC registers
 */
#define RTC_SECONDS       0x00
#define RTC_SECONDS_ALARM 0x01
#define RTC_MINUTES       0x02
#define RTC_MINUTES_ALARM 0x03
#define RTC_HOURS         0x04
#define RTC_HOURS_ALARM   0x05
#define RTC_DAY_OF_WEEK   0x06
#define RTC_DAY_OF_MONTH  0x07
#define RTC_MONTH         0x08
#define RTC_YEAR          0x09
#define RTC_CENTURY       0x32

#define RTC_REG_A   0x0A
#define RTC_REG_B   0x0B
#define RTC_REG_C   0x0C
#define RTC_REG_D   0x0D

#define CMOS_FLOPPY_TYPE  0x10

/*
 * Register D Bits1
 */
#define RTC_REG_D_VRT (1 << 7)

static inline unsigned char bin2bcd(unsigned val)
{
  return ((val / 10) << 4) + val % 10;
}


class Cmos : public Device {
 private:
  bool      non_maskable_interrupt_disabled_;
  uint8_t   cmos_index_;
  uint8_t   cmos_data_[128];

 public:

  Cmos() {
    AddIoResource(kIoResourceTypePio, RTC_BASE_ADDRESS, 2, "CMOS");
  }

  void Reset() {
    non_maskable_interrupt_disabled_ = false;
    cmos_index_ = 0;
    bzero(cmos_data_, sizeof(cmos_data_));
  }

  bool SaveState(MigrationWriter* writer) {
    CmosState state;
    state.set_index(cmos_index_);
    state.set_data(cmos_data_, sizeof(cmos_data_));
    state.set_nmi_disabled(non_maskable_interrupt_disabled_);
    writer->WriteProtobuf("CMOS", state);
    return Device::SaveState(writer);
  } 

  bool LoadState(MigrationReader* reader) {
    CmosState state;
    if (!reader->ReadProtobuf("CMOS", state)) {
      return false;
    }
    non_maskable_interrupt_disabled_ = state.nmi_disabled();
    cmos_index_ = state.index();
    memcpy(cmos_data_, state.data().data(), sizeof(cmos_data_));
    return Device::LoadState(reader);
  }

  void Read(const IoResource* resource, uint64_t offset, uint8_t* data, uint32_t size) {
    if (offset == 0) {
      *data = 0xFF;
      return;
    }

    time_t timestamp;
    time(&timestamp);
    struct tm* tm = gmtime(&timestamp);

    switch (cmos_index_) {
    case RTC_SECONDS:
      *data = bin2bcd(tm->tm_sec);
      break;
    case RTC_MINUTES:
      *data = bin2bcd(tm->tm_min);
      break;
    case RTC_HOURS:
      *data = bin2bcd(tm->tm_hour);
      break;
    case RTC_DAY_OF_WEEK:
      *data = bin2bcd(tm->tm_wday + 1);
      break;
    case RTC_DAY_OF_MONTH:
      *data = bin2bcd(tm->tm_mday);
      break;
    case RTC_MONTH:
      *data = bin2bcd(tm->tm_mon + 1);
      break;
    case RTC_YEAR: {
      int year;
      year = tm->tm_year + 1900;
      *data = bin2bcd(year % 100);
      break;
    }
    case RTC_CENTURY: {
      int year;
      year = tm->tm_year + 1900;
      *data = bin2bcd(year / 100);
      break;
    }
    case CMOS_FLOPPY_TYPE:
      if (manager_->LookupDeviceByClass("Floppy")) {
        // 4 - 1.44MB, 3.5" - 2 heads, 80 tracks, 18 sectors
        *data = 0x40;
      }
      break;
    default:
      *data = cmos_data_[cmos_index_];
      break;
    }
  }

  void Write(const IoResource* resource, uint64_t offset, uint8_t* data, uint32_t size) {
    if (offset == 0) { /* index register */
      uint8_t value = *data;
      cmos_index_  = value & ~(1UL << 7);
      non_maskable_interrupt_disabled_ = value & (1UL << 7);
      return;
    }

    switch (cmos_index_) {
    case RTC_REG_C:
    case RTC_REG_D:
      /* Read-only */
      break;
    default:
      cmos_data_[cmos_index_] = *data;
      break;
    }
    return;
  }


};

DECLARE_DEVICE(Cmos);
