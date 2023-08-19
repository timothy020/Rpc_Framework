// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friendlist.proto

#include "friendlist.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_friendlist_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_friendlist_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_ResultCode;
}  // namespace protobuf_friendlist_2eproto
namespace fixbug {
class ResultCodeDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ResultCode>
      _instance;
} _ResultCode_default_instance_;
class GetFriendListRequestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<GetFriendListRequest>
      _instance;
} _GetFriendListRequest_default_instance_;
class GetFriendListResponseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<GetFriendListResponse>
      _instance;
} _GetFriendListResponse_default_instance_;
}  // namespace fixbug
namespace protobuf_friendlist_2eproto {
static void InitDefaultsResultCode() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::fixbug::_ResultCode_default_instance_;
    new (ptr) ::fixbug::ResultCode();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::fixbug::ResultCode::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ResultCode =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsResultCode}, {}};

static void InitDefaultsGetFriendListRequest() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::fixbug::_GetFriendListRequest_default_instance_;
    new (ptr) ::fixbug::GetFriendListRequest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::fixbug::GetFriendListRequest::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_GetFriendListRequest =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsGetFriendListRequest}, {}};

static void InitDefaultsGetFriendListResponse() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::fixbug::_GetFriendListResponse_default_instance_;
    new (ptr) ::fixbug::GetFriendListResponse();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::fixbug::GetFriendListResponse::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_GetFriendListResponse =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsGetFriendListResponse}, {
      &protobuf_friendlist_2eproto::scc_info_ResultCode.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_ResultCode.base);
  ::google::protobuf::internal::InitSCC(&scc_info_GetFriendListRequest.base);
  ::google::protobuf::internal::InitSCC(&scc_info_GetFriendListResponse.base);
}

::google::protobuf::Metadata file_level_metadata[3];
const ::google::protobuf::ServiceDescriptor* file_level_service_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::ResultCode, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::ResultCode, errnum_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::ResultCode, errmsg_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::GetFriendListRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::GetFriendListRequest, id_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::GetFriendListResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::GetFriendListResponse, rcode_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::fixbug::GetFriendListResponse, names_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::fixbug::ResultCode)},
  { 7, -1, sizeof(::fixbug::GetFriendListRequest)},
  { 13, -1, sizeof(::fixbug::GetFriendListResponse)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::fixbug::_ResultCode_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::fixbug::_GetFriendListRequest_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::fixbug::_GetFriendListResponse_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "friendlist.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, file_level_service_descriptors);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 3);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\020friendlist.proto\022\006fixbug\",\n\nResultCode"
      "\022\016\n\006errnum\030\001 \001(\005\022\016\n\006errmsg\030\002 \001(\014\"\"\n\024GetF"
      "riendListRequest\022\n\n\002id\030\001 \001(\r\"I\n\025GetFrien"
      "dListResponse\022!\n\005rcode\030\001 \001(\0132\022.fixbug.Re"
      "sultCode\022\r\n\005names\030\002 \003(\0142d\n\024GetFriendList"
      "Service\022L\n\rGetFriendList\022\034.fixbug.GetFri"
      "endListRequest\032\035.fixbug.GetFriendListRes"
      "ponseB\003\200\001\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 298);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "friendlist.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_friendlist_2eproto
namespace fixbug {

// ===================================================================

void ResultCode::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ResultCode::kErrnumFieldNumber;
const int ResultCode::kErrmsgFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ResultCode::ResultCode()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_friendlist_2eproto::scc_info_ResultCode.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:fixbug.ResultCode)
}
ResultCode::ResultCode(const ResultCode& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  errmsg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.errmsg().size() > 0) {
    errmsg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.errmsg_);
  }
  errnum_ = from.errnum_;
  // @@protoc_insertion_point(copy_constructor:fixbug.ResultCode)
}

void ResultCode::SharedCtor() {
  errmsg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  errnum_ = 0;
}

ResultCode::~ResultCode() {
  // @@protoc_insertion_point(destructor:fixbug.ResultCode)
  SharedDtor();
}

void ResultCode::SharedDtor() {
  errmsg_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ResultCode::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ResultCode::descriptor() {
  ::protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_friendlist_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ResultCode& ResultCode::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_friendlist_2eproto::scc_info_ResultCode.base);
  return *internal_default_instance();
}


void ResultCode::Clear() {
// @@protoc_insertion_point(message_clear_start:fixbug.ResultCode)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  errmsg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  errnum_ = 0;
  _internal_metadata_.Clear();
}

bool ResultCode::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:fixbug.ResultCode)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int32 errnum = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &errnum_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes errmsg = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_errmsg()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:fixbug.ResultCode)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:fixbug.ResultCode)
  return false;
#undef DO_
}

void ResultCode::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:fixbug.ResultCode)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 errnum = 1;
  if (this->errnum() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->errnum(), output);
  }

  // bytes errmsg = 2;
  if (this->errmsg().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->errmsg(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:fixbug.ResultCode)
}

::google::protobuf::uint8* ResultCode::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:fixbug.ResultCode)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 errnum = 1;
  if (this->errnum() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->errnum(), target);
  }

  // bytes errmsg = 2;
  if (this->errmsg().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->errmsg(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fixbug.ResultCode)
  return target;
}

size_t ResultCode::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fixbug.ResultCode)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // bytes errmsg = 2;
  if (this->errmsg().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->errmsg());
  }

  // int32 errnum = 1;
  if (this->errnum() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->errnum());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ResultCode::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:fixbug.ResultCode)
  GOOGLE_DCHECK_NE(&from, this);
  const ResultCode* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ResultCode>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:fixbug.ResultCode)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:fixbug.ResultCode)
    MergeFrom(*source);
  }
}

void ResultCode::MergeFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fixbug.ResultCode)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.errmsg().size() > 0) {

    errmsg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.errmsg_);
  }
  if (from.errnum() != 0) {
    set_errnum(from.errnum());
  }
}

void ResultCode::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:fixbug.ResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ResultCode::CopyFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fixbug.ResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResultCode::IsInitialized() const {
  return true;
}

void ResultCode::Swap(ResultCode* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ResultCode::InternalSwap(ResultCode* other) {
  using std::swap;
  errmsg_.Swap(&other->errmsg_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(errnum_, other->errnum_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ResultCode::GetMetadata() const {
  protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_friendlist_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void GetFriendListRequest::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GetFriendListRequest::kIdFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GetFriendListRequest::GetFriendListRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_friendlist_2eproto::scc_info_GetFriendListRequest.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:fixbug.GetFriendListRequest)
}
GetFriendListRequest::GetFriendListRequest(const GetFriendListRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:fixbug.GetFriendListRequest)
}

void GetFriendListRequest::SharedCtor() {
  id_ = 0u;
}

GetFriendListRequest::~GetFriendListRequest() {
  // @@protoc_insertion_point(destructor:fixbug.GetFriendListRequest)
  SharedDtor();
}

void GetFriendListRequest::SharedDtor() {
}

void GetFriendListRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* GetFriendListRequest::descriptor() {
  ::protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_friendlist_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GetFriendListRequest& GetFriendListRequest::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_friendlist_2eproto::scc_info_GetFriendListRequest.base);
  return *internal_default_instance();
}


void GetFriendListRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:fixbug.GetFriendListRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_ = 0u;
  _internal_metadata_.Clear();
}

bool GetFriendListRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:fixbug.GetFriendListRequest)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:fixbug.GetFriendListRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:fixbug.GetFriendListRequest)
  return false;
#undef DO_
}

void GetFriendListRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:fixbug.GetFriendListRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:fixbug.GetFriendListRequest)
}

::google::protobuf::uint8* GetFriendListRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:fixbug.GetFriendListRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fixbug.GetFriendListRequest)
  return target;
}

size_t GetFriendListRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fixbug.GetFriendListRequest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // uint32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->id());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GetFriendListRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:fixbug.GetFriendListRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const GetFriendListRequest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GetFriendListRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:fixbug.GetFriendListRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:fixbug.GetFriendListRequest)
    MergeFrom(*source);
  }
}

void GetFriendListRequest::MergeFrom(const GetFriendListRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fixbug.GetFriendListRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id() != 0) {
    set_id(from.id());
  }
}

void GetFriendListRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:fixbug.GetFriendListRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetFriendListRequest::CopyFrom(const GetFriendListRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fixbug.GetFriendListRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetFriendListRequest::IsInitialized() const {
  return true;
}

void GetFriendListRequest::Swap(GetFriendListRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GetFriendListRequest::InternalSwap(GetFriendListRequest* other) {
  using std::swap;
  swap(id_, other->id_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata GetFriendListRequest::GetMetadata() const {
  protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_friendlist_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void GetFriendListResponse::InitAsDefaultInstance() {
  ::fixbug::_GetFriendListResponse_default_instance_._instance.get_mutable()->rcode_ = const_cast< ::fixbug::ResultCode*>(
      ::fixbug::ResultCode::internal_default_instance());
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int GetFriendListResponse::kRcodeFieldNumber;
const int GetFriendListResponse::kNamesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

GetFriendListResponse::GetFriendListResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_friendlist_2eproto::scc_info_GetFriendListResponse.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:fixbug.GetFriendListResponse)
}
GetFriendListResponse::GetFriendListResponse(const GetFriendListResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      names_(from.names_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_rcode()) {
    rcode_ = new ::fixbug::ResultCode(*from.rcode_);
  } else {
    rcode_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:fixbug.GetFriendListResponse)
}

void GetFriendListResponse::SharedCtor() {
  rcode_ = NULL;
}

GetFriendListResponse::~GetFriendListResponse() {
  // @@protoc_insertion_point(destructor:fixbug.GetFriendListResponse)
  SharedDtor();
}

void GetFriendListResponse::SharedDtor() {
  if (this != internal_default_instance()) delete rcode_;
}

void GetFriendListResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* GetFriendListResponse::descriptor() {
  ::protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_friendlist_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const GetFriendListResponse& GetFriendListResponse::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_friendlist_2eproto::scc_info_GetFriendListResponse.base);
  return *internal_default_instance();
}


void GetFriendListResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:fixbug.GetFriendListResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  names_.Clear();
  if (GetArenaNoVirtual() == NULL && rcode_ != NULL) {
    delete rcode_;
  }
  rcode_ = NULL;
  _internal_metadata_.Clear();
}

bool GetFriendListResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:fixbug.GetFriendListResponse)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .fixbug.ResultCode rcode = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_rcode()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated bytes names = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_names()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:fixbug.GetFriendListResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:fixbug.GetFriendListResponse)
  return false;
#undef DO_
}

void GetFriendListResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:fixbug.GetFriendListResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .fixbug.ResultCode rcode = 1;
  if (this->has_rcode()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->_internal_rcode(), output);
  }

  // repeated bytes names = 2;
  for (int i = 0, n = this->names_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->names(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:fixbug.GetFriendListResponse)
}

::google::protobuf::uint8* GetFriendListResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:fixbug.GetFriendListResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .fixbug.ResultCode rcode = 1;
  if (this->has_rcode()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->_internal_rcode(), deterministic, target);
  }

  // repeated bytes names = 2;
  for (int i = 0, n = this->names_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBytesToArray(2, this->names(i), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fixbug.GetFriendListResponse)
  return target;
}

size_t GetFriendListResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fixbug.GetFriendListResponse)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated bytes names = 2;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->names_size());
  for (int i = 0, n = this->names_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->names(i));
  }

  // .fixbug.ResultCode rcode = 1;
  if (this->has_rcode()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *rcode_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GetFriendListResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:fixbug.GetFriendListResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const GetFriendListResponse* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const GetFriendListResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:fixbug.GetFriendListResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:fixbug.GetFriendListResponse)
    MergeFrom(*source);
  }
}

void GetFriendListResponse::MergeFrom(const GetFriendListResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fixbug.GetFriendListResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  names_.MergeFrom(from.names_);
  if (from.has_rcode()) {
    mutable_rcode()->::fixbug::ResultCode::MergeFrom(from.rcode());
  }
}

void GetFriendListResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:fixbug.GetFriendListResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetFriendListResponse::CopyFrom(const GetFriendListResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fixbug.GetFriendListResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetFriendListResponse::IsInitialized() const {
  return true;
}

void GetFriendListResponse::Swap(GetFriendListResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GetFriendListResponse::InternalSwap(GetFriendListResponse* other) {
  using std::swap;
  names_.InternalSwap(CastToBase(&other->names_));
  swap(rcode_, other->rcode_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata GetFriendListResponse::GetMetadata() const {
  protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_friendlist_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

GetFriendListService::~GetFriendListService() {}

const ::google::protobuf::ServiceDescriptor* GetFriendListService::descriptor() {
  protobuf_friendlist_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_friendlist_2eproto::file_level_service_descriptors[0];
}

const ::google::protobuf::ServiceDescriptor* GetFriendListService::GetDescriptor() {
  return descriptor();
}

void GetFriendListService::GetFriendList(::google::protobuf::RpcController* controller,
                         const ::fixbug::GetFriendListRequest*,
                         ::fixbug::GetFriendListResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetFriendList() not implemented.");
  done->Run();
}

void GetFriendListService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), protobuf_friendlist_2eproto::file_level_service_descriptors[0]);
  switch(method->index()) {
    case 0:
      GetFriendList(controller,
             ::google::protobuf::down_cast<const ::fixbug::GetFriendListRequest*>(request),
             ::google::protobuf::down_cast< ::fixbug::GetFriendListResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& GetFriendListService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::fixbug::GetFriendListRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::google::protobuf::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::google::protobuf::Message& GetFriendListService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::fixbug::GetFriendListResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::google::protobuf::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

GetFriendListService_Stub::GetFriendListService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
GetFriendListService_Stub::GetFriendListService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
GetFriendListService_Stub::~GetFriendListService_Stub() {
  if (owns_channel_) delete channel_;
}

void GetFriendListService_Stub::GetFriendList(::google::protobuf::RpcController* controller,
                              const ::fixbug::GetFriendListRequest* request,
                              ::fixbug::GetFriendListResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace fixbug
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::fixbug::ResultCode* Arena::CreateMaybeMessage< ::fixbug::ResultCode >(Arena* arena) {
  return Arena::CreateInternal< ::fixbug::ResultCode >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::fixbug::GetFriendListRequest* Arena::CreateMaybeMessage< ::fixbug::GetFriendListRequest >(Arena* arena) {
  return Arena::CreateInternal< ::fixbug::GetFriendListRequest >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::fixbug::GetFriendListResponse* Arena::CreateMaybeMessage< ::fixbug::GetFriendListResponse >(Arena* arena) {
  return Arena::CreateInternal< ::fixbug::GetFriendListResponse >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
