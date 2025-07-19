cmake_minimum_required(VERSION 3.20)

project(test_logger)

# 添加头文件查找路径
include_directories("../logger") 

# 指定库文件查找路径
link_directories("../logger/build")

add_executable(test_logger test_logger.cpp)

#指定加载的库
target_link_libraries(test_logger Logger)