#pragma once

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Matrix {
	size_t rows, cols, size;

	double* data;
	bool memFreed;
} Matrix;

void allocMatrix(Matrix* matrix);
void deallocMatrix(Matrix* matrix);

void getMatrixRow(Matrix* matrix, size_t row, double* rowBuffer);
void getMatrixColumn(Matrix* matrix, size_t column, double* colBuffer);
