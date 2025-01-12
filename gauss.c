<<<<<<< Updated upstream
#include "gauss.h"

void swapRows(Matrix* mat, size_t rowAId, size_t rowBId) {
	if (rowAId == rowBId) {
		return;
	}

	if ((rowAId >= mat->rows) || (rowBId >= mat->rows)) {
		fprintf(stderr, "Error: row index out of bounds\n\tidA = %lu\n\t idB = %lu\n", rowAId, rowBId);
		exit(EXIT_FAILURE);
	}

	double* rowA = (double*)calloc(mat->cols, sizeof(double));
	double* rowB = (double*)calloc(mat->cols, sizeof(double));

	getMatrixRow(mat, rowAId, rowA);
	getMatrixRow(mat, rowBId, rowB);

	setMatrixRow(mat, rowAId, rowB);
	setMatrixRow(mat, rowBId, rowA);

	free(rowB);
	free(rowA);

	return;
}

void subtractRows(Matrix* mat, size_t rowAId, size_t rowBId, double coeffRowB) {
	double* rowA = (double*)calloc(mat->cols, sizeof(double));
	double* rowB = (double*)calloc(mat->cols, sizeof(double));

	getMatrixRow(mat, rowAId, rowA);
	getMatrixRow(mat, rowBId, rowB);

	for (size_t i = 0; i < mat->cols; i++) {
		rowA[i] -= coeffRowB * rowB[i];
	}

	setMatrixRow(mat, rowAId, rowA);

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
	size_t c;

	c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}

size_t chooseSortingPivot(size_t min, size_t max) {
	//return (min + max) / 2;
	return 0;
	//return randomIndex(min, max);
}

void sortingSwap(Matrix* mat, size_t* pivots, size_t idA, size_t idB, Swap** swaps, size_t* swapsMade) {
	if (idA == idB) {
		return;
	}

	swapRows(mat, idA, idB);
	swapElements(pivots, idA, idB);

	*swapsMade += 1;

	Swap* newPtr = (Swap*)realloc(*swaps, *swapsMade * sizeof(Swap));

	if (newPtr != NULL) {
		*swaps = newPtr;
	}
	else {
		fprintf(stderr, "Error or not enough space available in memory to continue\n");
		exit(EXIT_FAILURE);
	}

	Swap newSwap = { idA, idB };
	(*swaps)[*swapsMade - 1] = newSwap;
}

/* -- QuickSort implementation, needs to be fixed so implemented BubbleSort instead
size_t Partitioning(Matrix* mat, size_t firstId, size_t lastId, size_t pivotRowId, Swap** swaps, size_t* swapsMade) {
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
		//printf("%lu\t", rowsGaussPivots[i]);
	}
	//printf("\n\n");

	size_t firstRowVal, lastRowVal, pivotRowVal;

	firstRowVal = rowsGaussPivots[firstId];
	lastRowVal = rowsGaussPivots[lastId];
	pivotRowVal = rowsGaussPivots[pivotRowId];

	//printf("Call A : idA = %lu\tidB = %lu\n", pivotRowId, lastId);
	sortingSwap(mat, rowsGaussPivots, pivotRowId, lastId, swaps, swapsMade);

	size_t j = firstId;

	for (size_t i = firstId; i < lastId; i++) {
		if (rowsGaussPivots[i] <= rowsGaussPivots[lastId]) {
			//printf("Call B : idA = %lu\tidB = %lu\n", i, j);
			sortingSwap(mat, rowsGaussPivots, i, j, swaps, swapsMade);
			j++;
		}
	}

	//printf("Call C : idA = %lu\tidB = %lu\n", lastId, j);
	sortingSwap(mat, rowsGaussPivots, lastId, j, swaps, swapsMade);

	free(rowsGaussPivots);

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
		printf("firstId = %lu\tlastId = %lu\n", firstId, lastId);
		sortingPivot = chooseSortingPivot(firstId, lastId);
		sortingPivot = Partitioning(mat, firstId, lastId, sortingPivot, swaps, swapsMade);

		QuickSort(mat, firstId, sortingPivot - 1, swaps, swapsMade);
		QuickSort(mat, sortingPivot + 1, lastId, swaps, swapsMade);
	}
}
*/

void BubbleSort(Matrix* mat, Swap** swaps, size_t* swapsMade) {
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	size_t i, j;
	size_t n = mat->rows;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (rowsGaussPivots[j] > rowsGaussPivots[j + 1]) {
				sortingSwap(mat, rowsGaussPivots, j, j + 1, swaps, swapsMade);
			}
		}
	}

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	free(rowsGaussPivots);
}

void prepareGauss(Matrix* mat, Swap** swaps, size_t* swapsMade) {
	*swaps = (Swap*)malloc(1 * sizeof(Swap));
	*swapsMade = 0;

	//QuickSort(mat, 0, mat->rows - 1, swaps, swapsMade);
	BubbleSort(mat, swaps, swapsMade);
}

void Gauss(Matrix* mat) {
	Swap* swaps;
	size_t swapsMade;

	double* col = (double*)calloc(mat->rows, sizeof(double));

	prepareGauss(mat, &swaps, &swapsMade);
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	for (size_t i = 0; i < mat->rows; i++) {
		getMatrixColumn(mat, i, col);

		if (col[i] != 0) {
			for (size_t j = i + 1; j < mat->rows; j++) {
				double coeff = col[j] / col[i];
				printf("i, j = %lu, %lu\n", i, j);
				subtractRows(mat, j, i, coeff);
			}
		}
	}

	free(rowsGaussPivots);
	free(col);
	free(swaps);
=======
#include "gauss.h"

void swapRows(Matrix* mat, size_t rowAId, size_t rowBId) {
	if (rowAId == rowBId) {
		return;
	}

	if ((rowAId >= mat->rows) || (rowBId >= mat->rows)) {
		fprintf(stderr, "Error: row index out of bounds\n\tidA = %lu\n\t idB = %lu\n", rowAId, rowBId);
		exit(EXIT_FAILURE);
	}

	value_t* rowA = (value_t*)calloc(mat->cols, sizeof(value_t));
	value_t* rowB = (value_t*)calloc(mat->cols, sizeof(value_t));

	getMatrixRow(mat, rowAId, rowA);
	getMatrixRow(mat, rowBId, rowB);

	setMatrixRow(mat, rowAId, rowB);
	setMatrixRow(mat, rowBId, rowA);

	free(rowB);
	free(rowA);

	return;
}

void subtractRows(Matrix* mat, size_t rowAId, size_t rowBId, value_t coeffRowB) {
	value_t* rowA = (value_t*)calloc(mat->cols, sizeof(value_t));
	value_t* rowB = (value_t*)calloc(mat->cols, sizeof(value_t));

	getMatrixRow(mat, rowAId, rowA);
	getMatrixRow(mat, rowBId, rowB);

	for (size_t i = 0; i < mat->cols; i++) {
		rowA[i] -= coeffRowB * rowB[i];
	}

	setMatrixRow(mat, rowAId, rowA);

	free(rowA);
	free(rowB);

	return;
}

void multiplyRow(Matrix* mat, size_t rowId, value_t coeffRow) {
	value_t* row = (value_t*)calloc(mat->cols, sizeof(value_t));

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
	value_t* row = (value_t*)calloc(mat->cols, sizeof(value_t));

	getMatrixRow(mat, rowId, row);

	size_t i;
	bool run = true;

	// Iterating until we find a non-null value
	for (i = 0; (i < mat->cols) && run; i++) {
		value_t val = row[i];
		run = val == 0.0;
	}

	i--; // The for-loop always returns `pivotIndex + 1`, so we take 1 away.

	free(row);

	return i;
}

void swapElements(size_t* arr, size_t a, size_t b) {
	size_t c;

	c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}

size_t chooseSortingPivot(size_t min, size_t max) {
	//return (min + max) / 2;
	return 0;
	//return randomIndex(min, max);
}

void sortingSwap(Matrix* mat, size_t* pivots, size_t idA, size_t idB, Swap** swaps, size_t* swapsMade) {
	if (idA == idB) {
		return;
	}

	swapRows(mat, idA, idB);
	swapElements(pivots, idA, idB);

	*swapsMade += 1;

	Swap* newPtr = (Swap*)realloc(*swaps, *swapsMade * sizeof(Swap));

	if (newPtr != NULL) {
		*swaps = newPtr;
	}
	else {
		fprintf(stderr, "Error or not enough space available in memory to continue\n");
		exit(EXIT_FAILURE);
	}

	Swap newSwap = { idA, idB };
	(*swaps)[*swapsMade - 1] = newSwap;
}

/* -- QuickSort implementation, needs to be fixed so implemented BubbleSort instead
size_t Partitioning(Matrix* mat, size_t firstId, size_t lastId, size_t pivotRowId, Swap** swaps, size_t* swapsMade) {
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
		//printf("%lu\t", rowsGaussPivots[i]);
	}
	//printf("\n\n");

	size_t firstRowVal, lastRowVal, pivotRowVal;

	firstRowVal = rowsGaussPivots[firstId];
	lastRowVal = rowsGaussPivots[lastId];
	pivotRowVal = rowsGaussPivots[pivotRowId];

	//printf("Call A : idA = %lu\tidB = %lu\n", pivotRowId, lastId);
	sortingSwap(mat, rowsGaussPivots, pivotRowId, lastId, swaps, swapsMade);

	size_t j = firstId;

	for (size_t i = firstId; i < lastId; i++) {
		if (rowsGaussPivots[i] <= rowsGaussPivots[lastId]) {
			//printf("Call B : idA = %lu\tidB = %lu\n", i, j);
			sortingSwap(mat, rowsGaussPivots, i, j, swaps, swapsMade);
			j++;
		}
	}

	//printf("Call C : idA = %lu\tidB = %lu\n", lastId, j);
	sortingSwap(mat, rowsGaussPivots, lastId, j, swaps, swapsMade);

	free(rowsGaussPivots);

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
		printf("firstId = %lu\tlastId = %lu\n", firstId, lastId);
		sortingPivot = chooseSortingPivot(firstId, lastId);
		sortingPivot = Partitioning(mat, firstId, lastId, sortingPivot, swaps, swapsMade);

		QuickSort(mat, firstId, sortingPivot - 1, swaps, swapsMade);
		QuickSort(mat, sortingPivot + 1, lastId, swaps, swapsMade);
	}
}
*/

void BubbleSort(Matrix* mat, Swap** swaps, size_t* swapsMade) {
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	size_t i, j;
	size_t n = mat->rows;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (rowsGaussPivots[j] > rowsGaussPivots[j + 1]) {
				sortingSwap(mat, rowsGaussPivots, j, j + 1, swaps, swapsMade);
			}
		}
	}

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	free(rowsGaussPivots);
}

void prepareGauss(Matrix* mat, Swap** swaps, size_t* swapsMade) {
	*swaps = (Swap*)malloc(1 * sizeof(Swap));
	*swapsMade = 0;

	//QuickSort(mat, 0, mat->rows - 1, swaps, swapsMade);
	BubbleSort(mat, swaps, swapsMade);
}

void Gauss(Matrix* mat) {
	Swap* swaps;
	size_t swapsMade;

	value_t* col = (value_t*)calloc(mat->rows, sizeof(value_t));

	prepareGauss(mat, &swaps, &swapsMade);
	size_t* rowsGaussPivots = (size_t*)calloc(mat->rows, sizeof(size_t));

	for (size_t i = 0; i < mat->rows; i++) {
		rowsGaussPivots[i] = identifyGaussPivot(mat, i);
	}

	for (size_t i = 0; i < mat->rows; i++) {
		getMatrixColumn(mat, i, col);

		if (col[i] != 0) {
			for (size_t j = i + 1; j < mat->rows; j++) {
				value_t coeff = col[j] / col[i];
				printf("i, j = %lu, %lu\n", i, j);
				subtractRows(mat, j, i, coeff);
			}
		}
	}

	free(rowsGaussPivots);
	free(col);
	free(swaps);
>>>>>>> Stashed changes
}