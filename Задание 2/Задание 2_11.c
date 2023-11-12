#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0; 
    int j = 0; 
    int k = 0; 


    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }


    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    printf("Введите размер первого массива: ");
    scanf("%d", &size1);
    int arr1[size1];

    printf("Введите элементы первого массива (упорядоченные по неубыванию):\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Введите размер второго массива: ");
    scanf("%d", &size2);
    int arr2[size2];

    printf("Введите элементы второго массива (упорядоченные по неубыванию):\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result[size1 + size2]; // Результат объединения массивов
    mergeArrays(arr1, size1, arr2, size2, result);

    printf("Результат объединения массивов (упорядоченный по неубыванию):\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
