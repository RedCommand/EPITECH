/*
** EPITECH PROJECT, 2023
** Project
** File description:
** ftrace.h
*/

#pragma once

    #define NO_INS      0x0f0f
    #define SYSCALL_INS 0x050f

    #define STR_BUFFER_SIZE 128

#include <getopt.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "nm.h"

enum STATUS { ERROR = -1, EXITED = 0, SUCCESS = 1 };
enum OPCODE {
    FAIL = -1,
    EXIT = 0,
    NOOP,
    NR_CALL,
    FR_CALL,
    NA_CALL,
    FA_CALL,
    JMP,
    FAR_JMP,
    RET,
    SYSCALL
};

typedef struct args_s {
    bool s;
    char *cmd;
} args_t;

typedef struct ftrace_s {
    pid_t pid;
    args_t *args;
    symbol_t **symbols;
} ftrace_t;

typedef enum STATUS (*ftrace_func_t)(
    ftrace_t *params, struct user_regs_struct *regs);

int ftrace(int argc, char **argv);
enum STATUS ftrace_loop(ftrace_t *params);

args_t *get_args(int argc, char **argv);

int start_fork(args_t *args);

enum STATUS ptrace_get_regs(pid_t pid, struct user_regs_struct *regs);
uint16_t ptrace_get_ins(
    pid_t pid, struct user_regs_struct *regs, bool refresh);
enum OPCODE ptrace_jmp_next(pid_t pid, struct user_regs_struct *regs);
enum STATUS ptrace_run_syscall(pid_t pid, struct user_regs_struct *regs);
enum STATUS ptrace_single_step(pid_t pid, struct user_regs_struct *regs);

char *ptrace_get_str(char *child_ptr, pid_t pid);
char *ptrace_get_nstr(char *child_ptr, pid_t pid, size_t n);
void *ptrace_get_ptr(void *child_ptr, pid_t pid);

enum STATUS ftrace_syscall(ftrace_t *params, struct user_regs_struct *regs);
enum STATUS ftrace_continue(ftrace_t *params, struct user_regs_struct *regs);
enum STATUS ftrace_call(ftrace_t *params, struct user_regs_struct *regs);
