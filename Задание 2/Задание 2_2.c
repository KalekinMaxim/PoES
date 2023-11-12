void Add_two_Matrix(int m, int n, int matrix1[m][n], int matrix2[m][n]) {
    int result[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
void Subtract_two_Matrix(int m, int n, int matrix1[m][n], int matrix2[m][n]) {
    int result[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
void Multiply_two_Matrix_By_Number(int m, int n, int matrix[m][n], int num) {
    int result[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix[i][j] * num;
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
void Multiply_two_Matrix(int m, int n, int p, int matrix1[m][n], int matrix2[n][p]) {
    int result[m][p];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
void Transpose_Matrix(int m, int n, int matrix[m][n]) {
    int result[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix[j][i];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
int Equal_two_Matrix(int m, int n, int matrix1[m][n], int matrix2[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    int matrix2[2][2] = {{10, 22}, {33, 44}};
    printf("Сложение матриц:\n");
    Add_two_Matrix(2, 2, matrix1, matrix2);
    printf("\nВычитание матриц:\n");
    Subtract_two_Matrix(2, 2, matrix1, matrix2);
    printf("\nУмножение матрицы на число:\n");
    Multiply_two_Matrix_By_Number(2, 2, matrix1, 3);
    printf("\nУмножение матриц:\n");
    Multiply_two_Matrix(2, 2, 2, matrix1, matrix2);
    printf("\nТранспонирование:\n");
    Transpose_Matrix(2, 2, matrix1);
    printf("\nПроверка равенства матриц: %d\n", Equal_two_Matrix(2, 2, matrix1, matrix2));
    return 0;
}