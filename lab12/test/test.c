/**
 * @file test_lib.c
 * @brief Тестовий файл для функцій трикутника Паскаля
 */

#include <stdio.h>
#include <check.h>
#include "lib.h"

// Функція для перевірки результатів генерації трикутника Паскаля за допомогою ітеративного методу
START_TEST(test_pascalTriangleIterative)
{
    int n = 5;
    int expected_output[5][5] = {{1},
                                {1, 1},
                                {1, 2, 1},
                                {1, 3, 3, 1},
                                {1, 4, 6, 4, 1}};
    int output[5][5];

    pascalTriangleIterative(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &output[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            ck_assert_int_eq(expected_output[i][j], output[i][j]);
        }
    }
}
END_TEST

// Функція для перевірки результатів генерації трикутника Паскаля за допомогою рекурсивного методу
START_TEST(test_pascalTriangleRecursive)
{
    int n = 5;
    int expected_output[5][5] = {{1},
                                {1, 1},
                                {1, 2, 1},
                                {1, 3, 3, 1},
                                {1, 4, 6, 4, 1}};
    int output[5][5];

    pascalTriangleRecursive(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &output[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            ck_assert_int_eq(expected_output[i][j], output[i][j]);
        }
    }
}
END_TEST

/**
 * @brief Функція для запуску всіх тестів
 * 
 * @return кількість неуспішних тестів
 */
int main()
{
    int number_failed;
    
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
    // Створення нової набору тестів
    Suite *s = suite_create("Programing");

    // Додавання нової набору випадків тестування до набору тестів
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_pascalTriangleIterative);
    tcase_add_test(tc_core, test_pascalTriangleRecursive);

    suite_add_tcase(s, tc_core);

    // Створення нового прогону тестів
    TCase *tc_core = tcase_create("lab012");

    // Запуск всіх тестів
    srunner_run_all(sr, CK_VERBOSE);

    // Отримання кількості неуспішних тестів
    number_failed = srunner_ntests_failed(sr);

    // Виведення результатів тестування
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
