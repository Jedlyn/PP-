#include <stdio.h>

// Definicja szablonu struktury product
typedef struct {
    int id;
    char name[15];
    double weight;
    double price;
} product;

int main() {
    // Inicjalizacja trzech obiektów typu product
    product product1 = {1, "Jabłko", 0.5, 2.99};
    product product2;
    product product3;
    product *product3_ptr = &product3; // Wskaźnik do trzeciej struktury

    // Uzupełnienie danych drugiej struktury przez użytkownika
    printf("Podaj ID drugiego produktu: ");
    scanf("%d", &product2.id);
    printf("Podaj nazwę drugiego produktu: ");
    scanf("%s", product2.name);
    printf("Podaj wagę drugiego produktu: ");
    scanf("%lf", &product2.weight);
    printf("Podaj cenę drugiego produktu: ");
    scanf("%lf", &product2.price);

    // Uzupełnienie danych trzeciej struktury przez użytkownika z wykorzystaniem wskaźnika
    printf("Podaj ID trzeciego produktu: ");
    scanf("%d", &product3_ptr->id);
    printf("Podaj nazwę trzeciego produktu: ");
    scanf("%s", product3_ptr->name);
    printf("Podaj wagę trzeciego produktu: ");
    scanf("%lf", &product3_ptr->weight);
    printf("Podaj cenę trzeciego produktu: ");
    scanf("%lf", &product3_ptr->price);

    // Wyświetlenie wszystkich struktur
    printf("Produkt 1: ID=%d, Nazwa=%s, Waga=%.2f, Cena=%.2f\n", product1.id, product1.name, product1.weight, product1.price);
    printf("Produkt 2: ID=%d, Nazwa=%s, Waga=%.2f, Cena=%.2f\n", product2.id, product2.name, product2.weight, product2.price);
    printf("Produkt 3: ID=%d, Nazwa=%s, Waga=%.2f, Cena=%.2f\n", product3_ptr->id, product3_ptr->name, product3_ptr->weight, product3_ptr->price);

    return 0;
}
