#ifndef HXX_CXX_INTERNAL_DEFINES
#define HXX_CXX_INTERNAL_DEFINES

#if defined(__cplusplus)
#if defined(_MSC_VER)
#define CRCXX_STDCXX_VERSION_CHECK(v) (_MSVC_LANG >= (v))
#else
#define CRCXX_STDCXX_VERSION_CHECK(v) (__cplusplus >= (v))
#endif
#else
#define CRCXX_STDCXX_VERSION_CHECK(v) 0
#endif

#if !defined(__has_builtin)
#define __has_builtin(x) 0
#endif

#if __has_builtin(__builtin_convertvector) && defined(__clang__)
#define CRCXX_HAS_BUILTIN_BITREVERSE 1
#else
#define CRCXX_HAS_BUILTIN_BITREVERSE 0
#endif

#if defined(__SIZEOF_INT128__)
#define CRCXX_HAS_128BIT_ALGO 1
#else
#define CRCXX_HAS_128BIT_ALGO 0
#endif

#if CRCXX_STDCXX_VERSION_CHECK(201103)
#define CRCXX_NOEXCEPT noexcept
#else
#define CRCXX_NOEXCEPT
#endif

#if defined(__cpp_constexpr)
#define CRCXX_CONSTEXPR constexpr
#if __cpp_constexpr >= 201304
#define CRCXX_CONSTEXPR_14 constexpr
#else
#define CRCXX_CONSTEXPR_14
#endif
#define CRCXX_CONST_OR_CONSTEXPR constexpr
#else
#define CRCXX_CONSTEXPR
#define CRCXX_CONSTEXPR_14
#define CRCXX_CONST_OR_CONSTEXPR const
#endif

#if CRCXX_STDCXX_VERSION_CHECK(200410)
#define CRCXX_STATIC_ASSERT static_assert
#else
#define CRCXX_CONCAT_(a, b) a##b
#define CRCXX_CONCAT(a, b) CRCXX_CONCAT_(a, b)
#define CRCXX_MAKE_ASSERT_NAME(a) CRCXX_CONCAT(a, __COUNTER__)
#define CRCXX_STATIC_ASSERT(expr, msg) typedef char CRCXX_MAKE_ASSERT_NAME(CRCXX_STATIC_ASSERTION_)[(expr) ? 1 : -1]
#endif

#endif // HXX_CXX_INTERNAL_DEFINES
