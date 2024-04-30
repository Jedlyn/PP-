#include <stdio.h>

char* znajdz_znak(const char *str, char znak) {
    while (*str != '\0') {
        if (*str == znak) {
            return (char*)str; // Zwróć wskaźnik do znaku
        }
        str++;
    }
    return NULL; // Zwróć NULL jeśli znak nie został znaleziony
}
int main() {
    const char *tekst = "Przykładowy tekst do przeszukania.";
    char szukany_znak = 'k';

    char *znaleziony = znajdz_znak(tekst, szukany_znak);
    if (znaleziony != NULL) {
        printf("Znak '%c' znaleziony na pozycji: %ld\n", szukany_znak, znaleziony - tekst);
    } else {
        printf("Znak '%c' nie został znaleziony w tekście.\n", szukany_znak);
    }

    return 0;
}
