#include <stdio.h>


int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    int counter = 0;
    int i = 0;
    while (i < length) {
        int j = 0;
        while (j < length) {
            if (source1[i] == source2[j]) {
                destination[counter] = source1[i];
                counter = counter + 1;
                break;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    return counter;
}


#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    
    return 0;
}
