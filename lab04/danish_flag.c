#include <stdio.h>

int main (void) {
    
    int size;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    for(int rows = 1;rows<=size*4;rows++){
        for(int cols=1;cols<=size*9;cols++){
            if((rows<=size*2-1||rows>=size*2+2) && (cols<=size*3-1||cols>=size*3+2)) {
                printf("#");
            } else {
                printf(" ");
                
            }
            
        }
        printf("\n");
     }
     return 0;
}
