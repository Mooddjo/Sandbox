
cmake_minimum_required(VERSION 2.8)

project(sandbox_engine)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(sandbox_engine ${PROJECT_SOURCE_DIR}/test.cpp)