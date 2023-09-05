#include "crc.h"
#include <stdio.h>
#include <stdlib.h>

static uint32_t rev(uint32_t x);
static uint8_t crc8(uint8_t poly, int refin, uint8_t init);
static uint16_t crc16(uint16_t poly, int refin, uint16_t init);
static uint32_t crc32(uint32_t poly, int refin, uint32_t init);
static void crc8_table_init(uint8_t *table, int width, uint8_t poly, int refin);
static void crc16_table_init(uint16_t *table, int width, uint16_t poly, int refin);
static void crc32_table_init(uint32_t *table, int width, uint32_t poly, int refin);
static uint8_t crc8_init_value(uint8_t init, int width, int refin);
static uint16_t crc16_init_value(uint16_t init, int width, int refin);
static uint32_t crc32_init_value(uint32_t init, int width, int refin);

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
}

void crc32_destroy(Crc32 *crc) {
    if(!crc || !crc->table) {
        return;
    }
    free((void *)crc->table);
}


void crc8_update(Crc8 *crc, const void *bytes, size_t size) {
    int i;

    if(!crc || !bytes) {
        return;
    }

    for(i = 0; i < size; i++) {
        crc->value = crc->table[crc->value ^ ((uint8_t *)bytes)[i]];
    }
}

void crc16_update(Crc16 *crc, const void *bytes, size_t size) {
    int i;

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
    int i;

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


static uint32_t rev(uint32_t x) {
    x = (x & 0x55555555) << 1 | (x >> 1) & 0x55555555;
    x = (x & 0x33333333) << 2 | (x >> 2) & 0x33333333;
    x = (x & 0x0F0F0F0F) << 4 | (x >> 4) & 0x0F0F0F0F;
    x = (x << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | (x >> 24);
    return x;
}

static uint8_t crc8(uint8_t poly, int refin, uint8_t init) {
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

static uint16_t crc16(uint16_t poly, int refin, uint16_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 8;
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> 7) & 1));
        }
    }

    return init;
}

static uint32_t crc32(uint32_t poly, int refin, uint32_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 24;
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> 7) & 1));
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

static uint8_t crc8_init_value(uint8_t init, int width, int refin) {
    if(refin) {
        return rev(init) >> (32 - width);
    } else {
        return init << 8 - width;
    }
}

static uint16_t crc16_init_value(uint16_t init, int width, int refin) {
    if(refin) {
        return rev(init) >> (32 - width);
    } else {
        return init << 16 - width;
    }
}

static uint32_t crc32_init_value(uint32_t init, int width, int refin) {
    if(refin) {
        return rev(init) >> (32 - width);
    } else {
        return init << 32 - width;
    }
}
