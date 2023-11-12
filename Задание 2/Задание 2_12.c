 #include <stdio.h>
 int arr4[] = {3, 5, 1, 4, 2};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);

    for (i = 0; i < size4 - 1; i++) {
        int maxIdx = i;
        for (j = i + 1; j < size4; j++) {
            if (arr4[j] > arr4[maxIdx]) {
                maxIdx = j;
            }
        }
        int temp = arr4[maxIdx];
        arr4[maxIdx] = arr4[i];
        arr4[i] = temp;
    }

    printf("Упорядоченный массив по неубыванию:\n");
    for (i = 0; i < size4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n");
