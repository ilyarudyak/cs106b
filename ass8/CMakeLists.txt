cmake_minimum_required(VERSION 3.5)
project(ass8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BST.h QueueWithArray.h)
add_executable(ass8 ${SOURCE_FILES})