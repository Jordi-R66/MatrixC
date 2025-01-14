#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum TransformationType {
	SWAP = 0,
	SUB = 1,
	MUL = 2
} TransformationType;

typedef enum SwapType {
	Row = 0,
	Column = 1
} SwapType;

typedef struct Swap {
	size_t A, B;
	SwapType type;
} Swap;

typedef struct MatrixTransformation {
	TransformationType transType;

	size_t A, B;
	value_t coeff;

	SwapType swapType;
} MatrixTransformation;

#if defined(__x86_64__) || defined(_M_X64)
#define VALUE_TYPE double
#elif defined(__i386__) || defined(_M_IX86)
#define VALUE_TYPE float
#else
#error Unsupported target
#endif

typedef VALUE_TYPE value_t;
