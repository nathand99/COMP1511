#include <stdio.h>

int main (void) {
    int num1, num2, num3, middle;
    printf("Enter integer: ");
    scanf("%d", &num1);
    
    printf("Enter integer: ");
    scanf("%d", &num2);
    
    printf("Enter integer: ");
    scanf("%d", &num3);
    
    if ((num1 >= num2 && num1 <= num3) || 
       (num1 <= num2 && num1 >= num3)) {
        middle = num1;
    }
        
    if ((num2 >= num1 && num2 <= num3) || 
       (num2 <= num1 && num2 >= num3)) {
        middle = num2;
    }
    else {
        middle = num3;
    }
    
    printf("Middle: %d\n", middle);
    return 0;
}
