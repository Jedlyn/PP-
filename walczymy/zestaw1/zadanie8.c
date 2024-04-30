#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja alokująca pamięć i wypełniająca tablicę losowymi liczbami
int* allocate_and_fill_array() {
    int *tab = (int*) malloc(200 * sizeof(int));
    if (tab == NULL) {
        printf("Nie udało się zaalokować pamięci.\n");
        return NULL;
    }
    for (int i = 0; i < 200; i++) {
        tab[i] = rand() % 5001; // Losowe liczby z zakresu 0-5000
    }
    return tab;
}

// Funkcja tworząca tablicę postrzępioną
int** create_fragmented_array(int *tab, int size, int *counts) {
    int **fragmented = (int**) malloc(10 * sizeof(int*));
    if (fragmented == NULL) {
        printf("Nie udało się zaalokować pamięci dla tablicy postrzępionej.\n");
        return NULL;
    }

    int temp_counts[10] = {0};

    // Zliczanie elementów dla każdej ostatniej cyfry
    for (int i = 0; i < size; i++) {
        int last_digit = tab[i] % 10;
        temp_counts[last_digit]++;
    }

    // Alokacja pamięci dla każdego wiersza
    for (int i = 0; i < 10; i++) {
        fragmented[i] = (int*) malloc(temp_counts[i] * sizeof(int));
        counts[i] = temp_counts[i]; // Zapisanie liczby elementów w tablicy counts
    }

    // Resetowanie liczników dla wypełnienia
    int index[10] = {0};

    // Wypełnianie tablicy postrzępionej
    for (int i = 0; i < size; i++) {
        int last_digit = tab[i] % 10;
        fragmented[last_digit][index[last_digit]++] = tab[i];
    }

    return fragmented;
}

// Funkcja wyświetlająca tablicę postrzępioną
void print_fragmented_array(int **fragmented, int *counts) {
    for (int i = 0; i < 10; i++) {
        printf("Wiersz %d: ", i);
        for (int j = 0; j < counts[i]; j++) {
            printf("%d ", fragmented[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    int *tab = allocate_and_fill_array();
    if (tab == NULL) return -1;

    int counts[10] = {0};
    int **fragmented = create_fragmented_array(tab, 200, counts);
    if (fragmented == NULL) return -1;

    print_fragmented_array(fragmented, counts);

    // Zwolnienie pamięci
    for (int i = 0; i < 10; i++) {
        free(fragmented[i]);
    }
    free(fragmented);
    free(tab);

    return 0;
}
