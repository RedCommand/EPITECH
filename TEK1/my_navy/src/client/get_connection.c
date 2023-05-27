/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** get_connection
*/

#include "local.h"

int get_c_connection(int pid)
{
    int failed = 0;
    int enemy_pid = -84;

    while (failed <= 10) {
        if (send_pid(pid) != 0)
            return -84;
        enemy_pid = get_other_pid();
        if (enemy_pid == -84)
            failed += 1;
        else
            break;
    }
    if (failed > 10 || enemy_pid != pid)
        return -84;
    return 0;
}
