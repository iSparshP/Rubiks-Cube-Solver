//
// Created by Sparsh Prakash on 20/10/23.
//

#include "RubiksCube.h"

class RubiksCube1dArray : public RubiksCube {
private:
    // Static inline function to calculate the 1D array index from 3D coordinates
    static inline int getIndex(int index, int row, int col){
        return (index*9) + (row*3) + col;
    }

    // Function to rotate a single face of the cube
    void rotateFace(int index){
        // Store the current state of the face in a temporary array
        char temp_arr[9] ={};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp_arr[i * 3 + j] = cube[getIndex(index, i, j)];
            }
        }
        // Perform the face rotation by updating cube elements
        for (int i = 0; i < 3; ++i) { cube[getIndex(index,0,i)] = temp_arr[getIndex(0,2-i,0)];}
        for (int i = 0; i < 3; ++i) { cube[getIndex(index,i,2)] = temp_arr[getIndex(0,0,i)];}
        for (int i = 0; i < 3; ++i) { cube[getIndex(index,2,2-i)] = temp_arr[getIndex(0,i,2)];}
        for (int i = 0; i < 3; ++i) { cube[getIndex(index,2-i,0)] = temp_arr[getIndex(0,2,2-i)];}
    }

public:
    char cube[54]{};

    // Constructor for RubiksCube1dArray
    // Initializes the cube object with default colors
    RubiksCube1dArray(){
        // Initialize the cube's colors based on predefined constants
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cube[i * 9 + j * 3 + k] = getColorLetter(COLOR(i));
                }
            }
        }
    }


    // Implementation of the getColor method to retrieve the color of a face
    // at a specific position on the cube.
    COLOR getColor(FACE face, unsigned row, unsigned col) const override{
        char color = cube[getIndex((int)face, (int)row, (int)col)];
        // Map the character color to a COLOR enumeration
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }



    // Check if the cube is solved
    bool isSolved() const override{
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // Compare the current cube color with the expected color
                    if(this->cube[getIndex(i,j,k)] == getColorLetter(COLOR(i))) continue;
                    // If any element doesn't match, the cube is not solved
                    return false;
                }
            }
        }
        // All elements match the expected colors, the cube is solved
        return true;
    }



    // Implementations of cube rotation methods u, uPrime, u2, l, lPrime, l2, etc.
    RubiksCube &u() override{
        this->rotateFace(0);

        char temporary_array[] = {};
        for (int i = 0; i < 3; i++) {temporary_array[i] = cube[getIndex(4,0,2-i)];}
        for (int i = 0; i < 3; i++) {cube[getIndex(4,0,2-i)] = cube[getIndex(1,0,2-i)];}
        for (int i = 0; i < 3; i++) {cube[getIndex(1,0,2-i)] = cube[getIndex(2,0,2-i)];}
        for (int i = 0; i < 3; i++) {cube[getIndex(2,0,2-i)] = cube[getIndex(3,0,2-i)];}
        for (int i = 0; i < 3; i++) {cube[getIndex(3,0,2-i)] = temporary_array[i];}

        return *this;
    }

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }


    RubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }



    // Overloaded equality operator to compare two RubiksCube1dArray objects for equality.
    bool operator==(const RubiksCube1dArray &r1) const {
        for (int i = 0; i < 54; i++) {
            // Compare each element of the cubes for equality
            if (cube[i] != r1.cube[i]) return false;
        }
        // All elements match, the cubes are equal
        return true;
    }


    // Overloaded assignment operator to copy the state of another RubiksCube1dArray object.
    RubiksCube1dArray &operator=(const RubiksCube1dArray &r1) {
        for (int i = 0; i < 54; i++) {
            // Copy the state of each element from one cube to another
            cube[i] = r1.cube[i];
        }
        // Return the modified cube
        return *this;
    }

};


// Hash1d Function to generate a hash code for RubiksCube1dArray objects

struct Hash1d {
    size_t operator()(const RubiksCube1dArray &r1) const {
        string str = "";
        for (int i = 0; i < 54; i++) str += r1.cube[i];
        // Use the hash function to generate a hash code for the cube state
        return hash<string>()(str);
    }
};