cmake_minimum_required(VERSION 3.3)
project(pa6_pqueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PQueueVect.cpp PQueueVect.h)
add_executable(pa6_pqueue ${SOURCE_FILES})