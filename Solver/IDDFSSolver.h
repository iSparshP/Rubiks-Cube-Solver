// The following code defines a class named 'IDDFSSolver' (Iterative Deepening Depth-First Search Solver)
// Created by Sparsh Prakash on 29/10/23.

#include "bits/stdc++.h"
#include "../Prototype/RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename CubeType, typename HashType>
class IDDFSSolver {

private:
    int maxDepth; // Maximum depth for iterative deepening.
    vector<RubiksCube::MOVE> solutionMoves; // A vector to store the Rubik's Cube moves.

public:
    CubeType rubiksCube; // An instance of the Rubik's Cube.

    // Constructor for the IDDFSSolver class.
    IDDFSSolver(CubeType _rubiksCube, int _maxDepth = 7) {
        rubiksCube = _rubiksCube; // Initialize the Rubik's Cube.
        maxDepth = _maxDepth; // Set the maximum search depth.
    }

    // Function to solve the Rubik's Cube using an iterative deepening DFS approach.
    vector<RubiksCube::MOVE> solve() {
        for (int depth = 1; depth <= maxDepth; depth++) {
            DFSSolver<CubeType, HashType> dfsSolver(rubiksCube, depth); // Use DFS Solver with increasing maxDepth.
            solutionMoves = dfsSolver.solve(); // Perform a DFS search with the current depth.
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube; // If solved, update the Rubik's Cube state.
                break;
            }
        }
        return solutionMoves; // Return the list of moves used to solve the Rubik's Cube.
    }
};

#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
