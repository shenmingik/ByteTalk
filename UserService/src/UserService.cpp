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
    master_.get_follow();
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

    //获取信息
    char recv_buf[BUFF_SIZE] = {0};
    recv(client_fd, recv_buf, BUFF_SIZE, 0);
    ik_UserServer::LoginReponse login_response;
    login_response.ParseFromString(recv_buf);
    response->set_is_success(login_response.is_success());

    close(client_fd);
    done->Run();
}
void UserService::Registe(::google::protobuf::RpcController *controller,
                          const ::ik_UserService::RegisterRequest *request,
                          ::ik_UserService::RegisterResponse *response,
                          ::google::protobuf::Closure *done)
{
    master_.get_follow();
    ik_UserServer::Request register_request;
    register_request.set_type("Register");
    register_request.set_request(request->SerializeAsString());

    string send_str = register_request.SerializeAsString();
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

    //获取信息
    char recv_buf[BUFF_SIZE] = {0};
    recv(client_fd, recv_buf, BUFF_SIZE, 0);
    ik_UserServer::RegisterResponse register_response;

    register_response.ParseFromString(recv_buf);
    response->set_id(register_response.id());
    response->set_is_success(register_response.is_success());

    close(client_fd);
    done->Run();
}
void UserService::LoginOut(::google::protobuf::RpcController *controller,
                           const ::ik_UserService::LoginOutRequest *request,
                           ::google::protobuf::Empty *response,
                           ::google::protobuf::Closure *done)
{
    master_.get_follow();
    ik_UserServer::Request loginout_request;
    loginout_request.set_type("LoginOut");
    loginout_request.set_request(request->SerializeAsString());

    string send_str = loginout_request.SerializeAsString();
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

    close(client_fd);
    done->Run();
}