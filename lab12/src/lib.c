#include "lib.h"
// Функція для обчислення комбінаційного коефіцієнту C(n, k)
int binomialCoefficient(int n, int k) {
    int res = 1;

    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Функція для формування трикутника Паскаля ітеративним методом
void pascalTriangleIterative(int n) {
    for (int line = 0; line < n; ++line) {
        for (int i = 0; i <= line; ++i) {
            printf("%d ", binomialCoefficient(line, i));
        }
        printf("\n");
    }
}

// Функція для формування трикутника Паскаля рекурсивним методом
void pascalTriangleRecursive(int n) {
    if (n == 0) {
        printf("1\n");
        return;
    }

    pascalTriangleRecursive(n - 1);

    for (int i = 0; i <= n; ++i) {
        printf("%d ", binomialCoefficient(n, i));
    }

    printf("\n");
}



