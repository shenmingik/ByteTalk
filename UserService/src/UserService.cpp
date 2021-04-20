#include "UserService.hpp"
#include <iostream>

using namespace std;

UserService::UserService():stub_(new RpcChannel)
{
    pool_ = Connect_pool::get_instance();
    if(pool_ == nullptr)
    {
        cout<<"error"<<endl;
    }
}

//登录
bool UserService::Login(int id, string password)
{

}

//注销
void UserService::LoginOut(int id)
{
}

//注册 成功返回注册的账户，失败返回-1
int UserService::Register(string name, string password)
{
}