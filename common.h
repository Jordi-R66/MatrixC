#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Swap {
	size_t A, B;
} Swap;

#if defined(__x86_64__) || defined(_M_X64)
#define VALUE_TYPE double
#elif defined(__i386__) || defined(_M_IX86)
#define VALUE_TYPE float
#endif

typedef VALUE_TYPE value_t;
