#ifndef H_CRC_BENCH
#define H_CRC_BENCH

#include <crc/catalog.h>
#include <crc/lib.h>

#define PICOBENCH_IMPLEMENT_WITH_MAIN
#include <picobench/picobench.hpp>

static const char bench_data[4096] = {0};

#define crc_bench(__algo) \
    void crc_bench_##__algo(picobench::state &s) { \
        CRC_CONCAT(crc_u, CRC_DO_EXPAND_RWIDTH __algo) value; \
        CRC_CONCAT(Crc, CRC_DO_EXPAND_RWIDTH __algo) *crc = \
            CRC_TRICAT(crc, CRC_DO_EXPAND_RWIDTH __algo, _init_)(CRC_EXPAND_CTOR(__algo)); \
        for(auto _: s) { \
            value = \
                CRC_TRICAT(crc, CRC_DO_EXPAND_RWIDTH __algo, _checksum)(crc, (void *)bench_data, sizeof(bench_data)); \
            (void)value; \
            (void)_; \
        } \
        CRC_TRICAT(crc, CRC_DO_EXPAND_RWIDTH __algo, _destroy)(crc); \
    } \
    PICOBENCH(crc_bench_##__algo).label(#__algo)

#endif /* H_CRC_BENCH */
