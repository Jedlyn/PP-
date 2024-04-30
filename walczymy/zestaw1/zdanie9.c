#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja alokująca pamięć i wypełniająca tablicę liczbami losowymi
double** allocate_and_fill_matrix(int n, int m) {
    double **matrix = (double**) malloc(n * sizeof(double*));
    if (matrix == NULL) {
        printf("Nie udało się zaalokować pamięci dla macierzy.\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*) malloc(m * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Nie udało się zaalokować pamięci dla wiersza %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
        for (int j = 0; j < m; j++) {
            matrix[i][j] = (double)(rand() % 201 - 100) + (double)rand() / RAND_MAX;
        }
    }
    return matrix;
}

// Funkcja sumująca elementy w kolumnie
double sum_column(double **matrix, int n, int col) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][col];
    }
    return sum;
}

// Funkcja zamieniająca dwie kolumny w macierzy
void swap_columns(double **matrix, int n, int col1, int col2) {
    for (int i = 0; i < n; i++) {
        double temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

// Funkcja sortująca kolumny macierzy względem sumy ich elementów
void sort_columns_by_sum(double **matrix, int n, int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (sum_column(matrix, n, j) > sum_column(matrix, n, j + 1)) {
                swap_columns(matrix, n, j, j + 1);
            }
        }
    }
}

// Funkcja do wyświetlania macierzy
void print_matrix(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n = 5, m = 5; // Przykładowe wartości n i m
    double **matrix = allocate_and_fill_matrix(n, m);
    if (matrix != NULL) {
        printf("Macierz przed sortowaniem:\n");
        print_matrix(matrix, n, m);
        sort_columns_by_sum(matrix, n, m);
        printf("Macierz po sortowaniu kolumn względem sumy elementów:\n");
        print_matrix(matrix, n, m);

        // Zwolnienie pamięci
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
    return 0;
}
