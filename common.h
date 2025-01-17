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
