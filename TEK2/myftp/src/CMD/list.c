/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** files.c
*/

#include "ftp.h"

uint16_t cmd_list(client_t *client, server_t *server, char *args)
{
    if (!is_logged(client, server))
        return 0;
    if (client->mod != NONE) {
        client_answer(
            client, server, "150 Here comes the directory listing.\r\n");
        return client_answer(client, server, "226 Directory send OK.\r\n");
    }
    client->mod = NONE;
    return client_answer(client, server, "425 Use PORT or PASV first.\r\n");
}

uint16_t cmd_fork_list(client_t *client, server_t *server, char *args)
{
    FILE *fp;
    char path[PATH_MAX + 1] = {0};
    char cmd[PATH_MAX + 6] = "ls -l ";
    size_t size;
    char buf[BUF_SIZE] = {0};

    if (!get_current_dir(path, server->root, client->cwd, args))
        return 0;
    strcat(cmd, path);
    fp = popen(cmd, "r");
    if (fp == NULL)
        return 0;
    do {
        size = fread(buf, sizeof(char), BUF_SIZE, fp);
        if (size == -1 || size == 0)
            return 0;
        write(client->fd, buf, size);
    } while (size == BUF_SIZE);
    return 0;
}
