#include <stdio.h>
#include <string.h>

int main() {
    char text[1024];
    char phrase[100];
    char *search_ptr;

    printf("Wpisz tekst: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Usuń znak nowej linii

    printf("Wpisz frazę do wyszukania: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = 0; // Usuń znak nowej linii

    search_ptr = strstr(text, phrase);
    if (search_ptr != NULL) {
        printf("Pozostała część tekstu od pierwszego wystąpienia frazy: '%s'\n", search_ptr);
        search_ptr = strstr(search_ptr + 1, phrase);
        if (search_ptr != NULL) {
            printf("Pozostała część tekstu od drugiego wystąpienia frazy: '%s'\n", search_ptr);
        } else {
            printf("Nie znaleziono drugiego wystąpienia frazy.\n");
        }
    } else {
        printf("Nie znaleziono frazy w tekście.\n");
    }

    return 0;
}
