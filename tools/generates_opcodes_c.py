#!/usr/bin/env python3

import json
from collections import OrderedDict

opcodes = json.loads(open('opcodes.json').read(), object_pairs_hook=OrderedDict)

for opcode, data in opcodes['unprefixed'].items():
    mnemonic = data['mnemonic']
    print('static void opcode_up_{}_{}(cpu_registers_t *registers, void *memory, void *arguments)'.format(opcode, mnemonic))
    print('{\n\n}\n')

for opcode, data in opcodes['cbprefixed'].items():
    mnemonic = data['mnemonic']
    print('static void opcode_cb_{}_{}(cpu_registers_t *registers, void *memory, void *arguments)'.format(opcode, mnemonic))
    print('{\n\n}\n')

for opcode, data in opcodes['unprefixed'].items():
    mnemonic = data['mnemonic']
    length = data['length']
    cycles = data['cycles']
    flags = data['flags']

    print('(opcodes->up_opcodes)[{}].mnemonic = "{}";'.format(opcode, mnemonic))
    print('(opcodes->up_opcodes)[{}].func = &opcode_up_{}_{};'.format(opcode, opcode, mnemonic))
    print('(opcodes->up_opcodes)[{}].length = {};'.format(opcode, length))
    print('(opcodes->up_opcodes)[{}].cycles[0] = {};'.format(opcode, cycles[0]))
    try:
        print('(opcodes->up_opcodes)[{}].cycles[1] = {};'.format(opcode, cycles[1]))
    except:
        print('(opcodes->up_opcodes)[{}].cycles[1] = {};'.format(opcode, cycles[0]))
    if flags[0] == 'Z':
        z = 'ONE'
    elif flags[0] == '0':
        z = 'ZERO'
    else:
        z = 'UNTOUCHED'
    if flags[1] == '1':
        n = 'ONE'
    elif flags[1] == '0':
        n = 'ZERO'
    else:
        n = 'UNTOUCHED'
    if flags[2] == 'H':
        h = 'ONE'
    elif flags[2] == '0':
        h = 'ZERO'
    else:
        h = 'UNTOUCHED'
    if flags[3] == 'C':
        c = 'ONE'
    elif flags[3] == '0':
        c = 'ZERO'
    else:
        c = 'UNTOUCHED'
    print('(opcodes->up_opcodes)[{}].flag_z = {};'.format(opcode, z))
    print('(opcodes->up_opcodes)[{}].flag_n = {};'.format(opcode, n))
    print('(opcodes->up_opcodes)[{}].flag_h = {};'.format(opcode, h))
    print('(opcodes->up_opcodes)[{}].flag_c = {};'.format(opcode, c))
    print()

for opcode, data in opcodes['cbprefixed'].items():
    mnemonic = data['mnemonic']
    length = data['length']
    cycles = data['cycles']
    flags = data['flags']

    print('(opcodes->cb_opcodes)[{}].mnemonic = "{}";'.format(opcode, mnemonic))
    print('(opcodes->cb_opcodes)[{}].func = &opcode_cb_{}_{};'.format(opcode, opcode, mnemonic))
    print('(opcodes->cb_opcodes)[{}].length = {};'.format(opcode, length))
    print('(opcodes->cb_opcodes)[{}].cycles[0] = {};'.format(opcode, cycles[0]))
    try:
        print('(opcodes->cb_opcodes)[{}].cycles[1] = {};'.format(opcode, cycles[1]))
    except:
        print('(opcodes->cb_opcodes)[{}].cycles[1] = {};'.format(opcode, cycles[0]))
    if flags[0] == 'Z':
        z = 'ONE'
    elif flags[0] == '0':
        z = 'ZERO'
    else:
        z = 'UNTOUCHED'
    if flags[1] == '1':
        n = 'ONE'
    elif flags[1] == '0':
        n = 'ZERO'
    else:
        n = 'UNTOUCHED'
    if flags[2] == 'H':
        h = 'ONE'
    elif flags[2] == '0':
        h = 'ZERO'
    else:
        h = 'UNTOUCHED'
    if flags[3] == 'C':
        c = 'ONE'
    elif flags[3] == '0':
        c = 'ZERO'
    else:
        c = 'UNTOUCHED'
    print('(opcodes->cb_opcodes)[{}].flag_z = {};'.format(opcode, z))
    print('(opcodes->cb_opcodes)[{}].flag_n = {};'.format(opcode, n))
    print('(opcodes->cb_opcodes)[{}].flag_h = {};'.format(opcode, h))
    print('(opcodes->cb_opcodes)[{}].flag_c = {};'.format(opcode, c))
    print()
