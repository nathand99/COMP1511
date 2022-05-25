#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    char string[] = "-n";
    if ((strcmp(argv[1], string)) == 0) {
        int lines = atoi(argv[2]);
        
     FILE *stream = fopen(argv[3], "r");
    
    int c = fgetc(stream);
    int line = 0;
    while (c != EOF && c != 0 && line < lines) {
            fputc(c, stdout); 
            c = fgetc(stream);
            if (c == '\n') {
            line = line + 1;
            }
            
        }
    if (c != EOF && c != 0) {
        fputc(c, stdout); 
    }
    } else {
    FILE *stream = fopen(argv[1], "r");
    
    int c = fgetc(stream);
    int line = 0;
    while (c != EOF && c != 0 && line <= 9) {
            fputc(c, stdout); 
            c = fgetc(stream);
            if (c == '\n') {
            line = line + 1;
            }
            
        }
    if (c != EOF && c != 0) {
        fputc(c, stdout); 
    }
    }
   return 0;
   
} 
    
    
    
    
    
    /*
    
    if (argv[1][0] == - && argv[1][1] == n) {
        int lines = atoi(agrv[2]);
        
     FILE *stream = fopen(argv[3], "r");
    
    int c = fgetc(stream);
    int line = 0;
    while (c != EOF && c != 0 && line <= lines) {
            fputc(c, stdout); 
            c = fgetc(stream);
            if (c == '\n') {
            line = line + 1;
            }
            
        }
    if (c != EOF && c != 0) {
        fputc(c, stdout); 
    }
    
    
*/
