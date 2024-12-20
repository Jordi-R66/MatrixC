#include "matrix.h"

void mallocMatrix(Matrix* matrix) {
	matrix->size = matrix->rows * matrix->cols;
	matrix->data = (double*)malloc(matrix->size * sizeof(double));
	matrix->memFreed = false;
}

void deallocMatrix(Matrix* matrix) {
	free(matrix->data);
	matrix->memFreed = true;
}

void getMatrixRow(Matrix* matrix, size_t row, double* rowBuffer) {
	size_t iStart, iEnd;

	iStart = row * matrix->cols;
	iEnd = (row + 1) * matrix->cols;

	for (size_t i = iStart; i < iEnd; i++) {
		rowBuffer[i - iStart] = matrix->data[i];
	}
}

void getMatrixColumn(Matrix* matrix, size_t column, double* colBuffer) {
	for (size_t row = 0; row < matrix->rows; row++) {
		size_t i = row * matrix->cols + column;
		colBuffer[row] = matrix->data[i];
	}
}

void setMatrixCase(Matrix* matrix, double value, size_t row, size_t col) {
	size_t i = row * matrix->cols + col;

	matrix->data[i] = value;
}

double getMatrixCase(Matrix* matrix, size_t row, size_t col) {
	size_t i = row * matrix->cols + col;

	return matrix->data[i];
}

void scalarMul(Matrix* matrix, double scalar) {
	for (size_t i = 0; i < matrix->size; i++) {
		matrix->data[i] *= scalar;
	}
}

/*
	Performs an inefficient matrix multiplication algorithm and stores the resulting matrix in a given address
	Stores the result matDest of matA * matB
*/
void matrixMultiplication(Matrix* matA, Matrix* matB, Matrix* matDest) {
	
}
