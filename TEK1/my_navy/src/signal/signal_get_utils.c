/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** signal_utlis
*/

#include "local.h"

int get_other_pid(void)
{
    int pid = recev_int(0, 60000);
    return pid;
}

position_t *get_shoot_pos(int enemy_pid)
{
    position_t *pos = malloc(sizeof(position_t));

    pos->x = recev_int(enemy_pid, (TURN_TIMEOUT * 1000 + 7000));
    if (pos->x == -84)
        return NULL;
    pos->y = recev_int(enemy_pid, 6);
    if (pos->y == -84)
        return NULL;
    return pos;
}

int **recev_map(int enemy_pid)
{
    int **map = init_map();

    map[0][0] = recev_int(enemy_pid, 6000);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = (i == 0); j < BOARD_SIZE; j++) {
            map[i][j] = recev_int(enemy_pid, 6);
            if (map[i][j] == -84)
                return NULL;
        }
    }
    return map;
}
