//print a hollow triangle

#include <stdio.h>

int main (void) {
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    int i = 1;
    while ( i < size) {
        int k = 1;
        while (k <= i) {
            printf("*");
            if (k - i != 0) {
                printf(" ");
            }   else {
                    printf("*");
                }
           
             k = k + 1
       }
        printf("\n");
        i = i + 1;
   }
   
    printf("\n");
    return 0;
    
}
