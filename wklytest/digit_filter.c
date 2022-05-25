
#include <stdio.h>

int main (void) {
    int c = getchar();
    while (c != EOF) {
        if ((c >= '0' && c <= '9') || (c == '\n') || (c == ' ')) {
            putchar(c);
        } else {
            putchar('.');
        }
        c = getchar();
    }
    
    return 0;
}
