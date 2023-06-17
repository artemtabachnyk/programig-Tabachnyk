#include "list.h"
#include <check.h>

START_TEST(testAddRemoveEntity)
{
    List* entityList = createList();

    Entity entity1, entity2;
    initializeEntity(&entity1, "Entity 1");
    initializeEntity(&entity2, "Entity 2");

    ck_assert_int_eq(entityList->size, 0);

    addToEnd(entityList, &entity1);
    addToEnd(entityList, &entity2);

    ck_assert_int_eq(entityList->size, 2);

    removeFromList(entityList, 0);

    ck_assert_int_eq(entityList->size, 1);

    free(entityList);
}
END_TEST

START_TEST(testDisplayEntityList)
{
    List* entityList = createList();

    Entity entity1, entity2;
    initializeEntity(&entity1, "Entity 1");
    initializeEntity(&entity2, "Entity 2");

    ck_assert_int_eq(entityList->size, 0);

    addToEnd(entityList, &entity1);
    addToEnd(entityList, &entity2);

    ck_assert_int_eq(entityList->size, 2);

    displayList(entityList);

    free(entityList);
}
END_TEST

Suite* entitySuite() {
    Suite* s = suite_create("Entity");

    TCase* tc_entity = tcase_create("EntityList");
    tcase_add_test(tc_entity, testAddRemoveEntity);
    tcase_add_test(tc_entity, testDisplayEntityList);
    suite_add_tcase(s, tc_entity);

    return s;
}

int main(void) {
    Suite* s = entitySuite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

