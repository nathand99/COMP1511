#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "fruit_bot.h"


#define TRUE 1
#define FALSE 0
int nearest_electricity(struct bot *b);
int has_electricity_for_sale(struct location *l);

int main(int argc, char *argv[]) {
    struct bot *me = fruit_bot_input(stdin);

    int distance = nearest_electricity(me);
    printf("Distance to nearest available electricity is %d\n", distance);

    return 0;
}


// return distance to nearest electricity
// if nearest electricity is west return negative int
// if nearest electricity is current location return 0

int nearest_electricity(struct bot *b) {

    // locations are linked in a circular list
    // move a pointer forwards around list
    // and move a pointer backwards around the list
    // stop when either reaches electricity

    struct location *start = b->location;
    struct location *eastwards = b->location;
    struct location *westwards = b->location;
    int distance = 0;
    while (distance == 0 || eastwards != start) {
        if (has_electricity_for_sale(eastwards)) {
            return distance;
        }
        if (has_electricity_for_sale(westwards)) {
            return -distance;
        }
        eastwards = eastwards->east;
        westwards = westwards->west;
        distance = distance + 1;
    }

    // we should never reach here
    // there should be an electricity seller in every world
    assert(0);
}

int has_electricity_for_sale(struct location *l){
    if (strcmp(l->fruit, "Electricity") == 0
       && l->price < 0 
       && l->quantity > 0) {           
           return TRUE;
    }
    else {
        return FALSE;
    }
}
