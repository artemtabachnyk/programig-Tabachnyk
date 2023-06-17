/**
 * @file test.c
 * @brief Тестовий файл для перевірки функції sort.
 */

#include <stdlib.h>
#include <check.h>
#include "lib.h"

#define DATA_SIZE 10

/**
 * @brief Тестова функція для перевірки функції sort.
 */
START_TEST(test_flatten_and_sort)
{
    int N = 3;
    int input_matrix[3][3] = {{3, 2, 1},
                              {6, 5, 4},
                              {9, 8, 7}};
    int expected_result[DATA_SIZE] = {1, 5, 9};
    int actual_result[DATA_SIZE];

    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            matrix[i][j] = input_matrix[i][j];
        }
    }

    sort(matrix, N, actual_result);

    for (int i = 0; i < DATA_SIZE; i++) {
        ck_assert_int_eq(expected_result[i], actual_result[i]);
    }

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/**
 * @brief Функція main, яка викликає тести.
 *
 * Функція створює тести та запускає їх за допомогою фреймворка Check.
 * Після виконання тестів повертається код успішного завершення (0),
 * якщо всі тести пройшли успішно, або код невдачі (1) в іншому випадку.
 *
 * @return Код успішного виконання тестів.
 */
int main(void)
{
    Suite* s = suite_create("Programing");
    TCase* tc_core = tcase_create("lab11");

    tcase_add_test(tc_core, test_flatten_and_sort);
    suite_add_tcase(s, tc_core);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
