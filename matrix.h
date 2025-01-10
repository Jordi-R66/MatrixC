#pragma once

#include "common.h"

typedef struct Matrix {
	size_t rows, cols, size;

	double* data;
	bool memFreed;
} Matrix;

void allocMatrix(Matrix* matrix);
void deallocMatrix(Matrix* matrix);

void getMatrixRow(Matrix* matrix, size_t row, double* rowBuffer);
void getMatrixColumn(Matrix* matrix, size_t column, double* colBuffer);

void setMatrixRow(Matrix* matrix, size_t row, double* rowBuffer);
void setMatrixColumn(Matrix* matrix, size_t column, double* colBuffer);

void setMatrixCase(Matrix* matrix, double value, size_t row, size_t col);
double getMatrixCase(Matrix* matrix, size_t row, size_t col);

void setMatrix(Matrix* matrix, double* values);

void scalarMul(Matrix* matrix, double scalar);
void matrixMultiplication(Matrix* matA, Matrix* matB, Matrix* matDest);
void matrixAddition(Matrix* matA, Matrix* matB);

void genIdentityMatrix(Matrix* matrix, size_t n);


void printMatrix(Matrix* matrix);