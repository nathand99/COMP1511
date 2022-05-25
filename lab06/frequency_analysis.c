#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define lENGTH 10000
void count(int character, int count_array[]);
int count_array[10000] = {0};
int main (int argc, char *argv[]) {
    int c = 0;
   
    while (c != EOF) {
        c = getchar();
        
        if (c != EOF) {            
        count(c, count_array);
      
        }
    }
    //print out array
    int a = 'a';
    double sum = 0.0;
    while (a <= 'z') {
            
            sum = sum + count_array[a];
            
            a = a + 1;
        }
    //printf("%lf", sum);
    sum = 1.0 / sum;
    
    
    int m = 'a';
    while (m <= 'z') {
        
        
        double decimal = 0.0;
        decimal = count_array[m];
        if (decimal != 0) {
            decimal = sum * decimal;
        }
        printf("'%c' %.6lf %d\n", m, decimal, count_array[m]);
        m = m + 1;
    }
    
    return 0;
    
}

void count(int character, int count_array[]) {
    int i = 0;
    if (character >= 'A' && character <= 'Z') {
        character = character - 'A' + 'a';
    }
   
    count_array[character] = count_array[character] + 1;
    
    
    
    
    
    //return character;
}





