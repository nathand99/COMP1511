// CONVERT A STRING TO UPPERCASE
// CREATED BY
//  ... (Z0000000)
//  ... (Z0000000)
// CREATED ON 2017-08-??
// TUTOR'S NAME (DAYHH-LAB)

#include <stdio.h>
#include <string.h>
/// THIS WON'T WORK!
///
/// str only points to a string literal, which it is not legal to change.
/// If you attempt to modify it on Linux you will get a runtime error.
//
// char *str = "Hello!"
// string_reverse(str)

void string_reverse(char *buffer);

int main(int argc, char *argv[]) {
    char str[] = ".'neetneves' :egassem terces A";
    string_reverse(str);
    printf("%s\n", str);
    return 0;
}

// Takes a string in `buffer`, and reverses it in-place.
void string_reverse(char *buffer) {
    int i = 0;
    while (buffer[i] != '\0') {
        i = i + 1;
    }
    i = i - 1;
    int length = i;
    int temp = 0;
    int j = 0;
    while (i >= 0) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
        j++;
        i--;
        if (j > length / 2) {
            break;
        }
    }
}
