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

Test(factors, single_digit)
{
    char *source[] = {"42"};
    int res = factors(source);

    cr_assert_eq(res, 42);
}

Test(factors, single_op)
{
    char *source[] = {"42*12"};
    int res = factors(source);

    cr_assert_eq(res, 504);
}

Test(factors, div_op)
{
    char *source[] = {"42/21"};
    int res = factors(source);

    cr_assert_eq(res, 2);
}

Test(factors, empty)
{
    char *source[] = {""};
    int res = factors(source);

    cr_assert_eq(res, 0);
}

Test(factors, bloated_op)
{
    char *source[] = {"42*21/21*12/2/2"};
    int res = factors(source);

    cr_assert_eq(res, 126);
}
