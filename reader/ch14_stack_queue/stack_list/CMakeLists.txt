cmake_minimum_required(VERSION 3.3)
project(stack_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Stack.h)
add_executable(stack_list ${SOURCE_FILES})