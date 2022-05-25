//a code to see if matilda has enough money for ice cream
//created by Nathan Driscoll

#include <stdio.h>

int main(void)  {

int scoops;
int cost;

printf("How many scoops? ");
scanf("%d", &scoops);

printf("How many dollars does each scoop cost? ");
scanf("%d", &cost);

if((cost*scoops)>10) {
printf("Oh no, you don't have enough money :(\n");
}
else {
printf("You have enough money!\n");

}

return 0;

}
