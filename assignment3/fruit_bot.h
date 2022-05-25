// DO NOT CHANGE THIS FILE
// DO NOT ADD LINES TO THIS FILE
// DO NOT DELETE LINES FROM THIS FILE
// DO NOT CHANGE THIS FILE

// Fruit Bot - https://cgi.unsw.edu.au/~cs1511/assignments/ass3/

// header guard: https://en.wikipedia.org/wiki/Include_guard
// This avoids errors if this file is included multiple times
// in a complex source file setup

#ifndef FRUIT_BOT_H
#define FRUIT_BOT_H

// These constants are upper bounds on various features of the Fruit Bot world
// You may not need to use any of these constants in your program.

#define MAX_TURNS                         999
#define MAX_LOCATIONS                     2048
#define MAX_BOTS                          2048
#define MAX_FRUIT_TYPES                   128
#define MAX_NAME_CHARS                    64
#define MAX_SUPPLIED_BOT_NAME_CHARS       32


// Description of the state of a single bot
//
//  name - unique string of between 1 and MAX_NAME_CHARS (does not change during simulation)
//
//  location - pointer to struct representing bot's current location, never NULL
//
//  cash - how much cash the bot has
//
//  battery_level - how many kJ in the bot's battery - reduces by 1 kJ for every location bot moves
//
//  fruit - name of the fruit bot is carrying (between 1 and MAX_NAME_CHARS)
//          note bots may only carry one type of fruit at a time
//          NULL if the bot is not carrying fruit
//
//  fruit_kg - how many kg of fruit the bot is carrying
//
//  turns_left - turns left in simulation, always > 0 (reduces by 1 every turn)
//
//  battery_capacity - maximum kJ bot's battery can hold
//
//  maximum_move - maximum number of location bot can move
//
//  maximum_fruit_kg - maximum kg of fruit bot can carry
//
//  battery_capacity, maximum_fruit_kg, maximum_move are the same for all bots
//  and do not change during the simulation.
//
//  name is different for every bot and does not change during the simulation

struct bot {
    char            *name;
    struct location *location;
    int             cash;
    int             battery_level;
    char            *fruit;
    int             fruit_kg;
    int             turns_left;
    int             battery_capacity;
    int             maximum_move;
    int             maximum_fruit_kg;
};


// Description of a location in the fruit bot world
//
//  name - unique string of between 1 and MAX_NAME_CHARS (never NULL)
//
//  fruit - name of the fruit this location buys/sells
//          string of between 1 and MAX_NAME_CHARS (never NULL)
//          if fruit == "Anything" location buys any fruit
//          fruit == "Electricity" is a special case, bots can recharge by buying electricity
//          note some locations have fruit == "Nothing" and price == 0 & quantity  == 0
//
//  price -  price at which this location sells/buys a kg of fruit or, kJ of electricity
//           a positive price indicates this location only buys fruit
//           a negative price indicates this location only sells fruit or electricity
//           a price of zero indicates location does not buy or sell anything
//           price does not change during the simulation
//
//  quantity - a non-negative number indicating how many units of fruit/electricity
//             this location currently has available to buy or sell
//             quantity never increases during the simulation
//             it reduces by n kg/kJ when a bot buy/sells n kg/kJ at this location
//
//  bots - pointer to a linked list of bots currently at this location (NULL if no bots at this location)
//
//
//  east - pointer to struct representing next location east, never NULL
//         The east fields of locations link them in a circular list
//
//  west - pointer to struct representing next location west, never NULL
//         The west fields of locations link them in a circular list
//         but in the reverse direction to east fields.
//

struct location {
    char                *name;
    char                *fruit;
    int                 price;
    int                 quantity;
    struct location     *east;
    struct location     *west;
    struct bot_list     *bots;
};



// linked list of bots
//
// bot - pointer to a struct representing a bot
//
// next - points to remainder of list
//        next is NULL if there are no more bots in list

struct bot_list {
    struct bot      *bot;
    struct bot_list *next;
};


struct bot *fruit_bot_input(FILE *stream);

#endif
