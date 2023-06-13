/**
 * @file test.c
 * @brief Тестовий файл для перевірки функцій з бібліотеки lib.h.
 */
#include <stdlib.h>
#include <check.h>
#include "lib.h"

START_TEST(test_create_triangle)
{
    const char* input_filename = "test_input.txt";
    const char* output_filename = "test_output.txt";

    // Створення тестових вхідних параметрів
    FILE* input_file = fopen(input_filename, "w");
    fprintf(input_file, "4 * 6");
    fclose(input_file);

    // Виклик функції, яку необхідно протестувати
    create_triangle(input_filename, output_filename);

    // Перевірка результату
    FILE* output_file = fopen(output_filename, "r");
    char expected_output[] = "     *     \n"
                             "    ***    \n"
                             "   *****   \n"
                             "  *******  \n";
    char output[100];
    fgets(output, sizeof(output), output_file);
    fclose(output_file);

    ck_assert_str_eq(expected_output, output);
}
END_TEST

Suite* lib_suite(void)
{
    Suite* s;
    TCase* tc_core;

    s = suite_create("Lib");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_triangle);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    Suite* s = lib_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}