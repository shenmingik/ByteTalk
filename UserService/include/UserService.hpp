#pragma once
#include "LogServer.pb.h"
#include "UserService.pb.h"
#include <mysql/mysql.h>
#include <SQL_pool/connect_pool.hpp>
#include <rpc/RpcChannel.hpp>
#include <google/protobuf/service.h>

using namespace std;

class UserService : public ik_login::UserServiceRpc
{
public:
    UserService();

    //登录
    bool Login(int id, string password);

    //注销
    void LoginOut(int id);

    //注册 成功返回注册的账户，失败返回-1
    int Register(string name, string password);

public:
    void Login(::google::protobuf::RpcController *controller,
               const ::ik_login::LoginRequest *request,
               ::ik_login::LoginReponse *response,
               ::google::protobuf::Closure *done);
    void Registe(::google::protobuf::RpcController *controller,
                 const ::ik_login::RegisterRequest *request,
                 ::ik_login::RegisterResponse *response,
                 ::google::protobuf::Closure *done);
    void LoginOut(::google::protobuf::RpcController *controller,
                  const ::ik_login::LoginOutRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done);

private:
    Connect_pool *pool_; //数据库连接池

    ik::LogServerRpc_Stub stub_; //日志服务器桩类
};