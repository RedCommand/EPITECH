/*
** EPITECH PROJECT, 2021
** test_my_strstr
** File description:
** test criterion for my_strstr
*/

#include <stdlib.h>
#include <criterion/criterion.h>
char *better_summands(char **str_ptr);

Test(better_summands, single_digit)
{
    char *source[] = {"42"};
    char *res = better_summands(source);

    cr_assert_str_eq(res, "42");
}

Test(better_summands, single_op)
{
    char *source[] = {"42+12"};
    char *res = better_summands(source);

    cr_assert_str_eq(res, "54");
}

Test(better_summands, double_op)
{
    char *source[] = {"42-21"};
    char *res = better_summands(source);

    cr_assert_str_eq(res, "21");
}

Test(better_summands, long_op)
{
    char *source[] = {"42+23*36+42/42-1"};
    char *res = better_summands(source);

    cr_assert_str_eq(res, "870");
}
