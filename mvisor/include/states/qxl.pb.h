// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: qxl.proto

#ifndef PROTOBUF_qxl_2eproto__INCLUDED
#define PROTOBUF_qxl_2eproto__INCLUDED

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

namespace protobuf_qxl_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsQxlState_GuestSlotImpl();
void InitDefaultsQxlState_GuestSlot();
void InitDefaultsQxlState_GuestPrimaryImpl();
void InitDefaultsQxlState_GuestPrimary();
void InitDefaultsQxlState_SurfaceImpl();
void InitDefaultsQxlState_Surface();
void InitDefaultsQxlState_DrawableImpl();
void InitDefaultsQxlState_Drawable();
void InitDefaultsQxlStateImpl();
void InitDefaultsQxlState();
inline void InitDefaults() {
  InitDefaultsQxlState_GuestSlot();
  InitDefaultsQxlState_GuestPrimary();
  InitDefaultsQxlState_Surface();
  InitDefaultsQxlState_Drawable();
  InitDefaultsQxlState();
}
}  // namespace protobuf_qxl_2eproto
class QxlState;
class QxlStateDefaultTypeInternal;
extern QxlStateDefaultTypeInternal _QxlState_default_instance_;
class QxlState_Drawable;
class QxlState_DrawableDefaultTypeInternal;
extern QxlState_DrawableDefaultTypeInternal _QxlState_Drawable_default_instance_;
class QxlState_GuestPrimary;
class QxlState_GuestPrimaryDefaultTypeInternal;
extern QxlState_GuestPrimaryDefaultTypeInternal _QxlState_GuestPrimary_default_instance_;
class QxlState_GuestSlot;
class QxlState_GuestSlotDefaultTypeInternal;
extern QxlState_GuestSlotDefaultTypeInternal _QxlState_GuestSlot_default_instance_;
class QxlState_Surface;
class QxlState_SurfaceDefaultTypeInternal;
extern QxlState_SurfaceDefaultTypeInternal _QxlState_Surface_default_instance_;

// ===================================================================

class QxlState_GuestSlot : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:QxlState.GuestSlot) */ {
 public:
  QxlState_GuestSlot();
  virtual ~QxlState_GuestSlot();

  QxlState_GuestSlot(const QxlState_GuestSlot& from);

  inline QxlState_GuestSlot& operator=(const QxlState_GuestSlot& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  QxlState_GuestSlot(QxlState_GuestSlot&& from) noexcept
    : QxlState_GuestSlot() {
    *this = ::std::move(from);
  }

  inline QxlState_GuestSlot& operator=(QxlState_GuestSlot&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const QxlState_GuestSlot& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const QxlState_GuestSlot* internal_default_instance() {
    return reinterpret_cast<const QxlState_GuestSlot*>(
               &_QxlState_GuestSlot_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(QxlState_GuestSlot* other);
  friend void swap(QxlState_GuestSlot& a, QxlState_GuestSlot& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline QxlState_GuestSlot* New() const PROTOBUF_FINAL { return New(NULL); }

  QxlState_GuestSlot* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const QxlState_GuestSlot& from);
  void MergeFrom(const QxlState_GuestSlot& from);
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
  void InternalSwap(QxlState_GuestSlot* other);
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

  // uint64 mem_start = 1;
  void clear_mem_start();
  static const int kMemStartFieldNumber = 1;
  ::google::protobuf::uint64 mem_start() const;
  void set_mem_start(::google::protobuf::uint64 value);

  // uint64 mem_end = 2;
  void clear_mem_end();
  static const int kMemEndFieldNumber = 2;
  ::google::protobuf::uint64 mem_end() const;
  void set_mem_end(::google::protobuf::uint64 value);

  // bool active = 3;
  void clear_active();
  static const int kActiveFieldNumber = 3;
  bool active() const;
  void set_active(bool value);

  // @@protoc_insertion_point(class_scope:QxlState.GuestSlot)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 mem_start_;
  ::google::protobuf::uint64 mem_end_;
  bool active_;
  mutable int _cached_size_;
  friend struct ::protobuf_qxl_2eproto::TableStruct;
  friend void ::protobuf_qxl_2eproto::InitDefaultsQxlState_GuestSlotImpl();
};
// -------------------------------------------------------------------

class QxlState_GuestPrimary : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:QxlState.GuestPrimary) */ {
 public:
  QxlState_GuestPrimary();
  virtual ~QxlState_GuestPrimary();

  QxlState_GuestPrimary(const QxlState_GuestPrimary& from);

  inline QxlState_GuestPrimary& operator=(const QxlState_GuestPrimary& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  QxlState_GuestPrimary(QxlState_GuestPrimary&& from) noexcept
    : QxlState_GuestPrimary() {
    *this = ::std::move(from);
  }

  inline QxlState_GuestPrimary& operator=(QxlState_GuestPrimary&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const QxlState_GuestPrimary& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const QxlState_GuestPrimary* internal_default_instance() {
    return reinterpret_cast<const QxlState_GuestPrimary*>(
               &_QxlState_GuestPrimary_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(QxlState_GuestPrimary* other);
  friend void swap(QxlState_GuestPrimary& a, QxlState_GuestPrimary& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline QxlState_GuestPrimary* New() const PROTOBUF_FINAL { return New(NULL); }

  QxlState_GuestPrimary* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const QxlState_GuestPrimary& from);
  void MergeFrom(const QxlState_GuestPrimary& from);
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
  void InternalSwap(QxlState_GuestPrimary* other);
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

  // uint32 width = 1;
  void clear_width();
  static const int kWidthFieldNumber = 1;
  ::google::protobuf::uint32 width() const;
  void set_width(::google::protobuf::uint32 value);

  // uint32 height = 2;
  void clear_height();
  static const int kHeightFieldNumber = 2;
  ::google::protobuf::uint32 height() const;
  void set_height(::google::protobuf::uint32 value);

  // int32 stride = 3;
  void clear_stride();
  static const int kStrideFieldNumber = 3;
  ::google::protobuf::int32 stride() const;
  void set_stride(::google::protobuf::int32 value);

  // uint32 format = 4;
  void clear_format();
  static const int kFormatFieldNumber = 4;
  ::google::protobuf::uint32 format() const;
  void set_format(::google::protobuf::uint32 value);

  // uint32 position = 5;
  void clear_position();
  static const int kPositionFieldNumber = 5;
  ::google::protobuf::uint32 position() const;
  void set_position(::google::protobuf::uint32 value);

  // uint32 mouse_mode = 6;
  void clear_mouse_mode();
  static const int kMouseModeFieldNumber = 6;
  ::google::protobuf::uint32 mouse_mode() const;
  void set_mouse_mode(::google::protobuf::uint32 value);

  // uint32 flags = 7;
  void clear_flags();
  static const int kFlagsFieldNumber = 7;
  ::google::protobuf::uint32 flags() const;
  void set_flags(::google::protobuf::uint32 value);

  // uint32 type = 8;
  void clear_type();
  static const int kTypeFieldNumber = 8;
  ::google::protobuf::uint32 type() const;
  void set_type(::google::protobuf::uint32 value);

  // uint64 mem_address = 9;
  void clear_mem_address();
  static const int kMemAddressFieldNumber = 9;
  ::google::protobuf::uint64 mem_address() const;
  void set_mem_address(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:QxlState.GuestPrimary)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 width_;
  ::google::protobuf::uint32 height_;
  ::google::protobuf::int32 stride_;
  ::google::protobuf::uint32 format_;
  ::google::protobuf::uint32 position_;
  ::google::protobuf::uint32 mouse_mode_;
  ::google::protobuf::uint32 flags_;
  ::google::protobuf::uint32 type_;
  ::google::protobuf::uint64 mem_address_;
  mutable int _cached_size_;
  friend struct ::protobuf_qxl_2eproto::TableStruct;
  friend void ::protobuf_qxl_2eproto::InitDefaultsQxlState_GuestPrimaryImpl();
};
// -------------------------------------------------------------------

class QxlState_Surface : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:QxlState.Surface) */ {
 public:
  QxlState_Surface();
  virtual ~QxlState_Surface();

  QxlState_Surface(const QxlState_Surface& from);

  inline QxlState_Surface& operator=(const QxlState_Surface& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  QxlState_Surface(QxlState_Surface&& from) noexcept
    : QxlState_Surface() {
    *this = ::std::move(from);
  }

  inline QxlState_Surface& operator=(QxlState_Surface&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const QxlState_Surface& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const QxlState_Surface* internal_default_instance() {
    return reinterpret_cast<const QxlState_Surface*>(
               &_QxlState_Surface_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(QxlState_Surface* other);
  friend void swap(QxlState_Surface& a, QxlState_Surface& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline QxlState_Surface* New() const PROTOBUF_FINAL { return New(NULL); }

  QxlState_Surface* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const QxlState_Surface& from);
  void MergeFrom(const QxlState_Surface& from);
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
  void InternalSwap(QxlState_Surface* other);
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

  // uint64 slot_address = 2;
  void clear_slot_address();
  static const int kSlotAddressFieldNumber = 2;
  ::google::protobuf::uint64 slot_address() const;
  void set_slot_address(::google::protobuf::uint64 value);

  // uint32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:QxlState.Surface)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 slot_address_;
  ::google::protobuf::uint32 id_;
  mutable int _cached_size_;
  friend struct ::protobuf_qxl_2eproto::TableStruct;
  friend void ::protobuf_qxl_2eproto::InitDefaultsQxlState_SurfaceImpl();
};
// -------------------------------------------------------------------

class QxlState_Drawable : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:QxlState.Drawable) */ {
 public:
  QxlState_Drawable();
  virtual ~QxlState_Drawable();

  QxlState_Drawable(const QxlState_Drawable& from);

  inline QxlState_Drawable& operator=(const QxlState_Drawable& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  QxlState_Drawable(QxlState_Drawable&& from) noexcept
    : QxlState_Drawable() {
    *this = ::std::move(from);
  }

  inline QxlState_Drawable& operator=(QxlState_Drawable&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const QxlState_Drawable& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const QxlState_Drawable* internal_default_instance() {
    return reinterpret_cast<const QxlState_Drawable*>(
               &_QxlState_Drawable_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(QxlState_Drawable* other);
  friend void swap(QxlState_Drawable& a, QxlState_Drawable& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline QxlState_Drawable* New() const PROTOBUF_FINAL { return New(NULL); }

  QxlState_Drawable* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const QxlState_Drawable& from);
  void MergeFrom(const QxlState_Drawable& from);
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
  void InternalSwap(QxlState_Drawable* other);
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

  // uint64 slot_address = 1;
  void clear_slot_address();
  static const int kSlotAddressFieldNumber = 1;
  ::google::protobuf::uint64 slot_address() const;
  void set_slot_address(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:QxlState.Drawable)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 slot_address_;
  mutable int _cached_size_;
  friend struct ::protobuf_qxl_2eproto::TableStruct;
  friend void ::protobuf_qxl_2eproto::InitDefaultsQxlState_DrawableImpl();
};
// -------------------------------------------------------------------

class QxlState : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:QxlState) */ {
 public:
  QxlState();
  virtual ~QxlState();

  QxlState(const QxlState& from);

  inline QxlState& operator=(const QxlState& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  QxlState(QxlState&& from) noexcept
    : QxlState() {
    *this = ::std::move(from);
  }

  inline QxlState& operator=(QxlState&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const QxlState& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const QxlState* internal_default_instance() {
    return reinterpret_cast<const QxlState*>(
               &_QxlState_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(QxlState* other);
  friend void swap(QxlState& a, QxlState& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline QxlState* New() const PROTOBUF_FINAL { return New(NULL); }

  QxlState* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const QxlState& from);
  void MergeFrom(const QxlState& from);
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
  void InternalSwap(QxlState* other);
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

  typedef QxlState_GuestSlot GuestSlot;
  typedef QxlState_GuestPrimary GuestPrimary;
  typedef QxlState_Surface Surface;
  typedef QxlState_Drawable Drawable;

  // accessors -------------------------------------------------------

  // repeated .QxlState.GuestSlot guest_slots = 2;
  int guest_slots_size() const;
  void clear_guest_slots();
  static const int kGuestSlotsFieldNumber = 2;
  const ::QxlState_GuestSlot& guest_slots(int index) const;
  ::QxlState_GuestSlot* mutable_guest_slots(int index);
  ::QxlState_GuestSlot* add_guest_slots();
  ::google::protobuf::RepeatedPtrField< ::QxlState_GuestSlot >*
      mutable_guest_slots();
  const ::google::protobuf::RepeatedPtrField< ::QxlState_GuestSlot >&
      guest_slots() const;

  // repeated uint64 free_resources = 5;
  int free_resources_size() const;
  void clear_free_resources();
  static const int kFreeResourcesFieldNumber = 5;
  ::google::protobuf::uint64 free_resources(int index) const;
  void set_free_resources(int index, ::google::protobuf::uint64 value);
  void add_free_resources(::google::protobuf::uint64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      free_resources() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_free_resources();

  // repeated .QxlState.Surface surfaces = 6;
  int surfaces_size() const;
  void clear_surfaces();
  static const int kSurfacesFieldNumber = 6;
  const ::QxlState_Surface& surfaces(int index) const;
  ::QxlState_Surface* mutable_surfaces(int index);
  ::QxlState_Surface* add_surfaces();
  ::google::protobuf::RepeatedPtrField< ::QxlState_Surface >*
      mutable_surfaces();
  const ::google::protobuf::RepeatedPtrField< ::QxlState_Surface >&
      surfaces() const;

  // repeated .QxlState.Drawable drawbles = 7;
  int drawbles_size() const;
  void clear_drawbles();
  static const int kDrawblesFieldNumber = 7;
  const ::QxlState_Drawable& drawbles(int index) const;
  ::QxlState_Drawable* mutable_drawbles(int index);
  ::QxlState_Drawable* add_drawbles();
  ::google::protobuf::RepeatedPtrField< ::QxlState_Drawable >*
      mutable_drawbles();
  const ::google::protobuf::RepeatedPtrField< ::QxlState_Drawable >&
      drawbles() const;

  // .QxlState.GuestPrimary guest_primary = 3;
  bool has_guest_primary() const;
  void clear_guest_primary();
  static const int kGuestPrimaryFieldNumber = 3;
  const ::QxlState_GuestPrimary& guest_primary() const;
  ::QxlState_GuestPrimary* release_guest_primary();
  ::QxlState_GuestPrimary* mutable_guest_primary();
  void set_allocated_guest_primary(::QxlState_GuestPrimary* guest_primary);

  // @@protoc_insertion_point(class_scope:QxlState)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::QxlState_GuestSlot > guest_slots_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > free_resources_;
  mutable int _free_resources_cached_byte_size_;
  ::google::protobuf::RepeatedPtrField< ::QxlState_Surface > surfaces_;
  ::google::protobuf::RepeatedPtrField< ::QxlState_Drawable > drawbles_;
  ::QxlState_GuestPrimary* guest_primary_;
  mutable int _cached_size_;
  friend struct ::protobuf_qxl_2eproto::TableStruct;
  friend void ::protobuf_qxl_2eproto::InitDefaultsQxlStateImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// QxlState_GuestSlot

// uint64 mem_start = 1;
inline void QxlState_GuestSlot::clear_mem_start() {
  mem_start_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 QxlState_GuestSlot::mem_start() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestSlot.mem_start)
  return mem_start_;
}
inline void QxlState_GuestSlot::set_mem_start(::google::protobuf::uint64 value) {
  
  mem_start_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestSlot.mem_start)
}

// uint64 mem_end = 2;
inline void QxlState_GuestSlot::clear_mem_end() {
  mem_end_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 QxlState_GuestSlot::mem_end() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestSlot.mem_end)
  return mem_end_;
}
inline void QxlState_GuestSlot::set_mem_end(::google::protobuf::uint64 value) {
  
  mem_end_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestSlot.mem_end)
}

// bool active = 3;
inline void QxlState_GuestSlot::clear_active() {
  active_ = false;
}
inline bool QxlState_GuestSlot::active() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestSlot.active)
  return active_;
}
inline void QxlState_GuestSlot::set_active(bool value) {
  
  active_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestSlot.active)
}

// -------------------------------------------------------------------

// QxlState_GuestPrimary

// uint32 width = 1;
inline void QxlState_GuestPrimary::clear_width() {
  width_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::width() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.width)
  return width_;
}
inline void QxlState_GuestPrimary::set_width(::google::protobuf::uint32 value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.width)
}

// uint32 height = 2;
inline void QxlState_GuestPrimary::clear_height() {
  height_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::height() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.height)
  return height_;
}
inline void QxlState_GuestPrimary::set_height(::google::protobuf::uint32 value) {
  
  height_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.height)
}

// int32 stride = 3;
inline void QxlState_GuestPrimary::clear_stride() {
  stride_ = 0;
}
inline ::google::protobuf::int32 QxlState_GuestPrimary::stride() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.stride)
  return stride_;
}
inline void QxlState_GuestPrimary::set_stride(::google::protobuf::int32 value) {
  
  stride_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.stride)
}

// uint32 format = 4;
inline void QxlState_GuestPrimary::clear_format() {
  format_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::format() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.format)
  return format_;
}
inline void QxlState_GuestPrimary::set_format(::google::protobuf::uint32 value) {
  
  format_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.format)
}

// uint32 position = 5;
inline void QxlState_GuestPrimary::clear_position() {
  position_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::position() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.position)
  return position_;
}
inline void QxlState_GuestPrimary::set_position(::google::protobuf::uint32 value) {
  
  position_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.position)
}

// uint32 mouse_mode = 6;
inline void QxlState_GuestPrimary::clear_mouse_mode() {
  mouse_mode_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::mouse_mode() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.mouse_mode)
  return mouse_mode_;
}
inline void QxlState_GuestPrimary::set_mouse_mode(::google::protobuf::uint32 value) {
  
  mouse_mode_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.mouse_mode)
}

// uint32 flags = 7;
inline void QxlState_GuestPrimary::clear_flags() {
  flags_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::flags() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.flags)
  return flags_;
}
inline void QxlState_GuestPrimary::set_flags(::google::protobuf::uint32 value) {
  
  flags_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.flags)
}

// uint32 type = 8;
inline void QxlState_GuestPrimary::clear_type() {
  type_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_GuestPrimary::type() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.type)
  return type_;
}
inline void QxlState_GuestPrimary::set_type(::google::protobuf::uint32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.type)
}

// uint64 mem_address = 9;
inline void QxlState_GuestPrimary::clear_mem_address() {
  mem_address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 QxlState_GuestPrimary::mem_address() const {
  // @@protoc_insertion_point(field_get:QxlState.GuestPrimary.mem_address)
  return mem_address_;
}
inline void QxlState_GuestPrimary::set_mem_address(::google::protobuf::uint64 value) {
  
  mem_address_ = value;
  // @@protoc_insertion_point(field_set:QxlState.GuestPrimary.mem_address)
}

// -------------------------------------------------------------------

// QxlState_Surface

// uint32 id = 1;
inline void QxlState_Surface::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 QxlState_Surface::id() const {
  // @@protoc_insertion_point(field_get:QxlState.Surface.id)
  return id_;
}
inline void QxlState_Surface::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:QxlState.Surface.id)
}

// uint64 slot_address = 2;
inline void QxlState_Surface::clear_slot_address() {
  slot_address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 QxlState_Surface::slot_address() const {
  // @@protoc_insertion_point(field_get:QxlState.Surface.slot_address)
  return slot_address_;
}
inline void QxlState_Surface::set_slot_address(::google::protobuf::uint64 value) {
  
  slot_address_ = value;
  // @@protoc_insertion_point(field_set:QxlState.Surface.slot_address)
}

// -------------------------------------------------------------------

// QxlState_Drawable

// uint64 slot_address = 1;
inline void QxlState_Drawable::clear_slot_address() {
  slot_address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 QxlState_Drawable::slot_address() const {
  // @@protoc_insertion_point(field_get:QxlState.Drawable.slot_address)
  return slot_address_;
}
inline void QxlState_Drawable::set_slot_address(::google::protobuf::uint64 value) {
  
  slot_address_ = value;
  // @@protoc_insertion_point(field_set:QxlState.Drawable.slot_address)
}

// -------------------------------------------------------------------

// QxlState

// repeated .QxlState.GuestSlot guest_slots = 2;
inline int QxlState::guest_slots_size() const {
  return guest_slots_.size();
}
inline void QxlState::clear_guest_slots() {
  guest_slots_.Clear();
}
inline const ::QxlState_GuestSlot& QxlState::guest_slots(int index) const {
  // @@protoc_insertion_point(field_get:QxlState.guest_slots)
  return guest_slots_.Get(index);
}
inline ::QxlState_GuestSlot* QxlState::mutable_guest_slots(int index) {
  // @@protoc_insertion_point(field_mutable:QxlState.guest_slots)
  return guest_slots_.Mutable(index);
}
inline ::QxlState_GuestSlot* QxlState::add_guest_slots() {
  // @@protoc_insertion_point(field_add:QxlState.guest_slots)
  return guest_slots_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::QxlState_GuestSlot >*
QxlState::mutable_guest_slots() {
  // @@protoc_insertion_point(field_mutable_list:QxlState.guest_slots)
  return &guest_slots_;
}
inline const ::google::protobuf::RepeatedPtrField< ::QxlState_GuestSlot >&
QxlState::guest_slots() const {
  // @@protoc_insertion_point(field_list:QxlState.guest_slots)
  return guest_slots_;
}

// .QxlState.GuestPrimary guest_primary = 3;
inline bool QxlState::has_guest_primary() const {
  return this != internal_default_instance() && guest_primary_ != NULL;
}
inline void QxlState::clear_guest_primary() {
  if (GetArenaNoVirtual() == NULL && guest_primary_ != NULL) {
    delete guest_primary_;
  }
  guest_primary_ = NULL;
}
inline const ::QxlState_GuestPrimary& QxlState::guest_primary() const {
  const ::QxlState_GuestPrimary* p = guest_primary_;
  // @@protoc_insertion_point(field_get:QxlState.guest_primary)
  return p != NULL ? *p : *reinterpret_cast<const ::QxlState_GuestPrimary*>(
      &::_QxlState_GuestPrimary_default_instance_);
}
inline ::QxlState_GuestPrimary* QxlState::release_guest_primary() {
  // @@protoc_insertion_point(field_release:QxlState.guest_primary)
  
  ::QxlState_GuestPrimary* temp = guest_primary_;
  guest_primary_ = NULL;
  return temp;
}
inline ::QxlState_GuestPrimary* QxlState::mutable_guest_primary() {
  
  if (guest_primary_ == NULL) {
    guest_primary_ = new ::QxlState_GuestPrimary;
  }
  // @@protoc_insertion_point(field_mutable:QxlState.guest_primary)
  return guest_primary_;
}
inline void QxlState::set_allocated_guest_primary(::QxlState_GuestPrimary* guest_primary) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete guest_primary_;
  }
  if (guest_primary) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      guest_primary = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, guest_primary, submessage_arena);
    }
    
  } else {
    
  }
  guest_primary_ = guest_primary;
  // @@protoc_insertion_point(field_set_allocated:QxlState.guest_primary)
}

// repeated uint64 free_resources = 5;
inline int QxlState::free_resources_size() const {
  return free_resources_.size();
}
inline void QxlState::clear_free_resources() {
  free_resources_.Clear();
}
inline ::google::protobuf::uint64 QxlState::free_resources(int index) const {
  // @@protoc_insertion_point(field_get:QxlState.free_resources)
  return free_resources_.Get(index);
}
inline void QxlState::set_free_resources(int index, ::google::protobuf::uint64 value) {
  free_resources_.Set(index, value);
  // @@protoc_insertion_point(field_set:QxlState.free_resources)
}
inline void QxlState::add_free_resources(::google::protobuf::uint64 value) {
  free_resources_.Add(value);
  // @@protoc_insertion_point(field_add:QxlState.free_resources)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
QxlState::free_resources() const {
  // @@protoc_insertion_point(field_list:QxlState.free_resources)
  return free_resources_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
QxlState::mutable_free_resources() {
  // @@protoc_insertion_point(field_mutable_list:QxlState.free_resources)
  return &free_resources_;
}

// repeated .QxlState.Surface surfaces = 6;
inline int QxlState::surfaces_size() const {
  return surfaces_.size();
}
inline void QxlState::clear_surfaces() {
  surfaces_.Clear();
}
inline const ::QxlState_Surface& QxlState::surfaces(int index) const {
  // @@protoc_insertion_point(field_get:QxlState.surfaces)
  return surfaces_.Get(index);
}
inline ::QxlState_Surface* QxlState::mutable_surfaces(int index) {
  // @@protoc_insertion_point(field_mutable:QxlState.surfaces)
  return surfaces_.Mutable(index);
}
inline ::QxlState_Surface* QxlState::add_surfaces() {
  // @@protoc_insertion_point(field_add:QxlState.surfaces)
  return surfaces_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::QxlState_Surface >*
QxlState::mutable_surfaces() {
  // @@protoc_insertion_point(field_mutable_list:QxlState.surfaces)
  return &surfaces_;
}
inline const ::google::protobuf::RepeatedPtrField< ::QxlState_Surface >&
QxlState::surfaces() const {
  // @@protoc_insertion_point(field_list:QxlState.surfaces)
  return surfaces_;
}

// repeated .QxlState.Drawable drawbles = 7;
inline int QxlState::drawbles_size() const {
  return drawbles_.size();
}
inline void QxlState::clear_drawbles() {
  drawbles_.Clear();
}
inline const ::QxlState_Drawable& QxlState::drawbles(int index) const {
  // @@protoc_insertion_point(field_get:QxlState.drawbles)
  return drawbles_.Get(index);
}
inline ::QxlState_Drawable* QxlState::mutable_drawbles(int index) {
  // @@protoc_insertion_point(field_mutable:QxlState.drawbles)
  return drawbles_.Mutable(index);
}
inline ::QxlState_Drawable* QxlState::add_drawbles() {
  // @@protoc_insertion_point(field_add:QxlState.drawbles)
  return drawbles_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::QxlState_Drawable >*
QxlState::mutable_drawbles() {
  // @@protoc_insertion_point(field_mutable_list:QxlState.drawbles)
  return &drawbles_;
}
inline const ::google::protobuf::RepeatedPtrField< ::QxlState_Drawable >&
QxlState::drawbles() const {
  // @@protoc_insertion_point(field_list:QxlState.drawbles)
  return drawbles_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_qxl_2eproto__INCLUDED
