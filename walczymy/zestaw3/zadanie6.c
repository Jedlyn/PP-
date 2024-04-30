#include <stdio.h>

typedef struct {
    char imie[20];
    char nazwisko[30];
    int rok;
    char kierunek[50];
    float oceny[10];
    int liczba_ocen;
} Student;

void wypiszStudentowRoku(Student studenci[], int liczba_studentow, int rok) {
    printf("Studenci roku %d:\n", rok);
    for (int i = 0; i < liczba_studentow; i++) {
        if (studenci[i].rok == rok) {
            printf("%s %s, kierunek: %s\n", studenci[i].imie, studenci[i].nazwisko, studenci[i].kierunek);
        }
    }
}

float obliczSredniaOcen(Student student) {
    float suma = 0;
    for (int i = 0; i < student.liczba_ocen; i++) {
        suma += student.oceny[i];
    }
    return suma / student.liczba_ocen;
}

void wypiszStudentaNajwyzszaSrednia(Student studenci[], int liczba_studentow) {
    float najwyzsza_srednia = 0;
    int indeks_najlepszego = -1;
    for (int i = 0; i < liczba_studentow; i++) {
        float srednia = obliczSredniaOcen(studenci[i]);
        if (srednia > najwyzsza_srednia) {
            najwyzsza_srednia = srednia;
            indeks_najlepszego = i;
        }
    }
    if (indeks_najlepszego != -1) {
        printf("Student z najwyższą średnią: %s %s, średnia: %.2f\n", 
               studenci[indeks_najlepszego].imie, 
               studenci[indeks_najlepszego].nazwisko, 
               najwyzsza_srednia);
    }
}

// Przykładowe użycie:
int main() {
    Student studenci[3] = {
        {"Jan", "Kowalski", 2, "Informatyka", {5.0, 4.5, 3.5}, 3},
        {"Anna", "Nowak", 2, "Matematyka", {5.0, 5.0, 5.0}, 3},
        {"Piotr", "Zalewski", 1, "Fizyka", {4.0, 3.5, 4.0}, 3}
    };

    wypiszStudentowRoku(studenci, 3, 2);
    printf("\n");
    wypiszStudentaNajwyzszaSrednia(studenci, 3);

    return 0;
}
