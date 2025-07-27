cmake_minimum_required(VERSION 3.20)
project(test_xlog)

include_directories(../xlog)

file(GLOB HSRC *.cpp *.cc)
file(GLOB HDRS *.hpp *.h)

add_executable(${PROJECT_NAME} ${HSRC} ${HDRS})

target_link_libraries(${PROJECT_NAME} xlog)