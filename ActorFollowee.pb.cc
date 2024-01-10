// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ActorFollowee.proto

#include "ActorFollowee.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace mq {
namespace proto {
namespace actorfollowee {
PROTOBUF_CONSTEXPR Position::Position(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.spawnid_)*/0u
  , /*decltype(_impl_.zoneid_)*/0u
  , /*decltype(_impl_.x_)*/0
  , /*decltype(_impl_.y_)*/0
  , /*decltype(_impl_.z_)*/0
  , /*decltype(_impl_.heading_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PositionDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PositionDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PositionDefaultTypeInternal() {}
  union {
    Position _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PositionDefaultTypeInternal _Position_default_instance_;
PROTOBUF_CONSTEXPR Message::Message(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.position_)*/nullptr
  , /*decltype(_impl_.id_)*/0} {}
struct MessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MessageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MessageDefaultTypeInternal() {}
  union {
    Message _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MessageDefaultTypeInternal _Message_default_instance_;
}  // namespace actorfollowee
}  // namespace proto
}  // namespace mq
static ::_pb::Metadata file_level_metadata_ActorFollowee_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_ActorFollowee_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ActorFollowee_2eproto = nullptr;

const uint32_t TableStruct_ActorFollowee_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.spawnid_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.zoneid_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.x_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.y_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.z_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Position, _impl_.heading_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Message, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Message, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Message, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::mq::proto::actorfollowee::Message, _impl_.position_),
  ~0u,
  0,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::mq::proto::actorfollowee::Position)},
  { 13, 21, -1, sizeof(::mq::proto::actorfollowee::Message)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::mq::proto::actorfollowee::_Position_default_instance_._instance,
  &::mq::proto::actorfollowee::_Message_default_instance_._instance,
};

const char descriptor_table_protodef_ActorFollowee_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023ActorFollowee.proto\022\026mq.proto.actorfol"
  "lowee\"k\n\010Position\022\017\n\007spawnid\030\001 \001(\r\022\014\n\004na"
  "me\030\002 \001(\t\022\016\n\006zoneid\030\003 \001(\r\022\t\n\001x\030\004 \001(\002\022\t\n\001y"
  "\030\005 \001(\002\022\t\n\001z\030\006 \001(\002\022\017\n\007heading\030\007 \001(\002\"~\n\007Me"
  "ssage\022-\n\002id\030\001 \001(\0162!.mq.proto.actorfollow"
  "ee.MessageId\0227\n\010position\030\002 \001(\0132 .mq.prot"
  "o.actorfollowee.PositionH\000\210\001\001B\013\n\t_positi"
  "on*I\n\tMessageId\022\010\n\004NoOp\020\000\022\r\n\tSubscribe\020\001"
  "\022\017\n\013UnSubscribe\020\002\022\022\n\016PositionUpdate\020\003b\006p"
  "roto3"
  ;
static ::_pbi::once_flag descriptor_table_ActorFollowee_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ActorFollowee_2eproto = {
    false, false, 365, descriptor_table_protodef_ActorFollowee_2eproto,
    "ActorFollowee.proto",
    &descriptor_table_ActorFollowee_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_ActorFollowee_2eproto::offsets,
    file_level_metadata_ActorFollowee_2eproto, file_level_enum_descriptors_ActorFollowee_2eproto,
    file_level_service_descriptors_ActorFollowee_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ActorFollowee_2eproto_getter() {
  return &descriptor_table_ActorFollowee_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ActorFollowee_2eproto(&descriptor_table_ActorFollowee_2eproto);
namespace mq {
namespace proto {
namespace actorfollowee {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_ActorFollowee_2eproto);
  return file_level_enum_descriptors_ActorFollowee_2eproto[0];
}
bool MessageId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class Position::_Internal {
 public:
};

Position::Position(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:mq.proto.actorfollowee.Position)
}
Position::Position(const Position& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Position* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.spawnid_){}
    , decltype(_impl_.zoneid_){}
    , decltype(_impl_.x_){}
    , decltype(_impl_.y_){}
    , decltype(_impl_.z_){}
    , decltype(_impl_.heading_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.spawnid_, &from._impl_.spawnid_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.heading_) -
    reinterpret_cast<char*>(&_impl_.spawnid_)) + sizeof(_impl_.heading_));
  // @@protoc_insertion_point(copy_constructor:mq.proto.actorfollowee.Position)
}

inline void Position::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.spawnid_){0u}
    , decltype(_impl_.zoneid_){0u}
    , decltype(_impl_.x_){0}
    , decltype(_impl_.y_){0}
    , decltype(_impl_.z_){0}
    , decltype(_impl_.heading_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Position::~Position() {
  // @@protoc_insertion_point(destructor:mq.proto.actorfollowee.Position)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Position::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
}

void Position::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Position::Clear() {
// @@protoc_insertion_point(message_clear_start:mq.proto.actorfollowee.Position)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  ::memset(&_impl_.spawnid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.heading_) -
      reinterpret_cast<char*>(&_impl_.spawnid_)) + sizeof(_impl_.heading_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Position::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 spawnid = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.spawnid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "mq.proto.actorfollowee.Position.name"));
        } else
          goto handle_unusual;
        continue;
      // uint32 zoneid = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.zoneid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // float x = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 37)) {
          _impl_.x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float y = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 45)) {
          _impl_.y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float z = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 53)) {
          _impl_.z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float heading = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 61)) {
          _impl_.heading_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Position::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mq.proto.actorfollowee.Position)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 spawnid = 1;
  if (this->_internal_spawnid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_spawnid(), target);
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "mq.proto.actorfollowee.Position.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // uint32 zoneid = 3;
  if (this->_internal_zoneid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_zoneid(), target);
  }

  // float x = 4;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_x = this->_internal_x();
  uint32_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(4, this->_internal_x(), target);
  }

  // float y = 5;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_y = this->_internal_y();
  uint32_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(5, this->_internal_y(), target);
  }

  // float z = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_z = this->_internal_z();
  uint32_t raw_z;
  memcpy(&raw_z, &tmp_z, sizeof(tmp_z));
  if (raw_z != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(6, this->_internal_z(), target);
  }

  // float heading = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_heading = this->_internal_heading();
  uint32_t raw_heading;
  memcpy(&raw_heading, &tmp_heading, sizeof(tmp_heading));
  if (raw_heading != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(7, this->_internal_heading(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mq.proto.actorfollowee.Position)
  return target;
}

size_t Position::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mq.proto.actorfollowee.Position)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // uint32 spawnid = 1;
  if (this->_internal_spawnid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_spawnid());
  }

  // uint32 zoneid = 3;
  if (this->_internal_zoneid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_zoneid());
  }

  // float x = 4;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_x = this->_internal_x();
  uint32_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    total_size += 1 + 4;
  }

  // float y = 5;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_y = this->_internal_y();
  uint32_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    total_size += 1 + 4;
  }

  // float z = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_z = this->_internal_z();
  uint32_t raw_z;
  memcpy(&raw_z, &tmp_z, sizeof(tmp_z));
  if (raw_z != 0) {
    total_size += 1 + 4;
  }

  // float heading = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_heading = this->_internal_heading();
  uint32_t raw_heading;
  memcpy(&raw_heading, &tmp_heading, sizeof(tmp_heading));
  if (raw_heading != 0) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Position::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Position::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Position::GetClassData() const { return &_class_data_; }


void Position::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Position*>(&to_msg);
  auto& from = static_cast<const Position&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:mq.proto.actorfollowee.Position)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (from._internal_spawnid() != 0) {
    _this->_internal_set_spawnid(from._internal_spawnid());
  }
  if (from._internal_zoneid() != 0) {
    _this->_internal_set_zoneid(from._internal_zoneid());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_x = from._internal_x();
  uint32_t raw_x;
  memcpy(&raw_x, &tmp_x, sizeof(tmp_x));
  if (raw_x != 0) {
    _this->_internal_set_x(from._internal_x());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_y = from._internal_y();
  uint32_t raw_y;
  memcpy(&raw_y, &tmp_y, sizeof(tmp_y));
  if (raw_y != 0) {
    _this->_internal_set_y(from._internal_y());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_z = from._internal_z();
  uint32_t raw_z;
  memcpy(&raw_z, &tmp_z, sizeof(tmp_z));
  if (raw_z != 0) {
    _this->_internal_set_z(from._internal_z());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_heading = from._internal_heading();
  uint32_t raw_heading;
  memcpy(&raw_heading, &tmp_heading, sizeof(tmp_heading));
  if (raw_heading != 0) {
    _this->_internal_set_heading(from._internal_heading());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Position::CopyFrom(const Position& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mq.proto.actorfollowee.Position)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Position::IsInitialized() const {
  return true;
}

void Position::InternalSwap(Position* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Position, _impl_.heading_)
      + sizeof(Position::_impl_.heading_)
      - PROTOBUF_FIELD_OFFSET(Position, _impl_.spawnid_)>(
          reinterpret_cast<char*>(&_impl_.spawnid_),
          reinterpret_cast<char*>(&other->_impl_.spawnid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Position::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ActorFollowee_2eproto_getter, &descriptor_table_ActorFollowee_2eproto_once,
      file_level_metadata_ActorFollowee_2eproto[0]);
}

// ===================================================================

class Message::_Internal {
 public:
  using HasBits = decltype(std::declval<Message>()._impl_._has_bits_);
  static const ::mq::proto::actorfollowee::Position& position(const Message* msg);
  static void set_has_position(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::mq::proto::actorfollowee::Position&
Message::_Internal::position(const Message* msg) {
  return *msg->_impl_.position_;
}
Message::Message(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:mq.proto.actorfollowee.Message)
}
Message::Message(const Message& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Message* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.position_){nullptr}
    , decltype(_impl_.id_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_position()) {
    _this->_impl_.position_ = new ::mq::proto::actorfollowee::Position(*from._impl_.position_);
  }
  _this->_impl_.id_ = from._impl_.id_;
  // @@protoc_insertion_point(copy_constructor:mq.proto.actorfollowee.Message)
}

inline void Message::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.position_){nullptr}
    , decltype(_impl_.id_){0}
  };
}

Message::~Message() {
  // @@protoc_insertion_point(destructor:mq.proto.actorfollowee.Message)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Message::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.position_;
}

void Message::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Message::Clear() {
// @@protoc_insertion_point(message_clear_start:mq.proto.actorfollowee.Message)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(_impl_.position_ != nullptr);
    _impl_.position_->Clear();
  }
  _impl_.id_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Message::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .mq.proto.actorfollowee.MessageId id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_id(static_cast<::mq::proto::actorfollowee::MessageId>(val));
        } else
          goto handle_unusual;
        continue;
      // optional .mq.proto.actorfollowee.Position position = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_position(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Message::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mq.proto.actorfollowee.Message)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .mq.proto.actorfollowee.MessageId id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_id(), target);
  }

  // optional .mq.proto.actorfollowee.Position position = 2;
  if (_internal_has_position()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::position(this),
        _Internal::position(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mq.proto.actorfollowee.Message)
  return target;
}

size_t Message::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mq.proto.actorfollowee.Message)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional .mq.proto.actorfollowee.Position position = 2;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.position_);
  }

  // .mq.proto.actorfollowee.MessageId id = 1;
  if (this->_internal_id() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Message::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Message::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Message::GetClassData() const { return &_class_data_; }


void Message::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Message*>(&to_msg);
  auto& from = static_cast<const Message&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:mq.proto.actorfollowee.Message)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_position()) {
    _this->_internal_mutable_position()->::mq::proto::actorfollowee::Position::MergeFrom(
        from._internal_position());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Message::CopyFrom(const Message& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mq.proto.actorfollowee.Message)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Message::IsInitialized() const {
  return true;
}

void Message::InternalSwap(Message* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Message, _impl_.id_)
      + sizeof(Message::_impl_.id_)
      - PROTOBUF_FIELD_OFFSET(Message, _impl_.position_)>(
          reinterpret_cast<char*>(&_impl_.position_),
          reinterpret_cast<char*>(&other->_impl_.position_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Message::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ActorFollowee_2eproto_getter, &descriptor_table_ActorFollowee_2eproto_once,
      file_level_metadata_ActorFollowee_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace actorfollowee
}  // namespace proto
}  // namespace mq
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mq::proto::actorfollowee::Position*
Arena::CreateMaybeMessage< ::mq::proto::actorfollowee::Position >(Arena* arena) {
  return Arena::CreateMessageInternal< ::mq::proto::actorfollowee::Position >(arena);
}
template<> PROTOBUF_NOINLINE ::mq::proto::actorfollowee::Message*
Arena::CreateMaybeMessage< ::mq::proto::actorfollowee::Message >(Arena* arena) {
  return Arena::CreateMessageInternal< ::mq::proto::actorfollowee::Message >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
