cmake_minimum_required(VERSION 3.27)
project(ws2)

set(CMAKE_CXX_STANDARD 17)

add_executable(ws2 main.cpp
        File.cpp
        File.h
        Employee.cpp
        Employee.h)
