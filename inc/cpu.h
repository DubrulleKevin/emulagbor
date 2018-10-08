#ifndef HEADER_CPU
#define HEADER_CPU


#include "cpu_opcodes.h"


typedef struct
{
    cpu_opcodes_t opcodes;
    cpu_registers_t registers;
} cpu_t;


void cpu_setup(cpu_t *cpu);


#endif
