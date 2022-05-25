#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "fruit_bot.h"

void print_player_name(void);
void print_move(struct bot *b);

int main(int argc, char *argv[]) {
    struct bot *me = fruit_bot_input(stdin);
    if (me == NULL) {
        print_player_name();
    } else {
        print_move(me);
    }

    return 0;
}

void print_player_name(void) {
    printf("Mr Bot");

}

// print_move - should print a single line indicating
//              the move you bot wishes to make
//
// This line should contain only the word Move, Sell or Buy
// followed by a single integer

void print_move(struct bot *b) {
    // ADD YOUR CODE HERE
    
    struct bot *here = b;
    
    int travel = 0;
    
    int stay = 0;
    
    if (strcmp("Apples", here->location->fruit) == 0) {
    
        if (here->location->price < 0) {
        
            if (here->location->quantity == 0) {
            
                travel = 1;
                
            } else if (here->fruit != NULL) {
            
                if (strcmp(here->fruit, "Apples") != 0) {
                
                    travel = 1;
                
                }
            
            } else {
                
                stay = here->location->quantity;
                
                if (here->location->quantity > 20) {
                
                    stay = 20;
                
                }
                
                printf("Buy %d\n", stay);
            
            }
        
        } else if (here->location->price > 0) {
        
            if (here->location->quantity == 0) {
            
                travel = 1;
            
            } else if (here->fruit_kg == 0) {
            
                travel = 1;
            
            } else {
        
                printf("Sell %d\n", here->fruit_kg);
                
            }
        
        }
    
    } else if (strcmp("Electricity", here->location->fruit) == 0) {
        
            if (here->location->quantity == 0) {
            
                travel = 1;
            
            } else if (here->battery_level == 100) {
            
                travel = 1;
            
            } else {
        
                printf("Buy %d\n", 100 - here->battery_level);
            }
    
    } else {
    
        printf("Move -%d\n", here->maximum_move);
    
    }
    
    if (travel == 1) {
    
        printf("Move -%d\n", here->maximum_move);
    
    }
    
    
    
    
}

