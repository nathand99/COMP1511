#include <stdio.h>
#include <string.h>

int main(void) {
    char *s = "hello";
    printf("%d\n", strcmp(s, s));
    return 0;
}
