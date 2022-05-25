#include <stdio.h>


int main (void) {
    int num;
    printf("Enter the flag size: ");
    scanf("%d", &num);
    
    int i = 0;
    
    while (i < num*4) {
        
        int j = num - 1;
        int k = 0;
        while (k <= num*9) {
            if ((k <= num * 2 + (num-1)) || (k > num * 2 + (num-1) + 2)) {
                printf("#");
            } else {
                  printf(" ");
              }
            j = j - 1;
            k = k + 1;
        }
        printf("\n");
        i = i + 1;
        if (i == num * 2 + (num-1)) {
            printf("\n");
            printf("\n");
        }
    }
    return 0;
}

