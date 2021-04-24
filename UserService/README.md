# 使用示例

直接加载配置文件 bin目录下
./UserServer -i user_server.conf    (UserServer 同理)
注意：需要先将LogServer 服务打开


# 开发信息
邮箱：2107810343@qq.com

时间：2021/4/18 22:55

开发环境：Ubuntu VS Code

编译器：g++

编程语言：C++

源码下载： [GitHub](https://github.com/shenmingik/ByteTalk/tree/main/UserService)

# 服务器设计思路
1. 整个服务器应该具有**高并发、高可用**的特点。
2. 服务器为了尽量保持一致性，并且由于登录、注册、注销等业务不属于高需求的业务，应直接与 mysql 交互，而不是 redis
3. 为了加快与 mysql 交互的效率，可用引进[数据库连接池（也是自己写的）](https://blog.csdn.net/shenmingxueIT/article/details/115025639?spm=1001.2014.3001.5501)
4. 为了保持对外接口一致性和便捷性，可用提供一个**抽象层**
5. 服务器与服务对象的通信协议采用 protobuf ，网络协议采用 TCP

# 服务器的设计
根据服务器的设计思路，我们可以向外提供一个**抽象节点 UserService**，所有关于登录、注册、注销的业务需求全都引向这里。而真正提供服务的是**服务节点 UserServer**，它负责与持久层的 mysql 进行交互，并且将自己的信息注册到zookeeper 集群上。**这个时候如果有需求到 UserService上，它的需求就会被UserService 从zookeeper 中拿出一个UserServer服务节点，向这个节点去分发需求**。实现了一个**反向代理的负载均衡**

# 服务节点：UserServer
## UserServer 的业务流向
UserServer 是整个服务集群中真正提供服务的节点。提供了**登录、注册、注销**三个功能。当一个业务请求通过 抽象节点 UserService分发到UserServer上的时候，它会先去反序列化请求，得到这个数据是请求哪个服务，然后根据请求类型，先去数据库连接池获得一个连接，然后去选择相应服务，并返回相应结果。
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021042422222292.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NoZW5taW5neHVlSVQ=,size_16,color_FFFFFF,t_70)
其对应的代码主要是在muduo库的messagecallback函数：

```cpp
//连接事件回调函数
void UserServer::msg_callback(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化由UserService传过来的序列化数据
    string message = buffer->retrieveAllAsString();
    ik_UserServer::Request request;
    request.ParseFromString(message);

    //登录业务
    if (request.type() == "Login")
    {
        // 反序列化数据得到 id、password
        ik_UserServer::LoginRequest login_request;
        login_request.ParseFromString(request.request());
        int id = login_request.id();
        string password = login_request.password();

        //执行具体的Login方法，执行成功is_success被设置为true
        ik_UserServer::LoginReponse login_response;
        if (Login(id, password) == true)
        {
            login_response.set_is_success(true);
        }
        else
        {
            login_response.set_is_success(false);
            ik_UserServer::ErrorMsg *msg = login_response.mutable_msg();
            msg->set_message("login error");
        }
        //序列化结果 并将结果返回
        string send = login_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "Register")  //注册业务
    {
        ik_UserServer::RegisterRequest register_request;
        register_request.ParseFromString(request.request());
        string name = register_request.name();
        string password = register_request.password();
        //cout<<name<<" "<<password<<endl;
        ik_UserServer::RegisterResponse register_response;
        int id = Register(name, password);
        if (id < 0)
        {
            register_response.set_is_success(false);
        }
        else
        {
            register_response.set_is_success(true);
            register_response.set_id(id);
        }
        string send = register_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "LoginOut")  //注销业务
    {
        ik_UserServer::LoginOutRequest out_request;
        out_request.ParseFromString(request.request());
        int id = out_request.id();

        LoginOut(id);
    }
    else //其他业务，这里是没有，所以向LogServer服务器打印一条日志信息
    {
        ik::LogRequest request;
        request.set_name("UserServer");
        string message = "UserServer:";
        message += ip_.c_str();
        message += " not have this service!";
        request.set_msg(message);
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}
```
## UserServer的大体设计
UserServer 大体上还是分为两层：**网络层**和**业务层**。网络层还是基于muduo网络库构建，通过那老一套的流程很快的搭建一个高性能的网络层。业务层则是首要的就是向zookeeper中去注册这个节点。一般是在`/UserService`目录下，以便抽象节点能够去发现服务。

> **注意：**
> 这个注册在zookeeper的节点应该是**临时节**点，**保证每个取得的节点都是可用的**。但是有个bug，zookeeper那边如果是上线基本秒更新，但是如果是下线一般会根据你设置的超时时间来判断，只有超过超时时间才判定这个节点下线了，但是如果超时时间过短，会造成频繁的与zookeeper-server连接。


![在这里插入图片描述](https://img-blog.csdnimg.cn/20210424224515122.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NoZW5taW5neHVlSVQ=,size_16,color_FFFFFF,t_70)
具体是在UserServer的构造函数和run方法中实现。

```cpp
UserServer::UserServer(string ip, int port) : stub_(new RpcChannel())
{
    ip_ = ip;
    port_ = port;
    pool_ = Connect_pool::get_instance();
    if (nullptr == pool_)
    {
        ik::LogRequest request;
        request.set_name("UserServer");
        request.set_msg("create mysql pool error");
        stub_.Log_ERROR(nullptr, &request, nullptr, nullptr);
    }
}

void UserServer::run()
{
    //初始化网络层
    muduo::net::InetAddress address(ip_.c_str(), port_);
    muduo::net::TcpServer server(&loop_, address, "UserServer");

    server.setMessageCallback(bind(&UserServer::msg_callback, this, _1, _2, _3));
    server.setConnectionCallback(bind(&UserServer::conn_callback, this, _1));

    //注册zookeeper节点
    ZKClient zk_client;
    zk_client.start();
    string server_path = "/UserService/server";
    char buffer[BUFF_SIZE] = {0};
    sprintf(buffer, "%s:%d", ip_.c_str(), port_);
    if (zk_client.create(server_path, buffer, strlen(buffer), ZOO_EPHEMERAL) == false)
    {
        ik::LogRequest request;
        string name = "UserServer ";
        name += buffer;
        request.set_name(name);
        request.set_msg("zookeeper connect error!");
        google::protobuf::Empty response;
        stub_.Log_ERROR(nullptr, &request, &response, nullptr);
    }
    else
    {
        ik::LogRequest request;
        string name = "UserServer ";
        name += buffer;
        request.set_name(name);
        request.set_msg("zookeeper connect!");
        google::protobuf::Empty response;
        stub_.Log_ERROR(nullptr, &request, &response, nullptr);
    }
    //开启事件循环
    server.setThreadNum(4);
    server.start();
    loop_.loop();
}
```
# 抽象节点：UserService
抽象节点[基于RPC框架](https://blog.csdn.net/shenmingxueIT/article/details/115773482?spm=1001.2014.3001.5501)，是整个ByteTalk 系统的提供服务的抽象节点，所有关于登录、注册、注销的业务需求都会在这里得到中转。可用看作是它管理了一群UserServer节点，每次都从这群节点冲抽取一个**可用的**，然后给它分派任务并等待它的返回结果。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210424225343717.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NoZW5taW5neHVlSVQ=,size_16,color_FFFFFF,t_70)
主要业务逻辑在各个RPC 方法中，拿一个 Login 出来看看：

```cpp
void UserService::Login(::google::protobuf::RpcController *controller,
                        const ::ik_UserService::LoginRequest *request,
                        ::ik_UserService::LoginReponse *response,
                        ::google::protobuf::Closure *done)
{
    master_.get_follow();
    ik_UserServer::Request login_request;
    login_request.set_type("Login");
    login_request.set_request(request->SerializeAsString());

    string send_str = login_request.SerializeAsString();
    //获取一个服务信息
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        //刷新服务列表
        master_.get_follow();
        sleep(1);
    }

    //发送信息
    send(client_fd, send_str.c_str(), send_str.size(), 0);

    //获取信息
    char recv_buf[BUFF_SIZE] = {0};
    recv(client_fd, recv_buf, BUFF_SIZE, 0);
    ik_UserServer::LoginReponse login_response;
    login_response.ParseFromString(recv_buf);
    response->set_is_success(login_response.is_success());

    close(client_fd);
    done->Run();
}
```
# 参考文献
	[1] 无
