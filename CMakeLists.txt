cmake_minimum_required(VERSION 3.8)
project(distance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Distance.cpp Distance.h)
add_executable(distance ${SOURCE_FILES})