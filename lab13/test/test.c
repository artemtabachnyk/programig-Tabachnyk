#include <stdlib.h>
#include <check.h>
#include "lib.h"

START_TEST(test_find_longest_shortest_word)
{
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char expected_longest_word[] = "consectetur";
    char expected_shortest_word[] = "sit";
    char longest_word[MAX_LENGTH];
    char shortest_word[MAX_LENGTH];

    void find_longest_shortest_word(text, longest_word, shortest_word);

    ck_assert_str_eq(expected_longest_word, longest_word);
    ck_assert_str_eq(expected_shortest_word, shortest_word);
}
END_TEST

Suite* string_suite(void)
{
    Suite* s;
    TCase* tc_core;

    s = suite_create("String");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_find_longest_shortest_word);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}