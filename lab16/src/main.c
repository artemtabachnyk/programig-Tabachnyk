#include "list.h"
int main() {
    List* list = createList();

    // Додавання об'єктів у кінець списку
    Entity* entity1 = createEntity();
    Entity* entity2 = createEntity();
    Entity* entity3 = createEntity();

    addToEnd(list, entity1);
    addToEnd(list, entity2);
    addToEnd(list, entity3);

    // Вивід вмісту списку на екран
    Node* current = list->head;
    while (current != NULL) {
        printEntity(current->entity);
        current = current->next;
    }

    // Виклик функції №1 з категорії "Методи для роботи з колекцією"
    toggleOn(entity1);

    // Видалення об'єкта зі списку за індексом
    removeFromList(list, 1);

    // Сортування вмісту списку за одним з критеріїв

    // Звільнення пам'яті
    //destroyList(list);

    return 0;
}
