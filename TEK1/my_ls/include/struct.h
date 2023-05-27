/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** struct
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct file_s {
    struct stat filestat;
    struct passwd *pwd;
    struct group *group;
    char *filename;
    char *path;
    char *filepath;
    char *time;
    unsigned char type;
} file_t;

typedef struct dir_s {
    char **filenames;
    int nb_files;
    unsigned char *types;
} dir_t;

typedef struct args_s {
    int l;
    int sr;
    int d;
    int r;
    int t;
    int a;
    char **paths;
    int nb_paths;
} args_t;

#endif