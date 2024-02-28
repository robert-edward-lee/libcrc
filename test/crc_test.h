#ifndef H_CRC_TEST
#define H_CRC_TEST

#include <inttypes.h>
#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

const char check[9] = "123456789";

#ifdef __SIZEOF_INT128__
typedef __uint128_t uint128_t;
#endif

#define print_hex(a)                                                                                                   \
    {                                                                                                                  \
        const uint8_t *as_u8 = (const uint8_t *)&a;                                                                    \
        printf("0x");                                                                                                  \
        for(int i = sizeof(a) - 1; i >= 0; i--) {                                                                      \
            printf("%02X", as_u8[i]);                                                                                  \
        }                                                                                                              \
    }

#define crc_test(__algo, __width)                                                                                      \
    {                                                                                                                  \
        Crc##__width crc;                                                                                              \
        crc##__width##_init(&crc, &__algo);                                                                            \
        uint##__width##_t value = crc##__width##_checksum(&crc, check, sizeof(check));                                 \
        if(crc.algo.check != value) {                                                                                  \
            printf("Invalid CRC check for " #__algo ": ");                                                             \
            print_hex(value);                                                                                          \
            printf(", expected = ");                                                                                   \
            print_hex(crc.algo.check);                                                                                 \
            printf("\n");                                                                                              \
            errors++;                                                                                                  \
        } else {                                                                                                       \
            printf(#__algo " passed\n");                                                                               \
            passed++;                                                                                                  \
        }                                                                                                              \
        crc##__width##_destroy(&crc);                                                                                  \
    }

#endif // H_CRC_TEST
