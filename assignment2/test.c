#define N_CARDS_INITIAL_HAND 10
#include <stdio.h>
#define TRUE 1
#define FALSE 0
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

void find_ones (int source[], int destination[], int size) {
    int i = 0;
    while (i < size) {
        if (source[i] != -1) {
            destination[i] = source[i] % 10;
        }
        i = i + 1;
    }
}

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



int main (void) {
int cards_played_history[10] = {12, 11 ,23, 25, 26, 23, 29 ,30 ,29, 10};
int cards[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int no_calves[10] = {-1};
int cards_ones[10] = {-1};
if (check_calves(cards_played_history, 10) == FALSE) {
            remove_calves(cards, no_calves, N_CARDS_INITIAL_HAND);
            find_ones(no_calves, cards_ones, N_CARDS_INITIAL_HAND);
            int position_in_array = find_lowest_in_array(cards_ones,  N_CARDS_INITIAL_HAND);
        int card_to_play = cards[position_in_array];
        printf("%d\n", card_to_play);
        }
        return 0;
}
