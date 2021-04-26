aux_source_directory(. SRC_LIST)

add_executable(FriendServer ${SRC_LIST})

target_link_libraries(FriendServer protobuf rpc muduo_base muduo_net pthread zookeeper_mt Pool mysqlclient)
