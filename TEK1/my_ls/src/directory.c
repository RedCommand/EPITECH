/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** directory
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "local.h"

int get_nb_dir_in_dir(char *path)
{
    dir_t dir = stdr_get_file_in_dir(path);
    int counter = 0;

    for (int i = 0; i < dir.nb_files; i++) {
        if (dir.types[i] == DT_DIR)
            counter++;
    }
    if (counter < 1)
        counter = 1;
    free_dir_t(dir);
    return counter;
}

dir_t init_dir_arr(void)
{
    dir_t dir_arr;

    dir_arr.nb_files = 0;
    dir_arr.types = malloc(sizeof(char) * 1);
    dir_arr.types[0] = '\0';
    dir_arr.filenames = malloc(sizeof(char*) * 1);
    dir_arr.filenames[0] = NULL;
    return dir_arr;
}

dir_t get_dir_only(char *path)
{
    DIR *dirs = opendir(path);
    dir_t dir_arr = init_dir_arr();

    if (dirs == NULL) {
        dir_arr.types = malloc(sizeof(unsigned char) * 1);
        dir_arr.types[0] = DT_UNKNOWN;
        dir_arr.nb_files++;
        return dir_arr;
    }
    dir_arr.types = malloc(sizeof(unsigned char) * 1);
    dir_arr.types[0] = DT_DIR;
    dir_arr.filenames = add_str_to_tabl(dir_arr.filenames, ".");
    dir_arr.nb_files++;
    closedir(dirs);
    return dir_arr;
}

dir_t stdr_get_file_in_dir(char *path)
{
    DIR *dirs = opendir(path);
    struct dirent *dir;
    dir_t dir_arr = init_dir_arr();

    if (dirs == NULL) {
        dir_arr.types = malloc(sizeof(unsigned char) * 1);
        dir_arr.types[0] = DT_UNKNOWN;
        dir_arr.nb_files++;
        return dir_arr;
    }
    while ((dir = readdir(dirs)) != NULL) {
        dir_arr.filenames = add_str_to_tabl(dir_arr.filenames, dir->d_name);
        dir_arr.types = add_to_ustr(dir_arr.types, dir->d_type);
        dir_arr.nb_files++;
    }
    closedir(dirs);
    free(dir);
    return dir_arr;
}

dir_t get_file_in_dir(char *path, args_t args)
{
    if (args.d)
        return get_dir_only(path);
    else
        return stdr_get_file_in_dir(path);
}