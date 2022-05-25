#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_last(head);
    print_list(new_head);

    return 0;
}


// Delete the last node in list.
// The deleted node is freed.
// The head of the list is returned.

struct node *delete_last(struct node *head) {
    //if theres nothing in the list, return NULL
    if (head == NULL) {
        return NULL;
    }
    //if there is only 1 thing in the list, return NULL
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }
    //go through the list until you hit NULL
    struct node *p = head;
    struct node *q; //q follows behind p
    while (p -> next != NULL) {
        q = p;
        p = p -> next;
    }
    //p is the last thing in the list, so make q (which is 1 behind p)
    //point to NULL, and free p
    q -> next = NULL;
    free(p);
    
    return head;

}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
         printf("%d", n->data);
         if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

