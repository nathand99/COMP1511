#include <stdio.h>


int main (void) {
    int num;
    printf("Enter size: ");
    scanf("%d", &num);
    
    int i = 0;
    
    while (i < num) {
        int j = num - 1;
        int k = 0;
        while (j >= 0) {
            if (j == i || k == i) {
                printf("*");
            } else {
                  printf("-");
              }
            j = j - 1;
            k = k + 1;
        }
        printf("\n");
        i = i + 1;
    }
    return 0;
}

