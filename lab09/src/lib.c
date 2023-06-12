#include "lib.h"

int grandom() {
    return rand();
}

int gtime() {
    return (int)time(NULL);
}

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
