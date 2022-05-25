//print a hollow triangle

#include <stdio.h>

int main (void) {
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    int i = 0;
    while ( i < size -1) {
        printf("*");
       
        int k = 1;
        
        while (k <= i) {
            
            
            if (i - k == 0) {
                printf("*");
            }   else {
                    printf(" ");
                }
             k = k + 1;
        }
        printf("\n");
        i = i + 1;
    }
    int j = 0;
    while ( j < size) {
        printf("*");
        j = j + 1;
    
    }
    printf("\n");
    
    return 0;
    
}
