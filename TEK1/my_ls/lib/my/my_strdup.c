/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

    res = my_strcpy(res, str);
    return res;
}