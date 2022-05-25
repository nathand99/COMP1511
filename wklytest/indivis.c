#include <stdio.h>

int main (void) {
    int array[1000] = {0};
    int indivisible[1000] = {0};
    int i = 0;
    int indivisible_counter = 0;
    while (scanf("%d", array[i]) == 1) {
        i = i = 1;
    }
    i = 0;
    while (array[i] != 0) {
        int j = 0;
        while (j != 0) {
            if (array[i] % array[j] == 0 && array[i] / array[j] != 1) {
                break;
            }
            j = j + 1;
            if (j == 0) {
                indivisible[indivisible_counter] = array[i];
                indivisible_counter++;
            }
                
        }
        i = i + 1;
    }
    
    
    
    return 0;
}
