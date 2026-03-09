#include <stdio.h>

#define SIZE 5


void printMatrix(int matrix[SIZE][SIZE]) { //prints matrix in a spaced format
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%6d", matrix[i][j]);
		}
		printf("\n");
	}
}


void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) { //adds two matrices
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
}


void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) { //multiplies two matrices and stores the result in a 3rd
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[i][j] = 0;
			for (int k = 0; k < SIZE; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}


void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) { //tranposes the matrix by swapping row and column indicies 
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			result[j][i] = matrix[i][j];  // swaps row and column index
		}
	}
}

int main() {
	int m1[SIZE][SIZE] = {
		{1,  2,  3,  4,  5},
		{6,  7,  8,  9,  10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10,  9,  8,  7,  6},
		{ 5,  4,  3,  2,  1}
	};

	int result[SIZE][SIZE];

	printf("Matrix 1:\n");
	printMatrix(m1);

	printf("\nMatrix 2:\n");
	printMatrix(m2);

	printf("\nMatrix 1 + Matrix 2:\n");
	addMatrices(m1, m2, result);
	printMatrix(result);

	printf("\nMatrix 1 * Matrix 2:\n");
	multiplyMatrices(m1, m2, result);
	printMatrix(result);

	printf("\nTranspose of Matrix 1:\n");
	transposeMatrix(m1, result);
	printMatrix(result);

	printf("\nTranspose of Matrix 2:\n");
	transposeMatrix(m2, result);
	printMatrix(result);

	return 0;
}