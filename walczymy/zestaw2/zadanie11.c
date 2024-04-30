#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char phone_number[15];
    printf("Wpisz numer telefonu w formacie (555)555-5555: ");
    fgets(phone_number, sizeof(phone_number), stdin);
    phone_number[strcspn(phone_number, "\n")] = 0; // Usuń znak nowej linii

    // Tokenizacja numeru telefonu
    char *area_code = strtok(phone_number, "()-");
    char *first_three = strtok(NULL, "()-");
    char *last_four = strtok(NULL, "()-");

    // Łączenie pierwszych trzech i ostatnich czterech cyfr
    char full_number[8];
    snprintf(full_number, sizeof(full_number), "%s%s", first_three, last_four);

    // Konwersja na typy liczbowe
    int area_code_int = atoi(area_code);
    long int full_number_long = atol(full_number);

    // Wyświetlenie wyników
    printf("Numer kierunkowy: %d\n", area_code_int);
    printf("Numer telefonu: %ld\n", full_number_long);

    return 0;
}
