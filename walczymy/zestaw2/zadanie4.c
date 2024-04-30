#include <stdio.h>

void remove_spaces(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (*src != ' ') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0'; // Zakończenie łańcucha znakiem końca
}

int main() {
    char tekst[100] = "Przykładowy tekst z odstępami.";
    printf("Przed usunięciem odstępów: %s\n", tekst);
    remove_spaces(tekst);
    printf("Po usunięciu odstępów: %s\n", tekst);
    
    return 0;
}
