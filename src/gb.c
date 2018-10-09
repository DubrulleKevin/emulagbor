#include "emulagbor.h"


void gb_setup(gb_t *gb)
{
    memset(gb->memory, 0, sizeof(*(gb->memory)));
    cpu_setup(&(gb->cpu));
}

void gb_run_up_opcode(gb_t *gb, u_int_8_t opcode, u_int_8_t *a)
{
    gb->cpu.opcodes.up[opcode].func(&(gb->cpu), gb->memory, a);
}

void gb_run_cb_opcode(gb_t *gb, u_int_8_t opcode, u_int_8_t *a)
{
    gb->cpu.opcodes.cb[opcode].func(&(gb->cpu), gb->memory, a);
}
