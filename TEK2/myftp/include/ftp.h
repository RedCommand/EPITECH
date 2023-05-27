/*
** EPITECH PROJECT, 2023
** nm-objdump
** File description:
** nm.h
*/

#ifndef MY_FTP_H
    #define MY_FTP_H

    #include <ctype.h>
    #include <fcntl.h>
    #include <linux/limits.h>
    #include <netinet/in.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>

    #define BUF_SIZE  4096
    #define LOCALHOST 0b00000001000000000000000001111111

    #define SERVER_DEAD        0b0000000000000001
    #define SERVER_FAIL        0b0000000000000010
    #define SERVER_FATAL       0b0000000000000100
    #define SERVER_FULL        0b0000000000001000
    #define CLIENT_DEAD        0b0000000100000000
    #define CLIENT_FAIL        0b0000001000000000
    #define CLIENT_FATAL       0b0000010000000000
    #define CLIENT_CONN_FAIL   0b0000100000000000
    #define CLIENT_DISCONN     0b0001000000000000
    #define CLIENT_SERVER_FAIL 0b0010000000000000

enum mode { NONE, PASSIVE, ACTIVE };

typedef struct client_s {
    int fd;
    char cwd[PATH_MAX + 1];
    enum mode mod;
    bool logged;
    bool identity;
} client_t;

typedef struct server_s {
    int sock;
    struct sockaddr_in sin;
    char root[PATH_MAX + 1];
    int n_clients;
    int n_client_max;
    fd_set read_fds;
    client_t **clients;
} server_t;

struct cmd_s {
    char *name;
    uint16_t (*func)(client_t *client, server_t *server, char *args);
};

struct cmds_s {
    struct cmd_s *cmds;
    size_t size;
};

// UTILS
bool is_dir(const char *path);
void clean_buf(char *buf, size_t size);
size_t get_ptr_pos(void **ptrs, void *ptr, size_t size);
bool get_current_dir(char *dest, const char *home, char *pwd, char *input);
bool file_exists(const char *path);
int open_file(const char *filepath);
bool is_logged(client_t *client, server_t *server);

// CLIENT
void client_destroy(client_t *client, server_t *server);
void client_accept(server_t *server);
uint16_t clients_handle(server_t *server, const struct cmds_s *cmds);
uint16_t client_handle(client_t *client, server_t *server,
    const struct cmds_s *cmds, int read_fd);
client_t *client_new(server_t *server, int sock);
uint16_t client_cmd(
    client_t *client, server_t *server, const struct cmds_s *cmds, char *buf);
uint16_t client_answer(client_t *client, server_t *server, const char *msg);

// SERVER
server_t *server_new(
    unsigned int port, in_addr_t addr, int n_client_max, const char *root);
server_t *server_init(
    unsigned int port, in_addr_t addr, int n_client_max, const char *root);
bool server_start(server_t *server);
void server_destroy(server_t *server);
bool server_run(server_t *server, const struct cmds_s *cmds);
void server_clean(server_t *server);

// CMD
uint16_t cmd_user(client_t *client, server_t *server, char *args);
uint16_t cmd_pass(client_t *client, server_t *server, char *args);
uint16_t cmd_cwd(client_t *client, server_t *server, char *args);
uint16_t cmd_cdup(client_t *client, server_t *server, char *args);
uint16_t cmd_quit(client_t *client, server_t *server, char *args);
uint16_t cmd_pwd(client_t *client, server_t *server, char *args);
uint16_t cmd_pasv(client_t *client, server_t *server, char *args);
uint16_t cmd_help(client_t *client, server_t *server, char *args);
uint16_t cmd_noop(client_t *client, server_t *server, char *args);
uint16_t cmd_retr(client_t *client, server_t *server, char *args);
uint16_t cmd_stor(client_t *client, server_t *server, char *args);
uint16_t cmd_list(client_t *client, server_t *server, char *args);
uint16_t cmd_syst(client_t *client, server_t *server, char *args);

// CMD_FORK
uint16_t cmd_fork_retr(client_t *client, server_t *server, char *args);
uint16_t cmd_fork_stor(client_t *client, server_t *server, char *args);
uint16_t cmd_fork_list(client_t *client, server_t *server, char *args);

bool ftp(char *root, uint16_t port, int n_client_max);

#endif //MY_FTP_H
