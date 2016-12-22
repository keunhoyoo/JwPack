cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/sample")
add_definitions(-std=c++11)
add_definitions(-D__cplusplus=201103L)
add_subdirectory(src)
add_subdirectory(sample)


