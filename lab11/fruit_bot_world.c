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
    // Put your code here to:
    // print details of all locations in the Fruit Bot world
    // starting from bot's current location and going east
    
    struct bot *head = b;
    
    struct location *here = b->location;
    
    
    int other = 0;
    
    int price = 0; // buy if 1, sell if 2.
    
    int units = 0; //1 if kg, 2 if kJ.
    
    int absoluteprice = 0;
    

    
    
    
    
    
        if (strcmp(here->fruit, "Nothing") == 0) {
        
            other = 1;
        
        }
        
        
        
        
        if (here->price > 0) {
        
            price = 1;
        
        } else {
        
            price = 2;
        
        }
        
        
        
        
        if (strcmp(here->fruit, "Electricity") == 0) {
        
            units = 2;
        
        } else {
        
            units = 1;
            
        }
        
        
        
        
        
        
        if (other == 1) {
    
            printf("%s: other\n", here->name);
    
        } else if (other == 0) {
        
        
            if (price == 1) {
            
            
                if (units == 1) {
            
                    printf("%s: will buy %d kg of %s for $%d\n", here->name, here->quantity, here->fruit, here->price);
            
            
                } else if (units == 2) {
            
            
            printf("%s: will buy %d kJ of %s for $%d\n", here->name, here->quantity, here->fruit, here->price);
            
            
                }
            
            
            } else if (price == 2) {
        
                absoluteprice = here->price * -1;
        
                if (units == 1) {
            
            printf("%s: will sell %d kg of %s for $%d\n", here->name, here->quantity, here->fruit, absoluteprice);
            
            
                } else if (units == 2) {
            
            
            printf("%s: will sell %d kJ of %s for $%d\n", here->name, here->quantity, here->fruit, absoluteprice);
            
            
                }
        
        
        
        
            }
        
        
        }
        
        
        other = 0;
        
        price = 0;
        
        units = 0;
        
        absoluteprice = 0;
    
    
    
    
 //   printf("%s\n", here->name);
    
    here = here->east;
    
  //  printf("%s\n", head->location->name);
    
    
    
    
    
    
    
    

    
   while ((strcmp(here->name, head->location->name) != 0)){
    
    
      
    
        if (strcmp(here->fruit, "Nothing") == 0) {
        
            other = 1;
        
        }
        
        
        
        
        if (here->price > 0) {
        
            price = 1;
        
        } else {
        
            price = 2;
        
        }
        
        
        
        
        if (strcmp(here->fruit, "Electricity") == 0) {
        
            units = 2;
        
        } else {
        
            units = 1;
            
        }
        
        
        
        
        
        
        if (other == 1) {
    
            printf("%s: other\n", here->name);
    
        } else if (other == 0) {
        
        
            if (price == 1) {
            
            
                if (units == 1) {
            
                    printf("%s: will buy %d kg of %s for $%d\n", here->name, here->quantity, here->fruit, here->price);
            
            
                } else if (units == 2) {
            
            
            printf("%s: will buy %d kJ of %s for $%d\n", here->name, here->quantity, here->fruit, here->price);
            
            
                }
            
            
            } else if (price == 2) {
        
                absoluteprice = here->price * -1;
        
                if (units == 1) {
            
            printf("%s: will sell %d kg of %s for $%d\n", here->name, here->quantity, here->fruit, absoluteprice);
            
            
                } else if (units == 2) {
            
            
            printf("%s: will sell %d kJ of %s for $%d\n", here->name, here->quantity, here->fruit, absoluteprice);
            
            
                }
        
        
        
        
            }
        
        
        }
        
        
        other = 0;
        
        price = 0;
        
        units = 0;
        
        absoluteprice = 0;
    
    
    
    
  //  printf("%s\n", here->name);
    
    here = here->east;
    
   // printf("%s\n", head->location->name);
        
    
    }
    
    
}

