//dating range
//created by Nathan Driscoll

#include <stdio.h>

int main(void) {
int age, upper, lower;

printf("Enter your age: ");
scanf("%d", &age);

lower=(age/2)+7;
upper=age+2*(age-lower);
if(age>=lower) {
printf("Your dating range is %d to %d years old.\n", lower, upper);
}
else {
printf("You are too young to be dating.\n");
}
return 0;
}
