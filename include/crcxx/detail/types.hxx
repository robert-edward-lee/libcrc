#ifndef HXX_CRCXX_DETAIL_TYPES
#define HXX_CRCXX_DETAIL_TYPES

#include "defines.hxx"

#if CRCXX_STDCXX_VERSION_CHECK(201103)
#include <cstdint>
#else
#include <stdint.h>
#endif

namespace crc {
#if CRCXX_STDCXX_VERSION_CHECK(201103)
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::size_t;
#else
using ::uint8_t;
using ::uint16_t;
using ::uint32_t;
using ::uint64_t;
using ::size_t;
#endif

#if CRCXX_HAS_128BIT_ALGO
typedef __uint128_t uint128_t;
#endif
} // namespace crc

#endif // HXX_CRCXX_DETAIL_TYPES
