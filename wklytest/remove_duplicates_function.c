int remove_duplicates(int length, int source[length], int destination[length]) {
    int i = 0;
    int destination_counter = 0;
    while (i < length) {
        int j = 0;
        while (j < length) {
            if (source[i] == source[j] && i != j) {
                source[j] = 0;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < length) {
        if (source[i] > 0) {
            destination[destination_counter] = source[i];
            destination_counter = destination_counter + 1;
        }
        i = i + 1;
    }
    return destination_counter;
}
