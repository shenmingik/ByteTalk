#include "ProxyServer.hpp"

using namespace placeholders;

//初始化服务器信息
ProxyServer::ProxyServer(muduo::net::EventLoop &loop, muduo::net::InetAddress &address, string name)
    : loop_(loop),
      server_(&loop, address, name)

{
    //注册连接事件回调函数
    server_.setMessageCallback(bind(&ProxyServer::on_message, this, _1, _2, _3));

    //注册连接事件回调函数
    server_.setConnectionCallback(bind(&ProxyServer::on_connet, this, _1));

    //设置工作线程数量
    //最佳线程数目 = （线程等待时间与线程CPU时间之比 + 1）* CPU数目 ==>高网络I/O设计
    server_.setThreadNum(4);
}

//代理服务器开始工作
void ProxyServer::start()
{
    server_.start();
}

//连接事件的回调函数
void ProxyServer::on_connet(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        //当客户端异常退出，执行此命令
        ProxyService::get_instance().client_close_exception(conn);
        conn->shutdown();
    }
}

//读写事件回调函数
void ProxyServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化
    string recv_str = buffer->retrieveAllAsString();
    ik_Proxy::PoxryMessage request;
    request.ParseFromString(recv_str);

    //获取对应的处理器并执行
    auto msg_handler = ProxyService::get_instance().get_handler(request.type());
    string str = request.request_msg();
    msg_handler(conn, str, stamp);
}