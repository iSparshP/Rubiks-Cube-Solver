//
// Created by Sparsh Prakash on 03/11/23.
//


#ifndef RUBIKS_CUBE_SOLVER_CORNERPATTERNDATABASE_H
#define RUBIKS_CUBE_SOLVER_CORNERPATTERNDATABASE_H

#include "../Prototype/RubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef RubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;

};

#endif //RUBIKS_CUBE_SOLVER_CORNERPATTERNDATABASE_H
