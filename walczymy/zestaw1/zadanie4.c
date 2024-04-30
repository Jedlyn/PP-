

#include <stdio.h>
#include <stdlib.h>

// Funkcja transponująca macierz
int** transpose_matrix(int **tab1, int n, int m) {
    int **tab2 = (int**) malloc(m * sizeof(int*));
    if (tab2 == NULL) {
        printf("Nie udało się zaalokować pamięci dla tab2.\n");
        return NULL;
    }
    for (int i = 0; i < m; i++) {
        tab2[i] = (int*) malloc(n * sizeof(int));
        if (tab2[i] == NULL) {
            printf("Nie udało się zaalokować pamięci dla tab2[%d].\n", i);
            // Zwolnienie pamięci przydzielonej do tej pory
            for (int j = 0; j < i; j++) {
                free(tab2[j]);
            }
            free(tab2);
            return NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab2[j][i] = tab1[i][j];
        }
    }

    return tab2;
}

// Funkcja do wyświetlania macierzy
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3, m = 4;
    int **tab1 = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        tab1[i] = (int*) malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            tab1[i][j] = i * m + j + 1; // Przykładowe wypełnienie macierzy
        }
    }

    printf("Macierz oryginalna:\n");
    print_matrix(tab1, n, m);

    int **tab2 = transpose_matrix(tab1, n, m);
    if (tab2 != NULL) {
        printf("Macierz transponowana:\n");
        print_matrix(tab2, m, n);

        // Zwolnienie pamięci
        for (int i = 0; i < m; i++) {
            free(tab2[i]);
        }
        free(tab2);
    }

    for (int i = 0; i < n; i++) {
        free(tab1[i]);
    }
    free(tab1);

    return 0;
}
