#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 1000
int encrypt(int character, char new_array[],char array2[]);

int main (int argc, char *argv[]) {
    char new_array[ALPHABET] = {0}; //array to collect the substitution 
    char array2[ALPHABET] = {0}; //array to get normal alpabet
   // f(argv[0]);
    
    
    int i = 'a';
    int counter = 0;
    //substituted alphabet
    while (i <= 'z') {
        new_array[i] = argv[1][counter];
        i = i + 1;
        counter = counter + 1;
    }
    //upper case
    int upper = 'A';
    counter = 0;
    while (upper <= 'Z') {
        array2[upper] = argv[1][counter] - 'a' + 'A';
        counter = counter + 1;
        upper = upper + 1;
    }
   
    int c = 0;
    while (c != EOF) {
        c = getchar();
        
        if (c != EOF && c != 0) {            
        c = encrypt(c, new_array, array2);
        
        putchar(c);
        }
    }
    
    return 0;
    
}

int encrypt(int character, char new_array[], char array2[]) {
    if (character >= 'a' && character <= 'z') {
        int i = character;         
        int a = new_array[i];
        return a;
        } else if (character >= 'A' && character <= 'Z') {
               int i = character;
               int b = 0;
               b = array2[i];
            return b;
            
            } else {
                  return character;
              }
}
