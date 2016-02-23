cmake_minimum_required(VERSION 3.3)
project(section_ass3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp list_mnemonics/ListMnemonics.cpp list_mnemonics/ListMnemonics.h measure/Measure.cpp measure/Measure.h)
add_executable(section_ass3 ${SOURCE_FILES})