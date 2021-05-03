#include "LogServer.pb.h"
#include "GroupServer.pb.h"
#include "GroupService.pb.h"

#include "ZooKeeperMaster.hpp"

#include <google/protobuf/service.h>
#include <rpc/RpcChannel.hpp>
#include <rpc/RpcControl.hpp>

#include <string>

using namespace std;

class GroupService : public ik_ChatService::GroupServiceRpc
{
public:
    GroupService();

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
    ik::LogServerRpc_Stub stub_;

    ZKMatser master_;
};