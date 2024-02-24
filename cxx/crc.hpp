#ifndef HPP_CRC
#define HPP_CRC

#include <array>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>
#include <type_traits>

namespace crc {

#ifdef __has_builtin
#if __has_builtin(__builtin_convertvector) && defined(__clang__)
#define __has_builtin_bitreverse
#endif
#endif

static inline uint8_t rev(uint8_t x) noexcept {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse8(x);
#else
    x = ((x & 0x55) << 1) | ((x & 0xAA) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xCC) >> 2);
    return x << 4 | x >> 4;
#endif
}
static inline uint16_t rev(uint16_t x) noexcept {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse16(x);
#else
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    return x << 8 | x >> 8;
#endif
}
static inline uint32_t rev(uint32_t x) noexcept {
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
static inline uint64_t rev(uint64_t x) noexcept {
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
static inline __uint128_t rev(__uint128_t x) noexcept {
    return static_cast<__uint128_t>(rev(static_cast<uint64_t>(x))) << 64 | rev(static_cast<uint64_t>(x >> 64));
}
#endif

template<typename ValueType,
         size_t Width,
         ValueType Poly,
         ValueType Init,
         bool RefIn,
         bool RefOut,
         ValueType XorOut,
         ValueType Check>
struct CrcAlgo {
    static_assert(std::is_integral<ValueType>::value
#ifdef __SIZEOF_INT128__
                      || std::is_same<ValueType, __uint128_t>::value
#endif
                  ,
                  "ValueType must be integral");
#ifdef __SIZEOF_INT128__
    static_assert(sizeof(ValueType) <= sizeof(__uint128_t), "ValueType size can not exceed 128 bit yet");
#else
    static_assert(sizeof(ValueType) <= sizeof(uint64_t), "ValueType size can not exceed 64 bit yet");
#endif
    static_assert(Width, "Width can not be a 0");
    static_assert(Width <= 8 * sizeof(ValueType), "CrcAlgo Width can not exceed the bitwidth of ValueType");

    using value_t = ValueType;

    static constexpr size_t width = Width;
    static constexpr value_t poly = Poly;
    static constexpr value_t init = Init;
    static constexpr bool refin = RefIn;
    static constexpr bool refout = RefOut;
    static constexpr value_t xorout = XorOut;
    static constexpr value_t check = Check;
};

template<typename> struct isCrcAlgo_: public std::false_type {};
template<typename ValueType,
         size_t Width,
         ValueType Poly,
         ValueType Init,
         bool RefIn,
         bool RefOut,
         ValueType XorOut,
         ValueType Check>
struct isCrcAlgo_<CrcAlgo<ValueType, Width, Poly, Init, RefIn, RefOut, XorOut, Check>>: public std::true_type {};

template<typename CrcAlgoType> class Crc {
    static_assert(isCrcAlgo_<CrcAlgoType>::value, "CrcAlgoType must be an instance of the CrcAlgo");

public:
    using value_t = typename CrcAlgoType::value_t;

    Crc() noexcept: m_value(init_value(init)), m_table(new value_t[256]) {
        table_init();
    }

    void update(const void *data, size_t size) noexcept {
        if(!data || !size) {
            return;
        }

        const uint8_t *bytes = reinterpret_cast<const uint8_t *>(data);
        if(real_width == 8) {
            for(size_t i = 0; i < size; i++) {
                m_value = m_table[m_value ^ bytes[i]];
            }
        } else if(refin) {
            for(size_t i = 0; i < size; i++) {
                m_value = m_table[(m_value & 0xFF) ^ bytes[i]] ^ (m_value >> 8);
            }
        } else {
            for(size_t i = 0; i < size; i++) {
                m_value = m_table[(m_value >> (real_width - 8)) ^ bytes[i]] ^ (m_value << 8);
            }
        }
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

    value_t checksum(const void *data, size_t size) noexcept {
        update(data, size);
        return finalize();
    }

    void print_table(void) const noexcept {
        printf("static const uint_t CRC_TABLE[256] = {\n");
        for(int i = 0; i < 256; i++) {
            printf("%s0x%0*X,%s", i % 8 ? "" : "    ", (unsigned)real_width / 4, m_table[i], (i + 1) % 8 ? " " : "\n");
        }
        printf("};\n");
    }

private:
    static constexpr size_t real_width = 8 * sizeof(value_t);
    static constexpr size_t width = CrcAlgoType::width;
    static constexpr value_t poly = CrcAlgoType::poly;
    static constexpr value_t init = CrcAlgoType::init;
    static constexpr bool refin = CrcAlgoType::refin;
    static constexpr bool refout = CrcAlgoType::refout;
    static constexpr value_t xorout = CrcAlgoType::xorout;
    static constexpr value_t check = CrcAlgoType::check;

    static constexpr value_t init_value(value_t init) noexcept {
        return refin ? rev(init) >> (real_width - width) : init << (real_width - width);
    }

    static value_t crc(value_t poly, value_t init) noexcept {
        int i = 8;

        if(refin) {
            while(i--) {
                init = (init >> 1) ^ (poly & -(init & 1));
            }
        } else {
            init <<= real_width - 8;
            while(i--) {
                init = (init << 1) ^ (poly & -((init >> (real_width - 1)) & 1));
            }
        }

        return init;
    }

    void table_init(void) noexcept {
        int i = 256;
        value_t real_poly = init_value(poly);
        while(i--) {
            m_table[i] = crc(real_poly, i);
        }
    }

    value_t m_value;
    std::unique_ptr<value_t[]> m_table;
};

} // namespace crc

#endif // HPP_CRC
