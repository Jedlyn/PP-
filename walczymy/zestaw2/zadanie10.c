#include <stdio.h>
#include <string.h>

void print_latin_word(const char *word) {
    if (strlen(word) < 2) return; // Każde słowo musi mieć przynajmniej dwie litery

    // Przesuń pierwszą literę na koniec i dodaj "ay"
    printf("%s%cay ", word + 1, word[0]);
}

int main() {
    char sentence[100];
    printf("Wpisz zdanie po angielsku: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; // Usuń znak nowej linii

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        print_latin_word(token);
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}

