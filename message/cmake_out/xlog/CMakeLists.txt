cmake_minimum_required(VERSION 3.20)
project(xlog)

# 改变行为的变量 BUILD_SHARED_LIBS ON 动态库 OFF 静态库 默认静态库

#set(BUILD_SHARED_LIBS ON)
set(BUILD_SHARED_LIBS ON) #静态库

#cmake 传递变量给C++
add_definitions(-Dxlog_STATIC) #默认值1

file(GLOB HDRS *.h *.hpp)
file(GLOB HSRC *.cpp)

#描述系统的变量
message("MSVC" = ${MSVC})
message("WIN32" = ${WIN32})
message("UNIX" = ${UNIX})
message("CMAKE_SYSTEM_NAME" = ${CMAKE_SYSTEM_NAME})

# 控制构建过程的变量，输出路径控制 CMAKE_COLOR_MAKEFILE 是否生成makefile的颜色，默认是on
add_library(${PROJECT_NAME} ${HDRS} ${HSRC})