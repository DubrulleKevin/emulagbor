#include <assert.h>

#include "emulagbor.h"


int main(void)
{
    cpu_t cpu;

    /* Test SP */
    cpu_setup(&cpu);

    cpu_registers_set_sp(&cpu, 0x42fe);
    assert(cpu_registers_get_sp(&cpu) == 0x42fe);
    assert(cpu_registers_get_pc(&cpu) == 0);
    assert(cpu_registers_get_af(&cpu) == 0);
    assert(cpu_registers_get_bc(&cpu) == 0);
    assert(cpu_registers_get_de(&cpu) == 0);
    assert(cpu_registers_get_hl(&cpu) == 0);

    /* Test PC */
    cpu_setup(&cpu);

    cpu_registers_set_pc(&cpu, 0x42fe);
    assert(cpu_registers_get_pc(&cpu) == 0x42fe);
    assert(cpu_registers_get_sp(&cpu) == 0);
    assert(cpu_registers_get_af(&cpu) == 0);
    assert(cpu_registers_get_bc(&cpu) == 0);
    assert(cpu_registers_get_de(&cpu) == 0);
    assert(cpu_registers_get_hl(&cpu) == 0);
    
    /* Test AF */
    cpu_setup(&cpu);

    cpu_registers_set_a(&cpu, 0xab);
    cpu_registers_set_f(&cpu, 0x2e);
    assert(cpu_registers_get_a(&cpu) == 0xab);
    assert(cpu_registers_get_f(&cpu) == 0x2e);
    assert(cpu_registers_get_af(&cpu) == 0xab2e);
    cpu_registers_set_af(&cpu, 0x42fe);
    assert(cpu_registers_get_af(&cpu) == 0x42fe);
    assert(cpu_registers_get_a(&cpu) == 0x42);
    assert(cpu_registers_get_f(&cpu) == 0xfe);
    assert(cpu_registers_get_sp(&cpu) == 0);
    assert(cpu_registers_get_pc(&cpu) == 0);
    assert(cpu_registers_get_bc(&cpu) == 0);
    assert(cpu_registers_get_de(&cpu) == 0);
    assert(cpu_registers_get_hl(&cpu) == 0);

    /* Test BC */
    cpu_setup(&cpu);

    cpu_registers_set_b(&cpu, 0xab);
    cpu_registers_set_c(&cpu, 0x2e);
    assert(cpu_registers_get_b(&cpu) == 0xab);
    assert(cpu_registers_get_c(&cpu) == 0x2e);
    assert(cpu_registers_get_bc(&cpu) == 0xab2e);
    cpu_registers_set_bc(&cpu, 0x42fe);
    assert(cpu_registers_get_bc(&cpu) == 0x42fe);
    assert(cpu_registers_get_b(&cpu) == 0x42);
    assert(cpu_registers_get_c(&cpu) == 0xfe);
    assert(cpu_registers_get_sp(&cpu) == 0);
    assert(cpu_registers_get_pc(&cpu) == 0);
    assert(cpu_registers_get_af(&cpu) == 0);
    assert(cpu_registers_get_de(&cpu) == 0);
    assert(cpu_registers_get_hl(&cpu) == 0);

    /* Test DE */
    cpu_setup(&cpu);

    cpu_registers_set_d(&cpu, 0xab);
    cpu_registers_set_e(&cpu, 0x2e);
    assert(cpu_registers_get_d(&cpu) == 0xab);
    assert(cpu_registers_get_e(&cpu) == 0x2e);
    assert(cpu_registers_get_de(&cpu) == 0xab2e);
    cpu_registers_set_de(&cpu, 0x42fe);
    assert(cpu_registers_get_de(&cpu) == 0x42fe);
    assert(cpu_registers_get_d(&cpu) == 0x42);
    assert(cpu_registers_get_e(&cpu) == 0xfe);
    assert(cpu_registers_get_sp(&cpu) == 0);
    assert(cpu_registers_get_pc(&cpu) == 0);
    assert(cpu_registers_get_af(&cpu) == 0);
    assert(cpu_registers_get_bc(&cpu) == 0);
    assert(cpu_registers_get_hl(&cpu) == 0);

    /* Test HL */
    cpu_setup(&cpu);

    cpu_registers_set_h(&cpu, 0xab);
    cpu_registers_set_l(&cpu, 0x2e);
    assert(cpu_registers_get_h(&cpu) == 0xab);
    assert(cpu_registers_get_l(&cpu) == 0x2e);
    assert(cpu_registers_get_hl(&cpu) == 0xab2e);
    cpu_registers_set_hl(&cpu, 0x42fe);
    assert(cpu_registers_get_hl(&cpu) == 0x42fe);
    assert(cpu_registers_get_h(&cpu) == 0x42);
    assert(cpu_registers_get_l(&cpu) == 0xfe);
    assert(cpu_registers_get_sp(&cpu) == 0);
    assert(cpu_registers_get_pc(&cpu) == 0);
    assert(cpu_registers_get_a(&cpu) == 0);
    assert(cpu_registers_get_bc(&cpu) == 0);
    assert(cpu_registers_get_de(&cpu) == 0);

    return EXIT_SUCCESS;
}
