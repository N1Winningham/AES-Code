//
// Created by Nathan Winningham on 3/10/24.
//

#include <iostream>

#ifndef AES_SHIFT_ROWS_HPP
#define AES_SHIFT_ROWS_HPP
class ShiftRows {
public:
    unsigned char shiftingTemp = 0x00;
    unsigned char shiftRow(unsigned char state[16], int row_num){
        //If it is the second row it shifts all the values so that the first value of the row is moved to the end and the
        //rest are shifted to the left one.
        if (row_num == 2){
            shiftingTemp = state[4];
            state[4] = state[5];
            state[5] = state[6];
            state[6] = state[7];
            state[7] = shiftingTemp;
            shiftingTemp = 0;

            //Swaps the first and third values of the row and the second and fourth of the row as well.
        } else if (row_num == 3){
            shiftingTemp = state[8];
            state[8] = state[10];
            state[10] = shiftingTemp;
            shiftingTemp = state[9];
            state[9] = state[11];
            state[11] = shiftingTemp;
            shiftingTemp = 0;

            //If it is the fourth row it shifts all the values so that the last value of the row is moved to the beginning and
            //the rest are shifted to the right one.
        } else if (row_num == 4){
            shiftingTemp = state[15];
            state[15] = state[14];
            state[14] = state[13];
            state[13] = state[12];
            state[12] = shiftingTemp;
            shiftingTemp = 0;
        }
        return state[0];
    }
};

#endif //AES_SHIFT_ROWS_HPP
