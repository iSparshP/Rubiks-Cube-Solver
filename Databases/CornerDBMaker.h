//
// Created by Sparsh Prakash on 04/11/23.
//


#ifndef RUBIKS_CUBE_SOLVER_CORNERDBMAKER_H
#define RUBIKS_CUBE_SOLVER_CORNERDBMAKER_H

#include "CornerPatternDatabase.h"
#include "../Prototype//RubiksCubeBitboard.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};


#endif //RUBIKS_CUBE_SOLVER_CORNERDBMAKER_H
