// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FriendService.proto

#ifndef PROTOBUF_FriendService_2eproto__INCLUDED
#define PROTOBUF_FriendService_2eproto__INCLUDED

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

namespace ik_FriendService {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_FriendService_2eproto();
void protobuf_AssignDesc_FriendService_2eproto();
void protobuf_ShutdownFile_FriendService_2eproto();

class AddFriendRequest;
class DeleteFriendRequest;
class FriendInfo;
class FriendListRequest;
class FriendListResponse;
class UserInfoReponse;
class UserInfoRequest;

// ===================================================================

class UserInfoRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.UserInfoRequest) */ {
 public:
  UserInfoRequest();
  virtual ~UserInfoRequest();

  UserInfoRequest(const UserInfoRequest& from);

  inline UserInfoRequest& operator=(const UserInfoRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UserInfoRequest& default_instance();

  void Swap(UserInfoRequest* other);

  // implements Message ----------------------------------------------

  inline UserInfoRequest* New() const { return New(NULL); }

  UserInfoRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UserInfoRequest& from);
  void MergeFrom(const UserInfoRequest& from);
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
  void InternalSwap(UserInfoRequest* other);
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

  // @@protoc_insertion_point(class_scope:ik_FriendService.UserInfoRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static UserInfoRequest* default_instance_;
};
// -------------------------------------------------------------------

class UserInfoReponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.UserInfoReponse) */ {
 public:
  UserInfoReponse();
  virtual ~UserInfoReponse();

  UserInfoReponse(const UserInfoReponse& from);

  inline UserInfoReponse& operator=(const UserInfoReponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UserInfoReponse& default_instance();

  void Swap(UserInfoReponse* other);

  // implements Message ----------------------------------------------

  inline UserInfoReponse* New() const { return New(NULL); }

  UserInfoReponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UserInfoReponse& from);
  void MergeFrom(const UserInfoReponse& from);
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
  void InternalSwap(UserInfoReponse* other);
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

  // @@protoc_insertion_point(class_scope:ik_FriendService.UserInfoReponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static UserInfoReponse* default_instance_;
};
// -------------------------------------------------------------------

class FriendInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.FriendInfo) */ {
 public:
  FriendInfo();
  virtual ~FriendInfo();

  FriendInfo(const FriendInfo& from);

  inline FriendInfo& operator=(const FriendInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const FriendInfo& default_instance();

  void Swap(FriendInfo* other);

  // implements Message ----------------------------------------------

  inline FriendInfo* New() const { return New(NULL); }

  FriendInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const FriendInfo& from);
  void MergeFrom(const FriendInfo& from);
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
  void InternalSwap(FriendInfo* other);
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

  // @@protoc_insertion_point(class_scope:ik_FriendService.FriendInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static FriendInfo* default_instance_;
};
// -------------------------------------------------------------------

class FriendListRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.FriendListRequest) */ {
 public:
  FriendListRequest();
  virtual ~FriendListRequest();

  FriendListRequest(const FriendListRequest& from);

  inline FriendListRequest& operator=(const FriendListRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const FriendListRequest& default_instance();

  void Swap(FriendListRequest* other);

  // implements Message ----------------------------------------------

  inline FriendListRequest* New() const { return New(NULL); }

  FriendListRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const FriendListRequest& from);
  void MergeFrom(const FriendListRequest& from);
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
  void InternalSwap(FriendListRequest* other);
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

  // @@protoc_insertion_point(class_scope:ik_FriendService.FriendListRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static FriendListRequest* default_instance_;
};
// -------------------------------------------------------------------

class FriendListResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.FriendListResponse) */ {
 public:
  FriendListResponse();
  virtual ~FriendListResponse();

  FriendListResponse(const FriendListResponse& from);

  inline FriendListResponse& operator=(const FriendListResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const FriendListResponse& default_instance();

  void Swap(FriendListResponse* other);

  // implements Message ----------------------------------------------

  inline FriendListResponse* New() const { return New(NULL); }

  FriendListResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const FriendListResponse& from);
  void MergeFrom(const FriendListResponse& from);
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
  void InternalSwap(FriendListResponse* other);
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

  // optional bool is_success = 1;
  void clear_is_success();
  static const int kIsSuccessFieldNumber = 1;
  bool is_success() const;
  void set_is_success(bool value);

  // repeated .ik_FriendService.FriendInfo friends = 2;
  int friends_size() const;
  void clear_friends();
  static const int kFriendsFieldNumber = 2;
  const ::ik_FriendService::FriendInfo& friends(int index) const;
  ::ik_FriendService::FriendInfo* mutable_friends(int index);
  ::ik_FriendService::FriendInfo* add_friends();
  ::google::protobuf::RepeatedPtrField< ::ik_FriendService::FriendInfo >*
      mutable_friends();
  const ::google::protobuf::RepeatedPtrField< ::ik_FriendService::FriendInfo >&
      friends() const;

  // @@protoc_insertion_point(class_scope:ik_FriendService.FriendListResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::ik_FriendService::FriendInfo > friends_;
  bool is_success_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static FriendListResponse* default_instance_;
};
// -------------------------------------------------------------------

class AddFriendRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.AddFriendRequest) */ {
 public:
  AddFriendRequest();
  virtual ~AddFriendRequest();

  AddFriendRequest(const AddFriendRequest& from);

  inline AddFriendRequest& operator=(const AddFriendRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AddFriendRequest& default_instance();

  void Swap(AddFriendRequest* other);

  // implements Message ----------------------------------------------

  inline AddFriendRequest* New() const { return New(NULL); }

  AddFriendRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AddFriendRequest& from);
  void MergeFrom(const AddFriendRequest& from);
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
  void InternalSwap(AddFriendRequest* other);
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

  // optional int32 myid = 1;
  void clear_myid();
  static const int kMyidFieldNumber = 1;
  ::google::protobuf::int32 myid() const;
  void set_myid(::google::protobuf::int32 value);

  // optional int32 friendid = 2;
  void clear_friendid();
  static const int kFriendidFieldNumber = 2;
  ::google::protobuf::int32 friendid() const;
  void set_friendid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ik_FriendService.AddFriendRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 myid_;
  ::google::protobuf::int32 friendid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static AddFriendRequest* default_instance_;
};
// -------------------------------------------------------------------

class DeleteFriendRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ik_FriendService.DeleteFriendRequest) */ {
 public:
  DeleteFriendRequest();
  virtual ~DeleteFriendRequest();

  DeleteFriendRequest(const DeleteFriendRequest& from);

  inline DeleteFriendRequest& operator=(const DeleteFriendRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DeleteFriendRequest& default_instance();

  void Swap(DeleteFriendRequest* other);

  // implements Message ----------------------------------------------

  inline DeleteFriendRequest* New() const { return New(NULL); }

  DeleteFriendRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DeleteFriendRequest& from);
  void MergeFrom(const DeleteFriendRequest& from);
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
  void InternalSwap(DeleteFriendRequest* other);
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

  // optional int32 myid = 1;
  void clear_myid();
  static const int kMyidFieldNumber = 1;
  ::google::protobuf::int32 myid() const;
  void set_myid(::google::protobuf::int32 value);

  // optional int32 friendid = 2;
  void clear_friendid();
  static const int kFriendidFieldNumber = 2;
  ::google::protobuf::int32 friendid() const;
  void set_friendid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ik_FriendService.DeleteFriendRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 myid_;
  ::google::protobuf::int32 friendid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_FriendService_2eproto();
  friend void protobuf_AssignDesc_FriendService_2eproto();
  friend void protobuf_ShutdownFile_FriendService_2eproto();

  void InitAsDefaultInstance();
  static DeleteFriendRequest* default_instance_;
};
// ===================================================================

class FriendServiceRpc_Stub;

class FriendServiceRpc : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline FriendServiceRpc() {};
 public:
  virtual ~FriendServiceRpc();

  typedef FriendServiceRpc_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void GetFriendList(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::FriendListRequest* request,
                       ::ik_FriendService::FriendListResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void GetUserInfo(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::UserInfoRequest* request,
                       ::ik_FriendService::UserInfoReponse* response,
                       ::google::protobuf::Closure* done);
  virtual void AddFriend(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::AddFriendRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
  virtual void DeleteFriend(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::DeleteFriendRequest* request,
                       ::google::protobuf::Empty* response,
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
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc);
};

class FriendServiceRpc_Stub : public FriendServiceRpc {
 public:
  FriendServiceRpc_Stub(::google::protobuf::RpcChannel* channel);
  FriendServiceRpc_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~FriendServiceRpc_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements FriendServiceRpc ------------------------------------------

  void GetFriendList(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::FriendListRequest* request,
                       ::ik_FriendService::FriendListResponse* response,
                       ::google::protobuf::Closure* done);
  void GetUserInfo(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::UserInfoRequest* request,
                       ::ik_FriendService::UserInfoReponse* response,
                       ::google::protobuf::Closure* done);
  void AddFriend(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::AddFriendRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
  void DeleteFriend(::google::protobuf::RpcController* controller,
                       const ::ik_FriendService::DeleteFriendRequest* request,
                       ::google::protobuf::Empty* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// UserInfoRequest

// optional int32 id = 1;
inline void UserInfoRequest::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 UserInfoRequest::id() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.UserInfoRequest.id)
  return id_;
}
inline void UserInfoRequest::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.UserInfoRequest.id)
}

// -------------------------------------------------------------------

// UserInfoReponse

// optional int32 id = 1;
inline void UserInfoReponse::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 UserInfoReponse::id() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.UserInfoReponse.id)
  return id_;
}
inline void UserInfoReponse::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.UserInfoReponse.id)
}

// optional bytes name = 2;
inline void UserInfoReponse::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserInfoReponse::name() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.UserInfoReponse.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfoReponse::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ik_FriendService.UserInfoReponse.name)
}
inline void UserInfoReponse::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ik_FriendService.UserInfoReponse.name)
}
inline void UserInfoReponse::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ik_FriendService.UserInfoReponse.name)
}
inline ::std::string* UserInfoReponse::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:ik_FriendService.UserInfoReponse.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserInfoReponse::release_name() {
  // @@protoc_insertion_point(field_release:ik_FriendService.UserInfoReponse.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfoReponse::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:ik_FriendService.UserInfoReponse.name)
}

// -------------------------------------------------------------------

// FriendInfo

// optional int32 id = 1;
inline void FriendInfo::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 FriendInfo::id() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.FriendInfo.id)
  return id_;
}
inline void FriendInfo::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.FriendInfo.id)
}

// optional bytes name = 2;
inline void FriendInfo::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FriendInfo::name() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.FriendInfo.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FriendInfo::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ik_FriendService.FriendInfo.name)
}
inline void FriendInfo::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ik_FriendService.FriendInfo.name)
}
inline void FriendInfo::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ik_FriendService.FriendInfo.name)
}
inline ::std::string* FriendInfo::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:ik_FriendService.FriendInfo.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FriendInfo::release_name() {
  // @@protoc_insertion_point(field_release:ik_FriendService.FriendInfo.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FriendInfo::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:ik_FriendService.FriendInfo.name)
}

// -------------------------------------------------------------------

// FriendListRequest

// optional int32 id = 1;
inline void FriendListRequest::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 FriendListRequest::id() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.FriendListRequest.id)
  return id_;
}
inline void FriendListRequest::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.FriendListRequest.id)
}

// -------------------------------------------------------------------

// FriendListResponse

// optional bool is_success = 1;
inline void FriendListResponse::clear_is_success() {
  is_success_ = false;
}
inline bool FriendListResponse::is_success() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.FriendListResponse.is_success)
  return is_success_;
}
inline void FriendListResponse::set_is_success(bool value) {
  
  is_success_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.FriendListResponse.is_success)
}

// repeated .ik_FriendService.FriendInfo friends = 2;
inline int FriendListResponse::friends_size() const {
  return friends_.size();
}
inline void FriendListResponse::clear_friends() {
  friends_.Clear();
}
inline const ::ik_FriendService::FriendInfo& FriendListResponse::friends(int index) const {
  // @@protoc_insertion_point(field_get:ik_FriendService.FriendListResponse.friends)
  return friends_.Get(index);
}
inline ::ik_FriendService::FriendInfo* FriendListResponse::mutable_friends(int index) {
  // @@protoc_insertion_point(field_mutable:ik_FriendService.FriendListResponse.friends)
  return friends_.Mutable(index);
}
inline ::ik_FriendService::FriendInfo* FriendListResponse::add_friends() {
  // @@protoc_insertion_point(field_add:ik_FriendService.FriendListResponse.friends)
  return friends_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::ik_FriendService::FriendInfo >*
FriendListResponse::mutable_friends() {
  // @@protoc_insertion_point(field_mutable_list:ik_FriendService.FriendListResponse.friends)
  return &friends_;
}
inline const ::google::protobuf::RepeatedPtrField< ::ik_FriendService::FriendInfo >&
FriendListResponse::friends() const {
  // @@protoc_insertion_point(field_list:ik_FriendService.FriendListResponse.friends)
  return friends_;
}

// -------------------------------------------------------------------

// AddFriendRequest

// optional int32 myid = 1;
inline void AddFriendRequest::clear_myid() {
  myid_ = 0;
}
inline ::google::protobuf::int32 AddFriendRequest::myid() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.AddFriendRequest.myid)
  return myid_;
}
inline void AddFriendRequest::set_myid(::google::protobuf::int32 value) {
  
  myid_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.AddFriendRequest.myid)
}

// optional int32 friendid = 2;
inline void AddFriendRequest::clear_friendid() {
  friendid_ = 0;
}
inline ::google::protobuf::int32 AddFriendRequest::friendid() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.AddFriendRequest.friendid)
  return friendid_;
}
inline void AddFriendRequest::set_friendid(::google::protobuf::int32 value) {
  
  friendid_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.AddFriendRequest.friendid)
}

// -------------------------------------------------------------------

// DeleteFriendRequest

// optional int32 myid = 1;
inline void DeleteFriendRequest::clear_myid() {
  myid_ = 0;
}
inline ::google::protobuf::int32 DeleteFriendRequest::myid() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.DeleteFriendRequest.myid)
  return myid_;
}
inline void DeleteFriendRequest::set_myid(::google::protobuf::int32 value) {
  
  myid_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.DeleteFriendRequest.myid)
}

// optional int32 friendid = 2;
inline void DeleteFriendRequest::clear_friendid() {
  friendid_ = 0;
}
inline ::google::protobuf::int32 DeleteFriendRequest::friendid() const {
  // @@protoc_insertion_point(field_get:ik_FriendService.DeleteFriendRequest.friendid)
  return friendid_;
}
inline void DeleteFriendRequest::set_friendid(::google::protobuf::int32 value) {
  
  friendid_ = value;
  // @@protoc_insertion_point(field_set:ik_FriendService.DeleteFriendRequest.friendid)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ik_FriendService

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_FriendService_2eproto__INCLUDED
