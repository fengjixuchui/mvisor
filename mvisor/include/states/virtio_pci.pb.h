// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: virtio_pci.proto

#ifndef PROTOBUF_virtio_5fpci_2eproto__INCLUDED
#define PROTOBUF_virtio_5fpci_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_virtio_5fpci_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsVirtioPciState_CommonConfigImpl();
void InitDefaultsVirtioPciState_CommonConfig();
void InitDefaultsVirtioPciState_QueueImpl();
void InitDefaultsVirtioPciState_Queue();
void InitDefaultsVirtioPciStateImpl();
void InitDefaultsVirtioPciState();
inline void InitDefaults() {
  InitDefaultsVirtioPciState_CommonConfig();
  InitDefaultsVirtioPciState_Queue();
  InitDefaultsVirtioPciState();
}
}  // namespace protobuf_virtio_5fpci_2eproto
class VirtioPciState;
class VirtioPciStateDefaultTypeInternal;
extern VirtioPciStateDefaultTypeInternal _VirtioPciState_default_instance_;
class VirtioPciState_CommonConfig;
class VirtioPciState_CommonConfigDefaultTypeInternal;
extern VirtioPciState_CommonConfigDefaultTypeInternal _VirtioPciState_CommonConfig_default_instance_;
class VirtioPciState_Queue;
class VirtioPciState_QueueDefaultTypeInternal;
extern VirtioPciState_QueueDefaultTypeInternal _VirtioPciState_Queue_default_instance_;

// ===================================================================

class VirtioPciState_CommonConfig : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:VirtioPciState.CommonConfig) */ {
 public:
  VirtioPciState_CommonConfig();
  virtual ~VirtioPciState_CommonConfig();

  VirtioPciState_CommonConfig(const VirtioPciState_CommonConfig& from);

  inline VirtioPciState_CommonConfig& operator=(const VirtioPciState_CommonConfig& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VirtioPciState_CommonConfig(VirtioPciState_CommonConfig&& from) noexcept
    : VirtioPciState_CommonConfig() {
    *this = ::std::move(from);
  }

  inline VirtioPciState_CommonConfig& operator=(VirtioPciState_CommonConfig&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VirtioPciState_CommonConfig& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VirtioPciState_CommonConfig* internal_default_instance() {
    return reinterpret_cast<const VirtioPciState_CommonConfig*>(
               &_VirtioPciState_CommonConfig_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(VirtioPciState_CommonConfig* other);
  friend void swap(VirtioPciState_CommonConfig& a, VirtioPciState_CommonConfig& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VirtioPciState_CommonConfig* New() const PROTOBUF_FINAL { return New(NULL); }

  VirtioPciState_CommonConfig* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VirtioPciState_CommonConfig& from);
  void MergeFrom(const VirtioPciState_CommonConfig& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(VirtioPciState_CommonConfig* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 guest_feature = 4;
  void clear_guest_feature();
  static const int kGuestFeatureFieldNumber = 4;
  ::google::protobuf::uint64 guest_feature() const;
  void set_guest_feature(::google::protobuf::uint64 value);

  // uint32 queue_select = 10;
  void clear_queue_select();
  static const int kQueueSelectFieldNumber = 10;
  ::google::protobuf::uint32 queue_select() const;
  void set_queue_select(::google::protobuf::uint32 value);

  // uint32 msix_config = 5;
  void clear_msix_config();
  static const int kMsixConfigFieldNumber = 5;
  ::google::protobuf::uint32 msix_config() const;
  void set_msix_config(::google::protobuf::uint32 value);

  // uint32 device_status = 7;
  void clear_device_status();
  static const int kDeviceStatusFieldNumber = 7;
  ::google::protobuf::uint32 device_status() const;
  void set_device_status(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:VirtioPciState.CommonConfig)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 guest_feature_;
  ::google::protobuf::uint32 queue_select_;
  ::google::protobuf::uint32 msix_config_;
  ::google::protobuf::uint32 device_status_;
  mutable int _cached_size_;
  friend struct ::protobuf_virtio_5fpci_2eproto::TableStruct;
  friend void ::protobuf_virtio_5fpci_2eproto::InitDefaultsVirtioPciState_CommonConfigImpl();
};
// -------------------------------------------------------------------

class VirtioPciState_Queue : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:VirtioPciState.Queue) */ {
 public:
  VirtioPciState_Queue();
  virtual ~VirtioPciState_Queue();

  VirtioPciState_Queue(const VirtioPciState_Queue& from);

  inline VirtioPciState_Queue& operator=(const VirtioPciState_Queue& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VirtioPciState_Queue(VirtioPciState_Queue&& from) noexcept
    : VirtioPciState_Queue() {
    *this = ::std::move(from);
  }

  inline VirtioPciState_Queue& operator=(VirtioPciState_Queue&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VirtioPciState_Queue& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VirtioPciState_Queue* internal_default_instance() {
    return reinterpret_cast<const VirtioPciState_Queue*>(
               &_VirtioPciState_Queue_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(VirtioPciState_Queue* other);
  friend void swap(VirtioPciState_Queue& a, VirtioPciState_Queue& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VirtioPciState_Queue* New() const PROTOBUF_FINAL { return New(NULL); }

  VirtioPciState_Queue* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VirtioPciState_Queue& from);
  void MergeFrom(const VirtioPciState_Queue& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(VirtioPciState_Queue* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool enabled = 1;
  void clear_enabled();
  static const int kEnabledFieldNumber = 1;
  bool enabled() const;
  void set_enabled(bool value);

  // int32 msix_vector = 2;
  void clear_msix_vector();
  static const int kMsixVectorFieldNumber = 2;
  ::google::protobuf::int32 msix_vector() const;
  void set_msix_vector(::google::protobuf::int32 value);

  // int32 size = 4;
  void clear_size();
  static const int kSizeFieldNumber = 4;
  ::google::protobuf::int32 size() const;
  void set_size(::google::protobuf::int32 value);

  // uint32 last_available_index = 5;
  void clear_last_available_index();
  static const int kLastAvailableIndexFieldNumber = 5;
  ::google::protobuf::uint32 last_available_index() const;
  void set_last_available_index(::google::protobuf::uint32 value);

  // uint64 descriptor_table_address = 6;
  void clear_descriptor_table_address();
  static const int kDescriptorTableAddressFieldNumber = 6;
  ::google::protobuf::uint64 descriptor_table_address() const;
  void set_descriptor_table_address(::google::protobuf::uint64 value);

  // uint64 available_ring_address = 7;
  void clear_available_ring_address();
  static const int kAvailableRingAddressFieldNumber = 7;
  ::google::protobuf::uint64 available_ring_address() const;
  void set_available_ring_address(::google::protobuf::uint64 value);

  // uint64 used_ring_address = 8;
  void clear_used_ring_address();
  static const int kUsedRingAddressFieldNumber = 8;
  ::google::protobuf::uint64 used_ring_address() const;
  void set_used_ring_address(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:VirtioPciState.Queue)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool enabled_;
  ::google::protobuf::int32 msix_vector_;
  ::google::protobuf::int32 size_;
  ::google::protobuf::uint32 last_available_index_;
  ::google::protobuf::uint64 descriptor_table_address_;
  ::google::protobuf::uint64 available_ring_address_;
  ::google::protobuf::uint64 used_ring_address_;
  mutable int _cached_size_;
  friend struct ::protobuf_virtio_5fpci_2eproto::TableStruct;
  friend void ::protobuf_virtio_5fpci_2eproto::InitDefaultsVirtioPciState_QueueImpl();
};
// -------------------------------------------------------------------

class VirtioPciState : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:VirtioPciState) */ {
 public:
  VirtioPciState();
  virtual ~VirtioPciState();

  VirtioPciState(const VirtioPciState& from);

  inline VirtioPciState& operator=(const VirtioPciState& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VirtioPciState(VirtioPciState&& from) noexcept
    : VirtioPciState() {
    *this = ::std::move(from);
  }

  inline VirtioPciState& operator=(VirtioPciState&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VirtioPciState& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VirtioPciState* internal_default_instance() {
    return reinterpret_cast<const VirtioPciState*>(
               &_VirtioPciState_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(VirtioPciState* other);
  friend void swap(VirtioPciState& a, VirtioPciState& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VirtioPciState* New() const PROTOBUF_FINAL { return New(NULL); }

  VirtioPciState* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VirtioPciState& from);
  void MergeFrom(const VirtioPciState& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(VirtioPciState* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef VirtioPciState_CommonConfig CommonConfig;
  typedef VirtioPciState_Queue Queue;

  // accessors -------------------------------------------------------

  // repeated .VirtioPciState.Queue queues = 2;
  int queues_size() const;
  void clear_queues();
  static const int kQueuesFieldNumber = 2;
  const ::VirtioPciState_Queue& queues(int index) const;
  ::VirtioPciState_Queue* mutable_queues(int index);
  ::VirtioPciState_Queue* add_queues();
  ::google::protobuf::RepeatedPtrField< ::VirtioPciState_Queue >*
      mutable_queues();
  const ::google::protobuf::RepeatedPtrField< ::VirtioPciState_Queue >&
      queues() const;

  // .VirtioPciState.CommonConfig common_config = 1;
  bool has_common_config() const;
  void clear_common_config();
  static const int kCommonConfigFieldNumber = 1;
  const ::VirtioPciState_CommonConfig& common_config() const;
  ::VirtioPciState_CommonConfig* release_common_config();
  ::VirtioPciState_CommonConfig* mutable_common_config();
  void set_allocated_common_config(::VirtioPciState_CommonConfig* common_config);

  // uint32 isr_status = 3;
  void clear_isr_status();
  static const int kIsrStatusFieldNumber = 3;
  ::google::protobuf::uint32 isr_status() const;
  void set_isr_status(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:VirtioPciState)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::VirtioPciState_Queue > queues_;
  ::VirtioPciState_CommonConfig* common_config_;
  ::google::protobuf::uint32 isr_status_;
  mutable int _cached_size_;
  friend struct ::protobuf_virtio_5fpci_2eproto::TableStruct;
  friend void ::protobuf_virtio_5fpci_2eproto::InitDefaultsVirtioPciStateImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// VirtioPciState_CommonConfig

// uint64 guest_feature = 4;
inline void VirtioPciState_CommonConfig::clear_guest_feature() {
  guest_feature_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 VirtioPciState_CommonConfig::guest_feature() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.CommonConfig.guest_feature)
  return guest_feature_;
}
inline void VirtioPciState_CommonConfig::set_guest_feature(::google::protobuf::uint64 value) {
  
  guest_feature_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.CommonConfig.guest_feature)
}

// uint32 msix_config = 5;
inline void VirtioPciState_CommonConfig::clear_msix_config() {
  msix_config_ = 0u;
}
inline ::google::protobuf::uint32 VirtioPciState_CommonConfig::msix_config() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.CommonConfig.msix_config)
  return msix_config_;
}
inline void VirtioPciState_CommonConfig::set_msix_config(::google::protobuf::uint32 value) {
  
  msix_config_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.CommonConfig.msix_config)
}

// uint32 device_status = 7;
inline void VirtioPciState_CommonConfig::clear_device_status() {
  device_status_ = 0u;
}
inline ::google::protobuf::uint32 VirtioPciState_CommonConfig::device_status() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.CommonConfig.device_status)
  return device_status_;
}
inline void VirtioPciState_CommonConfig::set_device_status(::google::protobuf::uint32 value) {
  
  device_status_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.CommonConfig.device_status)
}

// uint32 queue_select = 10;
inline void VirtioPciState_CommonConfig::clear_queue_select() {
  queue_select_ = 0u;
}
inline ::google::protobuf::uint32 VirtioPciState_CommonConfig::queue_select() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.CommonConfig.queue_select)
  return queue_select_;
}
inline void VirtioPciState_CommonConfig::set_queue_select(::google::protobuf::uint32 value) {
  
  queue_select_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.CommonConfig.queue_select)
}

// -------------------------------------------------------------------

// VirtioPciState_Queue

// bool enabled = 1;
inline void VirtioPciState_Queue::clear_enabled() {
  enabled_ = false;
}
inline bool VirtioPciState_Queue::enabled() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.enabled)
  return enabled_;
}
inline void VirtioPciState_Queue::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.enabled)
}

// int32 msix_vector = 2;
inline void VirtioPciState_Queue::clear_msix_vector() {
  msix_vector_ = 0;
}
inline ::google::protobuf::int32 VirtioPciState_Queue::msix_vector() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.msix_vector)
  return msix_vector_;
}
inline void VirtioPciState_Queue::set_msix_vector(::google::protobuf::int32 value) {
  
  msix_vector_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.msix_vector)
}

// int32 size = 4;
inline void VirtioPciState_Queue::clear_size() {
  size_ = 0;
}
inline ::google::protobuf::int32 VirtioPciState_Queue::size() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.size)
  return size_;
}
inline void VirtioPciState_Queue::set_size(::google::protobuf::int32 value) {
  
  size_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.size)
}

// uint32 last_available_index = 5;
inline void VirtioPciState_Queue::clear_last_available_index() {
  last_available_index_ = 0u;
}
inline ::google::protobuf::uint32 VirtioPciState_Queue::last_available_index() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.last_available_index)
  return last_available_index_;
}
inline void VirtioPciState_Queue::set_last_available_index(::google::protobuf::uint32 value) {
  
  last_available_index_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.last_available_index)
}

// uint64 descriptor_table_address = 6;
inline void VirtioPciState_Queue::clear_descriptor_table_address() {
  descriptor_table_address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 VirtioPciState_Queue::descriptor_table_address() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.descriptor_table_address)
  return descriptor_table_address_;
}
inline void VirtioPciState_Queue::set_descriptor_table_address(::google::protobuf::uint64 value) {
  
  descriptor_table_address_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.descriptor_table_address)
}

// uint64 available_ring_address = 7;
inline void VirtioPciState_Queue::clear_available_ring_address() {
  available_ring_address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 VirtioPciState_Queue::available_ring_address() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.available_ring_address)
  return available_ring_address_;
}
inline void VirtioPciState_Queue::set_available_ring_address(::google::protobuf::uint64 value) {
  
  available_ring_address_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.available_ring_address)
}

// uint64 used_ring_address = 8;
inline void VirtioPciState_Queue::clear_used_ring_address() {
  used_ring_address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 VirtioPciState_Queue::used_ring_address() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.Queue.used_ring_address)
  return used_ring_address_;
}
inline void VirtioPciState_Queue::set_used_ring_address(::google::protobuf::uint64 value) {
  
  used_ring_address_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.Queue.used_ring_address)
}

// -------------------------------------------------------------------

// VirtioPciState

// .VirtioPciState.CommonConfig common_config = 1;
inline bool VirtioPciState::has_common_config() const {
  return this != internal_default_instance() && common_config_ != NULL;
}
inline void VirtioPciState::clear_common_config() {
  if (GetArenaNoVirtual() == NULL && common_config_ != NULL) {
    delete common_config_;
  }
  common_config_ = NULL;
}
inline const ::VirtioPciState_CommonConfig& VirtioPciState::common_config() const {
  const ::VirtioPciState_CommonConfig* p = common_config_;
  // @@protoc_insertion_point(field_get:VirtioPciState.common_config)
  return p != NULL ? *p : *reinterpret_cast<const ::VirtioPciState_CommonConfig*>(
      &::_VirtioPciState_CommonConfig_default_instance_);
}
inline ::VirtioPciState_CommonConfig* VirtioPciState::release_common_config() {
  // @@protoc_insertion_point(field_release:VirtioPciState.common_config)
  
  ::VirtioPciState_CommonConfig* temp = common_config_;
  common_config_ = NULL;
  return temp;
}
inline ::VirtioPciState_CommonConfig* VirtioPciState::mutable_common_config() {
  
  if (common_config_ == NULL) {
    common_config_ = new ::VirtioPciState_CommonConfig;
  }
  // @@protoc_insertion_point(field_mutable:VirtioPciState.common_config)
  return common_config_;
}
inline void VirtioPciState::set_allocated_common_config(::VirtioPciState_CommonConfig* common_config) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete common_config_;
  }
  if (common_config) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      common_config = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, common_config, submessage_arena);
    }
    
  } else {
    
  }
  common_config_ = common_config;
  // @@protoc_insertion_point(field_set_allocated:VirtioPciState.common_config)
}

// repeated .VirtioPciState.Queue queues = 2;
inline int VirtioPciState::queues_size() const {
  return queues_.size();
}
inline void VirtioPciState::clear_queues() {
  queues_.Clear();
}
inline const ::VirtioPciState_Queue& VirtioPciState::queues(int index) const {
  // @@protoc_insertion_point(field_get:VirtioPciState.queues)
  return queues_.Get(index);
}
inline ::VirtioPciState_Queue* VirtioPciState::mutable_queues(int index) {
  // @@protoc_insertion_point(field_mutable:VirtioPciState.queues)
  return queues_.Mutable(index);
}
inline ::VirtioPciState_Queue* VirtioPciState::add_queues() {
  // @@protoc_insertion_point(field_add:VirtioPciState.queues)
  return queues_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::VirtioPciState_Queue >*
VirtioPciState::mutable_queues() {
  // @@protoc_insertion_point(field_mutable_list:VirtioPciState.queues)
  return &queues_;
}
inline const ::google::protobuf::RepeatedPtrField< ::VirtioPciState_Queue >&
VirtioPciState::queues() const {
  // @@protoc_insertion_point(field_list:VirtioPciState.queues)
  return queues_;
}

// uint32 isr_status = 3;
inline void VirtioPciState::clear_isr_status() {
  isr_status_ = 0u;
}
inline ::google::protobuf::uint32 VirtioPciState::isr_status() const {
  // @@protoc_insertion_point(field_get:VirtioPciState.isr_status)
  return isr_status_;
}
inline void VirtioPciState::set_isr_status(::google::protobuf::uint32 value) {
  
  isr_status_ = value;
  // @@protoc_insertion_point(field_set:VirtioPciState.isr_status)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_virtio_5fpci_2eproto__INCLUDED
