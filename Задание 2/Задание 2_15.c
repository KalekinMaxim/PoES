#include <stdio.h>

int main() {
    int x[] = {1, 2, 3, 4, -5, 6, 7};
    int size = sizeof(x) / sizeof(x[0]);
    int y = 0;
    int m = size;
    
    for (int i = 0; i < size; i++) {
        if (x[i] < 0) {
            m = i;
            break;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int product = 1;
        for (int j = 0; j <= i; j++) {
            product *= x[j];
        }
        y += product;
    }
    
    printf("Результат вычисления y: %d\n", y);
