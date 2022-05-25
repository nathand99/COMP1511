//a program that orders 3 numbers from smallest to largest

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
    high = num1;
    }    else if (num2 > num1 && num2 > num3) {
    high = num2;
         }   else {
    high = num3;
             }
    
    
         if (num1 > num2 && num1 < num3) {
            mid = num1;
            }    else if (num1 < num2 && num1 > num3) {
            
            } else if (num2 > num1 && num2 < num3) {
            mid = num2;
              } else if (num2 < num1 && num2 > num3) {
            mid = num2;
                 } else if (num3 > num1 && num3 < num2) {
            mid = num3;
              } else {
            mid = num3; }
                
             if (num1 < num2 && num1 < num3) {
                     low = num1;
                 }else if (num2 < num1 && num2 < num3) {
                         low = num2;
                    }   else  {
                 low = num3;
             }
    printf(" Ther integers in order are: %d %d %d\n", low, mid, high);
    
    return 0;
    
    }
