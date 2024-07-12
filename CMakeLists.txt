cmake_minimum_required(VERSION 3.28)
project(solving_equations)

set(CMAKE_CXX_STANDARD 26)

include_directories(.)

add_executable(solving_equations
        main.cpp
        main.h
        solving-equations/HalfDivide.cpp
        solving-equations/HalfDivide.h
        solving-equations/Newton.cpp
        solving-equations/Newton.h
        solving-equations/Secant_method.cpp
        solving-equations/Secant_method.h
)
