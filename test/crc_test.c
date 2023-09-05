#include <stdio.h>

#include "crc.h"
#include "crc_catalog.h"

const char check_str[] = "123456789";

#define test(test_algo, real_width) ({ \
    void test_##test_algo(void) { \
        uint##real_width##_t value; \
        Crc##real_width crc; \
        crc##real_width##_init(&crc, &test_algo); \
        value = crc##real_width##_checksum(&crc, check_str, sizeof(check_str) - 1); \
        if(crc.algo.check != value) { \
            printf("Invalid CRC check for " #test_algo ": %#X, expected = %#X\n", value, crc.algo.check); \
        } \
    } test_##test_algo();})


int main(void) {
    test(CRC8_MAXIM_ALGO, 8);
    test(CRC16_ARC_ALGO, 16);
    test(CRC16_MODBUS_ALGO, 16);
    test(CRC16_USB_ALGO, 16);
    test(CRC16_KERMIT_ALGO, 16);
    test(CRC16_XMODEM_ALGO, 16);
    test(CRC32_BZIP2_ALGO, 32);
    test(CRC32_MPEG2_ALGO, 32);

    return 0;
}
