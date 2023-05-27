/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print_string.c
*/

#include <stdio.h>
#include <string.h>
#include "ftrace.h"

size_t print_char_p(int pid, unsigned long long int value)
{
    char *str = NULL;

    if (value == 0) {
        printf("NULL");
        return -1;
    }
    str = ptrace_get_str((char *) value, pid);
    if (str == NULL) {
        return -1;
    }
    printf("\"%s\"", str);
    free(str);
    return sizeof(char *);
}

size_t print_string(int pid, unsigned long long int value)
{
    char *str = NULL;
    size_t size = 0;

    if (value == 0) {
        printf("NULL");
        return -1;
    }
    str = ptrace_get_str((char *) value, pid);
    if (str == NULL) {
        return -1;
    }
    printf("\"%s\"", str);
    size = strlen(str);
    free(str);
    return size;
}
