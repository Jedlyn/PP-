#include <stdio.h>
#include <string.h>

void compare_strings(const char *str1, const char *str2) {
    int result = strcmp(str1, str2);
    if (result < 0) {
        printf("Pierwszy ciąg tekstowy jest mniejszy niż drugi.\n");
    } else if (result > 0) {
        printf("Pierwszy ciąg tekstowy jest większy niż drugi.\n");
    } else {
        printf("Oba ciągi tekstowe są równe.\n");
    }
}

int main() {
    char str1[100];
    char str2[100];

    printf("Wpisz pierwszy ciąg tekstowy: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Usuń znak nowej linii

    printf("Wpisz drugi ciąg tekstowy: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Usuń znak nowej linii

    compare_strings(str1, str2);

    return 0;
}
