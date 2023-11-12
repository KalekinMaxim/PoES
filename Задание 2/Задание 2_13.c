#include <stdio.h>

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Размер массива должен быть положительным.\n");
        return 1;
    }

    int arr[size];

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Максимальный и минимальный элементы
    int maxElement = arr[0];
    int minElement = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }

    // Начальный и конечный индексы
    int start = (maxIndex < minIndex) ? maxIndex : minIndex;
    int end = (maxIndex > minIndex) ? maxIndex : minIndex;

    int sum = 0;

    // Суммируем элементы
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }

    printf("Сумма элементов между максимальным и минимальным элементами: %d\n", sum);

    return 0;
}
