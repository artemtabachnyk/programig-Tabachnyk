/**
 * @file lib.c
 * @brief Програма для створення рівнобедреного трикутника у файлі.
 */

#include "lib.h"

/**
 * @brief Створює рівнобедрений трикутник із заданих символів у файлі.
 *
 * @param input_filename Ім'я вхідного файлу з параметрами трикутника.
 * @param output_filename Ім'я результуючого файлу для збереження трикутника.
 */
void create_triangle(const char* input_filename, const char* output_filename) {
    int height, width;
    char fill_char;

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    fscanf(input_file, "%d %c %d", &height, &fill_char, &width);
    fclose(input_file);

    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= 2 * width - 1; j++) {
            if (j >= width - i + 1 && j <= width + i - 1) {
                fprintf(output_file, "%c", fill_char);
            } else {
                fprintf(output_file, " ");
            }
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);
}

/**
 * @brief Функція triagle, яка викликає створення трикутника.
 *
 * @param argc Кількість аргументів командного рядка.
 * @param argv Масив аргументів командного рядка.
 * @return int Код завершення програми.
 */
int triagle(int argc, char* argv[]) {
    char* input_filename = "home/artem/programig-Tabachnyk/lab14/assets/input.txt";
    char* output_filename = "home/artem/programig-Tabachnyk/lab14/assets/output.txt";
    
    if (argc < 3) {
        printf("Usage: ./program input_file output_file\n");
        return 1;
    }
    create_triangle(input_filename, output_filename);

    return 0;
}
