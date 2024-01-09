#include <inttypes.h>
#include <stdio.h>

#include "crc/catalog.h"
#include "crc/lib.h"

const char check_str[] = "123456789";

#if __STDC_VERSION__ >= 201112L // Generics C11 support
#define test(__algo, __width)                                                                                  \
    {                                                                                                          \
        uint##__width##_t value;                                                                               \
        Crc##__width crc;                                                                                      \
        crc_init(&crc, &__algo);                                                                               \
        value = crc_checksum(&crc, check_str, sizeof(check_str) - 1);                                          \
        if(crc.algo.check != value) {                                                                          \
            printf("Invalid CRC check for " #__algo ": %#" PRIX##__width ", expected = %#" PRIX##__width "\n", \
                   value,                                                                                      \
                   crc.algo.check);                                                                            \
        } else {                                                                                               \
            printf(#__algo " passed\n");                                                                       \
        }                                                                                                      \
        crc_destroy(&crc);                                                                                     \
    }
#else // Generics C11 support
#define test(__algo, __width)                                                                                  \
    {                                                                                                          \
        uint##__width##_t value;                                                                               \
        Crc##__width crc;                                                                                      \
        crc##__width##_init(&crc, &__algo);                                                                    \
        value = crc##__width##_checksum(&crc, check_str, sizeof(check_str) - 1);                               \
        if(crc.algo.check != value) {                                                                          \
            printf("Invalid CRC check for " #__algo ": %#" PRIX##__width ", expected = %#" PRIX##__width "\n", \
                   value,                                                                                      \
                   crc.algo.check);                                                                            \
        } else {                                                                                               \
            printf(#__algo " passed\n");                                                                       \
        }                                                                                                      \
        crc##__width##_destroy(&crc);                                                                          \
    }
#endif // Generics C11 support

#ifdef __SIZEOF_INT128__
void test128(const Crc128BasedAlgo *__algo, const char *name) {
    __uint128_t value;
    Crc128 crc;
    crc128_init(&crc, __algo);
    value = crc128_checksum(&crc, check_str, sizeof(check_str) - 1);
    if(crc.algo.check != value) {
        uint8_t *as_u8;

        printf("Invalid CRC check for %s: 0x", name);
        as_u8 = (uint8_t *)&value;
        for(unsigned i = 0; i < sizeof(__uint128_t); i++) {
            printf("%02X", as_u8[i]);
        }

        printf(", expected = 0x");
        as_u8 = (uint8_t *)&crc.algo.check;
        for(unsigned i = 0; i < sizeof(__uint128_t); i++) {
            printf("%02X", as_u8[i]);
        }

        printf("\n");

    } else {
        printf("%s passed\n", name);
    }
    crc128_destroy(&crc);
}
#define test128_wrapper(__algo) test128(&__algo, #__algo)
#else
#define test128_wrapper(__algo)
#endif

int main(void) {
#if __STDC_VERSION__ >= 201112L // Generics C11 support
    printf("Enable generics C11 support\n");
#endif // Generics C11 support
    test(CRC3_GSM, 8);
    test(CRC3_ROHC, 8);
    test(CRC4_G_704, 8);
    test(CRC4_INTERLAKEN, 8);
    test(CRC5_EPC_C1G2, 8);
    test(CRC5_G_704, 8);
    test(CRC5_USB, 8);
    test(CRC6_CDMA2000_A, 8);
    test(CRC6_CDMA2000_B, 8);
    test(CRC6_DARC, 8);
    test(CRC6_GSM, 8);
    test(CRC6_G_704, 8);
    test(CRC7_MMC, 8);
    test(CRC7_ROHC, 8);
    test(CRC7_UMTS, 8);
    test(CRC8_AUTOSAR, 8);
    test(CRC8_BLUETOOTH, 8);
    test(CRC8_CDMA2000, 8);
    test(CRC8_DARC, 8);
    test(CRC8_DVB_S2, 8);
    test(CRC8_GSM_A, 8);
    test(CRC8_GSM_B, 8);
    test(CRC8_HITAG, 8);
    test(CRC8_I_432_1, 8);
    test(CRC8_I_CODE, 8);
    test(CRC8_LTE, 8);
    test(CRC8_MAXIM, 8);
    test(CRC8_MIFARE_MAD, 8);
    test(CRC8_NRSC_5, 8);
    test(CRC8_OPENSAFETY, 8);
    test(CRC8_ROHC, 8);
    test(CRC8_SAE_J1850, 8);
    test(CRC8_SMBUS, 8);
    test(CRC8_TECH_3250, 8);
    test(CRC8_WCDMA, 8);
    test(CRC10_ATM, 16);
    test(CRC10_CDMA2000, 16);
    test(CRC10_GSM, 16);
    test(CRC11_FLEXRAY, 16);
    test(CRC11_UMTS, 16);
    test(CRC12_CDMA2000, 16);
    test(CRC12_DECT, 16);
    test(CRC12_GSM, 16);
    test(CRC12_UMTS, 16);
    test(CRC13_BBC, 16);
    test(CRC14_DARC, 16);
    test(CRC14_GSM, 16);
    test(CRC15_CAN, 16);
    test(CRC15_MPT1327, 16);
    test(CRC16_ARC, 16);
    test(CRC16_CDMA2000, 16);
    test(CRC16_CMS, 16);
    test(CRC16_DDS_110, 16);
    test(CRC16_DECT_R, 16);
    test(CRC16_DECT_X, 16);
    test(CRC16_DNP, 16);
    test(CRC16_EN_13757, 16);
    test(CRC16_GENIBUS, 16);
    test(CRC16_GSM, 16);
    test(CRC16_IBM_3740, 16);
    test(CRC16_IBM_SDLC, 16);
    test(CRC16_ISO_IEC_14443_3_A, 16);
    test(CRC16_KERMIT, 16);
    test(CRC16_LJ1200, 16);
    test(CRC16_M17, 16);
    test(CRC16_MAXIM_DOW, 16);
    test(CRC16_MCRF4XX, 16);
    test(CRC16_MODBUS, 16);
    test(CRC16_NRSC_5, 16);
    test(CRC16_OPENSAFETY_A, 16);
    test(CRC16_OPENSAFETY_B, 16);
    test(CRC16_PROFIBUS, 16);
    test(CRC16_RIELLO, 16);
    test(CRC16_SPI_FUJITSU, 16);
    test(CRC16_T10_DIF, 16);
    test(CRC16_TELEDISK, 16);
    test(CRC16_TMS37157, 16);
    test(CRC16_UMTS, 16);
    test(CRC16_USB, 16);
    test(CRC16_XMODEM, 16);
    test(CRC17_CAN_FD, 32);
    test(CRC21_CAN_FD, 32);
    test(CRC24_BLE, 32);
    test(CRC24_FLEXRAY_A, 32);
    test(CRC24_FLEXRAY_B, 32);
    test(CRC24_INTERLAKEN, 32);
    test(CRC24_LTE_A, 32);
    test(CRC24_LTE_B, 32);
    test(CRC24_OPENPGP, 32);
    test(CRC24_OS_9, 32);
    test(CRC30_CDMA, 32);
    test(CRC31_PHILIPS, 32);
    test(CRC32_AIXM, 32);
    test(CRC32_AUTOSAR, 32);
    test(CRC32_BASE91_D, 32);
    test(CRC32_BZIP2, 32);
    test(CRC32_CD_ROM_EDC, 32);
    test(CRC32_CKSUM, 32);
    test(CRC32_ISCSI, 32);
    test(CRC32_ISO_HDLC, 32);
    test(CRC32_JAMCRC, 32);
    test(CRC32_MEF, 32);
    test(CRC32_MPEG2, 32);
    test(CRC32_XFER, 32);
    test(CRC40_GSM, 64);
    test(CRC64_ECMA_182, 64);
    test(CRC64_GO_ISO, 64);
    test(CRC64_MS, 64);
    test(CRC64_REDIS, 64);
    test(CRC64_WE, 64);
    test(CRC64_XZ, 64);
    test128_wrapper(CRC82_DARC);
    return 0;
}
