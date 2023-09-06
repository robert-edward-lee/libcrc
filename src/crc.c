#include "crc.h"

#include <stdlib.h>

static inline uint32_t rev(uint32_t x);
static inline uint64_t rev64(uint64_t x);
static inline uint8_t crc8(uint8_t poly, int refin, uint8_t init);
static inline uint16_t crc16(uint16_t poly, int refin, uint16_t init);
static inline uint32_t crc32(uint32_t poly, int refin, uint32_t init);
static inline uint64_t crc64(uint64_t poly, int refin, uint64_t init);
static void crc8_table_init(uint8_t *table, int width, uint8_t poly, int refin);
static void crc16_table_init(uint16_t *table, int width, uint16_t poly, int refin);
static void crc32_table_init(uint32_t *table, int width, uint32_t poly, int refin);
static void crc64_table_init(uint64_t *table, int width, uint64_t poly, int refin);
static inline uint8_t crc8_init_value(uint8_t init, int width, int refin);
static inline uint16_t crc16_init_value(uint16_t init, int width, int refin);
static inline uint32_t crc32_init_value(uint32_t init, int width, int refin);
static inline uint64_t crc64_init_value(uint64_t init, int width, int refin);

void crc8_init_static(Crc8 *crc, Crc8BasedAlgo *algo, uint8_t *table) {
    if(!crc || !algo || !table) {
        return;
    }

    crc->algo = *algo;
    crc8_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc8_init_value(algo->init, algo->width, algo->refin);
}

void crc16_init_static(Crc16 *crc, Crc16BasedAlgo *algo, uint16_t *table) {
    if(!crc || !algo || !table) {
        return;
    }

    crc->algo = *algo;
    crc16_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc16_init_value(algo->init, algo->width, algo->refin);
}

void crc32_init_static(Crc32 *crc, Crc32BasedAlgo *algo, uint32_t *table) {
    if(!crc || !algo || !table) {
        return;
    }

    crc->algo = *algo;
    crc32_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc32_init_value(algo->init, algo->width, algo->refin);
}

void crc64_init_static(Crc64 *crc, Crc64BasedAlgo *algo, uint64_t *table) {
    if(!crc || !algo || !table) {
        return;
    }

    crc->algo = *algo;
    crc64_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc64_init_value(algo->init, algo->width, algo->refin);
}

void crc8_init(Crc8 *crc, Crc8BasedAlgo *algo) {
    uint8_t *table;

    if(!crc || !algo) {
        return;
    }

    table = malloc(256 * sizeof(uint8_t));
    if(!table) {
        return;
    }
    crc8_init_static(crc, algo, table);
}

void crc16_init(Crc16 *crc, Crc16BasedAlgo *algo) {
    uint16_t *table;

    if(!crc || !algo) {
        return;
    }

    table = malloc(256 * sizeof(uint16_t));
    if(!table) {
        return;
    }
    crc16_init_static(crc, algo, table);
}

void crc32_init(Crc32 *crc, Crc32BasedAlgo *algo) {
    uint32_t *table;

    if(!crc || !algo) {
        return;
    }

    table = malloc(256 * sizeof(uint32_t));
    if(!table) {
        return;
    }
    crc32_init_static(crc, algo, table);
}

void crc64_init(Crc64 *crc, Crc64BasedAlgo *algo) {
    uint64_t *table;

    if(!crc || !algo) {
        return;
    }

    table = malloc(256 * sizeof(uint64_t));
    if(!table) {
        return;
    }
    crc64_init_static(crc, algo, table);
}

void crc8_destroy(Crc8 *crc) {
    if(!crc || !crc->table) {
        return;
    }
    free((void *)crc->table);
}

void crc16_destroy(Crc16 *crc) {
    if(!crc || !crc->table) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
}

void crc32_destroy(Crc32 *crc) {
    if(!crc || !crc->table) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
}

void crc64_destroy(Crc64 *crc) {
    if(!crc || !crc->table) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
}


void crc8_update(Crc8 *crc, const void *bytes, size_t size) {
    unsigned i;

    if(!crc || !bytes) {
        return;
    }

    for(i = 0; i < size; i++) {
        crc->value = crc->table[crc->value ^ ((uint8_t *)bytes)[i]];
    }
}

void crc16_update(Crc16 *crc, const void *bytes, size_t size) {
    unsigned i;

    if(!crc || !bytes) {
        return;
    }

    if(crc->algo.refin) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value ^ ((uint8_t *)bytes)[i]) & 0xFF] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[((crc->value >> 8) ^ ((uint8_t *)bytes)[i]) & 0xFF] ^ (crc->value << 8);
        }
    }
}

void crc32_update(Crc32 *crc, const void *bytes, size_t size) {
    unsigned i;

    if(!crc || !bytes) {
        return;
    }

    if(crc->algo.refin) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value ^ ((uint8_t *)bytes)[i]) & 0xFF] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[((crc->value >> 24) ^ ((uint8_t *)bytes)[i]) & 0xFF] ^ (crc->value << 8);
        }
    }
}

void crc64_update(Crc64 *crc, const void *bytes, size_t size) {
    unsigned i;

    if(!crc || !bytes) {
        return;
    }

    if(crc->algo.refin) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value ^ ((uint8_t *)bytes)[i]) & 0xFF] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[((crc->value >> 56) ^ ((uint8_t *)bytes)[i]) & 0xFF] ^ (crc->value << 8);
        }
    }
}

uint8_t crc8_finalize(Crc8 *crc) {
    uint8_t ret = crc->value;

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev(ret) >> 24;
    }

    if(!crc->algo.refout) {
        ret >>= 8 - crc->algo.width;
    }
    crc->value = crc8_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);
    return ret ^ crc->algo.xorout;
}

uint16_t crc16_finalize(Crc16 *crc) {
    uint16_t ret = crc->value;

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev(ret) >> 16;
    }

    if(!crc->algo.refout) {
        ret >>= 16 - crc->algo.width;
    }
    crc->value = crc16_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);
    return ret ^ crc->algo.xorout;
}

uint32_t crc32_finalize(Crc32 *crc) {
    uint32_t ret = crc->value;

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev(ret);
    }

    if(!crc->algo.refout) {
        ret >>= 32 - crc->algo.width;
    }
    crc->value = crc32_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);
    return ret ^ crc->algo.xorout;
}

uint64_t crc64_finalize(Crc64 *crc) {
    uint64_t ret = crc->value;

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev64(ret);
    }

    if(!crc->algo.refout) {
        ret >>= 64 - crc->algo.width;
    }
    crc->value = crc64_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);
    return ret ^ crc->algo.xorout;
}

uint8_t crc8_checksum(Crc8 *crc, const void *bytes, size_t size) {
    crc8_update(crc, bytes, size);
    return crc8_finalize(crc);
}

uint16_t crc16_checksum(Crc16 *crc, const void *bytes, size_t size) {
    crc16_update(crc, bytes, size);
    return crc16_finalize(crc);
}

uint32_t crc32_checksum(Crc32 *crc, const void *bytes, size_t size) {
    crc32_update(crc, bytes, size);
    return crc32_finalize(crc);
}

uint64_t crc64_checksum(Crc64 *crc, const void *bytes, size_t size) {
    crc64_update(crc, bytes, size);
    return crc64_finalize(crc);
}


static inline uint32_t rev(uint32_t x) {
    x = ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
    x = ((x & 0x33333333) << 2) | ((x >> 2) & 0x33333333);
    x = ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
    return x;
}

static inline uint64_t rev64(uint64_t x) {
   uint64_t t;

   x = (x << 31) | (x >> 33); // shlr(x, 31).
   t = (x ^ (x >> 20)) & 0x00000FFF800007FF;
   x = (t | (t << 20)) ^ x;
   t = (x ^ (x >> 8)) & 0x00F8000F80700807;
   x = (t | (t << 8)) ^ x;
   t = (x ^ (x >> 4)) & 0x0808708080807008;
   x = (t | (t << 4)) ^ x;
   t = (x ^ (x >> 2)) & 0x1111111111111111;
   x = (t | (t << 2)) ^ x;
   return x;
}

static inline uint8_t crc8(uint8_t poly, int refin, uint8_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> 7) & 1));
        }
    }

    return init;
}

static inline uint16_t crc16(uint16_t poly, int refin, uint16_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 8;
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> 15) & 1));
        }
    }

    return init;
}

static inline uint32_t crc32(uint32_t poly, int refin, uint32_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 24;
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> 31) & 1));
        }
    }

    return init;
}

static inline uint64_t crc64(uint64_t poly, int refin, uint64_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 56;
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> 63) & 1));
        }
    }

    return init;
}

static void crc8_table_init(uint8_t *table, int width, uint8_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev(poly) >> 24;
        poly >>= 8 - width;
    } else {
        poly <<= 8 - width;
    }

    while(i--) {
        table[i] = crc8(poly, refin, i);
    }
}

static void crc16_table_init(uint16_t *table, int width, uint16_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev(poly) >> 16;
        poly >>= 16 - width;
    } else {
        poly <<= 16 - width;
    }

    while(i--) {
        table[i] = crc16(poly, refin, i);
    }
}

static void crc32_table_init(uint32_t *table, int width, uint32_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev(poly);
        poly >>= 32 - width;
    } else {
        poly <<= 32 - width;
    }

    while(i--) {
        table[i] = crc32(poly, refin, i);
    }
}

static void crc64_table_init(uint64_t *table, int width, uint64_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev64(poly);
        poly >>= 64 - width;
    } else {
        poly <<= 64 - width;
    }

    while(i--) {
        table[i] = crc64(poly, refin, i);
    }
}

static inline uint8_t crc8_init_value(uint8_t init, int width, int refin) {
    return refin ? (uint8_t)(rev(init) >> (32 - width)) : init << (8 - width);
}

static inline uint16_t crc16_init_value(uint16_t init, int width, int refin) {
    return refin ? (uint16_t)(rev(init) >> (32 - width)) : init << (16 - width);
}

static inline uint32_t crc32_init_value(uint32_t init, int width, int refin) {
    return refin ? rev(init) >> (32 - width) : init << (32 - width);
}

static inline uint64_t crc64_init_value(uint64_t init, int width, int refin) {
    return refin ? rev64(init) >> (64 - width) : init << (64 - width);
}
