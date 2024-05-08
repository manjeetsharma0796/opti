#include <stdio.h>

#define N 10  // Maximum size of matrix

// Function to calculate determinant of matrix
int determinant(int matrix[N][N], int n) {
    int det = 0;
    int submatrix[N][N];  // Submatrix for recursion

    if (n == 1)  // Base case: when matrix size is 1x1
        return matrix[0][0];
    else if (n == 2)  // Base case: when matrix size is 2x2
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    else {
        for (int x = 0; x < n; x++) {  // Iterate through first row to create submatrices
            int subi = 0;              // Row index for submatrix
            for (int i = 1; i < n; i++) {
                int subj = 0;  // Column index for submatrix
                for (int j = 0; j < n; j++) {
                    if (j == x) continue;  // Skip the column if it's the one we're eliminating
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
        }
    }
    return det;
}

int main() {
    int n, matrix[N][N];

    printf("Enter the size of the square matrix (max %d): ", N);
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int det = determinant(matrix, n);
    printf("Determinant of the matrix is: %d\n", det);

    return 0;
}