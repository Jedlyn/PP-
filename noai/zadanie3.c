#include <stdio.h>
#include <stdlib.h>

void splitFile(const char *inputFileName, int partSize) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Nie można otworzyć pliku");
        return;
    }

    // Ustalanie rozmiaru pliku
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    int partNumber = 0;
    char outputFileName[256];
    while (fileSize > 0) {
        sprintf(outputFileName, "part%d.bin", partNumber++);
        FILE *outputFile = fopen(outputFileName, "wb");
        if (outputFile == NULL) {
            perror("Nie można utworzyć pliku wyjściowego");
            fclose(inputFile);
            return;
        }

        int currentPartSize = (fileSize < partSize) ? fileSize : partSize;
        char *buffer = (char *)malloc(currentPartSize);

        if (buffer == NULL) {
            perror("Nie można przydzielić pamięci");
            fclose(outputFile);
            fclose(inputFile);
            return;
        }

        fread(buffer, 1, currentPartSize, inputFile);
        fwrite(buffer, 1, currentPartSize, outputFile);
        free(buffer);

        fclose(outputFile);
        fileSize -= currentPartSize;
    }

    fclose(inputFile);
}

int main() {
    char fileName[256];
    int partSize;

    printf("Podaj nazwę pliku: ");
    scanf("%255s", fileName);
    printf("Podaj maksymalny rozmiar części pliku w bajtach: ");
    scanf("%d", &partSize);

    splitFile(fileName, partSize);

    return 0;
}
