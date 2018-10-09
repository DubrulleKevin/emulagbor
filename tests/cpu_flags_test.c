#include <assert.h>

#include "emulagbor.h"


int main(void)
{
    cpu_t cpu;

    /* Test C */
    cpu_setup(&cpu);

    cpu_flags_set_c(&cpu, TRUE);
    assert(cpu_flags_get_c(&cpu) == TRUE);
    assert(cpu_flags_get_h(&cpu) == FALSE);
    assert(cpu_flags_get_n(&cpu) == FALSE);
    assert(cpu_flags_get_z(&cpu) == FALSE);

    /* Test H */
    cpu_setup(&cpu);

    cpu_flags_set_h(&cpu, TRUE);
    assert(cpu_flags_get_h(&cpu) == TRUE);
    assert(cpu_flags_get_c(&cpu) == FALSE);
    assert(cpu_flags_get_n(&cpu) == FALSE);
    assert(cpu_flags_get_z(&cpu) == FALSE);

    /* Test N */
    cpu_setup(&cpu);

    cpu_flags_set_n(&cpu, TRUE);
    assert(cpu_flags_get_n(&cpu) == TRUE);
    assert(cpu_flags_get_h(&cpu) == FALSE);
    assert(cpu_flags_get_c(&cpu) == FALSE);
    assert(cpu_flags_get_z(&cpu) == FALSE);

    /* Test Z */
    cpu_setup(&cpu);

    cpu_flags_set_z(&cpu, TRUE);
    assert(cpu_flags_get_z(&cpu) == TRUE);
    assert(cpu_flags_get_h(&cpu) == FALSE);
    assert(cpu_flags_get_n(&cpu) == FALSE);
    assert(cpu_flags_get_c(&cpu) == FALSE);

    return EXIT_SUCCESS;
}
