#include "emulagbor.h"


void cpu_flags_set_z(cpu_t *c, bool_t b)
{
    u_int_8_t v = cpu_registers_get_f(c);
    b ? (v |= 0x80) : (v &= 0x7f);
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_z(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return (v & 0x80) >> 7;
}

void cpu_flags_set_n(cpu_t *c, bool_t b)
{
    u_int_8_t v = cpu_registers_get_f(c);
    b ? (v |= 0x40) : (v &= 0xbf);
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_n(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return (v & 0x40) >> 6;
}

void cpu_flags_set_h(cpu_t *c, bool_t b)
{
    u_int_8_t v = cpu_registers_get_f(c);
    b ? (v |= 0x20) : (v &= 0xdf);
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_h(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return (v & 0x20) >> 5;
}

void cpu_flags_set_c(cpu_t *c, bool_t b)
{
    u_int_8_t v = cpu_registers_get_f(c);
    b ? (v |= 0x10) : (v &= 0xef);
    cpu_registers_set_f(c, v);
}

bool_t cpu_flags_get_c(cpu_t *c)
{
    u_int_8_t v = cpu_registers_get_f(c);
    return (v & 0x10) >> 4;
}

bool_t cpu_flags_are(cpu_t *cpu, bool_t z, bool_t n, bool_t h, bool_t c)
{
    return (cpu_flags_get_z(cpu) == z) && (cpu_flags_get_n(cpu) == n) && \
           (cpu_flags_get_h(cpu) == h) && (cpu_flags_get_c(cpu) == c);
}
