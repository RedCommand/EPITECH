/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** evalexpr changed functions
*/

#include "my.h"
int compute_op(int a, char c, int b);
int operand_sum(char **str_ptr);
char *nbr_to_str(int n);
int factors(char **str_ptr);

char *better_summands(char **str_ptr)
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
    return (nbr_to_str(sum));
}
