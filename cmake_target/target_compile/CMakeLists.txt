cmake_minimum_required(VERSION 3.20)
project(compile_features)

file(WRITE main.cpp [=[
int main()
{
    return 0;
}
]=]
)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

#支持的特征数组
message(CMAKE_CXX_COMPILE_FEATURES=${CMAKE_CXX_COMPILE_FEATURES})

foreach(var in LISTS ${CMAKE_CXX_COMPILE_FEATURES})
    message(${var})
endforeach()

# 判断当前编译器是否支持此特性
set(f1 cxx_std_23)
if(f1 IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message(${f1} OK)
    target_compile_features(main PRIVATE cxx_std_23)
else()
    message(${f1} FAILED)
endif()