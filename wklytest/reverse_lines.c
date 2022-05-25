#include <stdio.h>
#define SIZE 256

int main (void) {
    char array[SIZE] = {0};
    while (fgets(array, SIZE, stdin) != NULL) {
        int i = 0;
        while (array[i + 1] != '\n') {
            i = i + 1;
        }
        while (i >= 0) {
            putchar(array[i]);
            i = i - 1;
        }
        putchar('\n');
    }
    return 0;
}
