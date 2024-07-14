cmake_minimum_required(VERSION 3.27)
project(ws8)

set(CMAKE_CXX_STANDARD 14)

add_executable(ws8
        lab/main.cpp
        lab/Shape.h
        lab/Shape.cpp
        lab/LblShape.cpp
        lab/LblShape.h
        lab/Line.cpp
        lab/Line.h
        lab/Rectangle.cpp
        lab/Rectangle.h)
