/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** turn
*/

#include "local.h"

int i_am_alive(int **map)
{
    int success = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            success |= (map[i][j] > 0);
    return success;
}

int valid_shoot(position_t *shoot_position, int **map)
{
    if (shoot_position->x >= 0 && shoot_position->x <= BOARD_SIZE &&
        shoot_position->y >= 0 && shoot_position->y <= BOARD_SIZE)
        my_printf("%c%d: ", shoot_position->y + 'A', shoot_position->x + 1);
        if (map[shoot_position->x][shoot_position->y] > 0) {
            map[shoot_position->x][shoot_position->y] = -1;
            my_putstr("hit\n");
            return 1;
        } else
            map[shoot_position->x][shoot_position->y] = -2;
    my_putstr("missed\n");
    return 0;
}

int my_turn(int enemy_pid, int **map, int **enemy_map)
{
    position_t *shoot_position = read_input();
    int enemy_alive = 1;

    if (read_input == NULL)
        return -84;
    usleep(1000);
    if (send_shoot_pos(enemy_pid, shoot_position->x, shoot_position->y) == 84)
        return -84;
    if (valid_shoot(shoot_position, enemy_map))
        enemy_alive = i_am_alive(enemy_map);
    if (enemy_alive == 1)
        return your_turn(enemy_pid, map, enemy_map);
    return 0;
}

int your_turn(int enemy_pid, int **map, int **enemy_map)
{
    position_t *shoot_position;
    int alive = 1;

    display_maps(map, enemy_map);
    my_putstr("waiting for enemy's attack...\n");
    shoot_position = get_shoot_pos(enemy_pid);
    if (shoot_position == NULL)
        return -84;
    if (valid_shoot(shoot_position, map) == 1)
        alive = i_am_alive(map);
    if (alive == 1)
        return my_turn(enemy_pid, map, enemy_map);
    return 1;
}
