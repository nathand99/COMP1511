//calculating marks

#include <stdio.h>

int main (void) {

double totmarks, marks;

printf("Enter the total number of marks in the exam: ");
scanf("%lf", &totmarks);

printf("Enter the number of marks the student was awarded: ");
scanf("%lf", &marks);

double percentage = (marks / totmarks) * 100.0;



printf("The student scored %.0lf%% in this exam.\n", percentage);
return 0;

}
