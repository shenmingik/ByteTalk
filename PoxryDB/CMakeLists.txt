# cmake 最小支持版本
cmake_minimum_required(VERSION 3.0)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置头文件搜错路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 加载子文件
add_subdirectory(src)