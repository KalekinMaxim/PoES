#include <stdio.h>
#include <math.h>

int main() {
    int r, i, n, score;
    scanf("%d", &n);
    score = 1;
    i = 0;
    while(score != 0){
        i++;
        score = n/(pow(10, i));
    }
    printf("%d \n", i);
    for(int j=1; j <= i; j++){
        r = pow(10, j);
        score = n % r / pow(10, j-1);
        printf("%d", score);
    }
}