#ifndef H_CRC_INTERNAL_TYPES
#define H_CRC_INTERNAL_TYPES

#include <stdint.h>

#include "crc/internal/defines.h"

typedef unsigned char crc_u8;
typedef unsigned short crc_u16;
typedef unsigned int crc_u32;

#if defined(_WIN32) || defined(_WIN64)
typedef unsigned __int64 crc_u64;
#else
typedef unsigned long long crc_u64;
#endif

#define CRC_UINT64_C(w1, w2) ((crc_u64)CRC_CONCAT(w1, UL) << 32 | CRC_CONCAT(w2, UL))

#if CRC_HAS_128BIT_ALGO
typedef __uint128_t crc_u128;
#define CRC_UINT128_C(w1, w2, w3, w4) \
    ((crc_u128)CRC_CONCAT(w1, UL) << 96 | (crc_u128)CRC_CONCAT(w2, UL) << 64 | (crc_u128)CRC_CONCAT(w3, UL) << 32 \
     | CRC_CONCAT(w4, UL))
#endif

#endif /* H_CRC_INTERNAL_TYPES */
