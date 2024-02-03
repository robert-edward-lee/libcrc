#include <inttypes.h>
#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"
#include "../src/lib.c"

#define _CONCAT(a, b) a##b
#define CONCAT(a, b) _CONCAT(a, b)

#define _STR(s) #s
#define STR(s) _STR(s)

#define crc_print_table(__algo, __width)                                    \
    {                                                                       \
        CONCAT(Crc, __width) crc;                                           \
        CONCAT(CONCAT(crc, __width), _init)(&crc, &__algo);                 \
        printf("static const uint" STR(__width) "_t CRC_TABLE[256] = {\n"); \
        for(int i = 0; i < 256; i++) {                                      \
            printf("%s0x%0*" CONCAT(PRIX, __width) ",%s",                   \
                   i % 8 ? "" : "    ",                                     \
                   __width / 4,                                             \
                   crc.table[i],                                            \
                   (i + 1) % 8 ? " " : "\n");                               \
        }                                                                   \
        printf("};\n");                                                     \
    }

#ifdef __SIZEOF_INT128__
#define crc128_print_table(__algo)                                                  \
    {                                                                               \
        Crc128 crc;                                                                 \
        crc128_init(&crc, &__algo);                                                 \
        printf("static const __uint128_t CRC_TABLE[256] = {\n");                    \
        for(int i = 0; i < 256; i++) {                                              \
            printf("    (__uint128_t)0x%016" PRIX64 " << 64 | 0x%016" PRIX64 ",\n", \
                   (uint64_t)(crc.table[i] >> 64),                                  \
                   (uint64_t)crc.table[i]);                                         \
        }                                                                           \
        printf("};\n");                                                             \
    }
#endif // __SIZEOF_INT128__

int main(void) {
#if CRC_WIDTH < 128
    crc_print_table(CRC_NAME, CRC_WIDTH);
#elif __SIZEOF_INT128__
    crc128_print_table(CRC_NAME);
#else
#error "Crc algorithm with width 128 bits is not supported"
#endif
    return 0;
}
