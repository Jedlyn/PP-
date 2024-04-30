#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja pomocnicza do zamiany wartości
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja sortująca tablicę algorytmem sortowania bąbelkowego
void bubbleSort(int *start, int *end) {
    int *i, *j;
    for (i = start; i < end; i++) {
        for (j = start; j < end - (i - start); j++) {
            if (*j > *(j + 1)) {
                swap(j, j + 1);
            }
        }
    }
}

// Funkcja tworząca tablicę i wypełniająca ją losowymi wartościami
int* create_array(int size) {
    int *array = (int*) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Nie udało się zaalokować pamięci.\n");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 201) - 100; // Losowe liczby od -100 do 100
    }
    return array;
}

// Funkcja wyświetlająca tablicę
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int sizes[5];
    printf("Podaj rozmiary pięciu tablic:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &sizes[i]);
    }

    for (int i = 0; i < 5; i++) {
        int *array = create_array(sizes[i]);
        if (array != NULL) {
            printf("Tablica przed sortowaniem:\n");
            print_array(array, sizes[i]);
            bubbleSort(array, array + sizes[i] - 1);
            printf("Tablica po sortowaniu:\n");
            print_array(array, sizes[i]);
            free(array);
        }
    }

    return 0;
}