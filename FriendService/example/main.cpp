
#include "FriendService.pb.h"
#include <rpc/RpcChannel.hpp>
#include <rpc/RpcApplication.hpp>
#include <google/protobuf/service.h>
#include <google/protobuf/empty.pb.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    ik_FriendService::FriendServiceRpc_Stub stub(new RpcChannel);
    ik_FriendService::AddFriendRequest request;
    request.set_myid(1);
    request.set_friendid(4);

    ik_FriendService::FriendListResponse response;
    google::protobuf::Empty em;
    stub.AddFriend(nullptr, &request, &em, nullptr);
}