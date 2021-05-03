#include "LogServer.pb.h"
#include "OfflineServer.pb.h"
#include "OfflineService.pb.h"

#include "ZooKeeperMaster.hpp"

#include <google/protobuf/service.h>
#include <rpc/RpcChannel.hpp>
#include <rpc/RpcControl.hpp>

#include <string>

using namespace std;
class OfflineService : public ik_OfflineService::OfflineServiceRpc
{
public:
    OfflineService();

public:
    void WriteOffline(::google::protobuf::RpcController *controller,
                      const ::ik_OfflineService::WriteOfflineRequest *request,
                      ::google::protobuf::Empty *response,
                      ::google::protobuf::Closure *done);
    void ReadOffline(::google::protobuf::RpcController *controller,
                     const ::ik_OfflineService::ReadOfflineRequest *request,
                     ::ik_OfflineService::ReadOfflineResponse *response,
                     ::google::protobuf::Closure *done);

private:
    ik::LogServerRpc_Stub stub_;

    ZKMatser master_;
};