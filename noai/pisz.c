#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGHT 26

void count_letters(const char *str, int *letter_count) {
    while(*str){
        if(isalpha(*str)) {
            char lower_char = tolower(*str);
            letter_count[lower_char - 'a']++;
        }
        str++;
    }
}