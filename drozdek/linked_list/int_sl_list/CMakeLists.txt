cmake_minimum_required(VERSION 3.3)
project(int_sl_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h)
add_executable(int_sl_list ${SOURCE_FILES})