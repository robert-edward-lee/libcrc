#ifndef HXX_INTERNAL_UTILS
#define HXX_INTERNAL_UTILS

#include "defines.hxx"

#if CRCXX_STDCXX_VERSION_CHECK(201103)
#include <cstdint>
#else
#include <stdint.h>
#endif

namespace crc { namespace detail {
static CRCXX_CONSTEXPR_14 uint8_t rev(uint8_t x) CRCXX_NOEXCEPT {
#if CRCXX_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse8(x);
#else
    x = ((x & 0x55) << 1) | ((x & 0xAA) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xCC) >> 2);
    return x << 4 | x >> 4;
#endif
}
static CRCXX_CONSTEXPR_14 uint16_t rev(uint16_t x) CRCXX_NOEXCEPT {
#if CRCXX_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse16(x);
#else
    x = ((x & 0x5555) << 1) | ((x & 0xAAAA) >> 1);
    x = ((x & 0x3333) << 2) | ((x & 0xCCCC) >> 2);
    x = ((x & 0x0F0F) << 4) | ((x & 0xF0F0) >> 4);
    return x << 8 | x >> 8;
#endif
}
static CRCXX_CONSTEXPR_14 uint32_t rev(uint32_t x) CRCXX_NOEXCEPT {
#if CRCXX_HAS_BUILTIN_BITREVERSE
    return __builtin_bitreverse32(x);
#else
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x00FF00FF) << 8) | ((x & 0xFF00FF00) >> 8);
    return x << 16 | x >> 16;
#endif
}
static CRCXX_CONSTEXPR_14 uint64_t rev(uint64_t x) CRCXX_NOEXCEPT {
#if CRCXX_HAS_BUILTIN_BITREVERSE
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

#if CRCXX_HAS_128BIT_ALGO
static CRCXX_CONSTEXPR_14 __uint128_t rev(__uint128_t x) CRCXX_NOEXCEPT {
    return static_cast<__uint128_t>(rev(static_cast<uint64_t>(x))) << 64 | rev(static_cast<uint64_t>(x >> 64));
}
#endif

}} // namespace crc::detail

#endif // HXX_INTERNAL_UTILS
