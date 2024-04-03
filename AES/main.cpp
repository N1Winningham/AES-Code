#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int bitSize = 0;
    int roundSize = 0;
    string key;
    string inputText;
    int addSpaces = 0;

    cout << "Throughout this experience you will learn the steps of AES (Advanced Encryption Standard).\n"
            "The first thing we will need to know is what bit size you would like to choose.\n\n";

    //Sets the bit size and the round size.
    while (bitSize != 128 && bitSize != 192 && bitSize != 256) {
        cout << "Enter bit size (128, 192, or 256): ";
        cin >> bitSize;

        if (bitSize != 128 && bitSize != 192 && bitSize != 256) {
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

    //Makes sure the entered string is exactly 16 characters.
    while(inputText.length()>=16){
        cout<<"\nThe phrase you entered is not 16 characters. Please try again.\n";
        getline(cin, inputText);
    }

    //Makes the text divisible by 16
    while (inputText.length() % 16 != 0){
        inputText += ' ';
        addSpaces = 1;
    }

    //Declaring the two arrays and the lookup table.
    vector<char> stateVectorHex(inputText.begin(), inputText.end()); //Takes the individual characters and puts them into an array.
    vector<string> stateVector;
    map<int, string> lookupTable;

    //Converts the ASCII numbers into hexadecimal format using a lookup table.
    for(int j = 0; j < stateVectorHex.size(); j++){
        stringstream ss;    //Declares a stringstream that allows to switch from numbers to letter and back easily.
        ss << setfill('0') << setw(2) << hex << (int)stateVectorHex[j]; //Ensures that the hexadecimal is exactly two digits.
        lookupTable[(int)stateVectorHex[j]] = ss.str();
        stateVector.push_back(lookupTable[(int)stateVectorHex[j]]);
    }

    //Turns the decimal numbers of the characters into hexadecimal.
    for (int i = 0; i < stateVector.size(); i++) {
        cout << '"' << char(stateVectorHex[i]) << '"' << " in hexadecimal is: " << stateVector[i];
        cout << "\n";
    }


    cout << "\nThe matrix in hexadecimal format would look like:\n\n";

    //Divides the values into four-by-four format.
    for(int j = 0; j < stateVector.size(); j++){
        cout << stateVector[j] << "  ";
        if ((j+1)%4==0 && j!=0){
            cout << "\n";
        }
    }

    //Checks to see if the program had to add spaces to make the block 16 bytes.
    if(addSpaces == 1){
        cout<<"\nDue to AES operating on 16 byte blocks, we have added spaces to the end of your string so that there will be "
              "the correct amount of bytes for AES to occur.\n";
    }

    cout << "\nThis is called the 'state array.' It will undergo change throughout the process.\n";

    cout << "\nNow that we have our text, we need to establish a key.  The key is a 16 byte block. Our key will ensure only us and the people we"
            " want to share the data with have access.\nPlease enter an exactly 16 character phrase:\n";
    cout << "LLLLLLLLLLLLLLLL         <- Here is a 16 character measuring tool for you.\n";
    getline(cin, key);

    //Makes sure the entered string is exactly 16 characters.
    while(key.length()!=16){
        cout<<"\nThe phrase you entered is not 16 characters. Please try again.\n"
              "LLLLLLLLLLLLLLLL\n";
        getline(cin, key);
    }

    vector<char> keyVectorHex(key.begin(), key.end()); //Takes the individual characters and puts them into a vector.
    vector<string> keyVector;

    //Converts the ASCII numbers into hexadecimal format using a lookup table.
    for(int j = 0; j < keyVectorHex.size(); j++){
        stringstream ss;    //Declares a stringstream that allows to switch from numbers to letter and back easily.
        ss << setfill('0') << setw(2) << hex << (int)keyVectorHex[j]; //Ensures that the hexadecimal is exactly two digits.
        lookupTable[(int)keyVectorHex[j]] = ss.str();
        keyVector.push_back(lookupTable[(int)keyVectorHex[j]]);
    }

    //Turns the decimal numbers of the characters into hexadecimal.
    for (int i = 0; i < keyVector.size(); i++) {
        cout << '"' << char(keyVectorHex[i]) << '"' << " in hexadecimal is: " << keyVector[i];
        cout << "\n";
    }

    vector<int> keyVectorASCII;

    //Converts the ASCII numbers into hexadecimal format using a lookup table.
    for(int j = 0; j < keyVectorHex.size(); j++){
        keyVectorASCII.push_back((int)keyVectorHex[j]);
    }

    cout << "\nThe matrix in hexadecimal format would look like:\n\n";

    //Divides the values into four-by-four format.
    for(int j = 0; j < keyVector.size(); j++){
        cout << keyVector[j] << "  ";
        if ((j+1)%4==0 && j!=0){
            cout << "\n";
        }
    }

//    cout << "\nNow that we have our key, we can expand the key to fit our " << roundSize << " rounds.\n";
//
//    cout << "\nThe first step in expanding our round key is to take the current key we have right now and grab the "
//            "last column.  Once we have the last column, we will then rotate the column (put the top value on the bottom and "
//            "rotate the rest up.)\n";
////    HERE IS WHERE WE INSERT THE CODE/DEMONSTRATION OF THE ROTATE.
//
//    cout << "\nNow that we have rotated the column, we can substitute the bytes.  This is done by taking each of the "
//            "hexadecimal values and finding where they intersect to give a new value.\n";
//
////    HERE IS WHERE WE INSERT THE CODE/DEMONSTRATION OF THE SUB.
//
//    cout << "\nNow that we have substituted the bytes, we create the first column for the first round key. To do this,"
//            "we will start by XORing the column we just rotated and substituted with the first column of the state.\n";
//
//    //    HERE IS WHERE WE INSERT THE CODE/DEMONSTRATION OF THE XOR.
//
//    cout << "\nNow, we will XOR the column we just created with the first RCON value.\n";
//
//    //    HERE IS WHERE WE INSERT THE CODE/DEMONSTRATION OF THE XOR.
//
//    cout << "\n\n";

    return 0;
}

