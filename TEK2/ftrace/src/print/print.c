/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print.c
*/

#include "print.h"

static const print_func_t print_types[] = {
    &print_int,
    &print_string,
    &print_char_p,
    &print_unsigned_int,
    &print_ptr,
    &print_ptr,
};

syscall_t const *get_syscall(size_t syscall_id)
{
    size_t table_size = sizeof(table) / sizeof(syscall_t);

    for (size_t i = 0; i < table_size; i++) {
        if (table[i].index == syscall_id)
            return &(table[i]);
    }
    return NULL;
}

size_t print_type(pid_t pid, int type, long value, bool typed)
{
    if (!typed || type > NB_PRINT || type == 0
        || print_types[type - 1] == NULL) {
        printf("%p", value);
        return sizeof(long);
    }
    return print_types[type - 1](pid, value);
}

static void set_values(size_t *values, struct user_regs_struct *s_regs)
{
    values[0] = s_regs->rdi;
    values[1] = s_regs->rsi;
    values[2] = s_regs->rdx;
    values[3] = s_regs->r10;
    values[4] = s_regs->r8;
    values[5] = s_regs->r9;
}

unsigned long long int print_syscall(
    pid_t pid, struct user_regs_struct *regs, bool typed)
{
    syscall_t const *id = NULL;
    size_t const *args = NULL;
    size_t values[6] = {0};

    if (regs == NULL)
        return -1;
    id = get_syscall(regs->rax);
    if (id == NULL)
        return -1;
    printf("Syscall %s (", id->name);
    set_values(&values[0], regs);
    args = (size_t const *) &(id->arg1);
    for (int i = 0; i < id->nargs; i++) {
        print_type(pid, args[i], values[i], typed);
        if (i != id->nargs - 1)
            printf(", ");
    }
    printf(")");
    fflush(stdout);
    return regs->rax;
}

void print_sysres(
    pid_t pid, struct user_regs_struct *regs, size_t syscall_id, bool typed)
{
    syscall_t const *id = NULL;

    if (regs == NULL || syscall_id == -1)
        return;
    id = get_syscall(syscall_id);
    if (id == NULL)
        return;
    printf(" = ");
    print_type(pid, id->ret, regs->rax, typed);
    printf("\n");
    fflush(stdout);
}
