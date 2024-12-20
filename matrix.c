#include "matrix.h"

void mallocMatrix(Matrix* matrix) {
	matrix->elements = matrix->rows * matrix->cols;
	matrix->data = (double*)malloc(matrix->elements * sizeof(double));
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
