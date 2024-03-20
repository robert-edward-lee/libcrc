/**
    \file rev.h
    \brief Утилита для отзеркаливания битов в слове
*/
#ifndef H_REV
#define H_REV

#include <stdint.h>

#ifdef __has_builtin
#if defined(__clang__) && __has_builtin(__builtin_convertvector)
#define __has_builtin_bitreverse
#endif
#endif

/**
    \param x Слово шириной 8 бит
    \return Отзеркаленное слово
*/
static uint8_t rev8(uint8_t x) {
#ifdef __has_builtin_bitreverse
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
static uint16_t rev16(uint16_t x) {
#ifdef __has_builtin_bitreverse
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
static uint32_t rev32(uint32_t x) {
#ifdef __has_builtin_bitreverse
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
static uint64_t rev64(uint64_t x) {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse64(x);
#else
    x = ((x & 0x5555555555555555) << 1) | ((x & 0xAAAAAAAAAAAAAAAA) >> 1);
    x = ((x & 0x3333333333333333) << 2) | ((x & 0xCCCCCCCCCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F0F0F0F0F) << 4) | ((x & 0xF0F0F0F0F0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF00FF00FF) << 8) | ((x & 0xFF00FF00FF00FF00) >> 8);
    x = ((x & 0x0000FFFF0000FFFF) << 16) | ((x & 0xFFFF0000FFFF0000) >> 16);
    return x << 32 | x >> 32;
#endif
}

#ifdef __SIZEOF_INT128__
/**
    \param x Слово шириной 128 бит
    \return Отзеркаленное слово
*/
static __uint128_t rev128(__uint128_t x) {
    return (__uint128_t)rev64(x) << 64 | rev64(x >> 64);
}
#endif /* __SIZEOF_INT128__ */

#endif /* H_REV */
