#include "cpu_registers.h"


void cpu_registers_setup(cpu_registers_t *registers)
{
    memset(registers, 0, sizeof(*registers));
}
