#ifndef H_CRC
#define H_CRC

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

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
    int width;
    uint64_t poly;
    uint64_t init;
    int refin;
    int refout;
    uint64_t xorout;
    uint64_t check;
    uint64_t residue;
} Crc64BasedAlgo;

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

typedef struct {
    Crc64BasedAlgo algo;
    const uint64_t *table;
    uint64_t value;
} Crc64;

void crc8_init_static(Crc8 *crc, Crc8BasedAlgo *algo, uint8_t *table);
void crc16_init_static(Crc16 *crc, Crc16BasedAlgo *algo, uint16_t *table);
void crc32_init_static(Crc32 *crc, Crc32BasedAlgo *algo, uint32_t *table);
void crc64_init_static(Crc64 *crc, Crc64BasedAlgo *algo, uint64_t *table);
void crc8_init(Crc8 *crc, Crc8BasedAlgo *algo);
void crc16_init(Crc16 *crc, Crc16BasedAlgo *algo);
void crc32_init(Crc32 *crc, Crc32BasedAlgo *algo);
void crc64_init(Crc64 *crc, Crc64BasedAlgo *algo);
void crc8_destroy(Crc8 *crc);
void crc16_destroy(Crc16 *crc);
void crc32_destroy(Crc32 *crc);
void crc64_destroy(Crc64 *crc);

void crc8_update(Crc8 *crc, const void *bytes, size_t size);
void crc16_update(Crc16 *crc, const void *bytes, size_t size);
void crc32_update(Crc32 *crc, const void *bytes, size_t size);
void crc64_update(Crc64 *crc, const void *bytes, size_t size);
uint8_t crc8_finalize(Crc8 *crc);
uint16_t crc16_finalize(Crc16 *crc);
uint32_t crc32_finalize(Crc32 *crc);
uint64_t crc64_finalize(Crc64 *crc);
uint8_t crc8_checksum(Crc8 *crc, const void *bytes, size_t size);
uint16_t crc16_checksum(Crc16 *crc, const void *bytes, size_t size);
uint32_t crc32_checksum(Crc32 *crc, const void *bytes, size_t size);
uint64_t crc64_checksum(Crc64 *crc, const void *bytes, size_t size);

#ifdef __cplusplus
}
#endif

#if __STDC_VERSION__ >= 201112L // Generics C11 support

#define crc_init_static(crc, algo, table) _Generic((crc), \
    Crc8 *: crc8_init_static, \
    Crc16 *: crc16_init_static, \
    Crc32 *: crc32_init_static, \
    Crc64 *: crc64_init_static \
)(crc, algo, table)

#define crc_init(crc, algo) _Generic((crc), \
    Crc8 *: crc8_init, \
    Crc16 *: crc16_init, \
    Crc32 *: crc32_init, \
    Crc64 *: crc64_init \
)(crc, algo)

#define crc_destroy(crc) _Generic((crc), \
    Crc8 *: crc8_destroy, \
    Crc16 *: crc16_destroy, \
    Crc32 *: crc32_destroy, \
    Crc64 *: crc64_destroy \
)(crc)

#define crc_update(crc, bytes, size) _Generic((crc), \
    Crc8 *: crc8_update, \
    Crc16 *: crc16_update, \
    Crc32 *: crc32_update, \
    Crc64 *: crc64_update \
)(crc, bytes, size)

#define crc_finalize(crc) _Generic((crc), \
    Crc8 *: crc8_finalize, \
    Crc16 *: crc16_finalize, \
    Crc32 *: crc32_finalize, \
    Crc64 *: crc64_finalize \
)(crc)

#define crc_checksum(crc, bytes, size) _Generic((crc), \
    Crc8 *: crc8_checksum, \
    Crc16 *: crc16_checksum, \
    Crc32 *: crc32_checksum, \
    Crc64 *: crc64_checksum \
)(crc, bytes, size)

#endif // Generics C11 support

#endif // H_CRC
