#pragma once

#include "common.h"

enum TransformationType {
	SWAP = 0,
	SUB = 1,
	MUL = 2
};

typedef enum TransformationType TransformationType;

enum SwapType {
	Row = 0,
	Column = 1
};

typedef enum SwapType SwapType;

struct Swap {
	size_t A, B;
	SwapType type;
};

typedef struct Swap Swap;

struct MatrixTransformation {
	TransformationType transType;

	size_t A, B;
	value_t coeff;

	SwapType swapType;
};

typedef struct MatrixTransformation MatrixTransformation;
