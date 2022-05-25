#include <stdio.h>
#include <string.h>

struct student {
    int zID;
    char name[50];
    int mark;
};

struct student read_struct () {
    struct student s;
    printf("zID\t");
    scanf("%d", &s.zID);
    printf("Name\t");
    getchar(); //gets the newline
    fgets(s.name,50,stdin);
    //strcpy(s.name, "Caitlin\n"); //manually putting it in with strcpy
    printf("Mark\t");
    scanf("%d", &s.mark);
    return s;
}

void print_struct (struct student s) {
    printf("zID\t%d\n", s.zID);
    printf("Name\t%s", s.name);
    printf("Mark\t%d\n", s.mark);

}
int main (void) {
    
    struct student s = read_struct();
    
    print_struct(s);
    
    printf("%d", sizeof(int));
    return 0;
}
