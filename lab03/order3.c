
#include <stdio.h>

int main (void) {
    int num1, num2, num3, mid, hi, lo;
    
    printf("Enter integer: ");
    scanf("%d", &num1);
    
    printf("Enter integer: ");
    scanf("%d", &num2);
    
    printf("Enter integer: ");
    scanf("%d", &num3);
    
    if (num1>num2){
        mid=num1;
        lo=num2;
     } else {
        mid=num2;
        lo=num1;
     }
     if (mid>num3){
        hi=mid;
        if(lo>num3){
            mid=lo;
            lo=num3;
        } else{
            mid=num3;
        }
      } else hi=num3;
      
     printf("The integers in order are: %d %d %d\n", lo, mid, hi);

   return 0;
}
