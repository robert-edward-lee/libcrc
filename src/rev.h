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
static CRC_ALWAYS_INLINE uint8_t rev8(uint8_t x) {
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
static CRC_ALWAYS_INLINE uint16_t rev16(uint16_t x) {
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
static CRC_ALWAYS_INLINE uint32_t rev32(uint32_t x) {
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
static CRC_ALWAYS_INLINE uint64_t rev64(uint64_t x) {
#if CRC_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse64(x);
#else
    x = ((x & ((uint64_t)0x55555555 << 32 | 0x55555555)) << 1) | ((x & ((uint64_t)0xAAAAAAAA << 32 | 0xAAAAAAAA)) >> 1);
    x = ((x & ((uint64_t)0x33333333 << 32 | 0x33333333)) << 2) | ((x & ((uint64_t)0xCCCCCCCC << 32 | 0xCCCCCCCC)) >> 2);
    x = ((x & ((uint64_t)0x0F0F0F0F << 32 | 0x0F0F0F0F)) << 4) | ((x & ((uint64_t)0xF0F0F0F0 << 32 | 0xF0F0F0F0)) >> 4);
    x = ((x & ((uint64_t)0x00FF00FF << 32 | 0x00FF00FF)) << 8) | ((x & ((uint64_t)0xFF00FF00 << 32 | 0xFF00FF00)) >> 8);
    x = ((x & ((uint64_t)0x0000FFFF << 32 | 0x0000FFFF)) << 16)
      | ((x & ((uint64_t)0xFFFF0000 << 32 | 0xFFFF0000)) >> 16);
    return x << 32 | x >> 32;
#endif
}

#if CRC_HAS_128BIT_ALGO
/**
    \param x Слово шириной 128 бит
    \return Отзеркаленное слово
*/
static CRC_ALWAYS_INLINE uint128_t rev128(uint128_t x) {
    return (uint128_t)rev64(x) << 64 | rev64(x >> 64);
}
#endif /* CRC_HAS_128BIT_ALGO */

#endif /* H_CRC_REV */
