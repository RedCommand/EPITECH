/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** map_utils
*/

#include "local.h"

int **init_map(void)
{
    int **result = malloc(sizeof(int*) * (BOARD_SIZE + 2));

    result[BOARD_SIZE + 1] = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        result[i] = malloc(sizeof(int) * (BOARD_SIZE));
        for (int j = 0; j < BOARD_SIZE; j++)
            result[i][j] = 0;
    }
    return result;
}

int bool_arr_to_int(bool *arr)
{
    int ret = 0;
    int tmp = 0;

    for (int i = 0; i < 32; i++) {
        tmp = arr[i];
        ret |= tmp << (31 - i);
    }
    return ret;
}

bool *int_to_bool_arr(int nb)
{
    bool *ar = malloc(sizeof(bool) * 32);

    for (int i = 0; i < 32; i++)
        ar[i] = false;
    for (int i = 1; i < 32; i++) {
        ar[i] = (nb >> (31 - i)) % 2;
    }
    return ar;
}
