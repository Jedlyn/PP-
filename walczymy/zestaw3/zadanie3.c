#include <stdio.h>

typedef struct {
    int id;
    char name[15];
    double weight;
    double price;
} product;

void fillProduct(product *p) {
    printf("Podaj ID produktu: ");
    scanf("%d", &p->id);
    printf("Podaj nazwę produktu: ");
    scanf("%s", p->name);
    printf("Podaj wagę produktu: ");
    scanf("%lf", &p->weight);
    printf("Podaj cenę produktu: ");
    scanf("%lf", &p->price);
}

void printProduct(product p) {
    printf("ID: %d, Produkt: %s, Waga: %.2lf kg, Cena: %.2lf zł\n", p.id, p.name, p.weight, p.price);
}

int main() {
    product products[4];
    for (int i = 0; i < 4; i++) {
        printf("Wprowadź dane dla produktu %d:\n", i + 1);
        fillProduct(&products[i]);
    }

    printf("\nDane wprowadzonych produktów:\n");
    for (int i = 0; i < 4; i++) {
        printProduct(products[i]);
    }

    return 0;
}
