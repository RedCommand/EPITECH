/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** my_ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "local.h"

int ls_dir(args_t args, char *path, int bslash_l)
{
    file_t *files = NULL;
    dir_t dirs;
    int success = 0;

    dirs = get_file_in_dir(path, args);
    if (args.nb_paths > 1)
        my_printf("%s:\n", path);
    reset_file_t(files, dirs.nb_files);
    files = malloc(sizeof(file_t) * (dirs.nb_files + 1));
    for (int i = 0; i < dirs.nb_files; i++)
        files[i] = get_file_info(path, dirs.filenames[i], dirs.types[i], args);
    success = main_display(args, files, dirs.nb_files);
    free_file_t(files, dirs.nb_files);
    free_dir_t(dirs);
    if (bslash_l)
        write(1, "\n", 1);
    write(1, "\n", 1);
    return success;
}

int is_path_dir(char *path)
{
    struct stat pathstat;

    if (stat(path, &(pathstat)) < 0) {
        return -1;
    }
    if (S_ISDIR(pathstat.st_mode))
        return 1;
    else
        return 0;
}

int ls_file(args_t args, char *path, int bslash_l)
{
    file_t *files = NULL;
    int success = 0;

    if (args.nb_paths > 1)
        my_printf("%s:\n", path);
    files = malloc(sizeof(file_t) * 1);
    args.d = 1;
    files[0] = get_file_info(path, "", 1, args);
    success = main_display(args, files, 1);
    free_file_t(files, 1);
    if (bslash_l)
        write(1, "\n", 1);
    write(1, "\n", 1);
    return success;
}

int my_ls(int const ac, char const **av)
{
    args_t args = get_args(ac, av);
    int success = 0;

    for (int i = 0; i < args.nb_paths; i++) {
        if (is_path_dir(args.paths[i]) == 1)
            success |= ls_dir(args, args.paths[i], (i != args.nb_paths - 1));
        else {
            success |= ls_file(args, args.paths[i], (i != args.nb_paths - 1));
        }
    }
    free_char_tabl(args.paths);
    return success;
}