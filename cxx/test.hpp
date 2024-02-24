#ifndef HPP_CRC_TEST
#define HPP_CRC_TEST

#include <cinttypes>
#include <iostream>

const char check[] = "123456789";

#define crc_test(__algo, __width)                                                                                      \
    {                                                                                                                  \
        Crc<__algo> crc;                                                                                               \
        uint##__width##_t value = crc.checksum(check, sizeof(check) - 1);                                              \
        if(__algo::check != value) {                                                                                   \
            printf("Invalid CRC check for " #__algo ": 0x%0*" PRIX##__width ", expected = 0x%0*" PRIX##__width "\n",   \
                   __width / 4,                                                                                        \
                   value,                                                                                              \
                   __width / 4,                                                                                        \
                   __algo::check);                                                                                     \
            errors++;                                                                                                  \
        } else {                                                                                                       \
            printf(#__algo " passed\n");                                                                               \
            passed++;                                                                                                  \
        }                                                                                                              \
    }

#ifdef __SIZEOF_INT128__
#define print128(a)                                                                                                    \
    {                                                                                                                  \
        __uint128_t value = a;                                                                                         \
        uint8_t *as_u8 = (uint8_t *)&value;                                                                            \
        printf("0x");                                                                                                  \
        for(int i = sizeof(a) - 1; i >= 0; i--) {                                                                      \
            printf("%02X", as_u8[i]);                                                                                  \
        }                                                                                                              \
    }
#define crc_test128(__algo)                                                                                            \
    {                                                                                                                  \
        Crc<__algo> crc;                                                                                               \
        __uint128_t value = crc.checksum(check, sizeof(check) - 1);                                                    \
        if(__algo::check != value) {                                                                                   \
            printf("Invalid CRC check for " #__algo ": ");                                                             \
            print128(value);                                                                                           \
            printf(", expected = ");                                                                                   \
            print128(__algo::check);                                                                                   \
            printf("\n");                                                                                              \
            errors++;                                                                                                  \
        } else {                                                                                                       \
            printf(#__algo " passed\n");                                                                               \
            passed++;                                                                                                  \
        }                                                                                                              \
    }
#else // __SIZEOF_INT128__
#define print128(a)
#define crc_test128(__algo)
#endif // __SIZEOF_INT128__

#endif // HPP_CRC_TEST
