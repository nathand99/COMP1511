#include <stdio.h>

int main (void) {
    
    int number;
    printf("Enter number: ");
    scanf("%d", &number);


    int counter = 1; 
    int sum = 0;
   
    printf("The factors of %d are: \n", number);
    while (counter <= number) { 
        if (number % counter == 0) {
            printf("%d\n", counter);  
            sum = sum + counter;
            }
            
        counter = counter + 1; 
}

    printf("Sum of factors = %d\n", sum);
    if (sum == 2 * number) {
        printf("%d is a perfect number\n", number);
    }   else  {
            printf("%d is not a perfect number\n", number); 
        
        }
    return 0;
    
}
