cmake_minimum_required(VERSION 3.13)
project(PokerHand)

set(CMAKE_CXX_STANDARD 14)

# Change this path to wherever you have the file 'catch.hpp'
include_directories(../CLion)

# Using this add_execuatable with the two line file
# catch-main.cpp to prevent catch.hpp compiling
# with any change made to CardTest.cpp
add_executable(Poker 52Cards.hpp Card.cpp PokerHand.hpp PokerHandTest.cpp catch-main.cpp)

