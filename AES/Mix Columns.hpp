//
// Created by Nathan Winningham on 3/10/24.
//

//Includes psuedocode for future implementation.

using namespace std;
#ifndef AES_MIX_COLUMNS_HPP
#define AES_MIX_COLUMNS_HPP
class MixColumns {
public:

    int GF2(int value) {    //Using the Ireducable Polynomial Theorem, GF(2^3) for values two times the hex value
        if (value >= (1 << 8)) {
            value -= (1 << 8);  //removes the s^8;
            value ^= (1 << 4) | (1 << 3) | (1 << 1) | (1 << 0); //XORS 2^4, 2^3, 2^1, 2^0.
        }
        return value;
    }

    int GF3(int value) {
        //Multiplying the value by 3.
        int originalValue = value;  //Saves the value for later.
        int leftShiftedValue = value << 1;  //Shifts the value to the left by one bit.

        //When the value is larger than 256 (2^8) it replaces it with 2^4, 2^3, 2^1 and 2^0 and XORs those values with the
        //current value.
        while (leftShiftedValue >= (1 << 8)) {
            leftShiftedValue -= (1 << 8);  //removes the s^8;
            leftShiftedValue ^= (1 << 4) | (1 << 3) | (1 << 1) | (1 << 0); //XORS 2^4, 2^3, 2^1, 2^0.
        }

        //XORs the left-shifted value with the original value.
        value = leftShiftedValue ^ originalValue;

        return value;
    }

//Uses the Rijndael Mix Columns matrix to multiply the state matrix
    unsigned char temp[16];
    unsigned char mix(unsigned char state[16]) {
        temp[0] = GF2(2 * state[0]) ^ GF3(state[4]) ^ state[8] ^ state[12];
        temp[4] = state[0] ^ GF2(2 * state[4]) ^ GF3(state[8]) ^ state[12];
        temp[8] = state[0] ^ state[4] ^ GF2(2 * state[8]) ^ GF3(state[12]);
        temp[12] = GF3(state[0]) ^ state[4] ^ state[8] ^ GF2(2 * state[12]);
        temp[1] = GF2(2 * state[1]) ^ GF3(state[5]) ^ state[9] ^ state[13];
        temp[5] = state[1] ^ GF2(2 * state[5]) ^ GF3(state[9]) ^ state[13];
        temp[9] = state[1] ^ state[5] ^ GF2(2 * state[9]) ^ GF3(state[13]);
        temp[13] = GF3(state[1]) ^ state[5] ^ state[9] ^ GF2(2 * state[13]);
        temp[2] = GF2(2 * state[2]) ^ GF3(state[6]) ^ state[10] ^ state[14];
        temp[6] = state[2] ^ GF2(2 * state[6]) ^ GF3(state[10]) ^ state[14];
        temp[10] = state[2] ^ state[6] ^ GF2(2 * state[10]) ^ GF3(state[14]);
        temp[14] = GF3(state[2]) ^ state[6] ^ state[10] ^ GF2(2 * state[14]);
        temp[3] = GF2(2 * state[3]) ^ GF3(state[7]) ^ state[11] ^ state[15];
        temp[7] = state[3] ^ GF2(2 * state[7]) ^ GF3(state[11]) ^ state[15];
        temp[11] = state[3] ^ state[7] ^ GF2(2 * state[11]) ^ GF3(state[15]);
        temp[15] = GF3(state[3]) ^ state[7] ^ state[11] ^ GF2(2 * state[15]);
        //Would be more up to temp[32] for AES-192 and AES-256.

        return temp[0];
    }
};



#endif //AES_MIX_COLUMNS_HPP
