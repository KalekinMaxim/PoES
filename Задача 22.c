#include <stdio.h>

int main() {
    int a, b, nod;

    printf("Введите два положительных целых числа: ");
    scanf("%d %d", &a, &b);
    nod = 1;
    for(int i=1; i <= a && i <= b; i++) {
        if(a % i==0 && b % i==0) {
            nod = i;
        }
    }

    printf("Наибольший общий делитель, %d", nod);
}