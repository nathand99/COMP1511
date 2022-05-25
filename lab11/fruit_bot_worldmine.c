#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "fruit_bot.h"

void print_world(struct bot *b);

int main(void) {
    struct bot *b = fruit_bot_input(stdin);
    print_world(b);
    return 0;
}



void print_world(struct bot *b) {
    struct bot *head = b;
    
    struct bot*here = b;
    
    
    printf("%s", b->location->name);
}
