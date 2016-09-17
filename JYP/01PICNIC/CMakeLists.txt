cmake_minimum_required(VERSION 3.6)
project(01PICNIC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(01PICNIC ${SOURCE_FILES})