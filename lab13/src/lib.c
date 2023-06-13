#include "lib.h"
//в цій функції ми шукаємо найдовше та найкоротше слово
void find_longest_shortest_word(char* text) {
    char longest_word[MAX_LENGTH];
    char shortest_word[MAX_LENGTH];
    int longest_length = 0;
    int shortest_length = MAX_LENGTH;
    char* word;

    word = strtok(text, " \n\t");
    while (word != NULL) {
        int length = strlen(word);
        if (length > longest_length) {
            longest_length = length;
            strcpy(longest_word, word);
        }
        if (length < shortest_length) {
            shortest_length = length;
            strcpy(shortest_word, word);
        }
        word = strtok(NULL, " \n\t");
    }
//тут ми виводимо на екран наші слова 
    printf("Longest word: %s\n", longest_word);
    printf("Shortest word: %s\n", shortest_word);
}
//в цій функції ми спочатку перевіряємо на справність роботу функції, а лише потім запучкаємо функцію яка обчислює найдовше та найкоротше слово
int text() {
    FILE* file;
    char text[MAX_LENGTH];

    file = fopen("assets/input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (fgets(text, MAX_LENGTH, file) == NULL) {
        printf("Error reading file.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    find_longest_shortest_word(text);

    return 0;
}
