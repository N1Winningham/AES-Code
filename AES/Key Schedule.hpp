//
// Created by Nathan Winningham on 3/10/24.
//

//WIP, includes pseudocode.

int n,b,t,iteration; //n must be 16, 24, or 32 for 128-bit, 192-bit, and 256-bit.  b must be 176, 208, 240.  t is a temp.

std::string key,expanded_Key;

void assignKeyValues(int x){
    if (x == 128){
        n = 16;
        b = 176;
    } else if (x == 192){
        n = 24;
        b = 208;
    } else if (x == 256){
        n = 32;
        b = 240;
    } else {
        exit(EXIT_FAILURE);
    }
}

void stepOne(std::string k){             //First n bytes are set to the expansion key.
    for(int i=0;i<n;i++){   //Assign first n bytes of the expanded key as the expansion key.
        expandedKey(i) = key(i);
    }
}

void stepTwo(){             //Set Rcon iteration to one.
    iteration = 1;
}

void stepThree(){           //Generate n more bytes of expanded key.
    //Once the b amount of bytes has been generated, to generate n more bytes of the expanded key.
    //Assign previous four bytes of expanded key to t.
    //Perform key schedule core on four bytes with i as iteration.
    //Increment i.
    //XOR t with the four-byte block n bytes before the new expanded key (creating next four bytes of expanded key)
    //Repeat n/4 - 1 times.
    for(int i=0;i<n;i++){
        ...=expanded_Key(i);
    }
}

void stepFour(){            //Create next 12 bytes of expanded key.
    //Assign previous four bytes of expanded key to t.
    //XOR t until you have 12 bytes.
    for(int i=0;i<12;i++){

    }
}

void stepFive(){            //256-bit only, generate four more bytes of exapnded key.
    //Generate four more bytes.
    //Between assigning the four bytes to t and XORing, we would run each of the four bytes in t through Rijndael’s S-box.
}

void finalStep(int x){      //Repeat step five.
    //For 128-bit, don't repeat.
    //For 192-bit, repeat twice.
    //For 256-bit, repeat three times.
    if(x == 192){
        stepFive();
        stepFive();
    } else if(x == 256){
        stepFive();
        stepFive();
        stepFive();
    }
}

void keyExpansion(){
    stepOne();
    stepTwo();
    stepThree();
    stepFour();
    stepFive();
    finalStep(keySize);
}

#endif //AES_KEY_SCHEDULE_HPP
