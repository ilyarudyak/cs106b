cmake_minimum_required(VERSION 3.3)
project(maze)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Maze.cpp Maze.h Point.cpp Point.h Direction.cpp Direction.h)
add_executable(maze ${SOURCE_FILES})