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

#define CRC_EXPAND_INITIALIZER_LIST(width, poly, init, refin, refout, xorout, check) \
    width, poly, init, refin, refout, xorout, check
#define CRC_EXPAND_CHECK(width, poly, init, refin, refout, xorout, check) check

#define CRC_REFIN_TO_FLAGS(refin) (refin)
#define CRC_REFOUT_TO_FLAGS(refout) ((refout) << 1)
#define CRC_FLAGS_TO_REFIN(flags) ((flags) & 1)
#define CRC_FLAGS_TO_REFOUT(flags) ((flags) >> 1)

#define CRC_EXPAND_ALGO(width, poly, init, refin, refout, xorout, check) \
    {width, poly, init, CRC_REFIN_TO_FLAGS(refin) | CRC_REFOUT_TO_FLAGS(refout), xorout}

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

/******************************************************************************/
/*                           Language Feature-Test                            */
/******************************************************************************/
#if CRC_STDC_VERSION_CHECK(199901) || defined(__cplusplus)
#define CRC_INLINE inline
#elif defined(__GNUC__) || defined(__clang__)
#define CRC_INLINE __inline__
#elif defined(_MSC_VER)
#define CRC_INLINE __inline
#else
#define CRC_INLINE
#endif

/******************************************************************************/
/*                           Attribute Feature-Test                           */
/******************************************************************************/
#if defined(__has_attribute)
#define CRC_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
#define CRC_HAS_ATTRIBUTE(x) 0
#endif

#if CRC_GCC_VERSION_CHECK(3, 1, 0) || CRC_HAS_ATTRIBUTE(always_inline)
#define CRC_ALWAYS_INLINE CRC_INLINE __attribute__((always_inline))
#elif CRC_MSVC_VERSION_CHECK(1200)
#define CRC_ALWAYS_INLINE CRC_INLINE __forceinline
#else
#define CRC_ALWAYS_INLINE CRC_INLINE
#endif

/******************************************************************************/
/*                            Compiler Intrinsics                             */
/******************************************************************************/
#if !defined(__has_builtin)
#define __has_builtin(x) 0
#endif

#if __has_builtin(__builtin_convertvector) && defined(__clang__)
#define CRC_HAS_BUILTIN_BITREVERSE 1
#else
#define CRC_HAS_BUILTIN_BITREVERSE 0
#endif

#if defined(__SIZEOF_INT128__)
#define CRC_HAS_GNUC_INT128 1
#else
#define CRC_HAS_GNUC_INT128 0
#endif

#endif /* H_CRC_INTERNAL_DEFINES */
