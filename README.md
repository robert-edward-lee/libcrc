## Библиотека расчёта циклического избыточного кода

### Требования
Стандарт языка **C** не ниже c99/gnu99

### Спецификации алгоритмов
| Name                    | Width | Poly               | Init               | RefIn | RefOut | XorOut             | Check              | Residue            |
| ----------------------- | ----- | ------------------ | ------------------ | ----- | ------ | ------------------ | ------------------ | ------------------ |
| CRC3_GSM                | 3     | 0x3                | 0x0                | false | false  | 0x7                | 0x4                | 0x2                |
| CRC3_ROHC               | 3     | 0x3                | 0x7                | true  | true   | 0x0                | 0x6                | 0x0                |
| CRC4_G_704              | 4     | 0x3                | 0x0                | true  | true   | 0x0                | 0x7                | 0x0                |
| CRC4_INTERLAKEN         | 4     | 0x3                | 0xF                | false | false  | 0xF                | 0xB                | 0x2                |
| CRC5_EPC_C1G2           | 5     | 0x09               | 0x09               | false | false  | 0x00               | 0x00               | 0x00               |
| CRC5_G_704              | 5     | 0x15               | 0x00               | true  | true   | 0x00               | 0x07               | 0x00               |
| CRC5_USB                | 5     | 0x05               | 0x1F               | true  | true   | 0x1F               | 0x19               | 0x06               |
| CRC6_CDMA2000_A         | 6     | 0x27               | 0x3F               | false | false  | 0x00               | 0x0D               | 0x00               |
| CRC6_CDMA2000_B         | 6     | 0x07               | 0x3F               | false | false  | 0x00               | 0x3B               | 0x00               |
| CRC6_DARC               | 6     | 0x19               | 0x00               | true  | true   | 0x00               | 0x26               | 0x00               |
| CRC6_GSM                | 6     | 0x2F               | 0x00               | false | false  | 0x3F               | 0x13               | 0x3A               |
| CRC6_G_704              | 6     | 0x03               | 0x00               | true  | true   | 0x00               | 0x06               | 0x00               |
| CRC7_MMC                | 7     | 0x09               | 0x00               | false | false  | 0x00               | 0x75               | 0x00               |
| CRC7_ROHC               | 7     | 0x4F               | 0x7F               | true  | true   | 0x00               | 0x53               | 0x00               |
| CRC7_UMTS               | 7     | 0x45               | 0x00               | false | false  | 0x00               | 0x61               | 0x00               |
| CRC8_AUTOSAR            | 8     | 0x2F               | 0xFF               | false | false  | 0xFF               | 0xDF               | 0x42               |
| CRC8_BLUETOOTH          | 8     | 0xA7               | 0x00               | true  | true   | 0x00               | 0x26               | 0x00               |
| CRC8_CDMA2000           | 8     | 0x9B               | 0xFF               | false | false  | 0x00               | 0xDA               | 0x00               |
| CRC8_DARC               | 8     | 0x39               | 0x00               | true  | true   | 0x00               | 0x15               | 0x00               |
| CRC8_DVB_S2             | 8     | 0xD5               | 0x00               | false | false  | 0x00               | 0xBC               | 0x00               |
| CRC8_GSM_A              | 8     | 0x1D               | 0x00               | false | false  | 0x00               | 0x37               | 0x00               |
| CRC8_GSM_B              | 8     | 0x49               | 0x00               | false | false  | 0xFF               | 0x94               | 0x53               |
| CRC8_HITAG              | 8     | 0x1D               | 0xFF               | false | false  | 0x00               | 0xB4               | 0x00               |
| CRC8_I_432_1            | 8     | 0x07               | 0x00               | false | false  | 0x55               | 0xA1               | 0xAC               |
| CRC8_I_CODE             | 8     | 0x1D               | 0xFD               | false | false  | 0x00               | 0x7E               | 0x00               |
| CRC8_LTE                | 8     | 0x9B               | 0x00               | false | false  | 0x00               | 0xEA               | 0x00               |
| CRC8_MAXIM              | 8     | 0x31               | 0x00               | true  | true   | 0x00               | 0xA1               | 0x00               |
| CRC8_MIFARE_MAD         | 8     | 0x1D               | 0xC7               | false | false  | 0x00               | 0x99               | 0x00               |
| CRC8_NRSC_5             | 8     | 0x31               | 0xFF               | false | false  | 0x00               | 0xF7               | 0x00               |
| CRC8_OPENSAFETY         | 8     | 0x2F               | 0x00               | false | false  | 0x00               | 0x3E               | 0x00               |
| CRC8_ROHC               | 8     | 0x07               | 0xFF               | true  | true   | 0x00               | 0xD0               | 0x00               |
| CRC8_SAE_J1850          | 8     | 0x1D               | 0xFF               | false | false  | 0xFF               | 0x4B               | 0xC4               |
| CRC8_SMBUS              | 8     | 0x07               | 0x00               | false | false  | 0x00               | 0xF4               | 0x00               |
| CRC8_TECH_3250          | 8     | 0x1D               | 0xFF               | true  | true   | 0x00               | 0x97               | 0x00               |
| CRC8_WCDMA              | 8     | 0x9B               | 0x00               | true  | true   | 0x00               | 0x25               | 0x00               |
| CRC10_ATM               | 10    | 0x233              | 0x000              | false | false  | 0x000              | 0x199              | 0x000              |
| CRC10_CDMA2000          | 10    | 0x3D9              | 0x3FF              | false | false  | 0x000              | 0x233              | 0x000              |
| CRC10_GSM               | 10    | 0x175              | 0x000              | false | false  | 0x3FF              | 0x12A              | 0x0C6              |
| CRC11_FLEXRAY           | 11    | 0x385              | 0x01A              | false | false  | 0x000              | 0x5A3              | 0x000              |
| CRC11_UMTS              | 11    | 0x307              | 0x000              | false | false  | 0x000              | 0x061              | 0x000              |
| CRC12_CDMA2000          | 12    | 0xF13              | 0xFFF              | false | false  | 0x000              | 0xD4D              | 0x000              |
| CRC12_DECT              | 12    | 0x80F              | 0x000              | false | false  | 0x000              | 0xF5B              | 0x000              |
| CRC12_GSM               | 12    | 0xD31              | 0x000              | false | false  | 0xFFF              | 0xB34              | 0x178              |
| CRC12_UMTS              | 12    | 0x80F              | 0x000              | false | true   | 0x000              | 0xDAF              | 0x000              |
| CRC13_BBC               | 13    | 0x1CF5             | 0x0000             | false | false  | 0x0000             | 0x04FA             | 0x0000             |
| CRC14_DARC              | 14    | 0x0805             | 0x0000             | true  | true   | 0x0000             | 0x082D             | 0x0000             |
| CRC14_GSM               | 14    | 0x202D             | 0x0000             | false | false  | 0x3FFF             | 0x30AE             | 0x031E             |
| CRC15_CAN               | 15    | 0x4599             | 0x0000             | false | false  | 0x0000             | 0x059E             | 0x0000             |
| CRC15_MPT1327           | 15    | 0x6815             | 0x0000             | false | false  | 0x0001             | 0x2566             | 0x6815             |
| CRC16_ARC               | 16    | 0x8005             | 0x0000             | true  | true   | 0x0000             | 0xBB3D             | 0x0000             |
| CRC16_CDMA2000          | 16    | 0xC867             | 0xFFFF             | false | false  | 0x0000             | 0x4C06             | 0x0000             |
| CRC16_CMS               | 16    | 0x8005             | 0xFFFF             | false | false  | 0x0000             | 0xAEE7             | 0x0000             |
| CRC16_DDS_110           | 16    | 0x8005             | 0x800D             | false | false  | 0x0000             | 0x9ECF             | 0x0000             |
| CRC16_DECT_R            | 16    | 0x0589             | 0x0000             | false | false  | 0x0001             | 0x007E             | 0x0589             |
| CRC16_DECT_X            | 16    | 0x0589             | 0x0000             | false | false  | 0x0000             | 0x007F             | 0x0000             |
| CRC16_DNP               | 16    | 0x3D65             | 0x0000             | true  | true   | 0xFFFF             | 0xEA82             | 0x66C5             |
| CRC16_EN_13757          | 16    | 0x3D65             | 0x0000             | false | false  | 0xFFFF             | 0xC2B7             | 0xA366             |
| CRC16_GENIBUS           | 16    | 0x1021             | 0xFFFF             | false | false  | 0xFFFF             | 0xD64E             | 0x1D0F             |
| CRC16_GSM               | 16    | 0x1021             | 0x0000             | false | false  | 0xFFFF             | 0xCE3C             | 0x1D0F             |
| CRC16_IBM_3740          | 16    | 0x1021             | 0xFFFF             | false | false  | 0x0000             | 0x29B1             | 0x0000             |
| CRC16_IBM_SDLC          | 16    | 0x1021             | 0xFFFF             | true  | true   | 0xFFFF             | 0x906E             | 0xF0B8             |
| CRC16_ISO_IEC_14443_3_A | 16    | 0x1021             | 0xC6C6             | true  | true   | 0x0000             | 0xBF05             | 0x0000             |
| CRC16_KERMIT            | 16    | 0x1021             | 0x0000             | true  | true   | 0x0000             | 0x2189             | 0x0000             |
| CRC16_LJ1200            | 16    | 0x6F63             | 0x0000             | false | false  | 0x0000             | 0xBDF4             | 0x0000             |
| CRC16_M17               | 16    | 0x5935             | 0xFFFF             | false | false  | 0x0000             | 0x772B             | 0x0000             |
| CRC16_MAXIM_DOW         | 16    | 0x8005             | 0x0000             | true  | true   | 0xFFFF             | 0x44C2             | 0xB001             |
| CRC16_MCRF4XX           | 16    | 0x1021             | 0xFFFF             | true  | true   | 0x0000             | 0x6F91             | 0x0000             |
| CRC16_MODBUS            | 16    | 0x8005             | 0xFFFF             | true  | true   | 0x0000             | 0x4B37             | 0x0000             |
| CRC16_NRSC_5            | 16    | 0x080B             | 0xFFFF             | true  | true   | 0x0000             | 0xA066             | 0x0000             |
| CRC16_OPENSAFETY_A      | 16    | 0x5935             | 0x0000             | false | false  | 0x0000             | 0x5D38             | 0x0000             |
| CRC16_OPENSAFETY_B      | 16    | 0x755B             | 0x0000             | false | false  | 0x0000             | 0x20FE             | 0x0000             |
| CRC16_PROFIBUS          | 16    | 0x1DCF             | 0xFFFF             | false | false  | 0xFFFF             | 0xA819             | 0xE394             |
| CRC16_RIELLO            | 16    | 0x1021             | 0xB2AA             | true  | true   | 0x0000             | 0x63D0             | 0x0000             |
| CRC16_SPI_FUJITSU       | 16    | 0x1021             | 0x1D0F             | false | false  | 0x0000             | 0xE5CC             | 0x0000             |
| CRC16_T10_DIF           | 16    | 0x8BB7             | 0x0000             | false | false  | 0x0000             | 0xD0DB             | 0x0000             |
| CRC16_TELEDISK          | 16    | 0xA097             | 0x0000             | false | false  | 0x0000             | 0x0FB3             | 0x0000             |
| CRC16_TMS37157          | 16    | 0x1021             | 0x89EC             | true  | true   | 0x0000             | 0x26B1             | 0x0000             |
| CRC16_UMTS              | 16    | 0x8005             | 0x0000             | false | false  | 0x0000             | 0xFEE8             | 0x0000             |
| CRC16_USB               | 16    | 0x8005             | 0xFFFF             | true  | true   | 0xFFFF             | 0xB4C8             | 0xB001             |
| CRC16_XMODEM            | 16    | 0x1021             | 0x0000             | false | false  | 0x0000             | 0x31C3             | 0x0000             |
| CRC17_CAN_FD            | 17    | 0x1685B            | 0x00000            | false | false  | 0x00000            | 0x04F03            | 0x00000            |
| CRC21_CAN_FD            | 21    | 0x102899           | 0x000000           | false | false  | 0x000000           | 0x0ED841           | 0x000000           |
| CRC24_BLE               | 24    | 0x00065B           | 0x555555           | true  | true   | 0x000000           | 0xC25A56           | 0x000000           |
| CRC24_FLEXRAY_A         | 24    | 0x5D6DCB           | 0xFEDCBA           | false | false  | 0x000000           | 0x7979BD           | 0x000000           |
| CRC24_FLEXRAY_B         | 24    | 0x5D6DCB           | 0xABCDEF           | false | false  | 0x000000           | 0x1F23B8           | 0x000000           |
| CRC24_INTERLAKEN        | 24    | 0x328B63           | 0xFFFFFF           | false | false  | 0xFFFFFF           | 0xB4F3E6           | 0x144E63           |
| CRC24_LTE_A             | 24    | 0x864CFB           | 0x000000           | false | false  | 0x000000           | 0xCDE703           | 0x000000           |
| CRC24_LTE_B             | 24    | 0x800063           | 0x000000           | false | false  | 0x000000           | 0x23EF52           | 0x000000           |
| CRC24_OPENPGP           | 24    | 0x864CFB           | 0xB704CE           | false | false  | 0x000000           | 0x21CF02           | 0x000000           |
| CRC24_OS_9              | 24    | 0x800063           | 0xFFFFFF           | false | false  | 0xFFFFFF           | 0x200FA5           | 0x800FE3           |
| CRC30_CDMA              | 30    | 0x2030B9C7         | 0x3FFFFFFF         | false | false  | 0x3FFFFFFF         | 0x04C34ABF         | 0x34EFA55A         |
| CRC31_PHILIPS           | 31    | 0x04C11DB7         | 0x7FFFFFFF         | false | false  | 0x7FFFFFFF         | 0x0CE9E46C         | 0x4EAF26F1         |
| CRC32_AIXM              | 32    | 0x814141AB         | 0x00000000         | false | false  | 0x00000000         | 0x3010BF7F         | 0x00000000         |
| CRC32_AUTOSAR           | 32    | 0xF4ACFB13         | 0xFFFFFFFF         | true  | true   | 0xFFFFFFFF         | 0x1697D06A         | 0x904CDDBF         |
| CRC32_BASE91_D          | 32    | 0xA833982B         | 0xFFFFFFFF         | true  | true   | 0xFFFFFFFF         | 0x87315576         | 0x45270551         |
| CRC32_BZIP2             | 32    | 0x04C11DB7         | 0xFFFFFFFF         | false | false  | 0xFFFFFFFF         | 0xFC891918         | 0xC704DD7B         |
| CRC32_CD_ROM_EDC        | 32    | 0x8001801B         | 0x00000000         | true  | true   | 0x00000000         | 0x6EC2EDC4         | 0x00000000         |
| CRC32_CKSUM             | 32    | 0x04C11DB7         | 0x00000000         | false | false  | 0xFFFFFFFF         | 0x765E7680         | 0xC704DD7B         |
| CRC32_ISCSI             | 32    | 0x1EDC6F41         | 0xFFFFFFFF         | true  | true   | 0xFFFFFFFF         | 0xE3069283         | 0xB798B438         |
| CRC32_ISO_HDLC          | 32    | 0x04C11DB7         | 0xFFFFFFFF         | true  | true   | 0xFFFFFFFF         | 0xCBF43926         | 0xDEBB20E3         |
| CRC32_JAMCRC            | 32    | 0x04C11DB7         | 0xFFFFFFFF         | true  | true   | 0x00000000         | 0x340BC6D9         | 0x00000000         |
| CRC32_MEF               | 32    | 0x741B8CD7         | 0xFFFFFFFF         | true  | true   | 0x00000000         | 0xD2C22F51         | 0x00000000         |
| CRC32_MPEG2             | 32    | 0x04C11DB7         | 0xFFFFFFFF         | false | false  | 0x00000000         | 0x0376E6E7         | 0x00000000         |
| CRC32_XFER              | 32    | 0x000000AF         | 0x00000000         | false | false  | 0x00000000         | 0xBD0BE338         | 0x00000000         |
| CRC40_GSM               | 40    | 0x0004820009       | 0x0000000000       | false | false  | 0xFFFFFFFFFF       | 0xD4164FC646       | 0xC4FF8071FF       |
| CRC64_ECMA_182          | 64    | 0x42F0E1EBA9EA3693 | 0x0000000000000000 | false | false  | 0x0000000000000000 | 0x6C40DF5F0B497347 | 0x0000000000000000 |
| CRC64_GO_ISO            | 64    | 0x000000000000001B | 0xFFFFFFFFFFFFFFFF | true  | true   | 0xFFFFFFFFFFFFFFFF | 0xB90956C775A41001 | 0x5300000000000000 |
| CRC64_MS                | 64    | 0x259C84CBA6426349 | 0xFFFFFFFFFFFFFFFF | true  | true   | 0x0000000000000000 | 0x75D4B74F024ECEEA | 0x0000000000000000 |
| CRC64_REDIS             | 64    | 0xAD93D23594C935A9 | 0x0000000000000000 | true  | true   | 0x0000000000000000 | 0xE9C6D914C4B8D9CA | 0x0000000000000000 |
| CRC64_WE                | 64    | 0x42F0E1EBA9EA3693 | 0xFFFFFFFFFFFFFFFF | false | false  | 0xFFFFFFFFFFFFFFFF | 0x62EC59E3F1A4F00A | 0xFCACBEBD5931A992 |
| CRC64_XZ                | 64    | 0x42F0E1EBA9EA3693 | 0xFFFFFFFFFFFFFFFF | true  | true   | 0xFFFFFFFFFFFFFFFF | 0x995DC9BBDF1939FA | 0x49958C9ABD7D353F |

### Пример использования
#### С динамическим выделением памяти
```c
#include "crc.h"
#include "crc_catalog.h"

char data[] = "123456789";
uint16_t value;
Crc16 crc;

// если стандарт языка не поддерживает C11
crc16_init(&crc, &CRC16_ARC);
value = crc16_checksum(&crc, data, sizeof(data) - 1);
crc16_destroy(&crc);
// если стандарт языка поддерживает C11
crc_init(&crc, &CRC16_ARC);
value = crc_checksum(&crc, data, sizeof(data) - 1);
crc_destroy(&crc);
```

#### Со статическим выделением памяти
```c
#include "crc.h"
#include "crc_catalog.h"

char data[] = "123456789";
uint16_t table[256];
uint16_t value;
Crc16 crc;

// если стандарт языка не поддерживает C11
crc16_init_static(&crc, &CRC16_ARC, table);
value = crc16_checksum(&crc, data, sizeof(data) - 1);
// если стандарт языка поддерживает C11
crc_init(&crc, &CRC16_ARC, table);
value = crc_checksum(&crc, data, sizeof(data) - 1);
```

#### Итеративного вычисления
```c
#include "crc.h"
#include "crc_catalog.h"

char data[] = "123456789";
uint16_t value;
Crc16 crc;

// если стандарт языка не поддерживает C11
crc16_init(&crc, &CRC16_ARC);
for(int i = 0; i < sizeof(data); i++) {
    crc16_update(&crc, &data[i], 1);
}
value = crc16_finalize(&crc);
crc16_destroy(&crc);
// если стандарт языка поддерживает C11
crc_init(&crc, &CRC16_ARC);
for(int i = 0; i < sizeof(data); i++) {
    crc_update(&crc, &data[i], 1);
}
value = crc_finalize(&crc);
crc_destroy(&crc);
```
