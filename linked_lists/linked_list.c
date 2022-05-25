#include <stdio.h>
#include <stdlib.h>


struct node {
    struct node *next;
    int         data;
};

int sum_list(struct node *head);

int main(int argc, char *argv[]) {
    //give me a pointer to a size of memory that is as big as a
    //struct node
    struct node *a = malloc(sizeof (struct node));
    struct node *b = malloc(sizeof (struct node));
    struct node *c = malloc(sizeof (struct node));
    struct node *d = malloc(sizeof (struct node));
    
    //put data into the data fields of each struct
    a->data = 27;
    b->data = 12;
    c->data = 32;
    d->data = 42;

    //the next field now points to the next letter, another piece of memory
    //that holds a struct node
    a->next = b;
    b->next = c;
    c->next = d;
    d->next= NULL;

    printf("a=%p a->data=%d a->next=%p\n", a, a->data, a->next);
    printf("b=%p b->data=%d b->next=%p\n", b, b->data, b->next);
    printf("c=%p c->data=%d c->next=%p\n", c, c->data, c->next);
    printf("d=%p d->data=%d d->next=%p\n", d, d->data, d->next);

    int sum = sum_list(a);
    printf("%d\n", sum);
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
