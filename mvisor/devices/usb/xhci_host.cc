/* 
 * MVisor USB 3.0 XHCI
 * SPEC: <https://www.intel.com/content/dam/www/public/us/en/documents/ \
 *    technical-specifications/extensible-host-controler-interface-usb-xhci.pdf>
 * Copyright (C) 2022 Terrence <terrence@tenclass.com>
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
#include <vector>
#include <array>
#include <set>
#include <chrono>

#include "pci_device.h"
#include "usb_device.h"
#include "device_manager.h"
#include "xhci_internal.h"
#include "usb.h"
#include "logger.h"
#include "states/xhci_host.pb.h"

using namespace std::chrono;

struct UsbPortState {
  uint        id;
  uint32_t    speed_mask;
  UsbDevice*  device;
};

struct XhciRing {
  bool      consumer_cycle_bit;
  uint64_t  dequeue;
};

struct XhciTransfer;
struct XhciEndpoint {
  uint      id;
  uint      slot_id;
  EPType    type;
  uint      max_packet_size;
  uint      max_pstreams;
  bool      linear_stream_array;
  uint      interval;
  XhciRing  ring;
  int64_t   mfindex_last;
  uint      state;
  uint      kick_active;
  uint64_t  context_address;
  std::set<XhciTransfer*> transfers;
  uint      endpoint_address;
};

struct XhciSlot {
  bool        enabled;
  bool        addressed;
  uint64_t    context_address;
  XhciEndpoint* endpoints[31];
  UsbDevice*  device;
  int         interrupt_vector;
};

struct XhciEvent {
  TRBType   type;
  TRBCCode  completion_code;
  uint64_t  poniter;
  uint32_t  length;
  uint32_t  flags;
  uint      slot_id;
  uint      endpoint_id;
};

struct XhciTransfer {
  XhciEndpoint* endpoint;
  TRBCCode      status;
  uint          stream_id;
  bool          completed;
  bool          in_direction;
  bool          interrupt_on_completion;
  std::vector<XhciTransferRequestBlock> trbs;
  UsbPacket*    packet;
  UsbDevice*    device;
};

class XhciHost : public PciDevice {
 private:
    /* 8 ports in total, USB 2.0 ports 1-4, USB 3.0 ports 5-8 */
    uint max_ports_ = 8;
    uint max_interrupts_ = 16;
    uint max_slots_ = 64;
    uint max_pstreams_mask_ = 7;
  
    std::array<UsbPortState, 128>           port_states_ = { 0 };
    std::array<XhciPortRegisters, 128>      port_regs_ = { 0 };
    std::array<XhciInterruptRegisters, 128> interrupt_regs_ = { 0 };
    std::array<XhciSlot, 128>               slots_ = { 0 };
    XhciRing                                command_ring_;
    IoTimePoint                             microframe_index_start_;
    XhciCapabilityRegisters                 capability_regs_;
    XhciOperationalRegisters                operational_regs_;
    XhciRuntimeRegisters                    runtime_regs_;
  
    /* global mutex */
    std::mutex mutex_;

 public:
  XhciHost() {
    devfn_ = PCI_MAKE_DEVFN(3, 0);
    
    pci_header_.vendor_id = 0x1B36;
    pci_header_.device_id = 0x000D;
    pci_header_.class_code = 0x0C0330;
    pci_header_.revision_id = 1;
    pci_header_.header_type = PCI_HEADER_TYPE_NORMAL;
    pci_header_.subsys_vendor_id = 0x1AF4;
    pci_header_.subsys_id = 0x1100;
    pci_header_.irq_pin = 0;
    pci_header_.cacheline_size = 0x10;
    pci_header_.command = PCI_COMMAND_IO | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER;

    /* Specification Release 3.0 */
    pci_header_.data[0x60] = 0x30;
    next_capability_offset_ = 0x90;

    AddPciBar(0, 0x4000, kIoResourceTypeMmio);
    AddMsiXCapability(0, 16, 0x3000, 0x1000);
  }

  virtual void Connect() {
    PciDevice::Connect();
    
    MV_ASSERT(max_interrupts_ <= 128);
    MV_ASSERT(max_ports_ <= 128);
    MV_ASSERT(max_slots_ <= 128);

    /* USB ports are divided in half, 2.0 ports and 3.0 ports. */
    for (uint i = 0; i < max_ports_; i++) {
      port_states_[i].id = i + 1;
      port_states_[i].speed_mask = uint32_t(i < max_ports_ / 2 ? 0b111 : 0b1000);
    }

    /* Connect USB devices to ports */
    for (auto device : children_) {
      UsbDevice* usb = dynamic_cast<UsbDevice*>(device);
      if (usb) {
        AttachUsbDevice(usb);
      }
    }
  }

  bool AttachUsbDevice(UsbDevice* device) {
    for (auto &port_state : port_states_) {
      if (port_state.device)
        continue;
      if ((port_state.speed_mask & (1 << device->speed())) == 0)
        continue;
      port_state.device = device;
      if (debug_) {
        MV_LOG("Attach USB device %s to port %d", device->name(), port_state.id);
      }
      return true;
    }
    MV_PANIC("failed to attach USB device %s", device->name());
    return false;
  }

  bool SaveState(MigrationWriter* writer) {
    XhciHostState state;
    auto operational = state.mutable_operational();
    operational->set_usb_command(operational_regs_.usb_command);
    operational->set_usb_status(operational_regs_.usb_status);
    operational->set_device_notification_control(operational_regs_.device_notification_control);
    operational->set_command_ring_control(operational_regs_.command_ring_control);
    operational->set_context_base_array_pointer(operational_regs_.context_base_array_pointer);
    operational->set_configure(operational_regs_.configure);

    auto runtime = state.mutable_runtime();
    runtime->set_microframe_index(GetMicroFrameIndex());

    auto command_ring = state.mutable_command_ring();
    command_ring->set_dequeue(command_ring_.dequeue);
    command_ring->set_consumer_cycle_bit(command_ring_.consumer_cycle_bit);

    for (uint i = 0; i < max_ports_; i++) {
      auto port = state.add_ports();
      port->set_status_control(port_regs_[i].status_control);
    }

    for (uint i = 0; i < max_slots_; i++) {
      auto slot = state.add_slots();
      slot->set_enabled(slots_[i].enabled);
      slot->set_addressed(slots_[i].addressed);
    }

    for (uint i = 0; i < max_interrupts_; i++) {
      auto interrupt = state.add_interrupts();
      interrupt->set_management(interrupt_regs_[i].management);
      interrupt->set_moderation(interrupt_regs_[i].moderation);
      interrupt->set_event_ring_table_size(interrupt_regs_[i].event_ring_table_size);
      interrupt->set_event_ring_table_base(interrupt_regs_[i].event_ring_table_base);
      interrupt->set_event_ring_dequeue_pointer(interrupt_regs_[i].event_ring_dequeue_pointer);
      interrupt->set_event_ring_segment_start(interrupt_regs_[i].event_ring_segment.start);
      interrupt->set_event_ring_segment_size(interrupt_regs_[i].event_ring_segment.size);
      interrupt->set_event_ring_enqueue_index(interrupt_regs_[i].event_ring_enqueue_index);
      interrupt->set_event_ring_producer_cycle_bit(interrupt_regs_[i].producer_cycle_bit);
    }

    writer->WriteProtobuf("XHCI", state);
    return PciDevice::SaveState(writer);
  }

  bool LoadState(MigrationReader* reader) {
    if (!PciDevice::LoadState(reader)) {
      return false;
    }
    XhciHostState state;
    if (!reader->ReadProtobuf("XHCI", state)) {
      return false;
    }
    auto& operational = state.operational();
    operational_regs_.usb_command = operational.usb_command();
    operational_regs_.usb_status = operational.usb_status();
    operational_regs_.device_notification_control = operational.device_notification_control();
    operational_regs_.command_ring_control = operational.command_ring_control();
    operational_regs_.context_base_array_pointer = operational.context_base_array_pointer();
    operational_regs_.configure = operational.configure();

    auto& runtime = state.runtime();
    microframe_index_start_ = steady_clock::now() - nanoseconds(runtime.microframe_index() * 125000);

    auto& command_ring = state.command_ring();
    command_ring_.dequeue = command_ring.dequeue();
    command_ring_.consumer_cycle_bit = command_ring.consumer_cycle_bit();

    for (uint i = 0; i < max_ports_; i++) {
      auto& port = state.ports(i);
      port_regs_[i].status_control = port.status_control();
    }

    for (uint i = 0; i < max_slots_; i++) {
      auto& slot = state.slots(i);
      slots_[i].enabled = slot.enabled();
      slots_[i].addressed = slot.addressed();
      if (slot.addressed()) {
        PostLoadSlot(i + 1);
      }
    }

    for (uint i = 0; i < max_interrupts_; i++) {
      auto& interrupt = state.interrupts(i);
      interrupt_regs_[i].management = interrupt.management();
      interrupt_regs_[i].moderation = interrupt.moderation();
      interrupt_regs_[i].event_ring_table_size = interrupt.event_ring_table_size();
      interrupt_regs_[i].event_ring_table_base = interrupt.event_ring_table_base();
      interrupt_regs_[i].event_ring_dequeue_pointer = interrupt.event_ring_dequeue_pointer();
      interrupt_regs_[i].event_ring_segment.start = interrupt.event_ring_segment_start();
      interrupt_regs_[i].event_ring_segment.size = interrupt.event_ring_segment_size();
      interrupt_regs_[i].event_ring_enqueue_index = interrupt.event_ring_enqueue_index();
      interrupt_regs_[i].producer_cycle_bit = interrupt.event_ring_producer_cycle_bit();
    }
    return true;
  }

  virtual void Reset() {
    PciDevice::Reset();

    MV_ASSERT(sizeof(capability_regs_) == 0x40);
    bzero(&capability_regs_, sizeof(capability_regs_));
    bzero(&operational_regs_, sizeof(operational_regs_));
    bzero(&runtime_regs_, sizeof(runtime_regs_));

    capability_regs_.capability_length = sizeof(capability_regs_);
    capability_regs_.interface_version = 0x0100;
    capability_regs_.max_slots = max_slots_;
    capability_regs_.max_interrupts = max_interrupts_;
    capability_regs_.max_ports = max_ports_;
    capability_regs_.hcs_params2 = 0x0000000F;
    capability_regs_.hcs_params3 = 0x00000000;
    capability_regs_.capability_params1 = 0x00080001 | (max_pstreams_mask_ << 12);
    capability_regs_.doorbell_offset = 0x2000;
    capability_regs_.runtime_registers_offset = 0x1000;

    /* Extended capabilites */
    uint32_t* ext = capability_regs_.extended_capabilities;
    /* Supported protocol USB 2.0 (port 1-4) */
    *ext++ = 0x02000402;
    *ext++ = 0x20425355;
    *ext++ = (4 << 8) | 1;
    *ext++ = 0;
    /* Supported protocol USB 3.0 (port 5-8) */
    *ext++ = 0x03000002;
    *ext++ = 0x20425355;
    *ext++ = (4 << 8) | 5;
    *ext++ = 0;

    /* Operational registers */
    operational_regs_.usb_status = USBSTS_HCH; // halted
    operational_regs_.page_size = 1; // 4KB

    for (uint i = 1; i <= max_slots_; i++) {
      DisableSlot(i);
    }

    for (auto &interrupt: interrupt_regs_) {
      bzero(&interrupt, sizeof(interrupt));
      interrupt.producer_cycle_bit = true;
    }
    
    for (uint i = 0; i < max_ports_; i++) {
      SetupPort(i);
    }
  }

  bool IsRunning() {
    return !(operational_regs_.usb_status & USBSTS_HCH);
  }

  void PushEvent(uint vector, XhciEvent &event) {
    MV_ASSERT(vector < max_interrupts_);
    auto &interrupt = interrupt_regs_[vector];
    auto &segment = interrupt.event_ring_segment;
    auto dequeue_pointer = interrupt.event_ring_dequeue_pointer;
    auto dequeue_index = (dequeue_pointer - segment.start) / TRB_SIZE;
    auto enqueue_index = interrupt.event_ring_enqueue_index;
    MV_ASSERT(dequeue_index < segment.size);

    if ((enqueue_index + 2) % segment.size == dequeue_index) {
      MV_LOG("event ring[%d] is full, send error", vector);
      XhciEvent full = { ER_HOST_CONTROLLER, CC_EVENT_RING_FULL_ERROR };
      WriteEvent(vector, full);
    } else if ((enqueue_index + 1) % segment.size == dequeue_index) {
      MV_LOG("event ring[%d] is full, drop event", vector);
    } else {
      WriteEvent(vector, event);
    }
    RaiseInterrupt(vector);
  }

  void WriteEvent(uint vector, XhciEvent &event) {
    auto &interrupt = interrupt_regs_[vector];
    auto addr = interrupt.event_ring_segment.start + interrupt.event_ring_enqueue_index * TRB_SIZE;
    auto trb = (XhciTransferRequestBlock*)manager_->TranslateGuestMemory(addr);
    trb->parameter = event.poniter;
    trb->status = event.length | (event.completion_code << 24);
    trb->control = (event.slot_id << 24) | (event.endpoint_id << 16) |
      event.flags | (event.type << TRB_TYPE_SHIFT);
    if (interrupt.producer_cycle_bit) {
      trb->control |= TRB_C;
    }

    interrupt.event_ring_enqueue_index++;
    if (interrupt.event_ring_enqueue_index >= interrupt.event_ring_segment.size) {
      interrupt.event_ring_enqueue_index = 0;
      interrupt.producer_cycle_bit = !interrupt.producer_cycle_bit;
    }
  }

  void SetupRing(XhciRing &ring, uint64_t base) {
    ring.consumer_cycle_bit = true;
    ring.dequeue = base;
  }

  bool PopRing(XhciRing &ring, XhciTransferRequestBlock &trb) {
    while (true) {
      void* hva = manager_->TranslateGuestMemory(ring.dequeue);
      memcpy(&trb, hva, TRB_SIZE);
      trb.address = ring.dequeue;
      trb.cycle_bit = ring.consumer_cycle_bit;
      
      if (!!(trb.control & TRB_C) != ring.consumer_cycle_bit) {
        // Maybe software is still writing the ring ??
        return false;
      }

      auto type = TRB_TYPE(trb);
      if (type == TR_LINK) {
        ring.dequeue = trb.parameter;
        if (trb.control & TRB_LK_TC) {
          ring.consumer_cycle_bit = !ring.consumer_cycle_bit;
        }
      } else {
        ring.dequeue += TRB_SIZE;
        return true;
      }
    }
  }

  void ResetEventRing(int index) {
    auto &interrupt = interrupt_regs_[index];

    if (interrupt.event_ring_table_size == 0 || interrupt.event_ring_table_base == 0) {
      /* disabled */
      bzero(&interrupt.event_ring_segment, sizeof(interrupt.event_ring_segment));
      return;
    }
    MV_ASSERT(interrupt.event_ring_table_size == 1);

    interrupt.event_ring_segment = *(XhciEventRingSegment*)manager_->TranslateGuestMemory(
      interrupt.event_ring_table_base);
    interrupt.event_ring_enqueue_index = 0;
    interrupt.producer_cycle_bit = true;
    auto &segment = interrupt.event_ring_segment;

    if (debug_) {
      MV_LOG("reset event ring[%d] start=0x%lX size=%d", index, segment.start, segment.size); 
    }
    MV_ASSERT(segment.size >= 16 && segment.size < 4096);
  }

  void RaiseInterrupt(uint vector) {
    auto &interrupt = interrupt_regs_[vector];
    bool pending = interrupt.event_ring_dequeue_pointer & ERDP_EHB;

    interrupt.event_ring_dequeue_pointer |= ERDP_EHB;
    interrupt.management |= IMAN_IP;
    operational_regs_.usb_status |= USBSTS_EINT;

    if (pending) {
      return;
    }
    if (!(interrupt.management & IMAN_IE)) {
      return;
    }
    if (!(operational_regs_.usb_command & USBCMD_INTE)) {
      return;
    }
    if (msi_config_.enabled) {
      SignalMsi(vector);
    }
  }

  void CheckInterrupt(uint vector) {
    if (vector == 0) {
      auto &interrupt = interrupt_regs_[0];
      if ((interrupt.management & IMAN_IP) && (interrupt.management & IMAN_IE) &&
        (operational_regs_.usb_command & USBCMD_INTE)) {
        RaiseInterrupt(vector);
      }
    }
  }

  void WriteRuntimeRegs(uint64_t offset, uint8_t* data, uint32_t size) {
    MV_ASSERT(offset >= 0x20);
    uint64_t value = 0;
    memcpy(&value, data, size);
    int index = (offset - 0x20) / 0x20;
    auto &interrupt = interrupt_regs_[index];
    switch (offset & 0x1F)
    {
    case offsetof(XhciInterruptRegisters, management):
      if (value & IMAN_IP) {
        interrupt.management &= ~IMAN_IP;
      }
      interrupt.management &= ~IMAN_IE;
      interrupt.management |= value & IMAN_IE;
      CheckInterrupt(index);
      break;
    case offsetof(XhciInterruptRegisters, moderation):
      interrupt.moderation = value & 0xFFFFFFFF;
      break;
    case offsetof(XhciInterruptRegisters, event_ring_table_size):
      interrupt.event_ring_table_size = value & 0xFFFF;
      break;
    case offsetof(XhciInterruptRegisters, event_ring_table_base):
      interrupt.event_ring_table_base = value & 0xFFFFFFFFFFFFFFC0ULL;
      ResetEventRing(index);
      break;
    case offsetof(XhciInterruptRegisters, event_ring_dequeue_pointer):
      if (value & ERDP_EHB) {
        interrupt.event_ring_dequeue_pointer &= ~ERDP_EHB;
      }
      interrupt.event_ring_dequeue_pointer = (value & ~ERDP_EHB) |
        (interrupt.event_ring_dequeue_pointer & ERDP_EHB);
      if (value & ERDP_EHB) {
        auto dequeue = interrupt.event_ring_dequeue_pointer;
        auto &segment = interrupt.event_ring_segment;
        uint64_t dequeue_index = (dequeue - segment.start) / TRB_SIZE;
        if (dequeue >= segment.start && dequeue < (segment.start + TRB_SIZE * segment.size) &&
          dequeue_index != interrupt.event_ring_enqueue_index) {
          RaiseInterrupt(index);
        }
      }
      break;
    default:
      memcpy((uint8_t*)&interrupt + offset, data, size);
      break;
    }
  }

  void ReadOperationalRegs(uint64_t offset, uint8_t* data, uint32_t size) {
    memcpy(data, (uint8_t*)&operational_regs_ + offset, size);
  }

  void ReadPortRegs(uint64_t offset, uint8_t* data, uint32_t size) {
    uint64_t index = offset / sizeof(XhciPortRegisters);
    offset = offset % sizeof(XhciPortRegisters);
    auto& port = port_regs_[index];
    switch (offset)
    {
    case offsetof(XhciPortRegisters, status_control):
    case offsetof(XhciPortRegisters, link_info):
      memcpy(data, (uint8_t*)&port + offset, size);
      break;
    default:
      MV_PANIC("ReadPortRegs offset=0x%lx size=%u", offset, size);
      break;
    }
  }

  int64_t GetMicroFrameIndex() {
    auto delta_ns = (steady_clock::now() - microframe_index_start_).count();
    return delta_ns / 125000;
  }

  void ReadRuntimeRegs(uint64_t offset, uint8_t* data, uint32_t size) {
    if (offset < 0x20) {
      if (offset == offsetof(XhciRuntimeRegisters, microframe_index)) {
        auto mfindex = GetMicroFrameIndex();
        memcpy(data, &mfindex, size);
      } else {
        MV_PANIC("ReadRuntimeRegs offset=0x%lx size=%u", offset, size);
      }
    } else {
      auto index = (offset - 0x20) / sizeof(XhciInterruptRegisters);
      offset = offset % sizeof(XhciInterruptRegisters);
      auto &interrupt = interrupt_regs_[index];
      memcpy(data, (uint8_t*)&interrupt + offset, size);
    }
  }

  void WriteOperationalUsbCommand(uint32_t command) {
    if ((command & USBCMD_RS) && !(operational_regs_.usb_command & USBCMD_RS)) {
      // RUN
      operational_regs_.usb_status &= ~USBSTS_HCH;
      microframe_index_start_ = steady_clock::now();
    } else if (!(command & USBCMD_RS) && (operational_regs_.usb_command & USBCMD_RS)) {
      // STOP
      operational_regs_.usb_status |= USBSTS_HCH;
      operational_regs_.command_ring_control &= ~CRCR_CRR;
    }
    if (command & USBCMD_CSS) { // Save state
      operational_regs_.usb_status &= ~USBSTS_SRE;
    }
    if (command & USBCMD_CRS) { // Restore state
      operational_regs_.usb_status |= USBSTS_SRE;
    }
    operational_regs_.usb_command = command & 0xC0F;
    // mfwrap_timer is not supported yet
    MV_ASSERT((command & (USBCMD_RS | USBCMD_EWE)) != (USBCMD_RS | USBCMD_EWE));
    if (command & USBCMD_HCRST) {
      Reset();
    }
    CheckInterrupt(0);
  }

  void WriteOperationalRegs(uint64_t offset, uint8_t* data, uint32_t size) {
    switch (offset)
    {
    case offsetof(XhciOperationalRegisters, usb_command):
      WriteOperationalUsbCommand(*(uint32_t*)data);
      break;
    case offsetof(XhciOperationalRegisters, usb_status): {
      MV_ASSERT(size = 4);
      uint32_t value = *(uint32_t*)data;
      operational_regs_.usb_status &= ~(value & (USBSTS_HSE|USBSTS_EINT|USBSTS_PCD|USBSTS_SRE));
      CheckInterrupt(0);
      break;
    }
    case offsetof(XhciOperationalRegisters, configure):
      operational_regs_.configure = data[0];
      break;
    case offsetof(XhciOperationalRegisters, command_ring_control):
      if (data[0] & (CRCR_CA|CRCR_CS) && (data[0] & CRCR_CRR)) {
        XhciEvent event = { ER_COMMAND_COMPLETE, CC_COMMAND_RING_STOPPED };
        data[0] &= ~CRCR_CRR;
        PushEvent(0, event);
        memcpy(&operational_regs_.command_ring_control, data, size);
      } else {
        memcpy(&operational_regs_.command_ring_control, data, size);
        SetupRing(command_ring_, operational_regs_.command_ring_control & ~0x3F);
      }
      operational_regs_.command_ring_control &= ~(CRCR_CA | CRCR_CS);
      break;
    case offsetof(XhciOperationalRegisters, device_notification_control):
    case offsetof(XhciOperationalRegisters, context_base_array_pointer):
    case offsetof(XhciOperationalRegisters, context_base_array_pointer) + 4:
    case offsetof(XhciOperationalRegisters, command_ring_control) + 4:
      memcpy((uint8_t*)&operational_regs_ + offset, data, size);
      break;
    default:
      MV_PANIC("WriteOperationalRegs offset=0x%lx size=%u data=0x%lx",
        offset, size, *(uint64_t*)data);
      break;
    }
  }

  /* ======================== Slot Functions ======================= */

  TRBCCode EnableSlot(uint slot_id) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];
    if (!slot.enabled) {
      if (debug_) {
        MV_LOG("enable slot=%u", slot_id);
      }
      slot.enabled = true;
      bzero(slot.endpoints, sizeof(slot.endpoints));
    }
    return CC_SUCCESS;
  }

  TRBCCode DisableSlot(uint slot_id) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];
    if (slot.enabled) {
      if (debug_) {
        MV_LOG("disable slot=%u", slot_id);
      }
      for (uint i = 0; i < 31; i++) {
        if (slot.endpoints[i]) {
          DisableEndpoint(slot_id, i + 1);
        }
      }
      slot.enabled = false;
      slot.addressed = false;
    }
    return CC_SUCCESS;
  }

  bool GetSlot(XhciEvent &event, XhciTransferRequestBlock &trb, uint &slot_id) {
    slot_id = (trb.control >> TRB_CR_SLOTID_SHIFT) & TRB_CR_SLOTID_MASK;
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];
    if (!slot.enabled) {
      MV_LOG("slot %u is not enabled", slot_id);
      event.completion_code = CC_SLOT_NOT_ENABLED_ERROR;
      return false;
    }
    return true;
  }

  TRBCCode EvaluateSlot(uint slot_id, uint64_t input_addr) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];
    auto output_addr = slot.context_address;

    auto input = (uint32_t*)manager_->TranslateGuestMemory(input_addr);
    auto output = (uint32_t*)manager_->TranslateGuestMemory(output_addr);

    MV_ASSERT(input[0] == 0 && !(input[1] & ~0x3));

    auto input_slot = input + 8;
    if (input[1] & 1) {
      /* max exit latency */
      output[1] &= ~0xFFFF;
      output[1] |= input_slot[1] & 0xFFFF;
      slot.interrupt_vector = get_field(input_slot[2], TRB_INTR);
      set_field(&output[2], slot.interrupt_vector, TRB_INTR);
    }

    if (input[1] & 2) {
      auto input_endpoint0 = input_slot + 8;
      auto output_endpoint0 = output + 8;
      /* max packet size */
      output_endpoint0[1] &= ~0xFFFF0000;
      output_endpoint0[1] |= input_endpoint0[1] & 0xFFFF0000;
    }
    return CC_SUCCESS;
  }

  TRBCCode ConfigureSlot(uint slot_id, uint64_t input_addr, bool deconfigure) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];
    auto output_addr = slot.context_address;

    auto output = (uint32_t*)manager_->TranslateGuestMemory(output_addr);

    if (deconfigure) {
      for (int i = 2; i <= 31; i++) {
        if (slot.endpoints[i - 1]) {
          DisableEndpoint(slot_id, i);
        }
      }
      output[3] &= ~(SLOT_STATE_MASK << SLOT_STATE_SHIFT);
      output[3] |= SLOT_ADDRESSED << SLOT_STATE_SHIFT;
      return CC_SUCCESS;
    }

    auto input = (uint32_t*)manager_->TranslateGuestMemory(input_addr);
    MV_ASSERT((input[0] & 0x03) == 0 && (input[1] & 0x03) == 1);

    auto input_slot = input + 8;
    if (SLOT_STATE(output[3] < SLOT_ADDRESSED)) {
      return CC_CONTEXT_STATE_ERROR;
    }

    for (int i = 2; i <= 31; i++) {
      if (input[0] & (1 << i)) {
        DisableEndpoint(slot_id, i);
      }
      if (input[1] & (1 << i)) {
        auto endpoint_context = input_slot + 8 * i;
        DisableEndpoint(slot_id, i);
        EnableEndpoint(slot_id, i, endpoint_context, true);
        memcpy(output + 8 * i, endpoint_context, 0x20);
      }
    }

    output[3] &= ~(SLOT_STATE_MASK << SLOT_STATE_SHIFT);
    output[3] |= SLOT_CONFIGURED << SLOT_STATE_SHIFT;
    output[0] &= ~(SLOT_CONTEXT_ENTRIES_MASK << SLOT_CONTEXT_ENTRIES_SHIFT);
    output[0] |= input_slot[0] & (SLOT_CONTEXT_ENTRIES_MASK << SLOT_CONTEXT_ENTRIES_SHIFT);
    return CC_SUCCESS;
  }

  void PostLoadSlot(uint slot_id) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];

    auto context_base_array = (uint64_t*)manager_->TranslateGuestMemory(
      operational_regs_.context_base_array_pointer);
    slot.context_address = context_base_array[slot_id];
  
    auto slot_context = (uint32_t*)manager_->TranslateGuestMemory(slot.context_address);
    uint port_id = (slot_context[1] >> 16) & 0xFF;

    slot.interrupt_vector = get_field(slot_context[2], TRB_INTR);
    slot.device = LookupDevice(port_id, slot_context[0] & 0xFFFFF);
    MV_ASSERT(slot.device);
    
    for (uint endpoint_id = 1; endpoint_id <= 31; endpoint_id++) {
      auto endpoint_context = slot_context + 8 * endpoint_id;
      auto state = endpoint_context[0] & EP_STATE_MASK;
      if (state == EP_DISABLED)
        continue;
      
      EnableEndpoint(slot_id, endpoint_id, endpoint_context, false);
      if (state == EP_RUNNING) {
        /* Restart kicking endpoint */
        manager_->io()->Schedule([this, slot_id, endpoint_id]() {
          KickEndpoint(slot_id, endpoint_id, 0);
        });
      }
    }
  }

  TRBCCode AddressSlot(uint slot_id, uint64_t input_addr, bool block_set_request) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    auto &slot = slots_[slot_id - 1];

    auto context_base_array = (uint64_t*)manager_->TranslateGuestMemory(
      operational_regs_.context_base_array_pointer);
    auto output_addr = context_base_array[slot_id];
    
    auto input = (uint32_t*)manager_->TranslateGuestMemory(input_addr);
    auto output = (uint32_t*)manager_->TranslateGuestMemory(output_addr);
    MV_ASSERT(input[0] == 0x0 && input[1] == 0x3);

    auto input_slot = input + 8;
    auto input_endpoint0 = input_slot + 8;
    
    uint port_id = (input_slot[1] >> 16) & 0xFF;
    UsbDevice* device = LookupDevice(port_id, input_slot[0] & 0xFFFFF);
    if (device == nullptr) {
      MV_LOG("device not found, port=%d", port_id);
      return CC_TRB_ERROR;
    }

    for (uint i = 0; i < max_slots_; i++) {
      if (i != slot_id - 1 && slots_[i].device == device) {
        MV_LOG("USB device %s is already assigned to slot %u", device->name(), slot_id);
        return CC_TRB_ERROR;
      }
    }

    slot.addressed = true;
    slot.device = device;
    slot.context_address = output_addr;
    slot.interrupt_vector = get_field(input_slot[2], TRB_INTR);
    device->Reset();
    if (block_set_request) {
      input_slot[3] = SLOT_DEFAULT << SLOT_STATE_SHIFT;
    } else {
      input_slot[3] = (SLOT_ADDRESSED << SLOT_STATE_SHIFT) | slot_id;
      if (debug_) {
        MV_LOG("USB device %s assigned to slot %u", device->name(), slot_id);
      }
    }

    EnableEndpoint(slot_id, 1, input_endpoint0, true);
    
    memcpy(output, input_slot, 0x20);
    memcpy(output + 8, input_endpoint0, 0x20);
    return CC_SUCCESS;
  }

  /* ======================== Port Functions ======================= */

  /* USB 3.0 ports resets to U0 automatically */
  void SetupPort(int index) {
    auto &port_state = port_states_[index];
    auto &port = port_regs_[index];
    port.status_control = PORTSC_PP; // port power
    uint32_t port_link_state = PLS_RX_DETECT;

    if (port_state.device) {
      port.status_control |= PORTSC_CCS;
      switch (port_state.device->speed())
      {
      case kUsbSpeedLow:
        port.status_control |= PORTSC_SPEED_LOW;
        port_link_state = PLS_POLLING;
        break;
      case kUsbSpeedFull:
        port.status_control |= PORTSC_SPEED_FULL;
        port_link_state = PLS_POLLING;
        break;
      case kUsbSpeedHigh:
        port.status_control |= PORTSC_SPEED_HIGH;
        port_link_state = PLS_POLLING;
        break;
      case kUsbSpeedSuper:
        port.status_control |= PORTSC_SPEED_SUPER | PORTSC_PED;
        port_link_state = PLS_U0;
        break;
      }
    }
    port.status_control |= port_link_state << PORTSC_PLS_SHIFT;
    NotifyPort(index, PORTSC_CSC);
  }

  void ResetPort(int index, bool warm_reset) {
    auto &port_state = port_states_[index];
    auto &port = port_regs_[index];
    if (!port_state.device) {
      return;
    }
    port_state.device->Reset();

    MV_ASSERT(!warm_reset);
    set_field(&port.status_control, PLS_U0, PORTSC_PLS);
    port.status_control |= PORTSC_PED;
    port.status_control &= ~PORTSC_PR;
    NotifyPort(index, PORTSC_PRC);
  }

  void NotifyPort(uint index, uint32_t bits) {
    auto &port = port_regs_[index];
    if ((port.status_control & bits) == bits) {
      return;
    }
    port.status_control |= bits;

    if (!IsRunning()) {
      return;
    }
    XhciEvent event = { ER_PORT_STATUS_CHANGE, CC_SUCCESS, (index + 1ULL) << 24 };
    PushEvent(0, event);
  }

  void WritePortStatusControl(uint64_t index, uint32_t value) {
    auto& port = port_regs_[index];
    /* write-1-to-start bits */
    if (value & PORTSC_WPR) {
      ResetPort(index, true);
      return;
    }
    if (value & PORTSC_PR) {
      ResetPort(index, false);
      return;
    }
    uint32_t sc = port.status_control;
    uint32_t notify = 0;
    /* write-1-to-clear bits */
    sc &= ~(value & (PORTSC_CSC|PORTSC_PEC|PORTSC_WRC|PORTSC_OCC|PORTSC_PRC|PORTSC_PLC|PORTSC_CEC));
    
    if (value & PORTSC_LWS) { // overwrite PLS
      uint32_t old_pls = get_field(port.status_control, PORTSC_PLS);
      uint32_t new_pls = get_field(value, PORTSC_PLS);
      switch (new_pls)
      {
      case PLS_U0:
        if (old_pls != PLS_U0) {
          set_field(&sc, new_pls, PORTSC_PLS);
          notify = PORTSC_PLC;
        }
        break;
      case PLS_U3:
        if (old_pls < PLS_U3) {
          set_field(&sc, new_pls, PORTSC_PLS);
        }
        break;
      case PLS_RESUME:
        /* windows does this for some reason, don't spam stderr */
        break;
      default:
        MV_PANIC("ignore PLS write old=0x%x new=0x%x", old_pls, new_pls);
        break;
      }
    }

    /* read/write bits */
    sc &= ~(PORTSC_PP|PORTSC_WCE|PORTSC_WDE|PORTSC_WOE);
    sc |= (value & (PORTSC_PP|PORTSC_WCE|PORTSC_WDE|PORTSC_WOE));
    port.status_control = sc;
    if (notify) {
      NotifyPort(index, notify);
    }
  }

  void WritePortRegs(uint64_t offset, uint8_t* data, uint32_t size) {
    uint64_t index = offset / sizeof(XhciPortRegisters);
    offset = offset % sizeof(XhciPortRegisters);
    switch (offset)
    {
    case offsetof(XhciPortRegisters, status_control):
      MV_ASSERT(size == 4);
      WritePortStatusControl(index, *(uint32_t*)data);
      break;
    default:
      MV_PANIC("WritePortRegs offset=0x%lx size=%u data=0x%lx", offset, size, *(uint64_t*)data);
      break;
    }
  }

  /* FIXME: route_string is not supported yet */
  UsbDevice* LookupDevice(uint port_id, uint32_t route_string) {
    MV_ASSERT(port_id >= 1 && port_id <= max_ports_);
    for (auto &port_state : port_states_) {
      if (port_state.id == port_id) {
        return port_state.device;
      }
    }
    return nullptr;
  }

  /* ======================== Endpoint Functions ======================= */

  XhciEndpoint* CreateEndpoint(uint slot_id, uint endpoint_id, uint32_t* context) {
    auto endpoint = new XhciEndpoint { 0 };
    endpoint->id = endpoint_id;
    endpoint->slot_id = slot_id;

    uint64_t dequee_pointer = ((uint64_t)context[3] << 32) | (context[2] & ~0xF);
    endpoint->type = (EPType)((context[1] >> EP_TYPE_SHIFT) & EP_TYPE_MASK);
    endpoint->endpoint_address = ((endpoint->type >> 2) ? 0x80 : 0) | endpoint_id / 2;
    endpoint->max_packet_size = context[1] >> 16;
    endpoint->max_packet_size *= 1 + ((context[1] >> 8) & 0xFF);
    endpoint->max_pstreams = (context[0] >> 10) & max_pstreams_mask_;
    endpoint->linear_stream_array = (context[0] >> 15) & 1;
    if (endpoint->max_pstreams) {
      MV_PANIC("not implemented");
    } else {
      SetupRing(endpoint->ring, dequee_pointer);
      endpoint->ring.consumer_cycle_bit = context[2] & 1;
    }
    endpoint->interval = 1 << ((context[0] >> 16) & 0xFF);
    endpoint->mfindex_last = 0;
    endpoint->context_address = slots_[slot_id - 1].context_address + 0x20 * endpoint_id;
    return endpoint;
  }

  void EnableEndpoint(uint slot_id, uint endpoint_id, uint32_t* context, bool autorun) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    MV_ASSERT(endpoint_id >= 1 && endpoint_id <= 31);

    auto &slot = slots_[slot_id - 1];
    if (slot.endpoints[endpoint_id - 1]) {
      DisableEndpoint(slot_id, endpoint_id);
    }

    auto endpoint = CreateEndpoint(slot_id, endpoint_id, context);
    if (debug_) {
      MV_LOG("endpoint %d.%d type=%d, max packet size=%d interval=%d", endpoint_id / 2, endpoint_id % 2,
        endpoint->type, endpoint->max_packet_size, endpoint->interval);
    }
    slot.endpoints[endpoint_id - 1] = endpoint;
    if (autorun) {
      context[0] &= ~EP_STATE_MASK;
      context[0] |= EP_RUNNING;
    }
    endpoint->state = context[0] & EP_STATE_MASK;
  }

  TRBCCode DisableEndpoint(uint slot_id, uint endpoint_id) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    MV_ASSERT(endpoint_id >= 1 && endpoint_id <= 31);
    
    auto &slot = slots_[slot_id - 1];
    auto endpoint = slot.endpoints[endpoint_id - 1];
    if (!endpoint) {
      if (debug_) {
        MV_LOG("slot %d endpoint %d already disabled", slot_id, endpoint_id);
      }
      return CC_EP_NOT_ENABLED_ERROR;
    }

    TerminateAllTransfers(endpoint, CC_INVALID);

    /* only touch guest RAM if we're not resetting the HC */
    if (operational_regs_.context_base_array_pointer) {
      SetEndpointState(endpoint, EP_DISABLED);
    }

    delete endpoint;
    slot.endpoints[endpoint_id - 1] = nullptr;
    return CC_SUCCESS;
  }

  TRBCCode StopEndpoint(uint slot_id, uint endpoint_id) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    MV_ASSERT(endpoint_id >= 1 && endpoint_id <= 31);
    
    auto &slot = slots_[slot_id - 1];
    auto endpoint = slot.endpoints[endpoint_id - 1];
    if (!endpoint) {
      MV_LOG("slot %d endpoint %d already disabled", slot_id, endpoint_id);
      return CC_EP_NOT_ENABLED_ERROR;
    }

    TerminateAllTransfers(endpoint, CC_STOPPED);
    SetEndpointState(endpoint, EP_STOPPED);
    return CC_SUCCESS;
  }

  TRBCCode ResetEndpoint(uint slot_id, uint endpoint_id) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    MV_ASSERT(endpoint_id >= 1 && endpoint_id <= 31);
    
    auto &slot = slots_[slot_id - 1];
    auto endpoint = slot.endpoints[endpoint_id - 1];
    if (!endpoint) {
      MV_LOG("slot %d endpoint %d already disabled", slot_id, endpoint_id);
      return CC_EP_NOT_ENABLED_ERROR;
    }

    if (endpoint->state != EP_HALTED) {
      MV_LOG("reset endpoint while endpoint %d not halted", endpoint_id);
      return CC_CONTEXT_STATE_ERROR;
    }
    
    TerminateAllTransfers(endpoint, CC_INVALID);
    SetEndpointState(endpoint, EP_STOPPED);
    return CC_SUCCESS;
  }

  TRBCCode SetEndpointDequee(uint slot_id, uint endpoint_id, uint stream_id, uint64_t dequeue) {
    MV_ASSERT(slot_id >= 1 && slot_id <= max_slots_);
    MV_ASSERT(endpoint_id >= 1 && endpoint_id <= 31);
    
    auto &slot = slots_[slot_id - 1];
    auto endpoint = slot.endpoints[endpoint_id - 1];
    if (!endpoint) {
      MV_LOG("slot %d endpoint %d already disabled", slot_id, endpoint_id);
      return CC_EP_NOT_ENABLED_ERROR;
    }

    if (endpoint->state != EP_STOPPED) {
      MV_LOG("reset endpoint while endpoint %d not halted", endpoint_id);
      return CC_CONTEXT_STATE_ERROR;
    }

    SetupRing(endpoint->ring, dequeue & ~0xF);
    endpoint->ring.consumer_cycle_bit = dequeue & 1;
    
    SetEndpointState(endpoint, EP_STOPPED);
    return CC_SUCCESS;
  }

  void StallEndpoint(XhciTransfer* transfer) {
    auto endpoint = transfer->endpoint;
    MV_ASSERT(endpoint->type != ET_ISO_IN && endpoint->type != ET_ISO_OUT);

    endpoint->ring.dequeue = transfer->trbs[0].address;
    endpoint->ring.consumer_cycle_bit = transfer->trbs[0].cycle_bit;

    SetEndpointState(endpoint, EP_HALTED);
    if (debug_) {
      MV_LOG("%s stalled endpoint 0x%x", transfer->device->name(), endpoint->endpoint_address);
    }
  }

  void SetEndpointState(XhciEndpoint* endpoint, uint32_t state) {
    uint32_t* context = (uint32_t*)manager_->TranslateGuestMemory(
      endpoint->context_address);
    context[0] &= ~EP_STATE_MASK;
    context[0] |= state;

    auto &ring = endpoint->ring;
    context[2] = ring.dequeue | ring.consumer_cycle_bit;
    context[3] = ring.dequeue >> 32;
    endpoint->state = state;
    if (debug_) {
      MV_LOG("set endpoint=%d state=%d dequeue=0x%lx", endpoint->id, state, ring.dequeue);
    }
  }

  /* ======================== Transfer Functions ======================= */

  XhciTransfer* CreateTransfer(XhciEndpoint* endpoint, uint stream_id, int length) {
    auto transfer = new XhciTransfer;
    transfer->completed = false;
    transfer->endpoint = endpoint;
    transfer->device = slots_[endpoint->slot_id - 1].device;
    transfer->trbs.resize(length);
    transfer->status = CC_INVALID;
    transfer->packet = nullptr;
    transfer->stream_id = stream_id;
    endpoint->transfers.insert(transfer);
    return transfer;
  }

  void TerminateTransfer(XhciTransfer* transfer, TRBCCode report) {
    MV_ASSERT(!transfer->completed);
    if (report) {
      transfer->status = report;
      ReportTransfer(transfer);
    }
  }

  void TerminateAllTransfers(XhciEndpoint* endpoint, TRBCCode report) {
    auto copied(endpoint->transfers);
    for (auto transfer : copied) {
      TerminateTransfer(transfer, report);
      FreeTransfer(transfer);
    }
  }

  void FreeTransfer(XhciTransfer* transfer) {
    if (transfer->packet) {
      transfer->packet->Release();
    }
    transfer->packet = nullptr;
    if (transfer->endpoint->transfers.erase(transfer)) {
      delete transfer;
    }
  }

  void ReportTransfer(XhciTransfer* transfer) {
    XhciEvent event = { ER_TRANSFER, CC_SUCCESS };
    bool reported = false;
    bool short_packet = false;
    uint left = transfer->packet ? transfer->packet->content_length : 0;
    uint event_data_transfered = 0;

    for (auto &trb : transfer->trbs) {
      auto type = TRB_TYPE(trb);
      uint chunk = 0;
      switch (type)
      {
      case TR_SETUP:
        chunk = trb.status & 0x1FFFF;
        MV_ASSERT(chunk <= 8);
        break;
      case TR_DATA:
      case TR_NORMAL:
      case TR_ISOCH:
        chunk = trb.status & 0x1FFFF;
        if (chunk > left) {
          chunk = left;
          if (transfer->status == CC_SUCCESS)
            short_packet = true;
        }
        left -= chunk;
        event_data_transfered += chunk;
      case TR_STATUS:
        reported = false;
        short_packet = false;
        break;
      }

      if (!reported) {
        if ((trb.control & TRB_TR_IOC) ||
            (short_packet && (trb.control & TRB_TR_ISP)) ||
            (transfer->status != CC_SUCCESS && left == 0))
        {
          event.slot_id = transfer->endpoint->slot_id;
          event.endpoint_id = transfer->endpoint->id;
          if (transfer->status == CC_SUCCESS) {
            event.completion_code = short_packet ? CC_SHORT_PACKET : CC_SUCCESS;
          } else {
            event.completion_code = transfer->status;
          }
          if (type == TR_EVDATA) {
            event.poniter = trb.parameter;
            event.flags |= TRB_EV_ED;
            event.length = event_data_transfered & 0xFFFFFF;
            if (debug_) {
              MV_LOG("bytes transferred=%d status=%d", event_data_transfered, transfer->status);
            }
            event_data_transfered = 0;
          } else {
            event.poniter = trb.address;
            event.flags = 0;
            event.length = (trb.status & 0x1FFFF) - chunk;
          }

          PushEvent(TRB_INTR(trb), event);
          reported = true;
          if (transfer->status != CC_SUCCESS) {
            return;
          }
        }
      }
      
      if (type == TR_SETUP) {
        reported = false;
        short_packet = false;
      }
    }
  }

  void CompleteTransfer(XhciTransfer* transfer) {
    MV_ASSERT(transfer && !transfer->completed);
    transfer->completed = true;

    auto packet = transfer->packet;
    MV_ASSERT(packet);

    switch (packet->status)
    {
    case USB_RET_SUCCESS:
      transfer->status = CC_SUCCESS;
      break;
    case USB_RET_NODEV:
    case USB_RET_IOERROR:
      transfer->status = CC_USB_TRANSACTION_ERROR;
      break;
    case USB_RET_STALL:
      transfer->status = CC_STALL_ERROR;
      break;
    case USB_RET_BABBLE:
      transfer->status = CC_BABBLE_DETECTED;
      break;
    default:
      MV_PANIC("Unknown packet %p status=0x%x", packet, packet->status);
      break;
    }

    if (transfer->status != CC_SUCCESS) {
      StallEndpoint(transfer);
    } else {
      // Update ring dequeue to context
      auto endpoint = transfer->endpoint;
      SetEndpointState(endpoint, endpoint->state);
    }
  
    ReportTransfer(transfer);
  }

  bool SetupTransfer(XhciTransfer* transfer) {
    auto packet = transfer->device->CreatePacket(transfer->endpoint->endpoint_address,
      transfer->stream_id, transfer->trbs[0].address, [=]()
    {
      CompleteTransfer(transfer);
      FreeTransfer(transfer);
    });

    for (auto &trb : transfer->trbs) {
      if (trb.control & TRB_TR_IOC) {
        transfer->interrupt_on_completion = true;
      }

      uint chunk = trb.status & 0x1FFFF;
      uint64_t address = trb.parameter;
      switch (TRB_TYPE(trb))
      {
      case TR_DATA:
        MV_ASSERT(!!(trb.control & TRB_TR_DIR) == transfer->in_direction);
        /* fallthrough */
      case TR_NORMAL:
      case TR_ISOCH:
        if (trb.control & TRB_TR_IDT) {
          MV_ASSERT(chunk == 8 && !transfer->in_direction);
          address = trb.address;
        }
        packet->iov.push_back(iovec {
          .iov_base = manager_->TranslateGuestMemory(address),
          .iov_len = chunk
        });
        packet->size += chunk;
      }
    }
    transfer->packet = packet;
    return true;
  }

  void HandleDataTransfer(XhciTransfer* transfer) {
    auto endpoint = transfer->endpoint;

    transfer->in_direction = endpoint->type >> 2;
    if (!SetupTransfer(transfer)) {
      FreeTransfer(transfer);
      return;
    }
    transfer->device->HandlePacket(transfer->packet);
  }

  void HandleControlTransfer(XhciTransfer* transfer) {
    auto setup_trb = &transfer->trbs[0];
    auto status_trb = &transfer->trbs[transfer->trbs.size() - 1];

    if (TRB_TYPE(*status_trb) == TR_EVDATA && transfer->trbs.size() > 2) {
      status_trb--;
    }
    MV_ASSERT(TRB_TYPE(*setup_trb) == TR_SETUP);
    MV_ASSERT(TRB_TYPE(*status_trb) == TR_STATUS);
    MV_ASSERT(setup_trb->control & TRB_TR_IDT);
    MV_ASSERT((setup_trb->status & 0x1FFFF) == 8);

    transfer->in_direction = setup_trb->parameter & USB_DIR_IN;
    if (!SetupTransfer(transfer)) {
      FreeTransfer(transfer);
      return;
    }
    transfer->packet->control_parameter = setup_trb->parameter;
    transfer->device->HandlePacket(transfer->packet);
  }

  int GetRingChainLength(XhciRing &ring) {
    /* hack to bundle together the two/three TDs that make a setup transfer */
    int length = 0;
    bool control_td_set = false;
    bool cycle_bit = ring.consumer_cycle_bit;
    auto dequeue = ring.dequeue;
    while (true) {
      XhciTransferRequestBlock trb;
      memcpy(&trb, manager_->TranslateGuestMemory(dequeue), TRB_SIZE);
      if ((trb.control & TRB_C) != cycle_bit) {
        return -length;
      }

      auto type = TRB_TYPE(trb);
      if (type == TR_LINK) {
        dequeue = trb.parameter;
        if (trb.control & TRB_LK_TC) {
          cycle_bit = !cycle_bit;
        }
        continue;
      }

      length++;
      dequeue += TRB_SIZE;

      if (type == TR_SETUP) {
        control_td_set = true;
      } else if (type == TR_STATUS) {
        control_td_set = false;
      }
      if (!control_td_set && !(trb.control & TRB_TR_CH)) {
        return length;
      }
    }
  }

  void KickEndpoint(uint slot_id, uint endpoint_id, uint stream_id) {
    MV_ASSERT(slot_id <= max_slots_);
    MV_ASSERT(endpoint_id >= 1 && endpoint_id <= 31);
    auto &slot = slots_[slot_id - 1];
    if (!slot.enabled) {
      MV_LOG("kick disabled slot %d", slot_id);
      return;
    }
    auto endpoint = slot.endpoints[endpoint_id - 1];
    if (!endpoint || endpoint->state == EP_HALTED) {
      MV_LOG("kick disabled endpoint %d of %d", endpoint_id, slot_id);
      return;
    } 
    if (debug_) {
      MV_LOG("kick endpoint slot=%u ep=%u stream=%u kick_active=%u",
        slot_id, endpoint_id, stream_id, endpoint->kick_active);
    }
    if (endpoint->kick_active) {
      MV_LOG("kick active %d", endpoint->kick_active);
      return;
    }

    auto &ring = endpoint->ring;
    MV_ASSERT(stream_id == 0);
    SetEndpointState(endpoint, EP_RUNNING);
    MV_ASSERT(ring.dequeue);

    endpoint->kick_active++;
    while (endpoint->state != EP_HALTED) {
      int length = GetRingChainLength(ring);
      if (debug_) {
        MV_LOG("ring chain length=%d", length);
      }
      if (length <= 0) {
        if (endpoint->type == ET_ISO_OUT || endpoint->type == ET_ISO_IN) {
          XhciEvent event = { ER_TRANSFER,
            .completion_code = endpoint->type == ET_ISO_IN ? CC_RING_OVERRUN : CC_RING_UNDERRUN,
            .poniter = endpoint->ring.dequeue,
            .slot_id = endpoint->slot_id,
            .endpoint_id = endpoint->id
          };
          PushEvent(slot.interrupt_vector, event);
        }
        break;
      }

      auto transfer = CreateTransfer(endpoint, stream_id, length);
      MV_ASSERT(transfer);

      for (int i = 0; i < length; i++) {
        if (!PopRing(ring, transfer->trbs[i])) {
          endpoint->kick_active--;
          FreeTransfer(transfer);
          MV_PANIC("failed to pop ring");
          return;
        }
      }

      if (endpoint->id == 1) {
        HandleControlTransfer(transfer);
      } else {
        HandleDataTransfer(transfer);
      }
    }
    endpoint->kick_active--;
  }

  void ProcessCommands() {
    operational_regs_.command_ring_control |= CRCR_CRR;

    XhciTransferRequestBlock trb;
    while (PopRing(command_ring_, trb)) {
      uint slot_id = 0;
      TRBCCode code = CC_SUCCESS;
      XhciEvent event = { ER_COMMAND_COMPLETE, .poniter = trb.address };
      auto type = TRB_TYPE(trb);
      if (debug_) {
        MV_LOG("command=%d", type);
      }
      switch (type)
      {
      case CR_ENABLE_SLOT:
        for (uint i = 0; i < max_slots_; i++) {
          if (!slots_[i].enabled) {
            slot_id = i + 1;
            break;
          }
        }
        MV_ASSERT(slot_id);
        code = EnableSlot(slot_id);
        break;
      case CR_DISABLE_SLOT:
        if (GetSlot(event, trb, slot_id)) {
          code = DisableSlot(slot_id);
        }
        break;
      case CR_ADDRESS_DEVICE:
        if (GetSlot(event, trb, slot_id)) {
          code = AddressSlot(slot_id, trb.parameter, trb.control & TRB_CR_BSR);
        }
        break;
      case CR_CONFIGURE_ENDPOINT:
        if (GetSlot(event, trb, slot_id)) {
          code = ConfigureSlot(slot_id, trb.parameter, trb.control & TRB_CR_DC);
        }
        break;
      case CR_EVALUATE_CONTEXT:
        if (GetSlot(event, trb, slot_id)) {
          code = EvaluateSlot(slot_id, trb.parameter);
        }
        break;
      case CR_RESET_ENDPOINT:
        if (GetSlot(event, trb, slot_id)) {
          uint endpoint_id = (trb.control >> TRB_CR_EPID_SHIFT) & TRB_CR_EPID_MASK;
          code = ResetEndpoint(slot_id, endpoint_id);
        }
        break;
      case CR_STOP_ENDPOINT:
        if (GetSlot(event, trb, slot_id)) {
          uint endpoint_id = (trb.control >> TRB_CR_EPID_SHIFT) & TRB_CR_EPID_MASK;
          code = StopEndpoint(slot_id, endpoint_id);
        }
        break;
      case CR_SET_TR_DEQUEUE:
        if (GetSlot(event, trb, slot_id)) {
          uint endpoint_id = (trb.control >> TRB_CR_EPID_SHIFT) & TRB_CR_EPID_MASK;
          uint stream_id = (trb.status >> 16) & 0xFFFF;
          code = SetEndpointDequee(slot_id, endpoint_id, stream_id, trb.parameter);
        }
        break;
      default:
        MV_PANIC("unhandled TRB type=%d", type);
        break;
      }
      event.completion_code = code;
      event.slot_id = slot_id;
      PushEvent(0, event);
    }
  }

  void WriteDoorbellRegs(uint64_t address, uint64_t offset, uint8_t* data, uint32_t size) {
    MV_ASSERT(size == 4);
    uint64_t slot_id = offset >> 2;
    uint32_t value = *(uint32_t*)data;

    manager_->io()->Schedule([=]() {
      std::lock_guard<std::mutex> lock(mutex_);
      if (slot_id == 0) {
        ProcessCommands();
      } else {
        uint endpoint_id = value & 0xFF;
        uint stream_id = (value >> 16) & 0xFFFF;
        KickEndpoint(slot_id, endpoint_id, stream_id);
      }
    });
  }

  void Read(const IoResource* resource, uint64_t offset, uint8_t* data, uint32_t size) {
    if (resource->base == pci_bars_[0].address && offset < 0x3000) {
      if (offset < capability_regs_.capability_length) {
        memcpy(data, (uint8_t*)&capability_regs_ + offset, size);
      } else if (offset < capability_regs_.capability_length + 0x400ULL) {
        ReadOperationalRegs(offset - capability_regs_.capability_length, data, size);
      } else if (offset < 0x1000) {
        ReadPortRegs(offset - capability_regs_.capability_length - 0x400, data, size);
      } else if (offset < 0x2000) {
        ReadRuntimeRegs(offset - 0x1000, data, size);
      } else if (offset < 0x3000) {
        bzero(data, size);
      }
      // if (debug_) {
      //   MV_LOG("Read offset=0x%lx size=%u data=0x%lx", offset, size, *(uint64_t*)data);
      // }
    } else {
      PciDevice::Read(resource, offset, data, size);
    }
  }

  void Write(const IoResource* resource, uint64_t offset, uint8_t* data, uint32_t size) {
    if (resource->base == pci_bars_[0].address && offset < 0x3000) {
      std::lock_guard<std::mutex> lock(mutex_);
      // if (debug_) {
      //   MV_LOG("Write offset=0x%lx size=%u data=0x%lx", offset, size, *(uint64_t*)data);
      // }
      if (offset < capability_regs_.capability_length) {
      } else if (offset < capability_regs_.capability_length + 0x400ULL) {
        WriteOperationalRegs(offset - capability_regs_.capability_length, data, size);
      } else if (offset < 0x1000) {
        WritePortRegs(offset - capability_regs_.capability_length - 0x400, data, size);
      } else if (offset < 0x2000) {
        WriteRuntimeRegs(offset - 0x1000, data, size);
      } else if (offset < 0x3000) {
        WriteDoorbellRegs(resource->base + offset, offset - 0x2000, data, size);
      }
    } else {
      PciDevice::Write(resource, offset, data, size);
    }
  }
};

DECLARE_DEVICE(XhciHost);
