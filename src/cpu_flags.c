#include "emulagbor.h"


void cpu_flags_set_z(cpu_t *c, bool_t b)
{
    u_int_8_t v = (cpu_registers_get_f(c) & 0x7f) + ((!b) << 7); /* 0x7f = 0b01111111 */
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_z(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return !((v & 0x80) >> 7); /* 0x80 = 0b10000000 */
}

void cpu_flags_set_n(cpu_t *c, bool_t b)
{
    u_int_8_t v = (cpu_registers_get_f(c) & 0xbf) + ((!b) << 6); /* 0xbf = 0b10111111 */
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_n(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return !((v & 0x40) >> 6); /* 0x40 = 0b01000000 */
}

void cpu_flags_set_h(cpu_t *c, bool_t b)
{
    u_int_8_t v = (cpu_registers_get_f(c) & 0xbf) + ((!b) << 5); /* 0xdf = 0b11011111 */
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_h(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return !((v & 0x20) >> 5); /* 0x20 = 0b00100000 */
}

void cpu_flags_set_c(cpu_t *c, bool_t b)
{
    u_int_8_t v = (cpu_registers_get_f(c) & 0xef) + ((!b) << 4); /* 0xef = 0b11101111 */
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_c(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return !((v & 0x10) >> 4); /* 0x10 = 0b00010000 */
}
