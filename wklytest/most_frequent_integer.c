#include <stdio.h>

int main (void) {
    int array[100001] = {0};
    
    int num;
    while (scanf("%d", &num) == 1) {
        array[num] = array[num] + 1;
    }
      
    int highest = 0;
    int number_highest = 0;
    int i = 0;
    while (i < 100001) {
        if (array[i] >= highest) {
            highest = array[i];
            number_highest = i;
        }
        i = i + 1;
    }
        
    
    
    printf("%d\n", number_highest);
}
