#include <stdio.h>

typedef struct {
    int licznik;
    int mianownik;
} Ułamek;

Ułamek skroc(Ułamek u) {
    int a = u.licznik;
    int b = u.mianownik;
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    u.licznik /= a;
    u.mianownik /= a;
    return u;
}

Ułamek dodaj(Ułamek u1, Ułamek u2) {
    Ułamek wynik;
    wynik.licznik = u1.licznik * u2.mianownik + u2.licznik * u1.mianownik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    return skroc(wynik);
}

Ułamek odejmij(Ułamek u1, Ułamek u2) {
    Ułamek wynik;
    wynik.licznik = u1.licznik * u2.mianownik - u2.licznik * u1.mianownik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    return skroc(wynik);
}

Ułamek pomnoz(Ułamek u1, Ułamek u2) {
    Ułamek wynik;
    wynik.licznik = u1.licznik * u2.licznik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    return skroc(wynik);
}

Ułamek podziel(Ułamek u1, Ułamek u2) {
    Ułamek wynik;
    wynik.licznik = u1.licznik * u2.mianownik;
    wynik.mianownik = u1.mianownik * u2.licznik;
    return skroc(wynik);
}

void wyswietl(Ułamek u) {
    printf("%d/%d\n", u.licznik, u.mianownik);
}
