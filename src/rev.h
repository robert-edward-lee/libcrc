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
    x = ((x & 0x0F) << 4) | ((x & 0xF0) >> 4);
    return x;
}
/**
    \param x Слово шириной 16 бит
    \return Отзеркаленное слово
*/
static inline uint16_t rev16(uint16_t x) {
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    x = ((x & 0x00FF) << 8) | ((x & 0xFF00) >> 8);
    return x;
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
    x = ((x & 0x0000FFFF) << 16) | ((x & 0xFFFF0000) >> 16);
    return x;
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
    x = ((x & 0x00000000FFFFFFFF) << 32) | ((x & 0xFFFFFFFF00000000) >> 32);
    return x;
}

#endif // H_REV
