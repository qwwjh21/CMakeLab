# message
#[[
message(arg1 arg2 arg3)
]]
cmake_minimum_required(VERSION 3.20)
project(message)
message("参数1") #测试message
message("参数1" " 参数p2" #[[注释在message中]] " p3"  123  测试)

#message 高级使用-指定日志级别

# 进程退出 生成退出
#message(FATAL_ERROR "TEST FATAL ERROR")

# 进程退出 生成退出 不会生成 add_executable add_library
#message(SEND_ERROR "TEST SEND ERROR")

add_executable(test_message main.cpp)

message("after FATAL_ERROR")

# WARNING 打印代码路径和行号
message(WARNING "TEST WARNING")

message("TEST none")
# NOTICE == none 就是不加 == message("TEST NOTICE")
message(NOTICE "TEST NOTICE")

# STATUS 加前缀 -- 用户可能感兴趣
message(STATUS "TEST STATUS")

# VERBOSE 默认不显示 用户需要的详细信息
message(VERBOSE "TEST VERBOSE")

# 设置日志显示级别
# cmake -S . -B build --log-level=VERBOSE

# 标准输出重定向
# cmake -S . -B build --log-level=VERBOSE > log.txt

# 标准错误输出重定向到标准输出
# cmake -S . -B build --log-level=VERBOSE > log.txt 2>&1

message(DEBUG "test DEBUG")

message(TRACE "test TRACE")

#[[
message Reporting checks 查找库日志
CHECK_START 开始记录将要执行检查的消息
CHECK_PASS 记录检查的成功结果
CHECK_FAIL 记录不成功的检查结果
]]

# 开始查找
message(CHECK_START "查找 xcpp")

#message消息缩进
set(CMAKE_MESSAGE_INDENT "--")
# 查找库的代码

# 嵌套查找
message(CHECK_START "查找 logger")
# 查找logger
message(CHECK_PASS "成功")

message(CHECK_START "查找threadPool")
message(CHECK_FAIL "失败")

#message 取消缩进
set(CMAKE_MESSAGE_INDENT )

# 结束查找 查找失败
message(CHECK_FAIL "失败")
