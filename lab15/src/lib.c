#include "lib.h"

/**
 * Вмикання лампочки.
 *
 * @param bulb Вказівник на лампочку, яку потрібно вмикнути
 */
void turnOn(Bulb* bulb);

/**
 * Пошук перегорілих лампочок у масиві.
 *
 * @param bulbs Масив лампочок
 * @param count Кількість лампочок у масиві
 */
void findBurnedOutBulbs(Bulb* bulbs, int count);

/**
 * Обчислення загальної потужності (Вт) всіх не перегорілих лампочок у масиві.
 *
 * @param bulbs Масив лампочок
 * @param count Кількість лампочок у масиві
 * @return Загальна потужність (Вт)
 */
int calculateTotalWattage(Bulb* bulbs, int count);

/**
 * Вибір всіх розумних лампочок з масиву.
 * У цьому прикладі вибираються тільки лампочки з бездротовим керуванням.
 *
 * @param bulbs Масив лампочок
 * @param count Кількість лампочок у масиві
 * @return Вказівник на масив розумних лампочок, або NULL, якщо немає розумних лампочок
 */
SmartBulb* selectSmartBulbs(Bulb* bulbs, int count);

/**
 * Виведення інформації про лампочку на екран.
 *
 * @param bulb Вказівник на лампочку
 */
void printBulbInfo(Bulb* bulb);

/**
 * Виведення інформації про розумну лампочку на екран.
 *
 * @param smartBulb Вказівник на розумну лампочку
 */
void printSmartBulbInfo(SmartBulb* smartBulb);

/**
 * Виведення інформації про вічну лампочку на екран.
 *
 * @param eternalBulb Вказівник на вічну лампочку
 */
void printEternalBulbInfo(EternalBulb* eternalBulb);



void turnOn(Bulb* bulb) {
    // Логіка для вмикання лампочки
    // Зменшення лічильника вмикань перегорання
    bulb->switchCount--;

    // Якщо лічильник досягнув 0, встановлюємо прапор перегорання
    if (bulb->switchCount == 0) {
        strcpy(bulb->isBurnedOut, "yes");
    }
}

void findBurnedOutBulbs(Bulb* bulbs, int count) {
    // Логіка для пошуку перегорілих лампочок
    for (int i = 0; i < count; i++) {
        if (strcmp(bulbs[i].isBurnedOut, "yes") == 0) {
            printf("Burned out bulb found!\n");
            printBulbInfo(&bulbs[i]);
        }
    }
}

int calculateTotalWattage(Bulb* bulbs, int count) {
    int totalWattage = 0;
    // Логіка для обчислення сумарного споживання (Вт)
    for (int i = 0; i < count; i++) {
        if (strcmp(bulbs[i].isBurnedOut, "no") == 0) {
            totalWattage += bulbs[i].wattage;
        }
    }
    return totalWattage;
}

SmartBulb* selectSmartBulbs(Bulb* bulbs, int count) {
    // Логіка для вибору всіх розумних лампочок
    // Приклад реалізації, яка вибирає тільки лампочки з бездротовим керуванням
    int smartBulbCount = 0;
    SmartBulb* smartBulbs = malloc(count * sizeof(SmartBulb));

    for (int i = 0; i < count; i++) {
        if (strcmp(bulbs[i].isBurnedOut, "no") == 0 && strcmp(bulbs[i].wirelessControl, "yes") == 0) {
            smartBulbs[smartBulbCount].bulb = bulbs[i];
            smartBulbCount++;
        }
    }

    if (smartBulbCount == 0) {
        free(smartBulbs);
        return NULL;
    } else {
        return smartBulbs;
    }
}

void printBulbInfo(Bulb* bulb) {
    printf("Bulb Information:\n");
    printf("Is On: %s\n", bulb->isOn);
    printf("Is Burned Out: %s\n", bulb->isBurnedOut);
    printf("Manufacturer: %s\n", bulb->manufacturer);
    printf("Switch Count: %d\n", bulb->switchCount);
    printf("Wattage: %d\n", bulb->wattage);
    printf("Color Temperature: %d\n", bulb->colorTemperature);
    printf("Shape: %s\n", bulb->shape);
    printf("Socket Type: %s\n", bulb->socketType);
    printf("\n");
}

void printSmartBulbInfo(SmartBulb* smartBulb) {
    printf("Smart Bulb Information:\n");
    printBulbInfo(&smartBulb->bulb);
    printf("Wireless Control: %s\n", smartBulb->wirelessControl);
    printf("Microcontroller: %s\n", smartBulb->microcontroller);
    printf("Light Color: %s\n", smartBulb->lightColor);
    printf("\n");
}

void printEternalBulbInfo(EternalBulb* eternalBulb) {
    printf("Eternal Bulb Information:\n");
    printBulbInfo(&eternalBulb->bulb);
    printf("\n");
}