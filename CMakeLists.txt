cmake_minimum_required(VERSION 3.12)
project(practice)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_INCLUDE_DIR})

file(GLOB_RECURSE SOURCE "src/*.cpp")

add_subdirectory(boost_tests)

add_executable(test main.cpp ${SOURCE} include/hackerrank.h)