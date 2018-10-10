#include "emulagbor.h"


u_int_16_t bits_utils_2_bytes_array_to_word(u_int_8_t *a)
{
    return (a[1] << 8) + a[0];
}

u_int_8_t bits_utils_get_msb_from_word(u_int_16_t w)
{
    return w >> 8;
}

u_int_8_t bits_utils_get_lsb_from_word(u_int_16_t w)
{
    return (u_int_8_t)w;
}
