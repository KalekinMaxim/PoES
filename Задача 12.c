#include <stdio.h>

int main() {
    int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a > 0 && b > 0 && c > 0){
	    if (a + b > c && b + c > a && a + c > b){
          if (a == b && a == c){
             printf("Треугольник существует, причем равносторонний");
         }else if (a == b || b == c || a == c){
                printf("Треугольник существует, причем равнобедренный");
            }else{
                printf("Треугольник существует, причем разносторонний");
            }
        } else{
        printf("Треугольник с такими сторонами не существует");
        }
	}
    else {
        printf("Длинна отрезка не может быть отрицательной");
    }
}