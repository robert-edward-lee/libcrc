#include <inttypes.h>
#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

#define crc_print_table(__algo, __width) \
    do { \
        int i; \
        CRC_CONCAT(Crc, __width) * crc; \
        crc = CRC_CONCAT(CRC_CONCAT(crc, __width), _init_)(CRC_DO_EXPAND_INIT(__algo)); \
        printf("static const uint" CRC_STR(__width) "_t CRC_TABLE[256] = {\n"); \
        for(i = 0; i < 256; i++) { \
            printf("%s0x%0*" CRC_CONCAT(PRIX, __width) ",%s", \
                   i % 8 ? "" : "    ", \
                   __width / 4, \
                   crc->table[i], \
                   (i + 1) % 8 ? " " : "\n"); \
        } \
        printf("};\n"); \
    } while(0)

#if CRC_HAS_128BIT_ALGO
#define crc128_print_table(__algo) \
    do { \
        Crc128 *crc; \
        crc = crc128_init_(CRC_DO_EXPAND_INIT(__algo)); \
        printf("static const crc_u128 CRC_TABLE[256] = {\n"); \
        for(int i = 0; i < 256; i++) { \
            printf("    (__uint128_t)0x%016" PRIX64 " << 64 | 0x%016" PRIX64 ",\n", \
                   (crc_u64)(crc->table[i] >> 64), \
                   (crc_u64)crc->table[i]); \
        } \
        printf("};\n"); \
    } while(0)
#endif /* CRC_HAS_128BIT_ALGO */

int main(void) {
#if CRC_WIDTH < 128
    crc_print_table(CRC_NAME, CRC_WIDTH);
#elif CRC_HAS_128BIT_ALGO
    crc128_print_table(CRC_NAME);
#else
#error "The 128-bit wide Crc algorithm is not supported"
#endif
    return 0;
}
