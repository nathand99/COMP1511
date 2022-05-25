#include <stdio.h>
#define TRUE 1
#define FALSE 0
int is_vowel(int c);

int main (void) {
    int c = 0;
    
    while (c != EOF) {
        c = getchar();
 
        if (is_vowel(c) == TRUE) {
            putchar(c);
        }
    }
    return 0;
    
}
//checks if it is a vowel or not
int is_vowel(int c) {
     if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'
        && c != EOF) {
           return 1;
     } else {
           return 0;
       }
}  
