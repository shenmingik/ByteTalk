#include "UserService.hpp"
#include <iostream>
#include <memory>
using namespace std;

#define BUFF_SIZE 256

UserService::UserService() : stub_(new RpcChannel), master_("/UserService")
{
    master_.start();
}

void UserService::Login(::google::protobuf::RpcController *controller,
                        const ::ik_UserService::LoginRequest *request,
                        ::ik_UserService::LoginReponse *response,
                        ::google::protobuf::Closure *done)
{
    ik_UserServer::Request login_request;
    login_request.set_type("Login");
    login_request.set_request(request->SerializeAsString());

    string send_str = login_request.SerializeAsString();
    //获取一个服务信息
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        //刷新服务列表
        master_.get_follow();
        sleep(1);
    }

    //发送信息
    send(client_fd, send_str.c_str(), send_str.size(), 0);
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