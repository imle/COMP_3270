cmake_minimum_required(VERSION 3.6)
project(COMP_3270)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/AbstractHeader.cpp src/AbstractHeader.h)
add_executable(COMP_3270 ${SOURCE_FILES})