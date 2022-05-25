// Perform the ROT13 algorithm on a string
// Completed by
//  ... (z0000000)
//  ... (z0000000)
// Commpleted on 2017-08-??
// Tutor's name (day_hH-lab)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Add your own #defines here

void rotate_thirteen(char *string);
char rotate_one(char c);
void rotate_thirteen(char *string);
int strings_equal(char *string1, char *string2);

// Add your own function porototypes here

int main(int argc, char *argv[]) {
    // Example tests
    char test_a[MAX_LENGTH] = "Hello, world!";
    rotate_thirteen(test_a);
    assert(strings_equal("Uryyb, jbeyq!", test_a));

    char test_b[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotate_thirteen(test_b);
    assert(strings_equal("nopqrstuvwxyzabcdefghijklm", test_b));

    char test_c[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotate_thirteen(test_c);
    assert(strings_equal("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", test_c));

    // Add your own tests here

    printf("All tests passed. You are awesome!\n");

    return 0;
}

void rotate_thirteen(char *string) {
    int i = 0;
    int position = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            position = string[i] + 13;
            string[i] = position;
            if (position > 'z') {
                position = position - 'z';
                string[i] = 'a' + position - 1;
            }
        }
        if (string[i] >= 'A' && string[i] <= 'Z') {
            position = string[i] + 13;
            string[i] = position;
            if (position > 'Z') {
                position = position - 'Z';
                string[i] = 'A' + position - 1;
            }
        }
        i = i + 1;
    }
}

char rotate_one(char c) {
    if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z')) {
        c = c + 1;
    }
    if (c == 'z') {
        c = 'a';
    } else if (c == 'Z') {
        c = 'A';
    }
    return c;
}

int strings_equal(char *string1, char *string2) {
    if (string1[0] == '\0' && string2[0] == '\0') {
        return 1;
    }
    int i = 0;
    while (42 == 42) {
        if (string1[i] != string2[i]) {
            return 0;
        }
        i = i + 1;
        if (string1[i] == '\0' && string2[i] == '\0') {
            break;
        }
    }
    return 1;
}
