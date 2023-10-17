//
// Created by Sparsh Prakash on 17/10/23.
//

#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube {
public:
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE{
        U, UPRIME, U2,
        L, LPRIME, L2,
        F, FPRIME, F2,
        R, RPRIME, R2,
        B, BPRIME, B2,
        D, DPRIME, D2,
    };

    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const=0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const=0;

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

    string getCornerColorString(uint8_t index) const;

    uint8_t getCornerIndex(uint8_t index) const;

    uint8_t getCornerOrientation(uint8_t index) const;

};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
