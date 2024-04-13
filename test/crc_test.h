#ifndef H_CRC_TEST
#define H_CRC_TEST

#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

const char check[9] = "123456789";

#define print_hex(a) \
    do { \
        int i; \
        const uint8_t *as_u8 = (const uint8_t *)&a; \
        printf("0x"); \
        for(i = sizeof(a) - 1; i >= 0; i--) { \
            printf("%02X", as_u8[i]); \
        } \
    } while(0)

#define crc_test(__algo, __width) \
    do { \
        uint##__width##_t value; \
        Crc##__width crc; \
        crc##__width##_init(&crc, CRC_EXPAND_INITIALIZER_LIST(__algo)); \
        value = crc##__width##_checksum(&crc, check, sizeof(check)); \
        if(crc.algo.check != value) { \
            printf("Invalid CRC check for " #__algo ": "); \
            print_hex(value); \
            printf(", expected = "); \
            print_hex(crc.algo.check); \
            printf("\n"); \
            errors++; \
        } else { \
            printf(#__algo " passed\n"); \
            passed++; \
        } \
        crc##__width##_destroy(&crc); \
    } while(0)

#endif /* H_CRC_TEST */
