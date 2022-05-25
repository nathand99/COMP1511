
#include <stdio.h>

int main(void) {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    int difference = (num1 - num2);

    if (difference == 0) {
        printf("equal\n");
    }    else if (difference < 0)   {
            difference = difference * (-1);
            printf("%d\n", difference);
            }   else {
                    printf("%d\n", difference);
                    }
            
return 0;

}
