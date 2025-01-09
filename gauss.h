#pragma once

#include "matrix.h"

void swapRows(Matrix* mat, size_t rowAId, size_t rowBId);
void subtractRows(Matrix* mat, size_t rowAId, size_t rowBId, double coeffRowB);
void multiplyRow(Matrix* mat, size_t rowId, double coeffRow);