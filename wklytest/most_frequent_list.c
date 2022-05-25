#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int most_frequent(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = most_frequent(head);
    printf("%d\n", result);

    return 0;
}


// return the value which occurs most frequently in a linked list
// if several values are equally most frequent
// the value that occurs earliest in the list is returned

//go through list counting how many times a certain number is seen
//if this is higher than highest then save what the data field is
int most_frequent(struct node *head) {
    int highest_counter = 0; //counts how many times a number has been seen
    int highest_data;        //what the data is of the number seen most
    int highest_number = -1; //the amount of times the most seen number
                             //has been seen
    struct node *p = head;
    struct node *current = head;
    //p is the reference point - and is compared with current, whcih goes through
    //the list. After it checks one number, it moves to the next and current
    //resets to 0
    while (p != NULL) {     
        while (current != NULL) {
            if (p -> data == current -> data) {
                highest_counter = highest_counter + 1;
            }
            current = current -> next;
        }
        highest_counter = highest_counter - 1; 
        //take away 1 because when going through the list, current will always
        //be the original number of p (the same number) so minus 1 
        if (highest_counter > highest_number) {
            highest_number = highest_counter;
            highest_data = p -> data;
        }
        //reset the counter for how many times a number has been seen and
        //start current (the thing that goes through the list) back at the 
        //beginning (head)
        highest_counter = 0;
        current = head;
        p = p -> next;
    }
    if (highest_number == -1) { //if every number is unique return 0
        return 0;
    }
    return highest_data;    //return the number that is featured the most

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
