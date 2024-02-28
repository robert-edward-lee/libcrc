/**
    \file catalog.hpp
    \brief <a href="https://reveng.sourceforge.io/crc-catalogue/all.htm">Перечень</a> всех стандартных и общепринятых
    CRC алгоритмов шириной вплоть до 128 бит
*/
#ifndef HPP_CRC_CATALOG
#define HPP_CRC_CATALOG

#include "crc.hpp"
// clang-format off
namespace crc {
//                                ValueType  Width              Poly                Init  RefIn RefOut              XorOut               Check
using CRC3_GSM                = Crc< uint8_t,  3,                0x3,                0x0, false, false,                0x7,                0x4>;
using CRC3_ROHC               = Crc< uint8_t,  3,                0x3,                0x7,  true,  true,                0x0,                0x6>;
using CRC4_G_704              = Crc< uint8_t,  4,                0x3,                0x0,  true,  true,                0x0,                0x7>;
using CRC4_ITU                = CRC4_G_704;
using CRC4_INTERLAKEN         = Crc< uint8_t,  4,                0x3,                0xF, false, false,                0xF,                0xB>;
using CRC5_EPC_C1G2           = Crc< uint8_t,  5,               0x09,               0x09, false, false,               0x00,               0x00>;
using CRC5_EPC                = CRC5_EPC_C1G2;
using CRC5_G_704              = Crc< uint8_t,  5,               0x15,               0x00,  true,  true,               0x00,               0x07>;
using CRC5_ITU                = CRC5_G_704;
using CRC5_USB                = Crc< uint8_t,  5,               0x05,               0x1F,  true,  true,               0x1F,               0x19>;
using CRC6_CDMA2000_A         = Crc< uint8_t,  6,               0x27,               0x3F, false, false,               0x00,               0x0D>;
using CRC6_CDMA2000_B         = Crc< uint8_t,  6,               0x07,               0x3F, false, false,               0x00,               0x3B>;
using CRC6_DARC               = Crc< uint8_t,  6,               0x19,               0x00,  true,  true,               0x00,               0x26>;
using CRC6_G_704              = Crc< uint8_t,  6,               0x03,               0x00,  true,  true,               0x00,               0x06>;
using CRC6_ITU                = CRC6_G_704;
using CRC6_GSM                = Crc< uint8_t,  6,               0x2F,               0x00, false, false,               0x3F,               0x13>;
using CRC7_MMC                = Crc< uint8_t,  7,               0x09,               0x00, false, false,               0x00,               0x75>;
using CRC7_ROHC               = Crc< uint8_t,  7,               0x4F,               0x7F,  true,  true,               0x00,               0x53>;
using CRC7_UMTS               = Crc< uint8_t,  7,               0x45,               0x00, false, false,               0x00,               0x61>;
using CRC8_AUTOSAR            = Crc< uint8_t,  8,               0x2F,               0xFF, false, false,               0xFF,               0xDF>;
using CRC8_BLUETOOTH          = Crc< uint8_t,  8,               0xA7,               0x00,  true,  true,               0x00,               0x26>;
using CRC8_CDMA2000           = Crc< uint8_t,  8,               0x9B,               0xFF, false, false,               0x00,               0xDA>;
using CRC8_DARC               = Crc< uint8_t,  8,               0x39,               0x00,  true,  true,               0x00,               0x15>;
using CRC8_DVB_S2             = Crc< uint8_t,  8,               0xD5,               0x00, false, false,               0x00,               0xBC>;
using CRC8_GSM_A              = Crc< uint8_t,  8,               0x1D,               0x00, false, false,               0x00,               0x37>;
using CRC8_GSM_B              = Crc< uint8_t,  8,               0x49,               0x00, false, false,               0xFF,               0x94>;
using CRC8_HITAG              = Crc< uint8_t,  8,               0x1D,               0xFF, false, false,               0x00,               0xB4>;
using CRC8_I_432_1            = Crc< uint8_t,  8,               0x07,               0x00, false, false,               0x55,               0xA1>;
using CRC8_ITU                = CRC8_I_432_1;
using CRC8_I_CODE             = Crc< uint8_t,  8,               0x1D,               0xFD, false, false,               0x00,               0x7E>;
using CRC8_LTE                = Crc< uint8_t,  8,               0x9B,               0x00, false, false,               0x00,               0xEA>;
using CRC8_MAXIM_DOW          = Crc< uint8_t,  8,               0x31,               0x00,  true,  true,               0x00,               0xA1>;
using CRC8_MAXIM              = CRC8_MAXIM_DOW;
using CRC8_MIFARE_MAD         = Crc< uint8_t,  8,               0x1D,               0xC7, false, false,               0x00,               0x99>;
using CRC8_NRSC_5             = Crc< uint8_t,  8,               0x31,               0xFF, false, false,               0x00,               0xF7>;
using CRC8_OPENSAFETY         = Crc< uint8_t,  8,               0x2F,               0x00, false, false,               0x00,               0x3E>;
using CRC8_ROHC               = Crc< uint8_t,  8,               0x07,               0xFF,  true,  true,               0x00,               0xD0>;
using CRC8_SAE_J1850          = Crc< uint8_t,  8,               0x1D,               0xFF, false, false,               0xFF,               0x4B>;
using CRC8_SMBUS              = Crc< uint8_t,  8,               0x07,               0x00, false, false,               0x00,               0xF4>;
using CRC8_TECH_3250          = Crc< uint8_t,  8,               0x1D,               0xFF,  true,  true,               0x00,               0x97>;
using CRC8_AES                = CRC8_TECH_3250;
using CRC8_EBU                = CRC8_TECH_3250;
using CRC8_WCDMA              = Crc< uint8_t,  8,               0x9B,               0x00,  true,  true,               0x00,               0x25>;
using CRC10_ATM               = Crc<uint16_t, 10,              0x233,              0x000, false, false,              0x000,              0x199>;
using CRC10_I_610             = CRC10_ATM;
using CRC10_CDMA2000          = Crc<uint16_t, 10,              0x3D9,              0x3FF, false, false,              0x000,              0x233>;
using CRC10_GSM               = Crc<uint16_t, 10,              0x175,              0x000, false, false,              0x3FF,              0x12A>;
using CRC11_FLEXRAY           = Crc<uint16_t, 11,              0x385,              0x01A, false, false,              0x000,              0x5A3>;
using CRC11_UMTS              = Crc<uint16_t, 11,              0x307,              0x000, false, false,              0x000,              0x061>;
using CRC12_CDMA2000          = Crc<uint16_t, 12,              0xF13,              0xFFF, false, false,              0x000,              0xD4D>;
using CRC12_DECT              = Crc<uint16_t, 12,              0x80F,              0x000, false, false,              0x000,              0xF5B>;
using CRC12_GSM               = Crc<uint16_t, 12,              0xD31,              0x000, false, false,              0xFFF,              0xB34>;
using CRC12_UMTS              = Crc<uint16_t, 12,              0x80F,              0x000, false,  true,              0x000,              0xDAF>;
using CRC12_3GPP              = CRC12_UMTS;
using CRC13_BBC               = Crc<uint16_t, 13,             0x1CF5,             0x0000, false, false,             0x0000,             0x04FA>;
using CRC14_DARC              = Crc<uint16_t, 14,             0x0805,             0x0000,  true,  true,             0x0000,             0x082D>;
using CRC14_GSM               = Crc<uint16_t, 14,             0x202D,             0x0000, false, false,             0x3FFF,             0x30AE>;
using CRC15_CAN               = Crc<uint16_t, 15,             0x4599,             0x0000, false, false,             0x0000,             0x059E>;
using CRC15_MPT1327           = Crc<uint16_t, 15,             0x6815,             0x0000, false, false,             0x0001,             0x2566>;
using CRC16_ARC               = Crc<uint16_t, 16,             0x8005,             0x0000,  true,  true,             0x0000,             0xBB3D>;
using CRC16_LHA               = CRC16_ARC;
using CRC16_CDMA2000          = Crc<uint16_t, 16,             0xC867,             0xFFFF, false, false,             0x0000,             0x4C06>;
using CRC16_CMS               = Crc<uint16_t, 16,             0x8005,             0xFFFF, false, false,             0x0000,             0xAEE7>;
using CRC16_DDS_110           = Crc<uint16_t, 16,             0x8005,             0x800D, false, false,             0x0000,             0x9ECF>;
using CRC16_DECT_R            = Crc<uint16_t, 16,             0x0589,             0x0000, false, false,             0x0001,             0x007E>;
using CRC16_DECT_X            = Crc<uint16_t, 16,             0x0589,             0x0000, false, false,             0x0000,             0x007F>;
using CRC16_DNP               = Crc<uint16_t, 16,             0x3D65,             0x0000,  true,  true,             0xFFFF,             0xEA82>;
using CRC16_EN_13757          = Crc<uint16_t, 16,             0x3D65,             0x0000, false, false,             0xFFFF,             0xC2B7>;
using CRC16_GENIBUS           = Crc<uint16_t, 16,             0x1021,             0xFFFF, false, false,             0xFFFF,             0xD64E>;
using CRC16_DARC              = CRC16_GENIBUS;
using CRC16_EPC               = CRC16_GENIBUS;
using CRC16_EPC_C1G2          = CRC16_GENIBUS;
using CRC16_I_CODE            = CRC16_GENIBUS;
using CRC16_GSM               = Crc<uint16_t, 16,             0x1021,             0x0000, false, false,             0xFFFF,             0xCE3C>;
using CRC16_IBM_3740          = Crc<uint16_t, 16,             0x1021,             0xFFFF, false, false,             0x0000,             0x29B1>;
using CRC16_AUTOSAR           = CRC16_IBM_3740;
using CRC16_CCITT_FALSE       = CRC16_IBM_3740;
using CRC16_IBM_SDLC          = Crc<uint16_t, 16,             0x1021,             0xFFFF,  true,  true,             0xFFFF,             0x906E>;
using CRC16_ISO_HDLC          = CRC16_IBM_SDLC;
using CRC16_ISO_IEC_14443_3_B = CRC16_IBM_SDLC;
using CRC16_X_25              = CRC16_IBM_SDLC;
using CRC16_ISO_IEC_14443_3_A = Crc<uint16_t, 16,             0x1021,             0xC6C6,  true,  true,             0x0000,             0xBF05>;
using CRC16_KERMIT            = Crc<uint16_t, 16,             0x1021,             0x0000,  true,  true,             0x0000,             0x2189>;
using CRC16_BLUETOOTH         = CRC16_KERMIT;
using CRC16_CCITT             = CRC16_KERMIT;
using CRC16_CCITT_TRUE        = CRC16_KERMIT;
using CRC16_V_41_LSB          = CRC16_KERMIT;
using CRC16_LJ1200            = Crc<uint16_t, 16,             0x6F63,             0x0000, false, false,             0x0000,             0xBDF4>;
using CRC16_M17               = Crc<uint16_t, 16,             0x5935,             0xFFFF, false, false,             0x0000,             0x772B>;
using CRC16_MAXIM_DOW         = Crc<uint16_t, 16,             0x8005,             0x0000,  true,  true,             0xFFFF,             0x44C2>;
using CRC16_MAXIM             = CRC16_MAXIM_DOW;
using CRC16_MCRF4XX           = Crc<uint16_t, 16,             0x1021,             0xFFFF,  true,  true,             0x0000,             0x6F91>;
using CRC16_MODBUS            = Crc<uint16_t, 16,             0x8005,             0xFFFF,  true,  true,             0x0000,             0x4B37>;
using CRC16_NRSC_5            = Crc<uint16_t, 16,             0x080B,             0xFFFF,  true,  true,             0x0000,             0xA066>;
using CRC16_OPENSAFETY_A      = Crc<uint16_t, 16,             0x5935,             0x0000, false, false,             0x0000,             0x5D38>;
using CRC16_OPENSAFETY_B      = Crc<uint16_t, 16,             0x755B,             0x0000, false, false,             0x0000,             0x20FE>;
using CRC16_PROFIBUS          = Crc<uint16_t, 16,             0x1DCF,             0xFFFF, false, false,             0xFFFF,             0xA819>;
using CRC16_IEC_61158_2       = CRC16_PROFIBUS;
using CRC16_RIELLO            = Crc<uint16_t, 16,             0x1021,             0xB2AA,  true,  true,             0x0000,             0x63D0>;
using CRC16_SPI_FUJITSU       = Crc<uint16_t, 16,             0x1021,             0x1D0F, false, false,             0x0000,             0xE5CC>;
using CRC16_AUG_CCITT         = CRC16_SPI_FUJITSU;
using CRC16_T10_DIF           = Crc<uint16_t, 16,             0x8BB7,             0x0000, false, false,             0x0000,             0xD0DB>;
using CRC16_TELEDISK          = Crc<uint16_t, 16,             0xA097,             0x0000, false, false,             0x0000,             0x0FB3>;
using CRC16_TMS37157          = Crc<uint16_t, 16,             0x1021,             0x89EC,  true,  true,             0x0000,             0x26B1>;
using CRC16_UMTS              = Crc<uint16_t, 16,             0x8005,             0x0000, false, false,             0x0000,             0xFEE8>;
using CRC16_BUYPASS           = CRC16_UMTS;
using CRC16_VERIFONE          = CRC16_UMTS;
using CRC16_USB               = Crc<uint16_t, 16,             0x8005,             0xFFFF,  true,  true,             0xFFFF,             0xB4C8>;
using CRC16_XMODEM            = Crc<uint16_t, 16,             0x1021,             0x0000, false, false,             0x0000,             0x31C3>;
using CRC16_ACORN             = CRC16_XMODEM;
using CRC16_LTE               = CRC16_XMODEM;
using CRC16_V_41_MSB          = CRC16_XMODEM;
using CRC17_CAN_FD            = Crc<uint32_t, 17,            0x1685B,            0x00000, false, false,            0x00000,            0x04F03>;
using CRC21_CAN_FD            = Crc<uint32_t, 21,           0x102899,           0x000000, false, false,           0x000000,           0x0ED841>;
using CRC24_BLE               = Crc<uint32_t, 24,           0x00065B,           0x555555,  true,  true,           0x000000,           0xC25A56>;
using CRC24_FLEXRAY_A         = Crc<uint32_t, 24,           0x5D6DCB,           0xFEDCBA, false, false,           0x000000,           0x7979BD>;
using CRC24_FLEXRAY_B         = Crc<uint32_t, 24,           0x5D6DCB,           0xABCDEF, false, false,           0x000000,           0x1F23B8>;
using CRC24_INTERLAKEN        = Crc<uint32_t, 24,           0x328B63,           0xFFFFFF, false, false,           0xFFFFFF,           0xB4F3E6>;
using CRC24_LTE_A             = Crc<uint32_t, 24,           0x864CFB,           0x000000, false, false,           0x000000,           0xCDE703>;
using CRC24_LTE_B             = Crc<uint32_t, 24,           0x800063,           0x000000, false, false,           0x000000,           0x23EF52>;
using CRC24_OPENPGP           = Crc<uint32_t, 24,           0x864CFB,           0xB704CE, false, false,           0x000000,           0x21CF02>;
using CRC24_OS_9              = Crc<uint32_t, 24,           0x800063,           0xFFFFFF, false, false,           0xFFFFFF,           0x200FA5>;
using CRC30_CDMA              = Crc<uint32_t, 30,         0x2030B9C7,         0x3FFFFFFF, false, false,         0x3FFFFFFF,         0x04C34ABF>;
using CRC31_PHILIPS           = Crc<uint32_t, 31,         0x04C11DB7,         0x7FFFFFFF, false, false,         0x7FFFFFFF,         0x0CE9E46C>;
using CRC32_AIXM              = Crc<uint32_t, 32,         0x814141AB,         0x00000000, false, false,         0x00000000,         0x3010BF7F>;
using CRC32_AUTOSAR           = Crc<uint32_t, 32,         0xF4ACFB13,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0x1697D06A>;
using CRC32_BASE91_D          = Crc<uint32_t, 32,         0xA833982B,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0x87315576>;
using CRC32_BZIP2             = Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF, false, false,         0xFFFFFFFF,         0xFC891918>;
using CRC32_AAL5              = CRC32_BZIP2;
using CRC32_DECT_B            = CRC32_BZIP2;
using CRC32_CD_ROM_EDC        = Crc<uint32_t, 32,         0x8001801B,         0x00000000,  true,  true,         0x00000000,         0x6EC2EDC4>;
using CRC32_CKSUM             = Crc<uint32_t, 32,         0x04C11DB7,         0x00000000, false, false,         0xFFFFFFFF,         0x765E7680>;
using CRC32_POSIX             = CRC32_CKSUM;
using CRC32_ISCSI             = Crc<uint32_t, 32,         0x1EDC6F41,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0xE3069283>;
using CRC32_BASE91_C          = CRC32_ISCSI;
using CRC32_CASTAGNOLI        = CRC32_ISCSI;
using CRC32_INTERLAKEN        = CRC32_ISCSI;
using CRC32_ISO_HDLC          = Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0xCBF43926>;
using CRC32_ADCCP             = CRC32_ISO_HDLC;
using CRC32_V_42              = CRC32_ISO_HDLC;
using CRC32_XZ                = CRC32_ISO_HDLC;
using CRC32_JAMCRC            = Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF,  true,  true,         0x00000000,         0x340BC6D9>;
using CRC32_MEF               = Crc<uint32_t, 32,         0x741B8CD7,         0xFFFFFFFF,  true,  true,         0x00000000,         0xD2C22F51>;
using CRC32_MPEG_2            = Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF, false, false,         0x00000000,         0x0376E6E7>;
using CRC32_XFER              = Crc<uint32_t, 32,         0x000000AF,         0x00000000, false, false,         0x00000000,         0xBD0BE338>;
using CRC40_GSM               = Crc<uint64_t, 40,       0x0004820009,       0x0000000000, false, false,       0xFFFFFFFFFF,       0xD4164FC646>;
using CRC64_ECMA_182          = Crc<uint64_t, 64, 0x42F0E1EBA9EA3693, 0x0000000000000000, false, false, 0x0000000000000000, 0x6C40DF5F0B497347>;
using CRC64_GO_ISO            = Crc<uint64_t, 64, 0x000000000000001B, 0xFFFFFFFFFFFFFFFF,  true,  true, 0xFFFFFFFFFFFFFFFF, 0xB90956C775A41001>;
using CRC64_MS                = Crc<uint64_t, 64, 0x259C84CBA6426349, 0xFFFFFFFFFFFFFFFF,  true,  true, 0x0000000000000000, 0x75D4B74F024ECEEA>;
using CRC64_REDIS             = Crc<uint64_t, 64, 0xAD93D23594C935A9, 0x0000000000000000,  true,  true, 0x0000000000000000, 0xE9C6D914C4B8D9CA>;
using CRC64_WE                = Crc<uint64_t, 64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, false, false, 0xFFFFFFFFFFFFFFFF, 0x62EC59E3F1A4F00A>;
using CRC64_XZ                = Crc<uint64_t, 64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF,  true,  true, 0xFFFFFFFFFFFFFFFF, 0x995DC9BBDF1939FA>;
using CRC64_GO_ECMA           = CRC64_XZ;

#ifdef __SIZEOF_INT128__
using CRC82_DARC              = Crc<__uint128_t, 82,
                                   (__uint128_t)0x0308C << 64 | 0x0111011401440411,
                                   (__uint128_t)0x00000 << 64 | 0x0000000000000000,
                                   true, true,
                                   (__uint128_t)0x00000 << 64 | 0x0000000000000000,
                                   (__uint128_t)0x09EA8 << 64 | 0x3F625023801FD612>;
#endif
} // namespace crc
// clang-format on

#endif // HPP_CRC_CATALOG
