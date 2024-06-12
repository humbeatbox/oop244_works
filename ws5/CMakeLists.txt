cmake_minimum_required(VERSION 3.27)
project(ws5)

set(CMAKE_CXX_STANDARD 11)

add_executable(ws5 main.cpp
        Account.cpp
        Account.h)
