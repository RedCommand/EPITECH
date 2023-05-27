/*
** EPITECH PROJECT, 2023
** Project
** File description:
** main.c
*/

#include "ftp.h"

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf(
            "USAGE: ./myftp port path\n"
            "      port is the port number on which the server socket "
            "listens\n"
            "      path is the path to the home directory for the Anonymous "
            "user\n");
        return 0;
    }
    if (argc != 3)
        return 84;
    if (!ftp(argv[2], atoi(argv[1]), 32))
        return 84;
    return 0;
}