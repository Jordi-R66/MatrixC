#pragma once

#include "common.h"
#include "matrix.h"
#include "gauss.h"

void mirrorMatrix(Matrix* mat, SwapType toSwap, Swap** swaps, size_t* swapsMade);

bool inversibilityCheck(Matrix* mat);
void inverseMatrix(Matrix* mat, Matrix* invMat);