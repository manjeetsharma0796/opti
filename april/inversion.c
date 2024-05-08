#include <stdio.h>
#include <stdlib.h>

float determinant(float **matrix, int n);
void getCofactor(float **matrix, float **temp, int p, int q, int n);
float **allocateMatrix(int n);
void freeMatrix(float **matrix, int n);

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    // Allocate memory for the matrix
    float **matrix = allocateMatrix(n);

    // Input elements of the matrix from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Calculate determinant
    float det = determinant(matrix, n);
    printf("Determinant of the matrix: %.2f\n", det);

    // Free dynamically allocated memory
    freeMatrix(matrix, n);
    return 0;
}

float determinant(float **matrix, int n) {
    float det = 0;
    if (n == 1) {
        return matrix[0][0];
    } else {
        float **temp = allocateMatrix(n);
        int sign     = 1;
        for (int f = 0; f < n; f++) {
            getCofactor(matrix, temp, 0, f, n);
            det += sign * matrix[0][f] * determinant(temp, n - 1);
            sign = -sign;
        }
        freeMatrix(temp, n);
    }
    return det;
}

void getCofactor(float **matrix, float **temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float **allocateMatrix(int n) {
    float **matrix = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (float *)malloc(n * sizeof(float));
    }
    return matrix;
}

void freeMatrix(float **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}