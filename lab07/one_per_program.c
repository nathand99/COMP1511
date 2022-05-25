//enter a string and print out characters each on a new line

#include <stdio.h>
#define SIZE 4096

int main (void) {
    int numbers[SIZE];
    printf("Enter a string: ");
    
    fgets (numbers, SIZE, stdin);
    
    int i = 0;
    while (numbers != '\n') {
        printf("%d\n", numbers[i];
        i = i + 1;       
    }

