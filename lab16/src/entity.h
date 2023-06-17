#ifndef ENTITY_H
#define ENTITY_H

/**
 * @brief Перерахування для типів цоколю.
 */
typedef enum {
    E14,
    E27,
    E40
} SocketType;

/**
 * @brief Перерахування для форми лампочки.
 */
typedef enum {
    Candle,
    Tubular,
    Globe,
    Pear,
    Ogive,
    Unknown
} LampShape;

/**
 * @brief Структура, що представляє об'єкт типу Entity.
 */
typedef struct {
    int isOn;                   /**< Чи ввімкнена лампочка (1 - так, 0 - ні). */
    int isBurnedOut;            /**< Чи перегоріла лампочка (1 - так, 0 - ні). */
    char* manufacturer;         /**< Виробник лампочки. */
    int switchCount;            /**< Кількість вмикань лампочки до перегоряння, зворотній лічильник. */
    int powerConsumption;       /**< Кількість ватт, які лампочка споживає кожну годину. */
    int colorTemperature;       /**< Температура кольору світіння лампочки. */
    LampShape shape;            /**< Форма лампочки. */
    SocketType socketType;      /**< Тип цоколю лампочки. */
} Entity;

/**
 * @brief Створює об'єкт типу Entity.
 * @return Вказівник на новий об'єкт типу Entity або NULL, якщо створення не вдалося.
 */
Entity* createEntity();

/**
 * @brief Виводить вміст об'єкту типу Entity на екран.
 * @param entity Вказівник на об'єкт типу Entity.
 */
void printEntity(Entity* entity);

/**
 * @brief Змінює стан включення об'єкту типу Entity.
 * Зменшує лічильник вмикань перегорання, при значенні лічильника 0 встановлює прапор перегорання.
 * @param entity Вказівник на об'єкт типу Entity.
 */
void toggleOn(Entity* entity);

/**
 * @brief Знаходить перегорілі лампочки в заданому масиві об'єктів типу Entity.
 * @param entities Масив вказівників на об'єкти типу Entity.
 * @param size Розмір масиву entities.
 */
void findBurnedOut(Entity** entities, int size);

/**
 * @brief Обчислює сумарне споживання ватт, не враховуючи перегорілі лампочки.
 * @param entities Масив вказівників на об'єкти типу Entity.
 * @param size Розмір масиву entities.
 * @return Сумарне споживання ватт.
 */
int calculateTotalPowerConsumption(Entity** entities, int size);

#endif  // ENTITY_H

