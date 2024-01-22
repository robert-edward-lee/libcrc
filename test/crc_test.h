#ifndef H_CRC_TEST
#define H_CRC_TEST

#include <inttypes.h>
#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

#if __STDC_VERSION__ >= 201112L // Generics C11 support
#define test(__algo, __width)                                                                                        \
    {                                                                                                                \
        uint##__width##_t value;                                                                                     \
        Crc##__width crc;                                                                                            \
        crc_init(&crc, &__algo);                                                                                     \
        value = crc_checksum(&crc, check, sizeof(check));                                                            \
        if(crc.algo.check != value) {                                                                                \
            printf("Invalid CRC check for " #__algo ": 0x%0*" PRIX##__width ", expected = 0x%0*" PRIX##__width "\n", \
                   __width / 4,                                                                                      \
                   value,                                                                                            \
                   __width / 4,                                                                                      \
                   crc.algo.check);                                                                                  \
            errors++;                                                                                                \
        } else {                                                                                                     \
            printf(#__algo " passed\n");                                                                             \
            passed++;                                                                                                \
        }                                                                                                            \
        crc_destroy(&crc);                                                                                           \
    }
#else // Generics C11 support
#define test(__algo, __width)                                                                                        \
    {                                                                                                                \
        uint##__width##_t value;                                                                                     \
        Crc##__width crc;                                                                                            \
        crc##__width##_init(&crc, &__algo);                                                                          \
        value = crc##__width##_checksum(&crc, check, sizeof(check));                                                 \
        if(crc.algo.check != value) {                                                                                \
            printf("Invalid CRC check for " #__algo ": 0x%0*" PRIX##__width ", expected = 0x%0*" PRIX##__width "\n", \
                   __width / 4,                                                                                      \
                   value,                                                                                            \
                   __width / 4,                                                                                      \
                   crc.algo.check);                                                                                  \
            errors++;                                                                                                \
        } else {                                                                                                     \
            printf(#__algo " passed\n");                                                                             \
            passed++;                                                                                                \
        }                                                                                                            \
        crc##__width##_destroy(&crc);                                                                                \
    }
#endif // Generics C11 support

#ifdef __SIZEOF_INT128__
#define print128(a)                               \
    {                                             \
        uint8_t *as_u8 = (uint8_t *)&a;           \
        printf("0x");                             \
        for(int i = sizeof(a) - 1; i >= 0; i--) { \
            printf("%02X", as_u8[i]);             \
        }                                         \
    }
#define test128(__algo)                                      \
    {                                                        \
        __uint128_t value;                                   \
        Crc128 crc;                                          \
        crc128_init(&crc, &__algo);                          \
        value = crc128_checksum(&crc, check, sizeof(check)); \
        if(crc.algo.check != value) {                        \
            printf("Invalid CRC check for " #__algo ": ");   \
            print128(value);                                 \
            printf(", expected = ");                         \
            print128(crc.algo.check);                        \
            printf("\n");                                    \
            errors++;                                        \
        } else {                                             \
            printf(#__algo " passed\n");                     \
            passed++;                                        \
        }                                                    \
        crc128_destroy(&crc);                                \
    }
#else // __SIZEOF_INT128__
#define test128(__algo)
#endif // __SIZEOF_INT128__

#endif // H_CRC_TEST
