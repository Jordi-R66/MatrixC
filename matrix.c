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
