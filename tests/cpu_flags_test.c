#include <assert.h>

#include "emulagbor.h"


int main(void)
{
    cpu_t cpu;

    /* Test C */

    cpu_setup(&cpu);

    cpu_flags_set_c(&cpu, ONE);
    assert(cpu_flags_get_c(&cpu) == ONE);
    assert(cpu_flags_get_h(&cpu) == ZERO);
    assert(cpu_flags_get_n(&cpu) == ZERO);
    assert(cpu_flags_get_z(&cpu) == ZERO);

    /* Test H */

    cpu_setup(&cpu);

    cpu_flags_set_h(&cpu, ONE);
    assert(cpu_flags_get_h(&cpu) == ONE);
    assert(cpu_flags_get_c(&cpu) == ZERO);
    assert(cpu_flags_get_n(&cpu) == ZERO);
    assert(cpu_flags_get_z(&cpu) == ZERO);

    /* Test N */

    cpu_setup(&cpu);

    cpu_flags_set_n(&cpu, ONE);
    assert(cpu_flags_get_n(&cpu) == ONE);
    assert(cpu_flags_get_h(&cpu) == ZERO);
    assert(cpu_flags_get_c(&cpu) == ZERO);
    assert(cpu_flags_get_z(&cpu) == ZERO);

    /* Test Z */

    cpu_setup(&cpu);

    cpu_flags_set_z(&cpu, ONE);
    assert(cpu_flags_get_z(&cpu) == ONE);
    assert(cpu_flags_get_h(&cpu) == ZERO);
    assert(cpu_flags_get_n(&cpu) == ZERO);
    assert(cpu_flags_get_c(&cpu) == ZERO);

    return EXIT_SUCCESS;
}
