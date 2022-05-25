#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26
int encrypt(int character, char new_array[],char array2[], char alphabet_lower[], char alphabet_upper[]);

int main (int argc, char *argv[]) {
    char new_array[ALPHABET] = {0}; //array to collect the substitution 
    char array2[ALPHABET] = {0}; //array to get normal alpabet
    char alphabet_upper[ALPHABET] = {0}; //the alphabet upper case
    char alphabet_lower[ALPHABET] = {0}; //the alphabet lower case
   // f(argv[0]);
    
    
    int counter = 0;
    //lower case substituted alphabet
    while (counter <= ALPHABET - 1) {
        new_array[counter] = argv[1][counter];
        counter = counter + 1;
    }
    //upper case substituted alphabet
    counter = 0;
    while (counter <= ALPHABET - 1) {
        array2[counter] = argv[1][counter] - 'a' + 'A';
        counter = counter + 1;
    }
     
    //make the normal lower case alphabet 
    counter = 0;
    int letter = 'a';
    while (counter <= ALPHABET - 1) {
        alphabet_lower[counter] = letter;
        letter = letter + 1;
        counter = counter + 1;
    }
    //make the normal lower case alphabet 
    counter = 0;
    int upper_letter = 'A';
    while (counter <= ALPHABET - 1) {
        alphabet_upper[counter] = upper_letter;
        upper_letter = upper_letter + 1;
        counter = counter + 1;
    }
    int character = 0;
    while (character != EOF) {
        character = getchar();
        
        if (character != EOF && character != 0) {            
        character = encrypt(character, new_array, array2, alphabet_lower,       alphabet_upper);
        
        putchar(character);
        }
    }
    
    return 0;
    
}

int encrypt(int character, char new_array[], char array2[], char alphabet_lower[], char alphabet_upper[]) {
    if (character >= 'a' && character <= 'z') {
        int i = 0;
        int a = 0;
        while (a != character) {
            a = new_array[i];
            i = i + 1;
        }
        a = alphabet_lower[i - 1];
        return a;
    } if (character >= 'A' && character <= 'Z') {
        int i = 0;
        int a = 0;
        while (a != character) {
            a = array2[i];
            i = i + 1;
        }
        a = alphabet_upper[i - 1];
        return a;
    }   else {
            return character;
              }
}
