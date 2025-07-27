cmake_minimum_required(VERSION 3.20)
project(cmake_target_include)

# WRITE 写文件 清空原数据 如果文件不存在则创建
file(WRITE a.cpp [=[
#include<iostream>
void A()
{
    std::cout << A_VAR << std::endl;
}
]=]
)

add_library(A STATIC a.cpp)

# INCLUDE_DIRECTORIES 当前目标使用的属性
# INTERFACE_INCLUDE_DIRECTORIES 依赖当前目标使用的属性

# PUBLIC 改变 INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A PUBLIC "/A_PUBLIC")

# PRIVATE 改变 INCLUDE_DIRECTORIES
target_include_directories(A PRIVATE "/A_PRIVATE")

# INTERFACE 改变 INTERFACE_INCLUDE_DIRECTORIES
target_include_directories(A INTERFACE "/A_INTERFACE")

#设置A库的宏
target_compile_definitions(A PUBLIC A_VAR=123)

#打印属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS A PROPERTIES
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES
)

# B 依赖A
file(WRITE b.cpp [=[
#include <iostream>
void A();
void B(){
    A();
    std::cout << "In B" << A_VAR << std::endl;
}
]=]
)
add_library(B STATIC b.cpp)
target_link_libraries(B PUBLIC A)
target_include_directories(B PUBLIC "/B_PUBLIC")
target_compile_definitions(B INTERFACE STATIC=222)
# 没打印出继承的属性
include(CMakePrintHelpers)
cmake_print_properties(TARGETS B PROPERTIES
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES
)

#cmake 原生属性调试接口
#[[
set(CMAKE_DEBUG_TARGET_PROPERTIES
INCLUDE_DIRECTORIES
INTERFACE_INCLUDE_DIRECTORIES
)
]]
file(WRITE main.cpp [=[
#include<iostream>
int main()
{
    void B();
    B();
    std::cout << STATIC << std::endl;
    return 0;
}
]=]
)

# main 依赖 B
add_executable(main main.cpp)
target_link_libraries(main PUBLIC B)


