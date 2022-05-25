// intensity.c
// Assignment 2, COMP1511 18s1: Intensity
//
// This program is created by NATHAN DRISCOLL (z5204935) on 24-8-18
//
//This program is an AI intensity player
//
// Version 1.0.1: Minor changes to wording of comments.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2
#define ACTION_UNIT_TESTS     3

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

#define TRUE                 1
#define FALSE                0

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
void run_unit_tests(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void copy_array (int size, int array[], int new_array[]);
void playable_cards (int tens, int size, int source[], int destination[]);
int find_tens (int number);
void find_ones (int source[], int destination[], int size);
int find_lowest (int array[], int size);
int find_highest (int array[], int size);
int find_lowest_in_array (int array[], int size);
int find_highest_in_array (int array[], int size);
int check_array (int source[]);
int check_calves (int source[], int size);
void remove_calves (int source[], int destination[], int size);
int find_buffalo (int source[], int size);
int find_calves (int source[], int size);

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    } else {
        run_unit_tests();
    }

    return 0;
}

void print_player_name(void) {
    printf("Robbo\n");

}

void choose_discards() {
    int cards[N_CARDS_INITIAL_HAND] = {0};
    int to_discard[N_CARDS_INITIAL_HAND] = {0};
    //reads in 10 cards that are dealt
    int i = 0;
    while (i < N_CARDS_INITIAL_HAND) {
        scanf("%d", &cards[i]);
        i = i + 1;
    }
    int counter = 0;
    int counter2 = 9;
    int j = 0;
    while (counter2 > 0) {
        j = 0;
        while (j < N_CARDS_INITIAL_HAND) {
            if (cards[j] % 10 == counter2) {
                to_discard[counter] = cards[j];
                counter = counter + 1;
            }
            j = j + 1;
        }
        counter2 = counter2 - 1;
   }
      
    // DISCARD CARDS FROM YOUR HAND.
    printf("%d, %d, %d\n", to_discard[0], to_discard[1], to_discard[2]);

}

void choose_card_to_play(void) {
    
    //scan in the number of cards in hand
    int cards_in_hand;
    scanf("%d", &cards_in_hand);
    
    //scan in the number of cards played in the round
    int cards_played_in_round;
    scanf("%d", &cards_played_in_round);
    
    //scan in the table position
    int table_position;
    scanf("%d", &table_position);

    //scanning in the cards currently in hand
    int my_cards[cards_in_hand];
    int cards[N_CARDS_INITIAL_HAND] = {-1};
    int i = 0;
    while (i < cards_in_hand) {
        scanf("%d", &my_cards[i]);
        i = i + 1;
    }
    copy_array(cards_in_hand, my_cards, cards);
    
    //scanning in cards played in the round
    int cards_played_round[N_CARDS_INITIAL_HAND]; 
    if (cards_played_in_round > 0) {     
        int k = 0;
        while (k < cards_played_in_round) {
            scanf("%d", &cards_played_round[k]);
            k = k + 1;
        }
    }
    //scanning in cards played in history of game
    int number_of_cards_played_in_history = (10 - cards_in_hand) * 4 + cards_played_in_round;
    int cards_played_history[N_CARDS] = {0};
    int j = 0;
    while (j < number_of_cards_played_in_history) {
        assert(scanf("%d", &cards_played_history[j]) == 1);
        j = j + 1;
    }

    //scan in the 3 cards discarded by player
    int counter = 0;
    int discarded[3];
    while (counter < 3) {
        scanf("%d", &discarded[counter]);
        counter = counter + 1;
    }
    
    //scan in 3 cards gained by player
    counter = 0;
    int gained[3];
    while (counter < 3) {
        scanf("%d", &gained[counter]);
        counter = counter + 1;
    }
    //if i am going first, play a card ending in low number
    //array to store ones of cards in hand
    int cards_ones[N_CARDS_INITIAL_HAND] = {-1};
    int no_calves[N_CARDS_INITIAL_HAND] = {-1};
    int card_to_play = 5;
    int position_in_array = 0;
    if (cards_played_in_round == 0) {
        //check if calves played in game yet
        if (check_calves(cards_played_history, N_CARDS) == FALSE) {
            remove_calves(cards, no_calves, N_CARDS_INITIAL_HAND);
            find_ones(no_calves, cards_ones, N_CARDS_INITIAL_HAND);
            position_in_array = find_lowest_in_array(cards_ones,  N_CARDS_INITIAL_HAND);
        card_to_play = cards[position_in_array];
        printf("%d\n", card_to_play);
        } else {
              find_ones(cards, cards_ones, N_CARDS_INITIAL_HAND);
              position_in_array = find_lowest_in_array(cards_ones, N_CARDS_INITIAL_HAND);
              card_to_play = cards[position_in_array];
              printf("%d\n", card_to_play);
          }
    }
    
    //if not going first, play a card that matches the first number of the 
    //first card played and also ending in a low number   
    int tens = 0;
    int new_deck[N_CARDS_INITIAL_HAND] = {0};  
    if (cards_played_in_round > 0) {
        tens = find_tens(cards_played_round[0]);
        //find all the cards I can play and put them in new_deck
        playable_cards(tens, N_CARDS_INITIAL_HAND, cards, new_deck);
        
        //if i can play a card
        if (check_array(new_deck) == TRUE) {
            card_to_play = find_lowest(new_deck, N_CARDS_INITIAL_HAND);
            printf("%d\n", card_to_play);
        }
        //if i cannot play a card, play the highest ones in my deck
        if (check_array(new_deck) == FALSE) {
            //if i have buffalo - play it
            if (find_buffalo(cards,N_CARDS_INITIAL_HAND) != FALSE) {
                card_to_play = find_buffalo(cards, N_CARDS_INITIAL_HAND);
                printf("%d", card_to_play);
              // if i have a calf, play my highest one
            } else if (find_calves(cards, N_CARDS_INITIAL_HAND) != FALSE) {
                  card_to_play = find_calves(cards, N_CARDS_INITIAL_HAND);
                  printf("%d\n", card_to_play);
              } else {
                  find_ones(cards, cards_ones, N_CARDS_INITIAL_HAND);
                  position_in_array = find_highest_in_array(cards_ones, N_CARDS_INITIAL_HAND);
                  card_to_play = cards[position_in_array];
                  printf("%d\n", card_to_play);
             }
        }
    }
}


// ADD A COMMENT HERE EXPLAINING YOUR OVERALL TESTING STRATEGY

void run_unit_tests(void) {
    // PUT YOUR UNIT TESTS HERE
}


// ADD YOUR FUNCTIONS HERE
void copy_array (int size, int source[], int destination[]) {
    int i = 0;
    while (i < size) {
        destination[i] = source[i];
        i = i + 1;
    }
}

    //find all cards in the 30's and put them in an array
void playable_cards (int tens, int size, int source[], int destination[]) {   
    int counter = 0;
    int counter2 = 0;
    while (counter < size) {
        if (find_tens(source[counter]) == tens) {
            destination[counter2] = source[counter];
            counter2 = counter2 + 1;
        }
        counter = counter + 1;
    }
}
//finds the tens of a number
int find_tens (int number) {
    int tens;
    tens = (number / 10);
    return tens;
}
//finds the ones of an array and put them in another array
void find_ones (int source[], int destination[], int size) {
    int i = 0;
    while (i < size) {
        if (source[i] != -1) {
            destination[i] = source[i] % 10;
        }
        i = i + 1;
    }
}

//finds the lowest number in an array
int find_lowest (int array[], int size) {
    int counter = 0;
    int lowest = 50;
    while (counter < size) {
        if (array[counter] < lowest && array[counter] != 0) {
            lowest = array[counter];
        }
        counter = counter + 1;  
    }
    return lowest;
}

//finds the highest number in an array
int find_highest (int array[], int size) {
    int counter = 0;
    int highest = 0;
    while (counter < size) {
        if (array[counter] > highest && array[counter] != 0) {
            highest = array[counter];
        }
        counter = counter + 1;  
    }
    return highest;
}

//find the position of the lowest number in an array
int find_lowest_in_array (int array[], int size) {
    int counter = 0;
    int lowest = 50;
    int position = 0;
    while (counter < size) {
        if (array[counter] <= lowest && (array[counter] != -1)) {
            lowest = array[counter];
            position = counter;
        }
        counter = counter + 1;  
    }
    return position;
}  

//find the position of the highest number in an array
int find_highest_in_array (int array[], int size) {
    int counter = 0;
    int highest = 0;
    int position = 0;
    while (counter < size) {
        if (array[counter] >= highest) {
            highest = array[counter];
            position = counter;
        }
        counter = counter + 1;  
    }
    return position;
}

//check if there is any data in an array
int check_array (int source[]) {
    int i = 0;
    
    while (i < N_CARDS_INITIAL_HAND) {
        if (source[i] > 0) {
            return TRUE;
        }
        i = i + 1;
    }
    return FALSE;
}

//if there is a calf in the array, return TRUE, if not return FALSE           
int check_calves (int source[], int size) {
    int i = 0;
    while (i < size) {
        if (source[i] >= 30 && source[i] <= 39) {
            return TRUE;
        }
        i = i + 1;
    }
    return FALSE;
}

//create a new deck without calves in it
void remove_calves (int source[], int destination[], int size) {
    int counter = 0;
    while (counter < size) {
        if (source[counter]>= 30 && source[counter] <= 39) {
            destination[counter] = -1;
        } else {
              destination[counter] = source[counter];
          }
        counter = counter + 1;
    }
}

//find the buffalo - if found, return 47
int find_buffalo (int source[], int size) {
    int i = 0;
    while (i < size) {
        if (source[i] == 47) {
            return 47;
        }
        i = i + 1;
    }
    return FALSE;
}

int find_calves (int source[], int size) {
    int calves[N_CARDS_INITIAL_HAND] = {0};
    int calves_counter = 0;
    //find all calves greater than 35 in deck and put them into another array
    int i = 0;
    while (i < size) {
        if (source[i] >= 35 && source[i] <= 39) {
            calves[calves_counter] = source[i];
            calves_counter = calves_counter + 1;
        }
        i = i + 1;
    }
    if (calves[0] == 0) {
        return FALSE;
    }
    int highest_calf = find_highest(calves, N_CARDS_INITIAL_HAND);
    return highest_calf;
}
