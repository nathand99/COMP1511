#include <stdio.h>
#include <stdlib.h>

// return the number of even values in an array.
int count_even(int length, int array[]) {
    int i = 0;
    int counter = 0;
    while (i < length) {
        if (array[i] % 2 == 0) {
            counter = counter + 1;
        }
        i = i + 1;
    }
    return counter;
}

// This is a simple main function which could be used
// to test your count_even function.
// It will not be marked.
// Only your count_even function will be marked.

# define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {16, 7, 8, 12, 13, 19, 21, 12};

    int result = count_even(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
