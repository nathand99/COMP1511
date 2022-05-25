#include <stdio.h>


void addnumbers (int num1, int num2) {
    int sum = num1 + num2;
    printf("%d\n", sum);
    return;
    
    }



int main (void) {
int num1;
int num2;
scanf("%d %d", &num1, &num2);

addnumbers (num1, num2);

return 0;
}
