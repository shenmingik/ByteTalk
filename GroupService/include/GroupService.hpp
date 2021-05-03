#include "GroupServer.pb.h"
#include "GroupService.pb.h"

class GroupService : public ik_ChatService::GroupServiceRpc
{
public:
    void AddGroup(::google::protobuf::RpcController *controller,
                  const ::ik_ChatService::AddGroupRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done);
    void CreateGroup(::google::protobuf::RpcController *controller,
                     const ::ik_ChatService::CreateGroupRequest *request,
                     ::ik_ChatService::CreateGroupResponse *response,
                     ::google::protobuf::Closure *done);
    void QuitGroup(::google::protobuf::RpcController *controller,
                   const ::ik_ChatService::QuitGroupRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done);
    void GetGroupUsers(::google::protobuf::RpcController *controller,
                       const ::ik_ChatService::GetGroupUsersRequest *request,
                       ::ik_ChatService::GetGroupUsersResponse *response,
                       ::google::protobuf::Closure *done);

private:
};