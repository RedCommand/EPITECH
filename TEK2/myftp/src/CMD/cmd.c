/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** cmd.c
*/

#include "ftp.h"

uint16_t cmd_syst(client_t *client, server_t *server, char *args)
{
    return client_answer(client, server, "215 UNIX Type: L8\r\n");
}
