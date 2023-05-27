/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-maxime.senard
** File description:
** for_str_in_str
*/

#include "my.h"

int for_str_in_str(char *base_str, char *str_to_find)
{
    int len_base_str = my_strlen(base_str);
    int len_str_to_find = my_strlen(str_to_find);
    int counter = 0;

    for (int i = 0; i < len_base_str; i++) {
        if (base_str[i] == str_to_find[0]) {
            counter += str_start_with(&base_str[i], str_to_find,
            len_base_str, len_str_to_find);
        }
    }
    return counter;
}
