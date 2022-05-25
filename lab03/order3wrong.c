// a program that orders 3 numbers from smallest to largest

#include <stdio.h>

int main (void) {

int num1, num2, num3, mid, high, low;
    printf("Enter integer: ");
    scanf("%d", &num1);

    printf("Enter integer: ");
    scanf("%d", &num2);

    printf("Enter integer: ");
    scanf("%d", &num3);

    if (num1 > num2 && num1 > num3) {
    num1 = high;
    }    else if (num2 > num1 && num2 > num3) {
    num2 = high;
         }   else if (num3 > num2 && num3 > num1) {
    num3 = high;
             }
             
    if (num1 < num2 && num1 < num3) {
    num1 = low;
    }    else if (num2 < num1 && num2 < num3) {
    num2 = low;
         }   else if (num3 < num2 && num3 < num1) {
    num3 = low;
             }
             
    if (num1 > num2 && num1 < num3) {
    num1 = mid;
    }    else if (num2 > num1 && num2 < num3) {
    num2 = mid;
         }
                
    printf(" Ther integers in order are: %d %d %d", low, mid, high);
    
    return 0;
    
    }
