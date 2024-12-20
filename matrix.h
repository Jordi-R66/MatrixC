#pragma once

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Matrix {
	size_t rows, cols, elements;

	double* data;
	bool memFreed;
} Matrix;

void allocMatrix(Matrix* matrix);
void deallocMatrix(Matrix* matrix);
