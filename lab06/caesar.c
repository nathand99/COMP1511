#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int encrypt(int character, int shift);

int main (int argc, char *argv[]) {
    int c = 0;
    
    int shift = atoi(argv[1]);
    shift = shift % 26;
   
    while (c != EOF) {
        c = getchar();
        
        if (c != EOF) {            
        c = encrypt(c, shift);
        putchar(c);
        }
    }
    return 0;
    
}

int encrypt(int character, int shift) {
    int i = 0;
    //change lower case (positive shift)
    if (shift > 0) {
    if (character >='a' && character <= 'z') {
        while (i < shift) {
            character = character + 1;
            if (character > 'z') {
                character = 'a';
            }
            i = i + 1;
        }
    }
    }
    //change lower case (negative shift)
    if (shift < 0) {
        if (character >='a' && character <= 'z') {
            while (i > shift) {
                character = character - 1;
                if (character < 'a') {
                    character = 'z';
                }
                i = i - 1;
            }
        }
    }    
    //change upper case   
    if (shift > 0) {
    if (character >='A' && character <= 'Z') {
        while (i < shift) {
            character = character + 1;
            if (character > 'Z') {
                character = 'A';
            }
            i = i + 1;
        }
    }  
    }     
    //change upper case (negative shift)
    if (shift < 0) {
        if (character >='A' && character <= 'Z') {
            while (i > shift) {
                character = character - 1;
                if (character < 'A') {
                    character = 'Z';
                }
                i = i - 1;
            }
        }   
    }    
    
    return character;
}
