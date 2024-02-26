#ifndef HPP_CRC
#define HPP_CRC

#include <memory>

#ifdef __has_builtin
#if __has_builtin(__builtin_convertvector) && defined(__clang__)
#define __has_builtin_bitreverse
#endif
#endif

#if __cpp_constexpr >= 201304
#define constexpr_14 constexpr
#else
#define constexpr_14 inline
#endif

namespace crc {

static constexpr_14 uint8_t rev(uint8_t x) noexcept {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse8(x);
#else
    x = ((x & 0x55) << 1) | ((x & 0xAA) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xCC) >> 2);
    return x << 4 | x >> 4;
#endif
}
static constexpr_14 uint16_t rev(uint16_t x) noexcept {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse16(x);
#else
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    return x << 8 | x >> 8;
#endif
}
static constexpr_14 uint32_t rev(uint32_t x) noexcept {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse32(x);
#else
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    return x << 16 | x >> 16;
#endif
}
static constexpr_14 uint64_t rev(uint64_t x) noexcept {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse64(x);
#else
    x = ((x & 0x5555555555555555) << 1) | ((x & 0xAAAAAAAAAAAAAAAA) >> 1);
    x = ((x & 0x3333333333333333) << 2) | ((x & 0xCCCCCCCCCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F0F0F0F0F) << 4) | ((x & 0xF0F0F0F0F0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF00FF00FF) << 8) | ((x & 0xFF00FF00FF00FF00) >> 8);
    x = ((x & 0x0000FFFF0000FFFF) << 16) | ((x & 0xFFFF0000FFFF0000) >> 16);
    return x << 32 | x >> 32;
#endif
}

#ifdef __SIZEOF_INT128__
static constexpr_14 __uint128_t rev(__uint128_t x) noexcept {
    return static_cast<__uint128_t>(rev(static_cast<uint64_t>(x))) << 64 | rev(static_cast<uint64_t>(x >> 64));
}
#endif

template<typename T> struct is_byte {
    static constexpr bool value = std::is_same<T, int8_t>::value || std::is_same<T, uint8_t>::value;
};

template<typename ValueType,
         size_t Width,
         ValueType Poly,
         ValueType Init,
         bool RefIn,
         bool RefOut,
         ValueType XorOut,
         ValueType Check>
class Crc {
#ifdef __SIZEOF_INT128__
    static_assert(std::is_integral<ValueType>::value || std::is_same<ValueType, __uint128_t>::value,
                  "ValueType must be an integral");
    static_assert(sizeof(ValueType) <= sizeof(__uint128_t), "ValueType size can not exceed 128 bit yet");
#else
    static_assert(std::is_integral<ValueType>::value, "ValueType must be an integral");
    static_assert(sizeof(ValueType) <= sizeof(uint64_t), "ValueType size can not exceed 64 bit yet");
#endif
    static_assert(Width, "Width can not be a 0");
    static_assert(Width <= 8 * sizeof(ValueType), "Crc Width can not exceed the bitwidth of ValueType");

public:
    using value_t = ValueType;

    static constexpr size_t real_width = 8 * sizeof(value_t);
    static constexpr size_t width = Width;
    static constexpr value_t poly = Poly;
    static constexpr value_t init = Init;
    static constexpr bool refin = RefIn;
    static constexpr bool refout = RefOut;
    static constexpr value_t xorout = XorOut;
    static constexpr value_t check = Check;

    Crc(void) noexcept: m_value(init_value(init)), m_table(new value_t[256]) {
        table_init();
    }

    value_t finalize(void) noexcept {
        value_t ret = m_value;
        m_value = init_value(init);

        if(refin != refout) {
            ret = rev(ret);
        }

        if(!refout) {
            ret >>= real_width - width;
        }

        return ret ^ xorout;
    }

    template<typename T> constexpr_14 typename std::enable_if<is_byte<T>::value>::type update(T byte) noexcept {
        if(real_width == 8) {
            m_value = m_table[m_value ^ byte];
        } else if(refin) {
            m_value = m_table[(m_value & 0xFF) ^ byte] ^ (m_value >> 8);
        } else {
            m_value = m_table[(m_value >> (real_width - 8)) ^ byte] ^ (m_value << 8);
        }
    }
    template<typename T> constexpr_14 typename std::enable_if<is_byte<T>::value>::type checksum(T byte) noexcept {
        update(byte);
        return finalize();
    }
    template<typename T> constexpr_14 typename std::enable_if<is_byte<T>::value>::type operator()(T byte) noexcept {
        return checksum(byte);
    }

    void update(const void *data, size_t size) noexcept {
        if(!data) {
            return;
        }

        for(size_t i = 0; i < size; i++) {
            update(reinterpret_cast<const uint8_t *>(data)[i]);
        }
    }
    constexpr_14 value_t checksum(const void *data, size_t size) noexcept {
        update(data, size);
        return finalize();
    }
    constexpr_14 value_t operator()(const void *data, size_t size) noexcept {
        return checksum(data, size);
    }

    void update(const void *begin, const void *end) noexcept {
        if(!begin) {
            return;
        }

        for(const uint8_t *byte = reinterpret_cast<const uint8_t *>(begin); byte < end; byte++) {
            update(*byte);
        }
    }
    constexpr_14 value_t checksum(const void *begin, const void *end) noexcept {
        update(begin, end);
        return finalize();
    }
    constexpr_14 value_t operator()(const void *begin, const void *end) noexcept {
        return checksum(begin, end);
    }

    Crc(const Crc &) = delete;
    Crc &operator=(const Crc &) = delete;

private:
    static constexpr value_t init_value(value_t init) noexcept {
        return refin ? rev(init) >> (real_width - width) : init << (real_width - width);
    }

    static constexpr_14 value_t crc(value_t value) noexcept {
        int i = 8;

        if(refin) {
            while(i--) {
                value = (value >> 1) ^ (init_value(poly) & -(value & 1));
            }
        } else {
            value <<= real_width - 8;
            while(i--) {
                value = (value << 1) ^ (init_value(poly) & -((value >> (real_width - 1)) & 1));
            }
        }

        return value;
    }

    void table_init(void) noexcept {
        int i = 256;
        while(i--) {
            m_table[i] = crc(i);
        }
    }

    value_t m_value;
    std::unique_ptr<value_t[]> m_table;
};

} // namespace crc

#endif // HPP_CRC
