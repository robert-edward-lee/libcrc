/**
    \file lib.c
    \brief Реализация библиотеки расчёта циклического избыточного кода
*/
#include "crc/lib.h"

#include <stdlib.h>

#include "rev.h"

/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc8_init_value
*/
static uint8_t crc8(uint8_t poly, int refin, uint8_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> (8 * sizeof(init) - 1)) & 1));
        }
    }

    return init;
}
/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc16_init_value
*/
static uint16_t crc16(uint16_t poly, int refin, uint16_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> (8 * sizeof(init) - 1)) & 1));
        }
    }

    return init;
}
/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc32_init_value
*/
static uint32_t crc32(uint32_t poly, int refin, uint32_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> (8 * sizeof(init) - 1)) & 1));
        }
    }

    return init;
}
/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc64_init_value
*/
static uint64_t crc64(uint64_t poly, int refin, uint64_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> (8 * sizeof(init) - 1)) & 1));
        }
    }

    return init;
}
/**
    \param[out] table Таблица для заполнения
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \brief Инициализация таблицы
*/
static void crc8_table_init(uint8_t *table, int width, uint8_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev8(poly);
        poly >>= 8 * sizeof(poly) - width;
    } else {
        poly <<= 8 * sizeof(poly) - width;
    }

    while(i--) {
        table[i] = crc8(poly, refin, i);
    }
}
/**
    \param[out] table Таблица для заполнения
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \brief Инициализация таблицы
*/
static void crc16_table_init(uint16_t *table, int width, uint16_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev16(poly);
        poly >>= 8 * sizeof(poly) - width;
    } else {
        poly <<= 8 * sizeof(poly) - width;
    }

    while(i--) {
        table[i] = crc16(poly, refin, i);
    }
}
/**
    \param[out] table Таблица для заполнения
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \brief Инициализация таблицы
*/
static void crc32_table_init(uint32_t *table, int width, uint32_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev32(poly);
        poly >>= 8 * sizeof(poly) - width;
    } else {
        poly <<= 8 * sizeof(poly) - width;
    }

    while(i--) {
        table[i] = crc32(poly, refin, i);
    }
}
/**
    \param[out] table Таблица для заполнения
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \brief Инициализация таблицы
*/
static void crc64_table_init(uint64_t *table, int width, uint64_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev64(poly);
        poly >>= 8 * sizeof(poly) - width;
    } else {
        poly <<= 8 * sizeof(poly) - width;
    }

    while(i--) {
        table[i] = crc64(poly, refin, i);
    }
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc8::value
    \brief Инициализация \ref Crc8::value
*/
static uint8_t crc8_init_value(uint8_t init, int width, int refin) {
    return refin ? rev8(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc16::value
    \brief Инициализация \ref Crc16::value
*/
static uint16_t crc16_init_value(uint16_t init, int width, int refin) {
    return refin ? rev16(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc32::value
    \brief Инициализация \ref Crc32::value
*/
static uint32_t crc32_init_value(uint32_t init, int width, int refin) {
    return refin ? rev32(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc64::value
    \brief Инициализация \ref Crc64::value
*/
static uint64_t crc64_init_value(uint64_t init, int width, int refin) {
    return refin ? rev64(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}

void crc8_init_static(Crc8 *crc, const Crc8BasedAlgo *algo, uint8_t *table) {
    if(!crc || !algo || !table) {
        return;
    }
    crc->algo = *algo;
    crc8_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc8_init_value(algo->init, algo->width, algo->refin);
}

void crc16_init_static(Crc16 *crc, const Crc16BasedAlgo *algo, uint16_t *table) {
    if(!crc || !algo || !table) {
        return;
    }
    crc->algo = *algo;
    crc16_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc16_init_value(algo->init, algo->width, algo->refin);
}

void crc32_init_static(Crc32 *crc, const Crc32BasedAlgo *algo, uint32_t *table) {
    if(!crc || !algo || !table) {
        return;
    }
    crc->algo = *algo;
    crc32_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc32_init_value(algo->init, algo->width, algo->refin);
}

void crc64_init_static(Crc64 *crc, const Crc64BasedAlgo *algo, uint64_t *table) {
    if(!crc || !algo || !table) {
        return;
    }
    crc->algo = *algo;
    crc64_table_init(table, algo->width, algo->poly, algo->refin);
    crc->table = table;
    crc->value = crc64_init_value(algo->init, algo->width, algo->refin);
}

void crc8_init(Crc8 *crc, const Crc8BasedAlgo *algo) {
    uint8_t *table;

    if(!crc || !algo) {
        return;
    }
    table = malloc(256 * sizeof(*table));
    if(!table) {
        return;
    }
    crc8_init_static(crc, algo, table);
}

void crc16_init(Crc16 *crc, const Crc16BasedAlgo *algo) {
    uint16_t *table;

    if(!crc || !algo) {
        return;
    }
    table = malloc(256 * sizeof(*table));
    if(!table) {
        return;
    }
    crc16_init_static(crc, algo, table);
}

void crc32_init(Crc32 *crc, const Crc32BasedAlgo *algo) {
    uint32_t *table;

    if(!crc || !algo) {
        return;
    }
    table = malloc(256 * sizeof(*table));
    if(!table) {
        return;
    }
    crc32_init_static(crc, algo, table);
}

void crc64_init(Crc64 *crc, const Crc64BasedAlgo *algo) {
    uint64_t *table;

    if(!crc || !algo) {
        return;
    }
    table = malloc(256 * sizeof(*table));
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
    crc->table = NULL;
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
            crc->value = crc->table[(crc->value & 0xFF) ^ ((uint8_t *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 8) ^ ((uint8_t *)bytes)[i]] ^ (crc->value << 8);
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
            crc->value = crc->table[(crc->value & 0xFF) ^ ((uint8_t *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 24) ^ ((uint8_t *)bytes)[i]] ^ (crc->value << 8);
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
            crc->value = crc->table[(crc->value & 0xFF) ^ ((uint8_t *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 56) ^ ((uint8_t *)bytes)[i]] ^ (crc->value << 8);
        }
    }
}

uint8_t crc8_finalize(Crc8 *crc) {
    uint8_t ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc8_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev8(ret);
    }
    if(!crc->algo.refout) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

uint16_t crc16_finalize(Crc16 *crc) {
    uint16_t ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc16_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev16(ret);
    }
    if(!crc->algo.refout) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

uint32_t crc32_finalize(Crc32 *crc) {
    uint32_t ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc32_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev32(ret);
    }
    if(!crc->algo.refout) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

uint64_t crc64_finalize(Crc64 *crc) {
    uint64_t ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc64_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev64(ret);
    }
    if(!crc->algo.refout) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
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

#ifdef __SIZEOF_INT128__
/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc128_init_value
*/
static __uint128_t crc128(__uint128_t poly, int refin, __uint128_t init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly & -(init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly & -((init >> (8 * sizeof(init) - 1)) & 1));
        }
    }

    return init;
}
/**
    \param[out] table Таблица для заполнения
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \brief Инициализация таблицы
*/
static void crc128_table_init(__uint128_t *table, int width, __uint128_t poly, int refin) {
    int i = 256;

    if(!table) {
        return;
    }

    if(refin) {
        poly = rev128(poly);
        poly >>= 8 * sizeof(poly) - width;
    } else {
        poly <<= 8 * sizeof(poly) - width;
    }

    while(i--) {
        table[i] = crc128(poly, refin, i);
    }
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc128::value
    \brief Инициализация \ref Crc128::value
*/
static __uint128_t crc128_init_value(__uint128_t init, int width, int refin) {
    return refin ? rev128(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}

void crc128_init_static(Crc128 *crc, const Crc128BasedAlgo *algo, __uint128_t *table) {
    if(!crc || !algo || !table) {
        return;
    }
    crc->algo = *algo;
    crc128_table_init(table, crc->algo.width, crc->algo.poly, crc->algo.refin);
    crc->table = table;
    crc->value = crc128_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);
}

void crc128_init(Crc128 *crc, const Crc128BasedAlgo *algo) {
    __uint128_t *table;

    if(!crc || !algo) {
        return;
    }
    table = malloc(256 * sizeof(*table));
    if(!table) {
        return;
    }
    crc128_init_static(crc, algo, table);
}

void crc128_destroy(Crc128 *crc) {
    if(!crc || !crc->table) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
}

void crc128_update(Crc128 *crc, const void *bytes, size_t size) {
    unsigned i;

    if(!crc || !bytes) {
        return;
    }
    if(crc->algo.refin) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value & 0xFF) ^ ((uint8_t *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 120) ^ ((uint8_t *)bytes)[i]] ^ (crc->value << 8);
        }
    }
}

__uint128_t crc128_finalize(Crc128 *crc) {
    __uint128_t ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc128_init_value(crc->algo.init, crc->algo.width, crc->algo.refin);

    if(crc->algo.refin ^ crc->algo.refout) {
        ret = rev128(ret);
    }
    if(!crc->algo.refout) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

__uint128_t crc128_checksum(Crc128 *crc, const void *bytes, size_t size) {
    crc128_update(crc, bytes, size);
    return crc128_finalize(crc);
}
#endif /* __SIZEOF_INT128__ */
