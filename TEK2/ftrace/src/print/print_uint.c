/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print_uint.c
*/

#include <stdio.h>

size_t print_unsigned_int(int pid, unsigned long long int value)
{
    printf("%u", (unsigned int) value);
    return sizeof(unsigned int);
}
