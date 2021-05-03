#include "OfflineService.hpp"

#define BUFF_SIZE 128

OfflineService::OfflineService() : stub_(new RpcChannel), master_("/OfflineService")
{
    master_.start();
}

void OfflineService::WriteOffline(::google::protobuf::RpcController *controller,
                                  const ::ik_OfflineService::WriteOfflineRequest *request,
                                  ::google::protobuf::Empty *response,
                                  ::google::protobuf::Closure *done)
{
    //刷新服务列表
    master_.get_follow();
    ik_OfflineServer::Request send_request;

    //重新序列化
    send_request.set_type("WriteOffline");
    send_request.set_request_msg(request->SerializeAsString());

    string send_str = send_request.SerializeAsString();
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("write-offline command send error");
        //打印错误信息
        ik::LogRequest log_request;
        log_request.set_name("OfflineService");
        log_request.set_msg("write-offline command send error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }
}
void OfflineService::ReadOffline(::google::protobuf::RpcController *controller,
                                 const ::ik_OfflineService::ReadOfflineRequest *request,
                                 ::ik_OfflineService::ReadOfflineResponse *response,
                                 ::google::protobuf::Closure *done)
{
    //刷新服务列表
    master_.get_follow();
    ik_OfflineServer::Request send_request;

    //重新序列化
    send_request.set_type("GetGroupUsers");
    send_request.set_request_msg(request->SerializeAsString());

    string send_str = send_request.SerializeAsString();
    int client_fd;
    while ((client_fd = master_.get_service()) == -1)
    {
        master_.get_follow();
        sleep(1);
    }

    if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("get offline msg command send error");
        //打印错误信息
        ik::LogRequest log_request;
        log_request.set_name("OfflineService");
        log_request.set_msg("get offline msg command send error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    char recv_buf[BUFF_SIZE] = {0};
    if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1)
    {
        //如果发生失败
        controller->SetFailed("get group users command recv error");
        //打印错误信息
        ik::LogRequest log_request;
        log_request.set_name("GroupService");
        log_request.set_msg("get group users command recv error");
        google::protobuf::Empty em;
        stub_.Log_ERROR(nullptr, &log_request, &em, nullptr);
    }

    response->ParseFromString(recv_buf);
}