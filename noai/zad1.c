#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void count_letters(const char *text, int counts[ALPHABET_SIZE]) {
    while (*text) {
        if (isalpha(*text)) {
            char letter = tolower(*text);
            counts[letter - 'a']++;
        }
        text++;
    }
}

void print_letter_counts(const int counts[ALPHABET_SIZE]) {
    printf("Letter | Count\n");
    printf("--------------\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("  %c   |  %d\n", 'a' + i, counts[i]);
    }
}

int main() {
    FILE *file;
    char *filename = "input.txt";
    char ch;
    int counts[ALPHABET_SIZE] = {0};

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        char str[2] = {ch, '\0'};
        count_letters(str, counts);
    }

    fclose(file);

    print_letter_counts(counts);

    return 0;
}
