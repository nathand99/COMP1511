#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char array[256] = {0};
    fgets(array, 256, stdin);
    
    int num = 0;
    scanf("%d", &num);
    
    printf("The character in position %d is %c\n", num, array[num]);
    
    return 0;
}
