#pragma once
#include "LogServer.pb.h"
#include "UserService.pb.h"
#include <mysql/mysql.h>
#include <SQL_pool/connect_pool.hpp>
#include <rpc/RpcChannel.hpp>
#include <google/protobuf/service.h>
#include <string>

using namespace std;

class UserService : public ik_UserService::UserServiceRpc
{
public:
    UserService();

public:
    void Login(::google::protobuf::RpcController *controller,
               const ::ik_UserService::LoginRequest *request,
               ::ik_UserService::LoginReponse *response,
               ::google::protobuf::Closure *done);
    void Registe(::google::protobuf::RpcController *controller,
                 const ::ik_UserService::RegisterRequest *request,
                 ::ik_UserService::RegisterResponse *response,
                 ::google::protobuf::Closure *done);
    void LoginOut(::google::protobuf::RpcController *controller,
                  const ::ik_UserService::LoginOutRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done);

private:
    ik::LogServerRpc_Stub stub_; //日志服务器桩类
};