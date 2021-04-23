#include "UserService.hpp"
#include <iostream>
#include <memory>
using namespace std;

#define BUFF_SIZE 256

UserService::UserService() : stub_(new RpcChannel)
{
}



void UserService::Login(::google::protobuf::RpcController *controller,
                        const ::ik_UserService::LoginRequest *request,
                        ::ik_UserService::LoginReponse *response,
                        ::google::protobuf::Closure *done)
{
}
void UserService::Registe(::google::protobuf::RpcController *controller,
                          const ::ik_UserService::RegisterRequest *request,
                          ::ik_UserService::RegisterResponse *response,
                          ::google::protobuf::Closure *done)
{
}
void UserService::LoginOut(::google::protobuf::RpcController *controller,
                           const ::ik_UserService::LoginOutRequest *request,
                           ::google::protobuf::Empty *response,
                           ::google::protobuf::Closure *done)
{
}