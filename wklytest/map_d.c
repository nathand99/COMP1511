#include <stdio.h>
#include <stdlib.h>
int change (char c, int array[]);

int main (int argc, char *argv[]) {
    int array[11] = {0};
    int i = 0;
    while (i < 10) {
        array[i] = argv[1][i];
        i = i + 1;
    }
    
    
    int c = getchar();
    while (c != EOF) {
        c = change(c, array);
        putchar(c);
        c = getchar();
    }
    
    return 0;
}

int change (char c, int array[]) {
    int num = 0;
    if (c >= '0' && c <= '9') {
        num = c - '0';
        c = array[num];
    }
    return c;
 }
