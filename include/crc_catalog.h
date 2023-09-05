#ifndef H_CRC_CATALOG
#define H_CRC_CATALOG

#include <stdbool.h>

#define CRC8_MAXIM ((Crc8BasedAlgo){8, 0x31, 0x00, true, true, 0x00, 0xA1, 0x00})
#define CRC16_ARC ((Crc16BasedAlgo){16, 0x8005, 0x0000, true, true, 0x0000, 0xBB3D, 0x0000})
#define CRC16_MODBUS ((Crc16BasedAlgo){16, 0x8005, 0xFFFF, true, true, 0x0000, 0x4B37, 0x0000})
#define CRC16_USB ((Crc16BasedAlgo){16, 0x8005, 0xFFFF, true, true, 0xFFFF, 0xB4C8, 0xB001})
#define CRC16_KERMIT ((Crc16BasedAlgo){16, 0x1021, 0x0000, true, true, 0x0000, 0x2189, 0x0000})
#define CRC16_XMODEM ((Crc16BasedAlgo){16, 0x1021, 0x0000, false, false, 0x0000, 0x31C3, 0x0000})
#define CRC32_BZIP2 ((Crc32BasedAlgo){32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0xFFFFFFFF, 0xFC891918, 0xC704DD7B})
#define CRC32_ISO_HDLC ((Crc32BasedAlgo){32, 0x04C11DB7, 0xFFFFFFFF, true, true, 0xFFFFFFFF, 0xCBF43926, 0xDEBB20E3})
#define CRC32_MPEG2 ((Crc32BasedAlgo){32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0x00000000, 0x0376E6E7, 0x00000000})

#endif // H_CRC_CATALOG
