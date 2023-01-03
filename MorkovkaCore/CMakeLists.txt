cmake_minimum_required(VERSION 3.16)
project("MorkovkaCore")

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INCLUDE src/*.hpp include/MorkovkaCore/*.hpp)

add_library(MorkovkaCore STATIC "${SOURCES}" "${INCLUDE}")
target_include_directories(MorkovkaCore PRIVATE include)