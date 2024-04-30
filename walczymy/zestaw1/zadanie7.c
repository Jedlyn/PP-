#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja alokująca pamięć dla dwuwymiarowej tablicy i wypełniająca ją liczbami pseudolosowymi
int** allocate_and_fill_matrix(int n, int m) {
    int **matrix = (int**) malloc(n * sizeof(int*));
    if (matrix == NULL) {
        printf("Nie udało się zaalokować pamięci dla macierzy.\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Nie udało się zaalokować pamięci dla wiersza %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 2 + rand() % 99; // Losowe liczby od 2 do 100
        }
    }
    return matrix;
}

// Funkcja znajdująca liczby podzielne przez k i zapisująca je do nowej tablicy
int* find_and_allocate_divisible(int **matrix, int n, int m, int k, int *size) {
    int count = 0;
    // Zliczanie liczb podzielnych przez k
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % k == 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        return NULL;
    }
    *size = count;
    int *divisible = (int*) malloc(count * sizeof(int));
    if (divisible == NULL) {
        printf("Nie udało się zaalokować pamięci dla tablicy wynikowej.\n");
        return NULL;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % k == 0) {
                divisible[index++] = matrix[i][j];
            }
        }
    }
    return divisible;
}

// Funkcja do wyświetlania tablicy jednowymiarowej
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n, m, k;
    printf("Podaj wymiary macierzy n i m (n * m = 1000): ");
    scanf("%d %d", &n, &m);
    if (n * m != 1000) {
        printf("Błąd: iloczyn n i m musi być równy 1000.\n");
        return 1;
    }
    int **matrix = allocate_and_fill_matrix(n, m);
    if (matrix == NULL) {
        return 1;
    }
    printf("Podaj wartość k (2 <= k <= 100): ");
    scanf("%d", &k);
    if (k < 2 || k > 100) {
        printf("Błąd: k musi być w zakresie od 2 do 100.\n");
        return 1;
    }
    int size;
    int *divisible = find_and_allocate_divisible(matrix, n, m, k, &size);
    if (divisible == NULL) {
        printf("Nie ma liczb podzielnych przez %d.\n", k);
    } else {
        printf("Liczby podzielne przez %d:\n", k);
        print_array(divisible, size);
        free(divisible);
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
