void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
}

int main() {
    int n;
    printf("Введите натуральное число: ");
    scanf("%d", &n);

    printf("Числа от 1 до %d: ", n);
    printNumbers(n);

    return 0;
}