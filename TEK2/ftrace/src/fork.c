/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** fork.c
*/

#include "ftrace.h"

int start_fork(args_t *args)
{
    char *argv[] = {NULL, NULL};
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid != 0)
        return pid;
    if (args == NULL || args->cmd == NULL)
        return 84;
    argv[0] = args->cmd;
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execvp(argv[0], argv);
    return 0;
}
