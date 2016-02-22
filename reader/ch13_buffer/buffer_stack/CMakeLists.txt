cmake_minimum_required(VERSION 3.3)
project(buffer_stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SimpleTextEditor.cpp EditorBuffer.cpp EditorBuffer.h)
add_executable(buffer_stack ${SOURCE_FILES})