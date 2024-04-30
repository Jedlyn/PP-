#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_PATTERN_LENGTH 6
#define ALPHABET_SIZE 26
#define NUM_WORDS 500
#define NUM_PATTERNS 10

bool containsAllLetters(const char *word) {
    bool letters[ALPHABET_SIZE] = {false};
    int uniqueCount = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (!letters[word[i] - 'A']) {
            letters[word[i] - 'A'] = true;
            uniqueCount++;
            if (uniqueCount == ALPHABET_SIZE) return true;
        }
    }
    return false;
}

bool hasNoRepeatingLetters(const char *word) {
    bool letters[ALPHABET_SIZE] = {false};
    for (int i = 0; word[i] != '\0'; i++) {
        if (letters[word[i] - 'A']) return false;
        letters[word[i] - 'A'] = true;
    }
    return true;
}

int countPatternOccurrences(const char *word, const char *pattern) {
    int count = 0;
    int wordLen = strlen(word);
    int patternLen = strlen(pattern);
    for (int i = 0; i <= wordLen - patternLen; i++) {
        if (strncmp(word + i, pattern, patternLen) == 0) {
            count++;
        }
    }
    return count;
}

void analyzeWordsAndPatterns() {
    FILE *wordsFile = fopen("words.txt", "r");
    FILE *patternsFile = fopen("patterns.txt", "r");
    char words[NUM_WORDS][MAX_WORD_LENGTH + 1];
    char patterns[NUM_PATTERNS][MAX_PATTERN_LENGTH + 1];
    int i, j;

    if (!wordsFile || !patternsFile) {
        printf("Nie można otworzyć plików.\n");
        return;
    }

    // Read words and patterns from files
    for (i = 0; i < NUM_WORDS; i++) {
        fscanf(wordsFile, "%s", words[i]);
    }
    for (i = 0; i < NUM_PATTERNS; i++) {
        fscanf(patternsFile, "%s", patterns[i]);
    }

    fclose(wordsFile);
    fclose(patternsFile);

    // Task 1: Words starting and ending with the same letter
    int sameStartEnd = 0;
    for (i = 0; i < NUM_WORDS; i++) {
        int len = strlen(words[i]);
        if (words[i][0] == words[i][len - 1]) {
            sameStartEnd++;
        }
    }
    printf("Liczba słów zaczynających i kończących się na tę samą literę: %d\n", sameStartEnd);

    // Task 2: Words containing all letters of the alphabet
    int allLettersCount = 0;
    for (i = 0; i < NUM_WORDS; i++) {
        if (containsAllLetters(words[i])) {
            allLettersCount++;
        }
    }
    printf("Liczba słów zawierających wszystkie litery alfabetu: %d\n", allLettersCount);

    // Task 3: Words with no repeating letters
    int noRepeatsCount = 0;
    for (i = 0; i < NUM_WORDS; i++) {
        if (hasNoRepeatingLetters(words[i])) {
            noRepeatsCount++;
        }
    }
    printf("Liczba słów bez powtarzających się liter: %d\n", noRepeatsCount);

    // Task 4: Word with the highest number of repeating letters
    int maxRepeats = 0;
    char *maxWord = NULL;
    for (i = 0; i < NUM_WORDS; i++) {
        int letterCount[ALPHABET_SIZE] = {0};
        int localMax = 0;
        for (j = 0; words[i][j] != '\0'; j++) {
            letterCount[words[i][j] - 'A']++;
            if (letterCount[words[i][j] - 'A'] > localMax) {
                localMax = letterCount[words[i][j] - 'A'];
            }
        }
        if (localMax > maxRepeats) {
            maxRepeats = localMax;
            maxWord = words[i];
        }
    }
    if (maxWord) {
        printf("Słowo z największą liczbą powtarzających się liter (%d powtórzeń): %s\n", maxRepeats, maxWord);
    }

    // Additional tasks based on patterns
    // Task 5: Patterns not found in any word
    bool patternFound[NUM_PATTERNS] = {false};
    for (i = 0; i < NUM_WORDS; i++) {
        for (j = 0; j < NUM_PATTERNS; j++) {
            if (countPatternOccurrences(words[i], patterns[j]) > 0) {
                patternFound[j] = true;
            }
        }
    }
    printf("Wzorce, które nie występują w żadnym słowie:\n");
    for (i = 0; i < NUM_PATTERNS; i++) {
        if (!patternFound[i]) {
            printf("%s\n", patterns[i]);
        }
    }

    // Task 6: Most frequent pattern in words
    int maxPatternCount = 0;
    char *mostFrequentPattern = NULL;
    for (i = 0; i < NUM_PATTERNS; i++) {
        int currentPatternCount = 0;
        for (j = 0; j < NUM_WORDS; j++) {
            currentPatternCount += countPatternOccurrences(words[j], patterns[i]);
        }
        if (currentPatternCount > maxPatternCount) {
            maxPatternCount = currentPatternCount;
            mostFrequentPattern = patterns[i];
        }
    }
    if (mostFrequentPattern) {
        printf("Najczęściej występujący wzorzec: %s (wystąpił %d razy)\n", mostFrequentPattern, maxPatternCount);
    }

    // Task 7: Word with the most occurrences of a single pattern
    maxRepeats = 0;
    maxWord = NULL;
    for (i = 0; i < NUM_WORDS; i++) {
        for (j = 0; j < NUM_PATTERNS; j++) {
            int patternCount = countPatternOccurrences(words[i], patterns[j]);
            if (patternCount > maxRepeats) {
                maxRepeats = patternCount;
                maxWord = words[i];
            }
        }
    }
    if (maxWord) {
        printf("Słowo z największą liczbą wystąpień jednego wzorca (%d wystąpień): %s\n", maxRepeats, maxWord);
    }
}

int main() {
    analyzeWordsAndPatterns();
    return 0;
}

