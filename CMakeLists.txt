cmake_minimum_required(VERSION 3.28)
project(solving_equations)

set(CMAKE_CXX_STANDARD 26)

include_directories(.)

add_executable(solving_equations
        main.cpp
        HalfDivide-solving-equations.cpp
        HalfDivide-solving-equations.h
        equations.cpp
        equations.h
        Secant_method-solving-equations.cpp
        Secant_method-solving-equations.h
        Newton-sloving-equations.cpp
        Newton-sloving-equations.h
)
