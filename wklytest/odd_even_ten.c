//a program that reads numbers and says if they are odd or even

#include <stdio.h>
#define ARRAY_SIZE 10



int main (void) {
    int numbers[ARRAY_SIZE] = {0};
    int i = 0;
    while (i < ARRAY_SIZE) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }
    int j = 0;
    
    printf("Odd numbers were: ");
    while (j < ARRAY_SIZE) {
        if (numbers[j] % 2 != 0) {
            printf("%d ", numbers[j]);
        }
        j = j + 1;
    }
    printf("\n");
    j = 0;
    printf("Even numbers were: ");
    while (j < ARRAY_SIZE) {
        if (numbers[j] % 2 == 0) {
            printf("%d ", numbers[j]);
        }
        j = j + 1;
    }
    printf("\n");
    return 0;
    
}
