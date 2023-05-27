/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** local
*/

#include "struct.h"

#ifndef LOCAL_H
    #define LOCAL_H
args_t get_args(int ac, char const **av);
file_t get_file_info(char *path, char *filenam, unsigned char type, args_t ag);
int main_display(args_t args, file_t *files, int nb_files);
unsigned char *add_to_ustr(unsigned char *str, unsigned char c);
char **add_str_to_tabl(char **tabl, char *str);
void free_char_tabl(char **tabl);
int my_char_tabl_len(char **tabl);
void reset_file_t(file_t *files, int nb_paths);
void free_dir_t(dir_t dirs);
void free_char_tabl(char **tabl);
void free_file_t(file_t *files, int nb_files);
dir_t stdr_get_file_in_dir(char *path);
char **create_char_tabl(int size);
dir_t get_file_in_dir(char *path, args_t args);
void sort_files(args_t args, file_t *files, int nb_files);
int get_nb_dir_in_dir(char *path);

#endif
