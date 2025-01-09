#include "gauss.h"

void swapRows(Matrix* mat, size_t rowAId, size_t rowBId) {
	double* rowA = (double*)calloc(mat->cols, sizeof(double));
	double* rowB = (double*)calloc(mat->cols, sizeof(double));

	getMatrixRow(mat, rowAId, rowA);
	getMatrixRow(mat, rowBId, rowB);

	setMatrixRow(mat, rowAId, rowB);
	setMatrixRow(mat, rowBId, rowA);

	free(rowA);
	free(rowB);

	return;
}

void subtractRows(Matrix* mat, size_t rowAId, size_t rowBId, double coeffRowB) {
	double* rowA = (double*)calloc(mat->cols, sizeof(double));
	double* rowB = (double*)calloc(mat->cols, sizeof(double));

	getMatrixRow(mat, rowAId, rowA);
	getMatrixRow(mat, rowBId, rowB);

	for (size_t i=0; i < mat->cols; i++) {
		rowA[i] -= coeffRowB * rowB[i];
	}

	setMatrixRow(mat, rowAId, rowA);
	setMatrixRow(mat, rowBId, rowB);

	free(rowA);
	free(rowB);

	return;
}

void multiplyRow(Matrix* mat, size_t rowId, double coeffRow) {
	return;
}
