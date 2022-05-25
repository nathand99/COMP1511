#include <stdio.h>
#define TRUE 1
#define FALSE 0
int convert_case(int character);

int main (void) {
    int c = 0;
    
    while (c != EOF) {
        c = getchar();
 
        c = convert_case(c);
        if (c != EOF) {            
        putchar(c);
        }
    }
    return 0;
    
}
//converts case
int convert_case(int character) {
     int alphabet_position = 0;
     if (character >= 'a' && character <= 'z') {
        alphabet_position = character - 'a' + 'A';
     } else if (character >= 'A' && character <= 'Z') {
           alphabet_position = character - 'A' + 'a';
       } else {
            alphabet_position = character;
         }
    return alphabet_position;
}
    

