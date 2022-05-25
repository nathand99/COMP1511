#include <stdio.h>

int filter (int character);

int main (void) {
    int c = 0;
    while (c != EOF) {
        c = getchar();
        if (c != EOF) {
            c = filter(c);
            putchar(c);
        }
    }
    
    
    return 0;
}

int filter (int character) {
    if ((character >= '0' && character <= '9') || (character == '\n') || character == ' ') {
        return character;
    } else {
          return '.';
      }
}
