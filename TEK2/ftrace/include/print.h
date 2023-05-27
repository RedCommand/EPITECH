/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print.h
*/

#pragma once

    #define NB_PRINT 6

#include <stdbool.h>
#include <stdio.h>
#include <sys/user.h>
#include <unistd.h>
#include "syscall.h"

typedef size_t (*print_func_t)(pid_t pid, unsigned long long int);

size_t print_type(pid_t pid, int type, long value, bool typed);
unsigned long long int print_syscall(
    pid_t pid, struct user_regs_struct *regs, bool typed);
void print_sysres(
    pid_t pid, struct user_regs_struct *regs, size_t syscall_id, bool typed);

size_t print_int(pid_t pid, unsigned long long int value);
size_t print_string(pid_t pid, unsigned long long int value);
size_t print_char_p(int pid, unsigned long long int value);
size_t print_unsigned_int(pid_t pid, unsigned long long int value);
size_t print_ptr(pid_t pid, unsigned long long int value);
