int* sortArray(int arr[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    return arr;
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int arr[size];
    printf("Введите элементы массива:  ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int ascending;
    printf("Введите 1 для сортировки в порядке возрастания или 0 для убывания: ");
    scanf("%d", &ascending);

    int* sortedArr = sortArray(arr, size, ascending);

    printf("Отсортированный массив представляет собой:");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }

    return 0;
}