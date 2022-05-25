//a program that counts from one number up to another

#include <stdio.h>

int main (void) {
    int i = 0;
    int max = 0;
    printf("Enter lower: ");
    scanf("%d", &i);
    
    printf("Enter upper: ");
    scanf("%d", &max);

    while (i < max -1) {
        printf("%d\n", i + 1);
        
        i = i + 1;
    }
              
    return 0;   
}
