
// Created by Sparsh Prakash on 29/10/23.

#include "bits/stdc++.h"
#include "../Prototype/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// Template Class: BFSSolver
// Typename CubeType: Represents the Rubik's Cube data structure (3D, 1D, Bitboard).
// Typename HashType: Represents the corresponding hash function for the cube's state.

template<typename CubeType, typename HashType>
class BFSSolver {
private:
    vector<RubiksCube::MOVE> solutionMoves; // A vector to store the Rubik's Cube moves to solve it.
    unordered_map<CubeType, bool, HashType> visited; // An unordered map to keep track of visited cube states.
    unordered_map<CubeType, RubiksCube::MOVE, HashType> moveDone; // An unordered map to store how each state was reached.

    // BFS (Breadth-First Search) algorithm to solve the Rubik's Cube.
    // Returns the solved state of the cube.
    CubeType bfs() {
        queue<CubeType> queue;
        queue.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!queue.empty()) {
            CubeType currentNode = queue.front();
            queue.pop();
            if (currentNode.isSolved()) {
                return currentNode;
            }
            for (int i = 0; i < 18; i++) {
                auto currentMove = RubiksCube::MOVE(i);
                currentNode.move(currentMove);
                if (!visited[currentNode]) {
                    visited[currentNode] = true;
                    moveDone[currentNode] = currentMove;
                    queue.push(currentNode);
                }
                currentNode.invert(currentMove);
            }
        }
        return rubiksCube;
    }

public:
    CubeType rubiksCube; // An instance of the Rubik's Cube.

    // Constructor for the BFSSolver class.
    BFSSolver(CubeType _rubiksCube) {
        rubiksCube = _rubiksCube; // Initialize the Rubik's Cube.
    }

    // Function to solve the Rubik's Cube using BFS and return the vector of moves performed.
    vector<RubiksCube::MOVE> solve() {
        CubeType solvedCube = bfs();
        assert(solvedCube.isSolved()); // Ensure the cube is solved.

        CubeType currentCube = solvedCube;
        while (!(currentCube == rubiksCube)) {
            RubiksCube::MOVE currentMove = moveDone[currentCube];
            solutionMoves.push_back(currentMove);
            currentCube.invert(currentMove);
        }
        rubiksCube = solvedCube;
        reverse(solutionMoves.begin(), solutionMoves.end()); // Reverse the order of moves.
        return solutionMoves; // Return the list of moves to solve the Rubik's Cube.
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H
