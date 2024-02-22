#include <cassert>
#include <cinttypes>
#include <iostream>

#include "crc.hpp"

using namespace try_2;

#define pr_expr(e) std::cout << #e << " = " << std::hex << e << std::endl

const char check_str[] = "123456789";

#define print128(x) printf("0x%016" PRIX64 " << 64 | 0x%016" PRIX64 "\n", \
                   static_cast<uint64_t>(x >> 64), \
                   static_cast<uint64_t>(x));

int main(void) {
    Crc<CRC5_USB> crc_usb;
    Crc<CRC10_GSM> crc_gsm;
    Crc<CRC14_DARC> crc_darc;
    Crc<CRC16_ARC> crc_arc;

    Crc<CRC82_DARC> crc82_darc;

    Crc<CrcAlgo<uint16_t, 11, 0x01, 0x0F, true, false, 0x11F, 0x5D>> crc_kek;

    assert(crc_usb.checksum(check_str, sizeof(check_str) - 1) == CRC5_USB::check);
    assert(crc_gsm.checksum(check_str, sizeof(check_str) - 1) == CRC10_GSM::check);
    assert(crc_darc.checksum(check_str, sizeof(check_str) - 1) == CRC14_DARC::check);
    assert(crc_arc.checksum(check_str, sizeof(check_str) - 1) == CRC16_ARC::check);

    assert(crc82_darc.checksum(check_str, sizeof(check_str) - 1) == CRC82_DARC::check);

    printf("crc_usb = 0x%X\n", crc_usb.checksum(check_str, sizeof(check_str) - 1));
    printf("crc_gsm = 0x%X\n", crc_gsm.checksum(check_str, sizeof(check_str) - 1));
    printf("crc_darc = 0x%X\n", crc_darc.checksum(check_str, sizeof(check_str) - 1));
    printf("crc_arc = 0x%X\n", crc_arc.checksum(check_str, sizeof(check_str) - 1));

    printf("crc82_darc = ");
    __uint128_t x = crc82_darc.checksum(check_str, sizeof(check_str) - 1);
    print128(x);

    printf("crc_kek = 0x%X\n", crc_kek.checksum(check_str, sizeof(check_str) - 1));

    return 0;
}
