#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//now we dont use the last_node function because it takes a lot of time
//we keep a pointer to the last node and kee moving it along
//every time we have a new number, it allocates space for it

//also im using free with the free list function

struct node {
    struct node *next;
    int         data;
};

int sum_list(struct node *head);
void print_list (struct node *head);
struct node *create_node (int i, struct node *next_node);
struct node *last_node (struct node *head);
void free_list(struct node *head);

int main(int argc, char *argv[]) {
    //if its the first one we create the node and set first and last to it
    //if we are adding on, we make a new node and make it when the last node created
    //points to with the last node starting at first
    //we then make the last node the current node
    struct node *first = NULL;
    struct node *last;
    int i = 0;
    while (scanf("%d", &i) == 1) {
        if (first == NULL) {
            first = create_node(i, NULL);
            last = first;
        } else {
            struct node *new = create_node(i, NULL);                             
            last -> next = new;
            last = new;      
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

void free_list(struct node *head) {
    struct node *p = head;
    while (p != NULL) {
        struct node *q = p -> next; //if we dont do this line, we get "use after
                                    //free" bugs
        free(p);
        p = q;
    }
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
    assert(a != NULL);
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
