// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: usb_device.proto

#ifndef PROTOBUF_usb_5fdevice_2eproto__INCLUDED
#define PROTOBUF_usb_5fdevice_2eproto__INCLUDED

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

namespace protobuf_usb_5fdevice_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsUsbDeviceStateImpl();
void InitDefaultsUsbDeviceState();
inline void InitDefaults() {
  InitDefaultsUsbDeviceState();
}
}  // namespace protobuf_usb_5fdevice_2eproto
class UsbDeviceState;
class UsbDeviceStateDefaultTypeInternal;
extern UsbDeviceStateDefaultTypeInternal _UsbDeviceState_default_instance_;

// ===================================================================

class UsbDeviceState : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:UsbDeviceState) */ {
 public:
  UsbDeviceState();
  virtual ~UsbDeviceState();

  UsbDeviceState(const UsbDeviceState& from);

  inline UsbDeviceState& operator=(const UsbDeviceState& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  UsbDeviceState(UsbDeviceState&& from) noexcept
    : UsbDeviceState() {
    *this = ::std::move(from);
  }

  inline UsbDeviceState& operator=(UsbDeviceState&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const UsbDeviceState& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UsbDeviceState* internal_default_instance() {
    return reinterpret_cast<const UsbDeviceState*>(
               &_UsbDeviceState_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(UsbDeviceState* other);
  friend void swap(UsbDeviceState& a, UsbDeviceState& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline UsbDeviceState* New() const PROTOBUF_FINAL { return New(NULL); }

  UsbDeviceState* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const UsbDeviceState& from);
  void MergeFrom(const UsbDeviceState& from);
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
  void InternalSwap(UsbDeviceState* other);
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

  // uint32 configuration_value = 1;
  void clear_configuration_value();
  static const int kConfigurationValueFieldNumber = 1;
  ::google::protobuf::uint32 configuration_value() const;
  void set_configuration_value(::google::protobuf::uint32 value);

  // uint32 remote_wakeup = 2;
  void clear_remote_wakeup();
  static const int kRemoteWakeupFieldNumber = 2;
  ::google::protobuf::uint32 remote_wakeup() const;
  void set_remote_wakeup(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:UsbDeviceState)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 configuration_value_;
  ::google::protobuf::uint32 remote_wakeup_;
  mutable int _cached_size_;
  friend struct ::protobuf_usb_5fdevice_2eproto::TableStruct;
  friend void ::protobuf_usb_5fdevice_2eproto::InitDefaultsUsbDeviceStateImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UsbDeviceState

// uint32 configuration_value = 1;
inline void UsbDeviceState::clear_configuration_value() {
  configuration_value_ = 0u;
}
inline ::google::protobuf::uint32 UsbDeviceState::configuration_value() const {
  // @@protoc_insertion_point(field_get:UsbDeviceState.configuration_value)
  return configuration_value_;
}
inline void UsbDeviceState::set_configuration_value(::google::protobuf::uint32 value) {
  
  configuration_value_ = value;
  // @@protoc_insertion_point(field_set:UsbDeviceState.configuration_value)
}

// uint32 remote_wakeup = 2;
inline void UsbDeviceState::clear_remote_wakeup() {
  remote_wakeup_ = 0u;
}
inline ::google::protobuf::uint32 UsbDeviceState::remote_wakeup() const {
  // @@protoc_insertion_point(field_get:UsbDeviceState.remote_wakeup)
  return remote_wakeup_;
}
inline void UsbDeviceState::set_remote_wakeup(::google::protobuf::uint32 value) {
  
  remote_wakeup_ = value;
  // @@protoc_insertion_point(field_set:UsbDeviceState.remote_wakeup)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_usb_5fdevice_2eproto__INCLUDED
