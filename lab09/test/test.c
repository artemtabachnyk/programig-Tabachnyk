/**
 * @file test.c
 * @brief Файл з тестами для перевірки функції знаходження послідовності Фібоначчі.
 */

#include <stdlib.h>
#include "lib.h"
#include <check.h>

#define DATA_SIZE 10

/**
 * @brief Тест перевірки функції findFibonachi().
 */
START_TEST(test_findFibonachi)
{
    int expected_Num = 10;
    int expected_arr[DATA_SIZE] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int actual_Num;
    int actual_arr[DATA_SIZE];

    findFibonachi(&actual_Num, actual_arr);

    ck_assert_int_eq(expected_Num, actual_Num);

    for (int i = 0; i < DATA_SIZE; i++) {
        ck_assert_int_eq(expected_arr[i], actual_arr[i]);
    }
}
END_TEST

/**
 * @brief Головна функція для запуску тестів.
 *
 * Створює тестовий набір, додає тестовий випадок, запускає виконання тестів
 * та повертає код успішного або невдалого виконання тестів.
 *
 * @return int Код успішного або невдалого виконання тестів.
 */
int main(void)
{
    Suite *s = suite_create("Programing");
    TCase *tc_core = tcase_create("lab09");

    tcase_add_test(tc_core, test_findFibonachi);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

