aux_source_directory(. SRC_LIST)

add_executable(ProxyServer ${SRC_LIST})

target_link_libraries(ProxyServer protobuf rpc zookeeper_mt muduo_net muduo_base pthread)