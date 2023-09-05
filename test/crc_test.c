#include <stdio.h>

#include "crc.h"
#include "crc_catalog.h"

const char check_str[] = "123456789";

#define test(__algo, __width) \
    void test_##__algo(void) { \
        uint##__width##_t value; \
        Crc##__width crc; \
        crc##__width##_init(&crc, &__algo); \
        value = crc##__width##_checksum(&crc, check_str, sizeof(check_str) - 1); \
        if(crc.algo.check != value) { \
            printf("Invalid CRC check for " #__algo ": %#X, expected = %#X\n", value, crc.algo.check); \
        } else {\
            printf(#__algo " passed\n"); \
        } \
        crc##__width##_destroy(&crc); \
    } test_##__algo()

int main(void) {
    test(CRC8_MAXIM, 8);
    test(CRC16_ARC, 16);
    test(CRC16_MODBUS, 16);
    test(CRC16_USB, 16);
    test(CRC16_KERMIT, 16);
    test(CRC16_XMODEM, 16);
    test(CRC32_BZIP2, 32);
    test(CRC32_ISO_HDLC, 32);
    test(CRC32_MPEG2, 32);

    return 0;
}
