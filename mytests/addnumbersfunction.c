#include <stdio.h>


int addnumbers (int num1, int num2) {
    int sum = num1 + num2;
    printf("%d\n", sum);
    return sum;
    
    }



int main (void) {
//int num1;
//int num2;
//printf("Enter 2 numbers: \n");
//scanf("%d %d", &num1, &num2);
//addnumbers (50, 2);
int sum = addnumbers (50, 2);
printf("sum = %d\n", sum); //put int num1 and int num2 in bracket to enter numbers instead
//printf("%d", sum);
return 0;
}
