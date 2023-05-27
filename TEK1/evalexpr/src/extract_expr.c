/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** extract eatch expr
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

char *better_summands(char **str_ptr);

char *my_concatstr(char *str1, char *str2)
{
    char *result;
    int lenstr1 = my_strlen(str1);
    int lenstr2 = my_strlen(str2);

    result = malloc(sizeof(char) * (lenstr1 + lenstr2 + 1));
    for (int i = 0; i < lenstr1; i++)
        result[i] = str1[i];
    for (int i = 0; i < lenstr2; i++)
        result[i + lenstr1] = str2[i];
    result[lenstr1 + lenstr2]=  '\0';
    return result;
}

char *extract_expr(char **str_ptr)
{
    char *res_prev = NULL;
    char *char_res;

    char_res = malloc(sizeof(char) * (my_strlen(str_ptr[0]) + 1));
    for (int i = 0; (*str_ptr)[0] != ')'; str_ptr[0] = &str_ptr[0][1]) {
        if ((*str_ptr)[0] == '(') {
            str_ptr[0] = &str_ptr[0][1];
            res_prev = extract_expr(str_ptr);
            char_res = my_concatstr(char_res, res_prev);
            i += my_strlen(res_prev);
        } else {
            char_res[i] = (*str_ptr)[0];
            i++;
        }
    }
    return better_summands(&char_res);
}
