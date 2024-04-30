#include <stdio.h>

typedef struct {
    float x;
    float y;
} Punkt;

int czyNadOsaOX(Punkt p) {
    if (p.y > 0) return 1;
    return 0;
}

void symetriaOsiowaOX(Punkt *p) {
    p->y = -p->y;
}

void symetriaSrodkowa(Punkt *p) {
    p->x = -p->x;
    p->y = -p->y;
}

void wczytajPunkty(Punkt punkty[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Podaj współrzędne punktu %d (x y): ", i + 1);
        scanf("%f %f", &punkty[i].x, &punkty[i].y);
    }
}

int liczPunktyNadOsaOX(Punkt punkty[], int n) {
    int licznik = 0;
    for (int i = 0; i < n; i++) {
        if (czyNadOsaOX(punkty[i])) {
            licznik++;
        }
    }
    return licznik;
}

void liczPunktyWCwiartkach(Punkt punkty[], int n, int liczniki[5]) {
    for (int i = 0; i < 5; i++) {
        liczniki[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (punkty[i].x == 0 || punkty[i].y == 0) {
            liczniki[4]++; // punkty na osiach
        } else if (punkty[i].x > 0 && punkty[i].y > 0) {
            liczniki[0]++; // I cwiartka
        } else if (punkty[i].x < 0 && punkty[i].y > 0) {
            liczniki[1]++; // II cwiartka
        } else if (punkty[i].x < 0 && punkty[i].y < 0) {
            liczniki[2]++; // III cwiartka
        } else if (punkty[i].x > 0 && punkty[i].y < 0) {
            liczniki[3]++; // IV cwiartka
        }
    }
}

int main() {
    int n;
    printf("Podaj liczbę punktów: ");
    scanf("%d", &n);
    Punkt punkty[n];

    wczytajPunkty(punkty, n);

    printf("Liczba punktów nad osią OX: %d\n", liczPunktyNadOsaOX(punkty, n));

    int liczniki[5];
    liczPunktyWCwiartkach(punkty, n, liczniki);
    printf("I cwiartka: %d\n", liczniki[0]);
    printf("II cwiartka: %d\n", liczniki[1]);
    printf("III cwiartka: %d\n", liczniki[2]);
    printf("IV cwiartka: %d\n", liczniki[3]);
    printf("Na osiach: %d\n", liczniki[4]);

    return 0;
}
