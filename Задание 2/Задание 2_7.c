#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findClosestToAverage(int arr[], int size) {
    if (size <= 0) {
        return -1; // Возвращаем -1 в случае пустого массива
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    double average = (double)sum / size; // Среднее значение

    int closest = arr[0]; // Начинаем с первого элемента
    int minDifference = abs(arr[0] - average);

    for (int i = 1; i < size; i++) {
        int difference = abs(arr[i] - average);
        if (difference < minDifference) {
            closest = arr[i];
            minDifference = difference;
        }
    }

    return closest;
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Размер массива должен быть положительным.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int closest = findClosestToAverage(arr, size);

    if (closest != -1) {
        printf("Элемент, наиболее близкий к среднему значению: %d\n", closest);
    } else {
        printf("Массив пуст.\n");
    }

    free(arr);

    return 0;
}
