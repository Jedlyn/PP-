#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    file = fopen("random_int.txt", "w");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych
    for (int i = 0; i < 1000; i++) {
        int random_number = (rand() % 15000) * 2 + 1; // Generowanie losowej nieparzystej liczby z zakresu 1 - 30000
        fprintf(file, "%d\n", random_number);
    }

    fclose(file);
    printf("Plik 'random_int.txt' został utworzony.\n");
    return 0;
}
