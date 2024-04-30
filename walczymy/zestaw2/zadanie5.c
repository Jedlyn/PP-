#include <stdio.h>

void read_first_word() {
    char word[100]; // Zakładamy, że słowo nie przekroczy 100 znaków
    scanf("%99s", word); // Wczytaj pierwsze słowo (do pierwszej spacji, tabulatora lub nowej linii)
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Porzuć resztę wiersza
    printf("Pierwsze słowo: %s\n", word);
}

int main() {
    printf("Wpisz zdanie: ");
    read_first_word();
    return 0;
}
