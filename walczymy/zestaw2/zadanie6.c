#include <stdio.h>

void print_three(char *str) {
    if (str[0] != '\0') printf("%c", str[0]);
    if (str[1] != '\0') printf("%c", str[1]);
    if (str[2] != '\0') printf("%c", str[2]);
    printf("\n");
}

int main() {
    char tekst[] = "Przykład";
    print_three(tekst);
    char krotki[] = "ab";
    print_three(krotki);
    return 0;
}

