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
#include "logger.h"
#include "device_manager.h"
#include "pci_device.h"
#include "states/pci_host.pb.h"

#define MCH_CONFIG_ADDR             0xCF8
#define MCH_CONFIG_DATA             0xCFC

#define MCH_PCIEXBAR                0x60
#define MCH_PCIEXBAR_SIZE           0x04

/*
 * PCI express ECAM (Enhanced Configuration Address Mapping) format.
 * AKA mmcfg address
 * bit 20 - 28: bus number
 * bit 15 - 19: device number
 * bit 12 - 14: function number
 * bit  0 - 11: offset in configuration space of a given device
 */
#define PCIE_MMCFG_SIZE_MAX             (1ULL << 29)
#define PCIE_MMCFG_SIZE_MIN             (1ULL << 20)
#define PCIE_MMCFG_BUS_BIT              20
#define PCIE_MMCFG_BUS_MASK             0x1ff
#define PCIE_MMCFG_DEVFN_BIT            12
#define PCIE_MMCFG_DEVFN_MASK           0xff
#define PCIE_MMCFG_CONFOFFSET_MASK      0xfff
#define PCIE_MMCFG_BUS(addr)            (((addr) >> PCIE_MMCFG_BUS_BIT) & \
                                         PCIE_MMCFG_BUS_MASK)
#define PCIE_MMCFG_DEVFN(addr)          (((addr) >> PCIE_MMCFG_DEVFN_BIT) & \
                                         PCIE_MMCFG_DEVFN_MASK)
#define PCIE_MMCFG_CONFOFFSET(addr)     ((addr) & PCIE_MMCFG_CONFOFFSET_MASK)

class PciHost : public PciDevice {
 private:
  uint64_t          pcie_xbar_base_ = 0;
  PciConfigAddress  config_addr_;

 public:
  PciHost() {
    devfn_ = PCI_MAKE_DEVFN(0, 0);
    is_pcie_ = true;
    
    pci_header_.vendor_id = 0x8086;
    pci_header_.device_id = 0x29C0;
    pci_header_.class_code = 0x060000;
    pci_header_.header_type = PCI_HEADER_TYPE_NORMAL;
    pci_header_.subsys_vendor_id = 0x1AF4;
    pci_header_.subsys_id = 0x1100;

    AddIoResource(kIoResourceTypePio, MCH_CONFIG_ADDR, 4, "MCH Config Base");
    AddIoResource(kIoResourceTypePio, MCH_CONFIG_DATA, 4, "MCH Config Data");
  }

  virtual bool SaveState(MigrationWriter* writer) {
    MchState state;
    state.set_config(config_addr_.data);
    writer->WriteProtobuf("MCH", state);
    return PciDevice::SaveState(writer);
  }

  virtual bool LoadState(MigrationReader* reader) {
    if (!PciDevice::LoadState(reader)) {
      return false;
    }
    MchState state;
    if (!reader->ReadProtobuf("MCH", state)) {
      return false;
    }
    config_addr_.data = state.config();
    MchUpdatePcieXBar();
    return true;
  }

  void MchUpdatePcieXBar() {
    uint32_t pciexbar = *(uint32_t*)(pci_header_.data + MCH_PCIEXBAR);
    int enable = pciexbar & 1;
    if (!!enable != !!pcie_xbar_base_) {
      uint32_t base = pciexbar & Q35_MASK(64, 35, 28);
      uint64_t length = (1LL << 20) * 256;
      if (pcie_xbar_base_) {
        RemoveIoResource(kIoResourceTypeMmio, pcie_xbar_base_);
        pcie_xbar_base_ = 0;
      }
      if (enable) {
        AddIoResource(kIoResourceTypeMmio, base, length, "PCIE XBAR");
        pcie_xbar_base_ = base;
      }
    }
  }

  void Write(const IoResource* resource, uint64_t offset, uint8_t* data, uint32_t size) {
    if (resource->base == MCH_CONFIG_ADDR) {
      uint8_t* pointer = (uint8_t*)&config_addr_.data + offset;
      memcpy(pointer, data, size);
    
    } else if (resource->base == MCH_CONFIG_DATA) {
      MV_ASSERT(size <= 4);
      
      PciDevice* pci_device = manager_->LookupPciDevice(config_addr_.bus, config_addr_.devfn);
      if (pci_device) {
        config_addr_.reg_offset = offset;
        pci_device->WritePciConfigSpace(
          config_addr_.data & PCI_DEVICE_CONFIG_MASK, data, size);
      } else {
        MV_LOG("failed to lookup pci bus=0x%x devfn=0x%02x",
          config_addr_.bus, config_addr_.devfn);
      }
    
    } else if (pcie_xbar_base_ && resource->base == pcie_xbar_base_) {
      uint8_t bus = PCIE_MMCFG_BUS(resource->base + offset);
      uint8_t devfn = PCIE_MMCFG_DEVFN(resource->base + offset);
      PciDevice* pci_device = manager_->LookupPciDevice(bus, devfn);
      uint64_t address = PCIE_MMCFG_CONFOFFSET(resource->base + offset);
      if (pci_device) {
        pci_device->WritePciConfigSpace(address, data, size);
      } else {
        MV_LOG("failed to lookup pci bus=0x%x devfn=0x%02x", bus, devfn);
      }
    
    } else {
      MV_PANIC("not implemented base=0x%lx offset=0x%lx data=0x%x size=%x",
        resource->base, offset, *(uint32_t*)data, size);
    }
  }

  void Read(const IoResource* resource, uint64_t offset, uint8_t* data, uint32_t size) {
    if (resource->base == MCH_CONFIG_ADDR) {
      uint8_t* pointer = (uint8_t*)&config_addr_.data + offset;
      memcpy(data, pointer, size);
    
    } else if (resource->base == MCH_CONFIG_DATA) {
      if (size > 4)
        size = 4;
      
      PciDevice* pci_device = manager_->LookupPciDevice(config_addr_.bus, config_addr_.devfn);
      if (pci_device) {
        config_addr_.reg_offset = offset;
        pci_device->ReadPciConfigSpace(
          config_addr_.data & PCI_DEVICE_CONFIG_MASK, data, size);
      } else {
        memset(data, 0xff, size);
      }
    
    } else if (pcie_xbar_base_ && resource->base == pcie_xbar_base_) {
      uint8_t bus = PCIE_MMCFG_BUS(resource->base + offset);
      uint8_t devfn = PCIE_MMCFG_DEVFN(resource->base + offset);
      PciDevice* pci_device = manager_->LookupPciDevice(bus, devfn);
      uint64_t address = PCIE_MMCFG_CONFOFFSET(resource->base + offset);
      if (pci_device) {
        pci_device->ReadPciConfigSpace(address, data, size);
      } else {
        memset(data, 0xff, size);
      }
    
    } else {
      MV_PANIC("not implemented base=0x%lx offset=0x%lx data=0x%x size=%x",
        resource->base, offset, *(uint32_t*)data, size);
    }
  }

  void WritePciConfigSpace(uint64_t offset, uint8_t* data, uint32_t length) {
    PciDevice::WritePciConfigSpace(offset, data, length);
    if (ranges_overlap(offset, length, MCH_PCIEXBAR, MCH_PCIEXBAR_SIZE)) {
      MchUpdatePcieXBar();
    
    } else if (ranges_overlap(offset, length, 0x9D, 2)) {
      MV_PANIC("SMRAM not supported yet");
    
    }
  }

};

DECLARE_DEVICE(PciHost);
