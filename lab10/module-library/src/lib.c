/**

@file lib.c
@brief Файл з реалізацією функцій для генерації випадкових чисел та обчислення послідовності Фібоначчі.
*/
#include "lib.h"

/**

@brief Генерує випадкове число.
@return int Випадкове число.
*/
int grandom() {
return rand();
}
/**

@brief Отримує поточний час.
@return int Поточний час.
*/
int gtime() {
return (int)time(NULL);
}
/**

@brief Знаходить послідовність Фібоначчі та виводить її елементи.

@return int Завершений код програми.
*/
int findFibonachi() {
srand(time(NULL));
int Num = random() % 10 + 10;
int arr[Num];
printf("Сгенероване число %d\n", Num);

int xxx = 0, yyy = 1, zzz, ccc = 0, iii;

do {
arr[ccc] = xxx;
ccc += 1;
zzz = xxx + yyy;
xxx = yyy;
yyy = zzz;
} while (xxx < 1000);

for (iii = 0; iii < Num; iii++) {
printf(" %d", arr[iii]);
}

return 0;
}