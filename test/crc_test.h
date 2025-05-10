#ifndef H_CRC_TEST
#define H_CRC_TEST

#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

static const char check[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

#define print_hex(a) \
    do { \
        int i; \
        const crc_u8 *as_u8 = (const crc_u8 *)&a; \
        printf("0x"); \
        for(i = sizeof(a) - 1; i >= 0; --i) { \
            printf("%02X", as_u8[i]); \
        } \
    } while(0)

#define crc_test(__algo) \
    do { \
        CRC_CONCAT(crc_u, CRC_DO_EXPAND_RWIDTH __algo) value, check_value = CRC_EXPAND_CHECK(__algo); \
        CRC_CONCAT(Crc, CRC_DO_EXPAND_RWIDTH __algo) *crc = \
            CRC_TRICAT(crc, CRC_DO_EXPAND_RWIDTH __algo, _init_)(CRC_EXPAND_CTOR(__algo)); \
        value = CRC_TRICAT(crc, CRC_DO_EXPAND_RWIDTH __algo, _checksum)(crc, check, sizeof(check)); \
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
        CRC_TRICAT(crc, CRC_DO_EXPAND_RWIDTH __algo, _destroy)(crc); \
    } while(0)

#endif /* H_CRC_TEST */
