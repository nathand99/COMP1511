#include <stdio.h>

#define SIZE 10000

int find_largest (int array[]);

int main(void) {
    int i = 0;
    int numbers[SIZE] = {0};
    int missing_numbers[SIZE] = {0};
    
    //scan in numbers until EOF into array
    while(scanf("%d", &numbers[i]) != EOF) {
        i = i + 1;        
    }
    int largest = find_largest(numbers);
    
    int j = 0;
    while (j < largest - 1) {
        missing_numbers[numbers[j]] = -1;
        j = j + 1;
    }
    

    //print out missing numbers
    int k = 1;
    while (k < largest) {
        if (missing_numbers[k] != -1) {      
            printf("%d ", k);
        }
        k = k + 1;
    }
    printf("\n");
    return 0;
}

int find_largest (int array[]) {
    int i = 0;
    int largest = 0;
    while (i < SIZE) {
        if (array[i] > largest) {
            largest = array[i];
        }
        i = i + 1;
    }
    return largest;
}
