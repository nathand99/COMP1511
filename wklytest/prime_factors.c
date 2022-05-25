#include <stdio.h>

int main (void) {
    int i = 2;
    int num = 0;
    int factor;
    int stoploop = 0;
    printf("Enter number: ");
    scanf("%d", &num);
   

    while (i <= num) {
        if (num % i != 0) {
            factor = i;
            }
            int k = 2;
            while (k < factor && stoploop ==0) {
                if (factor % k == 0) {
                    stoploop = 1;
                 }
                 k = k + 1;
                 printf("%d * ", factor);
        } 
        i = i + 1;
    }
    
 
    printf("The prime factorisation of %d is: ", num);
    
    
    
        printf("%d is prime\n", num);
    
    return 0;   
}
