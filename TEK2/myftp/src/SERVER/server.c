/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** server.c
*/

#include "ftp.h"

void server_destroy(server_t *server)
{
    while (server->n_clients > 0
        && server->clients[server->n_clients - 1] != NULL)
        client_destroy(server->clients[--server->n_clients], server);
    close(server->sock);
    free(server->clients);
    free(server);
}

void server_clean(server_t *server)
{
    FD_ZERO(&server->read_fds);
    FD_SET(server->sock, &server->read_fds);
    for (int i = 0; i < server->n_clients; i++) {
        if (server->clients[i] != NULL) {
            FD_SET(server->clients[i]->fd, &server->read_fds);
        }
    }
}

bool server_run(server_t *server, const struct cmds_s *cmds)
{
    int status = 0;

    while (1) {
        status = select(
            server->n_client_max + 3, &server->read_fds, NULL, NULL, NULL);
        if (status == -1) {
            perror("select");
            return false;
        }
        if (FD_ISSET(server->sock, &server->read_fds)) {
            client_accept(server);
            continue;
        }
        clients_handle(server, cmds);
        server_clean(server);
    }
    return true;
}
