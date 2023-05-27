/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** wrapper.c
*/

#include "ftrace.h"

static enum OPCODE get_call_type(uint16_t ins)
{
    if ((uint8_t) ins != 0xFF)
        return FAIL;
    switch ((uint8_t) (ins >> 8)) {
        case 0x25:
            return JMP;
        case 0xEA:
            return FAR_JMP;
        default:
            return NOOP;
    }
}

static enum STATUS get_ins_type_two(uint16_t ins, enum OPCODE *type)
{
    switch ((uint8_t) ins) {
        case 0xE8:
            *type = NR_CALL;
            break;
        case 0x9A:
            *type = FR_CALL;
            break;
        case 0xFF:
            *type = get_call_type(ins);
            break;
        case 0xC2:
        case 0xC3:
        case 0xCA:
        case 0xCB:
            *type = RET;
            break;
        default:
            break;
    }
    return SUCCESS;
}

static enum STATUS get_ins_type(uint16_t ins, enum OPCODE *type)
{
    if (type == NULL || ins == NO_INS)
        return ERROR;
    *type = NOOP;
    if (ins == SYSCALL_INS) {
        *type = SYSCALL;
        return SUCCESS;
    }
    return get_ins_type_two(ins, type);
}

enum OPCODE ptrace_jmp_next(pid_t pid, struct user_regs_struct *regs)
{
    enum STATUS status = 0;
    enum OPCODE type = NOOP;
    uint16_t ins = 0;

    while (type != FAIL) {
        ins = ptrace_get_ins(pid, regs, true);
        if (ins == NO_INS)
            return FAIL;
        status = get_ins_type(ins, &type);
        if (status != SUCCESS)
            return (enum OPCODE) status;
        if (type != NOOP)
            return type;
        status = ptrace_single_step(pid, regs);
        if (status != SUCCESS)
            return (enum OPCODE) status;
    }
    return FAIL;
}
