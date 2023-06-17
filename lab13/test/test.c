/**
 * @file test_lib.c
 * @brief Тестовий файл для модуля lib.
 */

#include <stdlib.h>
#include <check.h>
#include "lib.h"

#define DATA_SIZE 10

/**
 * @brief Тестує функцію find_longest_shortest_word.
 *
 * Перевіряє, чи коректно функція знаходить найдовше та найкоротше слово в тексті.
 * Використовується вхідний текст і відомі результати для перевірки.
 */
START_TEST(test_find_longest_shortest_word)
{
    char input_text[] = "This is a test text to check the function.";
    char expected_longest[] = "function.";
    char expected_shortest[] = "a";

    find_longest_shortest_word(input_text);

    // Assertions
    ck_assert_str_eq(get_longest_word(), expected_longest);
    ck_assert_str_eq(get_shortest_word(), expected_shortest);
}
END_TEST

/**
 * @brief Запускає усі тести для модуля lib.
 *
 * Створюється тестовий набір (suite) та додавання до нього тесту `test_find_longest_shortest_word`.
 * Запускається виконання тестового набору.
 * Перевіряється кількість тестів, які провалилися, та звільняється пам'ять.
 *
 * @return EXIT_SUCCESS, якщо всі тести пройшли успішно, або EXIT_FAILURE у разі невдалого виконання.
 */
int main(void)
{
    Suite *s = suite_create("lib");
    TCase *tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_find_longest_shortest_word);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
