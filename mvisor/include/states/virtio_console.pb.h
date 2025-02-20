// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: virtio_console.proto

#ifndef PROTOBUF_virtio_5fconsole_2eproto__INCLUDED
#define PROTOBUF_virtio_5fconsole_2eproto__INCLUDED

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

namespace protobuf_virtio_5fconsole_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsVirtioConsoleState_PortImpl();
void InitDefaultsVirtioConsoleState_Port();
void InitDefaultsVirtioConsoleStateImpl();
void InitDefaultsVirtioConsoleState();
inline void InitDefaults() {
  InitDefaultsVirtioConsoleState_Port();
  InitDefaultsVirtioConsoleState();
}
}  // namespace protobuf_virtio_5fconsole_2eproto
class VirtioConsoleState;
class VirtioConsoleStateDefaultTypeInternal;
extern VirtioConsoleStateDefaultTypeInternal _VirtioConsoleState_default_instance_;
class VirtioConsoleState_Port;
class VirtioConsoleState_PortDefaultTypeInternal;
extern VirtioConsoleState_PortDefaultTypeInternal _VirtioConsoleState_Port_default_instance_;

// ===================================================================

class VirtioConsoleState_Port : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:VirtioConsoleState.Port) */ {
 public:
  VirtioConsoleState_Port();
  virtual ~VirtioConsoleState_Port();

  VirtioConsoleState_Port(const VirtioConsoleState_Port& from);

  inline VirtioConsoleState_Port& operator=(const VirtioConsoleState_Port& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VirtioConsoleState_Port(VirtioConsoleState_Port&& from) noexcept
    : VirtioConsoleState_Port() {
    *this = ::std::move(from);
  }

  inline VirtioConsoleState_Port& operator=(VirtioConsoleState_Port&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VirtioConsoleState_Port& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VirtioConsoleState_Port* internal_default_instance() {
    return reinterpret_cast<const VirtioConsoleState_Port*>(
               &_VirtioConsoleState_Port_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(VirtioConsoleState_Port* other);
  friend void swap(VirtioConsoleState_Port& a, VirtioConsoleState_Port& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VirtioConsoleState_Port* New() const PROTOBUF_FINAL { return New(NULL); }

  VirtioConsoleState_Port* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VirtioConsoleState_Port& from);
  void MergeFrom(const VirtioConsoleState_Port& from);
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
  void InternalSwap(VirtioConsoleState_Port* other);
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

  // uint32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // bool ready = 2;
  void clear_ready();
  static const int kReadyFieldNumber = 2;
  bool ready() const;
  void set_ready(bool value);

  // @@protoc_insertion_point(class_scope:VirtioConsoleState.Port)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 id_;
  bool ready_;
  mutable int _cached_size_;
  friend struct ::protobuf_virtio_5fconsole_2eproto::TableStruct;
  friend void ::protobuf_virtio_5fconsole_2eproto::InitDefaultsVirtioConsoleState_PortImpl();
};
// -------------------------------------------------------------------

class VirtioConsoleState : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:VirtioConsoleState) */ {
 public:
  VirtioConsoleState();
  virtual ~VirtioConsoleState();

  VirtioConsoleState(const VirtioConsoleState& from);

  inline VirtioConsoleState& operator=(const VirtioConsoleState& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  VirtioConsoleState(VirtioConsoleState&& from) noexcept
    : VirtioConsoleState() {
    *this = ::std::move(from);
  }

  inline VirtioConsoleState& operator=(VirtioConsoleState&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const VirtioConsoleState& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VirtioConsoleState* internal_default_instance() {
    return reinterpret_cast<const VirtioConsoleState*>(
               &_VirtioConsoleState_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(VirtioConsoleState* other);
  friend void swap(VirtioConsoleState& a, VirtioConsoleState& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline VirtioConsoleState* New() const PROTOBUF_FINAL { return New(NULL); }

  VirtioConsoleState* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VirtioConsoleState& from);
  void MergeFrom(const VirtioConsoleState& from);
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
  void InternalSwap(VirtioConsoleState* other);
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

  typedef VirtioConsoleState_Port Port;

  // accessors -------------------------------------------------------

  // repeated .VirtioConsoleState.Port ports = 1;
  int ports_size() const;
  void clear_ports();
  static const int kPortsFieldNumber = 1;
  const ::VirtioConsoleState_Port& ports(int index) const;
  ::VirtioConsoleState_Port* mutable_ports(int index);
  ::VirtioConsoleState_Port* add_ports();
  ::google::protobuf::RepeatedPtrField< ::VirtioConsoleState_Port >*
      mutable_ports();
  const ::google::protobuf::RepeatedPtrField< ::VirtioConsoleState_Port >&
      ports() const;

  // @@protoc_insertion_point(class_scope:VirtioConsoleState)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::VirtioConsoleState_Port > ports_;
  mutable int _cached_size_;
  friend struct ::protobuf_virtio_5fconsole_2eproto::TableStruct;
  friend void ::protobuf_virtio_5fconsole_2eproto::InitDefaultsVirtioConsoleStateImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// VirtioConsoleState_Port

// uint32 id = 1;
inline void VirtioConsoleState_Port::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 VirtioConsoleState_Port::id() const {
  // @@protoc_insertion_point(field_get:VirtioConsoleState.Port.id)
  return id_;
}
inline void VirtioConsoleState_Port::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:VirtioConsoleState.Port.id)
}

// bool ready = 2;
inline void VirtioConsoleState_Port::clear_ready() {
  ready_ = false;
}
inline bool VirtioConsoleState_Port::ready() const {
  // @@protoc_insertion_point(field_get:VirtioConsoleState.Port.ready)
  return ready_;
}
inline void VirtioConsoleState_Port::set_ready(bool value) {
  
  ready_ = value;
  // @@protoc_insertion_point(field_set:VirtioConsoleState.Port.ready)
}

// -------------------------------------------------------------------

// VirtioConsoleState

// repeated .VirtioConsoleState.Port ports = 1;
inline int VirtioConsoleState::ports_size() const {
  return ports_.size();
}
inline void VirtioConsoleState::clear_ports() {
  ports_.Clear();
}
inline const ::VirtioConsoleState_Port& VirtioConsoleState::ports(int index) const {
  // @@protoc_insertion_point(field_get:VirtioConsoleState.ports)
  return ports_.Get(index);
}
inline ::VirtioConsoleState_Port* VirtioConsoleState::mutable_ports(int index) {
  // @@protoc_insertion_point(field_mutable:VirtioConsoleState.ports)
  return ports_.Mutable(index);
}
inline ::VirtioConsoleState_Port* VirtioConsoleState::add_ports() {
  // @@protoc_insertion_point(field_add:VirtioConsoleState.ports)
  return ports_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::VirtioConsoleState_Port >*
VirtioConsoleState::mutable_ports() {
  // @@protoc_insertion_point(field_mutable_list:VirtioConsoleState.ports)
  return &ports_;
}
inline const ::google::protobuf::RepeatedPtrField< ::VirtioConsoleState_Port >&
VirtioConsoleState::ports() const {
  // @@protoc_insertion_point(field_list:VirtioConsoleState.ports)
  return ports_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_virtio_5fconsole_2eproto__INCLUDED
