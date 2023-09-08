/**
    \file lib.h
    \brief Интерфейс библиотеки расчёта циклического избыточного кода
*/
#ifndef H_CRC_LIB
#define H_CRC_LIB

#include <stddef.h>
#include <stdint.h>

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
    uint8_t residue;
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
    uint16_t residue;
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
    uint32_t residue;
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
    uint64_t residue;
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

#ifdef __cplusplus
extern "C" {
#endif
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc8
*/
void crc8_init_static(Crc8 *crc, const Crc8BasedAlgo *algo, uint8_t *table);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 2x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc16
*/
void crc16_init_static(Crc16 *crc, const Crc16BasedAlgo *algo, uint16_t *table);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 4x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc32
*/
void crc32_init_static(Crc32 *crc, const Crc32BasedAlgo *algo, uint32_t *table);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \param[in] table Предварительно выделенная память размером 8x256 байт для хранения таблицы расчёта
    \brief Инициализация "объекта" \ref Crc64
*/
void crc64_init_static(Crc64 *crc, const Crc64BasedAlgo *algo, uint64_t *table);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc8, таблица при этом будет создана динамически
*/
void crc8_init(Crc8 *crc, const Crc8BasedAlgo *algo);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc16
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc16, таблица при этом будет создана динамически
*/
void crc16_init(Crc16 *crc, const Crc16BasedAlgo *algo);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc32
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc32, таблица при этом будет создана динамически
*/
void crc32_init(Crc32 *crc, const Crc32BasedAlgo *algo);
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \brief Инициализация "объекта" \ref Crc64, таблица при этом будет создана динамически
*/
void crc64_init(Crc64 *crc, const Crc64BasedAlgo *algo);
/**
    \param[in,out] crc Экземпляр \ref Crc8
    \brief Очистка памяти если crc инициализирован при помощи \ref crc8_init
*/
void crc8_destroy(Crc8 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc16
    \brief Очистка памяти если crc инициализирован при помощи \ref crc16_init
*/
void crc16_destroy(Crc16 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc32
    \brief Очистка памяти если crc инициализирован при помощи \ref crc32_init
*/
void crc32_destroy(Crc32 *crc);
/**
    \param[in,out] crc Экземпляр \ref Crc64
    \brief Очистка памяти если crc инициализирован при помощи \ref crc64_init
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
#ifdef __cplusplus
}
#endif

#if __STDC_VERSION__ >= 201112L // Generics C11 support
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8, \ref Crc16, \ref Crc32 или \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \param[in] table Предварительно выделенная память нужного размера для хранения таблицы расчёта. Для \ref Crc8 256,
    для \ref Crc16 512, для \ref Crc32 1024 и для \ref Crc64 2048 байт соответственно
    \brief Инициализация "объекта" crc. Обёртка над функциями \ref crc8_init_static, \ref crc16_init_static, \ref
    crc32_init_static и \ref crc64_init_static. В зависимости от типа crc будет вызвана соответствующая функция
*/
#define crc_init_static(crc, algo, table) \
    _Generic((crc),                       \
        Crc8 *: crc8_init_static,         \
        Crc16 *: crc16_init_static,       \
        Crc32 *: crc32_init_static,       \
        Crc64 *: crc64_init_static)(crc, algo, table)
/**
    \param[in,out] crc Предварительно созданный экземпляр \ref Crc8, \ref Crc16, \ref Crc32 или \ref Crc64
    \param[in] algo Каталожный алгоритм из файла crc_catalog.h или свой собственный
    \brief Инициализация crc, таблица при этом будет создана динамически. Обёртка над функциями \ref crc8_init, \ref
    crc16_init, \ref crc32_init и \ref crc64_init. В зависимости от  типа crc будет вызвана соответствующая функция
*/
#define crc_init(crc, algo) \
    _Generic((crc), Crc8 *: crc8_init, Crc16 *: crc16_init, Crc32 *: crc32_init, Crc64 *: crc64_init)(crc, algo)
/**
    \param[in,out] crc Экземпляр \ref Crc8, \ref Crc16, \ref Crc32 или \ref Crc64
    \brief Очистка памяти если crc инициализирован при помощи \ref crc_init. Обёртка над функциями \ref crc8_destroy,
    \ref crc16_destroy, \ref crc32_destroy и \ref crc64_destroy. В зависимости от  типа crc будет вызвана
    соответствующая функция
*/
#define crc_destroy(crc) \
    _Generic((crc), Crc8 *: crc8_destroy, Crc16 *: crc16_destroy, Crc32 *: crc32_destroy, Crc64 *: crc64_destroy)(crc)
/**
    \param[in,out] crc Экземпляр \ref Crc8, \ref Crc16, \ref Crc32 или \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \brief Обновление промежуточного значения контрольной суммы в crc::value. Функция позволяет вычислять CRC
    итеративно. Обёртка над функциями \ref crc8_update, \ref crc16_update, \ref crc32_update и \ref crc64_update. В
    зависимости от  типа crc будет вызвана соответствующая функция
*/
#define crc_update(crc, bytes, size)                                                                                 \
    _Generic((crc), Crc8 *: crc8_update, Crc16 *: crc16_update, Crc32 *: crc32_update, Crc64 *: crc64_update)(crc,   \
                                                                                                              bytes, \
                                                                                                              size)
/**
    \param[in,out] crc Экземпляр \ref Crc8, \ref Crc16, \ref Crc32 или \ref Crc64
    \return Контрольная сумма
    \brief Функция возвращает конечное вычисленное значение контрольной суммы данных, предварительно вычисленных с
    помощью \ref crc_update. Также происходит очистка значения crc::value и "объект" crc можно использовать для
    нового вычисления. Обёртка над функциями \ref crc8_finalize, \ref crc16_finalize, \ref crc32_finalize и \ref
    crc64_finalize. В зависимости от  типа crc будет вызвана соответствующая функция
*/
#define crc_finalize(crc)                                                                                              \
    _Generic((crc), Crc8 *: crc8_finalize, Crc16 *: crc16_finalize, Crc32 *: crc32_finalize, Crc64 *: crc64_finalize)( \
        crc)
/**
    \param[in,out] crc Экземпляр \ref Crc8, \ref Crc16, \ref Crc32 или \ref Crc64
    \param[in] bytes Данные для вычисления
    \param size Размер данных
    \return Контрольная сумма
    \brief Вычисление контрольной суммы "за один присест". Обёртка над функциями \ref crc8_checksum, \ref
    crc16_checksum, \ref crc32_checksum и \ref crc64_checksum. В зависимости от  типа crc будет вызвана соответствующая
    функция
*/
#define crc_checksum(crc, bytes, size)                                                                                 \
    _Generic((crc), Crc8 *: crc8_checksum, Crc16 *: crc16_checksum, Crc32 *: crc32_checksum, Crc64 *: crc64_checksum)( \
        crc,                                                                                                           \
        bytes,                                                                                                         \
        size)

#endif // Generics C11 support

#endif // H_CRC_LIB
