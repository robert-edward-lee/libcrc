#ifndef H_CRC_INTERNAL_TYPES
#define H_CRC_INTERNAL_TYPES

#include <stdint.h>

#include "crc/internal/defines.h"

#if CRC_HAS_128BIT_ALGO
typedef __uint128_t uint128_t;
#endif

#endif /* H_CRC_INTERNAL_TYPES */
