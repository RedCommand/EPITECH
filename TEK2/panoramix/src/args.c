/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** args.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "panoramix.h"

void print_help(bool help)
{
    printf(
        "USAGE"
        "\t./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
    if (!help)
        printf("\n"
        "DESCRIPTION\n"
        "\tnb_villagers\t\tNumber of villagers in the village\n"
        "\tpot_size\t\tSize of the pot\n"
        "\tnb_fights\t\tNumber of fights before the pot is empty\n"
        "\tnb_refills\t\tNumber of refills of the pot\n"
        "\nall arguments must be positive integers\n");
}

bool get_help(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help(true);
            return true;
        }
    return false;
}

// atoi does not handle errors, but because values must be positive,
// it's not a problem
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
bool get_args(args_t *args, int argc, char **argv)
{
    if (argc != 5) {
        print_help(false);
        return false;
    }
    args->nb_villagers = atoi(argv[1]);
    args->pot_size = atoi(argv[2]);
    args->nb_fights = atoi(argv[3]);
    args->nb_refills = atoi(argv[4]);
    if (args->nb_villagers <= 0 || args->pot_size <= 0 || args->nb_fights <= 0
        || args->nb_refills <= 0) {
        print_help(false);
        return false;
    }
    return true;
}
#pragma clang diagnostic pop
