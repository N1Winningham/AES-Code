//Used https://www.geeksforgeeks.org/iomanip-in-cpp/ to learn how to turn hexadecimal values from unsigned char using iomanip.
//Used https://www.geeksforgeeks.org/stringstream-c-applications/ to learn how to use string streams to easily output the hexadecimal values.
//Contains pseudocode for future implementation.
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include "Add Round Key.hpp"
#include "Mix Columns.hpp"
#include "Shift Rows.hpp"

int main() {
    int bitSize = 0;
    int roundSize = 0;
    string key;
    string inputText;
    int addSpaces = 0;
    int acc = 0;

    cout << "Throughout this experience you will learn the steps of AES-128 (Advanced Encryption Standard).\n"
            "The first thing we will need to know is what bit size you would like to choose.\n\n";
    //For AES-192 and AES-256, it would be the specified procedure, but the key size would be 24 bytes for AES-192
    // and 32 for AES-256.

    //Sets the bit size and the round size.
    while (bitSize != 128/* && bitSize != 192 && bitSize != 256*/) {
        cout << "Enter bit size (128, 192, or 256)[CAN ONLY WORK ON 128 CURRENTLY]: ";
        cin >> bitSize;

        if (bitSize != 128/* && bitSize != 192 && bitSize != 256*/) {
            cout << "Please input a correct value.\n";
        } else if (bitSize == 128) {
            roundSize = 10;
            cout << "This means that there are now " << roundSize << " rounds in our encryption\n\n";
        } else if (bitSize == 192) {
            roundSize = 12;
            cout << "This means that there are now " << roundSize << " rounds in our encryption\n\n";
        } else {
            roundSize = 14;
            cout << "This means that there are now " << roundSize << " rounds in our encryption\n\n";
        }
    }

    cin.ignore();   //Removes newline character allowing the user to enter the text they want encrypted.

    cout << "Now that we have the bit and round sizes, we will need some text to encrypt.\n";

    //Takes the text input that is to be encrypted.
    cout << "Enter the text you would like to have encrypted(For now a max of 16 characters):\n";
    getline(cin, inputText);

    //Makes sure the entered string is exactly 16 characters for AES-128.
    while (inputText.length() > 16) {
        cout << "\nThe phrase you entered is not 16 characters. Please try again.\n";
        getline(cin, inputText);
    }

    //Makes the text divisible by 16
    while (inputText.length() % 16 != 0) {
        inputText += '\0';
        addSpaces = 1;
    }

    //Declaring the two arrays and the lookup table.
    char stateArrayChar[16];
    string stateArray[16];
    unsigned char stateArrayASCII[16];
    map<int, string> lookupTable;

    //Takes the individual characters and puts them into an array.
    int w = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            stateArrayChar[w] = inputText[j * 4 + i];
            w++;
        }
    }
    w = 0;

    for (int i = 0; i < 16; i++) {
        stateArrayASCII[i] = (int) stateArrayChar[i];
    }

    //Converts the ASCII numbers into hexadecimal format using a lookup table.
    for (int i = 0; i < 16; i++) {
        stringstream ss;
        ss << setfill('0') << setw(2) << hex << (int) stateArrayChar[i];
        stateArray[i] = ss.str();
        lookupTable[(int) stateArrayChar[i]] = stateArray[i];
    }

    //Turns the decimal numbers of the characters into hexadecimal.
    for (int i = 0; i < 16; i++) {
        cout << '"' << char(stateArrayChar[i]) << '"' << " in hexadecimal is: " << stateArray[i];
        cout << "\n";
    }


    cout << "\nThe matrix in hexadecimal format would look like:\n\n";

    //Divides the values into four-by-four format.
    for (int i = 0; i < 16; i++) {
        cout << stateArray[i] << " ";
        if ((i + 1) % 4 == 0 && i != 0) {
            cout << "\n";
        }
    }

    //Checks to see if the program had to add spaces to make the block 16 bytes.
    if (addSpaces == 1) {
        cout
                << "\nDue to AES operating on 16 byte blocks, we have added spaces to the end of your string so that there will be "
                   "the correct amount of bytes for AES to occur.\n";
    }

    cout << "\nThis is called the 'state array.' It will undergo change throughout the process.\n";

    cout
            << "\nNow that we have our text, we need to establish a key.  The key is a 16 byte block. Our key will ensure only us and the people we"
               " want to share the data with have access.\nPlease enter an exactly 16 character phrase:\n";
    cout << "LLLLLLLLLLLLLLLL         <- Here is a 16 character measuring tool for you.\n";
    getline(cin, key);

    //Makes sure the entered string is exactly 16 characters.
    while (key.length() != 16) {
        cout << "\nThe phrase you entered is not 16 characters. Please try again.\n"
                "LLLLLLLLLLLLLLLL\n";
        getline(cin, key);
    }

    char keyArrayChar[16];
    string keyMatrix[4][4];
    unsigned char keyArrayASCII[16];

    //Takes the individual characters and puts them into a vector.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            keyArrayChar[w] = key[j * 4 + i];
            w++;
        }
    }

    //Converts the ASCII numbers into hexadecimal format using a lookup table.
    for (int i = 0; i < 16; i++) {
        keyArrayASCII[i] = (int) keyArrayChar[i];
    }

    //Converts the ASCII numbers into hexadecimal format using a lookup table.
    for (int j = 0; j < 16; j++) {
        stringstream ss;    //Declares a stringstream that allows to switch from numbers to letter and back easily.
        ss << setfill('0') << setw(2) << hex << (int) keyArrayChar[j]; //Ensures that the hexadecimal is exactly two digits.
        lookupTable[(int) keyArrayChar[j]] = ss.str();
        keyMatrix[j / 4][j % 4] = lookupTable[(int) keyArrayChar[j]];
    }

    //Prints out the hexadecimal version of the characters.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << '"' << char(keyArrayChar[acc]) << '"' << " in hexadecimal is: " << keyMatrix[i][j];
            cout << "\n";
            acc++;
        }
    }
    acc = 0;

    cout << "\nThe matrix in hexadecimal format would look like:\n\n";

    //Divides the values into four-by-four format.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << keyMatrix[i][j] << "  ";
            if ((j + 1) % 4 == 0 && j != 0) {
                cout << "\n";
            }
        }
    }

    cout << "\nNow that we have our key, we can expand the key to fit our " << roundSize << " rounds.\n";

    cout
            << "\nThe first step in expanding our round key is to take the current key we have right now and grab the last column. \nOnce we have the "
               "last column, we will then rotate the column (put the top value on the bottom and rotate the rest up.)\n";

    //Assigning the first column of the key to the visualization column.
    string visArrayOne[4];
    for (int i = 0; i < 4; i++) {
        visArrayOne[i] = keyMatrix[i][0];
    }
    //Assigning the last column of the key to the visualization column.
    string visArrayTwo[4];
    for (int i = 0; i < 4; i++) {
        visArrayTwo[i] = keyMatrix[i][3];
    }

    cout << "\nFirst column:        Fourth column:\n";
    for (int i = 0; i < 4; i++) {
        cout << visArrayOne[i] << "                   " << visArrayTwo[i] << '\n';
    }

    //Rotating the column.  (Also called RotWord).
    string visTemp;
    visTemp = visArrayTwo[0];
    visArrayTwo[0] = visArrayTwo[1];
    visArrayTwo[1] = visArrayTwo[2];
    visArrayTwo[2] = visArrayTwo[3];
    visArrayTwo[3] = visTemp;

    cout << "\n\nFourth column after rotation:\n";
    for (int i = 0; i < 4; i++) {
        cout << visArrayTwo[i] << '\n';
    }

    cout
            << "\nNow that we have rotated the column, we can substitute the bytes. This is done by taking each of the hexadecimal values and finding "
               "where they intersect in Rijndael's SBox to give a new value.\n";

    //Creating instances of each class.
    SubBytes SB;
    addRoundKey addRK;
    ShiftRows SR;
    MixColumns MC;

    //Creating a lookuptable for string to unsigned char.
    map<string, unsigned char> lookupTableTwo;

    //Assigning the int value to arrays for manipulation.
    unsigned char visArrayOneInt[4];
    for (int i = 0; i < 4; i++) {
        visArrayOneInt[i] = keyArrayASCII[4 * i];
    }
    unsigned char visArrayTwoInt[4];
    for (int i = 0; i < 4; i++) {
        visArrayTwoInt[i] = keyArrayASCII[i + (3 * (i + 1))];
    }

    //Rotating the int arrays.
    unsigned char vTemp;
    vTemp = visArrayTwoInt[0];
    visArrayTwoInt[0] = visArrayTwoInt[1];
    visArrayTwoInt[1] = visArrayTwoInt[2];
    visArrayTwoInt[2] = visArrayTwoInt[3];
    visArrayTwoInt[3] = vTemp;

    //Printing out the array in hexadecimal format.
    for (int i = 0; i < 4; i++) {
        visArrayTwoInt[i] = SB.s_box[visArrayTwoInt[i]];
        stringstream ss;
        ss << setfill('0') << setw(2) << hex << (int) visArrayTwoInt[i];
        cout << ss.str() << '\n';
    }

    unsigned char visCombinedArray[4];
    for (int i = 0; i < 4; i++) {
        visCombinedArray[i] = visArrayOneInt[i] ^ visArrayTwoInt[i];
    }

    cout
            << "\nNow that we have substituted the bytes, we create the first column for the first round key. To do this, we will start by XORing the "
               "column we just rotated and substituted with the first column of the round key.\n";

    cout
            << "\nFirst column:                            New fourth column:                                     New round key column:\n";
    for (int i = 0; i < 4; i++) {
        cout << visArrayOne[i] << "                  XOR                  ";
        stringstream ss;
        ss << setfill('0') << setw(2) << hex << (int) visArrayTwoInt[i];
        stringstream sst;
        sst << setfill('0') << setw(2) << hex << (int) visCombinedArray[i];
        cout << ss.str() << "                          =                          " << sst.str() << '\n';
    }

    cout << "\nNow, we will XOR the column that we just created with the first Rcon value.\n";

    cout
            << "\nNew round key column:                            First Rcon:                                      Final new round key column:\n";
    for (int i = 0; i < 4; i++) {
        stringstream sst;
        sst << setfill('0') << setw(2) << hex << (int) visCombinedArray[i];
        stringstream sstr;
        sstr << setfill('0') << setw(2) << hex << (int) addRK.rcon[0][i];
        cout << sst.str() << "                      XOR                      " << sstr.str()
             << "                       =                       ";
        visCombinedArray[i] = visCombinedArray[i] ^ addRK.rcon[0][i];
        stringstream sstri;
        sstri << setfill('0') << setw(2) << hex << (int) visCombinedArray[i];
        cout << sstri.str() << '\n';
    }

    cout << "\nNow that we are done, we can insert it into the first round key matrix.";

    unsigned char visFullKeyMatrix[4][60];
    int l = 0;

    //Adding the original key matrix to the full array;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            visFullKeyMatrix[i][j] = (unsigned char) (keyArrayASCII[l]);
            l++;
        }
    }

    //Adding the newly created column to the full array;
    for (int i = 0; i < 4; i++) {
        visFullKeyMatrix[i][4] = visCombinedArray[i];
    }

    //Filling in the rest of the values with 00;
    for (int i = 0; i < 4; i++) {
        for (int j = 5; j < 60; j++) {
            visFullKeyMatrix[i][j] = 0x00;
        }
    }

    //Displaying the current full array;
    cout
            << "\n                                                                                                                                         "
               "               |   Used for bit size 192   |   Used for bit size 256   |\n Original:      Round 1:      Round 2:      Round 3:      Round 4:"
               "      Round 5:      Round 6:      Round 7:      Round 8:      Round 9:     Round 10:  |  Round 11:     Round 12:  |  Round 13:     Round 14:"
               "  |\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 60; j++) {
            stringstream s;
            s << setfill('0') << setw(2) << hex << (int) visFullKeyMatrix[i][j];
            cout << s.str() << ' ';
            if ((j + 1) % 4 == 0) {
                cout << "| ";
            }
        }
        cout << '\n';
    }

    cout << "\nThis process will be repeated for remainder of the " << roundSize << " rounds.\n";




//    WAS INITIALLY GOING TO SHOW ALL OF THE COLUMNS BEING ADDED BUT DIDN'T HAVE THE TIME.
//
//
//    for(int roundNum=1; roundNum<roundSize;roundNum++){
//        cout << "\nThe next step in expanding our round key is to take the current key we have right now and grab the last column. \nOnce we have the "
//                "last column, we will then rotate the column (put the top value on the bottom and rotate the rest up.)\n";
//        for(int i=0;i<4;i++){
//            visArrayOne[i] = visFullKeyMatrix[i][roundNum];
//        }
//
//        for(int i=0;i<4;i++){
//            visArrayTwo[i] = visFullKeyMatrix[i][roundNum+3];
//        }
//
//        cout << "\n(i)th column:        (i+3)th column:\n";
//        for(int i=0;i<4;i++){
//            cout << visArrayOne[i] << "                   " << visArrayTwo[i] << '\n';
//        }
//
//        visTemp = visArrayTwo[0];
//        visArrayTwo[0] = visArrayTwo[1];
//        visArrayTwo[1] = visArrayTwo[2];
//        visArrayTwo[2] = visArrayTwo[3];
//        visArrayTwo[3] = visTemp;
//
//        cout << "\n\n(i+3)th column after rotation:\n";
//        for(int i=0;i<4;i++){
//            cout << visArrayTwo[i] << '\n';
//        }
//
//        cout << "\nNow that we have rotated the column, we can substitute the bytes.\n";
//
//        for (int i = 0; i < 4; i++) {
//            visArrayOneInt[i] = visFullKeyMatrix[4*i][roundNum];
//        }
//
//        for (int i = 0; i < 4; i++) {
//            visArrayTwoInt[i] = visFullKeyMatrix[i + (3*(i+1))][roundNum];
//        }
//
//        vTemp = visArrayTwoInt[0];
//        visArrayTwoInt[0] = visArrayTwoInt[1];
//        visArrayTwoInt[1] = visArrayTwoInt[2];
//        visArrayTwoInt[2] = visArrayTwoInt[3];
//        visArrayTwoInt[3] = vTemp;
//
//        for (int i = 0; i < 4; i++) {
//            visArrayTwoInt[i] = SB.s_box[visArrayTwoInt[i]];
//            stringstream ss;
//            ss << setfill('0') << setw(2) << hex << (int)visArrayTwoInt[i];
//            cout << ss.str() << '\n';
//        }
//
//        for(int i=0;i<4;i++){
//            visCombinedArray[i] = visArrayOneInt[i] ^ visArrayTwoInt[i];
//        }
//
//        cout << "\nNow that we have substituted the bytes, we create the next column for the round key. To do this, we will start by XORing the "
//                "column we just rotated and substituted with the (i)th column of the round key.\n";
//
//        cout << "\nFirst column:                            New fourth column:                                     New round key column:\n";
//        for (int i = 0; i < 4; i++) {
//            cout << visArrayOne[i] << "                  XOR                  ";
//            stringstream ss;
//            ss << setfill('0') << setw(2) << hex << (int)visArrayTwoInt[i];
//            stringstream sst;
//            sst << setfill('0') << setw(2) << hex << (int)visCombinedArray[i];
//            cout << ss.str() <<  "                          =                          " << sst.str() <<'\n';
//        }
//
//        cout << "\nNow, we will XOR the column that we just created with the first Rcon value.\n";
//
//        cout << "\nNew round key column:                            First Rcon:                                      Final new round key column:\n";
//        for (int i = 0; i < 4; i++) {
//            stringstream ss;
//            ss << setfill('0') << setw(2) << hex << (int)visCombinedArray[i];
//            stringstream sstr;
//            sstr << setfill('0') << setw(2) << hex << (int)addRK.rcon[0][i];
//            cout << ss.str() << "                      XOR                      " << sstr.str() << "                       =                       ";
//            stringstream sstri;
//            for(int i=0;i<4;i++){
//                visCombinedArray[i] = visArrayOneInt[i] ^ addRK.rcon[0][i];
//            }
//            sstri << setfill('0') << setw(2) << hex << (int)visCombinedArray[i];
//            cout << sstri.str() <<'\n';
//        }
//
//        cout << "\nNow that we are done, we can insert it into the first round key matrix.";
//
//        for(int i=0;i<4;i++){
//            visFullKeyMatrix[i][roundNum+4] = visCombinedArray[i];
//        }
//
//        cout << "\n                                                                                                                                         "
//                "               |   Used for bit size 192   |   Used for bit size 256   |\n Original:      Round 1:      Round 2:      Round 3:      Round 4:"
//                "      Round 5:      Round 6:      Round 7:      Round 8:      Round 9:     Round 10:  |  Round 11:     Round 12:  |  Round 13:     Round 14:"
//                "  |\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<60;j++){
//                stringstream s;
//                s << setfill('0') << setw(2) << hex << (int)visFullKeyMatrix[i][j];
//                cout << s.str() << ' ';
//                if((j+1) % 4 == 0){
//                    cout << "| ";
//                }
//            }
//            cout << '\n';
//        }
//
//    }


    //Generating the full key.
    unsigned char fullKey[4][60];
    addRK.generateFullKey(keyArrayASCII, fullKey);

    //Breaking the full key into individual round keys.
    addRK.roundKeyBreak(fullKey, addRK.InitialRoundKey, 0);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey1, 4);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey2, 8);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey3, 12);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey4, 16);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey5, 20);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey6, 24);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey7, 28);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey8, 32);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey9, 36);
    addRK.roundKeyBreak(fullKey, addRK.RoundKey10, 40);
    //For AES-192 and AES-256.
//    addRK.roundKeyBreak(fullKey, addRK.RoundKey11, 44);
//    addRK.roundKeyBreak(fullKey, addRK.RoundKey12, 48);
//    addRK.roundKeyBreak(fullKey, addRK.RoundKey13, 52);
//    addRK.roundKeyBreak(fullKey, addRK.RoundKey14, 56);

    //Printing the final full array.
    cout << "\nFinal full array:\n                                                                                                                                         "
            "               |   Used for bit size 192   |   Used for bit size 256   |\n Original:      Round 1:      Round 2:      Round 3:      Round 4:"
            "      Round 5:      Round 6:      Round 7:      Round 8:      Round 9:     Round 10:  |  Round 11:     Round 12:  |  Round 13:     Round 14:"
            "  |\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<60;j++){
            stringstream s;
            s << setfill('0') << setw(2) << hex << (int)fullKey[i][j];
            cout << s.str() << ' ';
            if((j+1) % 4 == 0){
                cout << "| ";
            }
        }
        cout << '\n';
    }

    cout << "\nNow that we have generated our round keys, we can take the initial round key and apply it to the state.\n";

    //Displaying the current state matrix.
    cout << "\nState matrix:\n";
    int p=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;
    //Displaying the initial key matrix.
    cout << "\nInitial key matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(addRK.InitialRoundKey[p]) << ' ';
            cout << ss.str();
            p++;
        }
        cout << '\n';
    }
    p=0;

    //XORing the state with the key.
    for(int i=0;i<16;i++){
        stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.InitialRoundKey[i];
    }

    //Displaying result.
    cout << "\nState after XORing with the initial key matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
            cout << ss.str();
            p++;
        }
        cout << '\n';
    }
    p=0;

    cout << "\nNow that we have applied the state to the initial round key, we can go through the main loop for AES. "
            "The main loop entails of using the subBytes step: \n";

    cout << "\nRound 1:\n";
    //Displaying the current state matrix.
    cout << "\nState matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    //Applying the SBox to the state.
    SB.SBoxState(stateArrayASCII);

    //Displaying result.
    cout << "\nState matrix after SBox:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;
    cout << "\nUsing the shiftRows step: \n";

    //Displaying the current state matrix.
    cout << "\nState matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    //Shifting all four columns of the array.
    //SR.shiftRow(1);   Does not shift anything since it is the first row.
    SR.shiftRow(stateArrayASCII, 2);
    SR.shiftRow(stateArrayASCII, 3);
    SR.shiftRow(stateArrayASCII, 4);

    //Displaying result.
    cout << "\nState matrix after shifting rows:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    cout << "\nUsing the mixColumns step: \n";

    //Displaying the current state matrix.
    cout << "\nState matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    //Mixing the columns (XORing the columns with the Rcon).
    MC.mix(stateArrayASCII);

    //Assigning the results of the mixColumn back to the state.
    for(int i=0;i<16;i++){
        stateArrayASCII[i] = MC.temp[i];
    }

    //Displaying result.
    cout << "\nState matrix after mixing columns:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    //Displaying the current state matrix.
    cout << "\nState matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    //Displaying the round key 1 matrix.
    cout << "\nRound 1 key matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey1[p]) << ' ';
            cout << ss.str();
            p++;
        }
        cout << '\n';
    }
    p=0;

    //XORing the state with the round key 1.
    for(int i=0;i<16;i++){
        stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey1[i];
    }

    //Displaying result.
    cout << "\nState after XORing with the round 1 key matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
            cout << ss.str();
            p++;
        }
        cout << '\n';
    }
    p=0;

    //Displaying the current state matrix.
    cout << "\nState matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    p=0;

    cout << "\n\n\n\n\nAnd finally, apply the round key and repeat for the " << roundSize << " rounds (Except for the last round.)\n";

    //Loop for remaining rounds.
    for(int roundCount=2;roundCount<roundSize;roundCount++){
        //Displaying the current state matrix.
        cout << "\nRound " << roundCount << ":\n";
        cout << "\nState matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        //SBoxing the state.
        SB.SBoxState(stateArrayASCII);

        //Displaying result.
        cout << "\nState matrix after SBox:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        cout << "\nUsing the shiftRows step: \n";

        //Displaying the current state matrix.
        cout << "\nState matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        //Shifting the rows.
        //SR.shiftRow(1);   Does not shift anything since it is the first row.
        SR.shiftRow(stateArrayASCII, 2);
        SR.shiftRow(stateArrayASCII, 3);
        SR.shiftRow(stateArrayASCII, 4);

        //Displaying result.
        cout << "\nState matrix after shifting rows:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        cout << "\nUsing the mixColumns step: \n";

        //Displaying the current state matrix.
        cout << "\nState matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        //Mixing the columns for all rounds except the last.
        if (roundCount!=roundSize){
            MC.mix(stateArrayASCII);
        }

        //Assigning the mixed values back to the state.
        for(int i=0;i<16;i++){
            stateArrayASCII[i] = MC.temp[i];
        }

        //Displaying results.
        cout << "\nState matrix after mixing columns:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        //Repeating but with the round two key.
        if(roundCount==2){
            cout << "\nRound 2 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey2[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey2[i];
            }

            cout << "\nState after XORing with the round 2 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the second round key, we can continue with the main loop.\n";
            //Repeating but with the round three key.
        } else if(roundCount==3){
            cout << "\nRound 3 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey3[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey3[i];
            }

            cout << "\nState after XORing with the round 3 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the third round key, we can continue with the main loop.\n";
            //Repeating but with the round four key.
        } else if (roundCount==4){
            cout << "\nRound 4 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey4[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey4[i];
            }

            cout << "\nState after XORing with the round 4 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the fourth round key, we can continue with the main loop.\n";
            //Repeating but with the round five key.
        } else if (roundCount==5){
            cout << "\nRound 5 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey5[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey5[i];
            }

            cout << "\nState after XORing with the round 5 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the fifth round key, we can continue with the main loop.\n";
            //Repeating but with the round six key.
        } else if (roundCount==6){
            cout << "\nRound 6 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey6[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey6[i];
            }

            cout << "\nState after XORing with the round 6 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the sixth round key, we can continue with the main loop.\n";
            //Repeating but with the round seven key.
        } else if (roundCount==7){
            cout << "\nRound 7 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey7[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey7[i];
            }

            cout << "\nState after XORing with the round 7 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the seventh round key, we can continue with the main loop.\n";
            //Repeating but with the round eight key.
        } else if (roundCount==8){
            cout << "\nRound 8 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey8[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey8[i];
            }

            cout << "\nState after XORing with the round 8 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the eighth round key, we can continue with the main loop.\n";
            //Repeating but with the round nine key.
        } else if (roundCount==9){
            cout << "\nRound 9 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey9[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey9[i];
            }

            cout << "\nState after XORing with the round 9 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the ninth round key, we can continue with the main loop.\n";
            //Repeating but with the round ten key.
        } else if (roundCount==10){
            if(roundSize==10){
                cout << "\nFor the last round, we will do the exact same steps, but we will not apply the mixColumns step.\n";
            }
            //Displaying the tenth key matrix.
            cout << "\nRound 10 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey10[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            //XORing the state with the round ten key.
            for(int i=0;i<16;i++){
                stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey10[i];
            }

            //Displaying result.
            cout << "\nState after XORing with the round 10 key matrix:\n";
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    stringstream ss;
                    ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                    cout << ss.str();
                    p++;
                }
                cout << '\n';
            }
            p=0;

            cout << "\n\n\n\n\nNow that we have applied the state to the tenth round key, we can are done with the main loop.\n";
        }
//        if(roundSize>10){
//            //Repeating but with the round 11 key.
//            if (roundCount==11){
//                cout << "\nRound 11 key matrix:\n";
//                for(int i=0;i<4;i++){
//                    for(int j=0;j<4;j++){
//                        stringstream ss;
//                        ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey11[p]) << ' ';
//                        cout << ss.str();
//                        p++;
//                    }
//                    cout << '\n';
//                }
//                p=0;
//
//                for(int i=0;i<16;i++){
//                    stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey11[i];
//                }
//
//                cout << "\nState after XORing with the round 11 key matrix:\n";
//                for(int i=0;i<4;i++){
//                    for(int j=0;j<4;j++){
//                        stringstream ss;
//                        ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
//                        cout << ss.str();
//                        p++;
//                    }
//                    cout << '\n';
//                }
//                p=0;
//
//                cout << "\nNow that we have applied the state to the eleventh round key, we can go through the main loop for AES. "
//                        "The main loop entails of using the subBytes step: \n";
//                //Repeating but with the round 12 key.
//            }  else if (roundCount==12){
//                if(roundSize==12){
//                    cout << "\nFor the last round, we will do the exact same steps, but we will not apply the mixColumns step.\n";
//                }
//                cout << "\nRound 12 key matrix:\n";
//                for(int i=0;i<4;i++){
//                    for(int j=0;j<4;j++){
//                        stringstream ss;
//                        ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey12[p]) << ' ';
//                        cout << ss.str();
//                        p++;
//                    }
//                    cout << '\n';
//                }
//                p=0;
//
//                for(int i=0;i<16;i++){
//                    stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey12[i];
//                }
//
//                cout << "\nState after XORing with the round 12 key matrix:\n";
//                for(int i=0;i<4;i++){
//                    for(int j=0;j<4;j++){
//                        stringstream ss;
//                        ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
//                        cout << ss.str();
//                        p++;
//                    }
//                    cout << '\n';
//                }
//                p=0;
//
//                cout << "\nNow that we have applied the state to the twelfth round key, we can go through the main loop for AES. "
//                        "The main loop entails of using the subBytes step: \n";
//            }
//        }
//        if(roundSize==14) {
//            //Repeating but with the round 13 key.
//            if (roundCount == 13) {
//                cout << "\nRound 13 key matrix:\n";
//                for (int i = 0; i < 4; i++) {
//                    for (int j = 0; j < 4; j++) {
//                        stringstream ss;
//                        ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey13[p]) << ' ';
//                        cout << ss.str();
//                        p++;
//                    }
//                    cout << '\n';
//                }
//                p = 0;
//
//                for (int i = 0; i < 16; i++) {
//                    stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey13[i];
//                }
//
//                cout << "\nState after XORing with the round 13 key matrix:\n";
//                for (int i = 0; i < 4; i++) {
//                    for (int j = 0; j < 4; j++) {
//                        stringstream ss;
//                        ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
//                        cout << ss.str();
//                        p++;
//                    }
//                    cout << '\n';
//                }
//                p = 0;
//                cout
//                        << "\nNow that we have applied the state to the thirteenth round key, we can go through the main loop for AES. "
//                           "The main loop entails of using the subBytes step: \n";
//            }
//        }
    }

        //Checking if the round size is 10 so that it can perform the final round without mixColumns.
    if(roundSize==10) {
        cout << "\nRound 10: \n";
        cout << "\nFor the last round, we will do the exact same steps, but we will not apply the mixColumns step.\n";
        cout << "\nState matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        SB.SBoxState(stateArrayASCII);

        cout << "\nState matrix after SBox:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

        cout << "\nUsing the shiftRows step: \n";

        cout << "\nState matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;

//    SR.shiftRow(1);   Does not shift anything since it is the first row.
        SR.shiftRow(stateArrayASCII, 2);
        SR.shiftRow(stateArrayASCII, 3);
        SR.shiftRow(stateArrayASCII, 4);

        cout << "\nState matrix after shifting rows:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
                cout << ss.str() << ' ';
                p++;
            }
            cout << '\n';
        }
        p=0;
        cout << "\nRound 10 key matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey10[p]) << ' ';
                cout << ss.str();
                p++;
            }
            cout << '\n';
        }
        p=0;

        for(int i=0;i<16;i++){
            stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey10[i];
        }

        cout << "\nState after XORing with the round 10 key matrix:\n";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                stringstream ss;
                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
                cout << ss.str();
                p++;
            }
            cout << '\n';
        }
        p=0;
    }

//        //Checking if the round size is 12 so that it can perform the final round without mixColumns.
//    if(roundSize==12) {
//        cout << "\nRound 10: \n";
//        cout << "\nFor the last round, we will do the exact same steps, but we will not apply the mixColumns step.\n";
//        cout << "\nState matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
//        SB.SBoxState(stateArrayASCII);
//
//        cout << "\nState matrix after SBox:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
//        cout << "\nUsing the shiftRows step: \n";
//
//        cout << "\nState matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
////    SR.shiftRow(1);   Does not shift anything since it is the first row.
//        SR.shiftRow(stateArrayASCII, 2);
//        SR.shiftRow(stateArrayASCII, 3);
//        SR.shiftRow(stateArrayASCII, 4);
//
//        cout << "\nState matrix after shifting rows:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//        cout << "\nRound 12 key matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey12[p]) << ' ';
//                cout << ss.str();
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
//        for(int i=0;i<16;i++){
//            stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey12[i];
//        }
//
//        cout << "\nState after XORing with the round 12 key matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
//                cout << ss.str();
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//    }
//        //Checking if the round size is 14 so that it can perform the final round without mixColumns.
//    if(roundSize==14) {
//        cout << "\nRound 10: \n";
//        cout << "\nFor the last round, we will do the exact same steps, but we will not apply the mixColumns step.\n";
//        cout << "\nState matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
//        SB.SBoxState(stateArrayASCII);
//
//        cout << "\nState matrix after SBox:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
//        cout << "\nUsing the shiftRows step: \n";
//
//        cout << "\nState matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
////    SR.shiftRow(1);   Does not shift anything since it is the first row.
//        SR.shiftRow(stateArrayASCII, 2);
//        SR.shiftRow(stateArrayASCII, 3);
//        SR.shiftRow(stateArrayASCII, 4);
//
//        cout << "\nState matrix after shifting rows:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
//                cout << ss.str() << ' ';
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//        cout << "\nRound 14 key matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(addRK.RoundKey14[p]) << ' ';
//                cout << ss.str();
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//
//        for(int i=0;i<16;i++){
//            stateArrayASCII[i] = stateArrayASCII[i] ^ addRK.RoundKey14[i];
//        }
//
//        cout << "\nState after XORing with the round 14 key matrix:\n";
//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++){
//                stringstream ss;
//                ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]) << ' ';
//                cout << ss.str();
//                p++;
//            }
//            cout << '\n';
//        }
//        p=0;
//    }


    cout << "\nFinal State Matrix:\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            stringstream ss;
            ss << setfill('0') << setw(2) << hex << int(stateArrayASCII[p]);
            cout << ss.str() << ' ';
            p++;
        }
        cout << '\n';
    }
    //If you wanted the base64 value for the output matrix it could go here and tell for the specific base64 value.
    cout << "\nIf we wanted to transform the output for input 'i love pizza' and key 'I love pizza so!' it would be:\nXcpxmodLqTC3WiLH";

    return 0;
}