// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GroupService.proto

#ifndef PROTOBUF_GroupService_2eproto__INCLUDED
#define PROTOBUF_GroupService_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/empty.pb.h>
// @@protoc_insertion_point(includes)

namespace ik_ChatService {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_GroupService_2eproto();
void protobuf_AssignDesc_GroupService_2eproto();
void protobuf_ShutdownFile_GroupService_2eproto();

class AddGroupRequest;
class CreateGroupRequest;
class CreateGroupResponse;
class GetGroupUsersRequest;
class GetGroupUsersResponse;
class QuitGroupRequest;
class UserInfo;

// ===================================================================

class AddGroupRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.AddGroupRequest) */ {
 public:
  AddGroupRequest();
  virtual ~AddGroupRequest();

  AddGroupRequest(const AddGroupRequest& from);

  inline AddGroupRequest& operator=(const AddGroupRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AddGroupRequest& default_instance();

  void Swap(AddGroupRequest* other);

  // implements Message ----------------------------------------------

  inline AddGroupRequest* New() const { return New(NULL); }

  AddGroupRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AddGroupRequest& from);
  void MergeFrom(const AddGroupRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(AddGroupRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 userid = 1;
  void clear_userid();
  static const int kUseridFieldNumber = 1;
  ::google::protobuf::int32 userid() const;
  void set_userid(::google::protobuf::int32 value);

  // optional int32 group_id = 2;
  void clear_group_id();
  static const int kGroupIdFieldNumber = 2;
  ::google::protobuf::int32 group_id() const;
  void set_group_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ik_ChatService.AddGroupRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 userid_;
  ::google::protobuf::int32 group_id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static AddGroupRequest* default_instance_;
};
// -------------------------------------------------------------------

class CreateGroupRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.CreateGroupRequest) */ {
 public:
  CreateGroupRequest();
  virtual ~CreateGroupRequest();

  CreateGroupRequest(const CreateGroupRequest& from);

  inline CreateGroupRequest& operator=(const CreateGroupRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CreateGroupRequest& default_instance();

  void Swap(CreateGroupRequest* other);

  // implements Message ----------------------------------------------

  inline CreateGroupRequest* New() const { return New(NULL); }

  CreateGroupRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CreateGroupRequest& from);
  void MergeFrom(const CreateGroupRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CreateGroupRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 userid = 1;
  void clear_userid();
  static const int kUseridFieldNumber = 1;
  ::google::protobuf::int32 userid() const;
  void set_userid(::google::protobuf::int32 value);

  // optional bytes group_name = 2;
  void clear_group_name();
  static const int kGroupNameFieldNumber = 2;
  const ::std::string& group_name() const;
  void set_group_name(const ::std::string& value);
  void set_group_name(const char* value);
  void set_group_name(const void* value, size_t size);
  ::std::string* mutable_group_name();
  ::std::string* release_group_name();
  void set_allocated_group_name(::std::string* group_name);

  // @@protoc_insertion_point(class_scope:ik_ChatService.CreateGroupRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr group_name_;
  ::google::protobuf::int32 userid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static CreateGroupRequest* default_instance_;
};
// -------------------------------------------------------------------

class CreateGroupResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.CreateGroupResponse) */ {
 public:
  CreateGroupResponse();
  virtual ~CreateGroupResponse();

  CreateGroupResponse(const CreateGroupResponse& from);

  inline CreateGroupResponse& operator=(const CreateGroupResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CreateGroupResponse& default_instance();

  void Swap(CreateGroupResponse* other);

  // implements Message ----------------------------------------------

  inline CreateGroupResponse* New() const { return New(NULL); }

  CreateGroupResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CreateGroupResponse& from);
  void MergeFrom(const CreateGroupResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(CreateGroupResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 grouid = 1;
  void clear_grouid();
  static const int kGrouidFieldNumber = 1;
  ::google::protobuf::int32 grouid() const;
  void set_grouid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ik_ChatService.CreateGroupResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 grouid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static CreateGroupResponse* default_instance_;
};
// -------------------------------------------------------------------

class QuitGroupRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.QuitGroupRequest) */ {
 public:
  QuitGroupRequest();
  virtual ~QuitGroupRequest();

  QuitGroupRequest(const QuitGroupRequest& from);

  inline QuitGroupRequest& operator=(const QuitGroupRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const QuitGroupRequest& default_instance();

  void Swap(QuitGroupRequest* other);

  // implements Message ----------------------------------------------

  inline QuitGroupRequest* New() const { return New(NULL); }

  QuitGroupRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const QuitGroupRequest& from);
  void MergeFrom(const QuitGroupRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(QuitGroupRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 userid = 1;
  void clear_userid();
  static const int kUseridFieldNumber = 1;
  ::google::protobuf::int32 userid() const;
  void set_userid(::google::protobuf::int32 value);

  // optional int32 groupid = 2;
  void clear_groupid();
  static const int kGroupidFieldNumber = 2;
  ::google::protobuf::int32 groupid() const;
  void set_groupid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ik_ChatService.QuitGroupRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 userid_;
  ::google::protobuf::int32 groupid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static QuitGroupRequest* default_instance_;
};
// -------------------------------------------------------------------

class GetGroupUsersRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.GetGroupUsersRequest) */ {
 public:
  GetGroupUsersRequest();
  virtual ~GetGroupUsersRequest();

  GetGroupUsersRequest(const GetGroupUsersRequest& from);

  inline GetGroupUsersRequest& operator=(const GetGroupUsersRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetGroupUsersRequest& default_instance();

  void Swap(GetGroupUsersRequest* other);

  // implements Message ----------------------------------------------

  inline GetGroupUsersRequest* New() const { return New(NULL); }

  GetGroupUsersRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGroupUsersRequest& from);
  void MergeFrom(const GetGroupUsersRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetGroupUsersRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 group_id = 1;
  void clear_group_id();
  static const int kGroupIdFieldNumber = 1;
  ::google::protobuf::int32 group_id() const;
  void set_group_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ik_ChatService.GetGroupUsersRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 group_id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static GetGroupUsersRequest* default_instance_;
};
// -------------------------------------------------------------------

class UserInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.UserInfo) */ {
 public:
  UserInfo();
  virtual ~UserInfo();

  UserInfo(const UserInfo& from);

  inline UserInfo& operator=(const UserInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UserInfo& default_instance();

  void Swap(UserInfo* other);

  // implements Message ----------------------------------------------

  inline UserInfo* New() const { return New(NULL); }

  UserInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UserInfo& from);
  void MergeFrom(const UserInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(UserInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional bytes name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:ik_ChatService.UserInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static UserInfo* default_instance_;
};
// -------------------------------------------------------------------

class GetGroupUsersResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_ChatService.GetGroupUsersResponse) */ {
 public:
  GetGroupUsersResponse();
  virtual ~GetGroupUsersResponse();

  GetGroupUsersResponse(const GetGroupUsersResponse& from);

  inline GetGroupUsersResponse& operator=(const GetGroupUsersResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetGroupUsersResponse& default_instance();

  void Swap(GetGroupUsersResponse* other);

  // implements Message ----------------------------------------------

  inline GetGroupUsersResponse* New() const { return New(NULL); }

  GetGroupUsersResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetGroupUsersResponse& from);
  void MergeFrom(const GetGroupUsersResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetGroupUsersResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .ik_ChatService.UserInfo users = 1;
  int users_size() const;
  void clear_users();
  static const int kUsersFieldNumber = 1;
  const ::ik_ChatService::UserInfo& users(int index) const;
  ::ik_ChatService::UserInfo* mutable_users(int index);
  ::ik_ChatService::UserInfo* add_users();
  ::google::protobuf::RepeatedPtrField< ::ik_ChatService::UserInfo >*
      mutable_users();
  const ::google::protobuf::RepeatedPtrField< ::ik_ChatService::UserInfo >&
      users() const;

  // @@protoc_insertion_point(class_scope:ik_ChatService.GetGroupUsersResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::ik_ChatService::UserInfo > users_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GroupService_2eproto();
  friend void protobuf_AssignDesc_GroupService_2eproto();
  friend void protobuf_ShutdownFile_GroupService_2eproto();

  void InitAsDefaultInstance();
  static GetGroupUsersResponse* default_instance_;
};
// ===================================================================

class GroupServiceRpc_Stub;

class GroupServiceRpc : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline GroupServiceRpc() {};
 public:
  virtual ~GroupServiceRpc();

  typedef GroupServiceRpc_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void AddGroup(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::AddGroupRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
  virtual void CreateGroup(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::CreateGroupRequest* request,
                       ::ik_ChatService::CreateGroupResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void QuitGroup(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::QuitGroupRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
  virtual void GetGroupUsers(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::GetGroupUsersRequest* request,
                       ::ik_ChatService::GetGroupUsersResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(GroupServiceRpc);
};

class GroupServiceRpc_Stub : public GroupServiceRpc {
 public:
  GroupServiceRpc_Stub(::google::protobuf::RpcChannel* channel);
  GroupServiceRpc_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~GroupServiceRpc_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements GroupServiceRpc ------------------------------------------

  void AddGroup(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::AddGroupRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
  void CreateGroup(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::CreateGroupRequest* request,
                       ::ik_ChatService::CreateGroupResponse* response,
                       ::google::protobuf::Closure* done);
  void QuitGroup(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::QuitGroupRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
  void GetGroupUsers(::google::protobuf::RpcController* controller,
                       const ::ik_ChatService::GetGroupUsersRequest* request,
                       ::ik_ChatService::GetGroupUsersResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(GroupServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// AddGroupRequest

// optional int32 userid = 1;
inline void AddGroupRequest::clear_userid() {
  userid_ = 0;
}
inline ::google::protobuf::int32 AddGroupRequest::userid() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.AddGroupRequest.userid)
  return userid_;
}
inline void AddGroupRequest::set_userid(::google::protobuf::int32 value) {
  
  userid_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.AddGroupRequest.userid)
}

// optional int32 group_id = 2;
inline void AddGroupRequest::clear_group_id() {
  group_id_ = 0;
}
inline ::google::protobuf::int32 AddGroupRequest::group_id() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.AddGroupRequest.group_id)
  return group_id_;
}
inline void AddGroupRequest::set_group_id(::google::protobuf::int32 value) {
  
  group_id_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.AddGroupRequest.group_id)
}

// -------------------------------------------------------------------

// CreateGroupRequest

// optional int32 userid = 1;
inline void CreateGroupRequest::clear_userid() {
  userid_ = 0;
}
inline ::google::protobuf::int32 CreateGroupRequest::userid() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.CreateGroupRequest.userid)
  return userid_;
}
inline void CreateGroupRequest::set_userid(::google::protobuf::int32 value) {
  
  userid_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.CreateGroupRequest.userid)
}

// optional bytes group_name = 2;
inline void CreateGroupRequest::clear_group_name() {
  group_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CreateGroupRequest::group_name() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.CreateGroupRequest.group_name)
  return group_name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CreateGroupRequest::set_group_name(const ::std::string& value) {
  
  group_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ik_ChatService.CreateGroupRequest.group_name)
}
inline void CreateGroupRequest::set_group_name(const char* value) {
  
  group_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ik_ChatService.CreateGroupRequest.group_name)
}
inline void CreateGroupRequest::set_group_name(const void* value, size_t size) {
  
  group_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ik_ChatService.CreateGroupRequest.group_name)
}
inline ::std::string* CreateGroupRequest::mutable_group_name() {
  
  // @@protoc_insertion_point(field_mutable:ik_ChatService.CreateGroupRequest.group_name)
  return group_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CreateGroupRequest::release_group_name() {
  // @@protoc_insertion_point(field_release:ik_ChatService.CreateGroupRequest.group_name)
  
  return group_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CreateGroupRequest::set_allocated_group_name(::std::string* group_name) {
  if (group_name != NULL) {
    
  } else {
    
  }
  group_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), group_name);
  // @@protoc_insertion_point(field_set_allocated:ik_ChatService.CreateGroupRequest.group_name)
}

// -------------------------------------------------------------------

// CreateGroupResponse

// optional int32 grouid = 1;
inline void CreateGroupResponse::clear_grouid() {
  grouid_ = 0;
}
inline ::google::protobuf::int32 CreateGroupResponse::grouid() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.CreateGroupResponse.grouid)
  return grouid_;
}
inline void CreateGroupResponse::set_grouid(::google::protobuf::int32 value) {
  
  grouid_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.CreateGroupResponse.grouid)
}

// -------------------------------------------------------------------

// QuitGroupRequest

// optional int32 userid = 1;
inline void QuitGroupRequest::clear_userid() {
  userid_ = 0;
}
inline ::google::protobuf::int32 QuitGroupRequest::userid() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.QuitGroupRequest.userid)
  return userid_;
}
inline void QuitGroupRequest::set_userid(::google::protobuf::int32 value) {
  
  userid_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.QuitGroupRequest.userid)
}

// optional int32 groupid = 2;
inline void QuitGroupRequest::clear_groupid() {
  groupid_ = 0;
}
inline ::google::protobuf::int32 QuitGroupRequest::groupid() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.QuitGroupRequest.groupid)
  return groupid_;
}
inline void QuitGroupRequest::set_groupid(::google::protobuf::int32 value) {
  
  groupid_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.QuitGroupRequest.groupid)
}

// -------------------------------------------------------------------

// GetGroupUsersRequest

// optional int32 group_id = 1;
inline void GetGroupUsersRequest::clear_group_id() {
  group_id_ = 0;
}
inline ::google::protobuf::int32 GetGroupUsersRequest::group_id() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.GetGroupUsersRequest.group_id)
  return group_id_;
}
inline void GetGroupUsersRequest::set_group_id(::google::protobuf::int32 value) {
  
  group_id_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.GetGroupUsersRequest.group_id)
}

// -------------------------------------------------------------------

// UserInfo

// optional int32 id = 1;
inline void UserInfo::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 UserInfo::id() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.UserInfo.id)
  return id_;
}
inline void UserInfo::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:ik_ChatService.UserInfo.id)
}

// optional bytes name = 2;
inline void UserInfo::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserInfo::name() const {
  // @@protoc_insertion_point(field_get:ik_ChatService.UserInfo.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ik_ChatService.UserInfo.name)
}
inline void UserInfo::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ik_ChatService.UserInfo.name)
}
inline void UserInfo::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ik_ChatService.UserInfo.name)
}
inline ::std::string* UserInfo::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:ik_ChatService.UserInfo.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserInfo::release_name() {
  // @@protoc_insertion_point(field_release:ik_ChatService.UserInfo.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:ik_ChatService.UserInfo.name)
}

// -------------------------------------------------------------------

// GetGroupUsersResponse

// repeated .ik_ChatService.UserInfo users = 1;
inline int GetGroupUsersResponse::users_size() const {
  return users_.size();
}
inline void GetGroupUsersResponse::clear_users() {
  users_.Clear();
}
inline const ::ik_ChatService::UserInfo& GetGroupUsersResponse::users(int index) const {
  // @@protoc_insertion_point(field_get:ik_ChatService.GetGroupUsersResponse.users)
  return users_.Get(index);
}
inline ::ik_ChatService::UserInfo* GetGroupUsersResponse::mutable_users(int index) {
  // @@protoc_insertion_point(field_mutable:ik_ChatService.GetGroupUsersResponse.users)
  return users_.Mutable(index);
}
inline ::ik_ChatService::UserInfo* GetGroupUsersResponse::add_users() {
  // @@protoc_insertion_point(field_add:ik_ChatService.GetGroupUsersResponse.users)
  return users_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::ik_ChatService::UserInfo >*
GetGroupUsersResponse::mutable_users() {
  // @@protoc_insertion_point(field_mutable_list:ik_ChatService.GetGroupUsersResponse.users)
  return &users_;
}
inline const ::google::protobuf::RepeatedPtrField< ::ik_ChatService::UserInfo >&
GetGroupUsersResponse::users() const {
  // @@protoc_insertion_point(field_list:ik_ChatService.GetGroupUsersResponse.users)
  return users_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ik_ChatService

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_GroupService_2eproto__INCLUDED
