#ifndef H_CRC_BENCH
#define H_CRC_BENCH

const volatile char bench_data[4096] = {0};

#define crc_bench(__algo, __width) \
    void crc_bench_##__algo(picobench::state &s) { \
        crc_u##__width value; \
        Crc##__width *crc = crc##__width##_init_(CRC_DO_EXPAND_INIT(__algo)); \
        for(auto _: s) { \
            value = crc##__width##_checksum(crc, (void *)bench_data, sizeof(bench_data)); \
            (void)value; \
            (void)_; \
        } \
        crc##__width##_destroy(crc); \
    } \
    PICOBENCH(crc_bench_##__algo).label(#__algo)

#endif /* H_CRC_BENCH */
