#include<stdio.h>

void input_matrix(int row, int col, int mat[row][col]) {
	int i, j;
	printf("Enter matrix element");
	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void display(int row, int col, int mat[row][col]) {
	int i, j;
	printf("Matrix elements are: \n");
	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%d	", mat[i][j]);
		}
		printf("\n");
	}
}

void mul(int row, int col, int mat[row][col], int mat1[row][col], int result[row][col]) {
	int i, j;
	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			result[i][j] = mat1[i][j] + mat[i][j];
		}
	}
}

int main() {
    int row, column;
    printf("Enter a row and column: ");
    scanf("%d", &row);
	scanf("%d", &column);
	int mat[row][column];
	int mat1[row][column];
	int result[row][column];
	input_matrix(row, column, mat);
	input_matrix(row, column, mat1);
	mul(row, column, mat, mat1, result);
	display(row, column, result);
	
    return 0;
}
