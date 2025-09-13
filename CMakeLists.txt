cmake_minimum_required(VERSION 4.0)
project(functiongraph)

set(CMAKE_CXX_STANDARD 20)

add_executable(functiongraph main.cpp
        graphfunctions.cpp
        graphfunctions.h
        graphvalues.h)
