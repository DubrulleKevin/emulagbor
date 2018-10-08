#include "cpu.h"


void cpu_setup(cpu_t *cpu)
{
    cpu_registers_setup(&(cpu->registers));
    cpu_opcodes_setup(&(cpu->opcodes));
}
