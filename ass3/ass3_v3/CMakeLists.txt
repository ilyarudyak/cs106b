cmake_minimum_required(VERSION 3.5)
project(ass3_v3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ListMnemonics.h Measurer.h)
add_executable(ass3_v3 ${SOURCE_FILES})