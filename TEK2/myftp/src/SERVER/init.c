/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** init.c
*/

#include "ftp.h"

static bool server_socket(server_t *server)
{
    server->sock = socket(server->sin.sin_family, SOCK_STREAM, 0);
    if (server->sock == -1)
        return false;
    FD_ZERO(&server->read_fds);
    FD_SET(server->sock, &server->read_fds);
    return true;
}

server_t *server_init(
    unsigned int port, in_addr_t addr, int n_client_max, const char *root)
{
    server_t *server = calloc(1, sizeof(server_t));

    if (!server)
        return NULL;
    server->clients = calloc(n_client_max, sizeof(client_t *));
    if (!server->clients)
        return NULL;
    memset(server->root, 0, PATH_MAX);
    strcpy(server->root, root);
    server->n_client_max = n_client_max;
    server->sin.sin_family = AF_INET;
    server->sin.sin_addr.s_addr = htonl(addr);
    server->sin.sin_port = htons(port);
    if (!server_socket(server)) {
        free(server->clients);
        free(server);
        return NULL;
    }
    return server;
}

bool server_start(server_t *server)
{
    socklen_t len;

    if (bind(server->sock, (struct sockaddr *) &server->sin,
            sizeof(server->sin))
        == -1)
        return false;
    if (server->sin.sin_port == 0) {
        len = sizeof(server->sin);
        if (getsockname(server->sock, (struct sockaddr *) &server->sin, &len)
            == -1)
            return false;
    }
    if (listen(server->sock, server->n_client_max) == -1)
        return false;
    return true;
}

server_t *server_new(
    unsigned int port, in_addr_t addr, int n_client_max, const char *root)
{
    server_t *server;

    if (!is_dir(root))
        return NULL;
    server = server_init(port, addr, n_client_max, root);
    if (server == NULL)
        return NULL;
    if (!server_start(server)) {
        server_destroy(server);
        return NULL;
    }
    return server;
}
