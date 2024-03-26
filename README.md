# AES-Code
This is the coding portion of my Junior IS for the College of Wooster titled, "Cracking the Code: A Deep Dive into AES Algorithmic Encryption."  It is written in C++ and shows the steps of AES while explaining them as it goes.  

Issues:
- The first part of my code is the main file, which combines all the other following parts and explains each step.
- The second part is the key schedule file, which is crucial for the individualism of the encryption (generating the round keys).
- The third part is the substitute bytes file, which uses Rijndael’s S-Box to change the data's hexadecimal value at the beginning of each round.
- The fourth part is the shift rows file, which mixes the four-by-four matrix for each round.
- The fifth and final part is the mix columns file, which multiplies a pre-determined four-by-four array to each column at the end of each round.
