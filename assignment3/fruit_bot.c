// fruit_bot.c
// Assignment 3, COMP1511 18s1: Fruit Bot
//
// This program by Nathan Driscoll (z5204935) on 23/5/2018
//
// This program is an AI fruit bot that travels around a simulated 
// world and buys and sells fruit in an attempt to make a profit
// The bot will buy from the nearest seller and then sell the fruit 
// at the location which offers the highest price for the fruit on board
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: minor bug in main fixed

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "fruit_bot.h"

#define TRUE 1
#define FALSE 0

void print_player_name(void);
void print_move(struct bot *b);
void run_unit_tests(void);

// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void recharge_battery (struct bot *b, struct location *current);
void buy_fruit (struct bot *b, struct location *current);
int nearest_electricity (struct bot *b);
int nearest_fruit (struct bot *b);
int highest_price_for_fruit (struct bot *b);
int has_electricity_for_sale(struct location *l);
int has_fruit_for_sale(struct location *l);
int will_buy_fruit(struct bot *b, struct location *l);
int will_buy_anything(struct location *l);
int sellers_available (char *fruit, struct bot *b);

int main(int argc, char *argv[]) {

    if (argc > 1) {
        // supply any command-line argument to run unit tests
        run_unit_tests();
        return 0;
    }

    struct bot *me = fruit_bot_input(stdin);
    if (me == NULL) {
        print_player_name();
    } else {
        print_move(me);
    }

    return 0;
}

void print_player_name(void) {
    printf("Mr Bot2\n");

}

void print_move(struct bot *b) {
    
    int move_counter = 0;
    int distance_to_travel = 0; 
    struct location *current = b -> location;
    
    // if its the last or second last turn just sell whatever is in inventory  
    if (b -> turns_left <= 2) {
        printf("Sell %d", b -> maximum_fruit_kg);
        return;
    }
    
    // if the battery is below 1/3 capacity, move to a charging station 
    // if at a charging station, consume electricity   
    // cash level must be above 100 so that if the bot is low on money
    // and wants to sell, it can do that first
    if (b -> battery_level < (b -> battery_capacity / 3) 
        && b-> cash > 100) {             
        distance_to_travel = nearest_electricity(b);   
        // if we are at a location that sells electricity, buy the maximum 
        // amount of electricity allowed
        if (distance_to_travel == 0) {
            printf("Buy %d", b -> battery_capacity);
            return;
        }    
        //if not, move to the closest location that sells electricity
        if (distance_to_travel != 0) {
            printf("Move %d", distance_to_travel);
            return;
        }
    }
    
    // if fruit inventory is empty, move to the nearest location that
    // sells fruit. If currently at that location, buy the max amount
    if (b -> fruit_kg == 0) {
        //buy_fruit(b, current);     
        distance_to_travel = nearest_fruit(b);
        if (distance_to_travel == 0) {
            printf("Buy %d", b -> maximum_fruit_kg);
            return;
        }
        if (distance_to_travel != 0) {
            printf("Move %d", distance_to_travel);
            return;
        }
    }
    
    // if there is something in fruit inventory, move to the location 
    // with the highest buying price. If currently at that location,
    // sell max fruit that can be inventory
    if (b -> fruit_kg > 0) {
        distance_to_travel = highest_price_for_fruit(b);
        if (distance_to_travel == 0) {
            printf("Sell %d", b -> maximum_fruit_kg);
            return;
        }
        if (distance_to_travel != 0) {
            printf("Move %d", distance_to_travel);
            return;
        }
    }
}

// OVERALL TESTING STRATEGY
// Test by running bot in many different worlds and checking performance. 
// If bot becomes stuck in an infinite loop or bot does wrong action, use 
// printfs to stderr to find where the problem is. Test individual functions
// usinng unit tests with bot and location structs created by me to test that
// individual functions return correct values when given certain input

void run_unit_tests(void) {
    // test has_electricty_for_sale function  
    // create a location that sells electricity
    struct location *e = malloc(sizeof(struct location));
    assert (e != NULL); //check malloc worked
    e -> fruit = "Electricity";
    e -> quantity = 50;
    e -> price = -10;
    assert(has_electricity_for_sale(e) == TRUE);
    // change fruit to apples so now has_electricty_for_sale should return FALSE
    e -> fruit = "Apples";
    assert(has_electricity_for_sale(e) == FALSE);
    
    // test has_fruit_for_sale function
    // create a struct location that sells fruit
    struct location *f = malloc(sizeof(struct location));
    assert (f != NULL);
    f -> fruit = "Apples";
    f -> quantity = 50;
    f -> price = -10;
    assert(has_fruit_for_sale(f) == TRUE);
    // at quantity 0, should return FALSE
    f -> quantity = 0;
    assert(has_fruit_for_sale(f) == FALSE);
    f -> quantity = 50;
    // positive price means that the location is buying and not selling
    f -> price = 20;
    assert(has_fruit_for_sale(f) == FALSE);
    
    // test will_buy_fruit function
    // create a struct bot
    struct bot *b = malloc(sizeof(struct bot));
    b -> fruit = "Apples";
    assert(will_buy_fruit(b, f) == TRUE);
    // change price to negative so now location is a seller
    f -> price = -20;
    assert(will_buy_fruit(b, f) == FALSE);
    
    // test will_buy_anything function
    f -> fruit = "Anything";
    assert(will_buy_anything(f) == TRUE);
    // change fruit to apples so now fruit is not "Anything"
    f -> fruit = "Apples";
    assert(will_buy_anything(f) == FALSE);
}


// ADD YOUR FUNCTIONS HERE

// some functions have been taken from the lab solutions 
// for the week 11 lab and modified

// this function returns distance to nearest electricity
// if nearest electricity is west return negative int
// if nearest electricity is current location return 0    
int nearest_electricity (struct bot *b) {

    struct location *start = b -> location;
    struct location *eastwards = b -> location;
    struct location *westwards = b -> location;
    int distance = 0;
    while (distance == 0 || eastwards != start) {
        if (has_electricity_for_sale(eastwards) == TRUE) {
            return distance;
        }
        if (has_electricity_for_sale(westwards) == TRUE) {
            return -distance;
        }
        eastwards = eastwards -> east;
        westwards = westwards -> west;
        distance = distance + 1;
    }
    // this point should never be reached as there should be an electricity
    // seller in every world
    return 0;
}

// return the distance to the nearest location that sells fruit (which isn't
// electricity) which has a buyer (not "Anything")
int nearest_fruit (struct bot *b) {
    struct location *start = b -> location;
    struct location *eastwards = b -> location;
    struct location *westwards = b -> location;
    int distance = 0;
    while (distance == 0 || eastwards != start) {
        if (has_fruit_for_sale(eastwards) == TRUE 
           && sellers_available(eastwards -> fruit, b) == TRUE) {
            return distance;
        }
        if (has_fruit_for_sale(westwards) == TRUE
           && sellers_available(westwards -> fruit, b) == TRUE) {
            return -distance;
        }
        eastwards = eastwards -> east;
        westwards = westwards -> west;
        distance = distance + 1;
    }
    return 0; //will get here when theres no fruit (should never reach)
}

// return the shortest distance to the location which offers the highest
// price for whatever fruit is in inventory
int highest_price_for_fruit (struct bot *b) {
    int east_highest_price = 0;
    int west_highest_price = 0;
    int eastwards_distance = 0;
    int westwards_distance = 0;
    struct location *start = b->location;
    struct location *eastwards = b->location;
    struct location *westwards = b->location;
    int distance = 0;
    // make 120 the maximum size the maximum distance the bot will travel
    // so it doesn't spend too much time travelling 
    while ((distance == 0 || eastwards != start) && distance < 120) {
        if (((will_buy_fruit(b, eastwards) == TRUE) || 
            will_buy_anything(eastwards)) &&
            (eastwards -> price > east_highest_price)) {
            east_highest_price = eastwards -> price;
            eastwards_distance = distance;
        }
        if (((will_buy_fruit(b, westwards) == TRUE) || 
           will_buy_anything(westwards)) &&
           (westwards -> price > west_highest_price)) {
           west_highest_price = westwards -> price;
           westwards_distance = distance;
        }
        eastwards = eastwards -> east;
        westwards = westwards -> west;
        distance = distance + 1;
    }
    // Whichever distance is lower, return that distance. 
    // If the same, just return the eastwards distance
    if (eastwards_distance < westwards_distance) {
        return eastwards_distance;
    }
    else if (eastwards_distance > westwards_distance) {
        return -westwards_distance;
    }
    else if (eastwards_distance == westwards_distance) {
        return eastwards_distance;
    }
    else {
        return 0;
    }
}

// if there is electricity for sale, return TRUE
// if not, return FALSE
int has_electricity_for_sale(struct location *l) {
    if (strcmp(l->fruit, "Electricity") == 0
       && l -> price < 0 && l -> quantity > 0) {           
        return TRUE;
    } else {
        return FALSE;
    }
}

// if the fruit is not electricity, and available to buy return TRUE
// if not, return FALSE
int has_fruit_for_sale(struct location *l) {
    if (strcmp(l -> fruit, "Electricity") != 0
       && l -> price < 0 && l -> quantity > 0) {           
        return TRUE;
    } else {
        return FALSE;
    }
}

// if this is a location that buys the fruit on board the bot, return TRUE
// if not, return false
int will_buy_fruit(struct bot *b, struct location *l) {
    if (strcmp(l -> fruit, b -> fruit) == 0
       && l -> price > 0 && l -> quantity > 0) {           
        return TRUE;
    } else {
        return FALSE;
    }
}

// if this location has fruit "Anything", return TRUE
// if not, return FALSE
int will_buy_anything(struct location *l) {
    if (strcmp(l -> fruit, "Anything") == 0) {           
        return TRUE;
    } else {
        return FALSE;
    }
}

// if there is a location that will buy the fruit that isn't "Anything"
// return TRUE. If not, return FALSE
int sellers_available (char *fruit, struct bot *b) {
    struct location *eastwards = b -> location;
    int distance = 0;
    while (distance == 0 || eastwards != b -> location) {
        if (fruit == eastwards -> fruit == 0
            && eastwards -> price > 0 && eastwards -> quantity > 0) {           
            return TRUE;
        }
        eastwards = eastwards -> east;
    }
    return FALSE;
}

        
        
        
