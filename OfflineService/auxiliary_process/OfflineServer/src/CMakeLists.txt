aux_source_directory(. SRC_LIST)

add_executable(OfflineServer ${SRC_LIST})

target_link_libraries(OfflineServer protobuf rpc zookeeper_mt muduo_net muduo_base pthread Pool mysqlclient)