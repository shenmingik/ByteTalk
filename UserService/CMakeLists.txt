# 设置最小支持版本号
cmake_minimum_required(VERSION 3.0)
project(UserServer)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置搜索头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/auxiliary_process/UserService_Sub/include)

# 加载子目录
add_subdirectory(src)
add_subdirectory(auxiliary_process)
add_subdirectory(example)
