#include <stdio.h>

int main (void) {
    int i = 0;
    int max = 0;
    int product = 1;
    printf("Enter lower: ");
    scanf("%d", &i);
    i = i + 1;
    printf("Enter upper: ");
    scanf("%d", &max);

    while (i < max) {
        if (i % 2 != 0) {
            product = product * i;
        } 
        i = i + 1;
    }
    printf("%d\n", product);
         
    return 0;   
}
