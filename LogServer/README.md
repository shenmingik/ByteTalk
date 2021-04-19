@[toc]

邮箱：2107810343@qq.com

时间：2021/4/18 22:55

开发环境：Ubuntu VS Code

编译器：g++

编程语言：C++

源码下载： [GitHub](https://github.com/shenmingik/ByteTalk.git)

# 写在前面
根据**架构师修炼之道——思维、方法、实践**一书的第三章内容，再结合自身在开发上的一点经验，决定去开发这么一款分布式的日志服务器。也是去供我开发 ByteTalk 之用。

正好也用上自研的RPC框架，嘿嘿。

# 服务器设计思路
1. 日志分为 TRACE、DEBUG、INFO、WARN、ERROR、FATAL。但是秉着轻量的设计（懒），日志只提供==INFO、ERROR、FATAL==三种级别。
	1.1 **INFO**：记录程序的运行过程，粒度可能较粗
	1.2 **ERROR**：打印程序运行过程中的错误信息，需要添加行号，文件名等信息，方便定位
	1.3 **FATAL**：当程序遇到不可抗力，无法进行下去的时候，打印此信息。
2. 根据 [网上资料](https://blog.csdn.net/dao_wolf/article/details/76815340) 显示，对于日志服务器的需求，不用采用数据库，因为文件I/O可能会快一些，数据库还要涉及网络的时延问题。
3. 日志打印应该对不同的节点都建立一个文件夹，每个文件夹里面的文件记录该节点一天的信息。且里面格式应该固定：年：月：日==>[日志级别]+日志信息
4. 服务器的主要服务对象应有两个，一个是其他分布式节点，一个是开发客户端供开发人员去读取服务器里面的日志，因为服务问题，这两个其实应该设计为两个进程，一个是因为读取日志是耗时操作，不应阻塞写日志的过程，二是进程比线程更为健壮。
5. 日志的组织方式应该是`/log/节点名称/日期_log.txt`
6. 日志服务器对数据完整性要求不是很高，但是如果日志服务器宕机了，可以考虑添加主从复制与哨兵机制（暂时不考虑）
7. 服务器与服务对象的通信协议采用 protobuf ，网络协议采用  TCP

从设计思路来看，整个服务器的瓶颈限制应该是**网络I/O**，应配备高带宽的网络设备。

## protobuf 通信格式设计
按照我们我们刚刚的设计思路，我们对外通信需要两个通信协议。

**一个是对于其他分布式节点；
一个是对于客户端阅读日志文件；**

### 与其他分布式节点
与其他分布式节点交互主要就一个内容，**其他节点往日志服务器写日志**。当我们写日志的时候，我们需要**指定当前节点的名称以及对于的日志信息**，日志服务器就会在本地对于节点名路径下对于的日期 log.txt 文件中写入这条日志。

```java
/*
* 发送日志节点的名称
* msg：收到的参数
*/
message LogRequest
{
    bytes name = 1;
    bytes msg = 2;
}
```
而对于**日志函数**，设计的是无返回值：

```java
service LogServerRpc
{
    rpc  Log_INFO(LogRequest) returns(google.protobuf.Empty);
    rpc  Log_ERROR(LogRequest) returns(google.protobuf.Empty);
    rpc  Log_FATAL(LogRequest) returns(google.protobuf.Empty);
}
```

### 与客户端
与客户端交互则是客户端指定**节点名**和**时间**，服务端找到这个文件，将这个文件发送过去（注意由于网络问题，每个数据可能不是按序到达，所以需要指定序号，还需要有个标志标志你是否发送完了）

```java
syntax = "proto3";

package ik;

/*
* node_name: 要查询哪个节点的日志信息
* time：要查询哪一天的日志信息（格式：%4d-%2d-%2d）
*/
message LogSendRequest
{
    bytes node_name = 1;
    bytes time = 2;
}

message LogSendReponse
{
    int32 serial = 1;   //序号
    bool is_end = 2;    //是否结束了
    bytes msg = 3;      //消息
}
```
# 日志服务器运行思路（图解）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210419214025547.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NoZW5taW5neHVlSVQ=,size_16,color_FFFFFF,t_70)

# 参考文献
	[1] 无