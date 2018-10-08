#ifndef HEADER_EMULAGBOR
#define HEADER_EMULAGBOR


#include <limits.h>
#include <string.h> /* For memset */


/* TYPES */


/* Inspired from SFML code. */
#if UCHAR_MAX == 0xFF
    typedef char int_8_t;
    typedef unsigned char u_int_8_t;
#else
    #error No 8 bits integer type for this platform
#endif
#if USHRT_MAX == 0xFFFF
    typedef short int_16_t;
    typedef unsigned short u_int_16_t;
#elif UINT_MAX == 0xFFFF
    typedef int int_16_t;
    typedef unsigned int u_int_16_t;
#elif ULONG_MAX == 0xFFFF
    typedef long int_16_t;
    typedef unsigned long u_int_16_t;
#else
    #error No 16 bits integer type for this platform
#endif
#if USHRT_MAX == 0xFFFFFFFF
    typedef short int_32_t;
    typedef unsigned short u_int_32_t;
#elif UINT_MAX == 0xFFFFFFFF
    typedef int int_32_t;
    typedef unsigned int u_int_32_t;
#elif ULONG_MAX == 0xFFFFFFFF
    typedef long int_32_t;
    typedef unsigned long u_int_32_t;
#else
    #error No 32 bits integer type for this platform
#endif

typedef u_int_8_t register_8_t;
typedef union register_16_t register_16_t;
typedef struct cpu_t cpu_t;
typedef struct cpu_opcode_t cpu_opcode_t;
typedef struct cpu_opcodes_t cpu_opcodes_t;
typedef struct cpu_registers_t cpu_registers_t;

typedef enum bit_t
{
    ZERO,
    ONE,
    UNTOUCHED
} bit_t;

union register_16_t
{
    struct
    {
#ifdef __LITTLEENDIAN__
        u_int_8_t l;
        u_int_8_t h;
#else
        u_int_8_t h;
        u_int_8_t l;
#endif
    } hl;

    u_int_16_t v;
};

struct cpu_opcode_t
{
    const char *mnemonic;
    void(*func)(cpu_t *c, void *m, void *a);
    u_int_8_t length;
    u_int_8_t cycles[2];
    bit_t flag_z, flag_n, flag_h, flag_c;
};

struct cpu_opcodes_t
{
    cpu_opcode_t up_opcodes[0x100];
    cpu_opcode_t cb_opcodes[0x100];
};

struct cpu_registers_t
{
    register_16_t sp, pc, af, bc, de, hl;
};

struct cpu_t
{
    cpu_opcodes_t opcodes;
    cpu_registers_t registers;
};


/* PUBLIC FUNCTIONS */


void cpu_setup(cpu_t *cpu);
register_16_t cpu_registers_get_sp(cpu_t *cpu);
void cpu_registers_set_sp(cpu_t *cpu, register_16_t v);
register_16_t cpu_registers_get_pc(cpu_t *cpu);
void cpu_registers_set_pc(cpu_t *cpu, register_16_t v);
register_16_t cpu_registers_get_af(cpu_t *cpu);
void cpu_registers_set_af(cpu_t *cpu, register_16_t v);
register_16_t cpu_registers_get_bc(cpu_t *cpu);
void cpu_registers_set_bc(cpu_t *cpu, register_16_t v);
register_16_t cpu_registers_get_de(cpu_t *cpu);
void cpu_registers_set_de(cpu_t *cpu, register_16_t v);
register_16_t cpu_registers_get_hl(cpu_t *cpu);
void cpu_registers_set_lh(cpu_t *cpu, register_16_t v);
register_8_t cpu_registers_get_a(cpu_t *cpu);
void cpu_registers_set_a(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_f(cpu_t *cpu);
void cpu_registers_set_f(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_b(cpu_t *cpu);
void cpu_registers_set_b(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_c(cpu_t *cpu);
void cpu_registers_set_c(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_d(cpu_t *cpu);
void cpu_registers_set_d(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_e(cpu_t *cpu);
void cpu_registers_set_e(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_h(cpu_t *cpu);
void cpu_registers_set_h(cpu_t *cpu, register_8_t v);
register_8_t cpu_registers_get_l(cpu_t *cpu);
void cpu_registers_set_l(cpu_t *cpu, register_8_t v);

void cpu_opcodes_setup(cpu_opcodes_t *opcodes);

void cpu_flags_set_z(cpu_t *c, bit_t b);
bit_t cpu_flags_get_z(cpu_t *cpu);
void cpu_flags_set_n(cpu_t *c, bit_t b);
bit_t cpu_flags_get_n(cpu_t *cpu);
void cpu_flags_set_h(cpu_t *c, bit_t b);
bit_t cpu_flags_get_h(cpu_t *cpu);
void cpu_flags_set_c(cpu_t *c, bit_t b);
bit_t cpu_flags_get_c(cpu_t *cpu);


#endif
