#include <stdio.h>

int main (void) {
    int i = 32;
    while (i < 127) {
        printf("%d 0x%X %c\n", i, i, i);
        i = i + 1;
    }
    
    
    
    return 0;
}
