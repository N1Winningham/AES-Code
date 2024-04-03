//
// Created by Nathan Winningham on 3/10/24.
//

//WIP, includes pseudocode.

#include <iostream>

#ifndef AES_SHIFT_ROWS_HPP
#define AES_SHIFT_ROWS_HPP

int shiftingTemp = 0;
void shiftRow(int row_num){
    //If it is the second row it shifts all the values so that the first value of the row is moved to the end and the
    //rest are shifted to the left one.
    if (row_num == 2){
        shiftingTemp = matrixValue[5];
        matrixValue[5] = matrixValue[6];
        matrixValue[6] = matrixValue[7];
        matrixValue[7] = matrixValue[8];
        matrixValue[8] = shiftingTemp;
        shiftingTemp = 0;

    //Swaps the first and third values of the row and the second and fourth of the row as well.
    } else if (row_num == 3){
        shiftingTemp = matrixValue[9];
        matrixValue[9] = matrixValue[11];
        matrixValue[11] = shiftingTemp;
        shiftingTemp = matrixValue[10];
        matrixValue[10] = matrixValue[12];
        matrixValue[12] = shiftingTemp;
        shiftingTemp = 0;

    //If it is the fourth row it shifts all the values so that the last value of the row is moved to the beginning and
    //the rest are shifted to the right one.
    } else if (row_num == 4){
        shiftingTemp = matrixValue[16];
        matrixValue[14] = matrixValue[13];
        matrixValue[15] = matrixValue[14];
        matrixValue[16] = matrixValue[15];
        matrixValue[13] = shiftingTemp;
        shiftingTemp = 0;
    }
}

#endif //AES_SHIFT_ROWS_HPP
