cmake_minimum_required(VERSION 3.8)
project(LastSAKODLAB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h Graph.cpp)
add_executable(LastSAKODLAB ${SOURCE_FILES})