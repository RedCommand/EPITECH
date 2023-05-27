/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** pasv.c
*/

#include "ftp.h"

static const struct cmds_s fork_cmds = {
    .cmds = (struct cmd_s[3]){{"RETR ", &cmd_fork_retr},
        {"STOR ", &cmd_fork_stor}, {"LIST", &cmd_fork_list}},
    .size = 3};

void pasv_msg(char *dest, u_int32_t addr, uint16_t port)
{
    uint8_t *addr_bytes = (uint8_t *) &addr;

    sprintf(dest, "227 Entering Passive Mode (%u,%u,%u,%u,%u,%u).\r\n",
        addr_bytes[0], addr_bytes[1], addr_bytes[2], addr_bytes[3], port % 256,
        port / 256);
}

uint16_t cmd_pasv(client_t *client, server_t *server, char *buf)
{
    server_t *data_server;
    int pid = fork();
    char addr[57] = {0};

    if (pid == -1)
        return CLIENT_FATAL;
    client->mod = PASSIVE;
    if (pid == 0)
        return 0;
    data_server = server_new(0, INADDR_ANY, 1, server->root);
    if (data_server == NULL)
        return CLIENT_FATAL;
    pasv_msg(addr, LOCALHOST, data_server->sin.sin_port);
    if (client_answer(client, server, addr) == 0) {
        client_accept(data_server);
        client_handle(data_server->clients[0], data_server, &fork_cmds,
            data_server->clients[0]->fd);
    }
    server_destroy(server);
    return 0;
}
