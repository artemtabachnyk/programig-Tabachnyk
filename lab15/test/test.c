#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Оголошення структури для базової лампочки
typedef struct {
    char isOn[MAX_LENGTH];
    char isBurnedOut[MAX_LENGTH];
    char manufacturer[MAX_LENGTH];
    int switchCount;
    int wattage;
    int colorTemperature;
    char shape[MAX_LENGTH];
    char socketType[MAX_LENGTH];
} Bulb;

// Оголошення структури для розумної лампочки (спадкоємець 1)
typedef struct {
    Bulb bulb;
    char wirelessControl[MAX_LENGTH];
    char microcontroller[MAX_LENGTH];
    char lightColor[MAX_LENGTH];
} SmartBulb;

// Оголошення структури для вічної лампочки (спадкоємець 2)
typedef struct {
    Bulb bulb;
} EternalBulb;

// Оголошення функцій
void turnOn(Bulb* bulb);
void findBurnedOutBulbs(Bulb* bulbs, int count);
int calculateTotalWattage(Bulb* bulbs, int count);
SmartBulb* selectSmartBulbs(Bulb* bulbs, int count);
void printBulbInfo(Bulb* bulb);
void printSmartBulbInfo(SmartBulb* smartBulb);
void printEternalBulbInfo(EternalBulb* eternalBulb);

START_TEST(test_turnOn)
{
    Bulb bulb;
    strcpy(bulb.isBurnedOut, "no");
    bulb.switchCount = 1;

    turnOn(&bulb);

    ck_assert_str_eq(bulb.isOn, "yes");
    ck_assert_int_eq(bulb.switchCount, 0);
}

START_TEST(test_findBurnedOutBulbs)
{
    Bulb bulbs[] = {
        { .isBurnedOut = "no" },
        { .isBurnedOut = "yes" },
        { .isBurnedOut = "no" },
        { .isBurnedOut = "yes" }
    };

    int numBulbs = sizeof(bulbs) / sizeof(Bulb);

    findBurnedOutBulbs(bulbs, numBulbs);
}

START_TEST(test_calculateTotalWattage)
{
    Bulb bulbs[] = {
        { .isBurnedOut = "no", .wattage = 60 },
        { .isBurnedOut = "yes", .wattage = 100 },
        { .isBurnedOut = "no", .wattage = 40 },
        { .isBurnedOut = "no", .wattage = 75 }
    };

    int numBulbs = sizeof(bulbs) / sizeof(Bulb);

    int totalWattage = calculateTotalWattage(bulbs, numBulbs);

    ck_assert_int_eq(totalWattage, 175);
}

START_TEST(test_selectSmartBulbs)
{
    Bulb bulbs[] = {
        { .isBurnedOut = "no", .wirelessControl = "yes" },
        { .isBurnedOut = "yes", .wirelessControl = "no" },
        { .isBurnedOut = "no", .wirelessControl = "yes" },
        { .isBurnedOut = "no", .wirelessControl = "yes" }
    };

    int numBulbs = sizeof(bulbs) / sizeof(Bulb);

    SmartBulb* smartBulbs = selectSmartBulbs(bulbs, numBulbs);

    ck_assert_ptr_nonnull(smartBulbs);

    for (int i = 0; smartBulbs[i].bulb.isOn != NULL; i++) {
        ck_assert_str_eq(smartBulbs[i].wirelessControl, "yes");
    }

    free(smartBulbs);
}

int main(void)
{
    Suite *s = suite_create("Programming");
    TCase *tc_core = tcase_create("lab");

    tcase_add_test(tc_core, test_turnOn);
    tcase_add_test(tc_core, test_findBurnedOutBulbs);
    tcase_add_test(tc_core, test_calculateTotalWattage);
    tcase_add_test(tc_core, test_selectSmartBulbs);

    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
