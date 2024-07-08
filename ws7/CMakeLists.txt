cmake_minimum_required(VERSION 3.27)
project(ws7)

set(CMAKE_CXX_STANDARD 11)

add_executable(ws7 main.cpp
        MotorVehicle.cpp
        MotorVehicle.h
        Truck.cpp
        Truck.h)
