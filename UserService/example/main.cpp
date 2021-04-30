#include "UserService.pb.h"
#include <rpc/RpcChannel.hpp>
#include <rpc/RpcApplication.hpp>
#include <google/protobuf/service.h>
#include <google/protobuf/empty.pb.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    ik_UserService::UserServiceRpc_Stub stub(new RpcChannel);
    ik_UserService::LoginRequest request;
    request.set_id(1);
    request.set_password("123456");

    ik_UserService::LoginReponse response;
    stub.Login(nullptr, &request, &response, nullptr);
}