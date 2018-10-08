#include "emulagbor.h"


void cpu_setup(cpu_t *cpu)
{
    memset(cpu, 0, sizeof(*cpu));
    cpu_opcodes_setup(&(cpu->opcodes));
}
