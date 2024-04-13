/**
    \file lib.h
    \brief Интерфейс библиотеки расчёта циклического избыточного кода
*/
#ifndef H_CRC_LIB
#define H_CRC_LIB

#include <stddef.h>

#include "crc/internal/defines.h"
#include "crc/internal/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 8 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    crc_u8 poly; /**< Порождающий многочлен */
    crc_u8 init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    crc_u8 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    crc_u8 check; /**< Значение CRC для строки «123456789» */
} Crc8BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 16 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    crc_u16 poly; /**< Порождающий многочлен */
    crc_u16 init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    crc_u16 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    crc_u16 check; /**< Значение CRC для строки «123456789» */
} Crc16BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 32 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    crc_u32 poly; /**< Порождающий многочлен */
    crc_u32 init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    crc_u32 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    crc_u32 check; /**< Значение CRC для строки «123456789» */
} Crc32BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 64 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    crc_u64 poly; /**< Порождающий многочлен */
    crc_u64 init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    crc_u64 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    crc_u64 check; /**< Значение CRC для строки «123456789» */
} Crc64BasedAlgo;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 8 бит
*/
typedef struct {
    Crc8BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u8 *table; /**< Таблица для вычисления */
    crc_u8 value; /**< Промежуточное значение контрольной суммы */
} Crc8;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 16 бит
*/
typedef struct {
    Crc16BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u16 *table; /**< Таблица для вычисления */
    crc_u16 value; /**< Промежуточное значение контрольной суммы */
} Crc16;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 32 бит
*/
typedef struct {
    Crc32BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u32 *table; /**< Таблица для вычисления */
    crc_u32 value; /**< Промежуточное значение контрольной суммы */
} Crc32;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 64 бит
*/
typedef struct {
    Crc64BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u64 *table; /**< Таблица для вычисления */
    crc_u64 value; /**< Промежуточное значение контрольной суммы */
} Crc64;

/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc8
*/
void crc8_init_static_impl(Crc8 *crc, const Crc8BasedAlgo *algo, crc_u8 *table);
#define crc8_init_static(crc, algo, table) \
    do { \
        Crc8BasedAlgo algo_ = algo; \
        crc8_init_static_impl(crc, &algo_, table); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 2x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc16
*/
void crc16_init_static_impl(Crc16 *crc, const Crc16BasedAlgo *algo, crc_u16 *table);
#define crc16_init_static(crc, algo, table) \
    do { \
        Crc16BasedAlgo algo_ = algo; \
        crc16_init_static_impl(crc, &algo_, table); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 4x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc32
*/
void crc32_init_static_impl(Crc32 *crc, const Crc32BasedAlgo *algo, crc_u32 *table);
#define crc32_init_static(crc, algo, table) \
    do { \
        Crc32BasedAlgo algo_ = algo; \
        crc32_init_static_impl(crc, &algo_, table); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc64
*/
void crc64_init_static_impl(Crc64 *crc, const Crc64BasedAlgo *algo, crc_u64 *table);
#define crc64_init_static(crc, algo, table) \
    do { \
        Crc64BasedAlgo algo_ = algo; \
        crc64_init_static_impl(crc, &algo_, table); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc8, таблица при этом будет создана динамически
*/
void crc8_init_impl(Crc8 *crc, const Crc8BasedAlgo *algo);
#define crc8_init(crc, algo) \
    do { \
        Crc8BasedAlgo algo_ = algo; \
        crc8_init_impl(crc, &algo_); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc16, таблица при этом будет создана динамически
*/
void crc16_init_impl(Crc16 *crc, const Crc16BasedAlgo *algo);
#define crc16_init(crc, algo) \
    do { \
        Crc16BasedAlgo algo_ = algo; \
        crc16_init_impl(crc, &algo_); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc32, таблица при этом будет создана динамически
*/
void crc32_init_impl(Crc32 *crc, const Crc32BasedAlgo *algo);
#define crc32_init(crc, algo) \
    do { \
        Crc32BasedAlgo algo_ = algo; \
        crc32_init_impl(crc, &algo_); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc64, таблица при этом будет создана динамически
*/
void crc64_init_impl(Crc64 *crc, const Crc64BasedAlgo *algo);
#define crc64_init(crc, algo) \
    do { \
        Crc64BasedAlgo algo_ = algo; \
        crc64_init_impl(crc, &algo_); \
    } while(0)
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \brief Очистка памяти если crc инициализирован при помощи \ref crc8_init_impl
*/
void crc8_destroy(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \brief Очистка памяти если crc инициализирован при помощи \ref crc16_init_impl
*/
void crc16_destroy(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \brief Очистка памяти если crc инициализирован при помощи \ref crc32_init_impl
*/
void crc32_destroy(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \brief Очистка памяти если crc инициализирован при помощи \ref crc64_init_impl
*/
void crc64_destroy(Crc64 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc8::value. Функция позволяет вычислять CRC
    итеративно
*/
void crc8_update(Crc8 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc16::value. Функция позволяет вычислять CRC
    итеративно
*/
void crc16_update(Crc16 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc32::value. Функция позволяет вычислять CRC
    итеративно
*/
void crc32_update(Crc32 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc64::value. Функция позволяет вычислять CRC
    итеративно
*/
void crc64_update(Crc64 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc8_update. Также происходит очистка значения \ref Crc8::value и "объект" crc можно использовать для
    нового вычисления
*/
crc_u8 crc8_finalize(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc16_update. Также происходит очистка значения \ref Crc16::value и "объект" crc можно использовать для
    нового вычисления
*/
crc_u16 crc16_finalize(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc32_update. Также происходит очистка значения \ref Crc32::value и "объект" crc можно использовать для
    нового вычисления
*/
crc_u32 crc32_finalize(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc64_update. Также происходит очистка значения \ref Crc64::value и "объект" crc можно использовать для
    нового вычисления
*/
crc_u64 crc64_finalize(Crc64 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
crc_u8 crc8_checksum(Crc8 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
crc_u16 crc16_checksum(Crc16 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
crc_u32 crc32_checksum(Crc32 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
crc_u64 crc64_checksum(Crc64 *crc, const void *bytes, size_t size);

#if CRC_HAS_128BIT_ALGO
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 128 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    crc_u128 poly; /**< Порождающий многочлен */
    crc_u128 init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    crc_u128 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    crc_u128 check; /**< Значение CRC для строки «123456789» */
} Crc128BasedAlgo;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 128 бит
*/
typedef struct {
    Crc128BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u128 *table; /**< Таблица для вычисления */
    crc_u128 value; /**< Промежуточное значение контрольной суммы */
} Crc128;

/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc128
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc128
*/
void crc128_init_static_impl(Crc128 *crc, const Crc128BasedAlgo *algo, crc_u128 *table);
#define crc128_init_static(crc, algo, table) \
    do { \
        Crc128BasedAlgo algo_ = algo; \
        crc128_init_static_impl(crc, &algo_, table); \
    } while(0)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc128
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc128, таблица при этом будет создана динамически
*/
void crc128_init_impl(Crc128 *crc, const Crc128BasedAlgo *algo);
#define crc128_init(crc, algo) \
    do { \
        Crc128BasedAlgo algo_ = algo; \
        crc128_init_impl(crc, &algo_); \
    } while(0)
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \brief Очистка памяти если crc инициализирован при помощи \ref crc128_init_impl
*/
void crc128_destroy(Crc128 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc128::value. Функция позволяет вычислять CRC
    итеративно
*/
void crc128_update(Crc128 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc128_update. Также происходит очистка значения \ref Crc128::value и "объект" crc можно использовать
   для нового вычисления
*/
crc_u128 crc128_finalize(Crc128 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
crc_u128 crc128_checksum(Crc128 *crc, const void *bytes, size_t size);
#endif /* CRC_HAS_128BIT_ALGO */

#ifdef __cplusplus
}
#endif

#endif /* H_CRC_LIB */
