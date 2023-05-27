/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** task02 : number
*/

#include "my.h"
#include <stdlib.h>

int compute_op(int a, char c, int b);
int do_op(int ac, char **av);

int number(char **str_ptr)
{
    int sum = 0;
    int i = 0;
    int neg = 1;

    while ((str_ptr[0][0] == '+') || (str_ptr[0][0] == '-')) {
        if (str_ptr[0][0] == '-')
            neg = neg * -1;
        str_ptr[0] = &str_ptr[0][1];
    }
    while ((str_ptr[0][i] >= '0') && (str_ptr[0][i] <= '9')) {
        sum = (str_ptr[0][i] - 48) + (sum * 10);
        (i++);
    }
    str_ptr[0] = &str_ptr[0][i];
    return (sum * neg);
}

int my_strtol(char *str , char **endptr)
{
    int sum = 0;
    int i =0;

    while ((str[i] >= '0') && (str[i] <= '9')) {
        sum = (str[i] - 48) + (sum * 10);
        (i++);
    }
    endptr[0] = &str[i];
    return (sum);
}

char *to_str_loop(int n)
{
    int m = n;
    char *c;
    int i = 0;

    for(; n != 0; n /= 10, i++);
    c = malloc(sizeof(char) * (i + 2));
    for (i = 0; m != 0; m /= 10, i++)
        c[i] = (m % 10) + 48;
    c[i] = '-';
    c[i + 1] = '\0';
    return (c);
}

char *nbr_to_str(int n)
{
    if (n == 0)
        return ("0");
    if (n < 0)
        return (my_revstr(to_str_loop(-n)));
    else
        return (&my_revstr(to_str_loop(n))[1]);
}
