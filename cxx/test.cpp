#include <cassert>
#include <iostream>

#include "crc.hpp"

using namespace try_2;

#define pr_expr(e) std::cout << #e << " = " << std::hex << e << std::endl

const char check_str[] = "123456789";

int main(void) {
    Crc<CRC5_USB> crc_usb;
    Crc<CRC10_GSM> crc_gsm;
    Crc<CRC14_DARC> crc_darc;
    Crc<CRC16_ARC> crc_arc;

    Crc<CrcAlgo<uint16_t, 11, 0x01, 0x0F, true, false, 0x11F, 0x5D>> crc_kek;

    assert(crc_usb.checksum(check_str, sizeof(check_str) - 1) == CRC5_USB::check);
    assert(crc_gsm.checksum(check_str, sizeof(check_str) - 1) == CRC10_GSM::check);
    assert(crc_darc.checksum(check_str, sizeof(check_str) - 1) == CRC14_DARC::check);
    assert(crc_arc.checksum(check_str, sizeof(check_str) - 1) == CRC16_ARC::check);

    printf("crc_usb = 0x%X\n", crc_usb.checksum(check_str, sizeof(check_str) - 1));
    printf("crc_gsm = 0x%X\n", crc_gsm.checksum(check_str, sizeof(check_str) - 1));
    printf("crc_darc = 0x%X\n", crc_darc.checksum(check_str, sizeof(check_str) - 1));
    printf("crc_arc = 0x%X\n", crc_arc.checksum(check_str, sizeof(check_str) - 1));

    printf("crc_kek = 0x%X\n", crc_kek.checksum(check_str, sizeof(check_str) - 1));

    return 0;
}
