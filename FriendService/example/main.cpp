
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
    ik_FriendService::FriendListRequest request;
    request.set_id(1);

    ik_FriendService::FriendListResponse response;
    stub.GetFriendList(nullptr, &request, &response, nullptr);
    for (int i = 0; i < response.friends_size(); i++)
    {
        cout << response.friends(i).name() << endl;
    }
}