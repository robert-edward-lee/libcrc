#ifndef HXX_CRCXX_LIB
#define HXX_CRCXX_LIB

#ifdef __has_builtin
#if __has_builtin(__builtin_convertvector) && defined(__clang__)
#define __has_builtin_bitreverse
#endif
#endif

#if __cpp_constexpr
#if __cpp_constexpr >= 201304
#define constexpr_14 constexpr
#else
#define constexpr_14 inline
#endif
#else
#define constexpr
#define constexpr_14 inline
#endif

#if __cplusplus < 201103
#define CRCXX_NOEXCEPT
template<typename T, T v> struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
    operator value_type() const {
        return value;
    }
};
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;
template<bool, typename T = void> struct enable_if {};
template<typename T> struct enable_if<true, T> {
    typedef T type;
};
template<typename T, typename U> struct is_same: false_type {};
template<typename T> struct is_same<T, T>: true_type {};

template<typename> struct is_byte: false_type {};
template<> struct is_byte<int8_t>: true_type {};
template<> struct is_byte<uint8_t>: true_type {};
#else
#define CRCXX_NOEXCEPT noexcept
template<bool Cond, typename T = void> using enable_if = std::enable_if<Cond, T>;
template<typename> struct is_byte: std::false_type {};
template<> struct is_byte<int8_t>: std::true_type {};
template<> struct is_byte<uint8_t>: std::true_type {};
#endif

namespace crc {

static constexpr_14 uint8_t rev(uint8_t x) CRCXX_NOEXCEPT {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse8(x);
#else
    x = ((x & 0x55) << 1) | ((x & 0xAA) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xCC) >> 2);
    return x << 4 | x >> 4;
#endif
}
static constexpr_14 uint16_t rev(uint16_t x) CRCXX_NOEXCEPT {
#ifdef __has_builtin_bitreverse
    return __builtin_bitreverse16(x);
#else
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    return x << 8 | x >> 8;
#endif
}
static constexpr_14 uint32_t rev(uint32_t x) CRCXX_NOEXCEPT {
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
static constexpr_14 uint64_t rev(uint64_t x) CRCXX_NOEXCEPT {
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
static constexpr_14 __uint128_t rev(__uint128_t x) CRCXX_NOEXCEPT {
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
class Crc {
#ifdef __SIZEOF_INT128__
    // static_assert(std::is_integral<ValueType>::value || std::is_same<ValueType, __uint128_t>::value,
    //               "ValueType must be an integral");
    // static_assert(sizeof(ValueType) <= sizeof(__uint128_t), "ValueType size can not exceed 128 bit yet");
#else
    // static_assert(std::is_integral<ValueType>::value, "ValueType must be an integral");
    static_assert(sizeof(ValueType) <= sizeof(uint64_t), "ValueType size can not exceed 64 bit yet");
#endif
    // static_assert(Width, "Width can not be a 0");
    // static_assert(Width <= 8 * sizeof(ValueType), "Crc Width can not exceed the bitwidth of ValueType");

public:
    typedef ValueType type;

    static const size_t real_width = 8 * sizeof(type);
    static const size_t width = Width;
    static const type poly = Poly;
    static const type init = Init;
    static const bool refin = RefIn;
    static const bool refout = RefOut;
    static const type xorout = XorOut;
    static const type check = Check;

    Crc(void): value(init_value(init)), table(new type[256]) {
        table_init();
    }

    ~Crc(void) {
        delete[] table;
    }

    type finalize(void) CRCXX_NOEXCEPT {
        type ret = value;
        value = init_value(init);

        if(refin != refout) {
            ret = rev(ret);
        }

        if(!refout) {
            ret >>= real_width - width;
        }

        return ret ^ xorout;
    }

    template<typename T> constexpr_14 typename enable_if<is_byte<T>::value>::type update(T byte) CRCXX_NOEXCEPT {
        if(real_width == 8) {
            value = table[value ^ byte];
        } else if(refin) {
            value = table[(value & 0xFF) ^ byte] ^ (value >> 8);
        } else {
            value = table[(value >> (real_width - 8)) ^ byte] ^ (value << 8);
        }
    }
    template<typename T>
    constexpr_14 typename enable_if<is_byte<T>::value, type>::type checksum(T byte) CRCXX_NOEXCEPT {
        update(byte);
        return finalize();
    }
    template<typename T>
    constexpr_14 typename enable_if<is_byte<T>::value, type>::type operator()(T byte) CRCXX_NOEXCEPT {
        return checksum(byte);
    }

    void update(const void *data, size_t size) CRCXX_NOEXCEPT {
        if(!data) {
            return;
        }

        for(size_t i = 0; i < size; i++) {
            update(reinterpret_cast<const uint8_t *>(data)[i]);
        }
    }
    constexpr_14 type checksum(const void *data, size_t size) CRCXX_NOEXCEPT {
        update(data, size);
        return finalize();
    }
    constexpr_14 type operator()(const void *data, size_t size) CRCXX_NOEXCEPT {
        return checksum(data, size);
    }

    void update(const void *begin, const void *end) CRCXX_NOEXCEPT {
        if(!begin) {
            return;
        }

        for(const uint8_t *byte = reinterpret_cast<const uint8_t *>(begin); byte < end; byte++) {
            update(*byte);
        }
    }
    constexpr_14 type checksum(const void *begin, const void *end) CRCXX_NOEXCEPT {
        update(begin, end);
        return finalize();
    }
    constexpr_14 type operator()(const void *begin, const void *end) CRCXX_NOEXCEPT {
        return checksum(begin, end);
    }

private:
    Crc(const Crc &);
    Crc &operator=(const Crc &);

    static constexpr type init_value(type init) CRCXX_NOEXCEPT {
        return refin ? rev(init) >> (real_width - width) : init << (real_width - width);
    }

    static constexpr_14 type crc(type value) CRCXX_NOEXCEPT {
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

    void table_init(void) CRCXX_NOEXCEPT {
        int i = 256;
        while(i--) {
            table[i] = crc(i);
        }
    }

    type value;
    type *table;
};

} // namespace crc

#endif // HXX_CRCXX_LIB
