#include <stdio.h>


int isLeapYear (int year);

int main (void) {

   
    int year = 1;
    
    printf("Enter year: ");
    scanf("%d", &year);
    

        if (isLeapYear (year) == 1) {
            printf("%d is a leap year.\n", year);
            
           } else {
           printf("%d is not a leap year.\n", year);
           }
 
 
return 0;

}  
        
int isLeapYear (int year) {

int result;
        if (year % 4 ==0 && (!(year % 100 == 0) || year % 400 == 0)){
            result = 1;
    }   else {
            result = 0;
            }
            return result;
     }




