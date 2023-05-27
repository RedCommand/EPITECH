/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** get_connection
*/

#include "local.h"

int get_s_connection(void)
{
    int failed = 0;
    int enemy_pid = 0;

    while (failed <= 10) {
        enemy_pid = get_other_pid();
        usleep(10000);
        if (send_pid(enemy_pid) != 0)
            return -84;
        if (enemy_pid == -84)
            failed += 1;
        else
            break;
    }
    if (failed > 10)
        return -84;
    return enemy_pid;
}
