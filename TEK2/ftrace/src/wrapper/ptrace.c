/*
** EPITECH PROJECT, 2023
** myftrace
** File description:
** ptrace.c
*/

#include "ftrace.h"

enum STATUS ptrace_get_regs(pid_t pid, struct user_regs_struct *regs)
{
    if (ptrace(PTRACE_GETREGS, pid, NULL, (void *) regs)) {
        perror("ptrace(PTRACE_GETREGS)");
        return ERROR;
    }
    return SUCCESS;
}

uint16_t ptrace_get_ins(pid_t pid, struct user_regs_struct *regs, bool refresh)
{
    long ins = 0;

    if (regs == NULL)
        return NO_INS;
    if (refresh == true) {
        if (ptrace_get_regs(pid, regs) != SUCCESS)
            return NO_INS;
    }
    ins = ptrace(PTRACE_PEEKTEXT, pid, regs->rip, NULL);
    if (ins == -1) {
        perror("ptrace(PTRACE_PEEKTEXT)");
        return NO_INS;
    }
    return (uint16_t) ins;
}

enum STATUS ptrace_single_step(pid_t pid, struct user_regs_struct *regs)
{
    int status = 0;
    long ptrace_ret = 0;

    if (regs == NULL)
        return ERROR;
    ptrace_ret = ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    if (ptrace_ret == -1 || ptrace_ret > INT_MAX) {
        perror("ptrace(PTRACE_SINGLESTEP)");
        return ERROR;
    }
    status = (int) ptrace_ret;
    if (status == 0)
        waitpid(pid, &status, 0);
    if (WIFSTOPPED(status) == 0)
        return EXITED;
    if (ptrace_get_regs(pid, regs) != SUCCESS)
        return ERROR;
    return SUCCESS;
}

enum STATUS ptrace_run_syscall(pid_t pid, struct user_regs_struct *regs)
{
    enum STATUS status = SUCCESS;

    if (regs == NULL)
        return ERROR;
    if (ptrace_get_ins(pid, regs, true) != SYSCALL_INS)
        return ERROR;
    status = ptrace_single_step(pid, regs);
    if (status != SUCCESS)
        return status;
    return ptrace_get_regs(pid, regs);
}
