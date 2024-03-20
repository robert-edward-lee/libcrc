#ifndef HXX_CRCXX_INTERNAL_TYPES
#define HXX_CRCXX_INTERNAL_TYPES

#include "defines.hxx"

namespace crc {
#if CRCXX_STDCXX_VERSION_CHECK(201103)
#include <cstdint>
#else
#include <stdint.h>
#endif
} // namespace crc

#endif // HXX_CRCXX_INTERNAL_TYPES
