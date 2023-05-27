/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** args
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "struct.h"

args_t init_args_t(int size)
{
    args_t args;

    args.l = 0;
    args.sr = 0;
    args.d = 0;
    args.r = 0;
    args.t = 0;
    args.a = 0;
    args.nb_paths = 0;
    args.paths = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i <= size; i++)
        args.paths[i] = NULL;
    return args;
}

void get_args_in_str(char const *args_str, args_t *args)
{
    for (int i = 0; i < my_strlen(args_str); i++) {
        if (args_str[i] == 'l')
            args->l = 1;
        if (args_str[i] == 'R')
            args->sr = 1;
        if (args_str[i] == 'd')
            args->d = 1;
        if (args_str[i] == 'r')
            args->r = 1;
        if (args_str[i] == 't')
            args->t = 1;
        if (args_str[i] == 'a')
            args->a = 1;
    }
}

args_t get_args(int ac, char const **av)
{
    args_t args = init_args_t(ac - 1);

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            get_args_in_str(av[i], &args);
        else {
            args.paths[args.nb_paths] = malloc(sizeof(char) *
            (my_strlen(av[i]) + 1));
            args.paths[args.nb_paths] = my_strcpy(args.paths[args.nb_paths],
            av[i]);
            args.nb_paths++;
        }
    }
    if (args.nb_paths <= 0) {
        args.nb_paths++;
        args.paths[0] = malloc(sizeof(char) * 2);
        args.paths[0] = my_strcpy(args.paths[0], ".\0");
    }
    return args;
}