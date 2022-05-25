

#include <stdio.h>

int main(void) {

    double num1, num2, num3;

    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if ((num1 + num2) > num3 && (num1 + num3) > num2 &&
    (num3 + num2) > num1 )   {
        printf("triangle\n");
    }    else   {
            printf("not a triangle\n");
         }



    return 0;
}
