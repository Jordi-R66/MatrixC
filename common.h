#pragma once

#define VALUE_TYPE
#define __64_BITS__

#if defined(__64_BITS__)
#undef VALUE_TYPE
#define VALUE_TYPE double
#elif defined(__32_BITS__)
#undef VALUE_TYPE
#define VALUE_TYPE float
#else
#error Unsupported target
#endif

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef VALUE_TYPE value_t;
