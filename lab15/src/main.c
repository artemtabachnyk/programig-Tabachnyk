/**
 * @file main.c
 * @brief Головний файл програми, що використовує функції з бібліотеки lib.h для обробки даних про лампочки.
 */

#include "lib.h"
/**
 * @brief Функція, яка виконує головну логіку програми.
 * @return Код завершення програми.
 */
int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int bulbCount;
    fscanf(file, "%d", &bulbCount);
    Bulb* bulbs = malloc(bulbCount * sizeof(Bulb));

    for (int i = 0; i < bulbCount; i++) {
        fscanf(file, "%s %s %s %d %d %d %s %s",
               bulbs[i].isOn,
               bulbs[i].isBurnedOut,
               bulbs[i].manufacturer,
               &bulbs[i].switchCount,
               &bulbs[i].wattage,
               &bulbs[i].colorTemperature,
               bulbs[i].shape,
               bulbs[i].socketType);
    }

    fclose(file);

    // Використовуємо функції для виконання різних операцій з лампочками
    for (int i = 0; i < bulbCount; i++) {
        printBulbInfo(&bulbs[i]);
    }

    SmartBulb* smartBulbs = selectSmartBulbs(bulbs, bulbCount);
    if (smartBulbs != NULL) {
        for (int i = 0; smartBulbs[i].bulb.isOn != NULL; i++) {
            printSmartBulbInfo(&smartBulbs[i]);
        }
    }

    free(bulbs);
    free(smartBulbs);
    return 0;
}
