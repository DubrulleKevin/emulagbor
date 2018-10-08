#include "emulagbor.h"


register_16_t cpu_registers_get_sp(cpu_t *cpu)
{
    return cpu->registers.sp;
}

void cpu_registers_set_sp(cpu_t *cpu, register_16_t v)
{
    cpu->registers.sp = v;
}

register_16_t cpu_registers_get_pc(cpu_t *cpu)
{
    return cpu->registers.pc;
}

void cpu_registers_set_pc(cpu_t *cpu, register_16_t v)
{
    cpu->registers.pc = v;
}

register_16_t cpu_registers_get_af(cpu_t *cpu)
{
    return cpu->registers.af;
}

void cpu_registers_set_af(cpu_t *cpu, register_16_t v)
{
    cpu->registers.af = v;
}

register_16_t cpu_registers_get_bc(cpu_t *cpu)
{
    return cpu->registers.bc;
}

void cpu_registers_set_bc(cpu_t *cpu, register_16_t v)
{
    cpu->registers.bc = v;
}

register_16_t cpu_registers_get_de(cpu_t *cpu)
{
    return cpu->registers.de;
}

void cpu_registers_set_de(cpu_t *cpu, register_16_t v)
{
    cpu->registers.de = v;
}

register_16_t cpu_registers_get_hl(cpu_t *cpu)
{
    return cpu->registers.hl;
}

void cpu_registers_set_lh(cpu_t *cpu, register_16_t v)
{
    cpu->registers.hl = v;
}

register_8_t cpu_registers_get_a(cpu_t *cpu)
{
    return cpu->registers.af.hl.h;
}

void cpu_registers_set_a(cpu_t *cpu, register_8_t v)
{
    cpu->registers.af.hl.h = v;
}

register_8_t cpu_registers_get_f(cpu_t *cpu)
{
    return cpu->registers.af.hl.l;
}

void cpu_registers_set_f(cpu_t *cpu, register_8_t v)
{
    cpu->registers.af.hl.l = v;
}

register_8_t cpu_registers_get_b(cpu_t *cpu)
{
    return cpu->registers.bc.hl.h;
}

void cpu_registers_set_b(cpu_t *cpu, register_8_t v)
{
    cpu->registers.bc.hl.h = v;
}

register_8_t cpu_registers_get_c(cpu_t *cpu)
{
    return cpu->registers.bc.hl.l;
}

void cpu_registers_set_c(cpu_t *cpu, register_8_t v)
{
    cpu->registers.bc.hl.l = v;
}

register_8_t cpu_registers_get_d(cpu_t *cpu)
{
    return cpu->registers.de.hl.h;
}

void cpu_registers_set_d(cpu_t *cpu, register_8_t v)
{
    cpu->registers.de.hl.h = v;
}

register_8_t cpu_registers_get_e(cpu_t *cpu)
{
    return cpu->registers.de.hl.l;
}

void cpu_registers_set_e(cpu_t *cpu, register_8_t v)
{
    cpu->registers.de.hl.l = v;
}

register_8_t cpu_registers_get_h(cpu_t *cpu)
{
    return cpu->registers.hl.hl.h;
}

void cpu_registers_set_h(cpu_t *cpu, register_8_t v)
{
    cpu->registers.hl.hl.h = v;
}

register_8_t cpu_registers_get_l(cpu_t *cpu)
{
    return cpu->registers.hl.hl.l;
}

void cpu_registers_set_l(cpu_t *cpu, register_8_t v)
{
    cpu->registers.hl.hl.l = v;
}
