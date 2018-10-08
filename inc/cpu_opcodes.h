#ifndef HEADER_CPU_OPCODES
#define HEADER_CPU_OPCODES


#include "cpu_registers.h"


typedef struct cpu_opcode_t
{
    const char *mnemonic;
    void(*func)(cpu_registers_t *registers, void *memory, void *arguments);
    u_int_8_t length;
    u_int_8_t cycles[2];
    bit_t flag_z, flag_n, flag_h, flag_c;
} cpu_opcode_t;

typedef struct cpu_opcodes_t
{
    cpu_opcode_t up_opcodes[0x100];
    cpu_opcode_t cb_opcodes[0x100];
} cpu_opcodes_t;


void cpu_opcodes_setup(cpu_opcodes_t *opcodes);


#endif
