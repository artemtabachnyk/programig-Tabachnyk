/**
 * @file lab.c
 * @brief Файл містить реалізацію функцій для сортування матриці та обробки тексту.
 */

#include "lib.h"

#define MAX_LENGTH 100

/**
 * @brief Знаходить найдовше та найкоротше слово в рядку тексту.
 *
 * Функція приймає рядок тексту `text` і знаходить найдовше та найкоротше слово.
 * Результат виводиться на екран.
 *
 * @param text Рядок тексту для обробки.
 */
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

    printf("Longest word: %s\n", longest_word);
    printf("Shortest word: %s\n", shortest_word);
}

/**
 * @brief Обробляє текстовий файл і знаходить найдовше та найкоротше слово.
 *
 * Функція відкриває файл "home/artem/programig-Tabachnyk/lab14/assets/output.txt" для зчитування тексту.
 * Читає рядок тексту з файлу і передає його функції find_longest_shortest_word.
 * Результат виводиться на екран.
 *
 * @return 0 у разі успішного виконання, 1 у разі помилки.
 */
int text() {
    FILE* file;
    char text[MAX_LENGTH];

    file = fopen("home/artem/programig-Tabachnyk/lab14/assets/output.txt", "r");
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
