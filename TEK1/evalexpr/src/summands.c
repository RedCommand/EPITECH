/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** task02 : number
*/

#include "my.h"
int compute_op(int a, char c, int b);
int number(char **str_ptr);

int operand_sum(char **str_ptr)
{
    int c = 0;

    while ((str_ptr[0][0] == '+') || (str_ptr[0][0] == '-')) {
        if (str_ptr[0][0] == '-')
            c = !(c);
        str_ptr[0] = &str_ptr[0][1];
    }
    if (c == 0)
        return ('+');
    else
        return ('-');
}

int is_op_prod(char **str_ptr)
{
    if (str_ptr[0][0] == '%')
        return (1);
    if (str_ptr[0][0] == '/')
        return (1);
    if (str_ptr[0][0] == '*')
        return (1);
    return (0);
}

int factors(char **str_ptr)
{
    int prod = number(str_ptr);
    char c = 0;
    int nbr2 = 0;

    while (is_op_prod(str_ptr)) {
        c = str_ptr[0][0];
        str_ptr[0] = &str_ptr[0][1];
        nbr2 = number(str_ptr);
        prod = compute_op(prod, c, nbr2);
    }
    return (prod);
}

int summands(char **str_ptr)
{
    int i = 0;
    int sum = factors(str_ptr);
    char c = 0;
    int nbr2 = 0;

    while (str_ptr[0][0] != '\0') {
        c = operand_sum(str_ptr);
        nbr2 = factors(str_ptr);
        sum = compute_op(sum, c, nbr2);
        (i++);
    }
    return (sum);
}
