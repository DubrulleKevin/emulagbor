#ifndef HEADER_CPU_REGISTERS
#define HEADER_CPU_REGISTERS


#include <string.h>

#include "types.h"


typedef struct cpu_registers_t
{
    register_16_t sp, pc;
    register_8_t a, b, c, d, e, f, h, l;
} cpu_registers_t;


void cpu_registers_setup(cpu_registers_t *registers);


#endif
