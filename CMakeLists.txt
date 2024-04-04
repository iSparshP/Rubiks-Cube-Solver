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
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h
        Solver/IDAstarSolver.h
        Databases/PatternDatabase.h
        Databases/NibbleArray.h
        Databases/NibbleArray.cpp
        Databases/PatternDatabase.cpp
        Databases/CornerPatternDatabase.cpp
        Databases/CornerPatternDatabase.h
        Databases/PermutationIndexer.h
        Databases/math.cpp
        Databases/math.h
        Databases/CornerDBMaker.cpp
        Databases/CornerDBMaker.h)
