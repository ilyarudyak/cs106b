cmake_minimum_required(VERSION 3.5)
project(pa4_boggle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pa4_boggle ${SOURCE_FILES})