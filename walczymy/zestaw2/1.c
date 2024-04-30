
char* moja_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*ptr) ptr++;  // Przesunięcie wskaźnika na koniec łańcucha dest
    while (*src) {
        *ptr++ = *src++; // Kopiowanie znaków z src do dest
    }
    *ptr = '\0';         // Dodanie znaku końca łańcucha
    return dest;
}

int main() {
    char str1[100] = "Witaj, ";
    const char str2[] = "świecie!";
    
    printf("Przed połączeniem: %s\n", str1);
    moja_strcat(str1, str2);
    printf("Po połączeniu: %s\n", str1);
    
    return 0;
}
