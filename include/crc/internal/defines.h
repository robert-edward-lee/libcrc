/**
    \file defines.h
    \brief Макроопределения
*/
#ifndef H_CRC_INTERNAL_DEFINES
#define H_CRC_INTERNAL_DEFINES

/******************************************************************************/
/*                                   Utils                                    */
/******************************************************************************/
#define CRC_DO_CONCAT(a, b) a##b
#define CRC_CONCAT(a, b) CRC_DO_CONCAT(a, b)

#define CRC_DO_STR(s) #s
#define CRC_STR(s) CRC_DO_STR(s)

#define CRC_DO_EXPAND_INIT(width, poly, init, refin, refout, xorout, check, residue) \
    width, poly, init, refin, refout, xorout
#define CRC_EXPAND_INIT(algo) CRC_DO_EXPAND_INIT(algo)

#define CRC_DO_EXPAND_CHECK(width, poly, init, refin, refout, xorout, check, residue) check
#define CRC_EXPAND_CHECK(algo) CRC_DO_EXPAND_CHECK(algo)

/******************************************************************************/
/*                          Language Standard Detect                          */
/******************************************************************************/
#if defined(__STDC_VERSION__)
#define CRC_STDC_VERSION_CHECK(v) (__STDC_VERSION__ >= (v))
#elif defined(__STDC__)
#define CRC_STDC_VERSION_CHECK(v) (198912 >= (v))
#else
#define CRC_STDC_VERSION_CHECK(v) 0
#endif

#if defined(__cplusplus)
#if defined(_MSC_VER)
#define CRC_CXX_VERSION_CHECK(v) (_MSVC_LANG >= (v))
#else
#define CRC_CXX_VERSION_CHECK(v) (__cplusplus >= (v))
#endif
#else
#define CRC_CXX_VERSION_CHECK(v) 0
#endif

/******************************************************************************/
/*                            Compiler Detect Test                            */
/******************************************************************************/
#if defined(__GNUC__) && !defined(__clang__)
#define CRC_GCC_VERSION_VALUE(maj, min, patch) (10000 * (maj) + 100 * (min) + (patch))
#define CRC_GCC_VERSION_CURRENT CRC_GCC_VERSION_VALUE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#define CRC_GCC_VERSION_CHECK(maj, min, patch) (CRC_GCC_VERSION_CURRENT >= CRC_GCC_VERSION_VALUE(maj, min, patch))
#else
#define CRC_GCC_VERSION_CHECK(maj, min, patch) 0
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#define CRC_MSVC_VERSION_CHECK(v) (_MSC_VER >= (v))
#else
#define CRC_MSVC_VERSION_CHECK(v) 0
#endif

#if defined(__has_attribute)
#define CRC_HAS_ATTRIBUTE(a) __has_attribute(a)
#else
#define CRC_HAS_ATTRIBUTE(a) 0
#endif

#if defined(__has_builtin)
#define CRC_HAS_BUILTIN(a) __has_builtin(a)
#else
#define CRC_HAS_BUILTIN(a) 0
#endif

/******************************************************************************/
/*                           Language Feature-Test                            */
/******************************************************************************/
#if defined(__cplusplus) /* extern C */
#define CRC_EXTERN_C_BEGIN extern "C" {
#define CRC_EXTERN_C_END }
#define CRC_EXTERN_C extern "C"
#else
#define CRC_EXTERN_C_BEGIN
#define CRC_EXTERN_C_END
#define CRC_EXTERN_C
#endif /* extern C */

#if CRC_STDC_VERSION_CHECK(199901) || defined(__cplusplus) /* inline */
#define CRC_INLINE inline
#elif defined(__GNUC__) || defined(__clang__)
#define CRC_INLINE __inline__
#elif defined(_MSC_VER)
#define CRC_INLINE __inline
#else
#define CRC_INLINE
#endif /* inline */

#if CRC_GCC_VERSION_CHECK(3, 3, 0) || CRC_HAS_ATTRIBUTE(nothrow) /* noexcept */
#define CRC_NOTHROW __attribute__((nothrow))
#else
#define CRC_NOTHROW
#endif /* noexcept */

#if !defined(__cplusplus) /* static_assert */
#if CRC_STDC_VERSION_CHECK(202003)
#define CRC_STATIC_ASSERT(expr) static_assert(expr)
#define CRC_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)
#elif CRC_STDC_VERSION_CHECK(201112)
#define CRC_STATIC_ASSERT(expr) _Static_assert(expr, STR(expr))
#define CRC_STATIC_ASSERT_MSG(expr, msg) _Static_assert(expr, msg)
#else
#define CRC_MAKE_ASSERT_NAME(a) CRC_CONCAT(a, __COUNTER__)
#define CRC_STATIC_ASSERT(expr) typedef char CRC_MAKE_ASSERT_NAME(static_assertion_)[(expr) ? 1 : -1]
#define CRC_STATIC_ASSERT_MSG(expr, msg) CRC_STATIC_ASSERT(expr)
#endif
#else
#if CRC_CXX_VERSION_CHECK(201411)
#define CRC_STATIC_ASSERT(expr) static_assert(expr)
#define CRC_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)
#elif CRC_CXX_VERSION_CHECK(200410)
#define CRC_STATIC_ASSERT(expr) static_assert(expr, STR(expr))
#define CRC_STATIC_ASSERT_MSG(expr, msg) static_assert(expr, msg)
#else
#define CRC_MAKE_ASSERT_NAME(a) CRC_CONCAT(a, __COUNTER__)
#define CRC_STATIC_ASSERT(expr) typedef char CRC_MAKE_ASSERT_NAME(static_assertion_)[(expr) ? 1 : -1]
#define CRC_STATIC_ASSERT_MSG(expr, msg) CRC_STATIC_ASSERT(expr)
#endif
#endif /* static_assert */

/******************************************************************************/
/*                           Attribute Feature-Test                           */
/******************************************************************************/
#if CRC_GCC_VERSION_CHECK(3, 1, 0) || CRC_HAS_ATTRIBUTE(always_inline) /* always_inline */
#define CRC_ALWAYS_INLINE CRC_INLINE __attribute__((always_inline))
#elif CRC_MSVC_VERSION_CHECK(1200)
#define CRC_ALWAYS_INLINE CRC_INLINE __forceinline
#else
#define CRC_ALWAYS_INLINE CRC_INLINE
#endif /* always_inline */

/******************************************************************************/
/*                            Compiler Intrinsics                             */
/******************************************************************************/
#if CRC_HAS_BUILTIN(__builtin_convertvector) && defined(__clang__) /* bitreverse */
#define CRC_HAS_BUILTIN_BITREVERSE 1
#else
#define CRC_HAS_BUILTIN_BITREVERSE 0
#endif /* bitreverse */

#if CRC_GCC_VERSION_CHECK(2, 96, 0) || CRC_HAS_BUILTIN(__builtin_expect) /* likely */
#define CRC_LIKELY(a) __builtin_expect(!!(a), 1)
#define CRC_UNLIKELY(a) __builtin_expect(!!(a), 0)
#else
#define CRC_LIKELY(a) (a)
#define CRC_UNLIKELY(a) (a)
#endif /* likely */

#if defined(__SIZEOF_INT128__)
#define CRC_HAS_GNUC_INT128 1
#else
#define CRC_HAS_GNUC_INT128 0
#endif

#endif /* H_CRC_INTERNAL_DEFINES */
