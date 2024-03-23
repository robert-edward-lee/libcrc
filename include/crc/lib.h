/**
    \file lib.h
    \brief Интерфейс библиотеки расчёта циклического избыточного кода
*/
#ifndef H_CRC_LIB
#define H_CRC_LIB

#include <stddef.h>
#include <stdint.h>

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
    uint8_t poly; /**< Порождающий многочлен */
    uint8_t init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    uint8_t xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    uint8_t check; /**< Значение CRC для строки «123456789» */
} Crc8BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 16 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    uint16_t poly; /**< Порождающий многочлен */
    uint16_t init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    uint16_t xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    uint16_t check; /**< Значение CRC для строки «123456789» */
} Crc16BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 32 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    uint32_t poly; /**< Порождающий многочлен */
    uint32_t init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    uint32_t xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    uint32_t check; /**< Значение CRC для строки «123456789» */
} Crc32BasedAlgo;
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 64 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    uint64_t poly; /**< Порождающий многочлен */
    uint64_t init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    uint64_t xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    uint64_t check; /**< Значение CRC для строки «123456789» */
} Crc64BasedAlgo;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 8 бит
*/
typedef struct {
    Crc8BasedAlgo algo; /**< Алгоритм вычисления */
    const uint8_t *table; /**< Таблица для вычисления */
    uint8_t value; /**< Промежуточное значение контрольной суммы */
} Crc8;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 16 бит
*/
typedef struct {
    Crc16BasedAlgo algo; /**< Алгоритм вычисления */
    const uint16_t *table; /**< Таблица для вычисления */
    uint16_t value; /**< Промежуточное значение контрольной суммы */
} Crc16;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 32 бит
*/
typedef struct {
    Crc32BasedAlgo algo; /**< Алгоритм вычисления */
    const uint32_t *table; /**< Таблица для вычисления */
    uint32_t value; /**< Промежуточное значение контрольной суммы */
} Crc32;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 64 бит
*/
typedef struct {
    Crc64BasedAlgo algo; /**< Алгоритм вычисления */
    const uint64_t *table; /**< Таблица для вычисления */
    uint64_t value; /**< Промежуточное значение контрольной суммы */
} Crc64;

/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc8
*/
void crc8_init_static_(Crc8 *crc, const Crc8BasedAlgo *algo, uint8_t *table);
#define crc8_init_static(crc, algo, table)                                                                             \
    {                                                                                                                  \
        Crc8BasedAlgo algo_ = algo;                                                                                    \
        crc8_init_static_(crc, &algo_, table);                                                                         \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 2x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc16
*/
void crc16_init_static_(Crc16 *crc, const Crc16BasedAlgo *algo, uint16_t *table);
#define crc16_init_static(crc, algo, table)                                                                            \
    {                                                                                                                  \
        Crc16BasedAlgo algo_ = algo;                                                                                   \
        crc16_init_static_(crc, &algo_, table);                                                                        \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 4x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc32
*/
void crc32_init_static_(Crc32 *crc, const Crc32BasedAlgo *algo, uint32_t *table);
#define crc32_init_static(crc, algo, table)                                                                            \
    {                                                                                                                  \
        Crc32BasedAlgo algo_ = algo;                                                                                   \
        crc32_init_static_(crc, &algo_, table);                                                                        \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc64
*/
void crc64_init_static_(Crc64 *crc, const Crc64BasedAlgo *algo, uint64_t *table);
#define crc64_init_static(crc, algo, table)                                                                            \
    {                                                                                                                  \
        Crc64BasedAlgo algo_ = algo;                                                                                   \
        crc64_init_static_(crc, &algo_, table);                                                                        \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc8, таблица при этом будет создана динамически
*/
void crc8_init_(Crc8 *crc, const Crc8BasedAlgo *algo);
#define crc8_init(crc, algo)                                                                                           \
    {                                                                                                                  \
        Crc8BasedAlgo algo_ = algo;                                                                                    \
        crc8_init_(crc, &algo_);                                                                                       \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc16, таблица при этом будет создана динамически
*/
void crc16_init_(Crc16 *crc, const Crc16BasedAlgo *algo);
#define crc16_init(crc, algo)                                                                                          \
    {                                                                                                                  \
        Crc16BasedAlgo algo_ = algo;                                                                                   \
        crc16_init_(crc, &algo_);                                                                                      \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc32, таблица при этом будет создана динамически
*/
void crc32_init_(Crc32 *crc, const Crc32BasedAlgo *algo);
#define crc32_init(crc, algo)                                                                                          \
    {                                                                                                                  \
        Crc32BasedAlgo algo_ = algo;                                                                                   \
        crc32_init_(crc, &algo_);                                                                                      \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc64, таблица при этом будет создана динамически
*/
void crc64_init_(Crc64 *crc, const Crc64BasedAlgo *algo);
#define crc64_init(crc, algo)                                                                                          \
    {                                                                                                                  \
        Crc64BasedAlgo algo_ = algo;                                                                                   \
        crc64_init_(crc, &algo_);                                                                                      \
    }
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \brief Очистка памяти если crc инициализирован при помощи \ref crc8_init_
*/
void crc8_destroy(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \brief Очистка памяти если crc инициализирован при помощи \ref crc16_init_
*/
void crc16_destroy(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \brief Очистка памяти если crc инициализирован при помощи \ref crc32_init_
*/
void crc32_destroy(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \brief Очистка памяти если crc инициализирован при помощи \ref crc64_init_
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
uint8_t crc8_finalize(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc16_update. Также происходит очистка значения \ref Crc16::value и "объект" crc можно использовать для
    нового вычисления
*/
uint16_t crc16_finalize(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc32_update. Также происходит очистка значения \ref Crc32::value и "объект" crc можно использовать для
    нового вычисления
*/
uint32_t crc32_finalize(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc64_update. Также происходит очистка значения \ref Crc64::value и "объект" crc можно использовать для
    нового вычисления
*/
uint64_t crc64_finalize(Crc64 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
uint8_t crc8_checksum(Crc8 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
uint16_t crc16_checksum(Crc16 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
uint32_t crc32_checksum(Crc32 *crc, const void *bytes, size_t size);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
uint64_t crc64_checksum(Crc64 *crc, const void *bytes, size_t size);

#if CRC_HAS_128BIT_ALGO
/**
    \brief Спецификация алгоритма расчёта циклического избыточного кода ширины не более 128 бит
*/
typedef struct {
    int width; /**< Степень порождающего многочлена */
    uint128_t poly; /**< Порождающий многочлен */
    uint128_t init; /**< Стартовые данные */
    int refin; /**< Начало и направление вычислений */
    int refout; /**< Инвертируется ли порядок битов при складывании по модулю 2 полученного результата */
    uint128_t xorout; /**< Число, с которым складывается по модулю 2 полученный результат */
    uint128_t check; /**< Значение CRC для строки «123456789» */
} Crc128BasedAlgo;
/**
    \brief "Объект" для расчёта контрольной суммы ширины не более 128 бит
*/
typedef struct {
    Crc128BasedAlgo algo; /**< Алгоритм вычисления */
    const uint128_t *table; /**< Таблица для вычисления */
    uint128_t value; /**< Промежуточное значение контрольной суммы */
} Crc128;

/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc128
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc128
*/
void crc128_init_static_(Crc128 *crc, const Crc128BasedAlgo *algo, uint128_t *table);
#define crc128_init_static(crc, algo, table)                                                                           \
    {                                                                                                                  \
        Crc128BasedAlgo algo_ = algo;                                                                                  \
        crc128_init_static_(crc, &algo_, table);                                                                       \
    }
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc128
    \param[in] algo Каталожный алгоритм из файла crc/catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc128, таблица при этом будет создана динамически
*/
void crc128_init_(Crc128 *crc, const Crc128BasedAlgo *algo);
#define crc128_init(crc, algo)                                                                                         \
    {                                                                                                                  \
        Crc128BasedAlgo algo_ = algo;                                                                                  \
        crc128_init_(crc, &algo_);                                                                                     \
    }
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \brief Очистка памяти если crc инициализирован при помощи \ref crc128_init_
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
uint128_t crc128_finalize(Crc128 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc128
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест"
*/
uint128_t crc128_checksum(Crc128 *crc, const void *bytes, size_t size);
#endif /* CRC_HAS_128BIT_ALGO */

#ifdef __cplusplus
}
#endif

#endif /* H_CRC_LIB */
