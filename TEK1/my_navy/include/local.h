/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** local
*/

#ifndef LOCAL_H
#define LOCAL_H

#define BOARD_SIZE 8
#define BOAT_NUMBER 4
#define TURN_TIMEOUT 100

#include "my.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <ucontext.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

struct boat
{
    int size;
    int x1;
    int y1;
    int x2;
    int y2;
};

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct signals_s {
    int sig_num;
    int sig_pid;
    int next;
} signals_t;

int **init_map(void);
int get_other_pid(void);
int get_s_connection(void);
int main_server(int **map);
position_t *read_input(void);
int verify_boat(char *boat);
int send_pid(int enemy_pid);
bool *int_to_bool_arr(int nb);
void printchar(int character);
int get_c_connection(int pid);
int send_int(int nb, int pid);
int **recev_map(int enemy_pid);
int bool_arr_to_int(bool *arr);
int main_client(int **map, int enemy_pid);
void print_map(int **map, int line);
int recev_int(int pid, int timeout);
int navy(int ac, char **av, int **map);
int **extract_position(char *file_char);
int **get_boat_position(char *filepath);
int send_map(int enemy_pid, int **map);
position_t *get_shoot_pos(int enemy_pid);
void display_maps(int **me, int **enemy);
void print_mapenemy(int **map, int line);
void init_sig_var(struct sigaction *act);
int **put_boat_pos(struct boat *boat, int **map);
int send_maptwo(int enemy_pid, int **map, int i);
int error_management(int ac, char **av, int **map);
int **extract_boat_position(char *boat_pos, int **map);
int send_shoot_pos(int enemy_pid, int posX, int posY);
void handler(int signum, siginfo_t *info, void *context);
int my_turn(int enemy_pid, int **map, int **enemy_map);
int your_turn(int enemy_pid, int **map, int **enemy_map);

#endif
