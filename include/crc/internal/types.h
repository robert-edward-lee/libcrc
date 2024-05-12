/**
    \file types.h
    \brief Типы значений полиномов
*/
#ifndef H_CRC_INTERNAL_TYPES
#define H_CRC_INTERNAL_TYPES

#include <stddef.h>

#include "crc/internal/defines.h"

#if defined(__GNUC__)
typedef unsigned int crc_u8 __attribute__((mode(QI)));
typedef unsigned int crc_u16 __attribute__((mode(HI)));
typedef unsigned int crc_u32 __attribute__((mode(SI)));
typedef unsigned int crc_u64 __attribute__((mode(DI)));
#elif defined(_MSC_VER)
typedef unsigned __int8 crc_u8;
typedef unsigned __int16 crc_u16;
typedef unsigned __int32 crc_u32;
typedef unsigned __int64 crc_u64;
#else
typedef unsigned char crc_u8;
typedef unsigned short crc_u16;
typedef unsigned int crc_u32;
#if defined(_WIN32) || defined(_WIN64)
typedef unsigned __int64 crc_u64;
#else
typedef unsigned long long crc_u64;
#endif
#endif

#if CRC_STDC_VERSION_CHECK(199901)
#include <stdbool.h>
typedef bool crc_bool;
#else
typedef crc_u8 crc_bool;
#endif

#define CRC_UINT64_C(w1, w2) ((crc_u64)CRC_CONCAT(w1, UL) << 32 | CRC_CONCAT(w2, UL))

#if CRC_HAS_GNUC_INT128
#define CRC_HAS_128BIT_ALGO 1
typedef __uint128_t crc_u128;
#define CRC_UINT128_C(w1, w2, w3, w4) \
    ((crc_u128)CRC_CONCAT(w1, UL) << 96 | (crc_u128)CRC_CONCAT(w2, UL) << 64 | (crc_u128)CRC_CONCAT(w3, UL) << 32 \
     | CRC_CONCAT(w4, UL))
#else
#define CRC_HAS_128BIT_ALGO 0
#endif

#endif /* H_CRC_INTERNAL_TYPES */
