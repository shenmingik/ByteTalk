#include "UserService.hpp"
#include <rpc/RpcApplication.hpp>
#include <rpc/RpcProvider.hpp>
#include <rpc/RpcControl.hpp>
#include <mysql/mysql.h>

int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    ik::LogServerRpc_Stub stub(new RpcChannel());
    ik::LogRequest request;
    request.set_name("UserServer");
    request.set_msg("error");
    
    stub.Log_INFO(nullptr, &request, nullptr, nullptr);

    /* 
    RpcApplication::init(argc, argv);
    RpcProvider provider;
    provider.notify_service(new UserService);
    provider.run();
    return 0;
    */
}