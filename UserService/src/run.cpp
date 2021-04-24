#include "ZooKeeperMaster.hpp"
#include <string>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv)
{
    RpcApplication::init(argc, argv);
    ZKMatser master("/UserService");
    master.start();
    int client_fd; 
    //获取服务
    while ((client_fd = master.get_service()) == -1)
    {
        // 刷新服务列表
        master.get_follow();
        cout << "no service" << endl;
        sleep(1);
    }
}