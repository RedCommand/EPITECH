/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print_int.c
*/

#include <stdio.h>

size_t print_int(int pid, unsigned long long int value)
{
    printf("%d", (int) value);
    return sizeof(int);
}
