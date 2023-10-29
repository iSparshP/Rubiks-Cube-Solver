/**
 * @file RubiksCube.h
 * @brief Header file for the Rubik's Cube class.
 *
 * This header file defines the RubiksCube class, which represents a Rubik's Cube puzzle. It provides
 * various methods for manipulating and solving the cube, as well as accessing its state.
 *
 * @author Sparsh Prakash
 * @date 17/10/23
 */

#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube {
public:
    // Enums for cube faces, colors, and moves.

    /**
     * @enum FACE
     * Represents the faces of the Rubik's Cube.
     */
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    /**
     * @enum COLOR
     * Represents the colors of the Rubik's Cube.
     */
    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };


    /**
     * @enum MOVE
     * Represents the different moves that can be applied to the Rubik's Cube.
     */


    enum class MOVE{
        U, UPRIME, U2,
        L, LPRIME, L2,
        F, FPRIME, F2,
        R, RPRIME, R2,
        B, BPRIME, B2,
        D, DPRIME, D2,
    };


    /**
     * Get the color of a specific position on the cube.
     *
     * @param face The face of the cube.
     * @param row The row (0-2) on the face.
     * @param col The column (0-2) on the face.
     * @return The color of the specified position.
     */


    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const=0;

     /**
     * Get the character representation of a cube color.
     *
     * @param color The cube color.
     * @return The character representation of the color.
     */

    static char getColorLetter(COLOR color);

    /**
     * Check if the Rubik's Cube is solved.
     *
     * @return True if the cube is solved, false otherwise.
     */

    virtual bool isSolved() const=0;

    // Methods for cube manipulation and movements.

    // ... (other methods not documented for brevity)

    static string getMove(MOVE index);

    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);

    RubiksCube &move(MOVE index);

    RubiksCube &invert(MOVE index);

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;



    /**
     * Get the color string of a corner at a specific index.
     *
     * @param index The index of the corner.
     * @return The color string representing the corner.
     */

    string getCornerColorString(uint8_t index) const;

    /**
     * Get the index of a corner at a specific position.
     *
     * @param index The index of the corner.
     * @return The index of the corner at the specified position.
     */

    uint8_t getCornerIndex(uint8_t index) const;

    /**
     * Get the orientation of a corner at a specific index.
     *
     * @param ex The index of the corner.
     * @return The orientation of the corner at the specified index.
     */

    uint8_t getCornerOrientation(uint8_t ex) const;

};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
