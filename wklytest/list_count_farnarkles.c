#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_farnarkles(struct node *head1, struct node *head2);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = count_farnarkles(head1, head2);
    printf("%d\n", result);

    return 0;
}

// Return the number of farnarkles in the two lists, i.e. the number of
// values which occur at the same position in both linked lists.
int count_farnarkles(struct node *head1, struct node *head2) {
    int farnarkle_counter = 0;
    struct node *list1 = head1;
    struct node *list2 = head2;
    while (list1 != NULL && list2 != NULL) {
        if (list1 -> data == list2 -> data) {
            farnarkle_counter = farnarkle_counter + 1;
        }
        list1 = list1 -> next;
        list2 = list2 -> next;
    }
    
    return farnarkle_counter;

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
