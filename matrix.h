#pragma once

#include "common.h"

typedef struct Matrix {
	size_t rows, cols, size;

	value_t* data;
	bool memFreed;
} Matrix;

void allocMatrix(Matrix* matrix);
void deallocMatrix(Matrix* matrix);

void getMatrixRow(Matrix* matrix, size_t row, value_t* rowBuffer);
void getMatrixColumn(Matrix* matrix, size_t column, value_t* colBuffer);

void setMatrixRow(Matrix* matrix, size_t row, value_t* rowBuffer);
void setMatrixColumn(Matrix* matrix, size_t column, value_t* colBuffer);

void setMatrixCase(Matrix* matrix, value_t value, size_t row, size_t col);
value_t getMatrixCase(Matrix* matrix, size_t row, size_t col);

void setMatrix(Matrix* matrix, value_t* values);

void scalarMul(Matrix* matrix, value_t scalar);
void matrixMultiplication(Matrix* matA, Matrix* matB, Matrix* matDest);
void matrixAddition(Matrix* matA, Matrix* matB);

void genIdentityMatrix(Matrix* matrix, size_t n);


void printMatrix(Matrix* matrix);