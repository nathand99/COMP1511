#include <stdio.h>

int main (void) {
    
    int c = getchar();
    
    while (c != EOF) {
        printf("%d\n", c);
        
        c = getchar();
    }
    
    
    
    return 0;
}
