cmake_minimum_required(VERSION 3.9)
project(theintrosort)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        sortingalgo.cpp
        sortingalgo.h)

set(MAIN_FILES
        ${SOURCE_FILES}
        main.cpp)

set(TESTING_FILES
        ${SOURCE_FILES}
        test/catch.hpp test/test.cpp)

add_executable(theintrosort ${MAIN_FILES})
add_executable(tistest ${TESTING_FILES})