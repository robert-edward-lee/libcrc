#ifndef HXX_CRCXX_DETAIL_TYPES
#define HXX_CRCXX_DETAIL_TYPES

#include "defines.hxx"

namespace crc {
#if CRCXX_STDCXX_VERSION_CHECK(201103)
#include <cstdint>
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::size_t;
#else
#include <stdint.h>
#endif

#if CRCXX_HAS_128BIT_ALGO
typedef __uint128_t uint128_t;
#endif
} // namespace crc

#endif // HXX_CRCXX_DETAIL_TYPES
