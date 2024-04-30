#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("pesele.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku pesele.txt.\n");
        return 1;
    }

    char pesel[12]; // 11 cyfr + znak końca linii
    int countDecember = 0;
    int countWomen = 0;
    int birthYears[100] = {0}; // Zakładamy, że PESEL zawiera lata 1900-1999
    int decadesCount[5] = {0}; // Lata 50, 60, 70, 80, 90
    int invalidPeselsCount = 0;
    char invalidPesels[150][12]; // Zakładamy, że wszystkie mogą być nieprawidłowe

    while (fscanf(file, "%11s", pesel) == 1) {
        // Zliczanie osób urodzonych w grudniu
        if (pesel[2] == '1' && pesel[3] == '2') {
            countDecember++;
        }

        // Zliczanie kobiet (parzysta przedostatnia cyfra)
        if ((pesel[9] - '0') % 2 == 0) {
            countWomen++;
        }

        // Wyznaczanie roku urodzenia
        int year = (pesel[0] - '0') * 10 + (pesel[1] - '0');
        if (year >= 50) {
            year += 1900;
        } else {
            year += 2000;
        }
        birthYears[year - 1900]++;

        // Zliczanie osób urodzonych w poszczególnych dekadach
        int decadeIndex = (year - 1950) / 10;
        if (decadeIndex >= 0 && decadeIndex < 5) {
            decadesCount[decadeIndex]++;
        }

        // Sprawdzanie poprawności cyfry kontrolnej
        int weights[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += (pesel[i] - '0') * weights[i];
        }
        int controlDigit = (10 - (sum % 10)) % 10;
        if (controlDigit != (pesel[10] - '0')) {
            strcpy(invalidPesels[invalidPeselsCount++], pesel);
        }
    }

    fclose(file);

    // Wypisywanie wyników
    printf("Liczba osób urodzonych w grudniu: %d\n", countDecember);
    printf("Liczba kobiet: %d\n", countWomen);

    // Rok z największą liczbą urodzeń
    int maxBirths = 0, maxYear = 0;
    for (int i = 0; i < 100; i++) {
        if (birthYears[i] > maxBirths) {
            maxBirths = birthYears[i];
            maxYear = 1900 + i;
        }
    }
    printf("Rok z największą liczbą urodzeń: %d\n", maxYear);

    // Wypisywanie liczby osób urodzonych w poszczególnych dekadach
    int totalDecadesCount = 0;
    for (int i = 0; i < 5; i++) {
        totalDecadesCount += decadesCount[i];
    }
    printf("Osoby urodzone w kolejnych dekadach:\n");
    for (int i = 0; i < 5; i++) {
        printf("Lata %d0s: %d osób (%.2f%%)\n", 195 + i, decadesCount[i], (100.0 * decadesCount[i]) / totalDecadesCount);
    }

    // Wypisywanie nieprawidłowych numerów PESEL
    printf("Nieprawidłowe numery PESEL:\n");
    for (int i = 0; i < invalidPeselsCount; i++) {
        printf("%s\n", invalidPesels[i]);
    }

    return 0;
}
