#include <stdio.h>
#define SIZE 256

int main (void) {
    char array[SIZE] = {0};
    
    fgets(array, SIZE, stdin); //read in line
    
    int position = 0;   //get position
    scanf("%d", &position);
    
    printf("The character in position %d is '%c'\n", position, array[position]);
    return 0;
}
