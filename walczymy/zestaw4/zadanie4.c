#include <stdio.h>
#include <stdlib.h>

// Funkcja do wczytywania danych z pliku i tworzenia dynamicznej tablicy dwuwymiarowej
int** create_dynamic_array_from_file(const char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Nie można otworzyć pliku %s.\n", filename);
        return NULL;
    }

    // Wczytanie rozmiarów tablicy
    if (fscanf(file, "%d %d", rows, cols) != 2) {
        printf("Nie udało się wczytać rozmiarów tablicy z pliku.\n");
        fclose(file);
        return NULL;
    }

    // Alokacja pamięci dla tablicy
    int** array = (int**) malloc(*rows * sizeof(int*));
    if (!array) {
        printf("Nie udało się zaalokować pamięci dla tablicy.\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *rows; i++) {
        array[i] = (int*) malloc(*cols * sizeof(int));
        if (!array[i]) {
            printf("Nie udało się zaalokować pamięci dla wiersza %d.\n", i);
            // Zwolnienie pamięci przydzielonej do tej pory
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            fclose(file);
            return NULL;
        }
        // Wczytanie danych do tablicy
        for (int j = 0; j < *cols; j++) {
            if (fscanf(file, "%d", &array[i][j]) != 1) {
                printf("Nie udało się wczytać danych dla elementu [%d][%d].\n", i, j);
                // Zwolnienie pamięci
                for (int k = 0; k <= i; k++) {
                    free(array[k]);
                }
                free(array);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return array;
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
    int n, m;
    int** dynamic_array = create_dynamic_array_from_file("numbers.txt", &n, &m);
    if (dynamic_array != NULL) {
        printf("Zawartość wczytanej tablicy:\n");
        print_matrix(dynamic_array, n, m);

        // Zwolnienie pamięci
        for (int i = 0; i < n; i++) {
            free(dynamic_array[i]);
        }
        free(dynamic_array);
    }

    return 0;
}
