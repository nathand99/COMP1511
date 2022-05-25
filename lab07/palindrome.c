//enter a string and tests if it is a palindrome (same forwards as it is backwards)

#include <stdio.h>
#define SIZE 4096
#define TRUE 1
#define FALSE 0

int compare(char numbers[SIZE], int i);
int count (char numbers[SIZE]);
int main (void) {
    char numbers[SIZE];
    printf("Enter a string: ");
    
    fgets(numbers, SIZE, stdin);
    
    int size = count(numbers);
    int function = compare(numbers, size);
    
    if (function == FALSE) {
        printf("String is not a palindrome\n");
    }   else if (function == TRUE) {
            printf("String is a palindrome\n");
        }
   
            
    
    return 0;
}
//compares letters from the front and back to see if they are equal
int compare(char numbers[SIZE], int i) {
    int j = 0;
    while (j <= i) {
        if (numbers[j] != numbers[i] ) {
            return FALSE;
        }
    j = j + 1;
    i = i - 1;
    }
    return TRUE;
}
//counts how many letters we have entered
int count (char numbers[SIZE]) {
    int i = 0;
    while (numbers[i] != '\n') {

        i = i + 1;       
        if (numbers[i] == '\n') {
        return i - 1;
    }
    
}
return 0;
}
