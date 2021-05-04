aux_source_directory(. SRC_LIST)
aux_source_directory(./proto PROTO_LIST)

add_executable(ProxyServer ${SRC_LIST} ${PROTO_LIST})

target_link_libraries(ProxyServer protobuf rpc zookeeper_mt hiredis muduo_net muduo_base pthread)