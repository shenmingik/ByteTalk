#include "FriendServer.hpp"

#define BUFF_SIZE 128

FriendServer::FriendServer(string ip, int port)
{
    ip_ = ip;
    port_ = port;

    pool_ = Connect_pool::get_instance();
}

//服务器运行
void FriendServer::run()
{
}

//读写事件回调函数
void FriendServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
}

//连接事件回调函数
void FriendServer::on_connect(const muduo::net::TcpConnectionPtr &conn)
{
}

//获取userid 用户的好友列表
vector<User> FriendServer::get_friendlist(int userid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select User.id,User.name from Friend,User where Friend.userid=%d and User.id=Friend.friendid", userid);
    MYSQL_RES *res = conn->query(sql);
    MYSQL_ROW row;

    vector<User> ret;
    while (row = mysql_fetch_row(res))
    {
        User user;
        user.set_id(atoi(row[0]));
        user.set_name(row[1]);
        ret.push_back(user);
    }

    mysql_free_result(res);
    return ret;
}

//获得userid用户信息
User FriendServer::get_userinfo(int userid)
{
    shared_ptr<Connect> conn = pool_->get_connect();
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select name from User where id=%d", userid);
    MYSQL_RES *res = conn->query(sql);
    User user;
    MYSQL_ROW row = mysql_fetch_row(res);
    user.set_id(userid);
    user.set_name(row[0]);

    mysql_free_result(res);
    return user;
}

//userid 的用户添加好友 friendid
void FriendServer::add_friend(int userid, int friendid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into Friend values(%d,%d)", userid, friendid);

    conn->update(sql);
}

//删除userid用户的好友 friendid
void FriendServer::delete_friend(int userid, int friendid)
{
    shared_ptr<Connect> conn = pool_->get_connect();

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "delete from Friend where userid=%d and friendid=%d", userid, friendid);

    conn->update(sql);
}