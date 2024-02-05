cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework1) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # C++ version
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Homework1 main.cpp part1.cpp part1.h)