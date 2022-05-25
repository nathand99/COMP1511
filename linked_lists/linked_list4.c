#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//now we go forwards through the list

struct node {
    struct node *next;
    int         data;
};

int sum_list(struct node *head);
void print_list (struct node *head);
struct node *create_node (int i, struct node *next_node);
struct node *last_node (struct node *head);

int main(int argc, char *argv[]) {
    //if we are making the first node, create it and make first point to it
    //if not, find the last node created, and create the next node
    //it points to, putting data in it
    //the first pointer remains pointing at the first node, so print_list will
    //go through the list from first to last
    struct node *first = NULL;
    int i = 0;
    while (scanf("%d", &i) == 1) {
        if (first == NULL) {
            first = create_node(i, NULL);
        } else {
              struct node *last = last_node(first);                             
              last -> next = create_node(i, NULL);       
        }                           
    }
    print_list(first);
    return 0;
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

//function that creates a new struct node and puts data and points to the 
//previous node
struct node *create_node (int i, struct node *next_node) {
    struct node *a = malloc(sizeof (struct node)); 
    a -> data = i;          //the data field of this is i                       
    a -> next = next_node;  
    return a;                    
}   
// PLEASE DO NOT CALL WITH NULL POINTER
//goes down the list and returns a pointer to the last node
struct node *last_node (struct node *head) {
    assert(head != NULL);
    struct node *p = head;
    while (p -> next != NULL) {
        p = p -> next;
    }
        return p;                  
}                            
                                
                                
                                
                                
