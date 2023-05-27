/*
** EPITECH PROJECT, 2023
** Project
** File description:
** main.c
*/

#include "ftrace.h"

int main(int argc, char **argv)
{
    return ftrace(argc, argv) == 0 ? 0 : 84;
}
