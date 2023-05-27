/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** server
*/

#include "local.h"

/* int checkmap(int **enemy, int **me)
{
    int *maps = malloc(sizeof(int) * 10);
    for (int i = 0)
    free(maps);
} */

int main_server(int **map)
{
    int enemy_pid = -84;
    int **enemy_map = NULL;
    int victory = 0;

    my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    enemy_pid = get_s_connection();
    my_printf("\nenemy connected\n\n");
    if (enemy_pid == -84)
        return -84;
    enemy_map = recev_map(enemy_pid);
    usleep(1000);
    send_map(enemy_pid, map);
    display_maps(map, enemy_map);
    victory = my_turn(enemy_pid, map, enemy_map);
    victory = 1 ? my_putstr("Enemy won\n") : my_putstr("I won\n");
    return victory;
}
