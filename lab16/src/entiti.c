#include "entity.h"
#include <stdlib.h>

/**
 * @brief Створює об'єкт типу Entity.
 * @return Вказівник на новий об'єкт типу Entity або NULL, якщо створення не вдалося.
 */
Entity* createEntity() {
    Entity* entity = malloc(sizeof(Entity));
   

    entity->isOn = 0;
    entity->isBurnedOut = 0;
    entity->manufacturer = NULL;
    entity->switchCount = 0;
    entity->powerConsumption = 0;
    entity->colorTemperature = 0;
   

    return entity;
}

/**
 * @brief Виводить вміст об'єкту типу Entity на екран.
 * @param entity Вказівник на об'єкт типу Entity.
 */
void printEntity(Entity* entity) {
    if (entity == NULL) {
        return;
    }

    printf("Is On: %d\n", entity->isOn);
    printf("Is Burned Out: %d\n", entity->isBurnedOut);
    printf("Manufacturer: %s\n", entity->manufacturer);
    printf("Switch Count: %d\n", entity->switchCount);
    printf("Power Consumption: %d\n", entity->powerConsumption);
    printf("Color Temperature: %d\n", entity->colorTemperature);
    
}

/**
 * @brief Змінює стан включення об'єкту типу Entity.
 * Зменшує лічильник вмикань перегорання, при значенні лічильника 0 встановлює прапор перегорання.
 * @param entity Вказівник на об'єкт типу Entity.
 */
void toggleOn(Entity* entity) {
    if (entity == NULL) {
        return;
    }

    if (entity->switchCount > 0) {
        entity->switchCount--;
    }

    if (entity->switchCount == 0) {
        entity->isBurnedOut = 1;
    }
}

/**
 * @brief Знаходить перегорілі лампочки в заданому масиві об'єктів типу Entity.
 * @param entities Масив вказівників на об'єкти типу Entity.
 * @param size Розмір масиву entities.
 */
void findBurnedOut(Entity** entities, int size) {
    if (entities == NULL || size <= 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        if (entities[i]->isBurnedOut) {
            printf("Burned out lamp found at index %d\n", i);
        }
    }
}

/**
 * @brief Обчислює сумарне споживання ватт, не враховуючи перегорілі лампочки.
 * @param entities Масив вказівників на об'єкти типу Entity.
 * @param size Розмір масиву entities.
 * @return Сумарне споживання ватт.
 */
int calculateTotalPowerConsumption(Entity** entities, int size) {
    if (entities == NULL || size <= 0) {
        return 0;
    }

    int totalPower = 0;

    for (int i = 0; i < size; i++) {
        if (!entities[i]->isBurnedOut) {
            totalPower += entities[i]->powerConsumption;
        }
    }

    return totalPower;
}

