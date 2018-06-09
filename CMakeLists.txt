cmake_minimum_required(VERSION 3.10)
project(Wet2)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Werror -pedantic-errors")

set(SOURCE_FILES
        library2.h
        main2.cpp
        List.h HashTable.h)
add_executable(Wet2 ${SOURCE_FILES})