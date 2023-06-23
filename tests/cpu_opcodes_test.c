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
    assert(cpu_flags_are(cpu, FALSE, FALSE, FALSE, FALSE));

    /* Test up_0x02 */
    gb_setup(&gb);
    cpu_registers_set_bc(cpu, 0x00aa);
    cpu_registers_set_a(cpu, 0x42);
    gb_run_up_opcode(&gb, 0x02, NULL);
    assert(gb.memory[0xff00 + cpu_registers_get_bc(cpu)] == 0x42);
    assert(cpu_flags_are(cpu, FALSE, FALSE, FALSE, FALSE));

    /* Test up_0x03 */
    gb_setup(&gb);
    gb_run_up_opcode(&gb, 0x03, NULL);
    assert(cpu_registers_get_bc(cpu) == 0x0001);
    assert(cpu_flags_are(cpu, FALSE, FALSE, FALSE, FALSE));

    /* Test up_0x04 */
    gb_setup(&gb);
    gb_run_up_opcode(&gb, 0x04, NULL);
    assert(cpu_registers_get_b(cpu) == 0x01);
    assert(cpu_flags_are(cpu, FALSE, FALSE, FALSE, FALSE));
    cpu_registers_set_b(cpu, 0xff);
    gb_run_up_opcode(&gb, 0x04, NULL);
    assert(cpu_registers_get_b(cpu) == 0x00);
    assert(cpu_flags_are(cpu, TRUE, FALSE, FALSE, FALSE));
    cpu_registers_set_b(cpu, 0x0f);
    gb_run_up_opcode(&gb, 0x04, NULL);
    assert(cpu_registers_get_b(cpu) == 0x10);
    assert(cpu_flags_are(cpu, FALSE, FALSE, TRUE, FALSE));

    /* Test up_0x05 */
    gb_setup(&gb);
    cpu_registers_set_b(cpu, 0x02);
    gb_run_up_opcode(&gb, 0x05, NULL);
    assert(cpu_registers_get_b(cpu) == 0x01);
    assert(cpu_flags_are(cpu, FALSE, TRUE, FALSE, FALSE));
    cpu_registers_set_b(cpu, 0x01);
    gb_run_up_opcode(&gb, 0x05, NULL);
    assert(cpu_registers_get_b(cpu) == 0x00);
    assert(cpu_flags_are(cpu, TRUE, TRUE, FALSE, FALSE));
    cpu_registers_set_b(cpu, 0x10);
    gb_run_up_opcode(&gb, 0x05, NULL);
    assert(cpu_registers_get_b(cpu) == 0x0f);
    assert(cpu_flags_are(cpu, FALSE, TRUE, TRUE, FALSE));

    /* Test up_0x06 */
    gb_setup(&gb);
    a[0] = 0x2e;
    gb_run_up_opcode(&gb, 0x06, a);
    assert(cpu_registers_get_b(cpu) == 0x2e);

    /* Test up_0x07 */
    gb_setup(&gb);
    cpu_registers_set_a(cpu, 0x01);
    gb_run_up_opcode(&gb, 0x07, NULL);
    assert(cpu_registers_get_a(cpu) == 0x02);
    assert(cpu_flags_get_c(cpu) == FALSE);
    cpu_registers_set_a(cpu, 0xf0);
    gb_run_up_opcode(&gb, 0x07, NULL);
    assert(cpu_registers_get_a(cpu) == 0xe1);
    assert(cpu_flags_get_c(cpu) == TRUE);

    /* Test up_0x08 */
    gb_setup(&gb);
    cpu_registers_set_sp(cpu, 0x1234);
    a[0] = 0x45;
    a[1] = 0x67;
    gb_run_up_opcode(&gb, 0x08, a);
    assert(gb.memory[0x6745] == 0x34);
    assert(gb.memory[0x6746] == 0x12);

    /* Test up_0x09 */
    gb_setup(&gb);
    cpu_registers_set_hl(cpu, 0x0001);
    cpu_registers_set_bc(cpu, 0x1234);
    gb_run_up_opcode(&gb, 0x09, NULL);
    assert(cpu_registers_get_hl(cpu) == 0x1235);
    assert(cpu_flags_get_c(cpu) == FALSE);
    assert(cpu_flags_get_h(cpu) == FALSE);
    assert(cpu_flags_get_n(cpu) == FALSE);
    cpu_registers_set_hl(cpu, 0x1000);
    cpu_registers_set_bc(cpu, 0xf000);
    gb_run_up_opcode(&gb, 0x09, NULL);
    assert(cpu_registers_get_hl(cpu) == 0x0000);
    assert(cpu_flags_get_c(cpu) == TRUE);
    assert(cpu_flags_get_h(cpu) == FALSE);
    assert(cpu_flags_get_n(cpu) == FALSE);
    cpu_registers_set_hl(cpu, 0x0f00);
    cpu_registers_set_bc(cpu, 0x0100);
    gb_run_up_opcode(&gb, 0x09, NULL);
    assert(cpu_registers_get_hl(cpu) == 0x1000);
    assert(cpu_flags_get_c(cpu) == FALSE);
    assert(cpu_flags_get_h(cpu) == TRUE);
    assert(cpu_flags_get_n(cpu) == FALSE);
    cpu_registers_set_hl(cpu, 0x0001);
    cpu_registers_set_bc(cpu, 0xffff);
    gb_run_up_opcode(&gb, 0x09, NULL);
    assert(cpu_registers_get_hl(cpu) == 0x0000);
    assert(cpu_flags_get_c(cpu) == TRUE);
    assert(cpu_flags_get_h(cpu) == TRUE);
    assert(cpu_flags_get_n(cpu) == FALSE);

    /* Test up_0x0A */
    gb_setup(&gb);
    gb.memory[0x5555] = 0x77;
    cpu_registers_set_bc(cpu, 0x5555);
    gb_run_up_opcode(&gb, 0x0a, NULL);
    assert(cpu_registers_get_a(cpu) == 0x77);


    return EXIT_SUCCESS;
}
