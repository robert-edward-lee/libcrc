/**
    \file rev.h
    \brief Утилита для отзеркаливания битов в слове
*/
#ifndef H_CRC_REV
#define H_CRC_REV

#include "crc/internal/defines.h"
#include "crc/internal/types.h"

/**
    \param x Слово шириной 8 бит
    \return Отзеркаленное слово
*/
static CRC_ALWAYS_INLINE crc_u8 rev8(crc_u8 x) {
#if CRC_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse8(x);
#else
    x = ((x & 0x55) << 1) | ((x & 0xAA) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xCC) >> 2);
    return x << 4 | x >> 4;
#endif
}
/**
    \param x Слово шириной 16 бит
    \return Отзеркаленное слово
*/
static CRC_ALWAYS_INLINE crc_u16 rev16(crc_u16 x) {
#if CRC_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse16(x);
#else
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    return x << 8 | x >> 8;
#endif
}
/**
    \param x Слово шириной 32 бит
    \return Отзеркаленное слово
*/
static CRC_ALWAYS_INLINE crc_u32 rev32(crc_u32 x) {
#if CRC_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse32(x);
#else
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    return x << 16 | x >> 16;
#endif
}
/**
    \param x Слово шириной 64 бит
    \return Отзеркаленное слово
*/
static CRC_ALWAYS_INLINE crc_u64 rev64(crc_u64 x) {
#if CRC_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse64(x);
#else
    x = ((x & CRC_UINT64_C(0x55555555, 0x55555555)) << 1) | ((x & CRC_UINT64_C(0xAAAAAAAA, 0xAAAAAAAA)) >> 1);
    x = ((x & CRC_UINT64_C(0x33333333, 0x33333333)) << 2) | ((x & CRC_UINT64_C(0xCCCCCCCC, 0xCCCCCCCC)) >> 2);
    x = ((x & CRC_UINT64_C(0x0F0F0F0F, 0x0F0F0F0F)) << 4) | ((x & CRC_UINT64_C(0xF0F0F0F0, 0xF0F0F0F0)) >> 4);
    x = ((x & CRC_UINT64_C(0x00FF00FF, 0x00FF00FF)) << 8) | ((x & CRC_UINT64_C(0xFF00FF00, 0xFF00FF00)) >> 8);
    x = ((x & CRC_UINT64_C(0x0000FFFF, 0x0000FFFF)) << 16) | ((x & CRC_UINT64_C(0xFFFF0000, 0xFFFF0000)) >> 16);
    return x << 32 | x >> 32;
#endif
}

#if CRC_HAS_128BIT_ALGO
/**
    \param x Слово шириной 128 бит
    \return Отзеркаленное слово
*/
static CRC_ALWAYS_INLINE crc_u128 rev128(crc_u128 x) {
    return (crc_u128)rev64(x) << 64 | rev64(x >> 64);
}
#endif /* CRC_HAS_128BIT_ALGO */

#endif /* H_CRC_REV */
