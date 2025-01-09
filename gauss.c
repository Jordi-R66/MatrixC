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
	multiplyRow(mat, rowBId, coeffRowB);
	getMatrixRow(mat, rowBId, rowB);

	for (size_t i=0; i < mat->cols; i++) {
		rowA[i] -= rowB[i];
	}

	setMatrixRow(mat, rowAId, rowA);
	setMatrixRow(mat, rowBId, rowB);

	free(rowA);
	free(rowB);

	return;
}

void multiplyRow(Matrix* mat, size_t rowId, double coeffRow) {
	double* row = (double*)calloc(mat->cols, sizeof(double));

	getMatrixRow(mat, rowId, row);

	for (size_t i=0; i < mat->cols; i++) {
		row[i] *= coeffRow;
	}

	setMatrixRow(mat, rowId, row);

	free(row);

	return;
}
