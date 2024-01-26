/**
    \file catalog.h
    \brief <a href="https://reveng.sourceforge.io/crc-catalogue/all.htm">Перечень</a> всех стандартных и общепринятых
    CRC алгоритмов шириной вплоть до 128 бит
*/
#ifndef H_CRC_CATALOG
#define H_CRC_CATALOG

#include <stdbool.h>
// clang-format off
//                                               Width              Poly                Init  RefIn  RefOut              XorOut              Check
#define CRC3_GSM                (( Crc8BasedAlgo){ 3,                0x3,                0x0, false, false,                0x7,                0x4})
#define CRC3_ROHC               (( Crc8BasedAlgo){ 3,                0x3,                0x7,  true,  true,                0x0,                0x6})
#define CRC4_G_704              (( Crc8BasedAlgo){ 4,                0x3,                0x0,  true,  true,                0x0,                0x7})
#define CRC4_ITU                CRC4_G_704
#define CRC4_INTERLAKEN         (( Crc8BasedAlgo){ 4,                0x3,                0xF, false, false,                0xF,                0xB})
#define CRC5_EPC_C1G2           (( Crc8BasedAlgo){ 5,               0x09,               0x09, false, false,               0x00,               0x00})
#define CRC5_EPC                CRC5_EPC_C1G2
#define CRC5_G_704              (( Crc8BasedAlgo){ 5,               0x15,               0x00,  true,  true,               0x00,               0x07})
#define CRC5_ITU                CRC5_G_704
#define CRC5_USB                (( Crc8BasedAlgo){ 5,               0x05,               0x1F,  true,  true,               0x1F,               0x19})
#define CRC6_CDMA2000_A         (( Crc8BasedAlgo){ 6,               0x27,               0x3F, false, false,               0x00,               0x0D})
#define CRC6_CDMA2000_B         (( Crc8BasedAlgo){ 6,               0x07,               0x3F, false, false,               0x00,               0x3B})
#define CRC6_DARC               (( Crc8BasedAlgo){ 6,               0x19,               0x00,  true,  true,               0x00,               0x26})
#define CRC6_G_704              (( Crc8BasedAlgo){ 6,               0x03,               0x00,  true,  true,               0x00,               0x06})
#define CRC6_ITU                CRC6_G_704
#define CRC6_GSM                (( Crc8BasedAlgo){ 6,               0x2F,               0x00, false, false,               0x3F,               0x13})
#define CRC7_MMC                (( Crc8BasedAlgo){ 7,               0x09,               0x00, false, false,               0x00,               0x75})
#define CRC7_ROHC               (( Crc8BasedAlgo){ 7,               0x4F,               0x7F,  true,  true,               0x00,               0x53})
#define CRC7_UMTS               (( Crc8BasedAlgo){ 7,               0x45,               0x00, false, false,               0x00,               0x61})
#define CRC8_AUTOSAR            (( Crc8BasedAlgo){ 8,               0x2F,               0xFF, false, false,               0xFF,               0xDF})
#define CRC8_BLUETOOTH          (( Crc8BasedAlgo){ 8,               0xA7,               0x00,  true,  true,               0x00,               0x26})
#define CRC8_CDMA2000           (( Crc8BasedAlgo){ 8,               0x9B,               0xFF, false, false,               0x00,               0xDA})
#define CRC8_DARC               (( Crc8BasedAlgo){ 8,               0x39,               0x00,  true,  true,               0x00,               0x15})
#define CRC8_DVB_S2             (( Crc8BasedAlgo){ 8,               0xD5,               0x00, false, false,               0x00,               0xBC})
#define CRC8_GSM_A              (( Crc8BasedAlgo){ 8,               0x1D,               0x00, false, false,               0x00,               0x37})
#define CRC8_GSM_B              (( Crc8BasedAlgo){ 8,               0x49,               0x00, false, false,               0xFF,               0x94})
#define CRC8_HITAG              (( Crc8BasedAlgo){ 8,               0x1D,               0xFF, false, false,               0x00,               0xB4})
#define CRC8_I_432_1            (( Crc8BasedAlgo){ 8,               0x07,               0x00, false, false,               0x55,               0xA1})
#define CRC8_ITU                CRC8_I_432_1
#define CRC8_I_CODE             (( Crc8BasedAlgo){ 8,               0x1D,               0xFD, false, false,               0x00,               0x7E})
#define CRC8_LTE                (( Crc8BasedAlgo){ 8,               0x9B,               0x00, false, false,               0x00,               0xEA})
#define CRC8_MAXIM_DOW          (( Crc8BasedAlgo){ 8,               0x31,               0x00,  true,  true,               0x00,               0xA1})
#define CRC8_MAXIM              CRC8_MAXIM_DOW
#define CRC8_MIFARE_MAD         (( Crc8BasedAlgo){ 8,               0x1D,               0xC7, false, false,               0x00,               0x99})
#define CRC8_NRSC_5             (( Crc8BasedAlgo){ 8,               0x31,               0xFF, false, false,               0x00,               0xF7})
#define CRC8_OPENSAFETY         (( Crc8BasedAlgo){ 8,               0x2F,               0x00, false, false,               0x00,               0x3E})
#define CRC8_ROHC               (( Crc8BasedAlgo){ 8,               0x07,               0xFF,  true,  true,               0x00,               0xD0})
#define CRC8_SAE_J1850          (( Crc8BasedAlgo){ 8,               0x1D,               0xFF, false, false,               0xFF,               0x4B})
#define CRC8_SMBUS              (( Crc8BasedAlgo){ 8,               0x07,               0x00, false, false,               0x00,               0xF4})
#define CRC8_TECH_3250          (( Crc8BasedAlgo){ 8,               0x1D,               0xFF,  true,  true,               0x00,               0x97})
#define CRC8_AES                CRC8_TECH_3250
#define CRC8_EBU                CRC8_TECH_3250
#define CRC8_WCDMA              (( Crc8BasedAlgo){ 8,               0x9B,               0x00,  true,  true,               0x00,               0x25})
#define CRC10_ATM               ((Crc16BasedAlgo){10,              0x233,              0x000, false, false,              0x000,              0x199})
#define CRC10_I_610             CRC10_ATM
#define CRC10_CDMA2000          ((Crc16BasedAlgo){10,              0x3D9,              0x3FF, false, false,              0x000,              0x233})
#define CRC10_GSM               ((Crc16BasedAlgo){10,              0x175,              0x000, false, false,              0x3FF,              0x12A})
#define CRC11_FLEXRAY           ((Crc16BasedAlgo){11,              0x385,              0x01A, false, false,              0x000,              0x5A3})
#define CRC11_UMTS              ((Crc16BasedAlgo){11,              0x307,              0x000, false, false,              0x000,              0x061})
#define CRC12_CDMA2000          ((Crc16BasedAlgo){12,              0xF13,              0xFFF, false, false,              0x000,              0xD4D})
#define CRC12_DECT              ((Crc16BasedAlgo){12,              0x80F,              0x000, false, false,              0x000,              0xF5B})
#define CRC12_GSM               ((Crc16BasedAlgo){12,              0xD31,              0x000, false, false,              0xFFF,              0xB34})
#define CRC12_UMTS              ((Crc16BasedAlgo){12,              0x80F,              0x000, false,  true,              0x000,              0xDAF})
#define CRC12_3GPP              CRC12_UMTS
#define CRC13_BBC               ((Crc16BasedAlgo){13,             0x1CF5,             0x0000, false, false,             0x0000,             0x04FA})
#define CRC14_DARC              ((Crc16BasedAlgo){14,             0x0805,             0x0000,  true,  true,             0x0000,             0x082D})
#define CRC14_GSM               ((Crc16BasedAlgo){14,             0x202D,             0x0000, false, false,             0x3FFF,             0x30AE})
#define CRC15_CAN               ((Crc16BasedAlgo){15,             0x4599,             0x0000, false, false,             0x0000,             0x059E})
#define CRC15_MPT1327           ((Crc16BasedAlgo){15,             0x6815,             0x0000, false, false,             0x0001,             0x2566})
#define CRC16_ARC               ((Crc16BasedAlgo){16,             0x8005,             0x0000,  true,  true,             0x0000,             0xBB3D})
#define CRC16_LHA               CRC16_ARC
#define CRC16_CDMA2000          ((Crc16BasedAlgo){16,             0xC867,             0xFFFF, false, false,             0x0000,             0x4C06})
#define CRC16_CMS               ((Crc16BasedAlgo){16,             0x8005,             0xFFFF, false, false,             0x0000,             0xAEE7})
#define CRC16_DDS_110           ((Crc16BasedAlgo){16,             0x8005,             0x800D, false, false,             0x0000,             0x9ECF})
#define CRC16_DECT_R            ((Crc16BasedAlgo){16,             0x0589,             0x0000, false, false,             0x0001,             0x007E})
#define CRC16_DECT_X            ((Crc16BasedAlgo){16,             0x0589,             0x0000, false, false,             0x0000,             0x007F})
#define CRC16_DNP               ((Crc16BasedAlgo){16,             0x3D65,             0x0000,  true,  true,             0xFFFF,             0xEA82})
#define CRC16_EN_13757          ((Crc16BasedAlgo){16,             0x3D65,             0x0000, false, false,             0xFFFF,             0xC2B7})
#define CRC16_GENIBUS           ((Crc16BasedAlgo){16,             0x1021,             0xFFFF, false, false,             0xFFFF,             0xD64E})
#define CRC16_DARC              CRC16_GENIBUS
#define CRC16_EPC               CRC16_GENIBUS
#define CRC16_EPC_C1G2          CRC16_GENIBUS
#define CRC16_I_CODE            CRC16_GENIBUS
#define CRC16_GSM               ((Crc16BasedAlgo){16,             0x1021,             0x0000, false, false,             0xFFFF,             0xCE3C})
#define CRC16_IBM_3740          ((Crc16BasedAlgo){16,             0x1021,             0xFFFF, false, false,             0x0000,             0x29B1})
#define CRC16_AUTOSAR           CRC16_IBM_3740
#define CRC16_CCITT_FALSE       CRC16_IBM_3740
#define CRC16_IBM_SDLC          ((Crc16BasedAlgo){16,             0x1021,             0xFFFF,  true,  true,             0xFFFF,             0x906E})
#define CRC16_ISO_HDLC          CRC16_IBM_SDLC
#define CRC16_ISO_IEC_14443_3_B CRC16_IBM_SDLC
#define CRC16_X_25              CRC16_IBM_SDLC
#define CRC16_ISO_IEC_14443_3_A ((Crc16BasedAlgo){16,             0x1021,             0xC6C6,  true,  true,             0x0000,             0xBF05})
#define CRC16_KERMIT            ((Crc16BasedAlgo){16,             0x1021,             0x0000,  true,  true,             0x0000,             0x2189})
#define CRC16_BLUETOOTH         CRC16_KERMIT
#define CRC16_CCITT             CRC16_KERMIT
#define CRC16_CCITT_TRUE        CRC16_KERMIT
#define CRC16_V_41_LSB          CRC16_KERMIT
#define CRC16_LJ1200            ((Crc16BasedAlgo){16,             0x6F63,             0x0000, false, false,             0x0000,             0xBDF4})
#define CRC16_M17               ((Crc16BasedAlgo){16,             0x5935,             0xFFFF, false, false,             0x0000,             0x772B})
#define CRC16_MAXIM_DOW         ((Crc16BasedAlgo){16,             0x8005,             0x0000,  true,  true,             0xFFFF,             0x44C2})
#define CRC16_MAXIM             CRC16_MAXIM_DOW
#define CRC16_MCRF4XX           ((Crc16BasedAlgo){16,             0x1021,             0xFFFF,  true,  true,             0x0000,             0x6F91})
#define CRC16_MODBUS            ((Crc16BasedAlgo){16,             0x8005,             0xFFFF,  true,  true,             0x0000,             0x4B37})
#define CRC16_NRSC_5            ((Crc16BasedAlgo){16,             0x080B,             0xFFFF,  true,  true,             0x0000,             0xA066})
#define CRC16_OPENSAFETY_A      ((Crc16BasedAlgo){16,             0x5935,             0x0000, false, false,             0x0000,             0x5D38})
#define CRC16_OPENSAFETY_B      ((Crc16BasedAlgo){16,             0x755B,             0x0000, false, false,             0x0000,             0x20FE})
#define CRC16_PROFIBUS          ((Crc16BasedAlgo){16,             0x1DCF,             0xFFFF, false, false,             0xFFFF,             0xA819})
#define CRC16_IEC_61158_2       CRC16_PROFIBUS
#define CRC16_RIELLO            ((Crc16BasedAlgo){16,             0x1021,             0xB2AA,  true,  true,             0x0000,             0x63D0})
#define CRC16_SPI_FUJITSU       ((Crc16BasedAlgo){16,             0x1021,             0x1D0F, false, false,             0x0000,             0xE5CC})
#define CRC16_AUG_CCITT         CRC16_SPI_FUJITSU
#define CRC16_T10_DIF           ((Crc16BasedAlgo){16,             0x8BB7,             0x0000, false, false,             0x0000,             0xD0DB})
#define CRC16_TELEDISK          ((Crc16BasedAlgo){16,             0xA097,             0x0000, false, false,             0x0000,             0x0FB3})
#define CRC16_TMS37157          ((Crc16BasedAlgo){16,             0x1021,             0x89EC,  true,  true,             0x0000,             0x26B1})
#define CRC16_UMTS              ((Crc16BasedAlgo){16,             0x8005,             0x0000, false, false,             0x0000,             0xFEE8})
#define CRC16_BUYPASS           CRC16_UMTS
#define CRC16_VERIFONE          CRC16_UMTS
#define CRC16_USB               ((Crc16BasedAlgo){16,             0x8005,             0xFFFF,  true,  true,             0xFFFF,             0xB4C8})
#define CRC16_XMODEM            ((Crc16BasedAlgo){16,             0x1021,             0x0000, false, false,             0x0000,             0x31C3})
#define CRC16_ACORN             CRC16_XMODEM
#define CRC16_LTE               CRC16_XMODEM
#define CRC16_V_41_MSB          CRC16_XMODEM
#define CRC17_CAN_FD            ((Crc32BasedAlgo){17,            0x1685B,            0x00000, false, false,            0x00000,            0x04F03})
#define CRC21_CAN_FD            ((Crc32BasedAlgo){21,           0x102899,           0x000000, false, false,           0x000000,           0x0ED841})
#define CRC24_BLE               ((Crc32BasedAlgo){24,           0x00065B,           0x555555,  true,  true,           0x000000,           0xC25A56})
#define CRC24_FLEXRAY_A         ((Crc32BasedAlgo){24,           0x5D6DCB,           0xFEDCBA, false, false,           0x000000,           0x7979BD})
#define CRC24_FLEXRAY_B         ((Crc32BasedAlgo){24,           0x5D6DCB,           0xABCDEF, false, false,           0x000000,           0x1F23B8})
#define CRC24_INTERLAKEN        ((Crc32BasedAlgo){24,           0x328B63,           0xFFFFFF, false, false,           0xFFFFFF,           0xB4F3E6})
#define CRC24_LTE_A             ((Crc32BasedAlgo){24,           0x864CFB,           0x000000, false, false,           0x000000,           0xCDE703})
#define CRC24_LTE_B             ((Crc32BasedAlgo){24,           0x800063,           0x000000, false, false,           0x000000,           0x23EF52})
#define CRC24_OPENPGP           ((Crc32BasedAlgo){24,           0x864CFB,           0xB704CE, false, false,           0x000000,           0x21CF02})
#define CRC24_OS_9              ((Crc32BasedAlgo){24,           0x800063,           0xFFFFFF, false, false,           0xFFFFFF,           0x200FA5})
#define CRC30_CDMA              ((Crc32BasedAlgo){30,         0x2030B9C7,         0x3FFFFFFF, false, false,         0x3FFFFFFF,         0x04C34ABF})
#define CRC31_PHILIPS           ((Crc32BasedAlgo){31,         0x04C11DB7,         0x7FFFFFFF, false, false,         0x7FFFFFFF,         0x0CE9E46C})
#define CRC32_AIXM              ((Crc32BasedAlgo){32,         0x814141AB,         0x00000000, false, false,         0x00000000,         0x3010BF7F})
#define CRC32_AUTOSAR           ((Crc32BasedAlgo){32,         0xF4ACFB13,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0x1697D06A})
#define CRC32_BASE91_D          ((Crc32BasedAlgo){32,         0xA833982B,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0x87315576})
#define CRC32_BZIP2             ((Crc32BasedAlgo){32,         0x04C11DB7,         0xFFFFFFFF, false, false,         0xFFFFFFFF,         0xFC891918})
#define CRC32_AAL5              CRC32_BZIP2
#define CRC32_DECT_B            CRC32_BZIP2
#define CRC32_CD_ROM_EDC        ((Crc32BasedAlgo){32,         0x8001801B,         0x00000000,  true,  true,         0x00000000,         0x6EC2EDC4})
#define CRC32_CKSUM             ((Crc32BasedAlgo){32,         0x04C11DB7,         0x00000000, false, false,         0xFFFFFFFF,         0x765E7680})
#define CRC32_POSIX             CRC32_CKSUM
#define CRC32_ISCSI             ((Crc32BasedAlgo){32,         0x1EDC6F41,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0xE3069283})
#define CRC32_BASE91_C          CRC32_ISCSI
#define CRC32_CASTAGNOLI        CRC32_ISCSI
#define CRC32_INTERLAKEN        CRC32_ISCSI
#define CRC32_ISO_HDLC          ((Crc32BasedAlgo){32,         0x04C11DB7,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0xCBF43926})
#define CRC32_ADCCP             CRC32_ISO_HDLC
#define CRC32_V_42              CRC32_ISO_HDLC
#define CRC32_XZ                CRC32_ISO_HDLC
#define CRC32_JAMCRC            ((Crc32BasedAlgo){32,         0x04C11DB7,         0xFFFFFFFF,  true,  true,         0x00000000,         0x340BC6D9})
#define CRC32_MEF               ((Crc32BasedAlgo){32,         0x741B8CD7,         0xFFFFFFFF,  true,  true,         0x00000000,         0xD2C22F51})
#define CRC32_MPEG_2            ((Crc32BasedAlgo){32,         0x04C11DB7,         0xFFFFFFFF, false, false,         0x00000000,         0x0376E6E7})
#define CRC32_XFER              ((Crc32BasedAlgo){32,         0x000000AF,         0x00000000, false, false,         0x00000000,         0xBD0BE338})
#define CRC40_GSM               ((Crc64BasedAlgo){40,       0x0004820009,       0x0000000000, false, false,       0xFFFFFFFFFF,       0xD4164FC646})
#define CRC64_ECMA_182          ((Crc64BasedAlgo){64, 0x42F0E1EBA9EA3693, 0x0000000000000000, false, false, 0x0000000000000000, 0x6C40DF5F0B497347})
#define CRC64_GO_ISO            ((Crc64BasedAlgo){64, 0x000000000000001B, 0xFFFFFFFFFFFFFFFF,  true,  true, 0xFFFFFFFFFFFFFFFF, 0xB90956C775A41001})
#define CRC64_MS                ((Crc64BasedAlgo){64, 0x259C84CBA6426349, 0xFFFFFFFFFFFFFFFF,  true,  true, 0x0000000000000000, 0x75D4B74F024ECEEA})
#define CRC64_REDIS             ((Crc64BasedAlgo){64, 0xAD93D23594C935A9, 0x0000000000000000,  true,  true, 0x0000000000000000, 0xE9C6D914C4B8D9CA})
#define CRC64_WE                ((Crc64BasedAlgo){64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, false, false, 0xFFFFFFFFFFFFFFFF, 0x62EC59E3F1A4F00A})
#define CRC64_XZ                ((Crc64BasedAlgo){64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF,  true,  true, 0xFFFFFFFFFFFFFFFF, 0x995DC9BBDF1939FA})
#define CRC64_GO_ECMA           CRC64_XZ

#ifdef __SIZEOF_INT128__
#define CRC82_DARC              ((Crc128BasedAlgo){82,  (__uint128_t)0x0308C << 64 | 0x0111011401440411, \
                                                        (__uint128_t)0x00000 << 64 | 0x0000000000000000, \
                                                        true, true, \
                                                        (__uint128_t)0x00000 << 64 | 0x0000000000000000, \
                                                        (__uint128_t)0x09EA8 << 64 | 0x3F625023801FD612})
#endif // __SIZEOF_INT128__
// clang-format on
#endif // H_CRC_CATALOG
