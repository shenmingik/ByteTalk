#pragma once

#include "LogServer.pb.h"
#include "FriendServer.pb.h"
#include "FriendService.pb.h"
#include "ZooKeeperMaster.hpp"

class FriendService
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