/**
    \file catalog.hxx
    \brief <a href="https://reveng.sourceforge.io/crc-catalogue/all.htm">Перечень</a> всех стандартных и общепринятых
    CRC алгоритмов шириной вплоть до 128 бит
*/
#ifndef HXX_CRCXX_CATALOG
#define HXX_CRCXX_CATALOG
#include "detail/types.hxx"
// clang-format off
namespace crc {
template<typename ValueType, size_t Width, ValueType Poly, ValueType Init, bool RefIn, bool RefOut, ValueType XorOut, ValueType Check> class Crc;
//        ValueType  Width              Poly                Init  RefIn RefOut              XorOut               Check
typedef Crc< uint8_t,  3,                0x3,                0x0, false, false,                0x7,                0x4> CRC3_GSM;
typedef Crc< uint8_t,  3,                0x3,                0x7,  true,  true,                0x0,                0x6> CRC3_ROHC;
typedef Crc< uint8_t,  4,                0x3,                0x0,  true,  true,                0x0,                0x7> CRC4_G_704;
typedef CRC4_G_704                                                                                                      CRC4_ITU;
typedef Crc< uint8_t,  4,                0x3,                0xF, false, false,                0xF,                0xB> CRC4_INTERLAKEN;
typedef Crc< uint8_t,  5,               0x09,               0x09, false, false,               0x00,               0x00> CRC5_EPC_C1G2;
typedef CRC5_EPC_C1G2                                                                                                   CRC5_EPC;
typedef Crc< uint8_t,  5,               0x15,               0x00,  true,  true,               0x00,               0x07> CRC5_G_704;
typedef CRC5_G_704                                                                                                      CRC5_ITU;
typedef Crc< uint8_t,  5,               0x05,               0x1F,  true,  true,               0x1F,               0x19> CRC5_USB;
typedef Crc< uint8_t,  6,               0x27,               0x3F, false, false,               0x00,               0x0D> CRC6_CDMA2000_A;
typedef Crc< uint8_t,  6,               0x07,               0x3F, false, false,               0x00,               0x3B> CRC6_CDMA2000_B;
typedef Crc< uint8_t,  6,               0x19,               0x00,  true,  true,               0x00,               0x26> CRC6_DARC;
typedef Crc< uint8_t,  6,               0x03,               0x00,  true,  true,               0x00,               0x06> CRC6_G_704;
typedef CRC6_G_704                                                                                                      CRC6_ITU;
typedef Crc< uint8_t,  6,               0x2F,               0x00, false, false,               0x3F,               0x13> CRC6_GSM;
typedef Crc< uint8_t,  7,               0x09,               0x00, false, false,               0x00,               0x75> CRC7_MMC;
typedef Crc< uint8_t,  7,               0x4F,               0x7F,  true,  true,               0x00,               0x53> CRC7_ROHC;
typedef Crc< uint8_t,  7,               0x45,               0x00, false, false,               0x00,               0x61> CRC7_UMTS;
typedef Crc< uint8_t,  8,               0x2F,               0xFF, false, false,               0xFF,               0xDF> CRC8_AUTOSAR;
typedef Crc< uint8_t,  8,               0xA7,               0x00,  true,  true,               0x00,               0x26> CRC8_BLUETOOTH;
typedef Crc< uint8_t,  8,               0x9B,               0xFF, false, false,               0x00,               0xDA> CRC8_CDMA2000;
typedef Crc< uint8_t,  8,               0x39,               0x00,  true,  true,               0x00,               0x15> CRC8_DARC;
typedef Crc< uint8_t,  8,               0xD5,               0x00, false, false,               0x00,               0xBC> CRC8_DVB_S2;
typedef Crc< uint8_t,  8,               0x1D,               0x00, false, false,               0x00,               0x37> CRC8_GSM_A;
typedef Crc< uint8_t,  8,               0x49,               0x00, false, false,               0xFF,               0x94> CRC8_GSM_B;
typedef Crc< uint8_t,  8,               0x1D,               0xFF, false, false,               0x00,               0xB4> CRC8_HITAG;
typedef Crc< uint8_t,  8,               0x07,               0x00, false, false,               0x55,               0xA1> CRC8_I_432_1;
typedef CRC8_I_432_1                                                                                                    CRC8_ITU;
typedef Crc< uint8_t,  8,               0x1D,               0xFD, false, false,               0x00,               0x7E> CRC8_I_CODE;
typedef Crc< uint8_t,  8,               0x9B,               0x00, false, false,               0x00,               0xEA> CRC8_LTE;
typedef Crc< uint8_t,  8,               0x31,               0x00,  true,  true,               0x00,               0xA1> CRC8_MAXIM_DOW;
typedef CRC8_MAXIM_DOW                                                                                                  CRC8_MAXIM;
typedef Crc< uint8_t,  8,               0x1D,               0xC7, false, false,               0x00,               0x99> CRC8_MIFARE_MAD;
typedef Crc< uint8_t,  8,               0x31,               0xFF, false, false,               0x00,               0xF7> CRC8_NRSC_5;
typedef Crc< uint8_t,  8,               0x2F,               0x00, false, false,               0x00,               0x3E> CRC8_OPENSAFETY;
typedef Crc< uint8_t,  8,               0x07,               0xFF,  true,  true,               0x00,               0xD0> CRC8_ROHC;
typedef Crc< uint8_t,  8,               0x1D,               0xFF, false, false,               0xFF,               0x4B> CRC8_SAE_J1850;
typedef Crc< uint8_t,  8,               0x07,               0x00, false, false,               0x00,               0xF4> CRC8_SMBUS;
typedef Crc< uint8_t,  8,               0x1D,               0xFF,  true,  true,               0x00,               0x97> CRC8_TECH_3250;
typedef CRC8_TECH_3250                                                                                                  CRC8_AES;
typedef CRC8_TECH_3250                                                                                                  CRC8_EBU;
typedef Crc< uint8_t,  8,               0x9B,               0x00,  true,  true,               0x00,               0x25> CRC8_WCDMA;
typedef Crc<uint16_t, 10,              0x233,              0x000, false, false,              0x000,              0x199> CRC10_ATM;
typedef CRC10_ATM                                                                                                       CRC10_I_610;
typedef Crc<uint16_t, 10,              0x3D9,              0x3FF, false, false,              0x000,              0x233> CRC10_CDMA2000;
typedef Crc<uint16_t, 10,              0x175,              0x000, false, false,              0x3FF,              0x12A> CRC10_GSM;
typedef Crc<uint16_t, 11,              0x385,              0x01A, false, false,              0x000,              0x5A3> CRC11_FLEXRAY;
typedef Crc<uint16_t, 11,              0x307,              0x000, false, false,              0x000,              0x061> CRC11_UMTS;
typedef Crc<uint16_t, 12,              0xF13,              0xFFF, false, false,              0x000,              0xD4D> CRC12_CDMA2000;
typedef Crc<uint16_t, 12,              0x80F,              0x000, false, false,              0x000,              0xF5B> CRC12_DECT;
typedef Crc<uint16_t, 12,              0xD31,              0x000, false, false,              0xFFF,              0xB34> CRC12_GSM;
typedef Crc<uint16_t, 12,              0x80F,              0x000, false,  true,              0x000,              0xDAF> CRC12_UMTS;
typedef CRC12_UMTS                                                                                                      CRC12_3GPP;
typedef Crc<uint16_t, 13,             0x1CF5,             0x0000, false, false,             0x0000,             0x04FA> CRC13_BBC;
typedef Crc<uint16_t, 14,             0x0805,             0x0000,  true,  true,             0x0000,             0x082D> CRC14_DARC;
typedef Crc<uint16_t, 14,             0x202D,             0x0000, false, false,             0x3FFF,             0x30AE> CRC14_GSM;
typedef Crc<uint16_t, 15,             0x4599,             0x0000, false, false,             0x0000,             0x059E> CRC15_CAN;
typedef Crc<uint16_t, 15,             0x6815,             0x0000, false, false,             0x0001,             0x2566> CRC15_MPT1327;
typedef Crc<uint16_t, 16,             0x8005,             0x0000,  true,  true,             0x0000,             0xBB3D> CRC16_ARC;
typedef CRC16_ARC                                                                                                       CRC16_LHA;
typedef Crc<uint16_t, 16,             0xC867,             0xFFFF, false, false,             0x0000,             0x4C06> CRC16_CDMA2000;
typedef Crc<uint16_t, 16,             0x8005,             0xFFFF, false, false,             0x0000,             0xAEE7> CRC16_CMS;
typedef Crc<uint16_t, 16,             0x8005,             0x800D, false, false,             0x0000,             0x9ECF> CRC16_DDS_110;
typedef Crc<uint16_t, 16,             0x0589,             0x0000, false, false,             0x0001,             0x007E> CRC16_DECT_R;
typedef Crc<uint16_t, 16,             0x0589,             0x0000, false, false,             0x0000,             0x007F> CRC16_DECT_X;
typedef Crc<uint16_t, 16,             0x3D65,             0x0000,  true,  true,             0xFFFF,             0xEA82> CRC16_DNP;
typedef Crc<uint16_t, 16,             0x3D65,             0x0000, false, false,             0xFFFF,             0xC2B7> CRC16_EN_13757;
typedef Crc<uint16_t, 16,             0x1021,             0xFFFF, false, false,             0xFFFF,             0xD64E> CRC16_GENIBUS;
typedef CRC16_GENIBUS                                                                                                   CRC16_DARC;
typedef CRC16_GENIBUS                                                                                                   CRC16_EPC;
typedef CRC16_GENIBUS                                                                                                   CRC16_EPC_C1G2;
typedef CRC16_GENIBUS                                                                                                   CRC16_I_CODE;
typedef Crc<uint16_t, 16,             0x1021,             0x0000, false, false,             0xFFFF,             0xCE3C> CRC16_GSM;
typedef Crc<uint16_t, 16,             0x1021,             0xFFFF, false, false,             0x0000,             0x29B1> CRC16_IBM_3740;
typedef CRC16_IBM_3740                                                                                                  CRC16_AUTOSAR;
typedef CRC16_IBM_3740                                                                                                  CRC16_CCITT_FALSE;
typedef Crc<uint16_t, 16,             0x1021,             0xFFFF,  true,  true,             0xFFFF,             0x906E> CRC16_IBM_SDLC;
typedef CRC16_IBM_SDLC                                                                                                  CRC16_ISO_HDLC;
typedef CRC16_IBM_SDLC                                                                                                  CRC16_ISO_IEC_14443_3_B;
typedef CRC16_IBM_SDLC                                                                                                  CRC16_X_25;
typedef Crc<uint16_t, 16,             0x1021,             0xC6C6,  true,  true,             0x0000,             0xBF05> CRC16_ISO_IEC_14443_3_A;
typedef Crc<uint16_t, 16,             0x1021,             0x0000,  true,  true,             0x0000,             0x2189> CRC16_KERMIT;
typedef CRC16_KERMIT                                                                                                    CRC16_BLUETOOTH;
typedef CRC16_KERMIT                                                                                                    CRC16_CCITT;
typedef CRC16_KERMIT                                                                                                    CRC16_CCITT_TRUE;
typedef CRC16_KERMIT                                                                                                    CRC16_V_41_LSB;
typedef Crc<uint16_t, 16,             0x6F63,             0x0000, false, false,             0x0000,             0xBDF4> CRC16_LJ1200;
typedef Crc<uint16_t, 16,             0x5935,             0xFFFF, false, false,             0x0000,             0x772B> CRC16_M17;
typedef Crc<uint16_t, 16,             0x8005,             0x0000,  true,  true,             0xFFFF,             0x44C2> CRC16_MAXIM_DOW;
typedef CRC16_MAXIM_DOW                                                                                                 CRC16_MAXIM;
typedef Crc<uint16_t, 16,             0x1021,             0xFFFF,  true,  true,             0x0000,             0x6F91> CRC16_MCRF4XX;
typedef Crc<uint16_t, 16,             0x8005,             0xFFFF,  true,  true,             0x0000,             0x4B37> CRC16_MODBUS;
typedef Crc<uint16_t, 16,             0x080B,             0xFFFF,  true,  true,             0x0000,             0xA066> CRC16_NRSC_5;
typedef Crc<uint16_t, 16,             0x5935,             0x0000, false, false,             0x0000,             0x5D38> CRC16_OPENSAFETY_A;
typedef Crc<uint16_t, 16,             0x755B,             0x0000, false, false,             0x0000,             0x20FE> CRC16_OPENSAFETY_B;
typedef Crc<uint16_t, 16,             0x1DCF,             0xFFFF, false, false,             0xFFFF,             0xA819> CRC16_PROFIBUS;
typedef CRC16_PROFIBUS                                                                                                  CRC16_IEC_61158_2;
typedef Crc<uint16_t, 16,             0x1021,             0xB2AA,  true,  true,             0x0000,             0x63D0> CRC16_RIELLO;
typedef Crc<uint16_t, 16,             0x1021,             0x1D0F, false, false,             0x0000,             0xE5CC> CRC16_SPI_FUJITSU;
typedef CRC16_SPI_FUJITSU                                                                                               CRC16_AUG_CCITT;
typedef Crc<uint16_t, 16,             0x8BB7,             0x0000, false, false,             0x0000,             0xD0DB> CRC16_T10_DIF;
typedef Crc<uint16_t, 16,             0xA097,             0x0000, false, false,             0x0000,             0x0FB3> CRC16_TELEDISK;
typedef Crc<uint16_t, 16,             0x1021,             0x89EC,  true,  true,             0x0000,             0x26B1> CRC16_TMS37157;
typedef Crc<uint16_t, 16,             0x8005,             0x0000, false, false,             0x0000,             0xFEE8> CRC16_UMTS;
typedef CRC16_UMTS                                                                                                      CRC16_BUYPASS;
typedef CRC16_UMTS                                                                                                      CRC16_VERIFONE;
typedef Crc<uint16_t, 16,             0x8005,             0xFFFF,  true,  true,             0xFFFF,             0xB4C8> CRC16_USB;
typedef Crc<uint16_t, 16,             0x1021,             0x0000, false, false,             0x0000,             0x31C3> CRC16_XMODEM;
typedef CRC16_XMODEM                                                                                                    CRC16_ACORN;
typedef CRC16_XMODEM                                                                                                    CRC16_LTE;
typedef CRC16_XMODEM                                                                                                    CRC16_V_41_MSB;
typedef Crc<uint32_t, 17,            0x1685B,            0x00000, false, false,            0x00000,            0x04F03> CRC17_CAN_FD;
typedef Crc<uint32_t, 21,           0x102899,           0x000000, false, false,           0x000000,           0x0ED841> CRC21_CAN_FD;
typedef Crc<uint32_t, 24,           0x00065B,           0x555555,  true,  true,           0x000000,           0xC25A56> CRC24_BLE;
typedef Crc<uint32_t, 24,           0x5D6DCB,           0xFEDCBA, false, false,           0x000000,           0x7979BD> CRC24_FLEXRAY_A;
typedef Crc<uint32_t, 24,           0x5D6DCB,           0xABCDEF, false, false,           0x000000,           0x1F23B8> CRC24_FLEXRAY_B;
typedef Crc<uint32_t, 24,           0x328B63,           0xFFFFFF, false, false,           0xFFFFFF,           0xB4F3E6> CRC24_INTERLAKEN;
typedef Crc<uint32_t, 24,           0x864CFB,           0x000000, false, false,           0x000000,           0xCDE703> CRC24_LTE_A;
typedef Crc<uint32_t, 24,           0x800063,           0x000000, false, false,           0x000000,           0x23EF52> CRC24_LTE_B;
typedef Crc<uint32_t, 24,           0x864CFB,           0xB704CE, false, false,           0x000000,           0x21CF02> CRC24_OPENPGP;
typedef Crc<uint32_t, 24,           0x800063,           0xFFFFFF, false, false,           0xFFFFFF,           0x200FA5> CRC24_OS_9;
typedef Crc<uint32_t, 30,         0x2030B9C7,         0x3FFFFFFF, false, false,         0x3FFFFFFF,         0x04C34ABF> CRC30_CDMA;
typedef Crc<uint32_t, 31,         0x04C11DB7,         0x7FFFFFFF, false, false,         0x7FFFFFFF,         0x0CE9E46C> CRC31_PHILIPS;
typedef Crc<uint32_t, 32,         0x814141AB,         0x00000000, false, false,         0x00000000,         0x3010BF7F> CRC32_AIXM;
typedef Crc<uint32_t, 32,         0xF4ACFB13,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0x1697D06A> CRC32_AUTOSAR;
typedef Crc<uint32_t, 32,         0xA833982B,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0x87315576> CRC32_BASE91_D;
typedef Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF, false, false,         0xFFFFFFFF,         0xFC891918> CRC32_BZIP2;
typedef CRC32_BZIP2                                                                                                     CRC32_AAL5;
typedef CRC32_BZIP2                                                                                                     CRC32_DECT_B;
typedef Crc<uint32_t, 32,         0x8001801B,         0x00000000,  true,  true,         0x00000000,         0x6EC2EDC4> CRC32_CD_ROM_EDC;
typedef Crc<uint32_t, 32,         0x04C11DB7,         0x00000000, false, false,         0xFFFFFFFF,         0x765E7680> CRC32_CKSUM;
typedef CRC32_CKSUM                                                                                                     CRC32_POSIX;
typedef Crc<uint32_t, 32,         0x1EDC6F41,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0xE3069283> CRC32_ISCSI;
typedef CRC32_ISCSI                                                                                                     CRC32_BASE91_C;
typedef CRC32_ISCSI                                                                                                     CRC32_CASTAGNOLI;
typedef CRC32_ISCSI                                                                                                     CRC32_INTERLAKEN;
typedef Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF,  true,  true,         0xFFFFFFFF,         0xCBF43926> CRC32_ISO_HDLC;
typedef CRC32_ISO_HDLC                                                                                                  CRC32_ADCCP;
typedef CRC32_ISO_HDLC                                                                                                  CRC32_V_42;
typedef CRC32_ISO_HDLC                                                                                                  CRC32_XZ;
typedef Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF,  true,  true,         0x00000000,         0x340BC6D9> CRC32_JAMCRC;
typedef Crc<uint32_t, 32,         0x741B8CD7,         0xFFFFFFFF,  true,  true,         0x00000000,         0xD2C22F51> CRC32_MEF;
typedef Crc<uint32_t, 32,         0x04C11DB7,         0xFFFFFFFF, false, false,         0x00000000,         0x0376E6E7> CRC32_MPEG_2;
typedef Crc<uint32_t, 32,         0x000000AF,         0x00000000, false, false,         0x00000000,         0xBD0BE338> CRC32_XFER;
typedef Crc<uint64_t, 40,       0x0004820009,       0x0000000000, false, false,       0xFFFFFFFFFF,       0xD4164FC646> CRC40_GSM;
typedef Crc<uint64_t, 64, 0x42F0E1EBA9EA3693, 0x0000000000000000, false, false, 0x0000000000000000, 0x6C40DF5F0B497347> CRC64_ECMA_182;
typedef Crc<uint64_t, 64, 0x000000000000001B, 0xFFFFFFFFFFFFFFFF,  true,  true, 0xFFFFFFFFFFFFFFFF, 0xB90956C775A41001> CRC64_GO_ISO;
typedef Crc<uint64_t, 64, 0x259C84CBA6426349, 0xFFFFFFFFFFFFFFFF,  true,  true, 0x0000000000000000, 0x75D4B74F024ECEEA> CRC64_MS;
typedef Crc<uint64_t, 64, 0xAD93D23594C935A9, 0x0000000000000000,  true,  true, 0x0000000000000000, 0xE9C6D914C4B8D9CA> CRC64_REDIS;
typedef Crc<uint64_t, 64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, false, false, 0xFFFFFFFFFFFFFFFF, 0x62EC59E3F1A4F00A> CRC64_WE;
typedef Crc<uint64_t, 64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF,  true,  true, 0xFFFFFFFFFFFFFFFF, 0x995DC9BBDF1939FA> CRC64_XZ;
typedef CRC64_XZ                                                                                                        CRC64_GO_ECMA;

#if CRCXX_HAS_128BIT_ALGO
typedef Crc<uint128_t, 82, (uint128_t)0x0308C << 64 | 0x0111011401440411, (uint128_t)0x00000 << 64 | 0x0000000000000000,
            true, true, (uint128_t)0x00000 << 64 | 0x0000000000000000, (uint128_t)0x09EA8 << 64 | 0x3F625023801FD612> CRC82_DARC;
#endif
} // namespace crc
// clang-format on

#endif // HXX_CRCXX_CATALOG
