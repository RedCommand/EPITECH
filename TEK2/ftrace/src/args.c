/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** args.c
*/

#include <string.h>
#include "ftrace.h"

static struct option long_options[] = {{"help", no_argument, 0, 'h'},
    {"show", no_argument, 0, 's'}, {0, 0, 0, 0}};

void *print_help(void)
{
    printf("USAGE: ./ftrace [-s] <command>");
    return NULL;
}

bool get_arg(int opt, args_t *args)
{
    switch (opt) {
        case 'h':
            return false;
        case 's':
            args->s = true;
            break;
        case '\1':
            if (args->cmd != NULL)
                return false;
            args->cmd = strdup(optarg);
            break;
        default:
            return false;
    }
    return true;
}

args_t *check_args(args_t *args)
{
    if (args->cmd == NULL) {
        free(args->cmd);
        free(args);
        return print_help();
    }
    return args;
}

args_t *get_args(int argc, char **argv)
{
    int opt;
    int option_index = 0;
    args_t *args = calloc(1, sizeof(args_t));

    if (args == NULL)
        return NULL;
    while (
        (opt = getopt_long(argc, argv, "-hsp:", long_options, &option_index))
        != -1) {
        if (!get_arg(opt, args)) {
            free(args->cmd);
            free(args);
            return print_help();
        }
    }
    return check_args(args);
}
