cmake_minimum_required(VERSION 3.3)
project(pa3_5_puzzle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pa3_5_puzzle ${SOURCE_FILES})