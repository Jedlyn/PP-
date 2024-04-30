#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    FILE *file = fopen("random_int.txt", "r");
    int num;
    int countPalindromes = 0, countPrimes = 0, countPrimePalindromes = 0;

    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    while (fscanf(file, "%d", &num) != EOF) {
        if (num >= 10 && isPalindrome(num)) {
            countPalindromes++;
        }
        if (isPrime(num)) {
            countPrimes++;
            if (isPrime(reverseNumber(num))) {
                countPrimePalindromes++;
            }
        }
    }

    fclose(file);

    printf("Liczba dwucyfrowych palindromów: %d\n", countPalindromes);
    printf("Liczba liczb pierwszych: %d\n", countPrimes);
    printf("Liczba liczb pierwszych, które są palindromami: %d\n", countPrimePalindromes);

    return 0;
}
