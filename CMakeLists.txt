cmake_minimum_required(VERSION 3.26)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubiks_Cube_Solver main.cpp
        Prototype/RubiksCube.h
        Prototype/RubiksCube.cpp
        Prototype/RubiksCube3dArray.cpp
        Prototype/RubiksCube1dArray.cpp
        Prototype/RubiksCubeBitboard.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h)
