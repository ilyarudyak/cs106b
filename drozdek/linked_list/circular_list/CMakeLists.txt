cmake_minimum_required(VERSION 3.3)
project(circular_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CircularList.cpp CircularList.h)
add_executable(circular_list ${SOURCE_FILES})