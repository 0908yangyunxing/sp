#include <stdio.h>
#include <stdlib.h>

// 定義矩陣結構體
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

// 初始化矩陣
Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (double *)malloc(rows * cols * sizeof(double));
    return matrix;
}

// 刪除矩陣
void deleteMatrix(Matrix *matrix) {
    free(matrix->data);
    matrix->data = NULL;
}

// 轉置矩陣
Matrix transposeMatrix(Matrix matrix) {
    Matrix result = createMatrix(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[j * result.cols + i] = matrix.data[i * matrix.cols + j];
        }
    }
    return result;
}

// 矩陣相加
Matrix addMatrices(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "Error: Matrices dimensions must match for addition.\n");
        exit(1);
    }
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i * a.cols + j] = a.data[i * a.cols + j] + b.data[i * a.cols + j];
        }
    }
    return result;
}

// 矩陣相乘
Matrix multiplyMatrices(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        fprintf(stderr, "Error: Matrices dimensions must match for multiplication.\n");
        exit(1);
    }
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i * b.cols + j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i * b.cols + j] += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
        }
    }
    return result;
}

// 印出矩陣
void dumpMatrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%lf ", matrix.data[i * matrix.cols + j]);
        }
        printf("\n");
    }
}

int main() {
    // 矩陣初始化範例
    Matrix a = createMatrix(2, 3);
    Matrix b = createMatrix(2, 3);

    // 設置矩陣數值
    for (int i = 0; i < 6; i++) {
        a.data[i] = i + 1;
        b.data[i] = i + 1;
    }

    // 印出矩陣 a 和 b
    printf("Matrix A:\n");
    dumpMatrix(a);
    printf("Matrix B:\n");
    dumpMatrix(b);

    // 矩陣相加範例
    Matrix sum = addMatrices(a, b);
    printf("Sum of A and B:\n");
    dumpMatrix(sum);

    // 矩陣轉置範例
    Matrix transposed = transposeMatrix(a);
    printf("Transpose of A:\n");
    dumpMatrix(transposed);

    // 矩陣相乘範例
    Matrix c = createMatrix(3, 2);
    for (int i = 0; i < 6; i++) {
        c.data[i] = i + 1;
    }
    Matrix product = multiplyMatrices(a, c);
    printf("Product of A and C:\n");
    dumpMatrix(product);

    // 清除矩陣
    deleteMatrix(&a);
    deleteMatrix(&b);
    deleteMatrix(&c);
    deleteMatrix(&sum);
    deleteMatrix(&transposed);
    deleteMatrix(&product);

    return 0;
}