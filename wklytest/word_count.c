#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int array[200] = {0};
    
    int line_counter = 0;
    int word_counter = 0;
    int character_counter = 0;
    
    int character = 0;
    int old_character = 0;
    while (character != EOF) {
        character = getchar();
        if (character == '\n') {
            line_counter = line_counter + 1;
        }
        if (character == ' ' || character == EOF) {
            word_counter = word_counter + 1;
        }
        if (character != EOF) {
        character_counter = character_counter + 1;     
        }
        if (character != EOF) {
            old_character = character;
        }
    }
    
    printf("%d lines %d words %d characters\n", line_counter, word_counter, character_counter);   
 
    return 0;
}


