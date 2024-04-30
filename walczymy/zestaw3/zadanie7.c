#include <stdio.h>

typedef struct {
    char marka[50];
    char model[50];
    int rok;
    float cena;
} Samochod;

void wypiszNajdrozszy(Samochod samochody[], int n) {
    int indeksNajdrozszego = 0;
    for (int i = 1; i < n; i++) {
        if (samochody[i].cena > samochody[indeksNajdrozszego].cena) {
            indeksNajdrozszego = i;
        }
    }
    printf("Najdrozszy samochod: %s %s, Rok: %d, Cena: %.2f\n", 
           samochody[indeksNajdrozszego].marka, samochody[indeksNajdrozszego].model, 
           samochody[indeksNajdrozszego].rok, samochody[indeksNajdrozszego].cena);
}

void wypiszNajmlodszy(Samochod samochody[], int n) {
    int indeksNajmlodszego = 0;
    for (int i = 1; i < n; i++) {
        if (samochody[i].rok > samochody[indeksNajmlodszego].rok) {
            indeksNajmlodszego = i;
        }
    }
    printf("Najmlodszy samochod: %s %s, Rok: %d, Cena: %.2f\n", 
           samochody[indeksNajmlodszego].marka, samochody[indeksNajmlodszego].model, 
           samochody[indeksNajmlodszego].rok, samochody[indeksNajmlodszego].cena);
}

float obliczSredniaCene(Samochod samochody[], int n) {
    float suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += samochody[i].cena;
    }
    return suma / n;
}

int main() {
    int n;
    printf("Podaj liczbe samochodow: ");
    scanf("%d", &n);
    Samochod samochody[n];

    for (int i = 0; i < n; i++) {
        printf("Samochod %d:\n", i + 1);
        printf("Podaj marke: ");
        scanf("%s", samochody[i].marka);
        printf("Podaj model: ");
        scanf("%s", samochody[i].model);
        printf("Podaj rok: ");
        scanf("%d", &samochody[i].rok);
        printf("Podaj cene: ");
        scanf("%f", &samochody[i].cena);
    }

    wypiszNajdrozszy(samochody, n);
    wypiszNajmlodszy(samochody, n);
    printf("Srednia cena samochodow: %.2f\n", obliczSredniaCene(samochody, n));

    return 0;
}
