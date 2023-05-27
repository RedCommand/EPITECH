/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** init.c
*/

#include "ftp.h"

client_t *client_new(server_t *server, int sock)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client)
        return NULL;
    client->fd = sock;
    strcpy(client->cwd, server->root);
    return client;
}

void client_destroy(client_t *client, server_t *server)
{
    size_t index =
        get_ptr_pos((void **) server->clients, client, server->n_clients);

    if (index == -1)
        return;
    FD_CLR(client->fd, &server->read_fds);
    close(client->fd);
    server->clients[index] = server->clients[server->n_clients - 1];
    server->clients[--server->n_clients] = NULL;
    free(client);
}
