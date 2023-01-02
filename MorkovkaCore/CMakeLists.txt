cmake_minimum_required(VERSION 3.16)
project("MorkovkaCore")

set(CMAKE_CXX_STANDARD 14)

add_library(MorkovkaCore STATIC src/ArrayList.cpp src/LinkedList.cpp)

target_include_directories(MorkovkaCore PUBLIC include)