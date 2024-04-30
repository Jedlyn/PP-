#include <stdio.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} product;

void fillProduct(product *p) {
    printf("Podaj nazwe produktu: ");
    scanf("%49s", p->name);
    printf("Podaj cene produktu: ");
    scanf("%f", &p->price);
    printf("Podaj ilosc produktu: ");
    scanf("%d", &p->quantity);
}

void printProduct(product p) {
    printf("Produkt: %s\n", p.name);
    printf("Cena: %.2f\n", p.price);
    printf("Ilosc: %d\n", p.quantity);
}

int main() {
    product product1, product2;

    printf("Wprowadz dane dla pierwszego produktu:\n");
    fillProduct(&product1);
    printf("Wprowadz dane dla drugiego produktu:\n");
    fillProduct(&product2);

    printf("\nInformacje o produktach:\n");
    printProduct(product1);
    printProduct(product2);

    return 0;
}
