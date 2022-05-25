#include <stdio.h>



int main (void) {
  int size = 0; 
  printf("Enter size: ");
  scanf("%d", &size);
 // while (42==42) {
    //print out first row
  int i = 0;
  while (i < size)  {
    printf("* ");
    i = i + 1;
  }
  printf("\n");
   
  int m = 2;  //second row
  while (m <= size-1) { //all the rows
  printf("*");
  int k = 2;
    while (k <= size) {     //prints end *
      if (k == size) {
        printf(" *\n");
      } else {
          printf("  ");
        }
      k = k + 1;
    }
    
  m = m + 1;        //last row
   }
     int n = 0;
  while (n < size)  {
    printf("* ");
    n = n + 1;
  }
  printf("\n");
   
  // }
   
   
   return 0;
}


