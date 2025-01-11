#pragma once

#include "matrix.h"
#include "common.h"

void swapRows(Matrix* mat, size_t rowAId, size_t rowBId);
void subtractRows(Matrix* mat, size_t rowAId, size_t rowBId, double coeffRowB);
void multiplyRow(Matrix* mat, size_t rowId, double coeffRow);

size_t identifyGaussPivot(Matrix* mat, size_t rowId);

//size_t Partitioning(Matrix* mat, size_t firstId, size_t lastId, size_t pivotRowId, Swap** swaps, size_t* swapsMade);
//void QuickSort(Matrix* mat, size_t firstId, size_t lastId, Swap** swaps, size_t* swapsMade);

void prepareGauss(Matrix* mat, Swap** swaps, size_t* swapsMade);
void Gauss(Matrix* mat);