#include "entity.h"
#include <stdlib.h>
/**
 * @brief Структура, що представляє вузол списку.
 */
typedef struct Node {
    Entity* entity;      /**< Вказівник на об'єкт типу Entity. */
    struct Node* next;   /**< Вказівник на наступний вузол списку. */
} Node;

/**
 * @brief Структура, що представляє список.
 */
typedef struct {
    Node* head;     /**< Вказівник на голову списку. */
    Node* tail;     /**< Вказівник на хвіст списку. */
} List;

/**
 * @brief Створює новий пустий список.
 * @return Вказівник на новий список або NULL, якщо створення не вдалося.
 */
List* createList();

/**
 * @brief Додає новий об'єкт до кінця списку.
 * @param list Вказівник на список.
 * @param entity Вказівник на об'єкт, який буде доданий до списку.
 * @return 1, якщо додавання вдалося, 0 - якщо додавання не вдалося.
 */
int addToEnd(List* list, Entity* entity);

/**
 * @brief Видаляє об'єкт зі списку за заданим індексом.
 * @param list Вказівник на список.
 * @param index Індекс елемента, який потрібно видалити.
 * @return 1, якщо видалення вдалося, 0 - якщо видалення не вдалося.
 */
int removeFromList(List* list, int index);



