cmake_minimum_required(VERSION 3.10.2)
project(PiggyBank)
set(CMAKE_CXX_STANDARD 14)

# Change the path from /Users/mercer/CLionProjects to the path with catch.cpp
include_directories(../CLion)
include_directories(cmake-build-debug)

add_executable(demos main.cpp PiggyBank.cpp)
