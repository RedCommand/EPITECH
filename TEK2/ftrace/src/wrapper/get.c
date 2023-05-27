/*
** EPITECH PROJECT, 2023
** myftrace
** File description:
** get.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include "ftrace.h"

char *ptrace_get_str(char *child_ptr, pid_t pid)
{
    char *str = NULL;
    long data = 0;
    size_t i = 0;

    if (child_ptr == NULL
        || (str = malloc(STR_BUFFER_SIZE * sizeof(char))) == NULL)
        return NULL;
    memset(str, 0, STR_BUFFER_SIZE * sizeof(char));
    for (char c = 1; c != '\0'; str[i++] = c) {
        data = ptrace(PTRACE_PEEKDATA, pid, child_ptr++, NULL);
        if (data == -1 || str == NULL) {
            free(str);
            return NULL;
        }
        c = (char) data;
        if (i + 1 % STR_BUFFER_SIZE == 0 && i != 0 && c != '\0')
            str = realloc(str, (i + STR_BUFFER_SIZE) * sizeof(char));
    }
    str[i] = '\0';
    return str;
}

char *ptrace_get_nstr(char *child_ptr, pid_t pid, size_t n)
{
    char *str = NULL;
    long data = 0;
    size_t i = 0;

    if (child_ptr == NULL || n == 0
        || (str = calloc(n + 1, sizeof(char))) == NULL)
        return NULL;
    for (char c = 1; i < n && c != '\0'; str[i++] = c) {
        data = ptrace(PTRACE_PEEKDATA, pid, child_ptr++, NULL);
        if (data == -1 || str == NULL) {
            perror("ptrace");
            free(str);
            return NULL;
        }
        c = (char) data;
    }
    str[i] = '\0';
    return str;
}

void *ptrace_get_ptr(void *child_ptr, pid_t pid)
{
    long data = 0;

    if (child_ptr == NULL)
        return NULL;
    data = ptrace(PTRACE_PEEKDATA, pid, child_ptr++, NULL);
    if (data == -1) {
        perror("ptrace");
        return NULL;
    }
    return (void *) data;
}
