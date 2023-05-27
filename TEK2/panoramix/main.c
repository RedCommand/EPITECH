/*
** EPITECH PROJECT, 2023
** Project
** File description:
** main.c
*/

#include "panoramix.h"

int main(int argc, char **argv)
{
    args_t args;

    if (get_help(argc, argv))
        return 0;
    if (!get_args(&args, argc, argv))
        return 84;
    if (!panoramix(&args))
        return 84;
    return 0;
}