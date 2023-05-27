/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** main file with error handling
*/

#include "my.h"

int eval_expr(char const *str);

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
