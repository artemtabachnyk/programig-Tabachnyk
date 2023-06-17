#include "list.h"
/**
 * @brief Створює новий пустий список.
 * @return Вказівник на новий список або NULL, якщо створення не вдалося.
 */
List* createList() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

/**
 * @brief Додає новий об'єкт до кінця списку.
 * @param list Вказівник на список.
 * @param entity Вказівник на об'єкт, який буде доданий до списку.
 * @return 1, якщо додавання вдалося, 0 - якщо додавання не вдалося.
 */
int addToEnd(List* list, Entity* entity) {
    if (list == NULL || entity == NULL) {
        return 0;
    }

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }

    newNode->entity = entity;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    return 1;
}

/**
 * @brief Видаляє об'єкт зі списку за заданим індексом.
 * @param list Вказівник на список.
 * @param index Індекс елемента, який потрібно видалити.
 * @return 1, якщо видалення вдалося, 0 - якщо видалення не вдалося.
 */
int removeFromList(List* list, int index) {
    if (list == NULL || index < 0) {
        return 0;
    }

    Node* currentNode = list->head;
    Node* previousNode = NULL;

    int currentIndex = 0;
    while (currentNode != NULL && currentIndex != index) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentNode == NULL) {
        return 0;
    }

    if (previousNode == NULL) {
        list->head = currentNode->next;
    } else {
        previousNode->next = currentNode->next;
    }

    if (currentNode == list->tail) {
        list->tail = previousNode;
    }

    free(currentNode->entity);
    free(currentNode);

    return 1;
}

