//
// Created by Nathan Winningham on 3/10/24.
//

//WIP, includes pseudocode and previous code.

#include <stdio.h>
#ifndef AES_SUBSTITUTE_BYTES_HPP
#define AES_SUBSTITUTE_BYTES_HPP

unsigned char vert,horz,matrix_value;
//void SBox() {
//        if(vert == '0'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == '1'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == '2'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == '3'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == '4'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == '5'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == '6'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == '7'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == '8'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == '9'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == 'a'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == 'b'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == 'c'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == 'd'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        } else if(vert == 'e'){
//            if (horz == '0') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == '1') {
//                vert = '7';
//                horz = 'c';
//            } else if (horz == '2') {
//                vert = '7';
//                horz = '7';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'b';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = '2';
//            } else if (horz == '5') {
//                vert = '6';
//                horz = 'b';
//            } else if (horz == '6') {
//                vert = '6';
//                horz = 'f';
//            } else if (horz == '7') {
//                vert = 'c';
//                horz = '5';
//            } else if (horz == '8') {
//                vert = '3';
//                horz = '0';
//            } else if (horz == '9') {
//                vert = '0';
//                horz = '1';
//            } else if (horz == 'a') {
//                vert = '6';
//                horz = '7';
//            } else if (horz == 'b') {
//                vert = '6';
//                horz = '3';
//            } else if (horz == 'c') {
//                vert = 'f';
//                horz = 'e';
//            } else if (horz == 'd') {
//                vert = 'd';
//                horz = '7';
//            } else if (horz == 'e') {
//                vert = 'a';
//                horz = 'b';
//            } else if (horz == 'f') {
//                vert = '7';
//                horz = '6';
//            }
//        } else if(vert == 'f'){
//            if (horz == '0') {
//                vert = 'c';
//                horz = 'a';
//            } else if (horz == '1') {
//                vert = '8';
//                horz = '2';
//            } else if (horz == '2') {
//                vert = 'c';
//                horz = '9';
//            } else if (horz == '3') {
//                vert = '7';
//                horz = 'd';
//            } else if (horz == '4') {
//                vert = 'f';
//                horz = 'a';
//            } else if (horz == '5') {
//                vert = '5';
//                horz = '9';
//            } else if (horz == '6') {
//                vert = '4';
//                horz = '7';
//            } else if (horz == '7') {
//                vert = 'f';
//                horz = '0';
//            } else if (horz == '8') {
//                vert = 'a';
//                horz = 'd';
//            } else if (horz == '9') {
//                vert = 'd';
//                horz = '4';
//            } else if (horz == 'a') {
//                vert = 'a';
//                horz = '2';
//            } else if (horz == 'b') {
//                vert = 'a';
//                horz = 'f';
//            } else if (horz == 'c') {
//                vert = '9';
//                horz = 'c';
//            } else if (horz == 'd') {
//                vert = 'a';
//                horz = '4';
//            } else if (horz == 'e') {
//                vert = '7';
//                horz = '2';
//            } else if (horz == 'f') {
//                vert = 'c';
//                horz = '0';
//            }
//        }
//};

//Creates the Rijndael S-Box.
unsigned char s_box[256] = {
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};

//Assigns new value after S-Box;
int SBox(unsigned char *byte) {
    *byte = s_box[*byte];
    return *byte;
}



#endif //AES_SUBSTITUTE_BYTES_HPP
