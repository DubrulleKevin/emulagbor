#include "emulagbor.h"


u_int_16_t bits_utils_2_bytes_array_to_word(u_int_8_t *a)
{
    return (a[1] << 8) + a[0];
}
