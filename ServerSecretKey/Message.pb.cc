// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Message.proto

#include "Message.pb.h"

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

PROTOBUF_CONSTEXPR ResquestMsg::ResquestMsg(
    ::_pbi::ConstantInitialized)
  : clientid_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , serverid_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , sign_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , data_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , cmd_(0){}
struct ResquestMsgDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResquestMsgDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResquestMsgDefaultTypeInternal() {}
  union {
    ResquestMsg _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResquestMsgDefaultTypeInternal _ResquestMsg_default_instance_;
PROTOBUF_CONSTEXPR ResponseMsg::ResponseMsg(
    ::_pbi::ConstantInitialized)
  : clientid_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , serverid_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , data_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , status_(false)
  , seckeyid_(0){}
struct ResponseMsgDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResponseMsgDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResponseMsgDefaultTypeInternal() {}
  union {
    ResponseMsg _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResponseMsgDefaultTypeInternal _ResponseMsg_default_instance_;
static ::_pb::Metadata file_level_metadata_Message_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_Message_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Message_2eproto = nullptr;

const uint32_t TableStruct_Message_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ResquestMsg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ResquestMsg, cmd_),
  PROTOBUF_FIELD_OFFSET(::ResquestMsg, clientid_),
  PROTOBUF_FIELD_OFFSET(::ResquestMsg, serverid_),
  PROTOBUF_FIELD_OFFSET(::ResquestMsg, sign_),
  PROTOBUF_FIELD_OFFSET(::ResquestMsg, data_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ResponseMsg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ResponseMsg, status_),
  PROTOBUF_FIELD_OFFSET(::ResponseMsg, clientid_),
  PROTOBUF_FIELD_OFFSET(::ResponseMsg, serverid_),
  PROTOBUF_FIELD_OFFSET(::ResponseMsg, seckeyid_),
  PROTOBUF_FIELD_OFFSET(::ResponseMsg, data_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::ResquestMsg)},
  { 11, -1, -1, sizeof(::ResponseMsg)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_ResquestMsg_default_instance_._instance,
  &::_ResponseMsg_default_instance_._instance,
};

const char descriptor_table_protodef_Message_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rMessage.proto\"Z\n\013ResquestMsg\022\013\n\003cmd\030\001 "
  "\001(\005\022\020\n\010clientID\030\002 \001(\014\022\020\n\010serverID\030\003 \001(\014\022"
  "\014\n\004sign\030\004 \001(\014\022\014\n\004data\030\005 \001(\014\"a\n\013ResponseM"
  "sg\022\016\n\006status\030\001 \001(\010\022\020\n\010clientID\030\002 \001(\014\022\020\n\010"
  "serverID\030\003 \001(\014\022\020\n\010seckeyID\030\004 \001(\005\022\014\n\004data"
  "\030\005 \001(\014b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_Message_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Message_2eproto = {
    false, false, 214, descriptor_table_protodef_Message_2eproto,
    "Message.proto",
    &descriptor_table_Message_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_Message_2eproto::offsets,
    file_level_metadata_Message_2eproto, file_level_enum_descriptors_Message_2eproto,
    file_level_service_descriptors_Message_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Message_2eproto_getter() {
  return &descriptor_table_Message_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Message_2eproto(&descriptor_table_Message_2eproto);

// ===================================================================

class ResquestMsg::_Internal {
 public:
};

ResquestMsg::ResquestMsg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:ResquestMsg)
}
ResquestMsg::ResquestMsg(const ResquestMsg& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clientid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    clientid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_clientid().empty()) {
    clientid_.Set(from._internal_clientid(), 
      GetArenaForAllocation());
  }
  serverid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    serverid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_serverid().empty()) {
    serverid_.Set(from._internal_serverid(), 
      GetArenaForAllocation());
  }
  sign_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    sign_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_sign().empty()) {
    sign_.Set(from._internal_sign(), 
      GetArenaForAllocation());
  }
  data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    data_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_data().empty()) {
    data_.Set(from._internal_data(), 
      GetArenaForAllocation());
  }
  cmd_ = from.cmd_;
  // @@protoc_insertion_point(copy_constructor:ResquestMsg)
}

inline void ResquestMsg::SharedCtor() {
clientid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  clientid_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
serverid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  serverid_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
sign_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  sign_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
data_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  data_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
cmd_ = 0;
}

ResquestMsg::~ResquestMsg() {
  // @@protoc_insertion_point(destructor:ResquestMsg)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ResquestMsg::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  clientid_.Destroy();
  serverid_.Destroy();
  sign_.Destroy();
  data_.Destroy();
}

void ResquestMsg::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ResquestMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:ResquestMsg)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clientid_.ClearToEmpty();
  serverid_.ClearToEmpty();
  sign_.ClearToEmpty();
  data_.ClearToEmpty();
  cmd_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ResquestMsg::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 cmd = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          cmd_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes clientID = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_clientid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes serverID = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_serverid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes sign = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_sign();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes data = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_data();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
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
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ResquestMsg::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ResquestMsg)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 cmd = 1;
  if (this->_internal_cmd() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_cmd(), target);
  }

  // bytes clientID = 2;
  if (!this->_internal_clientid().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_clientid(), target);
  }

  // bytes serverID = 3;
  if (!this->_internal_serverid().empty()) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_serverid(), target);
  }

  // bytes sign = 4;
  if (!this->_internal_sign().empty()) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_sign(), target);
  }

  // bytes data = 5;
  if (!this->_internal_data().empty()) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ResquestMsg)
  return target;
}

size_t ResquestMsg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ResquestMsg)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes clientID = 2;
  if (!this->_internal_clientid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_clientid());
  }

  // bytes serverID = 3;
  if (!this->_internal_serverid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_serverid());
  }

  // bytes sign = 4;
  if (!this->_internal_sign().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_sign());
  }

  // bytes data = 5;
  if (!this->_internal_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_data());
  }

  // int32 cmd = 1;
  if (this->_internal_cmd() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_cmd());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ResquestMsg::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ResquestMsg::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ResquestMsg::GetClassData() const { return &_class_data_; }

void ResquestMsg::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ResquestMsg *>(to)->MergeFrom(
      static_cast<const ResquestMsg &>(from));
}


void ResquestMsg::MergeFrom(const ResquestMsg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ResquestMsg)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_clientid().empty()) {
    _internal_set_clientid(from._internal_clientid());
  }
  if (!from._internal_serverid().empty()) {
    _internal_set_serverid(from._internal_serverid());
  }
  if (!from._internal_sign().empty()) {
    _internal_set_sign(from._internal_sign());
  }
  if (!from._internal_data().empty()) {
    _internal_set_data(from._internal_data());
  }
  if (from._internal_cmd() != 0) {
    _internal_set_cmd(from._internal_cmd());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ResquestMsg::CopyFrom(const ResquestMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ResquestMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResquestMsg::IsInitialized() const {
  return true;
}

void ResquestMsg::InternalSwap(ResquestMsg* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &clientid_, lhs_arena,
      &other->clientid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &serverid_, lhs_arena,
      &other->serverid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &sign_, lhs_arena,
      &other->sign_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &data_, lhs_arena,
      &other->data_, rhs_arena
  );
  swap(cmd_, other->cmd_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ResquestMsg::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Message_2eproto_getter, &descriptor_table_Message_2eproto_once,
      file_level_metadata_Message_2eproto[0]);
}

// ===================================================================

class ResponseMsg::_Internal {
 public:
};

ResponseMsg::ResponseMsg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:ResponseMsg)
}
ResponseMsg::ResponseMsg(const ResponseMsg& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clientid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    clientid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_clientid().empty()) {
    clientid_.Set(from._internal_clientid(), 
      GetArenaForAllocation());
  }
  serverid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    serverid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_serverid().empty()) {
    serverid_.Set(from._internal_serverid(), 
      GetArenaForAllocation());
  }
  data_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    data_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_data().empty()) {
    data_.Set(from._internal_data(), 
      GetArenaForAllocation());
  }
  ::memcpy(&status_, &from.status_,
    static_cast<size_t>(reinterpret_cast<char*>(&seckeyid_) -
    reinterpret_cast<char*>(&status_)) + sizeof(seckeyid_));
  // @@protoc_insertion_point(copy_constructor:ResponseMsg)
}

inline void ResponseMsg::SharedCtor() {
clientid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  clientid_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
serverid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  serverid_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
data_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  data_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&status_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&seckeyid_) -
    reinterpret_cast<char*>(&status_)) + sizeof(seckeyid_));
}

ResponseMsg::~ResponseMsg() {
  // @@protoc_insertion_point(destructor:ResponseMsg)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ResponseMsg::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  clientid_.Destroy();
  serverid_.Destroy();
  data_.Destroy();
}

void ResponseMsg::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ResponseMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:ResponseMsg)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clientid_.ClearToEmpty();
  serverid_.ClearToEmpty();
  data_.ClearToEmpty();
  ::memset(&status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&seckeyid_) -
      reinterpret_cast<char*>(&status_)) + sizeof(seckeyid_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ResponseMsg::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          status_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes clientID = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_clientid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes serverID = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_serverid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 seckeyID = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          seckeyid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes data = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_data();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
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
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ResponseMsg::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ResponseMsg)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool status = 1;
  if (this->_internal_status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(1, this->_internal_status(), target);
  }

  // bytes clientID = 2;
  if (!this->_internal_clientid().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_clientid(), target);
  }

  // bytes serverID = 3;
  if (!this->_internal_serverid().empty()) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_serverid(), target);
  }

  // int32 seckeyID = 4;
  if (this->_internal_seckeyid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(4, this->_internal_seckeyid(), target);
  }

  // bytes data = 5;
  if (!this->_internal_data().empty()) {
    target = stream->WriteBytesMaybeAliased(
        5, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ResponseMsg)
  return target;
}

size_t ResponseMsg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ResponseMsg)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes clientID = 2;
  if (!this->_internal_clientid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_clientid());
  }

  // bytes serverID = 3;
  if (!this->_internal_serverid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_serverid());
  }

  // bytes data = 5;
  if (!this->_internal_data().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_data());
  }

  // bool status = 1;
  if (this->_internal_status() != 0) {
    total_size += 1 + 1;
  }

  // int32 seckeyID = 4;
  if (this->_internal_seckeyid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_seckeyid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ResponseMsg::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ResponseMsg::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ResponseMsg::GetClassData() const { return &_class_data_; }

void ResponseMsg::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ResponseMsg *>(to)->MergeFrom(
      static_cast<const ResponseMsg &>(from));
}


void ResponseMsg::MergeFrom(const ResponseMsg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ResponseMsg)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_clientid().empty()) {
    _internal_set_clientid(from._internal_clientid());
  }
  if (!from._internal_serverid().empty()) {
    _internal_set_serverid(from._internal_serverid());
  }
  if (!from._internal_data().empty()) {
    _internal_set_data(from._internal_data());
  }
  if (from._internal_status() != 0) {
    _internal_set_status(from._internal_status());
  }
  if (from._internal_seckeyid() != 0) {
    _internal_set_seckeyid(from._internal_seckeyid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ResponseMsg::CopyFrom(const ResponseMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ResponseMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResponseMsg::IsInitialized() const {
  return true;
}

void ResponseMsg::InternalSwap(ResponseMsg* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &clientid_, lhs_arena,
      &other->clientid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &serverid_, lhs_arena,
      &other->serverid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &data_, lhs_arena,
      &other->data_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ResponseMsg, seckeyid_)
      + sizeof(ResponseMsg::seckeyid_)
      - PROTOBUF_FIELD_OFFSET(ResponseMsg, status_)>(
          reinterpret_cast<char*>(&status_),
          reinterpret_cast<char*>(&other->status_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ResponseMsg::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Message_2eproto_getter, &descriptor_table_Message_2eproto_once,
      file_level_metadata_Message_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ResquestMsg*
Arena::CreateMaybeMessage< ::ResquestMsg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ResquestMsg >(arena);
}
template<> PROTOBUF_NOINLINE ::ResponseMsg*
Arena::CreateMaybeMessage< ::ResponseMsg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ResponseMsg >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
