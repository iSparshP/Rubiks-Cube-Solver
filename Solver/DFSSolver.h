// The following code defines a class named 'DFSSolver' that is designed to solve a Rubik's Cube using Depth-First Search (DFS).

// Created by Sparsh Prakash on 29/10/23.

#include "bits/stdc++.h"
#include "../Prototype/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Define a template class DFSSolver with two template parameters CubeType and DepthType.
template<typename CubeType, typename DepthType>
class DFSSolver {
private:
    vector<RubiksCube::MOVE> solutionMoves; // A vector to store the Rubik's Cube moves to solve it.
    int maxSearchDepth; // Maximum search depth for the DFS algorithm.

    // Recursive depth-first search function to solve the Rubik's Cube.
    bool dfs(int depth) {
        if (rubiksCube.isSolved()) return true; // Check if the cube is solved.
        if (depth > maxSearchDepth) return false; // Check if the maximum search depth is reached.

        // Iterate through all possible cube moves (18 in total).
        for (int move = 0; move < 18; move++) {
            rubiksCube.move(RubiksCube::MOVE(move)); // Apply a move to the cube.
            solutionMoves.push_back(RubiksCube::MOVE(move)); // Add the move to the list of moves.

            // Recursively continue the DFS search.
            if (dfs(depth + 1)) return true; // If the cube is solved, return true.

            solutionMoves.pop_back(); // If not solved, backtrack by removing the last move.
            rubiksCube.invert(RubiksCube::MOVE(move)); // Invert the move to restore the cube's state.
        }
        return false; // If no solution is found, return false.
    }

public:
    CubeType rubiksCube; // An instance of the Rubik's Cube.

    // Constructor for the DFSSolver class.
    DFSSolver(CubeType _rubiksCube, int _maxSearchDepth = 8) {
        rubiksCube = _rubiksCube; // Initialize the Rubik's Cube.
        maxSearchDepth = _maxSearchDepth; // Set the maximum search depth.
    }

    // Function to initiate solving the Rubik's Cube using DFS.
    vector<RubiksCube::MOVE> solve() {
        dfs(1); // Start the DFS search from a depth of 1.
        return solutionMoves; // Return the list of moves to solve the Rubik's Cube.
    }
};

#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H
