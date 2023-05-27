/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** ftp.c
*/

#include "ftp.h"

static const struct cmds_s cmds = {
    .cmds = (struct cmd_s[13]){{"USER", &cmd_user}, {"PASS", &cmd_pass},
        {"CWD ", &cmd_cwd}, {"CDUP", &cmd_cdup}, {"QUIT", &cmd_quit},
        {"PWD", &cmd_pwd}, {"PASV", &cmd_pasv}, {"HELP", &cmd_help},
        {"NOOP", &cmd_noop}, {"LIST", &cmd_list}, {"RETR ", &cmd_retr},
        {"STOR ", &cmd_stor}, {"SYST", &cmd_syst}},
    .size = 13};

bool ftp(char *root, uint16_t port, int n_client_max)
{
    server_t *server = server_new(port, INADDR_ANY, n_client_max, root);

    if (server == NULL)
        return false;
    if (port == 0)
        printf("Using port %d\n", htons(server->sin.sin_port));
    return server_run(server, &cmds);
}
