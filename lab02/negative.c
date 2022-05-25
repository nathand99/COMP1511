//Created by Nathan Driscoll

//A program that says if a negative number is negative and a positive number is positive

#include <stdio.h>

int main(void) {

int number;

    scanf("%d", &number);
    
    if(number>0) {
    printf("You have entered a positive number.\n");  
}
    if(number<0) {
    printf("Don't be so negative!\n");
    
}
    if(number==0){
    printf("You have entered zero.\n");
}
return 0;
}
