#ifndef H_CRC_TEST
#define H_CRC_TEST

#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

const char check[9] = "123456789";

#define print_hex(a) \
    do { \
        int i; \
        const crc_u8 *as_u8 = (const crc_u8 *)&a; \
        printf("0x"); \
        for(i = sizeof(a) - 1; i >= 0; i--) { \
            printf("%02X", as_u8[i]); \
        } \
    } while(0)

#define crc_test(__algo, __width) \
    do { \
        crc_u##__width value, check_value = CRC_EXPAND_CHECK(__algo); \
        Crc##__width crc; \
        crc##__width##_init(&crc, CRC_EXPAND_INITIALIZER_LIST(__algo)); \
        value = crc##__width##_checksum(&crc, check, sizeof(check)); \
        if(check_value != value) { \
            printf("Invalid CRC check for " #__algo ": "); \
            print_hex(value); \
            printf(", expected = "); \
            print_hex(check_value); \
            printf("\n"); \
            errors++; \
        } else { \
            printf(#__algo " passed\n"); \
            passed++; \
        } \
        crc##__width##_destroy(&crc); \
    } while(0)

#endif /* H_CRC_TEST */
