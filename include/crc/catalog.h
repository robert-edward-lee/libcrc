/**
    \file catalog.h
    \brief <a href="https://reveng.sourceforge.io/crc-catalogue/all.htm">Перечень</a> всех стандартных и общепринятых
    CRC алгоритмов шириной вплоть до 128 бит
*/
#ifndef H_CRC_CATALOG
#define H_CRC_CATALOG
#include "crc/internal/defines.h"
/* clang-format off */
/*                              Width              Poly              Init RefIn RefOut         XorOut               Check */
#define CRC3_GSM                { 3,                0x3,                0x0, 0, 0,                0x7,                0x4}
#define CRC3_ROHC               { 3,                0x3,                0x7, 1, 1,                0x0,                0x6}
#define CRC4_G_704              { 4,                0x3,                0x0, 1, 1,                0x0,                0x7}
#define CRC4_ITU                CRC4_G_704
#define CRC4_INTERLAKEN         { 4,                0x3,                0xF, 0, 0,                0xF,                0xB}
#define CRC5_EPC_C1G2           { 5,               0x09,               0x09, 0, 0,               0x00,               0x00}
#define CRC5_EPC                CRC5_EPC_C1G2
#define CRC5_G_704              { 5,               0x15,               0x00, 1, 1,               0x00,               0x07}
#define CRC5_ITU                CRC5_G_704
#define CRC5_USB                { 5,               0x05,               0x1F, 1, 1,               0x1F,               0x19}
#define CRC6_CDMA2000_A         { 6,               0x27,               0x3F, 0, 0,               0x00,               0x0D}
#define CRC6_CDMA2000_B         { 6,               0x07,               0x3F, 0, 0,               0x00,               0x3B}
#define CRC6_DARC               { 6,               0x19,               0x00, 1, 1,               0x00,               0x26}
#define CRC6_G_704              { 6,               0x03,               0x00, 1, 1,               0x00,               0x06}
#define CRC6_ITU                CRC6_G_704
#define CRC6_GSM                { 6,               0x2F,               0x00, 0, 0,               0x3F,               0x13}
#define CRC7_MMC                { 7,               0x09,               0x00, 0, 0,               0x00,               0x75}
#define CRC7_ROHC               { 7,               0x4F,               0x7F, 1, 1,               0x00,               0x53}
#define CRC7_UMTS               { 7,               0x45,               0x00, 0, 0,               0x00,               0x61}
#define CRC8_AUTOSAR            { 8,               0x2F,               0xFF, 0, 0,               0xFF,               0xDF}
#define CRC8_BLUETOOTH          { 8,               0xA7,               0x00, 1, 1,               0x00,               0x26}
#define CRC8_CDMA2000           { 8,               0x9B,               0xFF, 0, 0,               0x00,               0xDA}
#define CRC8_DARC               { 8,               0x39,               0x00, 1, 1,               0x00,               0x15}
#define CRC8_DVB_S2             { 8,               0xD5,               0x00, 0, 0,               0x00,               0xBC}
#define CRC8_GSM_A              { 8,               0x1D,               0x00, 0, 0,               0x00,               0x37}
#define CRC8_GSM_B              { 8,               0x49,               0x00, 0, 0,               0xFF,               0x94}
#define CRC8_HITAG              { 8,               0x1D,               0xFF, 0, 0,               0x00,               0xB4}
#define CRC8_I_432_1            { 8,               0x07,               0x00, 0, 0,               0x55,               0xA1}
#define CRC8_ITU                CRC8_I_432_1
#define CRC8_I_CODE             { 8,               0x1D,               0xFD, 0, 0,               0x00,               0x7E}
#define CRC8_LTE                { 8,               0x9B,               0x00, 0, 0,               0x00,               0xEA}
#define CRC8_MAXIM_DOW          { 8,               0x31,               0x00, 1, 1,               0x00,               0xA1}
#define CRC8_MAXIM              CRC8_MAXIM_DOW
#define CRC8_MIFARE_MAD         { 8,               0x1D,               0xC7, 0, 0,               0x00,               0x99}
#define CRC8_NRSC_5             { 8,               0x31,               0xFF, 0, 0,               0x00,               0xF7}
#define CRC8_OPENSAFETY         { 8,               0x2F,               0x00, 0, 0,               0x00,               0x3E}
#define CRC8_ROHC               { 8,               0x07,               0xFF, 1, 1,               0x00,               0xD0}
#define CRC8_SAE_J1850          { 8,               0x1D,               0xFF, 0, 0,               0xFF,               0x4B}
#define CRC8_SMBUS              { 8,               0x07,               0x00, 0, 0,               0x00,               0xF4}
#define CRC8_TECH_3250          { 8,               0x1D,               0xFF, 1, 1,               0x00,               0x97}
#define CRC8_AES                CRC8_TECH_3250
#define CRC8_EBU                CRC8_TECH_3250
#define CRC8_WCDMA              { 8,               0x9B,               0x00, 1, 1,               0x00,               0x25}
#define CRC10_ATM               {10,              0x233,              0x000, 0, 0,              0x000,              0x199}
#define CRC10_I_610             CRC10_ATM
#define CRC10_CDMA2000          {10,              0x3D9,              0x3FF, 0, 0,              0x000,              0x233}
#define CRC10_GSM               {10,              0x175,              0x000, 0, 0,              0x3FF,              0x12A}
#define CRC11_FLEXRAY           {11,              0x385,              0x01A, 0, 0,              0x000,              0x5A3}
#define CRC11_UMTS              {11,              0x307,              0x000, 0, 0,              0x000,              0x061}
#define CRC12_CDMA2000          {12,              0xF13,              0xFFF, 0, 0,              0x000,              0xD4D}
#define CRC12_DECT              {12,              0x80F,              0x000, 0, 0,              0x000,              0xF5B}
#define CRC12_GSM               {12,              0xD31,              0x000, 0, 0,              0xFFF,              0xB34}
#define CRC12_UMTS              {12,              0x80F,              0x000, 0, 1,              0x000,              0xDAF}
#define CRC12_3GPP              CRC12_UMTS
#define CRC13_BBC               {13,             0x1CF5,             0x0000, 0, 0,             0x0000,             0x04FA}
#define CRC14_DARC              {14,             0x0805,             0x0000, 1, 1,             0x0000,             0x082D}
#define CRC14_GSM               {14,             0x202D,             0x0000, 0, 0,             0x3FFF,             0x30AE}
#define CRC15_CAN               {15,             0x4599,             0x0000, 0, 0,             0x0000,             0x059E}
#define CRC15_MPT1327           {15,             0x6815,             0x0000, 0, 0,             0x0001,             0x2566}
#define CRC16_ARC               {16,             0x8005,             0x0000, 1, 1,             0x0000,             0xBB3D}
#define CRC16_LHA               CRC16_ARC
#define CRC16_CDMA2000          {16,             0xC867,             0xFFFF, 0, 0,             0x0000,             0x4C06}
#define CRC16_CMS               {16,             0x8005,             0xFFFF, 0, 0,             0x0000,             0xAEE7}
#define CRC16_DDS_110           {16,             0x8005,             0x800D, 0, 0,             0x0000,             0x9ECF}
#define CRC16_DECT_R            {16,             0x0589,             0x0000, 0, 0,             0x0001,             0x007E}
#define CRC16_DECT_X            {16,             0x0589,             0x0000, 0, 0,             0x0000,             0x007F}
#define CRC16_DNP               {16,             0x3D65,             0x0000, 1, 1,             0xFFFF,             0xEA82}
#define CRC16_EN_13757          {16,             0x3D65,             0x0000, 0, 0,             0xFFFF,             0xC2B7}
#define CRC16_GENIBUS           {16,             0x1021,             0xFFFF, 0, 0,             0xFFFF,             0xD64E}
#define CRC16_DARC              CRC16_GENIBUS
#define CRC16_EPC               CRC16_GENIBUS
#define CRC16_EPC_C1G2          CRC16_GENIBUS
#define CRC16_I_CODE            CRC16_GENIBUS
#define CRC16_GSM               {16,             0x1021,             0x0000, 0, 0,             0xFFFF,             0xCE3C}
#define CRC16_IBM_3740          {16,             0x1021,             0xFFFF, 0, 0,             0x0000,             0x29B1}
#define CRC16_AUTOSAR           CRC16_IBM_3740
#define CRC16_CCITT_FALSE       CRC16_IBM_3740
#define CRC16_IBM_SDLC          {16,             0x1021,             0xFFFF, 1, 1,             0xFFFF,             0x906E}
#define CRC16_ISO_HDLC          CRC16_IBM_SDLC
#define CRC16_ISO_IEC_14443_3_B CRC16_IBM_SDLC
#define CRC16_X_25              CRC16_IBM_SDLC
#define CRC16_ISO_IEC_14443_3_A {16,             0x1021,             0xC6C6, 1, 1,             0x0000,             0xBF05}
#define CRC16_KERMIT            {16,             0x1021,             0x0000, 1, 1,             0x0000,             0x2189}
#define CRC16_BLUETOOTH         CRC16_KERMIT
#define CRC16_CCITT             CRC16_KERMIT
#define CRC16_CCITT_TRUE        CRC16_KERMIT
#define CRC16_V_41_LSB          CRC16_KERMIT
#define CRC16_LJ1200            {16,             0x6F63,             0x0000, 0, 0,             0x0000,             0xBDF4}
#define CRC16_M17               {16,             0x5935,             0xFFFF, 0, 0,             0x0000,             0x772B}
#define CRC16_MAXIM_DOW         {16,             0x8005,             0x0000, 1, 1,             0xFFFF,             0x44C2}
#define CRC16_MAXIM             CRC16_MAXIM_DOW
#define CRC16_MCRF4XX           {16,             0x1021,             0xFFFF, 1, 1,             0x0000,             0x6F91}
#define CRC16_MODBUS            {16,             0x8005,             0xFFFF, 1, 1,             0x0000,             0x4B37}
#define CRC16_NRSC_5            {16,             0x080B,             0xFFFF, 1, 1,             0x0000,             0xA066}
#define CRC16_OPENSAFETY_A      {16,             0x5935,             0x0000, 0, 0,             0x0000,             0x5D38}
#define CRC16_OPENSAFETY_B      {16,             0x755B,             0x0000, 0, 0,             0x0000,             0x20FE}
#define CRC16_PROFIBUS          {16,             0x1DCF,             0xFFFF, 0, 0,             0xFFFF,             0xA819}
#define CRC16_IEC_61158_2       CRC16_PROFIBUS
#define CRC16_RIELLO            {16,             0x1021,             0xB2AA, 1, 1,             0x0000,             0x63D0}
#define CRC16_SPI_FUJITSU       {16,             0x1021,             0x1D0F, 0, 0,             0x0000,             0xE5CC}
#define CRC16_AUG_CCITT         CRC16_SPI_FUJITSU
#define CRC16_T10_DIF           {16,             0x8BB7,             0x0000, 0, 0,             0x0000,             0xD0DB}
#define CRC16_TELEDISK          {16,             0xA097,             0x0000, 0, 0,             0x0000,             0x0FB3}
#define CRC16_TMS37157          {16,             0x1021,             0x89EC, 1, 1,             0x0000,             0x26B1}
#define CRC16_UMTS              {16,             0x8005,             0x0000, 0, 0,             0x0000,             0xFEE8}
#define CRC16_BUYPASS           CRC16_UMTS
#define CRC16_VERIFONE          CRC16_UMTS
#define CRC16_USB               {16,             0x8005,             0xFFFF, 1, 1,             0xFFFF,             0xB4C8}
#define CRC16_XMODEM            {16,             0x1021,             0x0000, 0, 0,             0x0000,             0x31C3}
#define CRC16_ACORN             CRC16_XMODEM
#define CRC16_LTE               CRC16_XMODEM
#define CRC16_V_41_MSB          CRC16_XMODEM
#define CRC17_CAN_FD            {17,            0x1685B,            0x00000, 0, 0,            0x00000,            0x04F03}
#define CRC21_CAN_FD            {21,           0x102899,           0x000000, 0, 0,           0x000000,           0x0ED841}
#define CRC24_BLE               {24,           0x00065B,           0x555555, 1, 1,           0x000000,           0xC25A56}
#define CRC24_FLEXRAY_A         {24,           0x5D6DCB,           0xFEDCBA, 0, 0,           0x000000,           0x7979BD}
#define CRC24_FLEXRAY_B         {24,           0x5D6DCB,           0xABCDEF, 0, 0,           0x000000,           0x1F23B8}
#define CRC24_INTERLAKEN        {24,           0x328B63,           0xFFFFFF, 0, 0,           0xFFFFFF,           0xB4F3E6}
#define CRC24_LTE_A             {24,           0x864CFB,           0x000000, 0, 0,           0x000000,           0xCDE703}
#define CRC24_LTE_B             {24,           0x800063,           0x000000, 0, 0,           0x000000,           0x23EF52}
#define CRC24_OPENPGP           {24,           0x864CFB,           0xB704CE, 0, 0,           0x000000,           0x21CF02}
#define CRC24_OS_9              {24,           0x800063,           0xFFFFFF, 0, 0,           0xFFFFFF,           0x200FA5}
#define CRC30_CDMA              {30,         0x2030B9C7,         0x3FFFFFFF, 0, 0,         0x3FFFFFFF,         0x04C34ABF}
#define CRC31_PHILIPS           {31,         0x04C11DB7,         0x7FFFFFFF, 0, 0,         0x7FFFFFFF,         0x0CE9E46C}
#define CRC32_AIXM              {32,         0x814141AB,         0x00000000, 0, 0,         0x00000000,         0x3010BF7F}
#define CRC32_AUTOSAR           {32,         0xF4ACFB13,         0xFFFFFFFF, 1, 1,         0xFFFFFFFF,         0x1697D06A}
#define CRC32_BASE91_D          {32,         0xA833982B,         0xFFFFFFFF, 1, 1,         0xFFFFFFFF,         0x87315576}
#define CRC32_BZIP2             {32,         0x04C11DB7,         0xFFFFFFFF, 0, 0,         0xFFFFFFFF,         0xFC891918}
#define CRC32_AAL5              CRC32_BZIP2
#define CRC32_DECT_B            CRC32_BZIP2
#define CRC32_CD_ROM_EDC        {32,         0x8001801B,         0x00000000, 1, 1,         0x00000000,         0x6EC2EDC4}
#define CRC32_CKSUM             {32,         0x04C11DB7,         0x00000000, 0, 0,         0xFFFFFFFF,         0x765E7680}
#define CRC32_POSIX             CRC32_CKSUM
#define CRC32_ISCSI             {32,         0x1EDC6F41,         0xFFFFFFFF, 1, 1,         0xFFFFFFFF,         0xE3069283}
#define CRC32_BASE91_C          CRC32_ISCSI
#define CRC32_CASTAGNOLI        CRC32_ISCSI
#define CRC32_INTERLAKEN        CRC32_ISCSI
#define CRC32_ISO_HDLC          {32,         0x04C11DB7,         0xFFFFFFFF, 1, 1,         0xFFFFFFFF,         0xCBF43926}
#define CRC32_ADCCP             CRC32_ISO_HDLC
#define CRC32_V_42              CRC32_ISO_HDLC
#define CRC32_XZ                CRC32_ISO_HDLC
#define CRC32_JAMCRC            {32,         0x04C11DB7,         0xFFFFFFFF, 1, 1,         0x00000000,         0x340BC6D9}
#define CRC32_MEF               {32,         0x741B8CD7,         0xFFFFFFFF, 1, 1,         0x00000000,         0xD2C22F51}
#define CRC32_MPEG_2            {32,         0x04C11DB7,         0xFFFFFFFF, 0, 0,         0x00000000,         0x0376E6E7}
#define CRC32_XFER              {32,         0x000000AF,         0x00000000, 0, 0,         0x00000000,         0xBD0BE338}
#define CRC40_GSM               {40, (uint64_t)0x00000000 << 32 | 0x04820009, (uint64_t)0x00000000 << 32 | 0x00000000,\
                               0, 0, (uint64_t)0x000000FF << 32 | 0xFFFFFFFF, (uint64_t)0x000000D4 << 32 | 0x164FC646}
#define CRC64_ECMA_182          {64, (uint64_t)0x42F0E1EB << 32 | 0xA9EA3693, (uint64_t)0x00000000 << 32 | 0x00000000,\
                               0, 0, (uint64_t)0x00000000 << 32 | 0x00000000, (uint64_t)0x6C40DF5F << 32 | 0x0B497347}
#define CRC64_GO_ISO            {64, (uint64_t)0x00000000 << 32 | 0x0000001B, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF,\
                               1, 1, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF, (uint64_t)0xB90956C7 << 32 | 0x75A41001}
#define CRC64_MS                {64, (uint64_t)0x259C84CB << 32 | 0xA6426349, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF,\
                               1, 1, (uint64_t)0x00000000 << 32 | 0x00000000, (uint64_t)0x75D4B74F << 32 | 0x024ECEEA}
#define CRC64_REDIS             {64, (uint64_t)0xAD93D235 << 32 | 0x94C935A9, (uint64_t)0x00000000 << 32 | 0x00000000,\
                               1, 1, (uint64_t)0x00000000 << 32 | 0x00000000, (uint64_t)0xE9C6D914 << 32 | 0xC4B8D9CA}
#define CRC64_WE                {64, (uint64_t)0x42F0E1EB << 32 | 0xA9EA3693, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF,\
                               0, 0, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF, (uint64_t)0x62EC59E3 << 32 | 0xF1A4F00A}
#define CRC64_XZ                {64, (uint64_t)0x42F0E1EB << 32 | 0xA9EA3693, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF,\
                               1, 1, (uint64_t)0xFFFFFFFF << 32 | 0xFFFFFFFF, (uint64_t)0x995DC9BB << 32 | 0xDF1939FA}
#define CRC64_GO_ECMA           CRC64_XZ

#if CRC_HAS_128BIT_ALGO
#define CRC82_DARC              { 82, (uint128_t)0x00000000 << 96 | (uint128_t)0x0000308C << 64 | (uint128_t)0x01110114 << 32 | 0x01440411,\
                                      (uint128_t)0x00000000 << 96 | (uint128_t)0x00000000 << 64 | (uint128_t)0x00000000 << 32 | 0x00000000,\
                                      1, 1,\
                                      (uint128_t)0x00000000 << 96 | (uint128_t)0x00000000 << 64 | (uint128_t)0x00000000 << 32 | 0x00000000,\
                                      (uint128_t)0x00000000 << 96 | (uint128_t)0x00009EA8 << 64 | (uint128_t)0x3F625023 << 32 | 0x801FD612}
#endif
/* clang-format on */
#endif /* H_CRC_CATALOG */
