#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_sentence() {
    const char *article[] = {"ten", "ta", "to"};
    const char *noun[] = {"chłopak", "dziewczyna", "pies", "miasto", "samochód"};
    const char *verb[] = {"prowadził", "skoczył", "uciekł", "szedł", "przeskoczył"};
    const char *preposition[] = {"do", "z", "na", "nad", "pod"};

    int article_size = sizeof(article) / sizeof(article[0]);
    int noun_size = sizeof(noun) / sizeof(noun[0]);
    int verb_size = sizeof(verb) / sizeof(verb[0]);
    int preposition_size = sizeof(preposition) / sizeof(preposition[0]);

    char sentence[200];
    for (int i = 0; i < 20; i++) {
        snprintf(sentence, sizeof(sentence), "%s %s %s %s %s %s",
                 article[rand() % article_size],
                 noun[rand() % noun_size],
                 verb[rand() % verb_size],
                 preposition[rand() % preposition_size],
                 article[rand() % article_size],
                 noun[rand() % noun_size]);
        printf("%s.\n", sentence);
    }
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych
    generate_sentence();
    return 0;
}
