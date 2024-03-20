#ifndef H_CRC_INTERNAL_DEFINES
#define H_CRC_INTERNAL_DEFINES

#if defined(__STDC_VERSION__)
#define CRC_STDC_VERSION_CHECK(v) (__STDC_VERSION__ >= (v))
#else
#define CRC_STDC_VERSION_CHECK(v) 0
#endif

#if !defined(__has_builtin)
#define __has_builtin(x) 0
#endif

#if __has_builtin(__builtin_convertvector) && defined(__clang__)
#define CRC_HAS_BUILTIN_BITREVERSE 1
#else
#define CRC_HAS_BUILTIN_BITREVERSE 0
#endif

#if defined(__SIZEOF_INT128__)
#define CRC_HAS_128BIT_ALGO 1
#else
#define CRC_HAS_128BIT_ALGO 0
#endif

#if CRC_STDC_VERSION_CHECK(199901)
#define CRC_INLINE inline
#elif defined(__GNUC__)
#define CRC_INLINE __inline__
#elif defined(_MSC_VER)
#define CRC_INLINE __forceinline
#else
#define CRC_INLINE
#endif

#if CRC_STDC_VERSION_CHECK(202003)
#define CRC_STATIC_ASSERT static_assert
#elif CRC_STDC_VERSION_CHECK(201112)
#define CRC_STATIC_ASSERT _Static_assert
#else
#define CRC_CONCAT_(a, b) a##b
#define CRC_CONCAT(a, b) CRC_CONCAT_(a, b)
#define CRC_MAKE_ASSERT_NAME(a) CRC_CONCAT(a, __COUNTER__)
#define CRC_STATIC_ASSERT(expr, msg) typedef char CRC_MAKE_ASSERT_NAME(CRC_STATIC_ASSERTION_)[(expr) ? 1 : -1]
#endif

#define CRC_EXPAND_INITIALIZER_LIST(...) __VA_ARGS__

#endif /* H_CRC_INTERNAL_DEFINES */
