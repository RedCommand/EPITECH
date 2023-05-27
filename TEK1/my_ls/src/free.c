/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** free
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "local.h"

void free_file_t(file_t *files, int nb_files)
{
    for (int i = 0; i < nb_files; i++) {
        if (files[i].type != DT_UNKNOWN) {
            free(files[i].filename);
            free(files[i].path);
            free(files[i].filepath);
        }
    }
    free(files);
}

void free_dir_t(dir_t dirs)
{
    free_char_tabl(dirs.filenames);
    free(dirs.types);
}

void free_char_tabl(char **tabl)
{
    for (int i = 0; i < my_char_tabl_len(tabl) - 1; i++)
        free(tabl[i]);
    free(tabl);
}

void reset_file_t(file_t *files, int nb_paths)
{
    file_t file;

    if (files == NULL)
        return files;
    for (int i = 0; i < nb_paths; i++) {
        free(files[i].filename);
        free(files[i].path);
    }
    free(files);
}