#include <stdio.h>

int main() {
    int x, y;
	scanf("%d %d", &x, &y);
	if (x == 0 && y == 0){
	    printf("Точка является началом координат");
	}else if(x == 0 || y == 0){
	    printf("Точка лежит на одной из осей");
	}else if(x > 0 && y > 0){
	    printf("Точка лежит в первой четверти");
	}else if(x < 0 && y > 0){
	    printf("Точка лежит во второй четверти");
	}else if(x < 0 && y < 0){
	    printf("Точка лежит в третьей четверти");
	}else{
	    printf("Точка лежит в четвертой четверти");
	}
}