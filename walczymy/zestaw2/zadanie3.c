void reverse_string(char *str) {
    int len = 0;
    char *start = str;
    while (*str) {
        len++;
        str++;
    }
    str--;
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = *start;
        *start = *str;
        *str = temp;
        start++;
        str--;
    }
}

int main() {
    char tekst[100] = "Przykładowy tekst do odwrócenia.";
    printf("Przed odwróceniem: %s\n", tekst);
    reverse_string(tekst);
    printf("Po odwróceniu: %s\n", tekst);
    
    return 0;
}
