// intensity.c
// Assignment 2, COMP1511 18s1: Intensity
//
// This program is created by NATHAN DRISCOLL (z5204935) on 24-8-18
//
//This program is an AI intensity player. The aim of this player is to never win a 
//round. It will discard cards with the highest second number from its deck. When
//playing, it will try to play the highest card in its deck under cards already
//played. If not, it will play the lowest remaining playable card. If there are no playable cards, a buffalo then calves will be attempted to be played and if it
//doesn't have them, the card with the highest second number in the deck will be 
//played
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
#define CARDS_PER_ROUND      4 
#define BUFFALO              47
#define FIRST_CALF           30
#define MIDWAY_CALF          35
#define LAST_CALF            39

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
void run_unit_tests(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
void copy_array (int size, int array[], int new_array[]);
void playable_cards (int tens, int size, int source[], int destination[]);
int find_tens (int number);
void find_ones (int source[], int destination[], int size);
int pick_a_card (int tens, int cards_played_in_round, int cards_played_round[],
int new_deck[], int size);
int find_lowest (int array[], int size);
int find_highest (int array[], int size);
int find_lowest_in_array (int array[], int size);
int find_highest_in_array (int array[], int size);
int check_array (int source[], int size);
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
    printf("Robbo2\n");

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
    int cards[N_CARDS_INITIAL_HAND];
    int i = 0;
    while(i < N_CARDS_INITIAL_HAND) {
        cards[i] = -1;
        i = i + 1;
    }
    i = 0;
    while (i < cards_in_hand) {
        scanf("%d", &my_cards[i]);
        i = i + 1;
    }
    copy_array(cards_in_hand, my_cards, cards);
    
    //scanning in cards played in the round
    int cards_played_round[CARDS_PER_ROUND] = {0}; 
    if (cards_played_in_round > 0) {     
        int k = 0;
        while (k < cards_played_in_round) {
            scanf("%d", &cards_played_round[k]);
            k = k + 1;
        }
    }
    //scanning in cards played in history of game
    int number_of_cards_played_in_history = (10 - cards_in_hand) * 4 +
    cards_played_in_round;
    int cards_played_history[N_CARDS] = {0};
    int j = 0;
    while (j < number_of_cards_played_in_history) {
        scanf("%d", &cards_played_history[j]);
        j = j + 1;
    }

    //scan in the 3 cards discarded by player
    int counter = 0;
    int discarded[CARDS_PER_ROUND - 1];
    while (counter < (CARDS_PER_ROUND - 1)) {
        scanf("%d", &discarded[counter]);
        counter = counter + 1;
    }
    
    //scan in 3 cards gained by player
    counter = 0;
    int gained[CARDS_PER_ROUND - 1];
    while (counter < (CARDS_PER_ROUND - 1)) {
        scanf("%d", &gained[counter]);
        counter = counter + 1;
    }
    //if i am going first, play a card ending in low number
    //array to store ones of cards in hand
    int cards_ones[N_CARDS_INITIAL_HAND];
    //array to store a deck without calves
    int no_calves[N_CARDS_INITIAL_HAND];
    //initialise both arrays to -1
    int x = 0;
    while (x < N_CARDS_INITIAL_HAND) {
        cards_ones[x] = -1;
        no_calves[x] = -1;
        x = x + 1;
    }    
    int card_to_play = 0;
    int position_in_array = 0;
    if (cards_played_in_round == 0) {
        //check if calves played in game yet
        //if they haven't remove all calves from deck, and play
        //card with the lowest second number
        if (check_calves(cards_played_history, N_CARDS) == FALSE) {
            remove_calves(cards, no_calves, N_CARDS_INITIAL_HAND);
            find_ones(no_calves, cards_ones, N_CARDS_INITIAL_HAND);
            position_in_array = find_lowest_in_array(cards_ones,
            N_CARDS_INITIAL_HAND);
            card_to_play = cards[position_in_array];
            printf("%d\n", card_to_play);
        //if a calf has been played, play card with lowest second number 
        } else {
            find_ones(cards, cards_ones, N_CARDS_INITIAL_HAND);      
            position_in_array = find_lowest_in_array(cards_ones,
            N_CARDS_INITIAL_HAND);
            card_to_play = cards[position_in_array];
            printf("%d\n", card_to_play);
          }
    }
    
    //if not going first, play a card that matches the first number of the 
    //first card played 
    int tens = 0;
    int new_deck[N_CARDS_INITIAL_HAND] = {0};  
    if (cards_played_in_round > 0) {
        tens = find_tens(cards_played_round[0]);
        //find all the cards I can play and put them in new_deck
        playable_cards(tens, N_CARDS_INITIAL_HAND, cards, new_deck);
        
        //if i can play a card
        //play my highest card under the highest card in play, else, 
        //play the lowest card above it
        if (check_array(new_deck, N_CARDS_INITIAL_HAND) == TRUE) {
            card_to_play = pick_a_card(tens, cards_played_in_round,
            cards_played_round, new_deck, N_CARDS_INITIAL_HAND);
            printf("%d\n", card_to_play);      
        }
        //if i cannot play a card
        if (check_array(new_deck, N_CARDS_INITIAL_HAND) == FALSE) {
            //if i have buffalo - play it
            if (find_buffalo(cards,N_CARDS_INITIAL_HAND) != FALSE) {
                card_to_play = find_buffalo(cards, N_CARDS_INITIAL_HAND);
                printf("%d", card_to_play);
              // if i have a calf, play highest one
            } else if (find_calves(cards, N_CARDS_INITIAL_HAND) != FALSE) {
                card_to_play = find_calves(cards, N_CARDS_INITIAL_HAND);
                printf("%d\n", card_to_play);
                //if i have neither, play card with the highest second number
            } else {
                find_ones(cards, cards_ones, N_CARDS_INITIAL_HAND);
                position_in_array = find_highest_in_array(cards_ones,
                N_CARDS_INITIAL_HAND);
                card_to_play = cards[position_in_array];
                printf("%d\n", card_to_play);
            }
        }
    }
}

//TESTING STRATEGY - Test all functions that return a value to ensure that
//the function returns correct output making sure that the function behaves
//correctly

void run_unit_tests(void) {
    //random deck
    int test_array1[N_CARDS_INITIAL_HAND] = 
    {10, 12, 15, 23, 27, 35, 36, 37, 47, 49};
    //random cards in my hand
    int test_array2[N_CARDS_INITIAL_HAND] = {10, 12, 15};
    int test_array3[N_CARDS_INITIAL_HAND] = {47, 49};
    //random cards played in round
    int test_array4[CARDS_PER_ROUND - 1] = {13, 32, 33};
    int test_array5[CARDS_PER_ROUND - 1] = {40, 42, 33};
    int test_array6[N_CARDS_INITIAL_HAND] = {0};
    //test find_tens function
    assert(find_tens(35) == 3);
    assert(find_tens(30) == 3);
    assert(find_tens(29) == 2);
    assert(find_tens(0) == 0);
    //test pick_a_card function
    assert(pick_a_card(1, 3, test_array4, test_array2, 
    N_CARDS_INITIAL_HAND) == 12);
    assert(pick_a_card(4, 2, test_array5, test_array3, 
    N_CARDS_INITIAL_HAND) == 47);
    //test to find lowest in an array
    assert(find_lowest(test_array1, N_CARDS_INITIAL_HAND) == 10);
    assert(find_lowest(test_array2, 3) == 10);
    assert(find_lowest(test_array3, 2) == 47);
    assert(find_lowest(test_array4, 3) == 13);
    assert(find_lowest(test_array5, 3) == 33);
    //test to find highest in an array
    assert(find_highest(test_array1, N_CARDS_INITIAL_HAND) == 49);
    assert(find_highest(test_array2, 3) == 15);
    assert(find_highest(test_array3, 2) == 49);
    assert(find_highest(test_array4, 3) == 33);
    assert(find_highest(test_array5, 3) == 42);
    //test to find position of lowest in an array
    assert(find_lowest_in_array(test_array1, N_CARDS_INITIAL_HAND) == 0);
    assert(find_lowest_in_array(test_array2, 3) == 0);
    assert(find_lowest_in_array(test_array4, 3) == 0);
    //test to find position of highest in an array
    assert(find_highest_in_array(test_array1, N_CARDS_INITIAL_HAND) == 9);
    assert(find_highest_in_array(test_array2, 3) == 2);
    assert(find_highest_in_array(test_array4, 3) == 2);
    //test check_array function
    assert(check_array(test_array1, N_CARDS_INITIAL_HAND) == TRUE);
    assert(check_array(test_array5, 3) == TRUE);
    assert(check_array(test_array6, N_CARDS_INITIAL_HAND) == FALSE);
    //test check_calves function
    assert(check_calves (test_array1, N_CARDS_INITIAL_HAND) == TRUE);
    assert(check_calves (test_array2, 3) == FALSE);
    //test find_buffalo function
    assert(find_buffalo(test_array1, N_CARDS_INITIAL_HAND) == BUFFALO);
    assert(find_buffalo(test_array2, 3) == FALSE);
    assert(find_buffalo(test_array3, 2) == BUFFALO);
    //test find_calves function
    assert(find_calves(test_array1, N_CARDS_INITIAL_HAND) == 37);
    assert(find_calves(test_array2, 3) == FALSE);
}

//ADD FUNCTIONS HERE

//this function copys an array into another array
void copy_array (int size, int source[], int destination[]) {
    int i = 0;
    while (i < size) {
        destination[i] = source[i];
        i = i + 1;
    }
}

//finds the tens of a number
int find_tens (int number) {
    int tens;
    tens = (number / 10);
    return tens;
}

    //find all cards in a specific tens range and put them in an array
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

//this function finds the highest card that has been played in the round and then
//picks the highest playable card under it. 
//If there are no cards under the highest card played in the round,
//it will play the lowest playable card
int pick_a_card (int tens, int cards_played_in_round, int cards_played_round[], int new_deck[], int size) {
    //new_deck has playable cards for this round in it
    //new_deck is copied into temp_deck
    int temp_deck[N_CARDS_INITIAL_HAND] = {0};
    copy_array(N_CARDS_INITIAL_HAND, new_deck, temp_deck);
    int highest_card_in_play = 0;
    int card_to_play = 0;
    //find the highest card that is in play in this round
    int i = 0;
    while (i < cards_played_in_round) {
        if ((find_tens(cards_played_round[i]) == tens) && (cards_played_round[i] >
        highest_card_in_play)) {
            highest_card_in_play = cards_played_round[i];
        }
        i = i + 1;
    }
    //find all the cards which are under the highest card in play
    i = 0;
    int temp_deck_counter = 0;
    while (i < size) {
        if (new_deck[i] < highest_card_in_play) {
            temp_deck[temp_deck_counter] = new_deck[i];
            temp_deck_counter = temp_deck_counter + 1;
        }
        i = i + 1;
    }
    //if there is something in temp_deck (ie there are cards under the highest card 
    //in play), play the highest one
    if (check_array(temp_deck, N_CARDS_INITIAL_HAND) == TRUE) {
        card_to_play = find_highest(temp_deck, N_CARDS_INITIAL_HAND);
        return card_to_play;
    //if not, play the lowest in new_deck
    } else {
          card_to_play = find_lowest(new_deck, N_CARDS_INITIAL_HAND);
          return card_to_play;
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
int check_array (int source[], int size) {
    int i = 0;
    
    while (i < size) {
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
        if (source[counter]>= FIRST_CALF && source[counter] <= LAST_CALF) {
            destination[counter] = -1;
        } else {
              destination[counter] = source[counter];
          }
        counter = counter + 1;
    }
}

//find the buffalo - if found, return BUFFALO
int find_buffalo (int source[], int size) {
    int i = 0;
    while (i < size) {
        if (source[i] == BUFFALO) {
            return BUFFALO;
        }
        i = i + 1;
    }
    return FALSE;
}
//this function finds high calves (calves >= 35 <=39) and puts them in an array. 
//It then returns the highest calf
int find_calves (int source[], int size) {
    int calves[N_CARDS_INITIAL_HAND] = {0};
    int calves_counter = 0;
    //find all calves greater than 35 in deck and put them into another array
    int i = 0;
    while (i < size) {
        if (source[i] >= MIDWAY_CALF && source[i] <= LAST_CALF) {
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
