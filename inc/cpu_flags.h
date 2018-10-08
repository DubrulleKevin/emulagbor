#ifndef HEADER_CPU_FLAGS
#define HEADER_CPU_FLAGS


#include "types.h"

#include "cpu.h"


void cpu_flags_set_z(cpu_t *cpu, bit_t bit);
bit_t cpu_flags_get_z(cpu_t *cpu);
void cpu_flags_set_n(cpu_t *cpu, bit_t bit);
bit_t cpu_flags_get_n(cpu_t *cpu);
void cpu_flags_set_h(cpu_t *cpu, bit_t bit);
bit_t cpu_flags_get_h(cpu_t *cpu);
void cpu_flags_set_c(cpu_t *cpu, bit_t bit);
bit_t cpu_flags_get_c(cpu_t *cpu);


#endif
