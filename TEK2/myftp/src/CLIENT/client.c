/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** client.c
*/

#include "ftp.h"

uint16_t client_cmd(
    client_t *client, server_t *server, const struct cmds_s *cmds, char *buf)
{
    size_t len;

    for (size_t i = 0; i < cmds->size; i++) {
        len = strlen(cmds->cmds[i].name);
        if (strncasecmp(buf, cmds->cmds[i].name, len) == 0) {
            return cmds->cmds[i].func(client, server, buf + len);
        }
    }
    return 0;
}

uint16_t client_handle(
    client_t *client, server_t *server, const struct cmds_s *cmds, int read_fd)
{
    char buf[BUF_SIZE + 1] = {0};
    size_t status = read(read_fd, buf, BUF_SIZE);

    if (status == -1) {
        perror("read");
        return CLIENT_FATAL;
    }
    if (status == 0) {
        client_destroy(client, server);
        return CLIENT_DEAD;
    }
    clean_buf(buf, BUF_SIZE);
    return client_cmd(client, server, cmds, buf);
}

uint16_t clients_handle(server_t *server, const struct cmds_s *cmds)
{
    for (int i = 0; i < server->n_clients; i++) {
        if (FD_ISSET(server->clients[i]->fd, &server->read_fds)) {
            return client_handle(
                server->clients[i], server, cmds, server->clients[i]->fd);
        }
    }
    return 0;
}

uint16_t client_answer(client_t *client, server_t *server, const char *msg)
{
    size_t len = strlen(msg);
    size_t status = write(client->fd, msg, len);

    if (status == -1) {
        perror("write");
        return CLIENT_FATAL;
    }
    if (status == 0) {
        client_destroy(client, server);
        return CLIENT_DEAD;
    }
    if (status != len) {
        fprintf(stderr, "write: %s", msg);
        return CLIENT_FAIL;
    }
    return 0;
}

void client_accept(server_t *server)
{
    int sock = 0;
    struct sockaddr csin;
    unsigned int csin_len = sizeof(csin);

    if (server->n_clients > server->n_client_max)
        return;
    sock = accept(server->sock, &csin, &csin_len);
    if (sock == -1) {
        perror("accept");
        return;
    }
    server->clients[server->n_clients] = client_new(server, sock);
    if (server->clients[server->n_clients] == NULL) {
        close(sock);
        return;
    }
    server->n_clients++;
    FD_SET(sock, &server->read_fds);
    client_answer(server->clients[server->n_clients - 1], server,
        "220 Service ready for new user.\r\n");
}
