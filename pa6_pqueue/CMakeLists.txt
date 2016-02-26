cmake_minimum_required(VERSION 3.3)
project(pa6_pqueue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pqueue_vector/PQueueVect.cpp pqueue_vector/PQueueVect.h pqueue_list/LinkedList.cpp pqueue_list/LinkedList.h pqueue_list/PQueueList.cpp pqueue_list/PQueueList.h)
add_executable(pa6_pqueue ${SOURCE_FILES})