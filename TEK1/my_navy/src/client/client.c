/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** client
*/

#include "local.h"

int main_client(int **map, int enemy_pid)
{
    int success = get_c_connection(enemy_pid);
    int **enemy_map = NULL;

    my_printf("my_pid: %d\n", getpid());
    if (success == -84)
        return -84;
    my_printf("successfully connected\n\n");
    usleep(1000);
    send_map(enemy_pid, map);
    enemy_map = recev_map(enemy_pid);
    return your_turn(enemy_pid, map, enemy_map);
}
