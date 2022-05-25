#include <stdio.h>
#define N_CARDS_INITIAL_HAND 10

void find_ones (int source[], int destination[], int size) {
    int i = 0;
    while (i < size) {
        destination[i] = source[i] % 10;
        i = i + 1;
    }
}
int find_lowest_in_array (int array[], int size) {
    int counter = 0;
    int position = 0;
    int lowest = 50;
    while (counter < size) {
        if (array[counter] <= lowest && array[counter] != -1) {
            lowest = array[counter];
            position = counter;   
        }
        counter = counter + 1;         
    }
    return position;
}  
int check_calves (int source[], int size) {
    int i = 0;
    while (i < size) {
        if (source[i] >= 30 && source[i] <= 39) {
            return 7000;
        }
        i = i + 1;
    }
    return 42;
}

int main (void) {



    int size = 10;
    int cards[10] = {15, 10, 25, 28, -1, 27, 16, 25, 49, 45};
    int cards_ones[10] = {-1};
   
   int f = check_calves(cards,10);
   printf("%d\n",f);
    find_ones(cards, cards_ones, N_CARDS_INITIAL_HAND);
    
        int position_in_array = find_lowest_in_array(cards_ones, N_CARDS_INITIAL_HAND);
        int card_to_play = cards[position_in_array];
        printf("%d\n", card_to_play);
        
    return 0;
}
