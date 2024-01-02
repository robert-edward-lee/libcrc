#include <inttypes.h>
#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

#define _CONCAT(a, b) a##b
#define CONCAT(a, b) _CONCAT(a, b)

#define _STR(s) #s
#define STR(s) _STR(s)

#define crc_print_table(__algo, __width) ({ \
    CONCAT(Crc, __width) crc; \
    CONCAT(CONCAT(crc, __width), _init)(&crc, &__algo); \
    printf("static const uint" STR(__width) "_t CRC_TABLE[256] = {\n"); \
    for(int i = 0; i < 256; i++) \
        printf("%s0x%0*" CONCAT(PRIX, __width) ",%s", \
            i % 8 ? "" : "    ", \
            __width / 4, \
            crc.table[i], \
            (i + 1) % 8 ? " " : "\n"); \
    printf("};\n"); \
})

int main(void) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
    crc_print_table(CRC_NAME, CRC_WIDTH);
#pragma GCC diagnostic pop
    return 0;
}
