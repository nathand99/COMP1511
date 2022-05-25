#include <stdio.h>
#define SIZE 256

int main (void) {
    char array[SIZE][SIZE];
    int stop = 0;
    int j = 0;
    while(fgets(array[j], SIZE, stdin) != NULL) { //read in input
        int i = 0;
        int k = 0;
        while (i < SIZE) {
            if (array[j] == array[i]) {     //go through array 
                stop = 1;
                break;
            }
            i = i + 1;
        }
        if (stop == 0) {
        fputs(array[j], stdin);
        }
        j = j + 1;
        stop = 0;
    }
    
}
