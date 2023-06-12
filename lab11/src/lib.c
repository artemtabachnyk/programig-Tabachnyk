#include "lib.h"

void sort(int** matrix, int N, int* result) {
    int i, j, k = 0;
    int* temp = (int*)malloc(N * sizeof(int));

    // Отримання елементів головної діагоналі
    for (i = 0; i < N; i++) {
        temp[i] = matrix[i][i];
    }

    // Сортування елементів головної діагоналі за зростанням
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    // Копіювання відсортованих елементів в результат
    for (i = 0; i < N; i++) {
        result[i] = temp[i];
    }
    free(temp);
}
    
    int matrix(){
       int N, i, j;
    srand(time(NULL));
    printf("Введіть розмір матриці: ");
    scanf("%d", &N);

    // Виділення пам'яті для матриці
    int** matrix = (int**)malloc(N * sizeof(int*));
    for (i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }
    // Заповнення матриці рандомними числами, щоб користувачу не треба було вручну вводити всі числа
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10 + 10;
        }
    }

    // Виділення пам'яті для результату
    int* result = (int*)malloc(N * sizeof(int));

    // Виклик функції flatten_and_sort
    sort(matrix, N, result);

    printf("Результат:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Звільнення пам'яті
    for (i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(result);

    return 0;
}