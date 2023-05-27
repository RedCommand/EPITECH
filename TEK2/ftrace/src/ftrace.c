/*
** EPITECH PROJECT, 2023
** Project
** File description:
** ftrace.c
*/

#include "ftrace.h"
#include "nm.h"
#include "print.h"
#include "syscall.h"

static const ftrace_func_t funcs[] = {
    NULL,
    &ftrace_continue,
    &ftrace_call,
    &ftrace_continue,
    &ftrace_continue,
    &ftrace_continue,
    &ftrace_continue,
    &ftrace_continue,
    &ftrace_continue,
    &ftrace_syscall,
};

int ftrace(int argc, char **argv)
{
    args_t *args = get_args(argc, argv);
    pid_t pid;
    ftrace_t params = {0};
    enum STATUS status;

    if (args == NULL || args->cmd == NULL)
        return 84;
    params.symbols = nm_file(args->cmd);
    if (params.symbols == NULL)
        return 84;
    pid = start_fork(args);
    if (pid == -1)
        return 84;
    params.pid = pid;
    params.args = args;
    status = ftrace_loop(&params);
    free_symbols(params.symbols);
    free(args->cmd);
    free(args);
    return status == EXITED ? 0 : 84;
}

enum STATUS ftrace_continue(ftrace_t *params, struct user_regs_struct *regs)
{
    if (params == NULL || regs == NULL)
        return ERROR;
    return ptrace_single_step(params->pid, regs);
}

enum STATUS ftrace_call(ftrace_t *params, struct user_regs_struct *regs)
{
    enum STATUS status = SUCCESS;
    char *sym = NULL;

    status = ptrace_single_step(params->pid, regs);
    if (status != SUCCESS)
        return status;
    sym = get_symbol_name(params->symbols, (void *) regs->rip);
    if (sym == NULL)
        return SUCCESS;
    printf("Entering function %s at %p\n", sym, (void *) regs->rip);
    return SUCCESS;
}

enum STATUS ftrace_syscall(ftrace_t *params, struct user_regs_struct *regs)
{
    size_t syscall_id = print_syscall(params->pid, regs, params->args->s);
    enum STATUS status = ptrace_run_syscall(params->pid, regs);

    if (status != SUCCESS)
        return status;
    print_sysres(params->pid, regs, syscall_id, params->args->s);
    return status;
}

enum STATUS ftrace_loop(ftrace_t *params)
{
    int pid_status = 0;
    struct user_regs_struct regs;
    enum STATUS status = SUCCESS;
    enum OPCODE opcode = NOOP;

    waitpid(params->pid, &pid_status, 0);
    ptrace(PTRACE_SETOPTIONS, params->pid, 0, PTRACE_O_EXITKILL);
    if (WIFSTOPPED(pid_status) == 0)
        return EXITED;
    while (status == SUCCESS) {
        opcode = ptrace_jmp_next(params->pid, &regs);
        if (opcode <= 0)
            return (enum STATUS) opcode;
        status = funcs[opcode](params, &regs);
    }
    return status;
}
