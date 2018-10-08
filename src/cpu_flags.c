#include "cpu_flags.h"


void cpu_flags_set_z(cpu_t *cpu, bit_t bit)
{
    register_8_t *flags = &(cpu->registers.f);
    *flags = (*flags & 0x7f) + (bit << 7); /* 0x7f = 0b01111111 */
}

bit_t cpu_flags_get_z(cpu_t *cpu)
{
    register_8_t *flags = &(cpu->registers.f);
    return (*flags & 0x80) >> 7; /* 0x80 = 0b10000000 */
}

void cpu_flags_set_n(cpu_t *cpu, bit_t bit)
{
    register_8_t *flags = &(cpu->registers.f);
    *flags = (*flags & 0xbf) + (bit << 6); /* 0xbf = 0b10111111 */
}

bit_t cpu_flags_get_n(cpu_t *cpu)
{
    register_8_t *flags = &(cpu->registers.f);
    return (*flags & 0x40) >> 6; /* 0x40 = 0b01000000 */
}

void cpu_flags_set_h(cpu_t *cpu, bit_t bit)
{
    register_8_t *flags = &(cpu->registers.f);
    *flags = (*flags & 0xbf) + (bit << 5); /* 0xdf = 0b11011111 */
}

bit_t cpu_flags_get_h(cpu_t *cpu)
{
    register_8_t *flags = &(cpu->registers.f);
    return (*flags & 0x20) >> 5; /* 0x20 = 0b00100000 */
}

void cpu_flags_set_c(cpu_t *cpu, bit_t bit)
{
    register_8_t *flags = &(cpu->registers.f);
    *flags = (*flags & 0xef) + (bit << 4); /* 0xef = 0b11101111 */
}

bit_t cpu_flags_get_c(cpu_t *cpu)
{
    register_8_t *flags = &(cpu->registers.f);
    return (*flags & 0x10) >> 4; /* 0x10 = 0b00010000 */
}
