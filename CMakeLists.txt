cmake_minimum_required(VERSION 3.22)

SET(CMAKE_C_COMPILER mpicc)
SET(CMAKE_CXX_COMPILER mpicxx)

set(CMAKE_CXX_FLAGS "-O3 -Wextra -Wpedantic -Wconversion -Wcast-align")

set(CMAKE_CXX_STANDARD 14)

project(telescopic)

add_executable(telescopic
               ./src/functions.cpp
               ./src/telescopicProjective.cpp
               telescopic.cpp)
