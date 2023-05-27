/*
** EPITECH PROJECT, 2021
** do_op
** File description:
** computes an operations
*/

#include <unistd.h>
#include "my.h"
int op_sum(int a, int b);
int op_diff(int a, int b);
int op_prod(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

int compute_op(int a, char c, int b)
{
    char str_op[] = {'+', '-', '*', '/', '%', 0};
    int (*op[])(int, int) = {&op_sum, &op_diff, &op_prod, &op_div, &op_mod, 0};
    int i = 0;

    for (; c != str_op[i]; i++)
        if (str_op[i] == 0) {
            write(2, "Stop : invalid syntax\n", 22);
            return (0);
        }
    return (op[i](a, b));
}

int do_op(int argc, char **argv)
{
    int result = 0;

    if ((argv[2][0] == '/') && (argv[3][0] == '0')) {
        write(2, "Stop : division by zero\n", 24);
        return (0);
    }
    if ((argv[2][0] == '%' && (argv[3][0] == '0'))) {
        write(2, "Stop : modulo by zero\n", 22);
        return (0);
    }
    if (argc != 4) {
        write(2, "Stop : invalid args\n", 20);
        return (0);
    }
    result = compute_op(my_getnbr(argv[1]), argv[2][0], my_getnbr(argv[3]));
    return (result);
}
