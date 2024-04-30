#include <stdio.h>

double* znajdzMaksymalny(double *tab, int rozmiar){
    double *maksymalny = tab;
    for(double *ptr = tab; ptr < tab + rozmiar; ptr++){
        if(*ptr > *maksymalny){
            maksymalny = ptr;
        }
    }
    return maksymalny;
}

int main(){
    double tab[] = {1,2,3,4,5,6,17,11};
    int rozmiar = sizeof(tab)/sizeof(tab[0]);
    double *maksymalny = znajdzMaksymalny(tab,rozmiar);
    printf("Maksymalny element w tablicy to: %.2f\n",*maksymalny);
    return 0;

}