#include "gauss.h"

#include <time.h>

size_t randomIndex(size_t min, size_t max) {
	srand(time(NULL));
	size_t r = rand();

	r %= max - min + 1;
	r += min;

	return r;
}

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

	for (size_t i = 0; i < mat->cols; i++) {
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

	for (size_t i = 0; i < mat->cols; i++) {
		row[i] *= coeffRow;
	}

	setMatrixRow(mat, rowId, row);

	free(row);

	return;
}

/*
Function to return the index of the row's pivot in the context
of Gauss' Pivot Algorithm
*/
size_t identifyGaussPivot(Matrix* mat, size_t rowId) {
	double* row = (double*)calloc(mat->cols, sizeof(double));

	getMatrixRow(mat, rowId, row);

	size_t i;
	bool run = true;

	// Iterating until we find a non-null value
	for (i = 0; (i < mat->cols) && run; i++) {
		double val = row[i];
		run = val == 0.0;
	}

	i--; // The for-loop always returns `pivotIndex + 1`, so we take 1 away.

	free(row);

	return i;
}

void swapElements(size_t* arr, size_t a, size_t b) {
	arr[a] += arr[b];
	arr[b] = arr[a] - arr[b];
	arr[a] -= arr[b];
}

void sortingSwap(Matrix* mat, size_t* pivots, size_t idA, size_t idB, Swap** swaps, size_t* swapsMade) {
	swapRows(mat, idA, idB);
	swapElements(pivots, idA, idB);

	*swapsMade += 1;
	printf("%lu <=> %lu\n", idA, idB);
	printf("New size : %lu\n", *swapsMade);

	if (*swapsMade > 1) {
		printf("Old Pointer : %p\n", *swaps);
		Swap* newPtr = (Swap*)realloc(*swaps, *swapsMade * sizeof(Swap));

		if (newPtr != NULL) {
			*swaps = newPtr;
		} else {
			fprintf(stderr, "Error or not enough space available in memory to continue\n");
			exit(EXIT_FAILURE);
		}

		printf("New Pointer : %p\n", *swaps);
	}

	Swap newSwap = {idA, idB};
	(*swaps)[*swapsMade - 1] = newSwap;

	printMatrix(mat);
}

size_t Partitioning(Matrix* mat, size_t firstId, size_t lastId, size_t pivotRowId, Swap** swaps, size_t* swapsMade) {
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	size_t firstRowVal, lastRowVal, pivotRowVal;

	firstRowVal = rowsGaussPivots[firstId];
	lastRowVal = rowsGaussPivots[lastId];
	pivotRowVal = rowsGaussPivots[pivotRowId];

	sortingSwap(mat, rowsGaussPivots, pivotRowId, lastId, swaps, swapsMade);

	size_t j = firstId;

	for (size_t i = 0; i < lastId; i++) {
		if (rowsGaussPivots[i] <= rowsGaussPivots[lastId]) {
			sortingSwap(mat, rowsGaussPivots, i, j, swaps, swapsMade);
			j++;
		}
	}

	sortingSwap(mat, rowsGaussPivots, lastId, j, swaps, swapsMade);

	return j;
}

void QuickSort(Matrix* mat, size_t firstId, size_t lastId, Swap** swaps, size_t* swapsMade) {
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	size_t sortingPivot;
	size_t firstRowVal, lastRowVal, pivotRowVal;

	firstRowVal = rowsGaussPivots[firstId];
	lastRowVal = rowsGaussPivots[lastId];

	free(rowsGaussPivots);

	if (firstRowVal < lastRowVal) {
		sortingPivot = randomIndex(firstId, lastId);
		sortingPivot = Partitioning(mat, firstId, lastId, sortingPivot, swaps, swapsMade);

		QuickSort(mat, firstId, sortingPivot - 1, swaps, swapsMade);
		QuickSort(mat, sortingPivot + 1, lastId, swaps, swapsMade);
	}
}
