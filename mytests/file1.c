#include <stdio.h>

int main (void) {

    int i = 0;
    while (i <128) {
    printf("The ascii code for %d prints out %c\n", i, i);
    i = i + 1;
    }
    return 0;
    
}
