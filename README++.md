## Библиотека расчёта циклического избыточного кода

### Требования
Компилятор с поддержкой стандарта **c++11**

### [Спецификации алгоритмов](./CATALOG.md)

### Пример использования
#### Вычисление суммы для блока памяти
```cpp
#include "crcxx/catalog.hpp"
#include "crcxx/crc.hpp"

char data[] = "123456789";
Crc<CRC16_ARC> crc;
uint16_t value;

// стандартное вычисление
value = crc.checksum(data, sizeof(data) - 1);
// тоже самое, но с помощью оператора ()
value = crc(data, sizeof(data) - 1);

// тоже самое, но используя стиль пары итераторов
value = crc.checksum(data, &data[9]);
value = crc(data, &data[9]);
```

#### Итеративного вычисления
```cpp
#include "crcxx/catalog.hpp"
#include "crcxx/crc.hpp"

char data[] = "123456789";
Crc<CRC16_ARC> crc;
uint16_t value;

for(int i = 0; i < sizeof(data); i++) {
    crc.update(data[i]);
}
value = crc.finalize();
```

#### Использование нестандартного алгоритма
```c
#include "crcxx/crc.hpp"

char data[] = "123456789";
Crc<ValueType, Width, Poly, Init, RefIn, RefOut, XorOut, Check> crc;
ValueType value = crc.checksum(data, sizeof(data) - 1);
```
