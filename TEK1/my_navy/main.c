/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** main
*/

#include "local.h"

int main(int ac, char **av)
{
    int **map = get_boat_position(av[(ac == 3) + 1]);

    if (error_management(ac, av, map) == 84)
        return 84;
    return navy(ac, av, map);
}
