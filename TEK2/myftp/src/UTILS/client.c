/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** client.c
*/

#include "ftp.h"

bool is_logged(client_t *client, server_t *server)
{
    if (client->logged)
        return true;
    client_answer(client, server, "530 Please login with USER and PASS.\r\n");
    return false;
}
