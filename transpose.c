// TRANSPOSE OF MATRIX
#include <stdio.h>
int main() {
    int m = 3, n = 3, i, j, matrix[3][3], transpose[3][3];
    //   printf("Enter rows and columns : ");
    //   scanf("%d", &m);
    //   scanf("%d", &n);

    printf("Enter elements of the matrix : \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d\t", &matrix[i][j]);
        }
    }

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            transpose[j][i] = matrix[i][j];

    printf("Transpose of the matrix: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}