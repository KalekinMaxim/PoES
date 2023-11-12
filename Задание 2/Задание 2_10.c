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

    printf("Введите элементы массива (неубывающая последовательность):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 1; 
    int duplicates = 0; 

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        } else {
            if (count > 1) {
                duplicates++;
            }
            count = 1; 
        }
    }

    if (count > 1) {
        duplicates++;
    }

    printf("Количество элементов, равных между собой и идущих подряд: %d\n", duplicates);

    return 0;
}