//
// Created by Nathan Winningham on 3/10/24.
//
using namespace std;
#include <vector>
#ifndef AES_MIX_COLUMNS_HPP
#define AES_MIX_COLUMNS_HPP
vector<int> state = {};
vector<int> shiftRowsOutput;
state[1] = shiftRowsOutput[1];
int gFeildTemp = 7;
int currentRound,roundSize;

void mix(){
    while( currentRound != roundSize){
        S'[0,j] = (2*) ^ (3*) ^ _ ^ _
        S'[1,j] = _ ^ (2*) ^ (3*) ^ _
        S'[2,j] = _ ^ _ ^ (2*) ^ (3*)
        S'[3,j] = (3*) ^ _ ^ _ ^ (2*)

        for(int i=0;i<4;i++){
            for(int i=0;i<4;i++){
                binary(predefinedMatrix[i row]);
                binary(stateArray[j column]);
                for(int i=0;i<8;i++){
                    if(binaryValue[i] == 1){

                    }
                }
            }
        }
    }
}


#endif //AES_MIX_COLUMNS_HPP
