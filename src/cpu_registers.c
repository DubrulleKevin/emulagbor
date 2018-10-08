#include "emulagbor.h"


register_16_t cpu_registers_get_sp(cpu_t *cpu)
{
    return cpu->sp;
}

void cpu_registers_set_sp(cpu_t *cpu, register_16_t v)
{
    cpu->sp = v;
}

register_16_t cpu_registers_get_pc(cpu_t *cpu)
{
    return cpu->pc;
}

void cpu_registers_set_pc(cpu_t *cpu, register_16_t v)
{
    cpu->pc = v;
}

register_16_t cpu_registers_get_af(cpu_t *cpu)
{
    return cpu->af;
}

void cpu_registers_set_af(cpu_t *cpu, register_16_t v)
{
    cpu->af = v;
}

register_16_t cpu_registers_get_bc(cpu_t *cpu)
{
    return cpu->bc;
}

void cpu_registers_set_bc(cpu_t *cpu, register_16_t v)
{
    cpu->bc = v;
}

register_16_t cpu_registers_get_de(cpu_t *cpu)
{
    return cpu->de;
}

void cpu_registers_set_de(cpu_t *cpu, register_16_t v)
{
    cpu->de = v;
}

register_16_t cpu_registers_get_hl(cpu_t *cpu)
{
    return cpu->hl;
}

void cpu_registers_set_lh(cpu_t *cpu, register_16_t v)
{
    cpu->hl = v;
}

register_8_t cpu_registers_get_a(cpu_t *cpu)
{
    return cpu->af.hl.h;
}

void cpu_registers_set_a(cpu_t *cpu, register_8_t v)
{
    cpu->af.hl.h = v;
}

register_8_t cpu_registers_get_f(cpu_t *cpu)
{
    return cpu->af.hl.l;
}

void cpu_registers_set_f(cpu_t *cpu, register_8_t v)
{
    cpu->af.hl.l = v;
}

register_8_t cpu_registers_get_b(cpu_t *cpu)
{
    return cpu->bc.hl.h;
}

void cpu_registers_set_b(cpu_t *cpu, register_8_t v)
{
    cpu->bc.hl.h = v;
}

register_8_t cpu_registers_get_c(cpu_t *cpu)
{
    return cpu->bc.hl.l;
}

void cpu_registers_set_c(cpu_t *cpu, register_8_t v)
{
    cpu->bc.hl.l = v;
}

register_8_t cpu_registers_get_d(cpu_t *cpu)
{
    return cpu->de.hl.h;
}

void cpu_registers_set_d(cpu_t *cpu, register_8_t v)
{
    cpu->de.hl.h = v;
}

register_8_t cpu_registers_get_e(cpu_t *cpu)
{
    return cpu->de.hl.l;
}

void cpu_registers_set_e(cpu_t *cpu, register_8_t v)
{
    cpu->de.hl.l = v;
}

register_8_t cpu_registers_get_h(cpu_t *cpu)
{
    return cpu->hl.hl.h;
}

void cpu_registers_set_h(cpu_t *cpu, register_8_t v)
{
    cpu->hl.hl.h = v;
}

register_8_t cpu_registers_get_l(cpu_t *cpu)
{
    return cpu->hl.hl.l;
}

void cpu_registers_set_l(cpu_t *cpu, register_8_t v)
{
    cpu->hl.hl.l = v;
}
