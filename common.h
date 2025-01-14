#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum SwapType {
	Line = 0,
	Column = 1
} SwapType;

typedef struct Swap {
	size_t A, B;
	SwapType type;
} Swap;

#if defined(__x86_64__) || defined(_M_X64)
#define VALUE_TYPE double
#elif defined(__i386__) || defined(_M_IX86)
#define VALUE_TYPE float
#endif

typedef VALUE_TYPE value_t;
