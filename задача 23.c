#include <stdio.h>
#include <math.h>

int main() {
    int a;
    scanf("%d", &a);
    if(a == 1){
        printf("плохо");
    } else if(a == 2){
        printf("неудовлетворительно");
    } else if(a == 3){
        printf("удовлетворитлеьно");
    } else if(a == 4){
        printf("хорошо");
    } else if(a == 5){
        printf("отлично");
    } else {
        printf("неверный балл");
    }
}