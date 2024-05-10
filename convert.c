#include <stdio.h>

int main() {
  int a[10][10], b[10][10], b1[10][10], sum[10][10];
  int r, c, r1, c1, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &r);
  printf("Enter the number of columns: ");
  scanf("%d", &c);

  printf("\nEnter elements of A matrix:\n");
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      printf("Enter element a%d%d: ", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }

  printf("The A matrix is:\n");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }

  printf("Enter the number of rows of B matrix: ");
  scanf("%d", &r1);
  printf("Enter the number of columns of B matrix: ");
  scanf("%d", &c1);

  printf("Enter the elements of the B matrix:\n");
  for (i = 0; i < r1; i++) {
    for (j = 0; j < c1; j++) {
      printf("Enter the element b%d%d: ", i + 1, j + 1);
      scanf("%d", &b[i][j]);
    }
  }

  printf("The B matrix is:\n");
  for (i = 0; i < r1; i++) {
    for (j = 0; j < c1; j++) {
      printf("%d\t", b[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < c1; i++) {
    for (j = 0; j < r1; j++) {
      b1[i][j] = b[j][i];
    }
  }

  printf("Transpose B matrix:\n");
  for (i = 0; i < c1; i++) {
    for (j = 0; j < r1; j++) {
      printf("%d\t", b1[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      sum[i][j] = a[i][j] + b1[i][j];
    }
  printf("\nSum of two matrices: \n");
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      printf("%d\t", sum[i][j]);
    }
    printf("\n\n");
  }

  return 0;
}
