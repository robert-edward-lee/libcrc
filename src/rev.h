/**
    \file rev.h
    \brief Утилита для отзеркаливания битов в слове
*/
#ifndef H_REV
#define H_REV

#include <stdint.h>

/**
    \param x Слово шириной 8 бит
    \return Отзеркаленное слово
*/
static inline uint8_t rev8(uint8_t x) {
    x = ((x & 0x55) << 1) | ((x & 0xAA) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xCC) >> 2);
    return x << 4 | x >> 4;
}
/**
    \param x Слово шириной 16 бит
    \return Отзеркаленное слово
*/
static inline uint16_t rev16(uint16_t x) {
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    return x << 8 | x >> 8;
}
/**
    \param x Слово шириной 32 бит
    \return Отзеркаленное слово
*/
static inline uint32_t rev32(uint32_t x) {
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    return x << 16 | x >> 16;
}
/**
    \param x Слово шириной 64 бит
    \return Отзеркаленное слово
*/
static inline uint64_t rev64(uint64_t x) {
    x = ((x & 0x5555555555555555) << 1) | ((x & 0xAAAAAAAAAAAAAAAA) >> 1);
    x = ((x & 0x3333333333333333) << 2) | ((x & 0xCCCCCCCCCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F0F0F0F0F) << 4) | ((x & 0xF0F0F0F0F0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF00FF00FF) << 8) | ((x & 0xFF00FF00FF00FF00) >> 8);
    x = ((x & 0x0000FFFF0000FFFF) << 16) | ((x & 0xFFFF0000FFFF0000) >> 16);
    return x << 32 | x >> 32;
}

#ifdef __SIZEOF_INT128__
/**
    \param x Слово шириной 128 бит
    \return Отзеркаленное слово
*/
static inline __uint128_t rev128(__uint128_t x) {
    return (__uint128_t)rev64(x) << 64 | rev64(x >> 64);
}

#ifdef __has_builtin
#if __has_builtin(__builtin_bswap128)
#define __has_builtin_bswap128
#endif
#endif

#ifdef __has_builtin_bswap128
/**
    \param x Слово шириной 128 бит
    \return Слово с обратным порядком байт
*/
static inline __uint128_t bswap128(__uint128_t x) {
    return __builtin_bswap128(x);
}
#else
/**
    \param x Слово шириной 64 бит
    \return Слово с обратным порядком байт
*/
static inline uint64_t bswap64(uint64_t x) {
    x = ((x & 0x00FF00FF00FF00FF) << 8) | ((x & 0xFF00FF00FF00FF00) >> 8);
    x = ((x & 0x0000FFFF0000FFFF) << 16) | ((x & 0xFFFF0000FFFF0000) >> 16);
    return x << 32 | x >> 32;
}
/**
    \param x Слово шириной 128 бит
    \return Слово с обратным порядком байт
*/
static inline __uint128_t bswap128(__uint128_t x) {
    return (__uint128_t)bswap64(x) << 64 | bswap64(x >> 64);
}
#endif // __has_builtin_bswap128
#endif // __SIZEOF_INT128__

#endif // H_REV
