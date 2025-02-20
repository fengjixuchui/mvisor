// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ich9_lpc.proto

#ifndef PROTOBUF_ich9_5flpc_2eproto__INCLUDED
#define PROTOBUF_ich9_5flpc_2eproto__INCLUDED

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

namespace protobuf_ich9_5flpc_2eproto {
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
void InitDefaultsIch9LpcState_ApmImpl();
void InitDefaultsIch9LpcState_Apm();
void InitDefaultsIch9LpcState_AcpiImpl();
void InitDefaultsIch9LpcState_Acpi();
void InitDefaultsIch9LpcStateImpl();
void InitDefaultsIch9LpcState();
inline void InitDefaults() {
  InitDefaultsIch9LpcState_Apm();
  InitDefaultsIch9LpcState_Acpi();
  InitDefaultsIch9LpcState();
}
}  // namespace protobuf_ich9_5flpc_2eproto
class Ich9LpcState;
class Ich9LpcStateDefaultTypeInternal;
extern Ich9LpcStateDefaultTypeInternal _Ich9LpcState_default_instance_;
class Ich9LpcState_Acpi;
class Ich9LpcState_AcpiDefaultTypeInternal;
extern Ich9LpcState_AcpiDefaultTypeInternal _Ich9LpcState_Acpi_default_instance_;
class Ich9LpcState_Apm;
class Ich9LpcState_ApmDefaultTypeInternal;
extern Ich9LpcState_ApmDefaultTypeInternal _Ich9LpcState_Apm_default_instance_;

// ===================================================================

class Ich9LpcState_Apm : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Ich9LpcState.Apm) */ {
 public:
  Ich9LpcState_Apm();
  virtual ~Ich9LpcState_Apm();

  Ich9LpcState_Apm(const Ich9LpcState_Apm& from);

  inline Ich9LpcState_Apm& operator=(const Ich9LpcState_Apm& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Ich9LpcState_Apm(Ich9LpcState_Apm&& from) noexcept
    : Ich9LpcState_Apm() {
    *this = ::std::move(from);
  }

  inline Ich9LpcState_Apm& operator=(Ich9LpcState_Apm&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ich9LpcState_Apm& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Ich9LpcState_Apm* internal_default_instance() {
    return reinterpret_cast<const Ich9LpcState_Apm*>(
               &_Ich9LpcState_Apm_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Ich9LpcState_Apm* other);
  friend void swap(Ich9LpcState_Apm& a, Ich9LpcState_Apm& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Ich9LpcState_Apm* New() const PROTOBUF_FINAL { return New(NULL); }

  Ich9LpcState_Apm* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Ich9LpcState_Apm& from);
  void MergeFrom(const Ich9LpcState_Apm& from);
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
  void InternalSwap(Ich9LpcState_Apm* other);
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

  // uint32 control = 1;
  void clear_control();
  static const int kControlFieldNumber = 1;
  ::google::protobuf::uint32 control() const;
  void set_control(::google::protobuf::uint32 value);

  // uint32 status = 2;
  void clear_status();
  static const int kStatusFieldNumber = 2;
  ::google::protobuf::uint32 status() const;
  void set_status(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Ich9LpcState.Apm)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 control_;
  ::google::protobuf::uint32 status_;
  mutable int _cached_size_;
  friend struct ::protobuf_ich9_5flpc_2eproto::TableStruct;
  friend void ::protobuf_ich9_5flpc_2eproto::InitDefaultsIch9LpcState_ApmImpl();
};
// -------------------------------------------------------------------

class Ich9LpcState_Acpi : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Ich9LpcState.Acpi) */ {
 public:
  Ich9LpcState_Acpi();
  virtual ~Ich9LpcState_Acpi();

  Ich9LpcState_Acpi(const Ich9LpcState_Acpi& from);

  inline Ich9LpcState_Acpi& operator=(const Ich9LpcState_Acpi& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Ich9LpcState_Acpi(Ich9LpcState_Acpi&& from) noexcept
    : Ich9LpcState_Acpi() {
    *this = ::std::move(from);
  }

  inline Ich9LpcState_Acpi& operator=(Ich9LpcState_Acpi&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ich9LpcState_Acpi& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Ich9LpcState_Acpi* internal_default_instance() {
    return reinterpret_cast<const Ich9LpcState_Acpi*>(
               &_Ich9LpcState_Acpi_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Ich9LpcState_Acpi* other);
  friend void swap(Ich9LpcState_Acpi& a, Ich9LpcState_Acpi& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Ich9LpcState_Acpi* New() const PROTOBUF_FINAL { return New(NULL); }

  Ich9LpcState_Acpi* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Ich9LpcState_Acpi& from);
  void MergeFrom(const Ich9LpcState_Acpi& from);
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
  void InternalSwap(Ich9LpcState_Acpi* other);
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

  // uint32 pm1_status = 1;
  void clear_pm1_status();
  static const int kPm1StatusFieldNumber = 1;
  ::google::protobuf::uint32 pm1_status() const;
  void set_pm1_status(::google::protobuf::uint32 value);

  // uint32 pm1_enable = 2;
  void clear_pm1_enable();
  static const int kPm1EnableFieldNumber = 2;
  ::google::protobuf::uint32 pm1_enable() const;
  void set_pm1_enable(::google::protobuf::uint32 value);

  // uint32 pm1_control = 3;
  void clear_pm1_control();
  static const int kPm1ControlFieldNumber = 3;
  ::google::protobuf::uint32 pm1_control() const;
  void set_pm1_control(::google::protobuf::uint32 value);

  // uint32 pm1_timer = 4;
  void clear_pm1_timer();
  static const int kPm1TimerFieldNumber = 4;
  ::google::protobuf::uint32 pm1_timer() const;
  void set_pm1_timer(::google::protobuf::uint32 value);

  // uint64 gpe0_status = 10;
  void clear_gpe0_status();
  static const int kGpe0StatusFieldNumber = 10;
  ::google::protobuf::uint64 gpe0_status() const;
  void set_gpe0_status(::google::protobuf::uint64 value);

  // uint64 gpe0_enable = 11;
  void clear_gpe0_enable();
  static const int kGpe0EnableFieldNumber = 11;
  ::google::protobuf::uint64 gpe0_enable() const;
  void set_gpe0_enable(::google::protobuf::uint64 value);

  // uint32 smi_enable = 12;
  void clear_smi_enable();
  static const int kSmiEnableFieldNumber = 12;
  ::google::protobuf::uint32 smi_enable() const;
  void set_smi_enable(::google::protobuf::uint32 value);

  // uint32 smi_status = 13;
  void clear_smi_status();
  static const int kSmiStatusFieldNumber = 13;
  ::google::protobuf::uint32 smi_status() const;
  void set_smi_status(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Ich9LpcState.Acpi)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 pm1_status_;
  ::google::protobuf::uint32 pm1_enable_;
  ::google::protobuf::uint32 pm1_control_;
  ::google::protobuf::uint32 pm1_timer_;
  ::google::protobuf::uint64 gpe0_status_;
  ::google::protobuf::uint64 gpe0_enable_;
  ::google::protobuf::uint32 smi_enable_;
  ::google::protobuf::uint32 smi_status_;
  mutable int _cached_size_;
  friend struct ::protobuf_ich9_5flpc_2eproto::TableStruct;
  friend void ::protobuf_ich9_5flpc_2eproto::InitDefaultsIch9LpcState_AcpiImpl();
};
// -------------------------------------------------------------------

class Ich9LpcState : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Ich9LpcState) */ {
 public:
  Ich9LpcState();
  virtual ~Ich9LpcState();

  Ich9LpcState(const Ich9LpcState& from);

  inline Ich9LpcState& operator=(const Ich9LpcState& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Ich9LpcState(Ich9LpcState&& from) noexcept
    : Ich9LpcState() {
    *this = ::std::move(from);
  }

  inline Ich9LpcState& operator=(Ich9LpcState&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ich9LpcState& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Ich9LpcState* internal_default_instance() {
    return reinterpret_cast<const Ich9LpcState*>(
               &_Ich9LpcState_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(Ich9LpcState* other);
  friend void swap(Ich9LpcState& a, Ich9LpcState& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Ich9LpcState* New() const PROTOBUF_FINAL { return New(NULL); }

  Ich9LpcState* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Ich9LpcState& from);
  void MergeFrom(const Ich9LpcState& from);
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
  void InternalSwap(Ich9LpcState* other);
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

  typedef Ich9LpcState_Apm Apm;
  typedef Ich9LpcState_Acpi Acpi;

  // accessors -------------------------------------------------------

  // .Ich9LpcState.Apm apm = 1;
  bool has_apm() const;
  void clear_apm();
  static const int kApmFieldNumber = 1;
  const ::Ich9LpcState_Apm& apm() const;
  ::Ich9LpcState_Apm* release_apm();
  ::Ich9LpcState_Apm* mutable_apm();
  void set_allocated_apm(::Ich9LpcState_Apm* apm);

  // .Ich9LpcState.Acpi acpi = 2;
  bool has_acpi() const;
  void clear_acpi();
  static const int kAcpiFieldNumber = 2;
  const ::Ich9LpcState_Acpi& acpi() const;
  ::Ich9LpcState_Acpi* release_acpi();
  ::Ich9LpcState_Acpi* mutable_acpi();
  void set_allocated_acpi(::Ich9LpcState_Acpi* acpi);

  // @@protoc_insertion_point(class_scope:Ich9LpcState)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Ich9LpcState_Apm* apm_;
  ::Ich9LpcState_Acpi* acpi_;
  mutable int _cached_size_;
  friend struct ::protobuf_ich9_5flpc_2eproto::TableStruct;
  friend void ::protobuf_ich9_5flpc_2eproto::InitDefaultsIch9LpcStateImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Ich9LpcState_Apm

// uint32 control = 1;
inline void Ich9LpcState_Apm::clear_control() {
  control_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Apm::control() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Apm.control)
  return control_;
}
inline void Ich9LpcState_Apm::set_control(::google::protobuf::uint32 value) {
  
  control_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Apm.control)
}

// uint32 status = 2;
inline void Ich9LpcState_Apm::clear_status() {
  status_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Apm::status() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Apm.status)
  return status_;
}
inline void Ich9LpcState_Apm::set_status(::google::protobuf::uint32 value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Apm.status)
}

// -------------------------------------------------------------------

// Ich9LpcState_Acpi

// uint32 pm1_status = 1;
inline void Ich9LpcState_Acpi::clear_pm1_status() {
  pm1_status_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Acpi::pm1_status() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.pm1_status)
  return pm1_status_;
}
inline void Ich9LpcState_Acpi::set_pm1_status(::google::protobuf::uint32 value) {
  
  pm1_status_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.pm1_status)
}

// uint32 pm1_enable = 2;
inline void Ich9LpcState_Acpi::clear_pm1_enable() {
  pm1_enable_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Acpi::pm1_enable() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.pm1_enable)
  return pm1_enable_;
}
inline void Ich9LpcState_Acpi::set_pm1_enable(::google::protobuf::uint32 value) {
  
  pm1_enable_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.pm1_enable)
}

// uint32 pm1_control = 3;
inline void Ich9LpcState_Acpi::clear_pm1_control() {
  pm1_control_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Acpi::pm1_control() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.pm1_control)
  return pm1_control_;
}
inline void Ich9LpcState_Acpi::set_pm1_control(::google::protobuf::uint32 value) {
  
  pm1_control_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.pm1_control)
}

// uint32 pm1_timer = 4;
inline void Ich9LpcState_Acpi::clear_pm1_timer() {
  pm1_timer_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Acpi::pm1_timer() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.pm1_timer)
  return pm1_timer_;
}
inline void Ich9LpcState_Acpi::set_pm1_timer(::google::protobuf::uint32 value) {
  
  pm1_timer_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.pm1_timer)
}

// uint64 gpe0_status = 10;
inline void Ich9LpcState_Acpi::clear_gpe0_status() {
  gpe0_status_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Ich9LpcState_Acpi::gpe0_status() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.gpe0_status)
  return gpe0_status_;
}
inline void Ich9LpcState_Acpi::set_gpe0_status(::google::protobuf::uint64 value) {
  
  gpe0_status_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.gpe0_status)
}

// uint64 gpe0_enable = 11;
inline void Ich9LpcState_Acpi::clear_gpe0_enable() {
  gpe0_enable_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Ich9LpcState_Acpi::gpe0_enable() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.gpe0_enable)
  return gpe0_enable_;
}
inline void Ich9LpcState_Acpi::set_gpe0_enable(::google::protobuf::uint64 value) {
  
  gpe0_enable_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.gpe0_enable)
}

// uint32 smi_enable = 12;
inline void Ich9LpcState_Acpi::clear_smi_enable() {
  smi_enable_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Acpi::smi_enable() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.smi_enable)
  return smi_enable_;
}
inline void Ich9LpcState_Acpi::set_smi_enable(::google::protobuf::uint32 value) {
  
  smi_enable_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.smi_enable)
}

// uint32 smi_status = 13;
inline void Ich9LpcState_Acpi::clear_smi_status() {
  smi_status_ = 0u;
}
inline ::google::protobuf::uint32 Ich9LpcState_Acpi::smi_status() const {
  // @@protoc_insertion_point(field_get:Ich9LpcState.Acpi.smi_status)
  return smi_status_;
}
inline void Ich9LpcState_Acpi::set_smi_status(::google::protobuf::uint32 value) {
  
  smi_status_ = value;
  // @@protoc_insertion_point(field_set:Ich9LpcState.Acpi.smi_status)
}

// -------------------------------------------------------------------

// Ich9LpcState

// .Ich9LpcState.Apm apm = 1;
inline bool Ich9LpcState::has_apm() const {
  return this != internal_default_instance() && apm_ != NULL;
}
inline void Ich9LpcState::clear_apm() {
  if (GetArenaNoVirtual() == NULL && apm_ != NULL) {
    delete apm_;
  }
  apm_ = NULL;
}
inline const ::Ich9LpcState_Apm& Ich9LpcState::apm() const {
  const ::Ich9LpcState_Apm* p = apm_;
  // @@protoc_insertion_point(field_get:Ich9LpcState.apm)
  return p != NULL ? *p : *reinterpret_cast<const ::Ich9LpcState_Apm*>(
      &::_Ich9LpcState_Apm_default_instance_);
}
inline ::Ich9LpcState_Apm* Ich9LpcState::release_apm() {
  // @@protoc_insertion_point(field_release:Ich9LpcState.apm)
  
  ::Ich9LpcState_Apm* temp = apm_;
  apm_ = NULL;
  return temp;
}
inline ::Ich9LpcState_Apm* Ich9LpcState::mutable_apm() {
  
  if (apm_ == NULL) {
    apm_ = new ::Ich9LpcState_Apm;
  }
  // @@protoc_insertion_point(field_mutable:Ich9LpcState.apm)
  return apm_;
}
inline void Ich9LpcState::set_allocated_apm(::Ich9LpcState_Apm* apm) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete apm_;
  }
  if (apm) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      apm = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, apm, submessage_arena);
    }
    
  } else {
    
  }
  apm_ = apm;
  // @@protoc_insertion_point(field_set_allocated:Ich9LpcState.apm)
}

// .Ich9LpcState.Acpi acpi = 2;
inline bool Ich9LpcState::has_acpi() const {
  return this != internal_default_instance() && acpi_ != NULL;
}
inline void Ich9LpcState::clear_acpi() {
  if (GetArenaNoVirtual() == NULL && acpi_ != NULL) {
    delete acpi_;
  }
  acpi_ = NULL;
}
inline const ::Ich9LpcState_Acpi& Ich9LpcState::acpi() const {
  const ::Ich9LpcState_Acpi* p = acpi_;
  // @@protoc_insertion_point(field_get:Ich9LpcState.acpi)
  return p != NULL ? *p : *reinterpret_cast<const ::Ich9LpcState_Acpi*>(
      &::_Ich9LpcState_Acpi_default_instance_);
}
inline ::Ich9LpcState_Acpi* Ich9LpcState::release_acpi() {
  // @@protoc_insertion_point(field_release:Ich9LpcState.acpi)
  
  ::Ich9LpcState_Acpi* temp = acpi_;
  acpi_ = NULL;
  return temp;
}
inline ::Ich9LpcState_Acpi* Ich9LpcState::mutable_acpi() {
  
  if (acpi_ == NULL) {
    acpi_ = new ::Ich9LpcState_Acpi;
  }
  // @@protoc_insertion_point(field_mutable:Ich9LpcState.acpi)
  return acpi_;
}
inline void Ich9LpcState::set_allocated_acpi(::Ich9LpcState_Acpi* acpi) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete acpi_;
  }
  if (acpi) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      acpi = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, acpi, submessage_arena);
    }
    
  } else {
    
  }
  acpi_ = acpi;
  // @@protoc_insertion_point(field_set_allocated:Ich9LpcState.acpi)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ich9_5flpc_2eproto__INCLUDED
