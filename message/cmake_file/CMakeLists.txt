cmake_minimum_required(VERSION 3.20)
project(auto_src_h)

set(INCLUDE_PATH "./include")
include_directories("./include")

#找到当前目录下源码 写入M_SRC中
aux_source_directory("." M_SRC)
aux_source_directory("./src" SRC)

file(GLOB HDRS ${INCLUDE_PATH}/*.h)

add_executable(${PROJECT_NAME} ${M_SRC} ${SRC} ${HDRS})