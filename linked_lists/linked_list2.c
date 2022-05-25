#include <stdio.h>
#include <stdlib.h>


struct node {
    struct node *next;
    int         data;
};

int sum_list(struct node *head);
void print_list (struct node *head);

int main(int argc, char *argv[]) {
    //create a struct node * that will be for the last node and 
    //initialise it to NULL
    struct node *last_node = NULL;
    struct node *a = NULL;
    int i = 0;
    //scan in numbers numbers until a number isn't read
    while (scanf("%d", &i) == 1) {
        a = malloc(sizeof (struct node)); //give "a" memory of size struct node
        a -> data = i;          //the data field of this is i                       
        a -> next = last_node;  //the next field is last_node (node created last time
                                //around the loop
        last_node = a;          //last_node is set to the struct_node created
    }                           

    print_list(a);


    //int sum = sum_list(a);
    //printf("%d\n", sum);
}

int sum_list(struct node *head) {
    //giving the struct node passed in the name p
    struct node *p = head;
    int total = 0;
    //go through the structs which are linked together and sum their data fields
    while (p != NULL) {
        //printf("p=%p p->data=%d p->next=%p\n", p, p->data, p->next);
        total = total + p->data;
        p = p->next;
    }
    return total;
}

void print_list (struct node *head) {    
    struct node *p = head;
    while (p != NULL) {
        printf("%d", p -> data);
        p = p -> next;
    }
    printf("\n");
}
