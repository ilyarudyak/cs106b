cmake_minimum_required(VERSION 3.5)
project(ass7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp StackWithVector.h RandomQueue.h Stack.h LinkedList.h)
add_executable(ass7 ${SOURCE_FILES})