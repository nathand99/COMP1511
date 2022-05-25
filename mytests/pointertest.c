#include <stdio.h>

int main (void) {
    int i = 0;
    int *p;
    p = &i;
    *p = 10;
    
    printf("%d\n", *p);
    
    
    return 0;
}
