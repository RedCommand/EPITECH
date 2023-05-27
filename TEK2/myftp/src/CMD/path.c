/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** path.c
*/

#include "ftp.h"

uint16_t cmd_cwd(client_t *client, server_t *server, char *args)
{
    if (!is_logged(client, server))
        return 0;
    if (get_current_dir(client->cwd, server->root, client->cwd, args))
        return client_answer(
            client, server, "250 Directory successfully changed.\r\n");
    return client_answer(
        client, server, "550 Failed to change directory.\r\n");
}

uint16_t cmd_cdup(client_t *client, server_t *server, char *args)
{
    if (!is_logged(client, server))
        return 0;
    get_current_dir(client->cwd, server->root, client->cwd, "..");
    return client_answer(
        client, server, "250 Directory successfully changed.\r\n");
}

uint16_t cmd_pwd(client_t *client, server_t *server, char *args)
{
    char res[PATH_MAX + 34] = {0};

    if (!is_logged(client, server))
        return 0;
    sprintf(res, "257 \"%s\" is current directory.\r\n", client->cwd);
    return client_answer(client, server, res);
}
