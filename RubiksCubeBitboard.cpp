//
// Created by Sparsh Prakash on 20/10/23.
//


#include "RubiksCube.h"

class RubiksCubeBitboard : public RubiksCube {
private:
    uint64_t solved_side_config[6]{};
    int arr[3][3]={{0,1,2},
                   {7,8,3},
                   {6,4,5}};

    uint64_t one_8 = (1 << 8) - 1, one_24 = (1 << 24) - 1;

    void rotateFace(int index) {
        uint64_t side = bitboard[index];
        side = side >> (8 * 6);
        bitboard[index] = (bitboard[index] << 16) | (side);
    }

    void rotateSide(int s1, int s1_1, int s1_2, int s1_3, int s2, int s2_1, int s2_2, int s2_3){
        uint64_t clr1 = (bitboard[s2] & (one_8 << (8 * s2_1))) >> (8 * s2_1);
        uint64_t clr2 = (bitboard[s2] & (one_8 << (8 * s2_2))) >> (8 * s2_2);
        uint64_t clr3 = (bitboard[s2] & (one_8 << (8 * s2_3))) >> (8 * s2_3);

        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_1))) | (clr1 << (8 * s1_1));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_1))) | (clr2 << (8 * s1_2));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_1))) | (clr3 << (8 * s1_3));
    }

    int get5bitCorner(string corner){
        int ret=0;
        string actual_str;
        for(auto c: corner){
            if(c != 'W' && c != 'Y') continue;
            actual_str.push_back(c);
            if(c == 'Y'){
                ret |= (1 << 2);
            }
        }

        for (auto c: corner) {
            if(c != 'B' && c != 'O') continue;
            if(c=='O'){
                ret |= (1<<1);
            }
        }

        for (auto c: corner) {
            if(c != 'B' && c != 'G') continue;
            if(c=='G'){
                ret |= (1<<0);
            }
        }

        if ( corner[1] == actual_str[0]){
            ret |= (1 << 3);
        } else if (corner[2] == actual_str[0])
        {
            ret |= (1 << 4);
        }
        return ret;
    }

public:
    uint64_t bitboard[6]{};

    RubiksCubeBitboard() {
        for (int side = 0; side < 6; ++side) {
            uint64_t clr = 1 << side;
            bitboard[side] =0;
            for (int faceIndex = 0; faceIndex < 8; ++faceIndex) {
                bitboard[side] |= clr << (8 * faceIndex);
            }
            solved_side_config[side] = bitboard[side];
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        int idx = arr[row][col];
        if (idx == 8) return (COLOR)((int) face);
        uint64_t side = bitboard[(int) face];
        uint64_t  color = (side >> (8 * idx)) & one_8;

        int bit_pos = 0;
        while (color != 0){
            color = color >>1;
            bit_pos++;
        }
        return (COLOR)(bit_pos -1);
    }

    bool isSolved() const override{
        for (int i = 0; i < 6; ++i) {
            if( solved_side_config[i] != bitboard[i]) return false;
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateFace(0);
        uint64_t temp = bitboard[2] & one_24;
        bitboard[2] = (bitboard[2] & ~one_24) | (bitboard[3] & ~one_24);
        bitboard[3] = (bitboard[3] & ~one_24) | (bitboard[4] & ~one_24);
        bitboard[4] = (bitboard[4] & ~one_24) | (bitboard[1] & ~one_24);
        bitboard[1] = (bitboard[1] & ~one_24) | temp;

        return *this;
    };

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    };

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    };

    RubiksCube &l() override {
        this->rotateFace(1);
        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 7))) >> (8 * 7);

        this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);

        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 7))) | (clr1 << (8 * 7));

        return *this;
    };

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    };

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    };

    RubiksCube &f() override {
        this->rotateFace(2);
        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(0, 4, 5, 6, 1, 2, 3, 4);
        this->rotateSide(1, 2, 3, 4, 5, 0, 1, 2);
        this->rotateSide(5, 0, 1, 2, 3, 6, 7, 0);

        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 7))) | (clr1 << (8 * 7));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));

        return *this;
    };

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    };

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    };


};