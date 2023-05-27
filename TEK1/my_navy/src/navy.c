/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** navy
*/

#include "local.h"

int print_help(void)
{
    my_putstr("USAGE:\n\t./navy [first_player_pid] (boat_positions)\n\
\nDESCRIPTION:\n\tfirst_player_pid: only for Player 2: PID of Player 1.\n\t\
boat_positions: file that represents the position of each ship.\n");
    return 0;
}

int error_management(int ac, char **av, int **map)
{
    int enemy_pid = my_getnbr(av[(ac == 3)]);

    if ((ac <= 1) || (ac > 3))
        return 84;
    if ((av[1][0] == '-') && (av[1][1] == 'h'))
        return print_help();
    if (ac == 2)
        return ((map != NULL) ? 0 : 84);
    if (ac == 3)
        return ((enemy_pid > 1 && (my_strlen(av[1]) == my_nbrlen(enemy_pid)) &&
        (map != NULL)) ? 0 : 84);
    return 0;
}

int navy(int ac, char **av, int **map)
{
    int success = 0;

    if (map == NULL)
        return 84;
    success = (ac == 2) ? main_server(map) : main_client(map, my_getnbr(av[1]));
    if (success == 0 || success == 1)
        return 0;
    return 84;
}
