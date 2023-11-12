#include <stdio.h>

int hasDuplicates(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1; 
            }
        }
    }
    return 0; 
}

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

    if (hasDuplicates(arr, size)) {
        printf("В массиве есть повторяющиеся элементы.\n");
    } else {
        printf("В массиве нет повторяющихся элементов.\n");
    }

    return 0;
}