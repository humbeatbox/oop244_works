cmake_minimum_required(VERSION 3.28)
project(ws10)

set(CMAKE_CXX_STANDARD 11)

add_executable(ws10 main.cpp
        ReadWrite.cpp
        Student.cpp
        Employee.cpp
        Car.cpp)
