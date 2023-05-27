/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** files.c
*/

#include "ftp.h"

uint16_t cmd_stor(client_t *client, server_t *server, char *args)
{
    if (!is_logged(client, server))
        return 0;
    if (client->mod != NONE)
        return client_answer(
            client, server, "425 Use PORT or PASV first.\r\n");
    client->mod = NONE;
    client_answer(client, server,
        "150 File status okay; about to open data connection.\r\n");
    return client_answer(client, server, "226 Closing data connection.\r\n");
}

uint16_t cmd_fork_stor(client_t *client, server_t *server, char *args)
{
    FILE *fp;
    char path[PATH_MAX + 1] = {0};
    size_t size;
    char buf[BUF_SIZE] = {0};

    if (!get_current_dir(path, server->root, client->cwd, args))
        return 0;
    if (file_exists(path))
        return 0;
    fp = fopen(path, "w");
    if (fp == NULL)
        return 0;
    do {
        size = read(client->fd, buf, BUF_SIZE);
        if (size == 0 || size == -1)
            break;
        fwrite(buf, sizeof(char), size, fp);
    } while (size == BUF_SIZE);
    fclose(fp);
    return 0;
}

uint16_t cmd_retr(client_t *client, server_t *server, char *args)
{
    if (!is_logged(client, server))
        return 0;
    if (client->mod != NONE)
        return client_answer(
            client, server, "425 Use PORT or PASV first.\r\n");
    client->mod = NONE;
    client_answer(
        client, server, "150 Opening BINARY mode data connection.\r\n");
    return client_answer(client, server, "226 Transfer complete.\r\n");
}

uint16_t cmd_fork_retr(client_t *client, server_t *server, char *args)
{
    char path[PATH_MAX + 1] = {0};
    int fd;
    size_t size = 0;
    char buf[BUF_SIZE] = {0};

    if (!get_current_dir(path, server->root, client->cwd, args))
        return 0;
    fd = open_file(path);
    if (fd == -1)
        return 0;
    do {
        size = read(fd, buf, BUF_SIZE);
        if (size == -1)
            return CLIENT_FATAL;
        if (size == 0)
            break;
        write(client->fd, buf, size);
    } while (size == BUF_SIZE);
    close(fd);
    return 0;
}
