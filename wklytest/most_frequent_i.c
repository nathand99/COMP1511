#include <stdio.h>

int main (void) {
    int array[100000] = {0};
    
    int num;
    while (scanf("%d", &num) == 1) {
        array[num] = array[num] + 1;
    }
      
    int highest = 0;
    int number_highest = 0;
    int i = 0;
    while (array[i] < 100000) {
        if (array[i] >= highest) {
            highest = array[i];
            number_highest = i;
        }
        i = i + 1;
    }
        
    
    
    return number_highest;
}
