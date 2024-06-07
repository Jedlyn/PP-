#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int count_words_in_line(char *line) {
    int word_count = 0;
    char *token = strtok(line, " \n");

    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " \n");
    }

    return word_count;
}

int main() {
    FILE *file;
    char *filename = "input.txt";
    char line[MAX_LINE_LENGTH];
    int total_word_count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        // Make a copy of the line to prevent strtok from modifying the original line
        char line_copy[MAX_LINE_LENGTH];
        strcpy(line_copy, line);

        total_word_count += count_words_in_line(line_copy);
    }

    fclose(file);

    printf("Total number of words: %d\n", total_word_count);

    return 0;
}
