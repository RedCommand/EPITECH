/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** user.c
*/

#include "ftp.h"

uint16_t cmd_user(client_t *client, server_t *server, char *args)
{
    if (args[0] == ' ')
        client->identity = true;
    if (strcasecmp(args, " anonymous") == 0) {
        client->logged = true;
        return client_answer(client, server, "230 Login successful.\r\n");
    }
    return client_answer(
        client, server, "331 Please specify the password.\r\n");
}

uint16_t cmd_pass(client_t *client, server_t *server, char *args)
{
    if (!client->identity)
        return client_answer(client, server, "503 Login with USER first.\r\n");
    if (client->logged)
        return client_answer(client, server, "230 Already logged in.\r\n");
    return client_answer(client, server, "530 Login incorrect.\r\n");
}

uint16_t cmd_quit(client_t *client, server_t *server, char *args)
{
    client_answer(client, server, "221 Goodbye.\r\n");
    client_destroy(client, server);
    return 0;
}

uint16_t cmd_help(client_t *client, server_t *server, char *args)
{
    return client_answer(client, server, "214 this is the help message.\r\n");
}

uint16_t cmd_noop(client_t *client, server_t *server, char *args)
{
    if (!is_logged(client, server))
        return 0;
    return client_answer(client, server, "200 NOOP ok.\r\n");
}
