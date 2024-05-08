#include <stdio.h>
#include <stdlib.h>

void display(float **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Equation %d: ", i);
        for (int j = 0; j < n; j++)
            printf("%.2fx%d ", arr[i][j], j+1);
        printf("= %.2f\n", arr[i][n]);
    }
    printf("\n");
}

void gaussElimination(float **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float ratio = arr[j][i] / arr[i][i];
            for (int k = 0; k <= n; k++) {
                arr[j][k] -= ratio * arr[i][k];
            }
        }
        display(arr, n);
    }
}

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    float **arr = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++)
        arr[i] = (float *)malloc((n + 1) * sizeof(float));
    printf("Enter the coefficients of the equations: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%f", &arr[i][j]);
    printf("Initial system of equations : \n");
    display(arr, n);
    gaussElimination(arr, n);
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
