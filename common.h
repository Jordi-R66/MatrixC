#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define VALUE_TYPE
#define __64_BITS__

#if defined(__64_BITS__)
#define VALUE_TYPE double
#elif defined(__32_BITS__)
#define VALUE_TYPE float
#else
#error Unsupported target
#endif

typedef VALUE_TYPE value_t;

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
