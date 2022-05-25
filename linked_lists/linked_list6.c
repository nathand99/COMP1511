#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//makes list in increasing order

//every time we have a new number, it allocates space for it
//we dont need to say how big it is before
struct node {
    struct node *next;
    int         data;
};

int sum_list(struct node *head);
void print_list (struct node *head);
struct node *create_node (int i, struct node *next_node);
struct node *last_node (struct node *head);
struct node *append(struct node *first, struct node *new);
struct node *insert(struct node *first, struct node *new);
struct node *insert_increasing(struct node *first, struct node *new);

int main(int argc, char *argv[]) {
    //if its the first one we create the node and set first and last to it
    //if we are adding on, we make a new node and make it when the last node created
    //points to with the last node starting at first
    //we then make the last node the current node
    struct node *first = NULL;
    
    int i = 0;
    while (scanf("%d", &i) == 1) {
        struct node *new = create_node(i, NULL);
        first = append(first, new);    
        }                           
    
    print_list(first);
    return 0;
}

//fundtion to add (appened) nodes to a list
//return new first node in list
struct node *append(struct node *first, struct node *new) {
    struct node *last =  last_node(first); 
    if (last == NULL) {
        return new;
    } else {
        last -> next = new;
        return first;
      }
}

struct node *insert(struct node *first, struct node *new) {
    if (first != NULL) {
        new -> next = first;
    }
    return new;
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

//function that inserts numbers so that the list is in increasing order
struct node *insert_increasing(struct node *first, struct node *new) {
    if (first == NULL) {
        return new;
    }
    struct node *p = first;
    while (p->next != NULL && new->data > p->next->data) {
        p = p->next;
    }       //when the loops exits, p finishes before where we want to do the ibsert
    new->next = p->next;   //these three lines puts the new node where it needs to go
    p->next = new;
    return first;
}

// PLEASE DO NOT CALL WITH NULL POINTER
//goes down the list and returns a pointer to the last node
struct node *last_node (struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *p = head;
    while (p -> next != NULL) {
        p = p -> next;
    }
        return p;                  
}                    
