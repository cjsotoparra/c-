cmake_minimum_required(VERSION 3.13)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

# Change this path to wherever you have catch.hpp.
include_directories(../CLion)

add_executable(demo GameOfLife.cpp catch-main.cpp)
