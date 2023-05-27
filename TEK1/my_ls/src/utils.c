/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** utils
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "local.h"

char **create_char_tabl(int size)
{
    char **res = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i <= size; i++)
        res[i] = NULL;
    return res;
}

int my_char_tabl_len(char **tabl)
{
    int i = 0;

    for (i = 0; tabl[i] != NULL; i++);
    return i + 1;
}

char **add_str_to_tabl(char **tabl, char *str)
{
    int length = my_char_tabl_len(tabl) - 1;
    char **res = create_char_tabl(length + 1);

    for (int i = 0; i < length; i++) {
        res[i] = malloc(sizeof(char) * (my_strlen(tabl[i]) + 1));
        res[i] = my_strcpy(res[i], tabl[i]);
    }
    free_char_tabl(tabl);
    res[length] = malloc(sizeof(char) * (my_strlen(str) + 1));
    res[length] = my_strcpy(res[length], str);
    return res;
}

unsigned char *add_to_ustr(unsigned char *str, unsigned char c)
{
    int length = my_strlen((char*)str);
    unsigned char *res = malloc(sizeof(unsigned char) * (length + 2));
    int i = 0;

    for (i = 0; i < length; i++)
        res[i] = str[i];
    res[i++] = c;
    res[i] = '\0';
    free(str);
    return res;
}