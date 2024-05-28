/**
    \file lib.c
    \brief Реализация библиотеки расчёта циклического избыточного кода
*/
#if defined(CRC_USE_HEAP)
#include <stdlib.h>
#endif

#include "crc/internal/defines.h"
#include "crc/internal/types.h"
#include "crc/lib.h"
#include "rev.h"

#define CRC_FLAG_REFIN (1 << 0)
#define CRC_REFIN_TO_FLAGS(refin) ((refin) << 0)
#define CRC_FLAGS_TO_REFIN(flags) (((flags) >> 0) & 1)

#define CRC_FLAG_REFOUT (1 << 1)
#define CRC_REFOUT_TO_FLAGS(refout) ((refout) << 1)
#define CRC_FLAGS_TO_REFOUT(flags) (((flags) >> 1) & 1)

#define CRC_FLAG_DYN_ALLOC (1 << 2)
#define CRC_DYN_ALLOC_TO_FLAGS(dyn_alloc) ((dyn_alloc) << 2)
#define CRC_FLAGS_TO_DYN_ALLOC(flags) (((flags) >> 2) & 1)

/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc8_init_value
*/
static CRC_INLINE crc_u8 crc8(crc_u8 poly, crc_bool refin, crc_u8 init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly * (init & 1));
        }
    } else {
        while(i--) {
            init = (init << 1) ^ (poly * ((init >> (8 * sizeof(init) - 1)) & 1));
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
static CRC_INLINE crc_u16 crc16(crc_u16 poly, crc_bool refin, crc_u16 init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly * (init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly * ((init >> (8 * sizeof(init) - 1)) & 1));
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
static CRC_INLINE crc_u32 crc32(crc_u32 poly, crc_bool refin, crc_u32 init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly * (init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly * ((init >> (8 * sizeof(init) - 1)) & 1));
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
static CRC_INLINE crc_u64 crc64(crc_u64 poly, crc_bool refin, crc_u64 init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly * (init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly * ((init >> (8 * sizeof(init) - 1)) & 1));
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
static void crc8_table_init(crc_u8 *table, crc_u8 width, crc_u8 poly, crc_bool refin) {
    int i = 256;

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
static void crc16_table_init(crc_u16 *table, crc_u8 width, crc_u16 poly, crc_bool refin) {
    int i = 256;

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
static void crc32_table_init(crc_u32 *table, crc_u8 width, crc_u32 poly, crc_bool refin) {
    int i = 256;

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
static void crc64_table_init(crc_u64 *table, crc_u8 width, crc_u64 poly, crc_bool refin) {
    int i = 256;

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
static CRC_INLINE crc_u8 crc8_init_value(crc_u8 init, crc_u8 width, crc_bool refin) {
    return refin ? rev8(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc16::value
    \brief Инициализация \ref Crc16::value
*/
static CRC_INLINE crc_u16 crc16_init_value(crc_u16 init, crc_u8 width, crc_bool refin) {
    return refin ? rev16(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc32::value
    \brief Инициализация \ref Crc32::value
*/
static CRC_INLINE crc_u32 crc32_init_value(crc_u32 init, crc_u8 width, crc_bool refin) {
    return refin ? rev32(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}
/**
    \param init Стартовые данные
    \param width Степень порождающего многочлена
    \param refin Начало и направление вычислений
    \return Значение контрольной суммы с которой будет начинаться вычисление \ref Crc64::value
    \brief Инициализация \ref Crc64::value
*/
static CRC_INLINE crc_u64 crc64_init_value(crc_u64 init, crc_u8 width, crc_bool refin) {
    return refin ? rev64(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}

static CRC_INLINE void crc8_init_impl(Crc8 *crc,
                                      crc_u8 width,
                                      crc_u8 poly,
                                      crc_u8 init,
                                      crc_bool refin,
                                      crc_bool refout,
                                      crc_u8 xorout,
                                      crc_u8 *table) {
    crc->algo.width = width;
    crc->algo.poly = poly;
    crc->algo.init = init;
    crc->algo.flags = CRC_REFIN_TO_FLAGS(refin) | CRC_REFOUT_TO_FLAGS(refout);
    crc->algo.xorout = xorout;
    crc8_table_init(table, width, poly, refin);
    crc->table = table;
    crc->value = crc8_init_value(init, width, refin);
}

static CRC_INLINE void crc16_init_impl(Crc16 *crc,
                                       crc_u16 width,
                                       crc_u16 poly,
                                       crc_u16 init,
                                       crc_bool refin,
                                       crc_bool refout,
                                       crc_u16 xorout,
                                       crc_u16 *table) {
    crc->algo.width = width;
    crc->algo.poly = poly;
    crc->algo.init = init;
    crc->algo.flags = CRC_REFIN_TO_FLAGS(refin) | CRC_REFOUT_TO_FLAGS(refout);
    crc->algo.xorout = xorout;
    crc16_table_init(table, width, poly, refin);
    crc->table = table;
    crc->value = crc16_init_value(init, width, refin);
}

static CRC_INLINE void crc32_init_impl(Crc32 *crc,
                                       crc_u32 width,
                                       crc_u32 poly,
                                       crc_u32 init,
                                       crc_bool refin,
                                       crc_bool refout,
                                       crc_u32 xorout,
                                       crc_u32 *table) {
    crc->algo.width = width;
    crc->algo.poly = poly;
    crc->algo.init = init;
    crc->algo.flags = CRC_REFIN_TO_FLAGS(refin) | CRC_REFOUT_TO_FLAGS(refout);
    crc->algo.xorout = xorout;
    crc32_table_init(table, width, poly, refin);
    crc->table = table;
    crc->value = crc32_init_value(init, width, refin);
}

static CRC_INLINE void crc64_init_impl(Crc64 *crc,
                                       crc_u64 width,
                                       crc_u64 poly,
                                       crc_u64 init,
                                       crc_bool refin,
                                       crc_bool refout,
                                       crc_u64 xorout,
                                       crc_u64 *table) {
    crc->algo.width = width;
    crc->algo.poly = poly;
    crc->algo.init = init;
    crc->algo.flags = CRC_REFIN_TO_FLAGS(refin) | CRC_REFOUT_TO_FLAGS(refout);
    crc->algo.xorout = xorout;
    crc64_table_init(table, width, poly, refin);
    crc->table = table;
    crc->value = crc64_init_value(init, width, refin);
}

static CRC_INLINE void crc8_update_impl(Crc8 *crc, const void *bytes, size_t size) {
    size_t i;

    for(i = 0; i < size; i++) {
        crc->value = crc->table[crc->value ^ ((crc_u8 *)bytes)[i]];
    }
}

static CRC_INLINE void crc16_update_impl(Crc16 *crc, const void *bytes, size_t size) {
    size_t i;

    if(crc->algo.flags & CRC_FLAG_REFIN) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value & 0xFF) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 8) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value << 8);
        }
    }
}

static CRC_INLINE void crc32_update_impl(Crc32 *crc, const void *bytes, size_t size) {
    size_t i;

    if(crc->algo.flags & CRC_FLAG_REFIN) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value & 0xFF) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 24) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value << 8);
        }
    }
}

static CRC_INLINE void crc64_update_impl(Crc64 *crc, const void *bytes, size_t size) {
    size_t i;

    if(crc->algo.flags & CRC_FLAG_REFIN) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value & 0xFF) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 56) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value << 8);
        }
    }
}

static CRC_INLINE crc_u8 crc8_finalize_impl(Crc8 *crc) {
    crc_u8 ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc8_init_value(crc->algo.init, crc->algo.width, CRC_FLAGS_TO_REFIN(crc->algo.flags));

    if(CRC_FLAGS_TO_REFIN(crc->algo.flags) ^ CRC_FLAGS_TO_REFOUT(crc->algo.flags)) {
        ret = rev8(ret);
    }
    if(!(crc->algo.flags & CRC_FLAG_REFOUT)) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

static CRC_INLINE crc_u16 crc16_finalize_impl(Crc16 *crc) {
    crc_u16 ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc16_init_value(crc->algo.init, crc->algo.width, CRC_FLAGS_TO_REFIN(crc->algo.flags));

    if(CRC_FLAGS_TO_REFIN(crc->algo.flags) ^ CRC_FLAGS_TO_REFOUT(crc->algo.flags)) {
        ret = rev16(ret);
    }
    if(!(crc->algo.flags & CRC_FLAG_REFOUT)) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

static CRC_INLINE crc_u32 crc32_finalize_impl(Crc32 *crc) {
    crc_u32 ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc32_init_value(crc->algo.init, crc->algo.width, CRC_FLAGS_TO_REFIN(crc->algo.flags));

    if(CRC_FLAGS_TO_REFIN(crc->algo.flags) ^ CRC_FLAGS_TO_REFOUT(crc->algo.flags)) {
        ret = rev32(ret);
    }
    if(!(crc->algo.flags & CRC_FLAG_REFOUT)) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

static CRC_INLINE crc_u64 crc64_finalize_impl(Crc64 *crc) {
    crc_u64 ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc64_init_value(crc->algo.init, crc->algo.width, CRC_FLAGS_TO_REFIN(crc->algo.flags));

    if(CRC_FLAGS_TO_REFIN(crc->algo.flags) ^ CRC_FLAGS_TO_REFOUT(crc->algo.flags)) {
        ret = rev64(ret);
    }
    if(!(crc->algo.flags & CRC_FLAG_REFOUT)) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

CrcErrors crc8_init_static_(Crc8 *crc,
                            crc_u8 width,
                            crc_u8 poly,
                            crc_u8 init,
                            crc_bool refin,
                            crc_bool refout,
                            crc_u8 xorout,
                            crc_u8 *table) {
    if(!crc || !table) {
        return CRC_ERR_INVALID_ARG;
    }

    crc8_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    return CRC_OK;
}

CrcErrors crc16_init_static_(Crc16 *crc,
                             crc_u16 width,
                             crc_u16 poly,
                             crc_u16 init,
                             crc_bool refin,
                             crc_bool refout,
                             crc_u16 xorout,
                             crc_u16 *table) {
    if(!crc || !table) {
        return CRC_ERR_INVALID_ARG;
    }

    crc16_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    return CRC_OK;
}

CrcErrors crc32_init_static_(Crc32 *crc,
                             crc_u32 width,
                             crc_u32 poly,
                             crc_u32 init,
                             crc_bool refin,
                             crc_bool refout,
                             crc_u32 xorout,
                             crc_u32 *table) {
    if(!crc || !table) {
        return CRC_ERR_INVALID_ARG;
    }

    crc32_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    return CRC_OK;
}

CrcErrors crc64_init_static_(Crc64 *crc,
                             crc_u64 width,
                             crc_u64 poly,
                             crc_u64 init,
                             crc_bool refin,
                             crc_bool refout,
                             crc_u64 xorout,
                             crc_u64 *table) {
    if(!crc || !table) {
        return CRC_ERR_INVALID_ARG;
    }

    crc64_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    return CRC_OK;
}
#if defined(CRC_USE_HEAP)
Crc8 *crc8_init_(crc_u8 width, crc_u8 poly, crc_u8 init, crc_bool refin, crc_bool refout, crc_u8 xorout) {
    Crc8 *crc;
    crc_u8 *table;

    crc = malloc(sizeof(*crc));
    if(!crc) {
        return NULL;
    }

    table = malloc(256 * sizeof(*table));
    if(!table) {
        free(crc);
        return NULL;
    }

    crc8_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    crc->algo.flags |= CRC_FLAG_DYN_ALLOC;
    return crc;
}

Crc16 *crc16_init_(crc_u16 width, crc_u16 poly, crc_u16 init, crc_bool refin, crc_bool refout, crc_u16 xorout) {
    Crc16 *crc;
    crc_u16 *table;

    crc = malloc(sizeof(*crc));
    if(!crc) {
        return NULL;
    }

    table = malloc(256 * sizeof(*table));
    if(!table) {
        free(crc);
        return NULL;
    }

    crc16_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    crc->algo.flags |= CRC_FLAG_DYN_ALLOC;
    return crc;
}

Crc32 *crc32_init_(crc_u32 width, crc_u32 poly, crc_u32 init, crc_bool refin, crc_bool refout, crc_u32 xorout) {
    Crc32 *crc;
    crc_u32 *table;

    crc = malloc(sizeof(*crc));
    if(!crc) {
        return NULL;
    }

    table = malloc(256 * sizeof(*table));
    if(!table) {
        free(crc);
        return NULL;
    }

    crc32_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    crc->algo.flags |= CRC_FLAG_DYN_ALLOC;
    return crc;
}

Crc64 *crc64_init_(crc_u64 width, crc_u64 poly, crc_u64 init, crc_bool refin, crc_bool refout, crc_u64 xorout) {
    Crc64 *crc;
    crc_u64 *table;

    crc = malloc(sizeof(*crc));
    if(!crc) {
        return NULL;
    }

    table = malloc(256 * sizeof(*table));
    if(!table) {
        free(crc);
        return NULL;
    }

    crc64_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    crc->algo.flags |= CRC_FLAG_DYN_ALLOC;
    return crc;
}

void crc8_destroy(Crc8 *crc) {
    if(!crc || !crc->table || !(crc->algo.flags & CRC_FLAG_DYN_ALLOC)) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
    free(crc);
}

void crc16_destroy(Crc16 *crc) {
    if(!crc || !crc->table || !(crc->algo.flags & CRC_FLAG_DYN_ALLOC)) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
    free(crc);
}

void crc32_destroy(Crc32 *crc) {
    if(!crc || !crc->table || !(crc->algo.flags & CRC_FLAG_DYN_ALLOC)) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
    free(crc);
}

void crc64_destroy(Crc64 *crc) {
    if(!crc || !crc->table || !(crc->algo.flags & CRC_FLAG_DYN_ALLOC)) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
    free(crc);
}
#endif /* CRC_USE_HEAP */
void crc8_update(Crc8 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return;
    }

    crc8_update_impl(crc, bytes, size);
}

void crc16_update(Crc16 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return;
    }

    crc16_update_impl(crc, bytes, size);
}

void crc32_update(Crc32 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return;
    }

    crc32_update_impl(crc, bytes, size);
}

void crc64_update(Crc64 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return;
    }

    crc64_update_impl(crc, bytes, size);
}

crc_u8 crc8_finalize(Crc8 *crc) {
    if(!crc) {
        return 0;
    }

    return crc8_finalize_impl(crc);
}

crc_u16 crc16_finalize(Crc16 *crc) {
    if(!crc) {
        return 0;
    }

    return crc16_finalize_impl(crc);
}

crc_u32 crc32_finalize(Crc32 *crc) {
    if(!crc) {
        return 0;
    }

    return crc32_finalize_impl(crc);
}

crc_u64 crc64_finalize(Crc64 *crc) {
    if(!crc) {
        return 0;
    }

    return crc64_finalize_impl(crc);
}

crc_u8 crc8_checksum(Crc8 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return 0;
    }

    crc8_update_impl(crc, bytes, size);
    return crc8_finalize_impl(crc);
}

crc_u16 crc16_checksum(Crc16 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return 0;
    }

    crc16_update_impl(crc, bytes, size);
    return crc16_finalize_impl(crc);
}

crc_u32 crc32_checksum(Crc32 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return 0;
    }

    crc32_update_impl(crc, bytes, size);
    return crc32_finalize_impl(crc);
}

crc_u64 crc64_checksum(Crc64 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return 0;
    }

    crc64_update_impl(crc, bytes, size);
    return crc64_finalize_impl(crc);
}

#if CRC_HAS_128BIT_ALGO
/**
    \param poly Порождающий многочлен
    \param refin Начало и направление вычислений
    \param init Стартовые данные
    \return Контрольную сумму
    \brief Ручное вычисление контрольной суммы. Необходимо для заполнения таблицы в \ref crc128_init_value
*/
static CRC_INLINE crc_u128 crc128(crc_u128 poly, crc_bool refin, crc_u128 init) {
    int i = 8;

    if(refin) {
        while(i--) {
            init = (init >> 1) ^ (poly * (init & 1));
        }
    } else {
        init <<= 8 * (sizeof(init) - 1);
        while(i--) {
            init = (init << 1) ^ (poly * ((init >> (8 * sizeof(init) - 1)) & 1));
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
static void crc128_table_init(crc_u128 *table, crc_u8 width, crc_u128 poly, crc_bool refin) {
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
static CRC_INLINE crc_u128 crc128_init_value(crc_u128 init, crc_u8 width, crc_bool refin) {
    return refin ? rev128(init) >> (8 * sizeof(init) - width) : init << (8 * sizeof(init) - width);
}

static CRC_INLINE void crc128_init_impl(Crc128 *crc,
                                        crc_u128 width,
                                        crc_u128 poly,
                                        crc_u128 init,
                                        crc_bool refin,
                                        crc_bool refout,
                                        crc_u128 xorout,
                                        crc_u128 *table) {
    crc->algo.width = width;
    crc->algo.poly = poly;
    crc->algo.init = init;
    crc->algo.flags = CRC_REFIN_TO_FLAGS(refin) | CRC_REFOUT_TO_FLAGS(refout);
    crc->algo.xorout = xorout;
    crc128_table_init(table, width, poly, refin);
    crc->table = table;
    crc->value = crc128_init_value(init, width, refin);
}

static CRC_INLINE void crc128_update_impl(Crc128 *crc, const void *bytes, size_t size) {
    size_t i;

    if(crc->algo.flags & CRC_FLAG_REFIN) {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value & 0xFF) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value >> 8);
        }
    } else {
        for(i = 0; i < size; i++) {
            crc->value = crc->table[(crc->value >> 120) ^ ((crc_u8 *)bytes)[i]] ^ (crc->value << 8);
        }
    }
}

static CRC_INLINE crc_u128 crc128_finalize_impl(Crc128 *crc) {
    crc_u128 ret;

    ret = crc->value; /* сохраняем значение CRC и восстанавливаем начальное */
    crc->value = crc128_init_value(crc->algo.init, crc->algo.width, CRC_FLAGS_TO_REFIN(crc->algo.flags));

    if(CRC_FLAGS_TO_REFIN(crc->algo.flags) ^ CRC_FLAGS_TO_REFOUT(crc->algo.flags)) {
        ret = rev128(ret);
    }
    if(!(crc->algo.flags & CRC_FLAG_REFOUT)) {
        ret >>= 8 * sizeof(ret) - crc->algo.width;
    }
    return ret ^ crc->algo.xorout;
}

CrcErrors crc128_init_static_(Crc128 *crc,
                              crc_u128 width,
                              crc_u128 poly,
                              crc_u128 init,
                              crc_bool refin,
                              crc_bool refout,
                              crc_u128 xorout,
                              crc_u128 *table) {
    if(!crc || !table) {
        return CRC_ERR_INVALID_ARG;
    }

    crc128_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    return CRC_OK;
}
#if defined(CRC_USE_HEAP)
Crc128 *crc128_init_(crc_u128 width, crc_u128 poly, crc_u128 init, crc_bool refin, crc_bool refout, crc_u128 xorout) {
    Crc128 *crc;
    crc_u128 *table;

    crc = malloc(sizeof(*crc));
    if(!crc) {
        return NULL;
    }

    table = malloc(256 * sizeof(*table));
    if(!table) {
        free(crc);
        return NULL;
    }

    crc128_init_impl(crc, width, poly, init, refin, refout, xorout, table);
    crc->algo.flags |= CRC_FLAG_DYN_ALLOC;
    return crc;
}

void crc128_destroy(Crc128 *crc) {
    if(!crc || !crc->table || !(crc->algo.flags & CRC_FLAG_DYN_ALLOC)) {
        return;
    }
    free((void *)crc->table);
    crc->table = NULL;
    free(crc);
}
#endif /* CRC_USE_HEAP */
void crc128_update(Crc128 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return;
    }

    crc128_update_impl(crc, bytes, size);
}

crc_u128 crc128_finalize(Crc128 *crc) {
    if(!crc) {
        return 0;
    }

    return crc128_finalize_impl(crc);
}

crc_u128 crc128_checksum(Crc128 *crc, const void *bytes, size_t size) {
    if(!crc || !bytes) {
        return 0;
    }

    crc128_update_impl(crc, bytes, size);
    return crc128_finalize_impl(crc);
}
#endif /* CRC_HAS_128BIT_ALGO */
