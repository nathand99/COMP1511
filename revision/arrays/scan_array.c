// Scan in an array.
// Created by
//  ... (z0000000)
//  ... (z0000000)
// Created on 2017-08-??
// Tutor's name (day_hH-lab)

#include <stdio.h>
#include <assert.h>

void scan_array(int size, int array[size]);
void show_array(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCITON
int main(int argc, char *argv[]) {
    // get array size
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // declare array
    int array[size];

    // get values
    printf("Enter array values: ");
    scan_array(size, array);

    // print values
    show_array(size, array);

    return 0;
}

// this function reads in values from
// standard input into an array
void scan_array(int size, int array[size]) {
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i = i + 1;
    }
}

// this function prints the array in the format
// [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    printf("[");
    int i = 0;
    while (i < size - 1) {
        printf("%d, ", array[i]);
        i = i + 1;
    }
    printf("%d]\n", array[size - 1]);
}
