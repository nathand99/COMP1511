#include <stdio.h>


int count_bigger(int length, int array[]) {
    int counter = 0;
    int i = 0;
    while (i < length) {
        if (array[i] > 99 || array[i] < -99) {
            counter = counter + 1;
        }
        i = i + 1;
    }
    
    return counter;
}


#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
