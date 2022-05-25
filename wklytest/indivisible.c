#include <stdio.h>

int main (void) {
    int array[1000] = {0};
    int indivisible[1000] = {0};
    int i = 0;
    int indivisible_counter = 0;
    while (scanf("%d", &array[i]) == 1) {
        i = i + 1;
    }
    int length = i;
    i = 0;
    while (i < length) {
        int j = 0;
        while (j < length) {
            if (array[i] % array[j] == 0 && i != j) {
                break;
            }
           // printf("%d", j);
            j = j + 1;
            if (j == length) {
                indivisible[indivisible_counter] = array[i];
                indivisible_counter++;

            }
                
        }
        i = i + 1;
    }
    printf("Indivisible numbers: ");
    i = 0;
    while (indivisible[i] != 0) {
        printf("%d ", indivisible[i]);
        i = i + 1;
    }
    printf("\n");
    return 0;
}
