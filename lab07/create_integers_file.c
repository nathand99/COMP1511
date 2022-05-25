//enter: start, finish of integers and a file name
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
   // char name = argv[3];
    int array[end+1];
    FILE *stream = fopen(argv[3], "w");
    int i = start;
    int counter = 0;
    while (i <= end) {
        array[counter] = i;
        i = i + 1;
        counter = counter + 1;
    }
  
   
    i = 0;
    while (i <= (end - start)) {
        fprintf(stream,"%d\n", array[i]);
        i = i + 1;
    
    }
   
    return 0;
}
