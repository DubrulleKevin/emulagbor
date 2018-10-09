#include "emulagbor.h"


static void opcode_up_0x0_NOP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    cpu_registers_set_bc(c, bits_utils_2_bytes_array_to_word(a));
}

static void opcode_up_0x2_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    m[0xff00 + cpu_registers_get_bc(c)] = cpu_registers_get_a(c);
}

static void opcode_up_0x3_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    u_int_16_t rbc = cpu_registers_get_bc(c);
    rbc == 0xffff ? (rbc = 0) : (rbc += 1);
    cpu_registers_set_bc(c, rbc);
}

static void opcode_up_0x4_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    u_int_8_t rb = cpu_registers_get_b(c);
    rb == 0xff ? (rb = 0) : (rb += 1);
    cpu_flags_set_z(c, rb == 0);
    cpu_flags_set_h(c, (rb & 0xf) == 0xf);
    cpu_registers_set_b(c, rb);
}

static void opcode_up_0x5_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    u_int_8_t rb = cpu_registers_get_b(c);
    rb == 0 ? (rb = 0xff) : (rb -= 1);
    cpu_flags_set_z(c, rb == 0);
    cpu_flags_set_h(c, (rb & 0xf) == 0);
    cpu_flags_set_n(c, TRUE);
    cpu_registers_set_b(c, rb);
}

static void opcode_up_0x6_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    cpu_registers_set_b(c, a[0]);
}

static void opcode_up_0x7_RLCA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{
    u_int_8_t ra = cpu_registers_get_a(c);
    u_int_8_t fc = ra >> 7;
    cpu_flags_set_c(c, fc != 0);
    cpu_flags_set_z(c, FALSE);
    cpu_flags_set_h(c, FALSE);
    cpu_flags_set_n(c, FALSE);
    cpu_registers_set_a(c, (ra << 1) | fc);
}

static void opcode_up_0x8_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf_RRCA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x10_STOP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x11_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x12_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x13_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x14_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x15_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x16_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x17_RLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x18_JR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x19_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1b_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1c_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1d_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x1f_RRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x20_JR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x21_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x22_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x23_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x24_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x25_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x26_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x27_DAA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x28_JR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x29_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x2a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x2b_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x2c_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x2d_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x2e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x2f_CPL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x30_JR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x31_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x32_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x33_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x34_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x35_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x36_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x37_SCF(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x38_JR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x39_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x3a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x3b_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x3c_INC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x3d_DEC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x3e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x3f_CCF(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x40_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x41_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x42_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x43_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x44_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x45_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x46_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x47_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x48_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x49_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x4a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x4b_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x4c_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x4d_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x4e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x4f_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x50_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x51_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x52_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x53_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x54_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x55_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x56_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x57_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x58_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x59_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x5a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x5b_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x5c_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x5d_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x5e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x5f_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x60_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x61_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x62_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x63_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x64_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x65_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x66_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x67_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x68_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x69_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x6a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x6b_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x6c_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x6d_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x6e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x6f_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x70_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x71_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x72_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x73_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x74_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x75_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x76_HALT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x77_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x78_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x79_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x7a_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x7b_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x7c_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x7d_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x7e_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x7f_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x80_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x81_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x82_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x83_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x84_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x85_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x86_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x87_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x88_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x89_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x8a_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x8b_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x8c_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x8d_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x8e_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x8f_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x90_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x91_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x92_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x93_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x94_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x95_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x96_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x97_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x98_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x99_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9a_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9b_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9c_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9d_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9e_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0x9f_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa0_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa1_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa2_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa3_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa4_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa5_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa6_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa7_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa8_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xa9_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xaa_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xab_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xac_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xad_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xae_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xaf_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb0_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb1_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb2_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb3_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb4_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb5_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb6_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb7_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb8_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xb9_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xba_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xbb_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xbc_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xbd_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xbe_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xbf_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc0_RET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc1_POP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc2_JP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc3_JP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc4_CALL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc5_PUSH(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc6_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc7_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc8_RET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xc9_RET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xca_JP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xcb_PREFIX(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xcc_CALL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xcd_CALL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xce_ADC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xcf_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd0_RET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd1_POP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd2_JP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd4_CALL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd5_PUSH(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd6_SUB(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd7_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd8_RET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xd9_RETI(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xda_JP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xdc_CALL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xde_SBC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xdf_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe0_LDH(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe1_POP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe2_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe5_PUSH(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe6_AND(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe7_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe8_ADD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xe9_JP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xea_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xee_XOR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xef_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf0_LDH(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf1_POP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf2_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf3_DI(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf5_PUSH(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf6_OR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf7_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf8_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xf9_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xfa_LD(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xfb_EI(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xfe_CP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_up_0xff_RST(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x0_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7_RLC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf_RRC(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x10_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x11_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x12_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x13_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x14_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x15_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x16_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x17_RL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x18_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x19_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1a_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1b_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1c_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1d_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1e_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x1f_RR(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x20_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x21_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x22_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x23_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x24_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x25_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x26_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x27_SLA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x28_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x29_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2a_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2b_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2c_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2d_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2e_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x2f_SRA(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x30_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x31_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x32_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x33_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x34_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x35_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x36_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x37_SWAP(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x38_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x39_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3a_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3b_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3c_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3d_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3e_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x3f_SRL(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x40_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x41_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x42_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x43_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x44_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x45_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x46_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x47_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x48_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x49_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4a_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4b_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4c_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4d_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4e_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x4f_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x50_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x51_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x52_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x53_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x54_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x55_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x56_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x57_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x58_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x59_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5a_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5b_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5c_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5d_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5e_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x5f_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x60_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x61_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x62_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x63_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x64_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x65_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x66_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x67_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x68_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x69_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6a_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6b_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6c_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6d_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6e_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x6f_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x70_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x71_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x72_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x73_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x74_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x75_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x76_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x77_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x78_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x79_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7a_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7b_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7c_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7d_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7e_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x7f_BIT(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x80_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x81_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x82_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x83_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x84_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x85_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x86_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x87_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x88_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x89_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8a_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8b_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8c_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8d_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8e_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x8f_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x90_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x91_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x92_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x93_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x94_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x95_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x96_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x97_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x98_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x99_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9a_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9b_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9c_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9d_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9e_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0x9f_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa0_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa1_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa2_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa3_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa4_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa5_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa6_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa7_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa8_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xa9_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xaa_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xab_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xac_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xad_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xae_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xaf_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb0_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb1_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb2_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb3_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb4_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb5_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb6_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb7_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb8_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xb9_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xba_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xbb_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xbc_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xbd_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xbe_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xbf_RES(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc0_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc1_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc2_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc3_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc4_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc5_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc6_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc7_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc8_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xc9_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xca_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xcb_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xcc_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xcd_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xce_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xcf_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd0_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd1_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd2_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd3_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd4_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd5_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd6_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd7_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd8_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xd9_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xda_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xdb_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xdc_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xdd_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xde_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xdf_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe0_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe1_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe2_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe3_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe4_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe5_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe6_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe7_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe8_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xe9_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xea_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xeb_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xec_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xed_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xee_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xef_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf0_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf1_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf2_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf3_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf4_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf5_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf6_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf7_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf8_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xf9_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xfa_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xfb_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xfc_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xfd_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xfe_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}

static void opcode_cb_0xff_SET(cpu_t *c, u_int_8_t *m, u_int_8_t *a)
{

}


void cpu_opcodes_setup(cpu_opcodes_t *opcodes)
{
    (opcodes->up)[0x0].mnemonic = "NOP";
    (opcodes->up)[0x0].func = &opcode_up_0x0_NOP;
    (opcodes->up)[0x0].length = 1;
    (opcodes->up)[0x0].cycles[0] = 4;
    (opcodes->up)[0x0].cycles[1] = 4;

    (opcodes->up)[0x1].mnemonic = "LD BC,d16";
    (opcodes->up)[0x1].func = &opcode_up_0x1_LD;
    (opcodes->up)[0x1].length = 3;
    (opcodes->up)[0x1].cycles[0] = 12;
    (opcodes->up)[0x1].cycles[1] = 12;

    (opcodes->up)[0x2].mnemonic = "LD (BC),A";
    (opcodes->up)[0x2].func = &opcode_up_0x2_LD;
    (opcodes->up)[0x2].length = 1;
    (opcodes->up)[0x2].cycles[0] = 8;
    (opcodes->up)[0x2].cycles[1] = 8;

    (opcodes->up)[0x3].mnemonic = "INC BC";
    (opcodes->up)[0x3].func = &opcode_up_0x3_INC;
    (opcodes->up)[0x3].length = 1;
    (opcodes->up)[0x3].cycles[0] = 8;
    (opcodes->up)[0x3].cycles[1] = 8;

    (opcodes->up)[0x4].mnemonic = "INC B";
    (opcodes->up)[0x4].func = &opcode_up_0x4_INC;
    (opcodes->up)[0x4].length = 1;
    (opcodes->up)[0x4].cycles[0] = 4;
    (opcodes->up)[0x4].cycles[1] = 4;

    (opcodes->up)[0x5].mnemonic = "DEC B";
    (opcodes->up)[0x5].func = &opcode_up_0x5_DEC;
    (opcodes->up)[0x5].length = 1;
    (opcodes->up)[0x5].cycles[0] = 4;
    (opcodes->up)[0x5].cycles[1] = 4;

    (opcodes->up)[0x6].mnemonic = "LD B,d8";
    (opcodes->up)[0x6].func = &opcode_up_0x6_LD;
    (opcodes->up)[0x6].length = 2;
    (opcodes->up)[0x6].cycles[0] = 8;
    (opcodes->up)[0x6].cycles[1] = 8;

    (opcodes->up)[0x7].mnemonic = "RLCA";
    (opcodes->up)[0x7].func = &opcode_up_0x7_RLCA;
    (opcodes->up)[0x7].length = 1;
    (opcodes->up)[0x7].cycles[0] = 4;
    (opcodes->up)[0x7].cycles[1] = 4;

    (opcodes->up)[0x8].mnemonic = "LD";
    (opcodes->up)[0x8].func = &opcode_up_0x8_LD;
    (opcodes->up)[0x8].length = 3;
    (opcodes->up)[0x8].cycles[0] = 20;
    (opcodes->up)[0x8].cycles[1] = 20;

    (opcodes->up)[0x9].mnemonic = "ADD";
    (opcodes->up)[0x9].func = &opcode_up_0x9_ADD;
    (opcodes->up)[0x9].length = 1;
    (opcodes->up)[0x9].cycles[0] = 8;
    (opcodes->up)[0x9].cycles[1] = 8;

    (opcodes->up)[0xa].mnemonic = "LD";
    (opcodes->up)[0xa].func = &opcode_up_0xa_LD;
    (opcodes->up)[0xa].length = 1;
    (opcodes->up)[0xa].cycles[0] = 8;
    (opcodes->up)[0xa].cycles[1] = 8;

    (opcodes->up)[0xb].mnemonic = "DEC";
    (opcodes->up)[0xb].func = &opcode_up_0xb_DEC;
    (opcodes->up)[0xb].length = 1;
    (opcodes->up)[0xb].cycles[0] = 8;
    (opcodes->up)[0xb].cycles[1] = 8;

    (opcodes->up)[0xc].mnemonic = "INC";
    (opcodes->up)[0xc].func = &opcode_up_0xc_INC;
    (opcodes->up)[0xc].length = 1;
    (opcodes->up)[0xc].cycles[0] = 4;
    (opcodes->up)[0xc].cycles[1] = 4;

    (opcodes->up)[0xd].mnemonic = "DEC";
    (opcodes->up)[0xd].func = &opcode_up_0xd_DEC;
    (opcodes->up)[0xd].length = 1;
    (opcodes->up)[0xd].cycles[0] = 4;
    (opcodes->up)[0xd].cycles[1] = 4;

    (opcodes->up)[0xe].mnemonic = "LD";
    (opcodes->up)[0xe].func = &opcode_up_0xe_LD;
    (opcodes->up)[0xe].length = 2;
    (opcodes->up)[0xe].cycles[0] = 8;
    (opcodes->up)[0xe].cycles[1] = 8;

    (opcodes->up)[0xf].mnemonic = "RRCA";
    (opcodes->up)[0xf].func = &opcode_up_0xf_RRCA;
    (opcodes->up)[0xf].length = 1;
    (opcodes->up)[0xf].cycles[0] = 4;
    (opcodes->up)[0xf].cycles[1] = 4;

    (opcodes->up)[0x10].mnemonic = "STOP";
    (opcodes->up)[0x10].func = &opcode_up_0x10_STOP;
    (opcodes->up)[0x10].length = 2;
    (opcodes->up)[0x10].cycles[0] = 4;
    (opcodes->up)[0x10].cycles[1] = 4;

    (opcodes->up)[0x11].mnemonic = "LD";
    (opcodes->up)[0x11].func = &opcode_up_0x11_LD;
    (opcodes->up)[0x11].length = 3;
    (opcodes->up)[0x11].cycles[0] = 12;
    (opcodes->up)[0x11].cycles[1] = 12;

    (opcodes->up)[0x12].mnemonic = "LD";
    (opcodes->up)[0x12].func = &opcode_up_0x12_LD;
    (opcodes->up)[0x12].length = 1;
    (opcodes->up)[0x12].cycles[0] = 8;
    (opcodes->up)[0x12].cycles[1] = 8;

    (opcodes->up)[0x13].mnemonic = "INC";
    (opcodes->up)[0x13].func = &opcode_up_0x13_INC;
    (opcodes->up)[0x13].length = 1;
    (opcodes->up)[0x13].cycles[0] = 8;
    (opcodes->up)[0x13].cycles[1] = 8;

    (opcodes->up)[0x14].mnemonic = "INC";
    (opcodes->up)[0x14].func = &opcode_up_0x14_INC;
    (opcodes->up)[0x14].length = 1;
    (opcodes->up)[0x14].cycles[0] = 4;
    (opcodes->up)[0x14].cycles[1] = 4;

    (opcodes->up)[0x15].mnemonic = "DEC";
    (opcodes->up)[0x15].func = &opcode_up_0x15_DEC;
    (opcodes->up)[0x15].length = 1;
    (opcodes->up)[0x15].cycles[0] = 4;
    (opcodes->up)[0x15].cycles[1] = 4;

    (opcodes->up)[0x16].mnemonic = "LD";
    (opcodes->up)[0x16].func = &opcode_up_0x16_LD;
    (opcodes->up)[0x16].length = 2;
    (opcodes->up)[0x16].cycles[0] = 8;
    (opcodes->up)[0x16].cycles[1] = 8;

    (opcodes->up)[0x17].mnemonic = "RLA";
    (opcodes->up)[0x17].func = &opcode_up_0x17_RLA;
    (opcodes->up)[0x17].length = 1;
    (opcodes->up)[0x17].cycles[0] = 4;
    (opcodes->up)[0x17].cycles[1] = 4;

    (opcodes->up)[0x18].mnemonic = "JR";
    (opcodes->up)[0x18].func = &opcode_up_0x18_JR;
    (opcodes->up)[0x18].length = 2;
    (opcodes->up)[0x18].cycles[0] = 12;
    (opcodes->up)[0x18].cycles[1] = 12;

    (opcodes->up)[0x19].mnemonic = "ADD";
    (opcodes->up)[0x19].func = &opcode_up_0x19_ADD;
    (opcodes->up)[0x19].length = 1;
    (opcodes->up)[0x19].cycles[0] = 8;
    (opcodes->up)[0x19].cycles[1] = 8;

    (opcodes->up)[0x1a].mnemonic = "LD";
    (opcodes->up)[0x1a].func = &opcode_up_0x1a_LD;
    (opcodes->up)[0x1a].length = 1;
    (opcodes->up)[0x1a].cycles[0] = 8;
    (opcodes->up)[0x1a].cycles[1] = 8;

    (opcodes->up)[0x1b].mnemonic = "DEC";
    (opcodes->up)[0x1b].func = &opcode_up_0x1b_DEC;
    (opcodes->up)[0x1b].length = 1;
    (opcodes->up)[0x1b].cycles[0] = 8;
    (opcodes->up)[0x1b].cycles[1] = 8;

    (opcodes->up)[0x1c].mnemonic = "INC";
    (opcodes->up)[0x1c].func = &opcode_up_0x1c_INC;
    (opcodes->up)[0x1c].length = 1;
    (opcodes->up)[0x1c].cycles[0] = 4;
    (opcodes->up)[0x1c].cycles[1] = 4;

    (opcodes->up)[0x1d].mnemonic = "DEC";
    (opcodes->up)[0x1d].func = &opcode_up_0x1d_DEC;
    (opcodes->up)[0x1d].length = 1;
    (opcodes->up)[0x1d].cycles[0] = 4;
    (opcodes->up)[0x1d].cycles[1] = 4;

    (opcodes->up)[0x1e].mnemonic = "LD";
    (opcodes->up)[0x1e].func = &opcode_up_0x1e_LD;
    (opcodes->up)[0x1e].length = 2;
    (opcodes->up)[0x1e].cycles[0] = 8;
    (opcodes->up)[0x1e].cycles[1] = 8;

    (opcodes->up)[0x1f].mnemonic = "RRA";
    (opcodes->up)[0x1f].func = &opcode_up_0x1f_RRA;
    (opcodes->up)[0x1f].length = 1;
    (opcodes->up)[0x1f].cycles[0] = 4;
    (opcodes->up)[0x1f].cycles[1] = 4;

    (opcodes->up)[0x20].mnemonic = "JR";
    (opcodes->up)[0x20].func = &opcode_up_0x20_JR;
    (opcodes->up)[0x20].length = 2;
    (opcodes->up)[0x20].cycles[0] = 12;
    (opcodes->up)[0x20].cycles[1] = 8;

    (opcodes->up)[0x21].mnemonic = "LD";
    (opcodes->up)[0x21].func = &opcode_up_0x21_LD;
    (opcodes->up)[0x21].length = 3;
    (opcodes->up)[0x21].cycles[0] = 12;
    (opcodes->up)[0x21].cycles[1] = 12;

    (opcodes->up)[0x22].mnemonic = "LD";
    (opcodes->up)[0x22].func = &opcode_up_0x22_LD;
    (opcodes->up)[0x22].length = 1;
    (opcodes->up)[0x22].cycles[0] = 8;
    (opcodes->up)[0x22].cycles[1] = 8;

    (opcodes->up)[0x23].mnemonic = "INC";
    (opcodes->up)[0x23].func = &opcode_up_0x23_INC;
    (opcodes->up)[0x23].length = 1;
    (opcodes->up)[0x23].cycles[0] = 8;
    (opcodes->up)[0x23].cycles[1] = 8;

    (opcodes->up)[0x24].mnemonic = "INC";
    (opcodes->up)[0x24].func = &opcode_up_0x24_INC;
    (opcodes->up)[0x24].length = 1;
    (opcodes->up)[0x24].cycles[0] = 4;
    (opcodes->up)[0x24].cycles[1] = 4;

    (opcodes->up)[0x25].mnemonic = "DEC";
    (opcodes->up)[0x25].func = &opcode_up_0x25_DEC;
    (opcodes->up)[0x25].length = 1;
    (opcodes->up)[0x25].cycles[0] = 4;
    (opcodes->up)[0x25].cycles[1] = 4;

    (opcodes->up)[0x26].mnemonic = "LD";
    (opcodes->up)[0x26].func = &opcode_up_0x26_LD;
    (opcodes->up)[0x26].length = 2;
    (opcodes->up)[0x26].cycles[0] = 8;
    (opcodes->up)[0x26].cycles[1] = 8;

    (opcodes->up)[0x27].mnemonic = "DAA";
    (opcodes->up)[0x27].func = &opcode_up_0x27_DAA;
    (opcodes->up)[0x27].length = 1;
    (opcodes->up)[0x27].cycles[0] = 4;
    (opcodes->up)[0x27].cycles[1] = 4;

    (opcodes->up)[0x28].mnemonic = "JR";
    (opcodes->up)[0x28].func = &opcode_up_0x28_JR;
    (opcodes->up)[0x28].length = 2;
    (opcodes->up)[0x28].cycles[0] = 12;
    (opcodes->up)[0x28].cycles[1] = 8;

    (opcodes->up)[0x29].mnemonic = "ADD";
    (opcodes->up)[0x29].func = &opcode_up_0x29_ADD;
    (opcodes->up)[0x29].length = 1;
    (opcodes->up)[0x29].cycles[0] = 8;
    (opcodes->up)[0x29].cycles[1] = 8;

    (opcodes->up)[0x2a].mnemonic = "LD";
    (opcodes->up)[0x2a].func = &opcode_up_0x2a_LD;
    (opcodes->up)[0x2a].length = 1;
    (opcodes->up)[0x2a].cycles[0] = 8;
    (opcodes->up)[0x2a].cycles[1] = 8;

    (opcodes->up)[0x2b].mnemonic = "DEC";
    (opcodes->up)[0x2b].func = &opcode_up_0x2b_DEC;
    (opcodes->up)[0x2b].length = 1;
    (opcodes->up)[0x2b].cycles[0] = 8;
    (opcodes->up)[0x2b].cycles[1] = 8;

    (opcodes->up)[0x2c].mnemonic = "INC";
    (opcodes->up)[0x2c].func = &opcode_up_0x2c_INC;
    (opcodes->up)[0x2c].length = 1;
    (opcodes->up)[0x2c].cycles[0] = 4;
    (opcodes->up)[0x2c].cycles[1] = 4;

    (opcodes->up)[0x2d].mnemonic = "DEC";
    (opcodes->up)[0x2d].func = &opcode_up_0x2d_DEC;
    (opcodes->up)[0x2d].length = 1;
    (opcodes->up)[0x2d].cycles[0] = 4;
    (opcodes->up)[0x2d].cycles[1] = 4;

    (opcodes->up)[0x2e].mnemonic = "LD";
    (opcodes->up)[0x2e].func = &opcode_up_0x2e_LD;
    (opcodes->up)[0x2e].length = 2;
    (opcodes->up)[0x2e].cycles[0] = 8;
    (opcodes->up)[0x2e].cycles[1] = 8;

    (opcodes->up)[0x2f].mnemonic = "CPL";
    (opcodes->up)[0x2f].func = &opcode_up_0x2f_CPL;
    (opcodes->up)[0x2f].length = 1;
    (opcodes->up)[0x2f].cycles[0] = 4;
    (opcodes->up)[0x2f].cycles[1] = 4;

    (opcodes->up)[0x30].mnemonic = "JR";
    (opcodes->up)[0x30].func = &opcode_up_0x30_JR;
    (opcodes->up)[0x30].length = 2;
    (opcodes->up)[0x30].cycles[0] = 12;
    (opcodes->up)[0x30].cycles[1] = 8;

    (opcodes->up)[0x31].mnemonic = "LD";
    (opcodes->up)[0x31].func = &opcode_up_0x31_LD;
    (opcodes->up)[0x31].length = 3;
    (opcodes->up)[0x31].cycles[0] = 12;
    (opcodes->up)[0x31].cycles[1] = 12;

    (opcodes->up)[0x32].mnemonic = "LD";
    (opcodes->up)[0x32].func = &opcode_up_0x32_LD;
    (opcodes->up)[0x32].length = 1;
    (opcodes->up)[0x32].cycles[0] = 8;
    (opcodes->up)[0x32].cycles[1] = 8;

    (opcodes->up)[0x33].mnemonic = "INC";
    (opcodes->up)[0x33].func = &opcode_up_0x33_INC;
    (opcodes->up)[0x33].length = 1;
    (opcodes->up)[0x33].cycles[0] = 8;
    (opcodes->up)[0x33].cycles[1] = 8;

    (opcodes->up)[0x34].mnemonic = "INC";
    (opcodes->up)[0x34].func = &opcode_up_0x34_INC;
    (opcodes->up)[0x34].length = 1;
    (opcodes->up)[0x34].cycles[0] = 12;
    (opcodes->up)[0x34].cycles[1] = 12;

    (opcodes->up)[0x35].mnemonic = "DEC";
    (opcodes->up)[0x35].func = &opcode_up_0x35_DEC;
    (opcodes->up)[0x35].length = 1;
    (opcodes->up)[0x35].cycles[0] = 12;
    (opcodes->up)[0x35].cycles[1] = 12;

    (opcodes->up)[0x36].mnemonic = "LD";
    (opcodes->up)[0x36].func = &opcode_up_0x36_LD;
    (opcodes->up)[0x36].length = 2;
    (opcodes->up)[0x36].cycles[0] = 12;
    (opcodes->up)[0x36].cycles[1] = 12;

    (opcodes->up)[0x37].mnemonic = "SCF";
    (opcodes->up)[0x37].func = &opcode_up_0x37_SCF;
    (opcodes->up)[0x37].length = 1;
    (opcodes->up)[0x37].cycles[0] = 4;
    (opcodes->up)[0x37].cycles[1] = 4;

    (opcodes->up)[0x38].mnemonic = "JR";
    (opcodes->up)[0x38].func = &opcode_up_0x38_JR;
    (opcodes->up)[0x38].length = 2;
    (opcodes->up)[0x38].cycles[0] = 12;
    (opcodes->up)[0x38].cycles[1] = 8;

    (opcodes->up)[0x39].mnemonic = "ADD";
    (opcodes->up)[0x39].func = &opcode_up_0x39_ADD;
    (opcodes->up)[0x39].length = 1;
    (opcodes->up)[0x39].cycles[0] = 8;
    (opcodes->up)[0x39].cycles[1] = 8;

    (opcodes->up)[0x3a].mnemonic = "LD";
    (opcodes->up)[0x3a].func = &opcode_up_0x3a_LD;
    (opcodes->up)[0x3a].length = 1;
    (opcodes->up)[0x3a].cycles[0] = 8;
    (opcodes->up)[0x3a].cycles[1] = 8;

    (opcodes->up)[0x3b].mnemonic = "DEC";
    (opcodes->up)[0x3b].func = &opcode_up_0x3b_DEC;
    (opcodes->up)[0x3b].length = 1;
    (opcodes->up)[0x3b].cycles[0] = 8;
    (opcodes->up)[0x3b].cycles[1] = 8;

    (opcodes->up)[0x3c].mnemonic = "INC";
    (opcodes->up)[0x3c].func = &opcode_up_0x3c_INC;
    (opcodes->up)[0x3c].length = 1;
    (opcodes->up)[0x3c].cycles[0] = 4;
    (opcodes->up)[0x3c].cycles[1] = 4;

    (opcodes->up)[0x3d].mnemonic = "DEC";
    (opcodes->up)[0x3d].func = &opcode_up_0x3d_DEC;
    (opcodes->up)[0x3d].length = 1;
    (opcodes->up)[0x3d].cycles[0] = 4;
    (opcodes->up)[0x3d].cycles[1] = 4;

    (opcodes->up)[0x3e].mnemonic = "LD";
    (opcodes->up)[0x3e].func = &opcode_up_0x3e_LD;
    (opcodes->up)[0x3e].length = 2;
    (opcodes->up)[0x3e].cycles[0] = 8;
    (opcodes->up)[0x3e].cycles[1] = 8;

    (opcodes->up)[0x3f].mnemonic = "CCF";
    (opcodes->up)[0x3f].func = &opcode_up_0x3f_CCF;
    (opcodes->up)[0x3f].length = 1;
    (opcodes->up)[0x3f].cycles[0] = 4;
    (opcodes->up)[0x3f].cycles[1] = 4;

    (opcodes->up)[0x40].mnemonic = "LD";
    (opcodes->up)[0x40].func = &opcode_up_0x40_LD;
    (opcodes->up)[0x40].length = 1;
    (opcodes->up)[0x40].cycles[0] = 4;
    (opcodes->up)[0x40].cycles[1] = 4;

    (opcodes->up)[0x41].mnemonic = "LD";
    (opcodes->up)[0x41].func = &opcode_up_0x41_LD;
    (opcodes->up)[0x41].length = 1;
    (opcodes->up)[0x41].cycles[0] = 4;
    (opcodes->up)[0x41].cycles[1] = 4;

    (opcodes->up)[0x42].mnemonic = "LD";
    (opcodes->up)[0x42].func = &opcode_up_0x42_LD;
    (opcodes->up)[0x42].length = 1;
    (opcodes->up)[0x42].cycles[0] = 4;
    (opcodes->up)[0x42].cycles[1] = 4;

    (opcodes->up)[0x43].mnemonic = "LD";
    (opcodes->up)[0x43].func = &opcode_up_0x43_LD;
    (opcodes->up)[0x43].length = 1;
    (opcodes->up)[0x43].cycles[0] = 4;
    (opcodes->up)[0x43].cycles[1] = 4;

    (opcodes->up)[0x44].mnemonic = "LD";
    (opcodes->up)[0x44].func = &opcode_up_0x44_LD;
    (opcodes->up)[0x44].length = 1;
    (opcodes->up)[0x44].cycles[0] = 4;
    (opcodes->up)[0x44].cycles[1] = 4;

    (opcodes->up)[0x45].mnemonic = "LD";
    (opcodes->up)[0x45].func = &opcode_up_0x45_LD;
    (opcodes->up)[0x45].length = 1;
    (opcodes->up)[0x45].cycles[0] = 4;
    (opcodes->up)[0x45].cycles[1] = 4;

    (opcodes->up)[0x46].mnemonic = "LD";
    (opcodes->up)[0x46].func = &opcode_up_0x46_LD;
    (opcodes->up)[0x46].length = 1;
    (opcodes->up)[0x46].cycles[0] = 8;
    (opcodes->up)[0x46].cycles[1] = 8;

    (opcodes->up)[0x47].mnemonic = "LD";
    (opcodes->up)[0x47].func = &opcode_up_0x47_LD;
    (opcodes->up)[0x47].length = 1;
    (opcodes->up)[0x47].cycles[0] = 4;
    (opcodes->up)[0x47].cycles[1] = 4;

    (opcodes->up)[0x48].mnemonic = "LD";
    (opcodes->up)[0x48].func = &opcode_up_0x48_LD;
    (opcodes->up)[0x48].length = 1;
    (opcodes->up)[0x48].cycles[0] = 4;
    (opcodes->up)[0x48].cycles[1] = 4;

    (opcodes->up)[0x49].mnemonic = "LD";
    (opcodes->up)[0x49].func = &opcode_up_0x49_LD;
    (opcodes->up)[0x49].length = 1;
    (opcodes->up)[0x49].cycles[0] = 4;
    (opcodes->up)[0x49].cycles[1] = 4;

    (opcodes->up)[0x4a].mnemonic = "LD";
    (opcodes->up)[0x4a].func = &opcode_up_0x4a_LD;
    (opcodes->up)[0x4a].length = 1;
    (opcodes->up)[0x4a].cycles[0] = 4;
    (opcodes->up)[0x4a].cycles[1] = 4;

    (opcodes->up)[0x4b].mnemonic = "LD";
    (opcodes->up)[0x4b].func = &opcode_up_0x4b_LD;
    (opcodes->up)[0x4b].length = 1;
    (opcodes->up)[0x4b].cycles[0] = 4;
    (opcodes->up)[0x4b].cycles[1] = 4;

    (opcodes->up)[0x4c].mnemonic = "LD";
    (opcodes->up)[0x4c].func = &opcode_up_0x4c_LD;
    (opcodes->up)[0x4c].length = 1;
    (opcodes->up)[0x4c].cycles[0] = 4;
    (opcodes->up)[0x4c].cycles[1] = 4;

    (opcodes->up)[0x4d].mnemonic = "LD";
    (opcodes->up)[0x4d].func = &opcode_up_0x4d_LD;
    (opcodes->up)[0x4d].length = 1;
    (opcodes->up)[0x4d].cycles[0] = 4;
    (opcodes->up)[0x4d].cycles[1] = 4;

    (opcodes->up)[0x4e].mnemonic = "LD";
    (opcodes->up)[0x4e].func = &opcode_up_0x4e_LD;
    (opcodes->up)[0x4e].length = 1;
    (opcodes->up)[0x4e].cycles[0] = 8;
    (opcodes->up)[0x4e].cycles[1] = 8;

    (opcodes->up)[0x4f].mnemonic = "LD";
    (opcodes->up)[0x4f].func = &opcode_up_0x4f_LD;
    (opcodes->up)[0x4f].length = 1;
    (opcodes->up)[0x4f].cycles[0] = 4;
    (opcodes->up)[0x4f].cycles[1] = 4;

    (opcodes->up)[0x50].mnemonic = "LD";
    (opcodes->up)[0x50].func = &opcode_up_0x50_LD;
    (opcodes->up)[0x50].length = 1;
    (opcodes->up)[0x50].cycles[0] = 4;
    (opcodes->up)[0x50].cycles[1] = 4;

    (opcodes->up)[0x51].mnemonic = "LD";
    (opcodes->up)[0x51].func = &opcode_up_0x51_LD;
    (opcodes->up)[0x51].length = 1;
    (opcodes->up)[0x51].cycles[0] = 4;
    (opcodes->up)[0x51].cycles[1] = 4;

    (opcodes->up)[0x52].mnemonic = "LD";
    (opcodes->up)[0x52].func = &opcode_up_0x52_LD;
    (opcodes->up)[0x52].length = 1;
    (opcodes->up)[0x52].cycles[0] = 4;
    (opcodes->up)[0x52].cycles[1] = 4;

    (opcodes->up)[0x53].mnemonic = "LD";
    (opcodes->up)[0x53].func = &opcode_up_0x53_LD;
    (opcodes->up)[0x53].length = 1;
    (opcodes->up)[0x53].cycles[0] = 4;
    (opcodes->up)[0x53].cycles[1] = 4;

    (opcodes->up)[0x54].mnemonic = "LD";
    (opcodes->up)[0x54].func = &opcode_up_0x54_LD;
    (opcodes->up)[0x54].length = 1;
    (opcodes->up)[0x54].cycles[0] = 4;
    (opcodes->up)[0x54].cycles[1] = 4;

    (opcodes->up)[0x55].mnemonic = "LD";
    (opcodes->up)[0x55].func = &opcode_up_0x55_LD;
    (opcodes->up)[0x55].length = 1;
    (opcodes->up)[0x55].cycles[0] = 4;
    (opcodes->up)[0x55].cycles[1] = 4;

    (opcodes->up)[0x56].mnemonic = "LD";
    (opcodes->up)[0x56].func = &opcode_up_0x56_LD;
    (opcodes->up)[0x56].length = 1;
    (opcodes->up)[0x56].cycles[0] = 8;
    (opcodes->up)[0x56].cycles[1] = 8;

    (opcodes->up)[0x57].mnemonic = "LD";
    (opcodes->up)[0x57].func = &opcode_up_0x57_LD;
    (opcodes->up)[0x57].length = 1;
    (opcodes->up)[0x57].cycles[0] = 4;
    (opcodes->up)[0x57].cycles[1] = 4;

    (opcodes->up)[0x58].mnemonic = "LD";
    (opcodes->up)[0x58].func = &opcode_up_0x58_LD;
    (opcodes->up)[0x58].length = 1;
    (opcodes->up)[0x58].cycles[0] = 4;
    (opcodes->up)[0x58].cycles[1] = 4;

    (opcodes->up)[0x59].mnemonic = "LD";
    (opcodes->up)[0x59].func = &opcode_up_0x59_LD;
    (opcodes->up)[0x59].length = 1;
    (opcodes->up)[0x59].cycles[0] = 4;
    (opcodes->up)[0x59].cycles[1] = 4;

    (opcodes->up)[0x5a].mnemonic = "LD";
    (opcodes->up)[0x5a].func = &opcode_up_0x5a_LD;
    (opcodes->up)[0x5a].length = 1;
    (opcodes->up)[0x5a].cycles[0] = 4;
    (opcodes->up)[0x5a].cycles[1] = 4;

    (opcodes->up)[0x5b].mnemonic = "LD";
    (opcodes->up)[0x5b].func = &opcode_up_0x5b_LD;
    (opcodes->up)[0x5b].length = 1;
    (opcodes->up)[0x5b].cycles[0] = 4;
    (opcodes->up)[0x5b].cycles[1] = 4;

    (opcodes->up)[0x5c].mnemonic = "LD";
    (opcodes->up)[0x5c].func = &opcode_up_0x5c_LD;
    (opcodes->up)[0x5c].length = 1;
    (opcodes->up)[0x5c].cycles[0] = 4;
    (opcodes->up)[0x5c].cycles[1] = 4;

    (opcodes->up)[0x5d].mnemonic = "LD";
    (opcodes->up)[0x5d].func = &opcode_up_0x5d_LD;
    (opcodes->up)[0x5d].length = 1;
    (opcodes->up)[0x5d].cycles[0] = 4;
    (opcodes->up)[0x5d].cycles[1] = 4;

    (opcodes->up)[0x5e].mnemonic = "LD";
    (opcodes->up)[0x5e].func = &opcode_up_0x5e_LD;
    (opcodes->up)[0x5e].length = 1;
    (opcodes->up)[0x5e].cycles[0] = 8;
    (opcodes->up)[0x5e].cycles[1] = 8;

    (opcodes->up)[0x5f].mnemonic = "LD";
    (opcodes->up)[0x5f].func = &opcode_up_0x5f_LD;
    (opcodes->up)[0x5f].length = 1;
    (opcodes->up)[0x5f].cycles[0] = 4;
    (opcodes->up)[0x5f].cycles[1] = 4;

    (opcodes->up)[0x60].mnemonic = "LD";
    (opcodes->up)[0x60].func = &opcode_up_0x60_LD;
    (opcodes->up)[0x60].length = 1;
    (opcodes->up)[0x60].cycles[0] = 4;
    (opcodes->up)[0x60].cycles[1] = 4;

    (opcodes->up)[0x61].mnemonic = "LD";
    (opcodes->up)[0x61].func = &opcode_up_0x61_LD;
    (opcodes->up)[0x61].length = 1;
    (opcodes->up)[0x61].cycles[0] = 4;
    (opcodes->up)[0x61].cycles[1] = 4;

    (opcodes->up)[0x62].mnemonic = "LD";
    (opcodes->up)[0x62].func = &opcode_up_0x62_LD;
    (opcodes->up)[0x62].length = 1;
    (opcodes->up)[0x62].cycles[0] = 4;
    (opcodes->up)[0x62].cycles[1] = 4;

    (opcodes->up)[0x63].mnemonic = "LD";
    (opcodes->up)[0x63].func = &opcode_up_0x63_LD;
    (opcodes->up)[0x63].length = 1;
    (opcodes->up)[0x63].cycles[0] = 4;
    (opcodes->up)[0x63].cycles[1] = 4;

    (opcodes->up)[0x64].mnemonic = "LD";
    (opcodes->up)[0x64].func = &opcode_up_0x64_LD;
    (opcodes->up)[0x64].length = 1;
    (opcodes->up)[0x64].cycles[0] = 4;
    (opcodes->up)[0x64].cycles[1] = 4;

    (opcodes->up)[0x65].mnemonic = "LD";
    (opcodes->up)[0x65].func = &opcode_up_0x65_LD;
    (opcodes->up)[0x65].length = 1;
    (opcodes->up)[0x65].cycles[0] = 4;
    (opcodes->up)[0x65].cycles[1] = 4;

    (opcodes->up)[0x66].mnemonic = "LD";
    (opcodes->up)[0x66].func = &opcode_up_0x66_LD;
    (opcodes->up)[0x66].length = 1;
    (opcodes->up)[0x66].cycles[0] = 8;
    (opcodes->up)[0x66].cycles[1] = 8;

    (opcodes->up)[0x67].mnemonic = "LD";
    (opcodes->up)[0x67].func = &opcode_up_0x67_LD;
    (opcodes->up)[0x67].length = 1;
    (opcodes->up)[0x67].cycles[0] = 4;
    (opcodes->up)[0x67].cycles[1] = 4;

    (opcodes->up)[0x68].mnemonic = "LD";
    (opcodes->up)[0x68].func = &opcode_up_0x68_LD;
    (opcodes->up)[0x68].length = 1;
    (opcodes->up)[0x68].cycles[0] = 4;
    (opcodes->up)[0x68].cycles[1] = 4;

    (opcodes->up)[0x69].mnemonic = "LD";
    (opcodes->up)[0x69].func = &opcode_up_0x69_LD;
    (opcodes->up)[0x69].length = 1;
    (opcodes->up)[0x69].cycles[0] = 4;
    (opcodes->up)[0x69].cycles[1] = 4;

    (opcodes->up)[0x6a].mnemonic = "LD";
    (opcodes->up)[0x6a].func = &opcode_up_0x6a_LD;
    (opcodes->up)[0x6a].length = 1;
    (opcodes->up)[0x6a].cycles[0] = 4;
    (opcodes->up)[0x6a].cycles[1] = 4;

    (opcodes->up)[0x6b].mnemonic = "LD";
    (opcodes->up)[0x6b].func = &opcode_up_0x6b_LD;
    (opcodes->up)[0x6b].length = 1;
    (opcodes->up)[0x6b].cycles[0] = 4;
    (opcodes->up)[0x6b].cycles[1] = 4;

    (opcodes->up)[0x6c].mnemonic = "LD";
    (opcodes->up)[0x6c].func = &opcode_up_0x6c_LD;
    (opcodes->up)[0x6c].length = 1;
    (opcodes->up)[0x6c].cycles[0] = 4;
    (opcodes->up)[0x6c].cycles[1] = 4;

    (opcodes->up)[0x6d].mnemonic = "LD";
    (opcodes->up)[0x6d].func = &opcode_up_0x6d_LD;
    (opcodes->up)[0x6d].length = 1;
    (opcodes->up)[0x6d].cycles[0] = 4;
    (opcodes->up)[0x6d].cycles[1] = 4;

    (opcodes->up)[0x6e].mnemonic = "LD";
    (opcodes->up)[0x6e].func = &opcode_up_0x6e_LD;
    (opcodes->up)[0x6e].length = 1;
    (opcodes->up)[0x6e].cycles[0] = 8;
    (opcodes->up)[0x6e].cycles[1] = 8;

    (opcodes->up)[0x6f].mnemonic = "LD";
    (opcodes->up)[0x6f].func = &opcode_up_0x6f_LD;
    (opcodes->up)[0x6f].length = 1;
    (opcodes->up)[0x6f].cycles[0] = 4;
    (opcodes->up)[0x6f].cycles[1] = 4;

    (opcodes->up)[0x70].mnemonic = "LD";
    (opcodes->up)[0x70].func = &opcode_up_0x70_LD;
    (opcodes->up)[0x70].length = 1;
    (opcodes->up)[0x70].cycles[0] = 8;
    (opcodes->up)[0x70].cycles[1] = 8;

    (opcodes->up)[0x71].mnemonic = "LD";
    (opcodes->up)[0x71].func = &opcode_up_0x71_LD;
    (opcodes->up)[0x71].length = 1;
    (opcodes->up)[0x71].cycles[0] = 8;
    (opcodes->up)[0x71].cycles[1] = 8;

    (opcodes->up)[0x72].mnemonic = "LD";
    (opcodes->up)[0x72].func = &opcode_up_0x72_LD;
    (opcodes->up)[0x72].length = 1;
    (opcodes->up)[0x72].cycles[0] = 8;
    (opcodes->up)[0x72].cycles[1] = 8;

    (opcodes->up)[0x73].mnemonic = "LD";
    (opcodes->up)[0x73].func = &opcode_up_0x73_LD;
    (opcodes->up)[0x73].length = 1;
    (opcodes->up)[0x73].cycles[0] = 8;
    (opcodes->up)[0x73].cycles[1] = 8;

    (opcodes->up)[0x74].mnemonic = "LD";
    (opcodes->up)[0x74].func = &opcode_up_0x74_LD;
    (opcodes->up)[0x74].length = 1;
    (opcodes->up)[0x74].cycles[0] = 8;
    (opcodes->up)[0x74].cycles[1] = 8;

    (opcodes->up)[0x75].mnemonic = "LD";
    (opcodes->up)[0x75].func = &opcode_up_0x75_LD;
    (opcodes->up)[0x75].length = 1;
    (opcodes->up)[0x75].cycles[0] = 8;
    (opcodes->up)[0x75].cycles[1] = 8;

    (opcodes->up)[0x76].mnemonic = "HALT";
    (opcodes->up)[0x76].func = &opcode_up_0x76_HALT;
    (opcodes->up)[0x76].length = 1;
    (opcodes->up)[0x76].cycles[0] = 4;
    (opcodes->up)[0x76].cycles[1] = 4;

    (opcodes->up)[0x77].mnemonic = "LD";
    (opcodes->up)[0x77].func = &opcode_up_0x77_LD;
    (opcodes->up)[0x77].length = 1;
    (opcodes->up)[0x77].cycles[0] = 8;
    (opcodes->up)[0x77].cycles[1] = 8;

    (opcodes->up)[0x78].mnemonic = "LD";
    (opcodes->up)[0x78].func = &opcode_up_0x78_LD;
    (opcodes->up)[0x78].length = 1;
    (opcodes->up)[0x78].cycles[0] = 4;
    (opcodes->up)[0x78].cycles[1] = 4;

    (opcodes->up)[0x79].mnemonic = "LD";
    (opcodes->up)[0x79].func = &opcode_up_0x79_LD;
    (opcodes->up)[0x79].length = 1;
    (opcodes->up)[0x79].cycles[0] = 4;
    (opcodes->up)[0x79].cycles[1] = 4;

    (opcodes->up)[0x7a].mnemonic = "LD";
    (opcodes->up)[0x7a].func = &opcode_up_0x7a_LD;
    (opcodes->up)[0x7a].length = 1;
    (opcodes->up)[0x7a].cycles[0] = 4;
    (opcodes->up)[0x7a].cycles[1] = 4;

    (opcodes->up)[0x7b].mnemonic = "LD";
    (opcodes->up)[0x7b].func = &opcode_up_0x7b_LD;
    (opcodes->up)[0x7b].length = 1;
    (opcodes->up)[0x7b].cycles[0] = 4;
    (opcodes->up)[0x7b].cycles[1] = 4;

    (opcodes->up)[0x7c].mnemonic = "LD";
    (opcodes->up)[0x7c].func = &opcode_up_0x7c_LD;
    (opcodes->up)[0x7c].length = 1;
    (opcodes->up)[0x7c].cycles[0] = 4;
    (opcodes->up)[0x7c].cycles[1] = 4;

    (opcodes->up)[0x7d].mnemonic = "LD";
    (opcodes->up)[0x7d].func = &opcode_up_0x7d_LD;
    (opcodes->up)[0x7d].length = 1;
    (opcodes->up)[0x7d].cycles[0] = 4;
    (opcodes->up)[0x7d].cycles[1] = 4;

    (opcodes->up)[0x7e].mnemonic = "LD";
    (opcodes->up)[0x7e].func = &opcode_up_0x7e_LD;
    (opcodes->up)[0x7e].length = 1;
    (opcodes->up)[0x7e].cycles[0] = 8;
    (opcodes->up)[0x7e].cycles[1] = 8;

    (opcodes->up)[0x7f].mnemonic = "LD";
    (opcodes->up)[0x7f].func = &opcode_up_0x7f_LD;
    (opcodes->up)[0x7f].length = 1;
    (opcodes->up)[0x7f].cycles[0] = 4;
    (opcodes->up)[0x7f].cycles[1] = 4;

    (opcodes->up)[0x80].mnemonic = "ADD";
    (opcodes->up)[0x80].func = &opcode_up_0x80_ADD;
    (opcodes->up)[0x80].length = 1;
    (opcodes->up)[0x80].cycles[0] = 4;
    (opcodes->up)[0x80].cycles[1] = 4;

    (opcodes->up)[0x81].mnemonic = "ADD";
    (opcodes->up)[0x81].func = &opcode_up_0x81_ADD;
    (opcodes->up)[0x81].length = 1;
    (opcodes->up)[0x81].cycles[0] = 4;
    (opcodes->up)[0x81].cycles[1] = 4;

    (opcodes->up)[0x82].mnemonic = "ADD";
    (opcodes->up)[0x82].func = &opcode_up_0x82_ADD;
    (opcodes->up)[0x82].length = 1;
    (opcodes->up)[0x82].cycles[0] = 4;
    (opcodes->up)[0x82].cycles[1] = 4;

    (opcodes->up)[0x83].mnemonic = "ADD";
    (opcodes->up)[0x83].func = &opcode_up_0x83_ADD;
    (opcodes->up)[0x83].length = 1;
    (opcodes->up)[0x83].cycles[0] = 4;
    (opcodes->up)[0x83].cycles[1] = 4;

    (opcodes->up)[0x84].mnemonic = "ADD";
    (opcodes->up)[0x84].func = &opcode_up_0x84_ADD;
    (opcodes->up)[0x84].length = 1;
    (opcodes->up)[0x84].cycles[0] = 4;
    (opcodes->up)[0x84].cycles[1] = 4;

    (opcodes->up)[0x85].mnemonic = "ADD";
    (opcodes->up)[0x85].func = &opcode_up_0x85_ADD;
    (opcodes->up)[0x85].length = 1;
    (opcodes->up)[0x85].cycles[0] = 4;
    (opcodes->up)[0x85].cycles[1] = 4;

    (opcodes->up)[0x86].mnemonic = "ADD";
    (opcodes->up)[0x86].func = &opcode_up_0x86_ADD;
    (opcodes->up)[0x86].length = 1;
    (opcodes->up)[0x86].cycles[0] = 8;
    (opcodes->up)[0x86].cycles[1] = 8;

    (opcodes->up)[0x87].mnemonic = "ADD";
    (opcodes->up)[0x87].func = &opcode_up_0x87_ADD;
    (opcodes->up)[0x87].length = 1;
    (opcodes->up)[0x87].cycles[0] = 4;
    (opcodes->up)[0x87].cycles[1] = 4;

    (opcodes->up)[0x88].mnemonic = "ADC";
    (opcodes->up)[0x88].func = &opcode_up_0x88_ADC;
    (opcodes->up)[0x88].length = 1;
    (opcodes->up)[0x88].cycles[0] = 4;
    (opcodes->up)[0x88].cycles[1] = 4;

    (opcodes->up)[0x89].mnemonic = "ADC";
    (opcodes->up)[0x89].func = &opcode_up_0x89_ADC;
    (opcodes->up)[0x89].length = 1;
    (opcodes->up)[0x89].cycles[0] = 4;
    (opcodes->up)[0x89].cycles[1] = 4;

    (opcodes->up)[0x8a].mnemonic = "ADC";
    (opcodes->up)[0x8a].func = &opcode_up_0x8a_ADC;
    (opcodes->up)[0x8a].length = 1;
    (opcodes->up)[0x8a].cycles[0] = 4;
    (opcodes->up)[0x8a].cycles[1] = 4;

    (opcodes->up)[0x8b].mnemonic = "ADC";
    (opcodes->up)[0x8b].func = &opcode_up_0x8b_ADC;
    (opcodes->up)[0x8b].length = 1;
    (opcodes->up)[0x8b].cycles[0] = 4;
    (opcodes->up)[0x8b].cycles[1] = 4;

    (opcodes->up)[0x8c].mnemonic = "ADC";
    (opcodes->up)[0x8c].func = &opcode_up_0x8c_ADC;
    (opcodes->up)[0x8c].length = 1;
    (opcodes->up)[0x8c].cycles[0] = 4;
    (opcodes->up)[0x8c].cycles[1] = 4;

    (opcodes->up)[0x8d].mnemonic = "ADC";
    (opcodes->up)[0x8d].func = &opcode_up_0x8d_ADC;
    (opcodes->up)[0x8d].length = 1;
    (opcodes->up)[0x8d].cycles[0] = 4;
    (opcodes->up)[0x8d].cycles[1] = 4;

    (opcodes->up)[0x8e].mnemonic = "ADC";
    (opcodes->up)[0x8e].func = &opcode_up_0x8e_ADC;
    (opcodes->up)[0x8e].length = 1;
    (opcodes->up)[0x8e].cycles[0] = 8;
    (opcodes->up)[0x8e].cycles[1] = 8;

    (opcodes->up)[0x8f].mnemonic = "ADC";
    (opcodes->up)[0x8f].func = &opcode_up_0x8f_ADC;
    (opcodes->up)[0x8f].length = 1;
    (opcodes->up)[0x8f].cycles[0] = 4;
    (opcodes->up)[0x8f].cycles[1] = 4;

    (opcodes->up)[0x90].mnemonic = "SUB";
    (opcodes->up)[0x90].func = &opcode_up_0x90_SUB;
    (opcodes->up)[0x90].length = 1;
    (opcodes->up)[0x90].cycles[0] = 4;
    (opcodes->up)[0x90].cycles[1] = 4;

    (opcodes->up)[0x91].mnemonic = "SUB";
    (opcodes->up)[0x91].func = &opcode_up_0x91_SUB;
    (opcodes->up)[0x91].length = 1;
    (opcodes->up)[0x91].cycles[0] = 4;
    (opcodes->up)[0x91].cycles[1] = 4;

    (opcodes->up)[0x92].mnemonic = "SUB";
    (opcodes->up)[0x92].func = &opcode_up_0x92_SUB;
    (opcodes->up)[0x92].length = 1;
    (opcodes->up)[0x92].cycles[0] = 4;
    (opcodes->up)[0x92].cycles[1] = 4;

    (opcodes->up)[0x93].mnemonic = "SUB";
    (opcodes->up)[0x93].func = &opcode_up_0x93_SUB;
    (opcodes->up)[0x93].length = 1;
    (opcodes->up)[0x93].cycles[0] = 4;
    (opcodes->up)[0x93].cycles[1] = 4;

    (opcodes->up)[0x94].mnemonic = "SUB";
    (opcodes->up)[0x94].func = &opcode_up_0x94_SUB;
    (opcodes->up)[0x94].length = 1;
    (opcodes->up)[0x94].cycles[0] = 4;
    (opcodes->up)[0x94].cycles[1] = 4;

    (opcodes->up)[0x95].mnemonic = "SUB";
    (opcodes->up)[0x95].func = &opcode_up_0x95_SUB;
    (opcodes->up)[0x95].length = 1;
    (opcodes->up)[0x95].cycles[0] = 4;
    (opcodes->up)[0x95].cycles[1] = 4;

    (opcodes->up)[0x96].mnemonic = "SUB";
    (opcodes->up)[0x96].func = &opcode_up_0x96_SUB;
    (opcodes->up)[0x96].length = 1;
    (opcodes->up)[0x96].cycles[0] = 8;
    (opcodes->up)[0x96].cycles[1] = 8;

    (opcodes->up)[0x97].mnemonic = "SUB";
    (opcodes->up)[0x97].func = &opcode_up_0x97_SUB;
    (opcodes->up)[0x97].length = 1;
    (opcodes->up)[0x97].cycles[0] = 4;
    (opcodes->up)[0x97].cycles[1] = 4;

    (opcodes->up)[0x98].mnemonic = "SBC";
    (opcodes->up)[0x98].func = &opcode_up_0x98_SBC;
    (opcodes->up)[0x98].length = 1;
    (opcodes->up)[0x98].cycles[0] = 4;
    (opcodes->up)[0x98].cycles[1] = 4;

    (opcodes->up)[0x99].mnemonic = "SBC";
    (opcodes->up)[0x99].func = &opcode_up_0x99_SBC;
    (opcodes->up)[0x99].length = 1;
    (opcodes->up)[0x99].cycles[0] = 4;
    (opcodes->up)[0x99].cycles[1] = 4;

    (opcodes->up)[0x9a].mnemonic = "SBC";
    (opcodes->up)[0x9a].func = &opcode_up_0x9a_SBC;
    (opcodes->up)[0x9a].length = 1;
    (opcodes->up)[0x9a].cycles[0] = 4;
    (opcodes->up)[0x9a].cycles[1] = 4;

    (opcodes->up)[0x9b].mnemonic = "SBC";
    (opcodes->up)[0x9b].func = &opcode_up_0x9b_SBC;
    (opcodes->up)[0x9b].length = 1;
    (opcodes->up)[0x9b].cycles[0] = 4;
    (opcodes->up)[0x9b].cycles[1] = 4;

    (opcodes->up)[0x9c].mnemonic = "SBC";
    (opcodes->up)[0x9c].func = &opcode_up_0x9c_SBC;
    (opcodes->up)[0x9c].length = 1;
    (opcodes->up)[0x9c].cycles[0] = 4;
    (opcodes->up)[0x9c].cycles[1] = 4;

    (opcodes->up)[0x9d].mnemonic = "SBC";
    (opcodes->up)[0x9d].func = &opcode_up_0x9d_SBC;
    (opcodes->up)[0x9d].length = 1;
    (opcodes->up)[0x9d].cycles[0] = 4;
    (opcodes->up)[0x9d].cycles[1] = 4;

    (opcodes->up)[0x9e].mnemonic = "SBC";
    (opcodes->up)[0x9e].func = &opcode_up_0x9e_SBC;
    (opcodes->up)[0x9e].length = 1;
    (opcodes->up)[0x9e].cycles[0] = 8;
    (opcodes->up)[0x9e].cycles[1] = 8;

    (opcodes->up)[0x9f].mnemonic = "SBC";
    (opcodes->up)[0x9f].func = &opcode_up_0x9f_SBC;
    (opcodes->up)[0x9f].length = 1;
    (opcodes->up)[0x9f].cycles[0] = 4;
    (opcodes->up)[0x9f].cycles[1] = 4;

    (opcodes->up)[0xa0].mnemonic = "AND";
    (opcodes->up)[0xa0].func = &opcode_up_0xa0_AND;
    (opcodes->up)[0xa0].length = 1;
    (opcodes->up)[0xa0].cycles[0] = 4;
    (opcodes->up)[0xa0].cycles[1] = 4;

    (opcodes->up)[0xa1].mnemonic = "AND";
    (opcodes->up)[0xa1].func = &opcode_up_0xa1_AND;
    (opcodes->up)[0xa1].length = 1;
    (opcodes->up)[0xa1].cycles[0] = 4;
    (opcodes->up)[0xa1].cycles[1] = 4;

    (opcodes->up)[0xa2].mnemonic = "AND";
    (opcodes->up)[0xa2].func = &opcode_up_0xa2_AND;
    (opcodes->up)[0xa2].length = 1;
    (opcodes->up)[0xa2].cycles[0] = 4;
    (opcodes->up)[0xa2].cycles[1] = 4;

    (opcodes->up)[0xa3].mnemonic = "AND";
    (opcodes->up)[0xa3].func = &opcode_up_0xa3_AND;
    (opcodes->up)[0xa3].length = 1;
    (opcodes->up)[0xa3].cycles[0] = 4;
    (opcodes->up)[0xa3].cycles[1] = 4;

    (opcodes->up)[0xa4].mnemonic = "AND";
    (opcodes->up)[0xa4].func = &opcode_up_0xa4_AND;
    (opcodes->up)[0xa4].length = 1;
    (opcodes->up)[0xa4].cycles[0] = 4;
    (opcodes->up)[0xa4].cycles[1] = 4;

    (opcodes->up)[0xa5].mnemonic = "AND";
    (opcodes->up)[0xa5].func = &opcode_up_0xa5_AND;
    (opcodes->up)[0xa5].length = 1;
    (opcodes->up)[0xa5].cycles[0] = 4;
    (opcodes->up)[0xa5].cycles[1] = 4;

    (opcodes->up)[0xa6].mnemonic = "AND";
    (opcodes->up)[0xa6].func = &opcode_up_0xa6_AND;
    (opcodes->up)[0xa6].length = 1;
    (opcodes->up)[0xa6].cycles[0] = 8;
    (opcodes->up)[0xa6].cycles[1] = 8;

    (opcodes->up)[0xa7].mnemonic = "AND";
    (opcodes->up)[0xa7].func = &opcode_up_0xa7_AND;
    (opcodes->up)[0xa7].length = 1;
    (opcodes->up)[0xa7].cycles[0] = 4;
    (opcodes->up)[0xa7].cycles[1] = 4;

    (opcodes->up)[0xa8].mnemonic = "XOR";
    (opcodes->up)[0xa8].func = &opcode_up_0xa8_XOR;
    (opcodes->up)[0xa8].length = 1;
    (opcodes->up)[0xa8].cycles[0] = 4;
    (opcodes->up)[0xa8].cycles[1] = 4;

    (opcodes->up)[0xa9].mnemonic = "XOR";
    (opcodes->up)[0xa9].func = &opcode_up_0xa9_XOR;
    (opcodes->up)[0xa9].length = 1;
    (opcodes->up)[0xa9].cycles[0] = 4;
    (opcodes->up)[0xa9].cycles[1] = 4;

    (opcodes->up)[0xaa].mnemonic = "XOR";
    (opcodes->up)[0xaa].func = &opcode_up_0xaa_XOR;
    (opcodes->up)[0xaa].length = 1;
    (opcodes->up)[0xaa].cycles[0] = 4;
    (opcodes->up)[0xaa].cycles[1] = 4;

    (opcodes->up)[0xab].mnemonic = "XOR";
    (opcodes->up)[0xab].func = &opcode_up_0xab_XOR;
    (opcodes->up)[0xab].length = 1;
    (opcodes->up)[0xab].cycles[0] = 4;
    (opcodes->up)[0xab].cycles[1] = 4;

    (opcodes->up)[0xac].mnemonic = "XOR";
    (opcodes->up)[0xac].func = &opcode_up_0xac_XOR;
    (opcodes->up)[0xac].length = 1;
    (opcodes->up)[0xac].cycles[0] = 4;
    (opcodes->up)[0xac].cycles[1] = 4;

    (opcodes->up)[0xad].mnemonic = "XOR";
    (opcodes->up)[0xad].func = &opcode_up_0xad_XOR;
    (opcodes->up)[0xad].length = 1;
    (opcodes->up)[0xad].cycles[0] = 4;
    (opcodes->up)[0xad].cycles[1] = 4;

    (opcodes->up)[0xae].mnemonic = "XOR";
    (opcodes->up)[0xae].func = &opcode_up_0xae_XOR;
    (opcodes->up)[0xae].length = 1;
    (opcodes->up)[0xae].cycles[0] = 8;
    (opcodes->up)[0xae].cycles[1] = 8;

    (opcodes->up)[0xaf].mnemonic = "XOR";
    (opcodes->up)[0xaf].func = &opcode_up_0xaf_XOR;
    (opcodes->up)[0xaf].length = 1;
    (opcodes->up)[0xaf].cycles[0] = 4;
    (opcodes->up)[0xaf].cycles[1] = 4;

    (opcodes->up)[0xb0].mnemonic = "OR";
    (opcodes->up)[0xb0].func = &opcode_up_0xb0_OR;
    (opcodes->up)[0xb0].length = 1;
    (opcodes->up)[0xb0].cycles[0] = 4;
    (opcodes->up)[0xb0].cycles[1] = 4;

    (opcodes->up)[0xb1].mnemonic = "OR";
    (opcodes->up)[0xb1].func = &opcode_up_0xb1_OR;
    (opcodes->up)[0xb1].length = 1;
    (opcodes->up)[0xb1].cycles[0] = 4;
    (opcodes->up)[0xb1].cycles[1] = 4;

    (opcodes->up)[0xb2].mnemonic = "OR";
    (opcodes->up)[0xb2].func = &opcode_up_0xb2_OR;
    (opcodes->up)[0xb2].length = 1;
    (opcodes->up)[0xb2].cycles[0] = 4;
    (opcodes->up)[0xb2].cycles[1] = 4;

    (opcodes->up)[0xb3].mnemonic = "OR";
    (opcodes->up)[0xb3].func = &opcode_up_0xb3_OR;
    (opcodes->up)[0xb3].length = 1;
    (opcodes->up)[0xb3].cycles[0] = 4;
    (opcodes->up)[0xb3].cycles[1] = 4;

    (opcodes->up)[0xb4].mnemonic = "OR";
    (opcodes->up)[0xb4].func = &opcode_up_0xb4_OR;
    (opcodes->up)[0xb4].length = 1;
    (opcodes->up)[0xb4].cycles[0] = 4;
    (opcodes->up)[0xb4].cycles[1] = 4;

    (opcodes->up)[0xb5].mnemonic = "OR";
    (opcodes->up)[0xb5].func = &opcode_up_0xb5_OR;
    (opcodes->up)[0xb5].length = 1;
    (opcodes->up)[0xb5].cycles[0] = 4;
    (opcodes->up)[0xb5].cycles[1] = 4;

    (opcodes->up)[0xb6].mnemonic = "OR";
    (opcodes->up)[0xb6].func = &opcode_up_0xb6_OR;
    (opcodes->up)[0xb6].length = 1;
    (opcodes->up)[0xb6].cycles[0] = 8;
    (opcodes->up)[0xb6].cycles[1] = 8;

    (opcodes->up)[0xb7].mnemonic = "OR";
    (opcodes->up)[0xb7].func = &opcode_up_0xb7_OR;
    (opcodes->up)[0xb7].length = 1;
    (opcodes->up)[0xb7].cycles[0] = 4;
    (opcodes->up)[0xb7].cycles[1] = 4;

    (opcodes->up)[0xb8].mnemonic = "CP";
    (opcodes->up)[0xb8].func = &opcode_up_0xb8_CP;
    (opcodes->up)[0xb8].length = 1;
    (opcodes->up)[0xb8].cycles[0] = 4;
    (opcodes->up)[0xb8].cycles[1] = 4;

    (opcodes->up)[0xb9].mnemonic = "CP";
    (opcodes->up)[0xb9].func = &opcode_up_0xb9_CP;
    (opcodes->up)[0xb9].length = 1;
    (opcodes->up)[0xb9].cycles[0] = 4;
    (opcodes->up)[0xb9].cycles[1] = 4;

    (opcodes->up)[0xba].mnemonic = "CP";
    (opcodes->up)[0xba].func = &opcode_up_0xba_CP;
    (opcodes->up)[0xba].length = 1;
    (opcodes->up)[0xba].cycles[0] = 4;
    (opcodes->up)[0xba].cycles[1] = 4;

    (opcodes->up)[0xbb].mnemonic = "CP";
    (opcodes->up)[0xbb].func = &opcode_up_0xbb_CP;
    (opcodes->up)[0xbb].length = 1;
    (opcodes->up)[0xbb].cycles[0] = 4;
    (opcodes->up)[0xbb].cycles[1] = 4;

    (opcodes->up)[0xbc].mnemonic = "CP";
    (opcodes->up)[0xbc].func = &opcode_up_0xbc_CP;
    (opcodes->up)[0xbc].length = 1;
    (opcodes->up)[0xbc].cycles[0] = 4;
    (opcodes->up)[0xbc].cycles[1] = 4;

    (opcodes->up)[0xbd].mnemonic = "CP";
    (opcodes->up)[0xbd].func = &opcode_up_0xbd_CP;
    (opcodes->up)[0xbd].length = 1;
    (opcodes->up)[0xbd].cycles[0] = 4;
    (opcodes->up)[0xbd].cycles[1] = 4;

    (opcodes->up)[0xbe].mnemonic = "CP";
    (opcodes->up)[0xbe].func = &opcode_up_0xbe_CP;
    (opcodes->up)[0xbe].length = 1;
    (opcodes->up)[0xbe].cycles[0] = 8;
    (opcodes->up)[0xbe].cycles[1] = 8;

    (opcodes->up)[0xbf].mnemonic = "CP";
    (opcodes->up)[0xbf].func = &opcode_up_0xbf_CP;
    (opcodes->up)[0xbf].length = 1;
    (opcodes->up)[0xbf].cycles[0] = 4;
    (opcodes->up)[0xbf].cycles[1] = 4;

    (opcodes->up)[0xc0].mnemonic = "RET";
    (opcodes->up)[0xc0].func = &opcode_up_0xc0_RET;
    (opcodes->up)[0xc0].length = 1;
    (opcodes->up)[0xc0].cycles[0] = 20;
    (opcodes->up)[0xc0].cycles[1] = 8;

    (opcodes->up)[0xc1].mnemonic = "POP";
    (opcodes->up)[0xc1].func = &opcode_up_0xc1_POP;
    (opcodes->up)[0xc1].length = 1;
    (opcodes->up)[0xc1].cycles[0] = 12;
    (opcodes->up)[0xc1].cycles[1] = 12;

    (opcodes->up)[0xc2].mnemonic = "JP";
    (opcodes->up)[0xc2].func = &opcode_up_0xc2_JP;
    (opcodes->up)[0xc2].length = 3;
    (opcodes->up)[0xc2].cycles[0] = 16;
    (opcodes->up)[0xc2].cycles[1] = 12;

    (opcodes->up)[0xc3].mnemonic = "JP";
    (opcodes->up)[0xc3].func = &opcode_up_0xc3_JP;
    (opcodes->up)[0xc3].length = 3;
    (opcodes->up)[0xc3].cycles[0] = 16;
    (opcodes->up)[0xc3].cycles[1] = 16;

    (opcodes->up)[0xc4].mnemonic = "CALL";
    (opcodes->up)[0xc4].func = &opcode_up_0xc4_CALL;
    (opcodes->up)[0xc4].length = 3;
    (opcodes->up)[0xc4].cycles[0] = 24;
    (opcodes->up)[0xc4].cycles[1] = 12;

    (opcodes->up)[0xc5].mnemonic = "PUSH";
    (opcodes->up)[0xc5].func = &opcode_up_0xc5_PUSH;
    (opcodes->up)[0xc5].length = 1;
    (opcodes->up)[0xc5].cycles[0] = 16;
    (opcodes->up)[0xc5].cycles[1] = 16;

    (opcodes->up)[0xc6].mnemonic = "ADD";
    (opcodes->up)[0xc6].func = &opcode_up_0xc6_ADD;
    (opcodes->up)[0xc6].length = 2;
    (opcodes->up)[0xc6].cycles[0] = 8;
    (opcodes->up)[0xc6].cycles[1] = 8;

    (opcodes->up)[0xc7].mnemonic = "RST";
    (opcodes->up)[0xc7].func = &opcode_up_0xc7_RST;
    (opcodes->up)[0xc7].length = 1;
    (opcodes->up)[0xc7].cycles[0] = 16;
    (opcodes->up)[0xc7].cycles[1] = 16;

    (opcodes->up)[0xc8].mnemonic = "RET";
    (opcodes->up)[0xc8].func = &opcode_up_0xc8_RET;
    (opcodes->up)[0xc8].length = 1;
    (opcodes->up)[0xc8].cycles[0] = 20;
    (opcodes->up)[0xc8].cycles[1] = 8;

    (opcodes->up)[0xc9].mnemonic = "RET";
    (opcodes->up)[0xc9].func = &opcode_up_0xc9_RET;
    (opcodes->up)[0xc9].length = 1;
    (opcodes->up)[0xc9].cycles[0] = 16;
    (opcodes->up)[0xc9].cycles[1] = 16;

    (opcodes->up)[0xca].mnemonic = "JP";
    (opcodes->up)[0xca].func = &opcode_up_0xca_JP;
    (opcodes->up)[0xca].length = 3;
    (opcodes->up)[0xca].cycles[0] = 16;
    (opcodes->up)[0xca].cycles[1] = 12;

    (opcodes->up)[0xcb].mnemonic = "PREFIX";
    (opcodes->up)[0xcb].func = &opcode_up_0xcb_PREFIX;
    (opcodes->up)[0xcb].length = 1;
    (opcodes->up)[0xcb].cycles[0] = 4;
    (opcodes->up)[0xcb].cycles[1] = 4;

    (opcodes->up)[0xcc].mnemonic = "CALL";
    (opcodes->up)[0xcc].func = &opcode_up_0xcc_CALL;
    (opcodes->up)[0xcc].length = 3;
    (opcodes->up)[0xcc].cycles[0] = 24;
    (opcodes->up)[0xcc].cycles[1] = 12;

    (opcodes->up)[0xcd].mnemonic = "CALL";
    (opcodes->up)[0xcd].func = &opcode_up_0xcd_CALL;
    (opcodes->up)[0xcd].length = 3;
    (opcodes->up)[0xcd].cycles[0] = 24;
    (opcodes->up)[0xcd].cycles[1] = 24;

    (opcodes->up)[0xce].mnemonic = "ADC";
    (opcodes->up)[0xce].func = &opcode_up_0xce_ADC;
    (opcodes->up)[0xce].length = 2;
    (opcodes->up)[0xce].cycles[0] = 8;
    (opcodes->up)[0xce].cycles[1] = 8;

    (opcodes->up)[0xcf].mnemonic = "RST";
    (opcodes->up)[0xcf].func = &opcode_up_0xcf_RST;
    (opcodes->up)[0xcf].length = 1;
    (opcodes->up)[0xcf].cycles[0] = 16;
    (opcodes->up)[0xcf].cycles[1] = 16;

    (opcodes->up)[0xd0].mnemonic = "RET";
    (opcodes->up)[0xd0].func = &opcode_up_0xd0_RET;
    (opcodes->up)[0xd0].length = 1;
    (opcodes->up)[0xd0].cycles[0] = 20;
    (opcodes->up)[0xd0].cycles[1] = 8;

    (opcodes->up)[0xd1].mnemonic = "POP";
    (opcodes->up)[0xd1].func = &opcode_up_0xd1_POP;
    (opcodes->up)[0xd1].length = 1;
    (opcodes->up)[0xd1].cycles[0] = 12;
    (opcodes->up)[0xd1].cycles[1] = 12;

    (opcodes->up)[0xd2].mnemonic = "JP";
    (opcodes->up)[0xd2].func = &opcode_up_0xd2_JP;
    (opcodes->up)[0xd2].length = 3;
    (opcodes->up)[0xd2].cycles[0] = 16;
    (opcodes->up)[0xd2].cycles[1] = 12;

    (opcodes->up)[0xd4].mnemonic = "CALL";
    (opcodes->up)[0xd4].func = &opcode_up_0xd4_CALL;
    (opcodes->up)[0xd4].length = 3;
    (opcodes->up)[0xd4].cycles[0] = 24;
    (opcodes->up)[0xd4].cycles[1] = 12;

    (opcodes->up)[0xd5].mnemonic = "PUSH";
    (opcodes->up)[0xd5].func = &opcode_up_0xd5_PUSH;
    (opcodes->up)[0xd5].length = 1;
    (opcodes->up)[0xd5].cycles[0] = 16;
    (opcodes->up)[0xd5].cycles[1] = 16;

    (opcodes->up)[0xd6].mnemonic = "SUB";
    (opcodes->up)[0xd6].func = &opcode_up_0xd6_SUB;
    (opcodes->up)[0xd6].length = 2;
    (opcodes->up)[0xd6].cycles[0] = 8;
    (opcodes->up)[0xd6].cycles[1] = 8;

    (opcodes->up)[0xd7].mnemonic = "RST";
    (opcodes->up)[0xd7].func = &opcode_up_0xd7_RST;
    (opcodes->up)[0xd7].length = 1;
    (opcodes->up)[0xd7].cycles[0] = 16;
    (opcodes->up)[0xd7].cycles[1] = 16;

    (opcodes->up)[0xd8].mnemonic = "RET";
    (opcodes->up)[0xd8].func = &opcode_up_0xd8_RET;
    (opcodes->up)[0xd8].length = 1;
    (opcodes->up)[0xd8].cycles[0] = 20;
    (opcodes->up)[0xd8].cycles[1] = 8;

    (opcodes->up)[0xd9].mnemonic = "RETI";
    (opcodes->up)[0xd9].func = &opcode_up_0xd9_RETI;
    (opcodes->up)[0xd9].length = 1;
    (opcodes->up)[0xd9].cycles[0] = 16;
    (opcodes->up)[0xd9].cycles[1] = 16;

    (opcodes->up)[0xda].mnemonic = "JP";
    (opcodes->up)[0xda].func = &opcode_up_0xda_JP;
    (opcodes->up)[0xda].length = 3;
    (opcodes->up)[0xda].cycles[0] = 16;
    (opcodes->up)[0xda].cycles[1] = 12;

    (opcodes->up)[0xdc].mnemonic = "CALL";
    (opcodes->up)[0xdc].func = &opcode_up_0xdc_CALL;
    (opcodes->up)[0xdc].length = 3;
    (opcodes->up)[0xdc].cycles[0] = 24;
    (opcodes->up)[0xdc].cycles[1] = 12;

    (opcodes->up)[0xde].mnemonic = "SBC";
    (opcodes->up)[0xde].func = &opcode_up_0xde_SBC;
    (opcodes->up)[0xde].length = 2;
    (opcodes->up)[0xde].cycles[0] = 8;
    (opcodes->up)[0xde].cycles[1] = 8;

    (opcodes->up)[0xdf].mnemonic = "RST";
    (opcodes->up)[0xdf].func = &opcode_up_0xdf_RST;
    (opcodes->up)[0xdf].length = 1;
    (opcodes->up)[0xdf].cycles[0] = 16;
    (opcodes->up)[0xdf].cycles[1] = 16;

    (opcodes->up)[0xe0].mnemonic = "LDH";
    (opcodes->up)[0xe0].func = &opcode_up_0xe0_LDH;
    (opcodes->up)[0xe0].length = 2;
    (opcodes->up)[0xe0].cycles[0] = 12;
    (opcodes->up)[0xe0].cycles[1] = 12;

    (opcodes->up)[0xe1].mnemonic = "POP";
    (opcodes->up)[0xe1].func = &opcode_up_0xe1_POP;
    (opcodes->up)[0xe1].length = 1;
    (opcodes->up)[0xe1].cycles[0] = 12;
    (opcodes->up)[0xe1].cycles[1] = 12;

    (opcodes->up)[0xe2].mnemonic = "LD";
    (opcodes->up)[0xe2].func = &opcode_up_0xe2_LD;
    (opcodes->up)[0xe2].length = 2;
    (opcodes->up)[0xe2].cycles[0] = 8;
    (opcodes->up)[0xe2].cycles[1] = 8;

    (opcodes->up)[0xe5].mnemonic = "PUSH";
    (opcodes->up)[0xe5].func = &opcode_up_0xe5_PUSH;
    (opcodes->up)[0xe5].length = 1;
    (opcodes->up)[0xe5].cycles[0] = 16;
    (opcodes->up)[0xe5].cycles[1] = 16;

    (opcodes->up)[0xe6].mnemonic = "AND";
    (opcodes->up)[0xe6].func = &opcode_up_0xe6_AND;
    (opcodes->up)[0xe6].length = 2;
    (opcodes->up)[0xe6].cycles[0] = 8;
    (opcodes->up)[0xe6].cycles[1] = 8;

    (opcodes->up)[0xe7].mnemonic = "RST";
    (opcodes->up)[0xe7].func = &opcode_up_0xe7_RST;
    (opcodes->up)[0xe7].length = 1;
    (opcodes->up)[0xe7].cycles[0] = 16;
    (opcodes->up)[0xe7].cycles[1] = 16;

    (opcodes->up)[0xe8].mnemonic = "ADD";
    (opcodes->up)[0xe8].func = &opcode_up_0xe8_ADD;
    (opcodes->up)[0xe8].length = 2;
    (opcodes->up)[0xe8].cycles[0] = 16;
    (opcodes->up)[0xe8].cycles[1] = 16;

    (opcodes->up)[0xe9].mnemonic = "JP";
    (opcodes->up)[0xe9].func = &opcode_up_0xe9_JP;
    (opcodes->up)[0xe9].length = 1;
    (opcodes->up)[0xe9].cycles[0] = 4;
    (opcodes->up)[0xe9].cycles[1] = 4;

    (opcodes->up)[0xea].mnemonic = "LD";
    (opcodes->up)[0xea].func = &opcode_up_0xea_LD;
    (opcodes->up)[0xea].length = 3;
    (opcodes->up)[0xea].cycles[0] = 16;
    (opcodes->up)[0xea].cycles[1] = 16;

    (opcodes->up)[0xee].mnemonic = "XOR";
    (opcodes->up)[0xee].func = &opcode_up_0xee_XOR;
    (opcodes->up)[0xee].length = 2;
    (opcodes->up)[0xee].cycles[0] = 8;
    (opcodes->up)[0xee].cycles[1] = 8;

    (opcodes->up)[0xef].mnemonic = "RST";
    (opcodes->up)[0xef].func = &opcode_up_0xef_RST;
    (opcodes->up)[0xef].length = 1;
    (opcodes->up)[0xef].cycles[0] = 16;
    (opcodes->up)[0xef].cycles[1] = 16;

    (opcodes->up)[0xf0].mnemonic = "LDH";
    (opcodes->up)[0xf0].func = &opcode_up_0xf0_LDH;
    (opcodes->up)[0xf0].length = 2;
    (opcodes->up)[0xf0].cycles[0] = 12;
    (opcodes->up)[0xf0].cycles[1] = 12;

    (opcodes->up)[0xf1].mnemonic = "POP";
    (opcodes->up)[0xf1].func = &opcode_up_0xf1_POP;
    (opcodes->up)[0xf1].length = 1;
    (opcodes->up)[0xf1].cycles[0] = 12;
    (opcodes->up)[0xf1].cycles[1] = 12;

    (opcodes->up)[0xf2].mnemonic = "LD";
    (opcodes->up)[0xf2].func = &opcode_up_0xf2_LD;
    (opcodes->up)[0xf2].length = 2;
    (opcodes->up)[0xf2].cycles[0] = 8;
    (opcodes->up)[0xf2].cycles[1] = 8;

    (opcodes->up)[0xf3].mnemonic = "DI";
    (opcodes->up)[0xf3].func = &opcode_up_0xf3_DI;
    (opcodes->up)[0xf3].length = 1;
    (opcodes->up)[0xf3].cycles[0] = 4;
    (opcodes->up)[0xf3].cycles[1] = 4;

    (opcodes->up)[0xf5].mnemonic = "PUSH";
    (opcodes->up)[0xf5].func = &opcode_up_0xf5_PUSH;
    (opcodes->up)[0xf5].length = 1;
    (opcodes->up)[0xf5].cycles[0] = 16;
    (opcodes->up)[0xf5].cycles[1] = 16;

    (opcodes->up)[0xf6].mnemonic = "OR";
    (opcodes->up)[0xf6].func = &opcode_up_0xf6_OR;
    (opcodes->up)[0xf6].length = 2;
    (opcodes->up)[0xf6].cycles[0] = 8;
    (opcodes->up)[0xf6].cycles[1] = 8;

    (opcodes->up)[0xf7].mnemonic = "RST";
    (opcodes->up)[0xf7].func = &opcode_up_0xf7_RST;
    (opcodes->up)[0xf7].length = 1;
    (opcodes->up)[0xf7].cycles[0] = 16;
    (opcodes->up)[0xf7].cycles[1] = 16;

    (opcodes->up)[0xf8].mnemonic = "LD";
    (opcodes->up)[0xf8].func = &opcode_up_0xf8_LD;
    (opcodes->up)[0xf8].length = 2;
    (opcodes->up)[0xf8].cycles[0] = 12;
    (opcodes->up)[0xf8].cycles[1] = 12;

    (opcodes->up)[0xf9].mnemonic = "LD";
    (opcodes->up)[0xf9].func = &opcode_up_0xf9_LD;
    (opcodes->up)[0xf9].length = 1;
    (opcodes->up)[0xf9].cycles[0] = 8;
    (opcodes->up)[0xf9].cycles[1] = 8;

    (opcodes->up)[0xfa].mnemonic = "LD";
    (opcodes->up)[0xfa].func = &opcode_up_0xfa_LD;
    (opcodes->up)[0xfa].length = 3;
    (opcodes->up)[0xfa].cycles[0] = 16;
    (opcodes->up)[0xfa].cycles[1] = 16;

    (opcodes->up)[0xfb].mnemonic = "EI";
    (opcodes->up)[0xfb].func = &opcode_up_0xfb_EI;
    (opcodes->up)[0xfb].length = 1;
    (opcodes->up)[0xfb].cycles[0] = 4;
    (opcodes->up)[0xfb].cycles[1] = 4;

    (opcodes->up)[0xfe].mnemonic = "CP";
    (opcodes->up)[0xfe].func = &opcode_up_0xfe_CP;
    (opcodes->up)[0xfe].length = 2;
    (opcodes->up)[0xfe].cycles[0] = 8;
    (opcodes->up)[0xfe].cycles[1] = 8;

    (opcodes->up)[0xff].mnemonic = "RST";
    (opcodes->up)[0xff].func = &opcode_up_0xff_RST;
    (opcodes->up)[0xff].length = 1;
    (opcodes->up)[0xff].cycles[0] = 16;
    (opcodes->up)[0xff].cycles[1] = 16;

    (opcodes->cb)[0x0].mnemonic = "RLC";
    (opcodes->cb)[0x0].func = &opcode_cb_0x0_RLC;
    (opcodes->cb)[0x0].length = 2;
    (opcodes->cb)[0x0].cycles[0] = 8;
    (opcodes->cb)[0x0].cycles[1] = 8;

    (opcodes->cb)[0x1].mnemonic = "RLC";
    (opcodes->cb)[0x1].func = &opcode_cb_0x1_RLC;
    (opcodes->cb)[0x1].length = 2;
    (opcodes->cb)[0x1].cycles[0] = 8;
    (opcodes->cb)[0x1].cycles[1] = 8;

    (opcodes->cb)[0x2].mnemonic = "RLC";
    (opcodes->cb)[0x2].func = &opcode_cb_0x2_RLC;
    (opcodes->cb)[0x2].length = 2;
    (opcodes->cb)[0x2].cycles[0] = 8;
    (opcodes->cb)[0x2].cycles[1] = 8;

    (opcodes->cb)[0x3].mnemonic = "RLC";
    (opcodes->cb)[0x3].func = &opcode_cb_0x3_RLC;
    (opcodes->cb)[0x3].length = 2;
    (opcodes->cb)[0x3].cycles[0] = 8;
    (opcodes->cb)[0x3].cycles[1] = 8;

    (opcodes->cb)[0x4].mnemonic = "RLC";
    (opcodes->cb)[0x4].func = &opcode_cb_0x4_RLC;
    (opcodes->cb)[0x4].length = 2;
    (opcodes->cb)[0x4].cycles[0] = 8;
    (opcodes->cb)[0x4].cycles[1] = 8;

    (opcodes->cb)[0x5].mnemonic = "RLC";
    (opcodes->cb)[0x5].func = &opcode_cb_0x5_RLC;
    (opcodes->cb)[0x5].length = 2;
    (opcodes->cb)[0x5].cycles[0] = 8;
    (opcodes->cb)[0x5].cycles[1] = 8;

    (opcodes->cb)[0x6].mnemonic = "RLC";
    (opcodes->cb)[0x6].func = &opcode_cb_0x6_RLC;
    (opcodes->cb)[0x6].length = 2;
    (opcodes->cb)[0x6].cycles[0] = 16;
    (opcodes->cb)[0x6].cycles[1] = 16;

    (opcodes->cb)[0x7].mnemonic = "RLC";
    (opcodes->cb)[0x7].func = &opcode_cb_0x7_RLC;
    (opcodes->cb)[0x7].length = 2;
    (opcodes->cb)[0x7].cycles[0] = 8;
    (opcodes->cb)[0x7].cycles[1] = 8;

    (opcodes->cb)[0x8].mnemonic = "RRC";
    (opcodes->cb)[0x8].func = &opcode_cb_0x8_RRC;
    (opcodes->cb)[0x8].length = 2;
    (opcodes->cb)[0x8].cycles[0] = 8;
    (opcodes->cb)[0x8].cycles[1] = 8;

    (opcodes->cb)[0x9].mnemonic = "RRC";
    (opcodes->cb)[0x9].func = &opcode_cb_0x9_RRC;
    (opcodes->cb)[0x9].length = 2;
    (opcodes->cb)[0x9].cycles[0] = 8;
    (opcodes->cb)[0x9].cycles[1] = 8;

    (opcodes->cb)[0xa].mnemonic = "RRC";
    (opcodes->cb)[0xa].func = &opcode_cb_0xa_RRC;
    (opcodes->cb)[0xa].length = 2;
    (opcodes->cb)[0xa].cycles[0] = 8;
    (opcodes->cb)[0xa].cycles[1] = 8;

    (opcodes->cb)[0xb].mnemonic = "RRC";
    (opcodes->cb)[0xb].func = &opcode_cb_0xb_RRC;
    (opcodes->cb)[0xb].length = 2;
    (opcodes->cb)[0xb].cycles[0] = 8;
    (opcodes->cb)[0xb].cycles[1] = 8;

    (opcodes->cb)[0xc].mnemonic = "RRC";
    (opcodes->cb)[0xc].func = &opcode_cb_0xc_RRC;
    (opcodes->cb)[0xc].length = 2;
    (opcodes->cb)[0xc].cycles[0] = 8;
    (opcodes->cb)[0xc].cycles[1] = 8;

    (opcodes->cb)[0xd].mnemonic = "RRC";
    (opcodes->cb)[0xd].func = &opcode_cb_0xd_RRC;
    (opcodes->cb)[0xd].length = 2;
    (opcodes->cb)[0xd].cycles[0] = 8;
    (opcodes->cb)[0xd].cycles[1] = 8;

    (opcodes->cb)[0xe].mnemonic = "RRC";
    (opcodes->cb)[0xe].func = &opcode_cb_0xe_RRC;
    (opcodes->cb)[0xe].length = 2;
    (opcodes->cb)[0xe].cycles[0] = 16;
    (opcodes->cb)[0xe].cycles[1] = 16;

    (opcodes->cb)[0xf].mnemonic = "RRC";
    (opcodes->cb)[0xf].func = &opcode_cb_0xf_RRC;
    (opcodes->cb)[0xf].length = 2;
    (opcodes->cb)[0xf].cycles[0] = 8;
    (opcodes->cb)[0xf].cycles[1] = 8;

    (opcodes->cb)[0x10].mnemonic = "RL";
    (opcodes->cb)[0x10].func = &opcode_cb_0x10_RL;
    (opcodes->cb)[0x10].length = 2;
    (opcodes->cb)[0x10].cycles[0] = 8;
    (opcodes->cb)[0x10].cycles[1] = 8;

    (opcodes->cb)[0x11].mnemonic = "RL";
    (opcodes->cb)[0x11].func = &opcode_cb_0x11_RL;
    (opcodes->cb)[0x11].length = 2;
    (opcodes->cb)[0x11].cycles[0] = 8;
    (opcodes->cb)[0x11].cycles[1] = 8;

    (opcodes->cb)[0x12].mnemonic = "RL";
    (opcodes->cb)[0x12].func = &opcode_cb_0x12_RL;
    (opcodes->cb)[0x12].length = 2;
    (opcodes->cb)[0x12].cycles[0] = 8;
    (opcodes->cb)[0x12].cycles[1] = 8;

    (opcodes->cb)[0x13].mnemonic = "RL";
    (opcodes->cb)[0x13].func = &opcode_cb_0x13_RL;
    (opcodes->cb)[0x13].length = 2;
    (opcodes->cb)[0x13].cycles[0] = 8;
    (opcodes->cb)[0x13].cycles[1] = 8;

    (opcodes->cb)[0x14].mnemonic = "RL";
    (opcodes->cb)[0x14].func = &opcode_cb_0x14_RL;
    (opcodes->cb)[0x14].length = 2;
    (opcodes->cb)[0x14].cycles[0] = 8;
    (opcodes->cb)[0x14].cycles[1] = 8;

    (opcodes->cb)[0x15].mnemonic = "RL";
    (opcodes->cb)[0x15].func = &opcode_cb_0x15_RL;
    (opcodes->cb)[0x15].length = 2;
    (opcodes->cb)[0x15].cycles[0] = 8;
    (opcodes->cb)[0x15].cycles[1] = 8;

    (opcodes->cb)[0x16].mnemonic = "RL";
    (opcodes->cb)[0x16].func = &opcode_cb_0x16_RL;
    (opcodes->cb)[0x16].length = 2;
    (opcodes->cb)[0x16].cycles[0] = 16;
    (opcodes->cb)[0x16].cycles[1] = 16;

    (opcodes->cb)[0x17].mnemonic = "RL";
    (opcodes->cb)[0x17].func = &opcode_cb_0x17_RL;
    (opcodes->cb)[0x17].length = 2;
    (opcodes->cb)[0x17].cycles[0] = 8;
    (opcodes->cb)[0x17].cycles[1] = 8;

    (opcodes->cb)[0x18].mnemonic = "RR";
    (opcodes->cb)[0x18].func = &opcode_cb_0x18_RR;
    (opcodes->cb)[0x18].length = 2;
    (opcodes->cb)[0x18].cycles[0] = 8;
    (opcodes->cb)[0x18].cycles[1] = 8;

    (opcodes->cb)[0x19].mnemonic = "RR";
    (opcodes->cb)[0x19].func = &opcode_cb_0x19_RR;
    (opcodes->cb)[0x19].length = 2;
    (opcodes->cb)[0x19].cycles[0] = 8;
    (opcodes->cb)[0x19].cycles[1] = 8;

    (opcodes->cb)[0x1a].mnemonic = "RR";
    (opcodes->cb)[0x1a].func = &opcode_cb_0x1a_RR;
    (opcodes->cb)[0x1a].length = 2;
    (opcodes->cb)[0x1a].cycles[0] = 8;
    (opcodes->cb)[0x1a].cycles[1] = 8;

    (opcodes->cb)[0x1b].mnemonic = "RR";
    (opcodes->cb)[0x1b].func = &opcode_cb_0x1b_RR;
    (opcodes->cb)[0x1b].length = 2;
    (opcodes->cb)[0x1b].cycles[0] = 8;
    (opcodes->cb)[0x1b].cycles[1] = 8;

    (opcodes->cb)[0x1c].mnemonic = "RR";
    (opcodes->cb)[0x1c].func = &opcode_cb_0x1c_RR;
    (opcodes->cb)[0x1c].length = 2;
    (opcodes->cb)[0x1c].cycles[0] = 8;
    (opcodes->cb)[0x1c].cycles[1] = 8;

    (opcodes->cb)[0x1d].mnemonic = "RR";
    (opcodes->cb)[0x1d].func = &opcode_cb_0x1d_RR;
    (opcodes->cb)[0x1d].length = 2;
    (opcodes->cb)[0x1d].cycles[0] = 8;
    (opcodes->cb)[0x1d].cycles[1] = 8;

    (opcodes->cb)[0x1e].mnemonic = "RR";
    (opcodes->cb)[0x1e].func = &opcode_cb_0x1e_RR;
    (opcodes->cb)[0x1e].length = 2;
    (opcodes->cb)[0x1e].cycles[0] = 16;
    (opcodes->cb)[0x1e].cycles[1] = 16;

    (opcodes->cb)[0x1f].mnemonic = "RR";
    (opcodes->cb)[0x1f].func = &opcode_cb_0x1f_RR;
    (opcodes->cb)[0x1f].length = 2;
    (opcodes->cb)[0x1f].cycles[0] = 8;
    (opcodes->cb)[0x1f].cycles[1] = 8;

    (opcodes->cb)[0x20].mnemonic = "SLA";
    (opcodes->cb)[0x20].func = &opcode_cb_0x20_SLA;
    (opcodes->cb)[0x20].length = 2;
    (opcodes->cb)[0x20].cycles[0] = 8;
    (opcodes->cb)[0x20].cycles[1] = 8;

    (opcodes->cb)[0x21].mnemonic = "SLA";
    (opcodes->cb)[0x21].func = &opcode_cb_0x21_SLA;
    (opcodes->cb)[0x21].length = 2;
    (opcodes->cb)[0x21].cycles[0] = 8;
    (opcodes->cb)[0x21].cycles[1] = 8;

    (opcodes->cb)[0x22].mnemonic = "SLA";
    (opcodes->cb)[0x22].func = &opcode_cb_0x22_SLA;
    (opcodes->cb)[0x22].length = 2;
    (opcodes->cb)[0x22].cycles[0] = 8;
    (opcodes->cb)[0x22].cycles[1] = 8;

    (opcodes->cb)[0x23].mnemonic = "SLA";
    (opcodes->cb)[0x23].func = &opcode_cb_0x23_SLA;
    (opcodes->cb)[0x23].length = 2;
    (opcodes->cb)[0x23].cycles[0] = 8;
    (opcodes->cb)[0x23].cycles[1] = 8;

    (opcodes->cb)[0x24].mnemonic = "SLA";
    (opcodes->cb)[0x24].func = &opcode_cb_0x24_SLA;
    (opcodes->cb)[0x24].length = 2;
    (opcodes->cb)[0x24].cycles[0] = 8;
    (opcodes->cb)[0x24].cycles[1] = 8;

    (opcodes->cb)[0x25].mnemonic = "SLA";
    (opcodes->cb)[0x25].func = &opcode_cb_0x25_SLA;
    (opcodes->cb)[0x25].length = 2;
    (opcodes->cb)[0x25].cycles[0] = 8;
    (opcodes->cb)[0x25].cycles[1] = 8;

    (opcodes->cb)[0x26].mnemonic = "SLA";
    (opcodes->cb)[0x26].func = &opcode_cb_0x26_SLA;
    (opcodes->cb)[0x26].length = 2;
    (opcodes->cb)[0x26].cycles[0] = 16;
    (opcodes->cb)[0x26].cycles[1] = 16;

    (opcodes->cb)[0x27].mnemonic = "SLA";
    (opcodes->cb)[0x27].func = &opcode_cb_0x27_SLA;
    (opcodes->cb)[0x27].length = 2;
    (opcodes->cb)[0x27].cycles[0] = 8;
    (opcodes->cb)[0x27].cycles[1] = 8;

    (opcodes->cb)[0x28].mnemonic = "SRA";
    (opcodes->cb)[0x28].func = &opcode_cb_0x28_SRA;
    (opcodes->cb)[0x28].length = 2;
    (opcodes->cb)[0x28].cycles[0] = 8;
    (opcodes->cb)[0x28].cycles[1] = 8;

    (opcodes->cb)[0x29].mnemonic = "SRA";
    (opcodes->cb)[0x29].func = &opcode_cb_0x29_SRA;
    (opcodes->cb)[0x29].length = 2;
    (opcodes->cb)[0x29].cycles[0] = 8;
    (opcodes->cb)[0x29].cycles[1] = 8;

    (opcodes->cb)[0x2a].mnemonic = "SRA";
    (opcodes->cb)[0x2a].func = &opcode_cb_0x2a_SRA;
    (opcodes->cb)[0x2a].length = 2;
    (opcodes->cb)[0x2a].cycles[0] = 8;
    (opcodes->cb)[0x2a].cycles[1] = 8;

    (opcodes->cb)[0x2b].mnemonic = "SRA";
    (opcodes->cb)[0x2b].func = &opcode_cb_0x2b_SRA;
    (opcodes->cb)[0x2b].length = 2;
    (opcodes->cb)[0x2b].cycles[0] = 8;
    (opcodes->cb)[0x2b].cycles[1] = 8;

    (opcodes->cb)[0x2c].mnemonic = "SRA";
    (opcodes->cb)[0x2c].func = &opcode_cb_0x2c_SRA;
    (opcodes->cb)[0x2c].length = 2;
    (opcodes->cb)[0x2c].cycles[0] = 8;
    (opcodes->cb)[0x2c].cycles[1] = 8;

    (opcodes->cb)[0x2d].mnemonic = "SRA";
    (opcodes->cb)[0x2d].func = &opcode_cb_0x2d_SRA;
    (opcodes->cb)[0x2d].length = 2;
    (opcodes->cb)[0x2d].cycles[0] = 8;
    (opcodes->cb)[0x2d].cycles[1] = 8;

    (opcodes->cb)[0x2e].mnemonic = "SRA";
    (opcodes->cb)[0x2e].func = &opcode_cb_0x2e_SRA;
    (opcodes->cb)[0x2e].length = 2;
    (opcodes->cb)[0x2e].cycles[0] = 16;
    (opcodes->cb)[0x2e].cycles[1] = 16;

    (opcodes->cb)[0x2f].mnemonic = "SRA";
    (opcodes->cb)[0x2f].func = &opcode_cb_0x2f_SRA;
    (opcodes->cb)[0x2f].length = 2;
    (opcodes->cb)[0x2f].cycles[0] = 8;
    (opcodes->cb)[0x2f].cycles[1] = 8;

    (opcodes->cb)[0x30].mnemonic = "SWAP";
    (opcodes->cb)[0x30].func = &opcode_cb_0x30_SWAP;
    (opcodes->cb)[0x30].length = 2;
    (opcodes->cb)[0x30].cycles[0] = 8;
    (opcodes->cb)[0x30].cycles[1] = 8;

    (opcodes->cb)[0x31].mnemonic = "SWAP";
    (opcodes->cb)[0x31].func = &opcode_cb_0x31_SWAP;
    (opcodes->cb)[0x31].length = 2;
    (opcodes->cb)[0x31].cycles[0] = 8;
    (opcodes->cb)[0x31].cycles[1] = 8;

    (opcodes->cb)[0x32].mnemonic = "SWAP";
    (opcodes->cb)[0x32].func = &opcode_cb_0x32_SWAP;
    (opcodes->cb)[0x32].length = 2;
    (opcodes->cb)[0x32].cycles[0] = 8;
    (opcodes->cb)[0x32].cycles[1] = 8;

    (opcodes->cb)[0x33].mnemonic = "SWAP";
    (opcodes->cb)[0x33].func = &opcode_cb_0x33_SWAP;
    (opcodes->cb)[0x33].length = 2;
    (opcodes->cb)[0x33].cycles[0] = 8;
    (opcodes->cb)[0x33].cycles[1] = 8;

    (opcodes->cb)[0x34].mnemonic = "SWAP";
    (opcodes->cb)[0x34].func = &opcode_cb_0x34_SWAP;
    (opcodes->cb)[0x34].length = 2;
    (opcodes->cb)[0x34].cycles[0] = 8;
    (opcodes->cb)[0x34].cycles[1] = 8;

    (opcodes->cb)[0x35].mnemonic = "SWAP";
    (opcodes->cb)[0x35].func = &opcode_cb_0x35_SWAP;
    (opcodes->cb)[0x35].length = 2;
    (opcodes->cb)[0x35].cycles[0] = 8;
    (opcodes->cb)[0x35].cycles[1] = 8;

    (opcodes->cb)[0x36].mnemonic = "SWAP";
    (opcodes->cb)[0x36].func = &opcode_cb_0x36_SWAP;
    (opcodes->cb)[0x36].length = 2;
    (opcodes->cb)[0x36].cycles[0] = 16;
    (opcodes->cb)[0x36].cycles[1] = 16;

    (opcodes->cb)[0x37].mnemonic = "SWAP";
    (opcodes->cb)[0x37].func = &opcode_cb_0x37_SWAP;
    (opcodes->cb)[0x37].length = 2;
    (opcodes->cb)[0x37].cycles[0] = 8;
    (opcodes->cb)[0x37].cycles[1] = 8;

    (opcodes->cb)[0x38].mnemonic = "SRL";
    (opcodes->cb)[0x38].func = &opcode_cb_0x38_SRL;
    (opcodes->cb)[0x38].length = 2;
    (opcodes->cb)[0x38].cycles[0] = 8;
    (opcodes->cb)[0x38].cycles[1] = 8;

    (opcodes->cb)[0x39].mnemonic = "SRL";
    (opcodes->cb)[0x39].func = &opcode_cb_0x39_SRL;
    (opcodes->cb)[0x39].length = 2;
    (opcodes->cb)[0x39].cycles[0] = 8;
    (opcodes->cb)[0x39].cycles[1] = 8;

    (opcodes->cb)[0x3a].mnemonic = "SRL";
    (opcodes->cb)[0x3a].func = &opcode_cb_0x3a_SRL;
    (opcodes->cb)[0x3a].length = 2;
    (opcodes->cb)[0x3a].cycles[0] = 8;
    (opcodes->cb)[0x3a].cycles[1] = 8;

    (opcodes->cb)[0x3b].mnemonic = "SRL";
    (opcodes->cb)[0x3b].func = &opcode_cb_0x3b_SRL;
    (opcodes->cb)[0x3b].length = 2;
    (opcodes->cb)[0x3b].cycles[0] = 8;
    (opcodes->cb)[0x3b].cycles[1] = 8;

    (opcodes->cb)[0x3c].mnemonic = "SRL";
    (opcodes->cb)[0x3c].func = &opcode_cb_0x3c_SRL;
    (opcodes->cb)[0x3c].length = 2;
    (opcodes->cb)[0x3c].cycles[0] = 8;
    (opcodes->cb)[0x3c].cycles[1] = 8;

    (opcodes->cb)[0x3d].mnemonic = "SRL";
    (opcodes->cb)[0x3d].func = &opcode_cb_0x3d_SRL;
    (opcodes->cb)[0x3d].length = 2;
    (opcodes->cb)[0x3d].cycles[0] = 8;
    (opcodes->cb)[0x3d].cycles[1] = 8;

    (opcodes->cb)[0x3e].mnemonic = "SRL";
    (opcodes->cb)[0x3e].func = &opcode_cb_0x3e_SRL;
    (opcodes->cb)[0x3e].length = 2;
    (opcodes->cb)[0x3e].cycles[0] = 16;
    (opcodes->cb)[0x3e].cycles[1] = 16;

    (opcodes->cb)[0x3f].mnemonic = "SRL";
    (opcodes->cb)[0x3f].func = &opcode_cb_0x3f_SRL;
    (opcodes->cb)[0x3f].length = 2;
    (opcodes->cb)[0x3f].cycles[0] = 8;
    (opcodes->cb)[0x3f].cycles[1] = 8;

    (opcodes->cb)[0x40].mnemonic = "BIT";
    (opcodes->cb)[0x40].func = &opcode_cb_0x40_BIT;
    (opcodes->cb)[0x40].length = 2;
    (opcodes->cb)[0x40].cycles[0] = 8;
    (opcodes->cb)[0x40].cycles[1] = 8;

    (opcodes->cb)[0x41].mnemonic = "BIT";
    (opcodes->cb)[0x41].func = &opcode_cb_0x41_BIT;
    (opcodes->cb)[0x41].length = 2;
    (opcodes->cb)[0x41].cycles[0] = 8;
    (opcodes->cb)[0x41].cycles[1] = 8;

    (opcodes->cb)[0x42].mnemonic = "BIT";
    (opcodes->cb)[0x42].func = &opcode_cb_0x42_BIT;
    (opcodes->cb)[0x42].length = 2;
    (opcodes->cb)[0x42].cycles[0] = 8;
    (opcodes->cb)[0x42].cycles[1] = 8;

    (opcodes->cb)[0x43].mnemonic = "BIT";
    (opcodes->cb)[0x43].func = &opcode_cb_0x43_BIT;
    (opcodes->cb)[0x43].length = 2;
    (opcodes->cb)[0x43].cycles[0] = 8;
    (opcodes->cb)[0x43].cycles[1] = 8;

    (opcodes->cb)[0x44].mnemonic = "BIT";
    (opcodes->cb)[0x44].func = &opcode_cb_0x44_BIT;
    (opcodes->cb)[0x44].length = 2;
    (opcodes->cb)[0x44].cycles[0] = 8;
    (opcodes->cb)[0x44].cycles[1] = 8;

    (opcodes->cb)[0x45].mnemonic = "BIT";
    (opcodes->cb)[0x45].func = &opcode_cb_0x45_BIT;
    (opcodes->cb)[0x45].length = 2;
    (opcodes->cb)[0x45].cycles[0] = 8;
    (opcodes->cb)[0x45].cycles[1] = 8;

    (opcodes->cb)[0x46].mnemonic = "BIT";
    (opcodes->cb)[0x46].func = &opcode_cb_0x46_BIT;
    (opcodes->cb)[0x46].length = 2;
    (opcodes->cb)[0x46].cycles[0] = 16;
    (opcodes->cb)[0x46].cycles[1] = 16;

    (opcodes->cb)[0x47].mnemonic = "BIT";
    (opcodes->cb)[0x47].func = &opcode_cb_0x47_BIT;
    (opcodes->cb)[0x47].length = 2;
    (opcodes->cb)[0x47].cycles[0] = 8;
    (opcodes->cb)[0x47].cycles[1] = 8;

    (opcodes->cb)[0x48].mnemonic = "BIT";
    (opcodes->cb)[0x48].func = &opcode_cb_0x48_BIT;
    (opcodes->cb)[0x48].length = 2;
    (opcodes->cb)[0x48].cycles[0] = 8;
    (opcodes->cb)[0x48].cycles[1] = 8;

    (opcodes->cb)[0x49].mnemonic = "BIT";
    (opcodes->cb)[0x49].func = &opcode_cb_0x49_BIT;
    (opcodes->cb)[0x49].length = 2;
    (opcodes->cb)[0x49].cycles[0] = 8;
    (opcodes->cb)[0x49].cycles[1] = 8;

    (opcodes->cb)[0x4a].mnemonic = "BIT";
    (opcodes->cb)[0x4a].func = &opcode_cb_0x4a_BIT;
    (opcodes->cb)[0x4a].length = 2;
    (opcodes->cb)[0x4a].cycles[0] = 8;
    (opcodes->cb)[0x4a].cycles[1] = 8;

    (opcodes->cb)[0x4b].mnemonic = "BIT";
    (opcodes->cb)[0x4b].func = &opcode_cb_0x4b_BIT;
    (opcodes->cb)[0x4b].length = 2;
    (opcodes->cb)[0x4b].cycles[0] = 8;
    (opcodes->cb)[0x4b].cycles[1] = 8;

    (opcodes->cb)[0x4c].mnemonic = "BIT";
    (opcodes->cb)[0x4c].func = &opcode_cb_0x4c_BIT;
    (opcodes->cb)[0x4c].length = 2;
    (opcodes->cb)[0x4c].cycles[0] = 8;
    (opcodes->cb)[0x4c].cycles[1] = 8;

    (opcodes->cb)[0x4d].mnemonic = "BIT";
    (opcodes->cb)[0x4d].func = &opcode_cb_0x4d_BIT;
    (opcodes->cb)[0x4d].length = 2;
    (opcodes->cb)[0x4d].cycles[0] = 8;
    (opcodes->cb)[0x4d].cycles[1] = 8;

    (opcodes->cb)[0x4e].mnemonic = "BIT";
    (opcodes->cb)[0x4e].func = &opcode_cb_0x4e_BIT;
    (opcodes->cb)[0x4e].length = 2;
    (opcodes->cb)[0x4e].cycles[0] = 16;
    (opcodes->cb)[0x4e].cycles[1] = 16;

    (opcodes->cb)[0x4f].mnemonic = "BIT";
    (opcodes->cb)[0x4f].func = &opcode_cb_0x4f_BIT;
    (opcodes->cb)[0x4f].length = 2;
    (opcodes->cb)[0x4f].cycles[0] = 8;
    (opcodes->cb)[0x4f].cycles[1] = 8;

    (opcodes->cb)[0x50].mnemonic = "BIT";
    (opcodes->cb)[0x50].func = &opcode_cb_0x50_BIT;
    (opcodes->cb)[0x50].length = 2;
    (opcodes->cb)[0x50].cycles[0] = 8;
    (opcodes->cb)[0x50].cycles[1] = 8;

    (opcodes->cb)[0x51].mnemonic = "BIT";
    (opcodes->cb)[0x51].func = &opcode_cb_0x51_BIT;
    (opcodes->cb)[0x51].length = 2;
    (opcodes->cb)[0x51].cycles[0] = 8;
    (opcodes->cb)[0x51].cycles[1] = 8;

    (opcodes->cb)[0x52].mnemonic = "BIT";
    (opcodes->cb)[0x52].func = &opcode_cb_0x52_BIT;
    (opcodes->cb)[0x52].length = 2;
    (opcodes->cb)[0x52].cycles[0] = 8;
    (opcodes->cb)[0x52].cycles[1] = 8;

    (opcodes->cb)[0x53].mnemonic = "BIT";
    (opcodes->cb)[0x53].func = &opcode_cb_0x53_BIT;
    (opcodes->cb)[0x53].length = 2;
    (opcodes->cb)[0x53].cycles[0] = 8;
    (opcodes->cb)[0x53].cycles[1] = 8;

    (opcodes->cb)[0x54].mnemonic = "BIT";
    (opcodes->cb)[0x54].func = &opcode_cb_0x54_BIT;
    (opcodes->cb)[0x54].length = 2;
    (opcodes->cb)[0x54].cycles[0] = 8;
    (opcodes->cb)[0x54].cycles[1] = 8;

    (opcodes->cb)[0x55].mnemonic = "BIT";
    (opcodes->cb)[0x55].func = &opcode_cb_0x55_BIT;
    (opcodes->cb)[0x55].length = 2;
    (opcodes->cb)[0x55].cycles[0] = 8;
    (opcodes->cb)[0x55].cycles[1] = 8;

    (opcodes->cb)[0x56].mnemonic = "BIT";
    (opcodes->cb)[0x56].func = &opcode_cb_0x56_BIT;
    (opcodes->cb)[0x56].length = 2;
    (opcodes->cb)[0x56].cycles[0] = 16;
    (opcodes->cb)[0x56].cycles[1] = 16;

    (opcodes->cb)[0x57].mnemonic = "BIT";
    (opcodes->cb)[0x57].func = &opcode_cb_0x57_BIT;
    (opcodes->cb)[0x57].length = 2;
    (opcodes->cb)[0x57].cycles[0] = 8;
    (opcodes->cb)[0x57].cycles[1] = 8;

    (opcodes->cb)[0x58].mnemonic = "BIT";
    (opcodes->cb)[0x58].func = &opcode_cb_0x58_BIT;
    (opcodes->cb)[0x58].length = 2;
    (opcodes->cb)[0x58].cycles[0] = 8;
    (opcodes->cb)[0x58].cycles[1] = 8;

    (opcodes->cb)[0x59].mnemonic = "BIT";
    (opcodes->cb)[0x59].func = &opcode_cb_0x59_BIT;
    (opcodes->cb)[0x59].length = 2;
    (opcodes->cb)[0x59].cycles[0] = 8;
    (opcodes->cb)[0x59].cycles[1] = 8;

    (opcodes->cb)[0x5a].mnemonic = "BIT";
    (opcodes->cb)[0x5a].func = &opcode_cb_0x5a_BIT;
    (opcodes->cb)[0x5a].length = 2;
    (opcodes->cb)[0x5a].cycles[0] = 8;
    (opcodes->cb)[0x5a].cycles[1] = 8;

    (opcodes->cb)[0x5b].mnemonic = "BIT";
    (opcodes->cb)[0x5b].func = &opcode_cb_0x5b_BIT;
    (opcodes->cb)[0x5b].length = 2;
    (opcodes->cb)[0x5b].cycles[0] = 8;
    (opcodes->cb)[0x5b].cycles[1] = 8;

    (opcodes->cb)[0x5c].mnemonic = "BIT";
    (opcodes->cb)[0x5c].func = &opcode_cb_0x5c_BIT;
    (opcodes->cb)[0x5c].length = 2;
    (opcodes->cb)[0x5c].cycles[0] = 8;
    (opcodes->cb)[0x5c].cycles[1] = 8;

    (opcodes->cb)[0x5d].mnemonic = "BIT";
    (opcodes->cb)[0x5d].func = &opcode_cb_0x5d_BIT;
    (opcodes->cb)[0x5d].length = 2;
    (opcodes->cb)[0x5d].cycles[0] = 8;
    (opcodes->cb)[0x5d].cycles[1] = 8;

    (opcodes->cb)[0x5e].mnemonic = "BIT";
    (opcodes->cb)[0x5e].func = &opcode_cb_0x5e_BIT;
    (opcodes->cb)[0x5e].length = 2;
    (opcodes->cb)[0x5e].cycles[0] = 16;
    (opcodes->cb)[0x5e].cycles[1] = 16;

    (opcodes->cb)[0x5f].mnemonic = "BIT";
    (opcodes->cb)[0x5f].func = &opcode_cb_0x5f_BIT;
    (opcodes->cb)[0x5f].length = 2;
    (opcodes->cb)[0x5f].cycles[0] = 8;
    (opcodes->cb)[0x5f].cycles[1] = 8;

    (opcodes->cb)[0x60].mnemonic = "BIT";
    (opcodes->cb)[0x60].func = &opcode_cb_0x60_BIT;
    (opcodes->cb)[0x60].length = 2;
    (opcodes->cb)[0x60].cycles[0] = 8;
    (opcodes->cb)[0x60].cycles[1] = 8;

    (opcodes->cb)[0x61].mnemonic = "BIT";
    (opcodes->cb)[0x61].func = &opcode_cb_0x61_BIT;
    (opcodes->cb)[0x61].length = 2;
    (opcodes->cb)[0x61].cycles[0] = 8;
    (opcodes->cb)[0x61].cycles[1] = 8;

    (opcodes->cb)[0x62].mnemonic = "BIT";
    (opcodes->cb)[0x62].func = &opcode_cb_0x62_BIT;
    (opcodes->cb)[0x62].length = 2;
    (opcodes->cb)[0x62].cycles[0] = 8;
    (opcodes->cb)[0x62].cycles[1] = 8;

    (opcodes->cb)[0x63].mnemonic = "BIT";
    (opcodes->cb)[0x63].func = &opcode_cb_0x63_BIT;
    (opcodes->cb)[0x63].length = 2;
    (opcodes->cb)[0x63].cycles[0] = 8;
    (opcodes->cb)[0x63].cycles[1] = 8;

    (opcodes->cb)[0x64].mnemonic = "BIT";
    (opcodes->cb)[0x64].func = &opcode_cb_0x64_BIT;
    (opcodes->cb)[0x64].length = 2;
    (opcodes->cb)[0x64].cycles[0] = 8;
    (opcodes->cb)[0x64].cycles[1] = 8;

    (opcodes->cb)[0x65].mnemonic = "BIT";
    (opcodes->cb)[0x65].func = &opcode_cb_0x65_BIT;
    (opcodes->cb)[0x65].length = 2;
    (opcodes->cb)[0x65].cycles[0] = 8;
    (opcodes->cb)[0x65].cycles[1] = 8;

    (opcodes->cb)[0x66].mnemonic = "BIT";
    (opcodes->cb)[0x66].func = &opcode_cb_0x66_BIT;
    (opcodes->cb)[0x66].length = 2;
    (opcodes->cb)[0x66].cycles[0] = 16;
    (opcodes->cb)[0x66].cycles[1] = 16;

    (opcodes->cb)[0x67].mnemonic = "BIT";
    (opcodes->cb)[0x67].func = &opcode_cb_0x67_BIT;
    (opcodes->cb)[0x67].length = 2;
    (opcodes->cb)[0x67].cycles[0] = 8;
    (opcodes->cb)[0x67].cycles[1] = 8;

    (opcodes->cb)[0x68].mnemonic = "BIT";
    (opcodes->cb)[0x68].func = &opcode_cb_0x68_BIT;
    (opcodes->cb)[0x68].length = 2;
    (opcodes->cb)[0x68].cycles[0] = 8;
    (opcodes->cb)[0x68].cycles[1] = 8;

    (opcodes->cb)[0x69].mnemonic = "BIT";
    (opcodes->cb)[0x69].func = &opcode_cb_0x69_BIT;
    (opcodes->cb)[0x69].length = 2;
    (opcodes->cb)[0x69].cycles[0] = 8;
    (opcodes->cb)[0x69].cycles[1] = 8;

    (opcodes->cb)[0x6a].mnemonic = "BIT";
    (opcodes->cb)[0x6a].func = &opcode_cb_0x6a_BIT;
    (opcodes->cb)[0x6a].length = 2;
    (opcodes->cb)[0x6a].cycles[0] = 8;
    (opcodes->cb)[0x6a].cycles[1] = 8;

    (opcodes->cb)[0x6b].mnemonic = "BIT";
    (opcodes->cb)[0x6b].func = &opcode_cb_0x6b_BIT;
    (opcodes->cb)[0x6b].length = 2;
    (opcodes->cb)[0x6b].cycles[0] = 8;
    (opcodes->cb)[0x6b].cycles[1] = 8;

    (opcodes->cb)[0x6c].mnemonic = "BIT";
    (opcodes->cb)[0x6c].func = &opcode_cb_0x6c_BIT;
    (opcodes->cb)[0x6c].length = 2;
    (opcodes->cb)[0x6c].cycles[0] = 8;
    (opcodes->cb)[0x6c].cycles[1] = 8;

    (opcodes->cb)[0x6d].mnemonic = "BIT";
    (opcodes->cb)[0x6d].func = &opcode_cb_0x6d_BIT;
    (opcodes->cb)[0x6d].length = 2;
    (opcodes->cb)[0x6d].cycles[0] = 8;
    (opcodes->cb)[0x6d].cycles[1] = 8;

    (opcodes->cb)[0x6e].mnemonic = "BIT";
    (opcodes->cb)[0x6e].func = &opcode_cb_0x6e_BIT;
    (opcodes->cb)[0x6e].length = 2;
    (opcodes->cb)[0x6e].cycles[0] = 16;
    (opcodes->cb)[0x6e].cycles[1] = 16;

    (opcodes->cb)[0x6f].mnemonic = "BIT";
    (opcodes->cb)[0x6f].func = &opcode_cb_0x6f_BIT;
    (opcodes->cb)[0x6f].length = 2;
    (opcodes->cb)[0x6f].cycles[0] = 8;
    (opcodes->cb)[0x6f].cycles[1] = 8;

    (opcodes->cb)[0x70].mnemonic = "BIT";
    (opcodes->cb)[0x70].func = &opcode_cb_0x70_BIT;
    (opcodes->cb)[0x70].length = 2;
    (opcodes->cb)[0x70].cycles[0] = 8;
    (opcodes->cb)[0x70].cycles[1] = 8;

    (opcodes->cb)[0x71].mnemonic = "BIT";
    (opcodes->cb)[0x71].func = &opcode_cb_0x71_BIT;
    (opcodes->cb)[0x71].length = 2;
    (opcodes->cb)[0x71].cycles[0] = 8;
    (opcodes->cb)[0x71].cycles[1] = 8;

    (opcodes->cb)[0x72].mnemonic = "BIT";
    (opcodes->cb)[0x72].func = &opcode_cb_0x72_BIT;
    (opcodes->cb)[0x72].length = 2;
    (opcodes->cb)[0x72].cycles[0] = 8;
    (opcodes->cb)[0x72].cycles[1] = 8;

    (opcodes->cb)[0x73].mnemonic = "BIT";
    (opcodes->cb)[0x73].func = &opcode_cb_0x73_BIT;
    (opcodes->cb)[0x73].length = 2;
    (opcodes->cb)[0x73].cycles[0] = 8;
    (opcodes->cb)[0x73].cycles[1] = 8;

    (opcodes->cb)[0x74].mnemonic = "BIT";
    (opcodes->cb)[0x74].func = &opcode_cb_0x74_BIT;
    (opcodes->cb)[0x74].length = 2;
    (opcodes->cb)[0x74].cycles[0] = 8;
    (opcodes->cb)[0x74].cycles[1] = 8;

    (opcodes->cb)[0x75].mnemonic = "BIT";
    (opcodes->cb)[0x75].func = &opcode_cb_0x75_BIT;
    (opcodes->cb)[0x75].length = 2;
    (opcodes->cb)[0x75].cycles[0] = 8;
    (opcodes->cb)[0x75].cycles[1] = 8;

    (opcodes->cb)[0x76].mnemonic = "BIT";
    (opcodes->cb)[0x76].func = &opcode_cb_0x76_BIT;
    (opcodes->cb)[0x76].length = 2;
    (opcodes->cb)[0x76].cycles[0] = 16;
    (opcodes->cb)[0x76].cycles[1] = 16;

    (opcodes->cb)[0x77].mnemonic = "BIT";
    (opcodes->cb)[0x77].func = &opcode_cb_0x77_BIT;
    (opcodes->cb)[0x77].length = 2;
    (opcodes->cb)[0x77].cycles[0] = 8;
    (opcodes->cb)[0x77].cycles[1] = 8;

    (opcodes->cb)[0x78].mnemonic = "BIT";
    (opcodes->cb)[0x78].func = &opcode_cb_0x78_BIT;
    (opcodes->cb)[0x78].length = 2;
    (opcodes->cb)[0x78].cycles[0] = 8;
    (opcodes->cb)[0x78].cycles[1] = 8;

    (opcodes->cb)[0x79].mnemonic = "BIT";
    (opcodes->cb)[0x79].func = &opcode_cb_0x79_BIT;
    (opcodes->cb)[0x79].length = 2;
    (opcodes->cb)[0x79].cycles[0] = 8;
    (opcodes->cb)[0x79].cycles[1] = 8;

    (opcodes->cb)[0x7a].mnemonic = "BIT";
    (opcodes->cb)[0x7a].func = &opcode_cb_0x7a_BIT;
    (opcodes->cb)[0x7a].length = 2;
    (opcodes->cb)[0x7a].cycles[0] = 8;
    (opcodes->cb)[0x7a].cycles[1] = 8;

    (opcodes->cb)[0x7b].mnemonic = "BIT";
    (opcodes->cb)[0x7b].func = &opcode_cb_0x7b_BIT;
    (opcodes->cb)[0x7b].length = 2;
    (opcodes->cb)[0x7b].cycles[0] = 8;
    (opcodes->cb)[0x7b].cycles[1] = 8;

    (opcodes->cb)[0x7c].mnemonic = "BIT";
    (opcodes->cb)[0x7c].func = &opcode_cb_0x7c_BIT;
    (opcodes->cb)[0x7c].length = 2;
    (opcodes->cb)[0x7c].cycles[0] = 8;
    (opcodes->cb)[0x7c].cycles[1] = 8;

    (opcodes->cb)[0x7d].mnemonic = "BIT";
    (opcodes->cb)[0x7d].func = &opcode_cb_0x7d_BIT;
    (opcodes->cb)[0x7d].length = 2;
    (opcodes->cb)[0x7d].cycles[0] = 8;
    (opcodes->cb)[0x7d].cycles[1] = 8;

    (opcodes->cb)[0x7e].mnemonic = "BIT";
    (opcodes->cb)[0x7e].func = &opcode_cb_0x7e_BIT;
    (opcodes->cb)[0x7e].length = 2;
    (opcodes->cb)[0x7e].cycles[0] = 16;
    (opcodes->cb)[0x7e].cycles[1] = 16;

    (opcodes->cb)[0x7f].mnemonic = "BIT";
    (opcodes->cb)[0x7f].func = &opcode_cb_0x7f_BIT;
    (opcodes->cb)[0x7f].length = 2;
    (opcodes->cb)[0x7f].cycles[0] = 8;
    (opcodes->cb)[0x7f].cycles[1] = 8;

    (opcodes->cb)[0x80].mnemonic = "RES";
    (opcodes->cb)[0x80].func = &opcode_cb_0x80_RES;
    (opcodes->cb)[0x80].length = 2;
    (opcodes->cb)[0x80].cycles[0] = 8;
    (opcodes->cb)[0x80].cycles[1] = 8;

    (opcodes->cb)[0x81].mnemonic = "RES";
    (opcodes->cb)[0x81].func = &opcode_cb_0x81_RES;
    (opcodes->cb)[0x81].length = 2;
    (opcodes->cb)[0x81].cycles[0] = 8;
    (opcodes->cb)[0x81].cycles[1] = 8;

    (opcodes->cb)[0x82].mnemonic = "RES";
    (opcodes->cb)[0x82].func = &opcode_cb_0x82_RES;
    (opcodes->cb)[0x82].length = 2;
    (opcodes->cb)[0x82].cycles[0] = 8;
    (opcodes->cb)[0x82].cycles[1] = 8;

    (opcodes->cb)[0x83].mnemonic = "RES";
    (opcodes->cb)[0x83].func = &opcode_cb_0x83_RES;
    (opcodes->cb)[0x83].length = 2;
    (opcodes->cb)[0x83].cycles[0] = 8;
    (opcodes->cb)[0x83].cycles[1] = 8;

    (opcodes->cb)[0x84].mnemonic = "RES";
    (opcodes->cb)[0x84].func = &opcode_cb_0x84_RES;
    (opcodes->cb)[0x84].length = 2;
    (opcodes->cb)[0x84].cycles[0] = 8;
    (opcodes->cb)[0x84].cycles[1] = 8;

    (opcodes->cb)[0x85].mnemonic = "RES";
    (opcodes->cb)[0x85].func = &opcode_cb_0x85_RES;
    (opcodes->cb)[0x85].length = 2;
    (opcodes->cb)[0x85].cycles[0] = 8;
    (opcodes->cb)[0x85].cycles[1] = 8;

    (opcodes->cb)[0x86].mnemonic = "RES";
    (opcodes->cb)[0x86].func = &opcode_cb_0x86_RES;
    (opcodes->cb)[0x86].length = 2;
    (opcodes->cb)[0x86].cycles[0] = 16;
    (opcodes->cb)[0x86].cycles[1] = 16;

    (opcodes->cb)[0x87].mnemonic = "RES";
    (opcodes->cb)[0x87].func = &opcode_cb_0x87_RES;
    (opcodes->cb)[0x87].length = 2;
    (opcodes->cb)[0x87].cycles[0] = 8;
    (opcodes->cb)[0x87].cycles[1] = 8;

    (opcodes->cb)[0x88].mnemonic = "RES";
    (opcodes->cb)[0x88].func = &opcode_cb_0x88_RES;
    (opcodes->cb)[0x88].length = 2;
    (opcodes->cb)[0x88].cycles[0] = 8;
    (opcodes->cb)[0x88].cycles[1] = 8;

    (opcodes->cb)[0x89].mnemonic = "RES";
    (opcodes->cb)[0x89].func = &opcode_cb_0x89_RES;
    (opcodes->cb)[0x89].length = 2;
    (opcodes->cb)[0x89].cycles[0] = 8;
    (opcodes->cb)[0x89].cycles[1] = 8;

    (opcodes->cb)[0x8a].mnemonic = "RES";
    (opcodes->cb)[0x8a].func = &opcode_cb_0x8a_RES;
    (opcodes->cb)[0x8a].length = 2;
    (opcodes->cb)[0x8a].cycles[0] = 8;
    (opcodes->cb)[0x8a].cycles[1] = 8;

    (opcodes->cb)[0x8b].mnemonic = "RES";
    (opcodes->cb)[0x8b].func = &opcode_cb_0x8b_RES;
    (opcodes->cb)[0x8b].length = 2;
    (opcodes->cb)[0x8b].cycles[0] = 8;
    (opcodes->cb)[0x8b].cycles[1] = 8;

    (opcodes->cb)[0x8c].mnemonic = "RES";
    (opcodes->cb)[0x8c].func = &opcode_cb_0x8c_RES;
    (opcodes->cb)[0x8c].length = 2;
    (opcodes->cb)[0x8c].cycles[0] = 8;
    (opcodes->cb)[0x8c].cycles[1] = 8;

    (opcodes->cb)[0x8d].mnemonic = "RES";
    (opcodes->cb)[0x8d].func = &opcode_cb_0x8d_RES;
    (opcodes->cb)[0x8d].length = 2;
    (opcodes->cb)[0x8d].cycles[0] = 8;
    (opcodes->cb)[0x8d].cycles[1] = 8;

    (opcodes->cb)[0x8e].mnemonic = "RES";
    (opcodes->cb)[0x8e].func = &opcode_cb_0x8e_RES;
    (opcodes->cb)[0x8e].length = 2;
    (opcodes->cb)[0x8e].cycles[0] = 16;
    (opcodes->cb)[0x8e].cycles[1] = 16;

    (opcodes->cb)[0x8f].mnemonic = "RES";
    (opcodes->cb)[0x8f].func = &opcode_cb_0x8f_RES;
    (opcodes->cb)[0x8f].length = 2;
    (opcodes->cb)[0x8f].cycles[0] = 8;
    (opcodes->cb)[0x8f].cycles[1] = 8;

    (opcodes->cb)[0x90].mnemonic = "RES";
    (opcodes->cb)[0x90].func = &opcode_cb_0x90_RES;
    (opcodes->cb)[0x90].length = 2;
    (opcodes->cb)[0x90].cycles[0] = 8;
    (opcodes->cb)[0x90].cycles[1] = 8;

    (opcodes->cb)[0x91].mnemonic = "RES";
    (opcodes->cb)[0x91].func = &opcode_cb_0x91_RES;
    (opcodes->cb)[0x91].length = 2;
    (opcodes->cb)[0x91].cycles[0] = 8;
    (opcodes->cb)[0x91].cycles[1] = 8;

    (opcodes->cb)[0x92].mnemonic = "RES";
    (opcodes->cb)[0x92].func = &opcode_cb_0x92_RES;
    (opcodes->cb)[0x92].length = 2;
    (opcodes->cb)[0x92].cycles[0] = 8;
    (opcodes->cb)[0x92].cycles[1] = 8;

    (opcodes->cb)[0x93].mnemonic = "RES";
    (opcodes->cb)[0x93].func = &opcode_cb_0x93_RES;
    (opcodes->cb)[0x93].length = 2;
    (opcodes->cb)[0x93].cycles[0] = 8;
    (opcodes->cb)[0x93].cycles[1] = 8;

    (opcodes->cb)[0x94].mnemonic = "RES";
    (opcodes->cb)[0x94].func = &opcode_cb_0x94_RES;
    (opcodes->cb)[0x94].length = 2;
    (opcodes->cb)[0x94].cycles[0] = 8;
    (opcodes->cb)[0x94].cycles[1] = 8;

    (opcodes->cb)[0x95].mnemonic = "RES";
    (opcodes->cb)[0x95].func = &opcode_cb_0x95_RES;
    (opcodes->cb)[0x95].length = 2;
    (opcodes->cb)[0x95].cycles[0] = 8;
    (opcodes->cb)[0x95].cycles[1] = 8;

    (opcodes->cb)[0x96].mnemonic = "RES";
    (opcodes->cb)[0x96].func = &opcode_cb_0x96_RES;
    (opcodes->cb)[0x96].length = 2;
    (opcodes->cb)[0x96].cycles[0] = 16;
    (opcodes->cb)[0x96].cycles[1] = 16;

    (opcodes->cb)[0x97].mnemonic = "RES";
    (opcodes->cb)[0x97].func = &opcode_cb_0x97_RES;
    (opcodes->cb)[0x97].length = 2;
    (opcodes->cb)[0x97].cycles[0] = 8;
    (opcodes->cb)[0x97].cycles[1] = 8;

    (opcodes->cb)[0x98].mnemonic = "RES";
    (opcodes->cb)[0x98].func = &opcode_cb_0x98_RES;
    (opcodes->cb)[0x98].length = 2;
    (opcodes->cb)[0x98].cycles[0] = 8;
    (opcodes->cb)[0x98].cycles[1] = 8;

    (opcodes->cb)[0x99].mnemonic = "RES";
    (opcodes->cb)[0x99].func = &opcode_cb_0x99_RES;
    (opcodes->cb)[0x99].length = 2;
    (opcodes->cb)[0x99].cycles[0] = 8;
    (opcodes->cb)[0x99].cycles[1] = 8;

    (opcodes->cb)[0x9a].mnemonic = "RES";
    (opcodes->cb)[0x9a].func = &opcode_cb_0x9a_RES;
    (opcodes->cb)[0x9a].length = 2;
    (opcodes->cb)[0x9a].cycles[0] = 8;
    (opcodes->cb)[0x9a].cycles[1] = 8;

    (opcodes->cb)[0x9b].mnemonic = "RES";
    (opcodes->cb)[0x9b].func = &opcode_cb_0x9b_RES;
    (opcodes->cb)[0x9b].length = 2;
    (opcodes->cb)[0x9b].cycles[0] = 8;
    (opcodes->cb)[0x9b].cycles[1] = 8;

    (opcodes->cb)[0x9c].mnemonic = "RES";
    (opcodes->cb)[0x9c].func = &opcode_cb_0x9c_RES;
    (opcodes->cb)[0x9c].length = 2;
    (opcodes->cb)[0x9c].cycles[0] = 8;
    (opcodes->cb)[0x9c].cycles[1] = 8;

    (opcodes->cb)[0x9d].mnemonic = "RES";
    (opcodes->cb)[0x9d].func = &opcode_cb_0x9d_RES;
    (opcodes->cb)[0x9d].length = 2;
    (opcodes->cb)[0x9d].cycles[0] = 8;
    (opcodes->cb)[0x9d].cycles[1] = 8;

    (opcodes->cb)[0x9e].mnemonic = "RES";
    (opcodes->cb)[0x9e].func = &opcode_cb_0x9e_RES;
    (opcodes->cb)[0x9e].length = 2;
    (opcodes->cb)[0x9e].cycles[0] = 16;
    (opcodes->cb)[0x9e].cycles[1] = 16;

    (opcodes->cb)[0x9f].mnemonic = "RES";
    (opcodes->cb)[0x9f].func = &opcode_cb_0x9f_RES;
    (opcodes->cb)[0x9f].length = 2;
    (opcodes->cb)[0x9f].cycles[0] = 8;
    (opcodes->cb)[0x9f].cycles[1] = 8;

    (opcodes->cb)[0xa0].mnemonic = "RES";
    (opcodes->cb)[0xa0].func = &opcode_cb_0xa0_RES;
    (opcodes->cb)[0xa0].length = 2;
    (opcodes->cb)[0xa0].cycles[0] = 8;
    (opcodes->cb)[0xa0].cycles[1] = 8;

    (opcodes->cb)[0xa1].mnemonic = "RES";
    (opcodes->cb)[0xa1].func = &opcode_cb_0xa1_RES;
    (opcodes->cb)[0xa1].length = 2;
    (opcodes->cb)[0xa1].cycles[0] = 8;
    (opcodes->cb)[0xa1].cycles[1] = 8;

    (opcodes->cb)[0xa2].mnemonic = "RES";
    (opcodes->cb)[0xa2].func = &opcode_cb_0xa2_RES;
    (opcodes->cb)[0xa2].length = 2;
    (opcodes->cb)[0xa2].cycles[0] = 8;
    (opcodes->cb)[0xa2].cycles[1] = 8;

    (opcodes->cb)[0xa3].mnemonic = "RES";
    (opcodes->cb)[0xa3].func = &opcode_cb_0xa3_RES;
    (opcodes->cb)[0xa3].length = 2;
    (opcodes->cb)[0xa3].cycles[0] = 8;
    (opcodes->cb)[0xa3].cycles[1] = 8;

    (opcodes->cb)[0xa4].mnemonic = "RES";
    (opcodes->cb)[0xa4].func = &opcode_cb_0xa4_RES;
    (opcodes->cb)[0xa4].length = 2;
    (opcodes->cb)[0xa4].cycles[0] = 8;
    (opcodes->cb)[0xa4].cycles[1] = 8;

    (opcodes->cb)[0xa5].mnemonic = "RES";
    (opcodes->cb)[0xa5].func = &opcode_cb_0xa5_RES;
    (opcodes->cb)[0xa5].length = 2;
    (opcodes->cb)[0xa5].cycles[0] = 8;
    (opcodes->cb)[0xa5].cycles[1] = 8;

    (opcodes->cb)[0xa6].mnemonic = "RES";
    (opcodes->cb)[0xa6].func = &opcode_cb_0xa6_RES;
    (opcodes->cb)[0xa6].length = 2;
    (opcodes->cb)[0xa6].cycles[0] = 16;
    (opcodes->cb)[0xa6].cycles[1] = 16;

    (opcodes->cb)[0xa7].mnemonic = "RES";
    (opcodes->cb)[0xa7].func = &opcode_cb_0xa7_RES;
    (opcodes->cb)[0xa7].length = 2;
    (opcodes->cb)[0xa7].cycles[0] = 8;
    (opcodes->cb)[0xa7].cycles[1] = 8;

    (opcodes->cb)[0xa8].mnemonic = "RES";
    (opcodes->cb)[0xa8].func = &opcode_cb_0xa8_RES;
    (opcodes->cb)[0xa8].length = 2;
    (opcodes->cb)[0xa8].cycles[0] = 8;
    (opcodes->cb)[0xa8].cycles[1] = 8;

    (opcodes->cb)[0xa9].mnemonic = "RES";
    (opcodes->cb)[0xa9].func = &opcode_cb_0xa9_RES;
    (opcodes->cb)[0xa9].length = 2;
    (opcodes->cb)[0xa9].cycles[0] = 8;
    (opcodes->cb)[0xa9].cycles[1] = 8;

    (opcodes->cb)[0xaa].mnemonic = "RES";
    (opcodes->cb)[0xaa].func = &opcode_cb_0xaa_RES;
    (opcodes->cb)[0xaa].length = 2;
    (opcodes->cb)[0xaa].cycles[0] = 8;
    (opcodes->cb)[0xaa].cycles[1] = 8;

    (opcodes->cb)[0xab].mnemonic = "RES";
    (opcodes->cb)[0xab].func = &opcode_cb_0xab_RES;
    (opcodes->cb)[0xab].length = 2;
    (opcodes->cb)[0xab].cycles[0] = 8;
    (opcodes->cb)[0xab].cycles[1] = 8;

    (opcodes->cb)[0xac].mnemonic = "RES";
    (opcodes->cb)[0xac].func = &opcode_cb_0xac_RES;
    (opcodes->cb)[0xac].length = 2;
    (opcodes->cb)[0xac].cycles[0] = 8;
    (opcodes->cb)[0xac].cycles[1] = 8;

    (opcodes->cb)[0xad].mnemonic = "RES";
    (opcodes->cb)[0xad].func = &opcode_cb_0xad_RES;
    (opcodes->cb)[0xad].length = 2;
    (opcodes->cb)[0xad].cycles[0] = 8;
    (opcodes->cb)[0xad].cycles[1] = 8;

    (opcodes->cb)[0xae].mnemonic = "RES";
    (opcodes->cb)[0xae].func = &opcode_cb_0xae_RES;
    (opcodes->cb)[0xae].length = 2;
    (opcodes->cb)[0xae].cycles[0] = 16;
    (opcodes->cb)[0xae].cycles[1] = 16;

    (opcodes->cb)[0xaf].mnemonic = "RES";
    (opcodes->cb)[0xaf].func = &opcode_cb_0xaf_RES;
    (opcodes->cb)[0xaf].length = 2;
    (opcodes->cb)[0xaf].cycles[0] = 8;
    (opcodes->cb)[0xaf].cycles[1] = 8;

    (opcodes->cb)[0xb0].mnemonic = "RES";
    (opcodes->cb)[0xb0].func = &opcode_cb_0xb0_RES;
    (opcodes->cb)[0xb0].length = 2;
    (opcodes->cb)[0xb0].cycles[0] = 8;
    (opcodes->cb)[0xb0].cycles[1] = 8;

    (opcodes->cb)[0xb1].mnemonic = "RES";
    (opcodes->cb)[0xb1].func = &opcode_cb_0xb1_RES;
    (opcodes->cb)[0xb1].length = 2;
    (opcodes->cb)[0xb1].cycles[0] = 8;
    (opcodes->cb)[0xb1].cycles[1] = 8;

    (opcodes->cb)[0xb2].mnemonic = "RES";
    (opcodes->cb)[0xb2].func = &opcode_cb_0xb2_RES;
    (opcodes->cb)[0xb2].length = 2;
    (opcodes->cb)[0xb2].cycles[0] = 8;
    (opcodes->cb)[0xb2].cycles[1] = 8;

    (opcodes->cb)[0xb3].mnemonic = "RES";
    (opcodes->cb)[0xb3].func = &opcode_cb_0xb3_RES;
    (opcodes->cb)[0xb3].length = 2;
    (opcodes->cb)[0xb3].cycles[0] = 8;
    (opcodes->cb)[0xb3].cycles[1] = 8;

    (opcodes->cb)[0xb4].mnemonic = "RES";
    (opcodes->cb)[0xb4].func = &opcode_cb_0xb4_RES;
    (opcodes->cb)[0xb4].length = 2;
    (opcodes->cb)[0xb4].cycles[0] = 8;
    (opcodes->cb)[0xb4].cycles[1] = 8;

    (opcodes->cb)[0xb5].mnemonic = "RES";
    (opcodes->cb)[0xb5].func = &opcode_cb_0xb5_RES;
    (opcodes->cb)[0xb5].length = 2;
    (opcodes->cb)[0xb5].cycles[0] = 8;
    (opcodes->cb)[0xb5].cycles[1] = 8;

    (opcodes->cb)[0xb6].mnemonic = "RES";
    (opcodes->cb)[0xb6].func = &opcode_cb_0xb6_RES;
    (opcodes->cb)[0xb6].length = 2;
    (opcodes->cb)[0xb6].cycles[0] = 16;
    (opcodes->cb)[0xb6].cycles[1] = 16;

    (opcodes->cb)[0xb7].mnemonic = "RES";
    (opcodes->cb)[0xb7].func = &opcode_cb_0xb7_RES;
    (opcodes->cb)[0xb7].length = 2;
    (opcodes->cb)[0xb7].cycles[0] = 8;
    (opcodes->cb)[0xb7].cycles[1] = 8;

    (opcodes->cb)[0xb8].mnemonic = "RES";
    (opcodes->cb)[0xb8].func = &opcode_cb_0xb8_RES;
    (opcodes->cb)[0xb8].length = 2;
    (opcodes->cb)[0xb8].cycles[0] = 8;
    (opcodes->cb)[0xb8].cycles[1] = 8;

    (opcodes->cb)[0xb9].mnemonic = "RES";
    (opcodes->cb)[0xb9].func = &opcode_cb_0xb9_RES;
    (opcodes->cb)[0xb9].length = 2;
    (opcodes->cb)[0xb9].cycles[0] = 8;
    (opcodes->cb)[0xb9].cycles[1] = 8;

    (opcodes->cb)[0xba].mnemonic = "RES";
    (opcodes->cb)[0xba].func = &opcode_cb_0xba_RES;
    (opcodes->cb)[0xba].length = 2;
    (opcodes->cb)[0xba].cycles[0] = 8;
    (opcodes->cb)[0xba].cycles[1] = 8;

    (opcodes->cb)[0xbb].mnemonic = "RES";
    (opcodes->cb)[0xbb].func = &opcode_cb_0xbb_RES;
    (opcodes->cb)[0xbb].length = 2;
    (opcodes->cb)[0xbb].cycles[0] = 8;
    (opcodes->cb)[0xbb].cycles[1] = 8;

    (opcodes->cb)[0xbc].mnemonic = "RES";
    (opcodes->cb)[0xbc].func = &opcode_cb_0xbc_RES;
    (opcodes->cb)[0xbc].length = 2;
    (opcodes->cb)[0xbc].cycles[0] = 8;
    (opcodes->cb)[0xbc].cycles[1] = 8;

    (opcodes->cb)[0xbd].mnemonic = "RES";
    (opcodes->cb)[0xbd].func = &opcode_cb_0xbd_RES;
    (opcodes->cb)[0xbd].length = 2;
    (opcodes->cb)[0xbd].cycles[0] = 8;
    (opcodes->cb)[0xbd].cycles[1] = 8;

    (opcodes->cb)[0xbe].mnemonic = "RES";
    (opcodes->cb)[0xbe].func = &opcode_cb_0xbe_RES;
    (opcodes->cb)[0xbe].length = 2;
    (opcodes->cb)[0xbe].cycles[0] = 16;
    (opcodes->cb)[0xbe].cycles[1] = 16;

    (opcodes->cb)[0xbf].mnemonic = "RES";
    (opcodes->cb)[0xbf].func = &opcode_cb_0xbf_RES;
    (opcodes->cb)[0xbf].length = 2;
    (opcodes->cb)[0xbf].cycles[0] = 8;
    (opcodes->cb)[0xbf].cycles[1] = 8;

    (opcodes->cb)[0xc0].mnemonic = "SET";
    (opcodes->cb)[0xc0].func = &opcode_cb_0xc0_SET;
    (opcodes->cb)[0xc0].length = 2;
    (opcodes->cb)[0xc0].cycles[0] = 8;
    (opcodes->cb)[0xc0].cycles[1] = 8;

    (opcodes->cb)[0xc1].mnemonic = "SET";
    (opcodes->cb)[0xc1].func = &opcode_cb_0xc1_SET;
    (opcodes->cb)[0xc1].length = 2;
    (opcodes->cb)[0xc1].cycles[0] = 8;
    (opcodes->cb)[0xc1].cycles[1] = 8;

    (opcodes->cb)[0xc2].mnemonic = "SET";
    (opcodes->cb)[0xc2].func = &opcode_cb_0xc2_SET;
    (opcodes->cb)[0xc2].length = 2;
    (opcodes->cb)[0xc2].cycles[0] = 8;
    (opcodes->cb)[0xc2].cycles[1] = 8;

    (opcodes->cb)[0xc3].mnemonic = "SET";
    (opcodes->cb)[0xc3].func = &opcode_cb_0xc3_SET;
    (opcodes->cb)[0xc3].length = 2;
    (opcodes->cb)[0xc3].cycles[0] = 8;
    (opcodes->cb)[0xc3].cycles[1] = 8;

    (opcodes->cb)[0xc4].mnemonic = "SET";
    (opcodes->cb)[0xc4].func = &opcode_cb_0xc4_SET;
    (opcodes->cb)[0xc4].length = 2;
    (opcodes->cb)[0xc4].cycles[0] = 8;
    (opcodes->cb)[0xc4].cycles[1] = 8;

    (opcodes->cb)[0xc5].mnemonic = "SET";
    (opcodes->cb)[0xc5].func = &opcode_cb_0xc5_SET;
    (opcodes->cb)[0xc5].length = 2;
    (opcodes->cb)[0xc5].cycles[0] = 8;
    (opcodes->cb)[0xc5].cycles[1] = 8;

    (opcodes->cb)[0xc6].mnemonic = "SET";
    (opcodes->cb)[0xc6].func = &opcode_cb_0xc6_SET;
    (opcodes->cb)[0xc6].length = 2;
    (opcodes->cb)[0xc6].cycles[0] = 16;
    (opcodes->cb)[0xc6].cycles[1] = 16;

    (opcodes->cb)[0xc7].mnemonic = "SET";
    (opcodes->cb)[0xc7].func = &opcode_cb_0xc7_SET;
    (opcodes->cb)[0xc7].length = 2;
    (opcodes->cb)[0xc7].cycles[0] = 8;
    (opcodes->cb)[0xc7].cycles[1] = 8;

    (opcodes->cb)[0xc8].mnemonic = "SET";
    (opcodes->cb)[0xc8].func = &opcode_cb_0xc8_SET;
    (opcodes->cb)[0xc8].length = 2;
    (opcodes->cb)[0xc8].cycles[0] = 8;
    (opcodes->cb)[0xc8].cycles[1] = 8;

    (opcodes->cb)[0xc9].mnemonic = "SET";
    (opcodes->cb)[0xc9].func = &opcode_cb_0xc9_SET;
    (opcodes->cb)[0xc9].length = 2;
    (opcodes->cb)[0xc9].cycles[0] = 8;
    (opcodes->cb)[0xc9].cycles[1] = 8;

    (opcodes->cb)[0xca].mnemonic = "SET";
    (opcodes->cb)[0xca].func = &opcode_cb_0xca_SET;
    (opcodes->cb)[0xca].length = 2;
    (opcodes->cb)[0xca].cycles[0] = 8;
    (opcodes->cb)[0xca].cycles[1] = 8;

    (opcodes->cb)[0xcb].mnemonic = "SET";
    (opcodes->cb)[0xcb].func = &opcode_cb_0xcb_SET;
    (opcodes->cb)[0xcb].length = 2;
    (opcodes->cb)[0xcb].cycles[0] = 8;
    (opcodes->cb)[0xcb].cycles[1] = 8;

    (opcodes->cb)[0xcc].mnemonic = "SET";
    (opcodes->cb)[0xcc].func = &opcode_cb_0xcc_SET;
    (opcodes->cb)[0xcc].length = 2;
    (opcodes->cb)[0xcc].cycles[0] = 8;
    (opcodes->cb)[0xcc].cycles[1] = 8;

    (opcodes->cb)[0xcd].mnemonic = "SET";
    (opcodes->cb)[0xcd].func = &opcode_cb_0xcd_SET;
    (opcodes->cb)[0xcd].length = 2;
    (opcodes->cb)[0xcd].cycles[0] = 8;
    (opcodes->cb)[0xcd].cycles[1] = 8;

    (opcodes->cb)[0xce].mnemonic = "SET";
    (opcodes->cb)[0xce].func = &opcode_cb_0xce_SET;
    (opcodes->cb)[0xce].length = 2;
    (opcodes->cb)[0xce].cycles[0] = 16;
    (opcodes->cb)[0xce].cycles[1] = 16;

    (opcodes->cb)[0xcf].mnemonic = "SET";
    (opcodes->cb)[0xcf].func = &opcode_cb_0xcf_SET;
    (opcodes->cb)[0xcf].length = 2;
    (opcodes->cb)[0xcf].cycles[0] = 8;
    (opcodes->cb)[0xcf].cycles[1] = 8;

    (opcodes->cb)[0xd0].mnemonic = "SET";
    (opcodes->cb)[0xd0].func = &opcode_cb_0xd0_SET;
    (opcodes->cb)[0xd0].length = 2;
    (opcodes->cb)[0xd0].cycles[0] = 8;
    (opcodes->cb)[0xd0].cycles[1] = 8;

    (opcodes->cb)[0xd1].mnemonic = "SET";
    (opcodes->cb)[0xd1].func = &opcode_cb_0xd1_SET;
    (opcodes->cb)[0xd1].length = 2;
    (opcodes->cb)[0xd1].cycles[0] = 8;
    (opcodes->cb)[0xd1].cycles[1] = 8;

    (opcodes->cb)[0xd2].mnemonic = "SET";
    (opcodes->cb)[0xd2].func = &opcode_cb_0xd2_SET;
    (opcodes->cb)[0xd2].length = 2;
    (opcodes->cb)[0xd2].cycles[0] = 8;
    (opcodes->cb)[0xd2].cycles[1] = 8;

    (opcodes->cb)[0xd3].mnemonic = "SET";
    (opcodes->cb)[0xd3].func = &opcode_cb_0xd3_SET;
    (opcodes->cb)[0xd3].length = 2;
    (opcodes->cb)[0xd3].cycles[0] = 8;
    (opcodes->cb)[0xd3].cycles[1] = 8;

    (opcodes->cb)[0xd4].mnemonic = "SET";
    (opcodes->cb)[0xd4].func = &opcode_cb_0xd4_SET;
    (opcodes->cb)[0xd4].length = 2;
    (opcodes->cb)[0xd4].cycles[0] = 8;
    (opcodes->cb)[0xd4].cycles[1] = 8;

    (opcodes->cb)[0xd5].mnemonic = "SET";
    (opcodes->cb)[0xd5].func = &opcode_cb_0xd5_SET;
    (opcodes->cb)[0xd5].length = 2;
    (opcodes->cb)[0xd5].cycles[0] = 8;
    (opcodes->cb)[0xd5].cycles[1] = 8;

    (opcodes->cb)[0xd6].mnemonic = "SET";
    (opcodes->cb)[0xd6].func = &opcode_cb_0xd6_SET;
    (opcodes->cb)[0xd6].length = 2;
    (opcodes->cb)[0xd6].cycles[0] = 16;
    (opcodes->cb)[0xd6].cycles[1] = 16;

    (opcodes->cb)[0xd7].mnemonic = "SET";
    (opcodes->cb)[0xd7].func = &opcode_cb_0xd7_SET;
    (opcodes->cb)[0xd7].length = 2;
    (opcodes->cb)[0xd7].cycles[0] = 8;
    (opcodes->cb)[0xd7].cycles[1] = 8;

    (opcodes->cb)[0xd8].mnemonic = "SET";
    (opcodes->cb)[0xd8].func = &opcode_cb_0xd8_SET;
    (opcodes->cb)[0xd8].length = 2;
    (opcodes->cb)[0xd8].cycles[0] = 8;
    (opcodes->cb)[0xd8].cycles[1] = 8;

    (opcodes->cb)[0xd9].mnemonic = "SET";
    (opcodes->cb)[0xd9].func = &opcode_cb_0xd9_SET;
    (opcodes->cb)[0xd9].length = 2;
    (opcodes->cb)[0xd9].cycles[0] = 8;
    (opcodes->cb)[0xd9].cycles[1] = 8;

    (opcodes->cb)[0xda].mnemonic = "SET";
    (opcodes->cb)[0xda].func = &opcode_cb_0xda_SET;
    (opcodes->cb)[0xda].length = 2;
    (opcodes->cb)[0xda].cycles[0] = 8;
    (opcodes->cb)[0xda].cycles[1] = 8;

    (opcodes->cb)[0xdb].mnemonic = "SET";
    (opcodes->cb)[0xdb].func = &opcode_cb_0xdb_SET;
    (opcodes->cb)[0xdb].length = 2;
    (opcodes->cb)[0xdb].cycles[0] = 8;
    (opcodes->cb)[0xdb].cycles[1] = 8;

    (opcodes->cb)[0xdc].mnemonic = "SET";
    (opcodes->cb)[0xdc].func = &opcode_cb_0xdc_SET;
    (opcodes->cb)[0xdc].length = 2;
    (opcodes->cb)[0xdc].cycles[0] = 8;
    (opcodes->cb)[0xdc].cycles[1] = 8;

    (opcodes->cb)[0xdd].mnemonic = "SET";
    (opcodes->cb)[0xdd].func = &opcode_cb_0xdd_SET;
    (opcodes->cb)[0xdd].length = 2;
    (opcodes->cb)[0xdd].cycles[0] = 8;
    (opcodes->cb)[0xdd].cycles[1] = 8;

    (opcodes->cb)[0xde].mnemonic = "SET";
    (opcodes->cb)[0xde].func = &opcode_cb_0xde_SET;
    (opcodes->cb)[0xde].length = 2;
    (opcodes->cb)[0xde].cycles[0] = 16;
    (opcodes->cb)[0xde].cycles[1] = 16;

    (opcodes->cb)[0xdf].mnemonic = "SET";
    (opcodes->cb)[0xdf].func = &opcode_cb_0xdf_SET;
    (opcodes->cb)[0xdf].length = 2;
    (opcodes->cb)[0xdf].cycles[0] = 8;
    (opcodes->cb)[0xdf].cycles[1] = 8;

    (opcodes->cb)[0xe0].mnemonic = "SET";
    (opcodes->cb)[0xe0].func = &opcode_cb_0xe0_SET;
    (opcodes->cb)[0xe0].length = 2;
    (opcodes->cb)[0xe0].cycles[0] = 8;
    (opcodes->cb)[0xe0].cycles[1] = 8;

    (opcodes->cb)[0xe1].mnemonic = "SET";
    (opcodes->cb)[0xe1].func = &opcode_cb_0xe1_SET;
    (opcodes->cb)[0xe1].length = 2;
    (opcodes->cb)[0xe1].cycles[0] = 8;
    (opcodes->cb)[0xe1].cycles[1] = 8;

    (opcodes->cb)[0xe2].mnemonic = "SET";
    (opcodes->cb)[0xe2].func = &opcode_cb_0xe2_SET;
    (opcodes->cb)[0xe2].length = 2;
    (opcodes->cb)[0xe2].cycles[0] = 8;
    (opcodes->cb)[0xe2].cycles[1] = 8;

    (opcodes->cb)[0xe3].mnemonic = "SET";
    (opcodes->cb)[0xe3].func = &opcode_cb_0xe3_SET;
    (opcodes->cb)[0xe3].length = 2;
    (opcodes->cb)[0xe3].cycles[0] = 8;
    (opcodes->cb)[0xe3].cycles[1] = 8;

    (opcodes->cb)[0xe4].mnemonic = "SET";
    (opcodes->cb)[0xe4].func = &opcode_cb_0xe4_SET;
    (opcodes->cb)[0xe4].length = 2;
    (opcodes->cb)[0xe4].cycles[0] = 8;
    (opcodes->cb)[0xe4].cycles[1] = 8;

    (opcodes->cb)[0xe5].mnemonic = "SET";
    (opcodes->cb)[0xe5].func = &opcode_cb_0xe5_SET;
    (opcodes->cb)[0xe5].length = 2;
    (opcodes->cb)[0xe5].cycles[0] = 8;
    (opcodes->cb)[0xe5].cycles[1] = 8;

    (opcodes->cb)[0xe6].mnemonic = "SET";
    (opcodes->cb)[0xe6].func = &opcode_cb_0xe6_SET;
    (opcodes->cb)[0xe6].length = 2;
    (opcodes->cb)[0xe6].cycles[0] = 16;
    (opcodes->cb)[0xe6].cycles[1] = 16;

    (opcodes->cb)[0xe7].mnemonic = "SET";
    (opcodes->cb)[0xe7].func = &opcode_cb_0xe7_SET;
    (opcodes->cb)[0xe7].length = 2;
    (opcodes->cb)[0xe7].cycles[0] = 8;
    (opcodes->cb)[0xe7].cycles[1] = 8;

    (opcodes->cb)[0xe8].mnemonic = "SET";
    (opcodes->cb)[0xe8].func = &opcode_cb_0xe8_SET;
    (opcodes->cb)[0xe8].length = 2;
    (opcodes->cb)[0xe8].cycles[0] = 8;
    (opcodes->cb)[0xe8].cycles[1] = 8;

    (opcodes->cb)[0xe9].mnemonic = "SET";
    (opcodes->cb)[0xe9].func = &opcode_cb_0xe9_SET;
    (opcodes->cb)[0xe9].length = 2;
    (opcodes->cb)[0xe9].cycles[0] = 8;
    (opcodes->cb)[0xe9].cycles[1] = 8;

    (opcodes->cb)[0xea].mnemonic = "SET";
    (opcodes->cb)[0xea].func = &opcode_cb_0xea_SET;
    (opcodes->cb)[0xea].length = 2;
    (opcodes->cb)[0xea].cycles[0] = 8;
    (opcodes->cb)[0xea].cycles[1] = 8;

    (opcodes->cb)[0xeb].mnemonic = "SET";
    (opcodes->cb)[0xeb].func = &opcode_cb_0xeb_SET;
    (opcodes->cb)[0xeb].length = 2;
    (opcodes->cb)[0xeb].cycles[0] = 8;
    (opcodes->cb)[0xeb].cycles[1] = 8;

    (opcodes->cb)[0xec].mnemonic = "SET";
    (opcodes->cb)[0xec].func = &opcode_cb_0xec_SET;
    (opcodes->cb)[0xec].length = 2;
    (opcodes->cb)[0xec].cycles[0] = 8;
    (opcodes->cb)[0xec].cycles[1] = 8;

    (opcodes->cb)[0xed].mnemonic = "SET";
    (opcodes->cb)[0xed].func = &opcode_cb_0xed_SET;
    (opcodes->cb)[0xed].length = 2;
    (opcodes->cb)[0xed].cycles[0] = 8;
    (opcodes->cb)[0xed].cycles[1] = 8;

    (opcodes->cb)[0xee].mnemonic = "SET";
    (opcodes->cb)[0xee].func = &opcode_cb_0xee_SET;
    (opcodes->cb)[0xee].length = 2;
    (opcodes->cb)[0xee].cycles[0] = 16;
    (opcodes->cb)[0xee].cycles[1] = 16;

    (opcodes->cb)[0xef].mnemonic = "SET";
    (opcodes->cb)[0xef].func = &opcode_cb_0xef_SET;
    (opcodes->cb)[0xef].length = 2;
    (opcodes->cb)[0xef].cycles[0] = 8;
    (opcodes->cb)[0xef].cycles[1] = 8;

    (opcodes->cb)[0xf0].mnemonic = "SET";
    (opcodes->cb)[0xf0].func = &opcode_cb_0xf0_SET;
    (opcodes->cb)[0xf0].length = 2;
    (opcodes->cb)[0xf0].cycles[0] = 8;
    (opcodes->cb)[0xf0].cycles[1] = 8;

    (opcodes->cb)[0xf1].mnemonic = "SET";
    (opcodes->cb)[0xf1].func = &opcode_cb_0xf1_SET;
    (opcodes->cb)[0xf1].length = 2;
    (opcodes->cb)[0xf1].cycles[0] = 8;
    (opcodes->cb)[0xf1].cycles[1] = 8;

    (opcodes->cb)[0xf2].mnemonic = "SET";
    (opcodes->cb)[0xf2].func = &opcode_cb_0xf2_SET;
    (opcodes->cb)[0xf2].length = 2;
    (opcodes->cb)[0xf2].cycles[0] = 8;
    (opcodes->cb)[0xf2].cycles[1] = 8;

    (opcodes->cb)[0xf3].mnemonic = "SET";
    (opcodes->cb)[0xf3].func = &opcode_cb_0xf3_SET;
    (opcodes->cb)[0xf3].length = 2;
    (opcodes->cb)[0xf3].cycles[0] = 8;
    (opcodes->cb)[0xf3].cycles[1] = 8;

    (opcodes->cb)[0xf4].mnemonic = "SET";
    (opcodes->cb)[0xf4].func = &opcode_cb_0xf4_SET;
    (opcodes->cb)[0xf4].length = 2;
    (opcodes->cb)[0xf4].cycles[0] = 8;
    (opcodes->cb)[0xf4].cycles[1] = 8;

    (opcodes->cb)[0xf5].mnemonic = "SET";
    (opcodes->cb)[0xf5].func = &opcode_cb_0xf5_SET;
    (opcodes->cb)[0xf5].length = 2;
    (opcodes->cb)[0xf5].cycles[0] = 8;
    (opcodes->cb)[0xf5].cycles[1] = 8;

    (opcodes->cb)[0xf6].mnemonic = "SET";
    (opcodes->cb)[0xf6].func = &opcode_cb_0xf6_SET;
    (opcodes->cb)[0xf6].length = 2;
    (opcodes->cb)[0xf6].cycles[0] = 16;
    (opcodes->cb)[0xf6].cycles[1] = 16;

    (opcodes->cb)[0xf7].mnemonic = "SET";
    (opcodes->cb)[0xf7].func = &opcode_cb_0xf7_SET;
    (opcodes->cb)[0xf7].length = 2;
    (opcodes->cb)[0xf7].cycles[0] = 8;
    (opcodes->cb)[0xf7].cycles[1] = 8;

    (opcodes->cb)[0xf8].mnemonic = "SET";
    (opcodes->cb)[0xf8].func = &opcode_cb_0xf8_SET;
    (opcodes->cb)[0xf8].length = 2;
    (opcodes->cb)[0xf8].cycles[0] = 8;
    (opcodes->cb)[0xf8].cycles[1] = 8;

    (opcodes->cb)[0xf9].mnemonic = "SET";
    (opcodes->cb)[0xf9].func = &opcode_cb_0xf9_SET;
    (opcodes->cb)[0xf9].length = 2;
    (opcodes->cb)[0xf9].cycles[0] = 8;
    (opcodes->cb)[0xf9].cycles[1] = 8;

    (opcodes->cb)[0xfa].mnemonic = "SET";
    (opcodes->cb)[0xfa].func = &opcode_cb_0xfa_SET;
    (opcodes->cb)[0xfa].length = 2;
    (opcodes->cb)[0xfa].cycles[0] = 8;
    (opcodes->cb)[0xfa].cycles[1] = 8;

    (opcodes->cb)[0xfb].mnemonic = "SET";
    (opcodes->cb)[0xfb].func = &opcode_cb_0xfb_SET;
    (opcodes->cb)[0xfb].length = 2;
    (opcodes->cb)[0xfb].cycles[0] = 8;
    (opcodes->cb)[0xfb].cycles[1] = 8;

    (opcodes->cb)[0xfc].mnemonic = "SET";
    (opcodes->cb)[0xfc].func = &opcode_cb_0xfc_SET;
    (opcodes->cb)[0xfc].length = 2;
    (opcodes->cb)[0xfc].cycles[0] = 8;
    (opcodes->cb)[0xfc].cycles[1] = 8;

    (opcodes->cb)[0xfd].mnemonic = "SET";
    (opcodes->cb)[0xfd].func = &opcode_cb_0xfd_SET;
    (opcodes->cb)[0xfd].length = 2;
    (opcodes->cb)[0xfd].cycles[0] = 8;
    (opcodes->cb)[0xfd].cycles[1] = 8;

    (opcodes->cb)[0xfe].mnemonic = "SET";
    (opcodes->cb)[0xfe].func = &opcode_cb_0xfe_SET;
    (opcodes->cb)[0xfe].length = 2;
    (opcodes->cb)[0xfe].cycles[0] = 16;
    (opcodes->cb)[0xfe].cycles[1] = 16;

    (opcodes->cb)[0xff].mnemonic = "SET";
    (opcodes->cb)[0xff].func = &opcode_cb_0xff_SET;
    (opcodes->cb)[0xff].length = 2;
    (opcodes->cb)[0xff].cycles[0] = 8;
    (opcodes->cb)[0xff].cycles[1] = 8;
}
