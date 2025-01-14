#include "advMatrix.h"

void mirrorMatrix(Matrix* mat, SwapType toSwap, Swap** swaps, size_t* swapsMade) {
	size_t j = 0;

	switch (toSwap) {
		case Row:
			for (size_t i=0; i < mat->rows / 2; i++) {
				j = mat->rows - 1 - i;

				if (i != j) {
					swapRows(mat, i, j);
					recordSwap(i, j, toSwap, swaps, swapsMade);
				}
			}

			break;

		case Column:
			for (size_t i=0; i < mat->cols / 2; i++) {
				j = mat->cols - 1 - i;

				if (i != j) {
					swapCols(mat, i, j);
					recordSwap(i, j, toSwap, swaps, swapsMade);
				}
			}

			break;

		default:
			fprintf("Can't mirror your matrix with the given option :\n\ttoSwap = %d", toSwap);
			exit(EXIT_FAILURE);
	}
}