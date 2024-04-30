
#include <stdlib.h>
#include <stdio.h>

int** dodaj_macierze(int **tab1, int **tab2, int n) {
    int **wynik = (int**) malloc(n * sizeof(int*));
    if (wynik == NULL) {
        printf("Nie udało się zaalokować pamięci dla wynikowej macierzy.\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        wynik[i] = (int*) malloc(n * sizeof(int));
        if (wynik[i] == NULL) {
            printf("Nie udało się zaalokować pamięci dla wynik[%d].\n", i);
            // Zwolnienie pamięci przydzielonej do tej pory
            for (int j = 0; j < i; j++) {
                free(wynik[j]);
            }
            free(wynik);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            wynik[i][j] = tab1[i][j] + tab2[i][j];
        }
    }
    return wynik;
}
