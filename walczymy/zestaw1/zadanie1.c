
#include <stdio.h>

int LiczElementy(int *tab, int rozmiar, int k) {
    int licznik = 0;
    for (int *ptr = tab; ptr < tab + rozmiar; ptr++){
        if (*ptr > k) {
            licznik++;
        }
    }
    return licznik;
}

int main(){
    int tab[] = {1,2,3,4,5,6,7,8,9};
    int rozmiar = sizeof(tab)/sizeof(tab[0]);
    int k = 3;
    printf("Liczba elementow wiekszych od %d wynosi: %d",k,LiczElementy(tab,rozmiar,k));
    return 0;
}


