// time2code.c
// Assignment 1, COMP1511 18s1: Time To Code.
//
// This program by NATHAN DRISCOLL (z5204935) on 2/04/2018
//
// Version 1.0.2: Add version numbers and header comment.
// Version 1.0.1: Fix day/time variable mix-up in main function.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <assert.h> 

// You must use these #defines - DO NOT CHANGE THEM

#define TOWN_ADELAIDE       0
#define TOWN_BRISBANE       1
#define TOWN_BROKEN_HILL    2
#define TOWN_CANBERRA       3
#define TOWN_DARWIN         4
#define TOWN_EUCLA          5
#define TOWN_HOBART         6
#define TOWN_LORD_HOWE_IS   7
#define TOWN_MELBOURNE      8
#define TOWN_PERTH          9
#define TOWN_SYDNEY         10

// New Zealand

#define TOWN_AUCKLAND       11
#define TOWN_CHRISTCHURCH   12
#define TOWN_WELLINGTON     13

// Australia

#define TIMEZONE_AWST_OFFSET  800 // Australian Western Standard Time

#define TIMEZONE_ACWST_OFFSET 845 // Australian Central Western Standard Time

#define TIMEZONE_ACST_OFFSET  930 // Australian Central Standard Time
#define TIMEZONE_ACDT_OFFSET 1030 // Australian Central Daylight Time

#define TIMEZONE_AEST_OFFSET 1000 // Australian Eastern Standard Time
#define TIMEZONE_AEDT_OFFSET 1100 // Australian Eastern Daylight Time

#define TIMEZONE_LHST_OFFSET 1030 // Lord Howe Standard Time
#define TIMEZONE_LHDT_OFFSET 1100 // Lord Howe Daylight Time

// New Zealand
#define TIMEZONE_NZST_OFFSET 1200 // NZ Standard Time
#define TIMEZONE_NZDT_OFFSET 1300 // NZ Daylight Time

// returned by get_local_time
#define INVALID_INPUT (-1)


// ADD YOUR #defines (if any) here
#define TRUE 1
#define FALSE 0
#define JAN 1
#define FEB 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUG 8
#define SEPT 9
#define OCT 10
#define NOV 11
#define DEC 12

#define MAX_TOWN 14

int get_local_time(int town, int utc_month, int utc_day, int utc_time);
void run_unit_tests(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE
int daylight_savings_east(int utc_month, int utc_day, int utc_time);
int daylight_savings_bh(int utc_month, int utc_day, int utc_time);
int daylight_savings_lhi(int utc_month, int utc_day, int utc_time);
int daylight_savings_nz(int utc_month, int utc_day, int utc_time);
int get_minutes(int utc_time);
int get_hours(int utc_time);
int invalid_input(int minutes, int hours, int utc_day, int utc_month, 
    int town);
int correct_time (int local_time); 
int calculate_local_time (int utc_time, int offset);
// DO NOT CHANGE THIS FUNCTION

// This main function won't be marked as part of the assignment
// It tests the functions you have to write.
// Do not change this main function.  If it does not work with
// your functions you have misunderstood the assignment.

int main(void) {
    int call_get_local_time = 0;

    printf("Enter 0 to call run_unit_tests()\n");
    printf("Enter 1 to call get_local_time()\n");
    printf("Call which function: ");
    scanf("%d", &call_get_local_time);

    if (!call_get_local_time) {
        printf("calling run_unit_tests()\n");
        run_unit_tests();
        printf("unit tests done\n");
        return 0;
    }

    int town = 0;
    int month = 0;
    int day = 0;
    int time = 0;

    printf("Enter %d for Adelaide\n", TOWN_ADELAIDE);
    printf("Enter %d for Brisbane\n", TOWN_BRISBANE);
    printf("Enter %d for Broken_hill\n", TOWN_BROKEN_HILL);
    printf("Enter %d for Canberra\n", TOWN_CANBERRA);
    printf("Enter %d for Darwin\n", TOWN_DARWIN);
    printf("Enter %d for Eucla\n", TOWN_EUCLA);
    printf("Enter %d for Hobart\n", TOWN_HOBART);
    printf("Enter %d for Lord Howe Island\n", TOWN_LORD_HOWE_IS);
    printf("Enter %d for Melbourne\n", TOWN_MELBOURNE);
    printf("Enter %d for Perth\n", TOWN_PERTH);
    printf("Enter %d for Sydney\n", TOWN_SYDNEY);
    printf("Enter %d for Auckland\n", TOWN_AUCKLAND);
    printf("Enter %d for Christchurch\n", TOWN_CHRISTCHURCH);
    printf("Enter %d for Wellington\n", TOWN_WELLINGTON);

    printf("Which town: ");
    scanf("%d", &town);

    printf("Enter UTC month as integer 1..12: ");
    scanf("%d", &month);

    printf("Enter UTC day as integer 1..31: ");
    scanf("%d", &day);

    printf("Enter UTC time as hour * 100 + minutes\n");
    printf("Enter UTC time as integer [0..2359]: ");
    scanf("%d", &time);

    int local_time = get_local_time(town, month, day, time);

    if (local_time == INVALID_INPUT) {
        printf("invalid input - local time could not be calculated\n");
    } else {
        printf("local_time is %d\n", local_time);
    }
    return 0;
}



// Given an Australian town and a 2018 UTC time
// return the local time in the Australian town
//
// time is returned as hours*100 + minutes
// INVALID_INPUT is return for invalid inputs
//
// utc_month should be 1..12
// utc_day should be 1..31
// utc_time should be 0..2359
// utc_time is hours*100 + minutes
//
// note UTC year is assumed to be 2018
// note UTC seconds is assumed to be zero


int get_local_time(int town, int utc_month, int utc_day, int utc_time) {
    int minutes = get_minutes(utc_time);
    int hours = get_hours(utc_time);
    int input_check = invalid_input(minutes, hours, utc_day, utc_month,
        town); 
        if (input_check == INVALID_INPUT) {
            return INVALID_INPUT;
        }
   
    int local_time = 0;
   
   //time for aukland, christchurch, wellington
    if (town == TOWN_AUCKLAND || town == TOWN_WELLINGTON || 
    town == TOWN_CHRISTCHURCH) {
        local_time = calculate_local_time(utc_time, TIMEZONE_NZST_OFFSET);    
        if (daylight_savings_nz(utc_month, utc_day, utc_time) == TRUE) {
            local_time = calculate_local_time(utc_time, TIMEZONE_NZDT_OFFSET);                       
        }    
    }
   
    //time for lord howe island
    if (town == TOWN_LORD_HOWE_IS) {
        local_time = calculate_local_time(utc_time, TIMEZONE_LHST_OFFSET);
        if (daylight_savings_lhi(utc_month, utc_day, utc_time) == TRUE) {
            local_time = calculate_local_time(utc_time, TIMEZONE_LHDT_OFFSET);
        }    
    }
   
    //time for sydney, melbourne, hobart, canberra
    if (town == TOWN_SYDNEY || town == TOWN_MELBOURNE || 
        town == TOWN_HOBART || town == TOWN_CANBERRA) {
        local_time = calculate_local_time(utc_time, TIMEZONE_AEST_OFFSET);
        if (daylight_savings_east(utc_month, utc_day, utc_time) == TRUE) {
           local_time = calculate_local_time(utc_time, TIMEZONE_AEDT_OFFSET);
        }    
    }                                                                    
    
    //time for brisbane
    if (town == TOWN_BRISBANE) {
        local_time = calculate_local_time(utc_time, TIMEZONE_AEST_OFFSET);
    }
   
    //time for broken hill
    if (town == TOWN_BROKEN_HILL) {
        local_time = calculate_local_time(utc_time, TIMEZONE_ACST_OFFSET);
        if (daylight_savings_bh(utc_month, utc_day, utc_time) == TRUE) {
            local_time = calculate_local_time(utc_time, TIMEZONE_ACDT_OFFSET);
        }    
    }
   
    //time for adelaide, darwin
    if (town == TOWN_ADELAIDE || town == TOWN_DARWIN) {
        local_time = calculate_local_time(utc_time, TIMEZONE_ACST_OFFSET);
    }
   
    //time for perth
    if (town == TOWN_PERTH) {
        local_time = calculate_local_time(utc_time, TIMEZONE_AWST_OFFSET);
    } 
   
    //time for eucla
    if (town == TOWN_EUCLA) {
        local_time = calculate_local_time(utc_time, TIMEZONE_ACWST_OFFSET);
    }   
       
    return local_time;   
}

//function to see if the date is inside daylight savings time for sydney,
//melbourne, hobart and canberra

int daylight_savings_east(int utc_month, int utc_day, int utc_time) {
    
    if((utc_month < MARCH) || (utc_month == MARCH && utc_day < 31) || 
       (utc_month == MARCH && utc_day == 31 && utc_time < 1600)) {
       return TRUE;                                                             
    }      
        else if((utc_month > OCT) || (utc_month == OCT && utc_day > 6) ||
            (utc_month == OCT && utc_day == 6 && utc_time > 1500)) {
            return TRUE;
        } else {
              return FALSE;
          } 
}

//function to see if the date is inside daylight savings time for
//broken hill
int daylight_savings_bh(int utc_month, int utc_day, int utc_time) {
    if((utc_month < MARCH) || (utc_month == MARCH && utc_day < 31) || 
       (utc_month == MARCH && utc_day == 31 && utc_time < 1630)) {
       return TRUE;                                                             
    }      
        else if((utc_month > OCT) || (utc_month == OCT && utc_day > 6) ||
            (utc_month == OCT && utc_day == 6 && utc_time > 1630)) {
            return TRUE;
        } else {
              return FALSE;
          } 
}

//function to see if the date is inside daylight savings time for
//lord howe island

int daylight_savings_lhi(int utc_month, int utc_day, int utc_time) {
    if((utc_month < MARCH) || (utc_month == MARCH && utc_day < 31) || 
       (utc_month == MARCH && utc_day == 31 && utc_time < 1500)) {
       return TRUE;                                                             
    }      
        else if((utc_month > OCT) || (utc_month == OCT && utc_day > 6) ||
            (utc_month == OCT && utc_day == 6 && utc_time > 1530)) {
            return TRUE;
        } else {
              return FALSE;
          } 
}

//function to see if the date is inside daylight savings time for nz

int daylight_savings_nz(int utc_month, int utc_day, int utc_time) {
    
    if((utc_month < MARCH) || (utc_month == MARCH && utc_day < 31) || 
    (utc_month == MARCH && utc_day == 31 && utc_time <= 1300 )) {
        return TRUE;  
    } else if ((utc_month > SEPT) || (utc_month == SEPT && 
      utc_day == 30 && utc_time > 1300)) {
          return TRUE;
      }  else {
             return FALSE;
         }
}   
    
//function to get minutes  
int get_minutes(int utc_time) {
    return utc_time % 100;
}
    
//function to get hours  
int get_hours(int utc_time) {
    return (utc_time) / (100);
}
    
//check invalid input function
int invalid_input(int minutes, int hours, int utc_day, int utc_month, 
    int town) {
    if ((minutes > 59 || minutes < 0) || (hours > 23 || hours < 0) || 
    (utc_day > 31 || utc_day < 1) || (utc_month > 12 || utc_month < 1)
    || town >= MAX_TOWN) {
         return INVALID_INPUT;
    }    else if ((utc_month == SEPT || utc_month == APRIL || 
         utc_month == JUNE || utc_month == NOV) && (utc_day > 30)) {
            return INVALID_INPUT; 
         }  else if (utc_month == FEB && utc_day > 28) {
                return INVALID_INPUT;
            } else {
                return 0;
               }
}
            
//function to get correct local_time

int calculate_local_time (int utc_time, int offset) {
    int extra_hours = 0;
    int total_hours = 0;
    int minutes = 0;
    int total_minutes = 0;
    int local_time= 0;
   
    int minutes_utc = get_minutes(utc_time);
    int minutes_offset = get_minutes(offset);
    int hours_utc = get_hours(utc_time);
    int hours_offset = get_hours(offset);
    
    if (minutes_utc + minutes_offset > 59) {
        extra_hours = 1;
        total_minutes = minutes_utc + minutes_offset - 60;
        total_hours = hours_utc + hours_offset + extra_hours;
    } else {
        total_minutes = minutes_utc + minutes_offset;
        total_hours = hours_utc + hours_offset;
      }
    local_time = (total_hours * 100) + total_minutes;
    if (local_time >= 2400) {
        local_time = local_time - 2400;
    }
    return local_time;
}
//EXPLAINING YOUR OVERALL TESTING STRATEGY

//tests are for each individual city, checking to see if daylight savings 
//time has been applied correctly, and correct outputs are produced for 
//different times of the year. Tests also check that input is valid and output
//doesn't equal something with minutes at 60


// run unit tests for get_local_time

void run_unit_tests(void) {
    // UTC midnight on 20th March -> time in Sydney: 11am AEDT
    assert(get_local_time(TOWN_SYDNEY, 3, 20, 0) == 1100);
    // 42 is not a valid month
    assert(get_local_time(TOWN_SYDNEY, 42, 0, 0) == INVALID_INPUT);
    //check there cannot be > 31 days in a month
    assert(get_local_time(TOWN_SYDNEY, 1, 32, 0) == INVALID_INPUT);
    //time cannot be > 2359
    assert(get_local_time(TOWN_SYDNEY, 1, 32, 10000) == INVALID_INPUT);
    //town cannot be MAX_TOWN or greater
    assert(get_local_time(MAX_TOWN, 1, 1, 0000) == INVALID_INPUT);
    assert(get_local_time(14 , 1, 1, 0000) == INVALID_INPUT);
    
    //check time for adelaide (no daylight savings)
    assert(get_local_time(TOWN_ADELAIDE, 1, 1, 0000) == 930);
    assert(get_local_time(TOWN_ADELAIDE, 1, 6, 0000) == 930);
    assert(get_local_time(TOWN_ADELAIDE, 1, 6, 2200) == 730);
    //check time for brisbane (no daylight savings)
    assert(get_local_time(TOWN_BRISBANE, 3, 14, 0000) == 1000);
    assert(get_local_time(TOWN_BRISBANE, 6, 6, 0000) == 1000);
    assert(get_local_time(TOWN_BRISBANE, 6, 6, 2000) == 600);
    //check time for broken hill (daylight savings)
    assert(get_local_time(TOWN_BROKEN_HILL, 1, 6, 0000) == 1030);
    assert(get_local_time(TOWN_BROKEN_HILL, 6, 6, 0000) == 930);
    assert(get_local_time(TOWN_BROKEN_HILL, 3, 13, 200) == 1230);
    //check time for canberra (daylight savings)
    assert(get_local_time(TOWN_CANBERRA, 1, 26, 0000) == 1100);
    assert(get_local_time(TOWN_CANBERRA, 6, 26, 0000) == 1000);
    assert(get_local_time(TOWN_CANBERRA, 6, 26, 1000) == 2000);
    assert(get_local_time(TOWN_CANBERRA, 6, 40, 0000) == INVALID_INPUT);
    //check time for darwin (no daylight savings)
    assert(get_local_time(TOWN_DARWIN, 1, 31, 0000) == 930);
    assert(get_local_time(TOWN_DARWIN, 6, 26, 600) == 1530);
    assert(get_local_time(TOWN_DARWIN, 8, 26, 1200) == 2130);
    assert(get_local_time(TOWN_DARWIN, 3, 16, 630) == 1600);
    assert(get_local_time(TOWN_DARWIN, 3, 16, 630) != 1560);
    //check time for eucla (no daylight savings)
    assert(get_local_time(TOWN_EUCLA, 1, 31, 0000) == 845);
    assert(get_local_time(TOWN_EUCLA, 6, 30, 0000) == 845);
    assert(get_local_time(TOWN_EUCLA, 10, 31, 700) == 1545);
    assert(get_local_time(TOWN_EUCLA, 10, 31, 2345) == 830);
    //check time for hobart (daylight savings)
    assert(get_local_time(TOWN_HOBART, 1, 4, 0000) == 1100);
    assert(get_local_time(TOWN_HOBART, 5, 4, 1000) == 2000);
    //check time for lord howe island (daylight savings)
    assert(get_local_time(TOWN_LORD_HOWE_IS, 1, 4, 0000) == 1100);
    assert(get_local_time(TOWN_LORD_HOWE_IS, 7, 4, 0000) == 1030);
    assert(get_local_time(TOWN_LORD_HOWE_IS, 2, 6, 1100) == 2200);
    //check time for melbourne (daylight savings)
    assert(get_local_time(TOWN_MELBOURNE, 1, 1, 0000) == 1100);
    assert(get_local_time(TOWN_MELBOURNE, 6, 1, 0000) == 1000);
    assert(get_local_time(TOWN_MELBOURNE, 4, 1, 2200) == 800);
    //check time for perth (no daylight savings)
    assert(get_local_time(TOWN_PERTH, 1, 1, 0000) == 800);
    assert(get_local_time(TOWN_PERTH, 6, 1, 0000) == 800);
    assert(get_local_time(TOWN_PERTH, 11, 9, 800) == 1600);
    //check time for sydney (daylight savings)
    assert(get_local_time(TOWN_SYDNEY, 1, 1, 0000) == 1100);
    assert(get_local_time(TOWN_SYDNEY, 6, 1, 0000) == 1000);
    assert(get_local_time(TOWN_SYDNEY, 9, 11, 2000) == 600);
    //check time for auckland (daylight savings)
    assert(get_local_time(TOWN_AUCKLAND, 1, 1, 0000) == 1300);
    assert(get_local_time(TOWN_AUCKLAND, 6, 1, 0000) == 1200);
    assert(get_local_time(TOWN_AUCKLAND, 7, 12, 1000) == 2200);
    //ENDPOINTS FOR DST NZ
    assert(get_local_time(TOWN_AUCKLAND, 9, 30, 1400) == 300);
    assert(get_local_time(TOWN_AUCKLAND, 9, 30, 1300) == 100);
    assert(get_local_time(TOWN_AUCKLAND, 3, 31, 1200) == 100);
    assert(get_local_time(TOWN_AUCKLAND, 3, 31, 1300) == 200);
    assert(get_local_time(TOWN_AUCKLAND, 3, 31, 1400) == 200);
    //check time for christchurch (daylight savings)
    assert(get_local_time(TOWN_CHRISTCHURCH, 1, 1, 0000) == 1300);
    assert(get_local_time(TOWN_CHRISTCHURCH, 7, 23, 0000) == 1200);
    assert(get_local_time(TOWN_CHRISTCHURCH, 3, 14, 1200) == 100);
    //check time for wellington (daylight savings)
    assert(get_local_time(TOWN_WELLINGTON, 1, 1, 0000) == 1300);
    assert(get_local_time(TOWN_WELLINGTON, 5, 15, 0000) == 1200);
    assert(get_local_time(TOWN_WELLINGTON, 2, 26, 200) == 1500);
    
}
