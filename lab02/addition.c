//A program that sums two numbers

#include <stdio.h>

int number1;
int number2;
int sum;



int main(void) {



printf("Please enter two integers: ");
scanf("%d %d", &number1, &number2);
sum = number1+number2;
printf("%d + %d = %d\n", number1, number2, sum);



return 0;
}
