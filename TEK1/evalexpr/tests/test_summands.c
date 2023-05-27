/*
** EPITECH PROJECT, 2021
** test_my_strstr
** File description:
** test criterion for my_strstr
*/

#include <stdlib.h>
#include <criterion/criterion.h>
int summands(char **str_ptr);
int factors(char **str_ptr);

Test(summands, single_digit)
{
    char *source[] = {"42"};
    int res = summands(source);

    cr_assert_eq(res, 42);
}

Test(summands, single_op)
{
    char *source[] = {"42+12"};
    int res = summands(source);

    cr_assert_eq(res, 54);
}

Test(summands, double_op)
{
    char *source[] = {"42-21"};
    int res = summands(source);

    cr_assert_eq(res, 21);
}

Test(summands, long_op)
{
    char *source[] = {"42+23*36+42/42-1"};
    int res = summands(source);

    cr_assert_eq(res, 870);
}
