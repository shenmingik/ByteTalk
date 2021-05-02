#include "ZooKeeperFow.hpp"
#include "GroupServer.pb.h"

#include <SQL_pool/connect_pool.hpp>

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>

#include <string>
#include <functional>

using namespace std;

class GroupServer
{
public:
    //将userid所代表的用户添加到groupid的群里
    bool add_group(int userid,int groupid);

    //创建群，群名为group_name
    bool create_group(int userid,string group_name);

private:
    ZKClient zk_client_;

    Connect_pool pool_;
};