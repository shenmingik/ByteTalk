#include "UserService.hpp"
#include <rpc/RpcApplication.hpp>
#include <rpc/RpcProvider.hpp>
#include <mysql/mysql.h>

int main(int argc, char **argv)
{
    MYSQL *conn = mysql_init(nullptr);
    MYSQL *p = mysql_real_connect(conn, "172.17.0.2", "ik", "123456", "ByteTalk", 3306, nullptr, 0);
    if (p == nullptr)
    {
        fprintf(stderr, "Failedtoconnecttodatabase:Error:%s\n", mysql_error(conn));
    }

    int red = mysql_query(conn, "update User set state='online' where id=1");
    cout << red << endl;

    /* 
    RpcApplication::init(argc, argv);
    RpcProvider provider;
    provider.notify_service(new UserService);
    provider.run();
    return 0;
    */
}