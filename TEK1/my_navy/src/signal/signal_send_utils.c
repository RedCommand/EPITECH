/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** signal_utlis
*/

#include "local.h"

int send_pid(int enemy_pid)
{
    int success = 0;

    success = send_int(getpid(), enemy_pid);
    if (success != 0)
        return 84;
    usleep(1000);
    return 0;
}

int send_shoot_pos(int enemy_pid, int posX, int posY)
{
    int success = 0;

    usleep(1000);
    success = send_int(posX, enemy_pid);
    if (success != 0)
        return 84;
    usleep(1000);
    success = send_int(posY, enemy_pid);
    if (success != 0)
        return 84;
    usleep(1000);
    return 0;
}

int send_maptwo(int enemy_pid, int **map, int i)
{
    int success = 0;

    for (int j = 0; j < BOARD_SIZE; j++) {
        success = send_int(map[i][j], enemy_pid);
        if (success != 0)
            return 84;
        usleep(1000);
    }
    return 0;
}

int send_map(int enemy_pid, int **map)
{
    int success = 0;

    usleep(2000);
    for (int i = 0; i < BOARD_SIZE; i++)
        if (send_maptwo(enemy_pid, map, i) != 0)
            return 84;
    return 0;
}
