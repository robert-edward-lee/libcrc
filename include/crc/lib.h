/**
    \file lib.h
    \brief Интерфейс библиотеки расчёта циклического избыточного кода
*/
#ifndef H_CRC_LIB
#define H_CRC_LIB

#include "crc/internal/defines.h"
#include "crc/internal/types.h"
#include "crc/version.h"

CRC_EXTERN_C_BEGIN

/**
    \brief Ошибки возвращаемые при инициализации
*/
typedef enum {
    CRC_OK, /**< Всё ок */
    CRC_ERR_INVALID_ARG /**< Как правило нуль-указатель в качестве аргумента */
} CrcErrors;

/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода шириной 8 бит
*/
typedef struct {
    crc_u8 width; /**< Степень порождающего многочлена */
    crc_u8 poly; /**< Порождающий многочлен */
    crc_u8 init; /**< Стартовые данные */
    crc_u8 flags; /**< RefIn и RefOut */
    crc_u8 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
} Crc8BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода шириной 16 бит
*/
typedef struct {
    crc_u8 width; /**< Степень порождающего многочлена */
    crc_u16 poly; /**< Порождающий многочлен */
    crc_u16 init; /**< Стартовые данные */
    crc_u8 flags; /**< RefIn и RefOut */
    crc_u16 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
} Crc16BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода шириной 32 бит
*/
typedef struct {
    crc_u8 width; /**< Степень порождающего многочлена */
    crc_u32 poly; /**< Порождающий многочлен */
    crc_u32 init; /**< Стартовые данные */
    crc_u8 flags; /**< RefIn и RefOut */
    crc_u32 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
} Crc32BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода шириной 64 бит
*/
typedef struct {
    crc_u8 width; /**< Степень порождающего многочлена */
    crc_u64 poly; /**< Порождающий многочлен */
    crc_u64 init; /**< Стартовые данные */
    crc_u8 flags; /**< RefIn и RefOut */
    crc_u64 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
} Crc64BasedAlgo;
/**
    \brief "Объект" для расчёта контрольной суммы шириной 8 бит
*/
typedef struct {
    Crc8BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u8 *table; /**< Таблица для вычисления */
    crc_u8 value; /**< Промежуточное значение контрольной суммы */
} Crc8;
/**
    \brief "Объект" для расчёта контрольной суммы шириной 16 бит
*/
typedef struct {
    Crc16BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u16 *table; /**< Таблица для вычисления */
    crc_u16 value; /**< Промежуточное значение контрольной суммы */
} Crc16;
/**
    \brief "Объект" для расчёта контрольной суммы шириной 32 бит
*/
typedef struct {
    Crc32BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u32 *table; /**< Таблица для вычисления */
    crc_u32 value; /**< Промежуточное значение контрольной суммы */
} Crc32;
/**
    \brief "Объект" для расчёта контрольной суммы шириной 64 бит
*/
typedef struct {
    Crc64BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u64 *table; /**< Таблица для вычисления */
    crc_u64 value; /**< Промежуточное значение контрольной суммы */
} Crc64;

/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \param xorout Число, с которым складывается по модулю 2 полученный результат
    \param[in] table Предварительно выделенная память размером 256 байт для хранения таблицы расчёта
    \return Код ошибки
    \brief Инициализация "объекта" \ref Crc8
*/
CRC_NOTHROW CrcErrors crc8_init_static_(Crc8 *crc,
                                        crc_u8 width,
                                        crc_u8 poly,
                                        crc_u8 init,
                                        crc_bool refin,
                                        crc_bool refout,
                                        crc_u8 xorout,
                                        crc_u8 *table);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 256 байт для хранения таблицы расчёта
    \return Код ошибки
    \brief Обёртка над функцией \ref crc8_init_static_
*/
#define crc8_init_static(crc, algo, table) crc8_init_static_(crc, CRC_DO_EXPAND_CTOR(algo), table)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \param xorout Число, с которым складывается по модулю 2 полученный результат
    \param[in] table Предварительно выделенная память размером 2x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc16
*/
CRC_NOTHROW CrcErrors crc16_init_static_(Crc16 *crc,
                                         crc_u8 width,
                                         crc_u16 poly,
                                         crc_u16 init,
                                         crc_bool refin,
                                         crc_bool refout,
                                         crc_u16 xorout,
                                         crc_u16 *table);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 2x256 байт для хранения таблицы расчёта
    \return Код ошибки
    \brief Обёртка над функцией \ref crc16_init_static_
*/
#define crc16_init_static(crc, algo, table) crc16_init_static_(crc, CRC_DO_EXPAND_CTOR(algo), table)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \param xorout Число, с которым складывается по модулю 2 полученный результат
    \param[in] table Предварительно выделенная память размером 4x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc32
*/
CRC_NOTHROW CrcErrors crc32_init_static_(Crc32 *crc,
                                         crc_u8 width,
                                         crc_u32 poly,
                                         crc_u32 init,
                                         crc_bool refin,
                                         crc_bool refout,
                                         crc_u32 xorout,
                                         crc_u32 *table);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 4x256 байт для хранения таблицы расчёта
    \return Код ошибки
    \brief Обёртка над функцией \ref crc32_init_static_
*/
#define crc32_init_static(crc, algo, table) crc32_init_static_(crc, CRC_DO_EXPAND_CTOR(algo), table)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \param xorout Число, с которым складывается по модулю 2 полученный результат
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc64
*/
CRC_NOTHROW CrcErrors crc64_init_static_(Crc64 *crc,
                                         crc_u8 width,
                                         crc_u64 poly,
                                         crc_u64 init,
                                         crc_bool refin,
                                         crc_bool refout,
                                         crc_u64 xorout,
                                         crc_u64 *table);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \return Код ошибки
    \brief Обёртка над функцией \ref crc64_init_static_
*/
#define crc64_init_static(crc, algo, table) crc64_init_static_(crc, CRC_DO_EXPAND_CTOR(algo), table)
#if defined(CRC_USE_HEAP)
/**
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \return Указатель на объект Crc
    \brief Инициализация "объекта" \ref Crc8, таблица при этом будет создана динамически
*/
CRC_NOTHROW Crc8 *crc8_init_(crc_u8 width, crc_u8 poly, crc_u8 init, crc_bool refin, crc_bool refout, crc_u8 xorout);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \return Указатель на объект Crc
    \brief Обёртка над функцией \ref crc8_init_
*/
#define crc8_init(algo) crc8_init_(CRC_DO_EXPAND_CTOR(algo))
/**
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \return Указатель на объект Crc
    \brief Инициализация "объекта" \ref Crc16, таблица при этом будет создана динамически
*/
CRC_NOTHROW Crc16 *
crc16_init_(crc_u8 width, crc_u16 poly, crc_u16 init, crc_bool refin, crc_bool refout, crc_u16 xorout);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \return Указатель на объект Crc
    \brief Обёртка над функцией \ref crc16_init_
*/
#define crc16_init(algo) crc16_init_(CRC_DO_EXPAND_CTOR(algo))
/**
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \return Указатель на объект Crc
    \brief Инициализация "объекта" \ref Crc32, таблица при этом будет создана динамически
*/
CRC_NOTHROW Crc32 *
crc32_init_(crc_u8 width, crc_u32 poly, crc_u32 init, crc_bool refin, crc_bool refout, crc_u32 xorout);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \return Указатель на объект Crc
    \brief Обёртка над функцией \ref crc32_init_
*/
#define crc32_init(algo) crc32_init_(CRC_DO_EXPAND_CTOR(algo))
/**
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \return Указатель на объект Crc
    \brief Инициализация "объекта" \ref Crc64, таблица при этом будет создана динамически
*/
CRC_NOTHROW Crc64 *
crc64_init_(crc_u8 width, crc_u64 poly, crc_u64 init, crc_bool refin, crc_bool refout, crc_u64 xorout);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \return Указатель на объект Crc
    \brief Обёртка над функцией \ref crc64_init_
*/
#define crc64_init(algo) crc64_init_(CRC_DO_EXPAND_CTOR(algo))
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \brief Очистка памяти если crc инициализирован при помощи \ref crc8_init_
*/
CRC_NOTHROW void crc8_destroy(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \brief Очистка памяти если crc инициализирован при помощи \ref crc16_init_
*/
CRC_NOTHROW void crc16_destroy(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \brief Очистка памяти если crc инициализирован при помощи \ref crc32_init_
*/
CRC_NOTHROW void crc32_destroy(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \brief Очистка памяти если crc инициализирован при помощи \ref crc64_init_
*/
CRC_NOTHROW void crc64_destroy(Crc64 *crc);
#endif /* CRC_USE_HEAP */
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc8::value. Функция позволяет вычислять CRC
    итеративно
*/
CRC_NOTHROW void crc8_update(Crc8 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc16::value. Функция позволяет вычислять CRC
    итеративно
*/
CRC_NOTHROW void crc16_update(Crc16 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc32::value. Функция позволяет вычислять CRC
    итеративно
*/
CRC_NOTHROW void crc32_update(Crc32 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc64::value. Функция позволяет вычислять CRC
    итеративно
*/
CRC_NOTHROW void crc64_update(Crc64 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc8_update. Также происходит очистка значения \ref Crc8::value и "объект" crc можно использовать для
    нового вычисления
*/
CRC_NOTHROW crc_u8 crc8_finalize(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc16_update. Также происходит очистка значения \ref Crc16::value и "объект" crc можно использовать для
    нового вычисления
*/
CRC_NOTHROW crc_u16 crc16_finalize(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc32_update. Также происходит очистка значения \ref Crc32::value и "объект" crc можно использовать для
    нового вычисления
*/
CRC_NOTHROW crc_u32 crc32_finalize(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc64_update. Также происходит очистка значения \ref Crc64::value и "объект" crc можно использовать для
    нового вычисления
*/
CRC_NOTHROW crc_u64 crc64_finalize(Crc64 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
CRC_NOTHROW crc_u8 crc8_checksum(Crc8 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
CRC_NOTHROW crc_u16 crc16_checksum(Crc16 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
CRC_NOTHROW crc_u32 crc32_checksum(Crc32 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
CRC_NOTHROW crc_u64 crc64_checksum(Crc64 *crc, const void *bytes, size_t size);

#if CRC_HAS_128BIT_ALGO
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода шириной 128 бит
*/
typedef struct {
    crc_u8 width; /**< Степень порождающего многочлена */
    crc_u128 poly; /**< Порождающий многочлен */
    crc_u128 init; /**< Стартовые данные */
    crc_u8 flags; /**< RefIn и RefOut */
    crc_u128 xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
} Crc128BasedAlgo;
/**
    \brief "Объект" для расчёта контрольной суммы шириной 128 бит
*/
typedef struct {
    Crc128BasedAlgo algo; /**< Алгоритм вычисления */
    const crc_u128 *table; /**< Таблица для вычисления */
    crc_u128 value; /**< Промежуточное значение контрольной суммы */
} Crc128;
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc128
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \param[in] table Предварительно выделенная память размером 128x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc128
*/
CRC_NOTHROW CrcErrors crc128_init_static_(Crc128 *crc,
                                          crc_u8 width,
                                          crc_u128 poly,
                                          crc_u128 init,
                                          crc_bool refin,
                                          crc_bool refout,
                                          crc_u128 xorout,
                                          crc_u128 *table);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc128
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 128x256 байт для хранения таблицы расчёта
    \return Код ошибки
    \brief Обёртка над функцией \ref crc128_init_static_
*/
#define crc128_init_static(crc, algo, table) crc128_init_static_(crc, CRC_DO_EXPAND_CTOR(algo), table)
#if defined(CRC_USE_HEAP)
/**
    \param width Степень порождающего многочлена
    \param poly Порождающий многочлен
    \param init Стартовые данные
    \param refin Начало и направление вычислений
    \param refout Инвертируется ли порядок битов при складывании по модулю 2 полученного результата
    \return Указатель на объект Crc
    \brief Инициализация "объекта" \ref Crc128, таблица при этом будет создана динамически
*/
CRC_NOTHROW Crc128 *
crc128_init_(crc_u8 width, crc_u128 poly, crc_u128 init, crc_bool refin, crc_bool refout, crc_u128 xorout);
/**
    \param[in,out] crc Указатель на предварительно созданный экземпляр \ref Crc128
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \return Указатель на объект Crc
    \brief Обёртка над функцией \ref crc128_init_
*/
#define crc128_init(algo) crc128_init_(CRC_DO_EXPAND_CTOR(algo))
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \brief Очистка памяти если crc инициализирован при помощи \ref crc128_
*/
CRC_NOTHROW void crc128_destroy(Crc128 *crc);
#endif /* CRC_USE_HEAP */
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в \ref Crc128::value. Функция позволяет вычислять CRC
    итеративно
*/
CRC_NOTHROW void crc128_update(Crc128 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc128_update. Также происходит очистка значения \ref Crc128::value и "объект" crc можно использовать
   для нового вычисления
*/
CRC_NOTHROW crc_u128 crc128_finalize(Crc128 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
CRC_NOTHROW crc_u128 crc128_checksum(Crc128 *crc, const void *bytes, size_t size);
#endif /* CRC_HAS_128BIT_ALGO */

CRC_EXTERN_C_END

#endif /* H_CRC_LIB */
