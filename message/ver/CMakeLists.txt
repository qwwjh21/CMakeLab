cmake_minimum_required(VERSION 3.20)
project(test_ver)
set(VER1 "设置变量VER1的值")

message(VER1=${VER1})
message("VER1 in string ${VER1}")

message("VER1 in string ${VER1}")

set(VER2 VER1)
message("VER2 = " ${VER2})
message("VER2 = " ${${VER2}})

unset(VER1)
message("VER1 in string ${VER1}")