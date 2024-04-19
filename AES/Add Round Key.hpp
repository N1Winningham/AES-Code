//
// Created by Nathan Winningham on 3/10/24.
//

//Includes pseudocode for future implementation.


#include <iostream>
#include "Substitute Bytes.hpp"
using namespace std;

#ifndef AES_KEY_SCHEDULE_HPP
#define AES_KEY_SCHEDULE_HPP

class addRoundKey{
public:

    SubBytes subB;

    //Rotate for the key expansion.
    void rotateKey(unsigned char *column) {
        int cTemp = column[0];
        column[0] = column[1];
        column[1] = column[2];
        column[2] = column[3];
        column[3] = cTemp;
    }

    //Generates the fully expanded key.
    unsigned char generateFullKey(unsigned char* originalKey, unsigned char fullKey[4][60]) {
        //Fills the first four-by-four of the full key with the original key.
        for (int i=0; i<16; i++) {
            fullKey[i/4][i%4] = originalKey[i]; //Fills top to bottom, then left to right.
        }

        //Creates a temporary one-by-four colum used to fill the next column in the full key.
        unsigned char temp[4];

        //Fills in the rest of the full key.
        for (int i=4; i<60; i++) {
            //Copies the full key column into the temp.
            for (int j=0; j<4; j++) {
                temp[j] = fullKey[j][i-1];
            }

            //Applies the rotate, subBytes, and rcon steps if the round is creating a new round key matrix.
            if (i%4 == 0) {
                rotateKey(temp);
                subB.SBoxKey(temp);
                temp[0] = temp[0] ^ rcon[i/4-1][0];
            }

            //XORs the temp column with the full key value with the column that is four to the left of the newly inserted
            // column.
            for (int j=0; j<4; j++) {
                fullKey[j][i] = fullKey[j][i-4] ^ temp[j];
            }
        }
        return fullKey[0][0];
    }

    //Declaring all the individual round key matrices.
    unsigned char InitialRoundKey[16];
    unsigned char RoundKey1[16];
    unsigned char RoundKey2[16];
    unsigned char RoundKey3[16];
    unsigned char RoundKey4[16];
    unsigned char RoundKey5[16];
    unsigned char RoundKey6[16];
    unsigned char RoundKey7[16];
    unsigned char RoundKey8[16];
    unsigned char RoundKey9[16];
    unsigned char RoundKey10[16];

    //For AES-192.
//    unsigned char InitialRoundKey[24];
//    unsigned char RoundKey1[24];
//    unsigned char RoundKey2[24];
//    unsigned char RoundKey3[24];
//    unsigned char RoundKey4[24];
//    unsigned char RoundKey5[24];
//    unsigned char RoundKey6[24];
//    unsigned char RoundKey7[24];
//    unsigned char RoundKey8[24];
//    unsigned char RoundKey9[24];
//    unsigned char RoundKey10[24];
//    unsigned char RoundKey11[24];
//    unsigned char RoundKey12[24];

    //For AES-256
//    unsigned char InitialRoundKey[32];
//    unsigned char RoundKey1[32];
//    unsigned char RoundKey2[32];
//    unsigned char RoundKey3[32];
//    unsigned char RoundKey4[32];
//    unsigned char RoundKey5[32];
//    unsigned char RoundKey6[32];
//    unsigned char RoundKey7[32];
//    unsigned char RoundKey8[32];
//    unsigned char RoundKey9[32];
//    unsigned char RoundKey10[32];
//    unsigned char RoundKey11[32];
//    unsigned char RoundKey12[32];
//    unsigned char RoundKey13[32];
//    unsigned char RoundKey14[32];

    //Function used to break up the full key.
    void roundKeyBreak(unsigned char fullKey[4][60],unsigned char * roundKey, int startColumn) {
        int index = 0;
        for (int col = 0; col < 4; col++) {
            for (int row = 0; row < 4; row++) {
                roundKey[col + row * 4] = fullKey[row][startColumn + col];
            }
        }
    }


    //Array of arrays which stand for the rows of the rcon table.
    const unsigned char rcon[14][4] = {
            {0x01, 0x00, 0x00, 0x00},
            {0x02, 0x00, 0x00, 0x00},
            {0x04, 0x00, 0x00, 0x00},
            {0x08, 0x00, 0x00, 0x00},
            {0x10, 0x00, 0x00, 0x00},
            {0x20, 0x00, 0x00, 0x00},
            {0x40, 0x00, 0x00, 0x00},
            {0x80, 0x00, 0x00, 0x00},
            {0x1b, 0x00, 0x00, 0x00},
            {0x36, 0x00, 0x00, 0x00},
            //For AES-192 and AES-256.
//            {0x6c, 0x00, 0x00, 0x00},
//            {0xd8, 0x00, 0x00, 0x00},
//            {0xab, 0x00, 0x00, 0x00},
//            {0x4d, 0x00, 0x00, 0x00}
    };
};


#endif //AES_ADD_ROUND_KEY_HPP
