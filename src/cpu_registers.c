#include "emulagbor.h"


/* https://stackoverflow.com/questions/2100331/c-macro-definition-to-determine-big-endian-or-little-endian-machine */
static u_int_32_t endianness = 0xdeadbeef; 

enum endianness_t
{
    BIG_ENDIAN,
    LITTLE_ENDIAN
};

#define ENDIANNESS ((0x000000ff & endianness) == 0xef ? LITTLE_ENDIAN : BIG_ENDIAN)


u_int_16_t cpu_registers_get_sp(cpu_t *cpu)
{
    return cpu->registers.sp.v;
}

void cpu_registers_set_sp(cpu_t *cpu, u_int_16_t v)
{
    cpu->registers.sp.v = v;
}

u_int_16_t cpu_registers_get_pc(cpu_t *cpu)
{
    return cpu->registers.pc.v;
}

void cpu_registers_set_pc(cpu_t *cpu, u_int_16_t v)
{
    cpu->registers.pc.v = v;
}

u_int_16_t cpu_registers_get_af(cpu_t *cpu)
{
    return cpu->registers.af.v;
}

void cpu_registers_set_af(cpu_t *cpu, u_int_16_t v)
{
    cpu->registers.af.v = v;
}

u_int_16_t cpu_registers_get_bc(cpu_t *cpu)
{
    return cpu->registers.bc.v;
}

void cpu_registers_set_bc(cpu_t *cpu, u_int_16_t v)
{
    cpu->registers.bc.v = v;
}

u_int_16_t cpu_registers_get_de(cpu_t *cpu)
{
    return cpu->registers.de.v;
}

void cpu_registers_set_de(cpu_t *cpu, u_int_16_t v)
{
    cpu->registers.de.v = v;
}

u_int_16_t cpu_registers_get_hl(cpu_t *cpu)
{
    return cpu->registers.hl.v;
}

void cpu_registers_set_hl(cpu_t *cpu, u_int_16_t v)
{
    cpu->registers.hl.v = v;
}

u_int_8_t cpu_registers_get_a(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    {
        return cpu->registers.af.hl.h;
    }
    else
    {
        return cpu->registers.af.hl.l;
    }
}

void cpu_registers_set_a(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    {   
        cpu->registers.af.hl.h = v;
    }
    else
    {
        cpu->registers.af.hl.l = v;
    }
}

u_int_8_t cpu_registers_get_f(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.af.hl.l;
    }
    else
    {
        return cpu->registers.af.hl.h;
    }
}

void cpu_registers_set_f(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.af.hl.l = v;
    }
    else
    {
        cpu->registers.af.hl.h = v;
    }
}

u_int_8_t cpu_registers_get_b(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.bc.hl.h;
    }
    else
    {
        return cpu->registers.bc.hl.l;
    }
}

void cpu_registers_set_b(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.bc.hl.h = v;
    }
    else
    {
        cpu->registers.bc.hl.l = v;
    }
}

u_int_8_t cpu_registers_get_c(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.bc.hl.l;
    }
    else
    {
        return cpu->registers.bc.hl.h;
    }
}

void cpu_registers_set_c(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.bc.hl.l = v;
    }
    else
    {
        cpu->registers.bc.hl.h = v;
    }
}

u_int_8_t cpu_registers_get_d(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.de.hl.h;
    }
    else
    {
        return cpu->registers.de.hl.l;
    }
}

void cpu_registers_set_d(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.de.hl.h = v;
    }
    else
    {
        cpu->registers.de.hl.l = v;
    }
}

u_int_8_t cpu_registers_get_e(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.de.hl.l;
    }
    else
    {
        return cpu->registers.de.hl.h;
    }
}

void cpu_registers_set_e(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.de.hl.l = v;
    }
    else
    {
        cpu->registers.de.hl.h = v;
    }
}

u_int_8_t cpu_registers_get_h(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.hl.hl.h;
    }
    else
    {
        return cpu->registers.hl.hl.l;
    }
}

void cpu_registers_set_h(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.hl.hl.h = v;
    }
    else
    {
        cpu->registers.hl.hl.l = v;
    }
}

u_int_8_t cpu_registers_get_l(cpu_t *cpu)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        return cpu->registers.hl.hl.l;
    }
    else
    {
        return cpu->registers.hl.hl.h;
    }
}

void cpu_registers_set_l(cpu_t *cpu, u_int_8_t v)
{
    if (ENDIANNESS == BIG_ENDIAN)
    { 
        cpu->registers.hl.hl.l = v;
    }
    else
    {
        cpu->registers.hl.hl.h = v;
    }
}
