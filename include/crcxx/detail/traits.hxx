#ifndef HXX_CXX_INTERNAL_TRAITS
#define HXX_CXX_INTERNAL_TRAITS

#include "defines.hxx"

#if CRCXX_STDCXX_VERSION_CHECK(201103)
#include <cstdint>
#else
#include <stdint.h>
#endif

namespace crc { namespace detail {
#if CRCXX_STDCXX_VERSION_CHECK(201103)
#include <type_traits>
template<bool Cond, typename T = void> using enable_if = std::enable_if<Cond, T>;
template<typename> struct is_byte: std::false_type {};
template<> struct is_byte<int8_t>: std::true_type {};
template<> struct is_byte<uint8_t>: std::true_type {};

template<typename T> struct is_valid_crc_type_helper: std::false_type {};
template<> struct is_valid_crc_type_helper<uint8_t>: std::true_type {};
template<> struct is_valid_crc_type_helper<uint16_t>: std::true_type {};
template<> struct is_valid_crc_type_helper<uint32_t>: std::true_type {};
template<> struct is_valid_crc_type_helper<uint64_t>: std::true_type {};
#if CRCXX_HAS_128BIT_ALGO
template<> struct is_valid_crc_type_helper<__uint128_t>: std::true_type {};
#endif
template<typename T> struct is_valid_crc_type: is_valid_crc_type_helper<typename std::remove_cv<T>::type> {};
#else
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

template<typename T> struct remove_cv {
    typedef T type;
};
template<typename T> struct remove_cv<const T> {
    typedef T type;
};
template<typename T> struct remove_cv<volatile T> {
    typedef T type;
};
template<typename T> struct remove_cv<const volatile T> {
    typedef T type;
};

template<typename T> struct is_valid_crc_type_helper: false_type {};
template<> struct is_valid_crc_type_helper<uint8_t>: true_type {};
template<> struct is_valid_crc_type_helper<uint16_t>: true_type {};
template<> struct is_valid_crc_type_helper<uint32_t>: true_type {};
template<> struct is_valid_crc_type_helper<uint64_t>: true_type {};
#if CRCXX_HAS_128BIT_ALGO
template<> struct is_valid_crc_type_helper<__uint128_t>: true_type {};
#endif
template<typename T> struct is_valid_crc_type: is_valid_crc_type_helper<typename remove_cv<T>::type> {};
#endif
}} // namespace crc::detail

#endif // HXX_CXX_INTERNAL_TRAITS
