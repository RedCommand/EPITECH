/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-navy-killian1.lelong
** File description:
** test_navy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "local.h"

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (error_management, nothing)
{
    char *av[] = {
        "./navy",
        NULL
    };
    int ret = error_management(1, av, NULL);
    cr_assert_eq(ret, 84);
}

Test (error_management, help)
{
    char *av[] = {
        "./navy",
        "-h",
        NULL
    };
    int ret = error_management(2, av, NULL);
    cr_assert_eq(ret, 0);
}

Test (error_management, invalid_2nd_arg)
{
    char *av[] = {
        "./navy",
        "ded",
        NULL
    };
    int ret = error_management(2, av, NULL);
    cr_assert_eq(ret, 84);
}

Test (error_management, invalid_pid)
{
    char *av[] = {
        "./navy",
        "0",
        NULL
    };
    int ret = error_management(2, av, NULL);
    cr_assert_eq(ret, 84);
}

Test (error_management, invalid_map)
{
    char *av[] = {
        "./navy",
        "teste.txt",
        NULL
    };
    int **map = get_boat_position(av[1]);
    int ret = error_management(2, av, map);
    cr_assert_eq(ret, 84);
}

Test (error_management, valid_map)
{
    char *av[] = {
        "./navy",
        "test.txt",
        NULL
    };
    int **map = get_boat_position(av[1]);
    int ret = error_management(2, av, map);
    cr_assert_eq(ret, 0);
}

Test (error_management, valid_map_but_invalid_pid)
{
    char *av[] = {
        "./navy",
        "1",
        "test.txt",
        NULL
    };
    int **map = get_boat_position(av[2]);
    int ret = error_management(3, av, map);
    cr_assert_eq(ret, 84);
}

Test (error_management, valid_map_valid_pid)
{
    char *av[] = {
        "./navy",
        "4",
        "test.txt",
        NULL
    };
    int **map = get_boat_position(av[2]);
    int ret = error_management(3, av, map);
    cr_assert_eq(ret, 0);
}

Test (error_management, valid_map_invalid_pid_v2)
{
    char *av[] = {
        "./navy",
        "vrefwe",
        "test.txt",
        NULL
    };
    int **map = get_boat_position(av[2]);
    int ret = error_management(3, av, map);
    cr_assert_eq(ret, 84);
}

Test (error_management, invalid_map_valid_pid)
{
    char *av[] = {
        "./navy",
        "5",
        "test.dtxt",
        NULL
    };
    int **map = get_boat_position(av[2]);
    int ret = error_management(3, av, map);
    cr_assert_eq(ret, 84);
}

Test (error_management, too_many_args)
{
    char *av[] = {
        "./navy",
        "5",
        "test.txt",
        "test.txt",
        NULL
    };
    int **map = get_boat_position(av[2]);
    int ret = error_management(4, av, map);
    cr_assert_eq(ret, 84);
}