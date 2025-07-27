cmake_minimum_required(VERSION 3.20)
project(xlogg)

#设置.so库输出路径 默认路径在 -B build下
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

#执行程序输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

#归档输出路径 静态库 .lib 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

add_subdirectory(xlog)
add_subdirectory(test_xlog)