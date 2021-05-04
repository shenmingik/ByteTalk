#include "ProxyService.hpp"

using namespace placeholders;

ProxyService::ProxyService() : master_("/ChatService"),
                               log_stub_(new RpcChannel),
                               friend_stub_(new RpcChannel),
                               user_stub_(new RpcChannel),
                               offline_stub_(new RpcChannel),
                               group_stub_(new RpcChannel)
{
    msg_handler_map_.insert({"Login", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"Regist", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"LoginOut", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"AddFriend", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"DelteFriend", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"GetUserInfo", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"GetFriendList", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"ReadOfflineMsg", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"CreateGroup", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"QuitGroup", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"AddGroup", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"ConveyMsg", bind(&ProxyService::login, this, _1, _2, _3)});
    msg_handler_map_.insert({"ChatMsg", bind(&ProxyService::login, this, _1, _2, _3)});

    master_.start();
}

//登录
void ProxyService::login(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_UserService::LoginRequest login_request;
    login_request.ParseFromString(recv_buf);

    //执行
    ik_UserService::LoginReponse response;
    user_stub_.Login(nullptr, &login_request, &response, nullptr);

    //在redis上记录此用户
    RpcConfigure configure = RpcApplication::get_instance().get_configure();
    string ip = configure.find_load("server_ip");
    int port = atoi(configure.find_load("server_port").c_str());
    redis_client_.set_host(login_request.id(), ip + ":" + to_string(port));

    //添加此用户到user map表中
    {
        lock_guard<mutex> lock(mutex_);
        use_connection_map_.insert({login_request.id(), conn});
    }

    //序列化并发送
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//注册
void ProxyService::regist(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_UserService::RegisterRequest regist_request;
    regist_request.ParseFromString(recv_buf);

    //执行
    ik_UserService::RegisterResponse response;
    user_stub_.Registe(nullptr, &regist_request, &response, nullptr);

    //序列化并发送
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//注销业务
void ProxyService::loginout(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_UserService::LoginOutRequest request;
    request.ParseFromString(recv_buf);

    //执行
    user_stub_.LoginOut(nullptr, &request, nullptr, nullptr);
}

//添加好友业务
void ProxyService::add_friend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_FriendService::AddFriendRequest request;
    request.ParseFromString(recv_buf);

    //执行
    RpcControl controller;
    google::protobuf::Empty em;
    friend_stub_.AddFriend(&controller, &request, &em, nullptr);

    //判断执行结果
    if (controller.Failed())
    {
        conn->send(controller.ErrorText());
    }
}

//删除好友
void ProxyService::delete_friend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_FriendService::DeleteFriendRequest request;
    request.ParseFromString(recv_buf);

    //执行
    RpcControl controller;
    google::protobuf::Empty em;
    friend_stub_.DeleteFriend(&controller, &request, &em, nullptr);

    //判断执行结果
    if (controller.Failed())
    {
        conn->send(controller.ErrorText());
    }
}

//获取用户信息
void ProxyService::get_userInfo(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_FriendService::UserInfoRequest request;
    request.ParseFromString(recv_buf);

    //执行
    ik_FriendService::UserInfoReponse response;
    friend_stub_.GetUserInfo(nullptr, &request, &response, nullptr);

    //序列化并返回结果
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//获取好友列表
void ProxyService::get_friendList(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_FriendService::FriendListRequest request;
    request.ParseFromString(recv_buf);

    //执行
    ik_FriendService::FriendListResponse response;
    friend_stub_.GetFriendList(nullptr, &request, &response, nullptr);

    //序列化并返回结果
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//读取离线消息
void ProxyService::read_offlineMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_OfflineService::ReadOfflineRequest request;
    request.ParseFromString(recv_buf);

    //执行
    ik_OfflineService::ReadOfflineResponse response;
    offline_stub_.ReadOffline(nullptr, &request, &response, nullptr);

    //序列化并返回结果
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//创建 群组
void ProxyService::create_group(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_GroupService::CreateGroupRequest request;
    request.ParseFromString(recv_buf);

    //执行
    RpcControl controller;
    ik_GroupService::CreateGroupResponse response;
    group_stub_.CreateGroup(&controller, &request, &response, nullptr);

    //序列化
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//加入群组
void ProxyService::add_group(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_GroupService::AddGroupRequest request;
    request.ParseFromString(recv_buf);

    //执行
    RpcControl controller;
    google::protobuf::Empty em;
    group_stub_.AddGroup(&controller, &request, &em, nullptr);

    //判断执行结果
    if (controller.Failed())
    {
        conn->send(controller.ErrorText());
    }
}

//退出群
void ProxyService::quit_group(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_GroupService::QuitGroupRequest request;
    request.ParseFromString(recv_buf);

    //执行
    RpcControl controller;
    google::protobuf::Empty em;
    group_stub_.QuitGroup(&controller, &request, &em, nullptr);

    //判断执行结果
    if (controller.Failed())
    {
        conn->send(controller.ErrorText());
    }
}

//获得群用户信息
void ProxyService::get_groupUsers(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_GroupService::GetGroupUsersRequest request;
    request.ParseFromString(recv_buf);

    //执行
    RpcControl controller;
    ik_GroupService::GetGroupUsersResponse response;
    group_stub_.GetGroupUsers(&controller, &request, &response, nullptr);

    //序列化
    string send_str = response.SerializeAsString();
    conn->send(send_str);
}

//转发而来的消息
void ProxyService::convey_msg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_ChatServer::MsgRequest request;
    request.ParseFromString(recv_buf);

    ik_Proxy::PoxryResponse response;
    response.set_type("ChatMsg");
    response.set_response_msg(request.msg());

    int id = request.id();
    {
        lock_guard<mutex> lock(mutex_);
        auto it = use_connection_map_.find(id);
        muduo::net::TcpConnectionPtr client_conn = it->second;
        client_conn->send(response.SerializeAsString());
    }
}

//聊天消息
void ProxyService::chat_msg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_ChatServer::MsgRequest request;
    request.ParseFromString(recv_buf);

    int id = request.id();
    auto it = use_connection_map_.find(id);
    //不在此服务器上
    if (it == use_connection_map_.end())
    {
        //刷新服务器连接
        master_.get_follow();
        //获取一个与转发服务器交互的可以连接
        int client_fd;
        while ((client_fd == master_.get_service()) == -1)
        {
            master_.get_follow();
            sleep(1);
        }

        send(client_fd, recv_buf.c_str(), recv_buf.size(), 0);
    }
    else
    {
        it->second->send(recv_buf);
    }
}

//获得消息对应的处理器
MsgHandler ProxyService::get_handler(string msg_type)
{
    //记录错误日志，msgid没有对应的事件处理回调
    auto it = msg_handler_map_.find(msg_type);
    //如果没有对应的msgid
    if (it == msg_handler_map_.end())
    {
        //返回一个默认处理器，打印错误日志
        ik::LogRequest request;
        request.set_name("ProxyService");
        request.set_msg("have this service: " + msg_type);
        google::protobuf::Empty em;
        log_stub_.Log_ERROR(nullptr, &request, &em, nullptr);

        return [=](const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time) {
        };
    }
    else
    {
        return msg_handler_map_[msg_type];
    }
}

//处理客户端异常退出
void ProxyService::client_close_exception(const muduo::net::TcpConnectionPtr &conn)
{
    //1.删除user_map    2.用户改为offline   3.线程安全 4.删除redis上的信息
    {
        lock_guard<mutex> lock(mutex_);
        for (auto it = use_connection_map_.begin(); it != use_connection_map_.end(); it++)
        {
            if (it->second == conn)
            {
                redis_client_.del_host(it->first);
                it = use_connection_map_.erase(it);
                break;
            }
        }
    }
}

//服务器异常，业务重置
void ProxyService::reset()
{
    //序列化客户端收到的语句
    ik_Proxy::PoxryResponse response;
    response.set_type("LoginOut");
    response.set_response_msg("server crash");
    string send_str = response.SerializeAsString();

    {
        lock_guard<mutex> lock(mutex_);
        //重置所有用户为下线状态
        ik_UserService::LoginOutRequest request;
        for (auto it = use_connection_map_.begin(); it != use_connection_map_.end(); it++)
        {
            request.set_id(it->first);

            //在redis上删除用户
            redis_client_.del_host(it->first);

            google::protobuf::Empty em;
            user_stub_.LoginOut(nullptr, &request, &em, nullptr);

            it->second->send(send_str);
        }
    }
    //清空map
    use_connection_map_.clear();
}
