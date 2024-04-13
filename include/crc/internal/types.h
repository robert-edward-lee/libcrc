#ifndef H_CRC_INTERNAL_TYPES
#define H_CRC_INTERNAL_TYPES

#include <stdint.h>

#include "crc/internal/defines.h"

#define CRC_UINT64_C(w1, w2) ((uint64_t)w1##UL << 32 | w2##UL)

#if CRC_HAS_128BIT_ALGO
typedef __uint128_t uint128_t;
#define CRC_UINT128_C(w1, w2, w3, w4) \
    ((uint128_t)w1##UL << 96 | (uint128_t)w2##UL << 64 | (uint128_t)w3##UL << 32 | w4##UL)
#endif

#endif /* H_CRC_INTERNAL_TYPES */
