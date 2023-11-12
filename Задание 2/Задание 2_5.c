#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для перебора элементов в массиве
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Найден элемент, возвращаем индекс
        }
    }
    return -1; // Элемент не найден
}

// Функция для двоичного поиска элемента в отсортированном массиве
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // Найден элемент, возвращаем индекс
        }
        
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target); // Рекурсивный поиск в левой половине
        }
        
        return binarySearch(arr, mid + 1, right, target); // Рекурсивный поиск в правой половине
    }
    
    return -1; // Элемент не найден
}

int main() {
    const int size = 100000000; // Размер массива
    int* arr = (int*)malloc(size * sizeof(int));

    // Заполняем массив случайными числами и сортируем его
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    int target = size - 1; // Элемент, который будем искать

    // Измеряем время выполнения линейного поиска
    clock_t start = clock();
    int linearResult = linearSearch(arr, size, target);
    clock_t end = clock();
    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Измеряем время выполнения двоичного поиска
    start = clock();
    int binaryResult = binarySearch(arr, 0, size - 1, target);
    end = clock();
    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (linearResult != -1) {
        printf("Линейный поиск: Элемент %d найден на индексе %d, время выполнения: %f сек\n", target, linearResult, linearTime);
    } else {
        printf("Линейный поиск: Элемент %d не найден, время выполнения: %f сек\n", target, linearTime);
    }

    if (binaryResult != -1) {
        printf("Двоичный поиск: Элемент %d найден на индексе %d, время выполнения: %f сек\n", target, binaryResult, binaryTime);
    } else {
        printf("Двоичный поиск: Элемент %d не найден, время выполнения: %f сек\n", target, binaryTime);
    }

    free(arr);

    return 0;
}