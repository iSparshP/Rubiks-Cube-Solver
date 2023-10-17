//
// Created by Sparsh Prakash on 17/10/23.
//

#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
private:
    void rotateFace(int index) {
        char temp_arr[3][3] = {};
        for (int i = 0; i <3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[index][i][j];
            }
        }
        for (int i = 0; i <3; i++) { cube[index][0][i] = temp_arr[2-i][0];}
    }
};