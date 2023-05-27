/*
** EPITECH PROJECT, 2023
** mystrace
** File description:
** print_ptr.c
*/

#include <stdbool.h>
#include <stdio.h>

size_t print_ptr(int pid, unsigned long long int value)
{
    if ((const void *) value == NULL) {
        printf("NULL");
        return false;
    }
    printf("%p", (const void *) value);
    return true;
}
