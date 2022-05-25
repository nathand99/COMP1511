#include <stdio.h>

int main (void) {
    char array[100000];
    FILE *stream = fopen("test2.txt", "r");
    
   
            while (fgets(array, 100000, stream) != NULL) {
                printf("read a '%s'\n",array); 
            }
    fclose(stream);
    return 0;
    
}
