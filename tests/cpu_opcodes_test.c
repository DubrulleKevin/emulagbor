#include <assert.h>

#include "emulagbor.h"


int main(void)
{
    gb_t gb;
    cpu_t *cpu = &(gb.cpu);
    u_int_8_t a[2];

    /* Test up_0x01 */
    gb_setup(&gb);
    a[0] = 0x2e;
    a[1] = 0x58;
    gb_run_up_opcode(&gb, 0x01, a);
    assert(cpu_registers_get_bc(cpu) == 0x582e);

    /* Test up_0x02 */
    gb_setup(&gb);
    cpu_registers_set_bc(cpu, 0x00aa);
    cpu_registers_set_a(cpu, 0x42);
    gb_run_up_opcode(&gb, 0x02, NULL);
    assert(gb.memory[0xff00 + cpu_registers_get_bc(cpu)] == 0x42);

    /* Test up_0x03 */
    gb_setup(&gb);
    gb_run_up_opcode(&gb, 0x03, NULL);
    assert(cpu_registers_get_bc(cpu) == 1);

    /* Test up_0x04 */
    gb_setup(&gb);
    gb_run_up_opcode(&gb, 0x04, NULL);
    assert(cpu_registers_get_b(cpu) == 1);

    /* Test up_0x05 */
    gb_setup(&gb);
    cpu_registers_set_b(cpu, 1);
    gb_run_up_opcode(&gb, 0x05, NULL);
    assert(cpu_registers_get_b(cpu) == 0);

    /* Test up_0x06 */
    gb_setup(&gb);
    a[0] = 1;
    gb_run_up_opcode(&gb, 0x06, a);
    assert(cpu_registers_get_b(cpu) == 1);

    return EXIT_SUCCESS;
}
