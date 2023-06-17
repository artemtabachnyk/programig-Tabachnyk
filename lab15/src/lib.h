/**
 * @file lib.h
 * @brief Заголовочний файл з функціями для обробки даних про лампочки.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

/**
 * @struct Bulb
 * @brief Структура для представлення базової лампочки.
 */
typedef struct {
    char isOn[MAX_LENGTH]; /**< Прапор, що показує, чи ввімкнена лампочка. */
    char isBurnedOut[MAX_LENGTH]; /**< Прапор, що показує, чи перегоріла лампочка. */
    char manufacturer[MAX_LENGTH]; /**< Виробник лампочки. */
    int switchCount; /**< Лічильник вмикань. */
    int wattage; /**< Потужність лампочки (Вт). */
    int colorTemperature; /**< Температура кольору лампочки (К). */
    char shape[MAX_LENGTH]; /**< Форма лампочки. */
    char socketType[MAX_LENGTH]; /**< Тип розетки лампочки. */
} Bulb;

/**
 * @struct SmartBulb
 * @brief Структура для представлення розумної лампочки (спадкоємець 1).
 */
typedef struct {
    Bulb bulb; /**< Базова лампочка. */
    char wirelessControl[MAX_LENGTH]; /**< Прапор, що показує, чи є бездротове керування. */
    char microcontroller[MAX_LENGTH]; /**< Мікроконтролер розумної лампочки. */
    char lightColor[MAX_LENGTH]; /**< Колір світла розумної лампочки. */
} SmartBulb;

/**
 * @brief Функція для вмикання лампочки.
 * @param bulb Вказівник на лампочку, яку треба вмикнути.
 */
void turnOn(Bulb* bulb);

/**
 * @brief Функція для пошуку перегорілих лампочок.
 * @param bulbs Масив лампочок.
 * @param count Кількість лампочок у масиві.
 */
void findBurnedOutBulbs(Bulb* bulbs, int count);

/**
 * @brief Функція для обчислення загальної потужності підключених лампочок.
 * @param bulbs Масив лампочок.
 * @param count Кількість лампочок у масиві.
 * @return Загальна потужність підключених лампочок (Вт).
 */
int calculateTotalWattage(Bulb* bulbs, int count);

/**
 * @brief Функція для вибору всіх розумних лампочок з масиву лампочок.
 * @param bulbs Масив лампочок.
 * @param count Кількість лампочок у масиві.
 * @return Вказівник на масив розумних лампочок або NULL, якщо немає розумних лампочок.
 */
SmartBulb* selectSmartBulbs(Bulb* bulbs, int count);

