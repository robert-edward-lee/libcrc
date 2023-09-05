#ifndef H_CRC
#define H_CRC

#include <stddef.h>
#include <stdint.h>

typedef struct {
    int width;
    uint8_t poly;
    uint8_t init;
    int refin;
    int refout;
    uint8_t xorout;
    uint8_t check;
    uint8_t residue;
} Crc8BasedAlgo;

typedef struct {
    int width;
    uint16_t poly;
    uint16_t init;
    int refin;
    int refout;
    uint16_t xorout;
    uint16_t check;
    uint16_t residue;
} Crc16BasedAlgo;

typedef struct {
    int width;
    uint32_t poly;
    uint32_t init;
    int refin;
    int refout;
    uint32_t xorout;
    uint32_t check;
    uint32_t residue;
} Crc32BasedAlgo;

typedef struct {
    Crc8BasedAlgo algo;
    const uint8_t *table;
    uint8_t value;
} Crc8;

typedef struct {
    Crc16BasedAlgo algo;
    const uint16_t *table;
    uint16_t value;
} Crc16;

typedef struct {
    Crc32BasedAlgo algo;
    const uint32_t *table;
    uint32_t value;
} Crc32;


void crc8_init_static(Crc8 *crc, Crc8BasedAlgo *algo, uint8_t *table);
void crc16_init_static(Crc16 *crc, Crc16BasedAlgo *algo, uint16_t *table);
void crc32_init_static(Crc32 *crc, Crc32BasedAlgo *algo, uint32_t *table);
void crc8_init(Crc8 *crc, Crc8BasedAlgo *algo);
void crc16_init(Crc16 *crc, Crc16BasedAlgo *algo);
void crc32_init(Crc32 *crc, Crc32BasedAlgo *algo);
void crc8_destroy(Crc8 *crc);
void crc16_destroy(Crc16 *crc);
void crc32_destroy(Crc32 *crc);

void crc8_update(Crc8 *crc, const void *bytes, size_t size);
void crc16_update(Crc16 *crc, const void *bytes, size_t size);
void crc32_update(Crc32 *crc, const void *bytes, size_t size);
uint8_t crc8_finalize(Crc8 *crc);
uint16_t crc16_finalize(Crc16 *crc);
uint32_t crc32_finalize(Crc32 *crc);
uint8_t crc8_checksum(Crc8 *crc, const void *bytes, size_t size);
uint16_t crc16_checksum(Crc16 *crc, const void *bytes, size_t size);
uint32_t crc32_checksum(Crc32 *crc, const void *bytes, size_t size);

#endif // H_CRC
