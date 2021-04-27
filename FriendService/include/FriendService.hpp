#pragma once

#include "LogServer.pb.h"
#include "FriendServer.pb.h"
#include "FriendService.pb.h"
#include "ZooKeeperMaster.hpp"

#include <google/protobuf/empty.pb.h>
#include <google/protobuf/service.h>
#include <rpc/RpcChannel.hpp>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string>

using namespace std;

class FriendService : public ik_FriendService::FriendServiceRpc
{
public:
    FriendService();

public:
    //获取好友列表
    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::ik_FriendService::FriendListRequest *request,
                       ::ik_FriendService::FriendListResponse *response,
                       ::google::protobuf::Closure *done);

    //获得用户信息
    void GetUserInfo(::google::protobuf::RpcController *controller,
                     const ::ik_FriendService::UserInfoRequest *request,
                     ::ik_FriendService::UserInfoReponse *response,
                     ::google::protobuf::Closure *done);

    //添加好友
    void AddFriend(::google::protobuf::RpcController *controller,
                   const ::ik_FriendService::AddFriendRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done);

    //删除好友
    void DeleteFriend(::google::protobuf::RpcController *controller,
                      const ::ik_FriendService::DeleteFriendRequest *request,
                      ::google::protobuf::Empty *response,
                      ::google::protobuf::Closure *done);

private:
    ik::LogServerRpc_Stub log_stub_;
    ZKMatser master_;
};