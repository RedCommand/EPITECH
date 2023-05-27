/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** user_input
*/

#include "local.h"

int process_input(position_t *pos)
{
    char str[] = "\0\0\0";
    int success = read(1, str, 3);

    usleep(1000);
    if (success < 0)
        return 84;
    str[2] = '\0';
    if (str[0] >= 'A' && str[0] < 'A' + BOARD_SIZE &&
    str[1] < '1' + BOARD_SIZE && str[1] >= '1') {
        pos->y = str[0] - 'A';
        pos->x = str[1] - '1';
        return 1;
    } else
        my_printf("wrong position\nattack: ");
    return 0;
}

position_t *read_input(void)
{
    int turn_time = 0;
    position_t *pos = malloc(sizeof(position_t));
    int success = 0;

    pos->x = 0;
    pos->y = -1;
    my_printf("\nattack: ");
    while (1) {
        success = process_input(pos);
        if (success == 1)
            break;
        if (success == 84)
            return NULL;
    }
    if (turn_time > TURN_TIMEOUT)
        my_printf("\nYou took more than %d seconds to attack!\n", TURN_TIMEOUT);
    return pos;
}
