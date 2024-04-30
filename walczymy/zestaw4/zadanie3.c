#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_numbers() {
    FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return;
    }

    srand(time(NULL));
    int n = rand() % (500 - 50 + 1) + 50;
    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++) {
        int m = rand() % (80 - 2 + 1) + 2;
        fprintf(file, "%d\n", m);

        for (int j = 0; j < m; j++) {
            int number = rand() % (500 - (-500) + 1) - 500;
            fprintf(file, "%d ", number);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    generate_numbers();
    return 0;
}
