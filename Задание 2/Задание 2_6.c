#include <stdio.h>
#include <math.h>

// Функция, для которой ищем корень
double equation(double x) {
    return cos(pow(x, 5)) + pow(x, 4) - 345.3 * x - 23;
}

// Функция для поиска корня методом деления отрезка пополам
double findRoot(double a, double b, double epsilon) {
    double mid = (a + b) / 2;
    if (b - a < epsilon) {
        return mid; 
    }

    double fa = equation(a);
    double fb = equation(b);
    double fmid = equation(mid);

    if (fa * fmid < 0) {
        return findRoot(a, mid, epsilon); 
    } else {
        return findRoot(mid, b, epsilon);     }
}

int main() {
    double a = 0.0; 
    double b = 10.0; 
    double epsilon = 0.001; 

    double root = findRoot(a, b, epsilon);

    printf("Корень уравнения: %lf\n", root);

    return 0;
}