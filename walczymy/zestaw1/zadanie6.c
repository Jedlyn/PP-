
#include <stdio.h>
#include <stdlib.h>

// Funkcja mnożąca dwie macierze kwadratowe
int** multiply_matrices(int **tab1, int **tab2, int n) {
    int **result = (int**) malloc(n * sizeof(int*));
    if (result == NULL) {
        printf("Nie udało się zaalokować pamięci dla wynikowej macierzy.\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        result[i] = (int*) malloc(n * sizeof(int));
        if (result[i] == NULL) {
            printf("Nie udało się zaalokować pamięci dla result[%d].\n", i);
            // Zwolnienie pamięci przydzielonej do tej pory
            for (int j = 0; j < i; j++) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += tab1[i][k] * tab2[k][j];
            }
        }
    }
    return result;
}

// Funkcja do wyświetlania macierzy
void print_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int **tab1 = (int**) malloc(n * sizeof(int*));
    int **tab2 = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        tab1[i] = (int*) malloc(n * sizeof(int));
        tab2[i] = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            tab1[i][j] = i * n + j + 1; // Przykładowe wypełnienie macierzy
            tab2[i][j] = (i + 1) * (j + 1); // Przykładowe wypełnienie macierzy
        }
    }

    printf("Macierz A:\n");
    print_matrix(tab1, n);
    printf("Macierz B:\n");
    print_matrix(tab2, n);

    int **result = multiply_matrices(tab1, tab2, n);
    if (result != NULL) {
        printf("Wynik mnożenia macierzy A i B:\n");
        print_matrix(result, n);

        // Zwolnienie pamięci
        for (int i = 0; i < n; i++) {
            free(tab1[i]);
            free(tab2[i]);
            free(result[i]);
        }
        free(tab1);
        free(tab2);
        free(result);
    }

    return 0;
}
