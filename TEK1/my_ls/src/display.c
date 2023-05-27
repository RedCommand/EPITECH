/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** display
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "struct.h"
#include "local.h"

char *get_permission(struct stat filestat)
{
    int perm[] = {0, S_IRUSR, S_IWUSR, S_IXUSR,
                S_IRGRP, S_IWGRP, S_IXGRP,
                S_IROTH, S_IWOTH, S_IXOTH};
    char *perm_char = my_strdup("----------");
    char *pos_perm = "drwxrwxrwx";
    perm[0] = S_ISDIR(filestat.st_mode);
    for (int i = 1; i < 10; i++) {
        if (perm[i] & filestat.st_mode)
            perm_char[i] = pos_perm[i];
    }
    if (perm[0])
        perm_char[0] = pos_perm[0];
    return perm_char;
}

void display_element(args_t args, file_t file, int index, int nb_files)
{
    if (args.l) {
        my_printf("%s %d %s %s %d %s %s",
        get_permission(file.filestat), get_nb_dir_in_dir(file.filepath),
        file.pwd->pw_name, file.group->gr_name, file.filestat.st_size,
        file.time, file.filename);
        if (index != nb_files - 1)
            my_putchar('\n');
    } else {
        if (index != 0)
            my_printf("  ");
        my_printf("%s", file.filename);
    }
}

int need_display(args_t args, file_t file, int index, int nb_files)
{
    if (args.a) {
        display_element(args, file, index, nb_files);
    } else {
        if (file.filename[0] != '.')
            display_element(args, file, index, nb_files);
    }
    if (file.type == DT_DIR) {
        recursive_ls(file.filepath, args, file.filename);
    }
}

int recursive_ls(char *path, args_t args, char *filename)
{
    if (args.sr) {
        if ((filename[0] == '.' && filename[1] == '\0') ||
        (filename[0] == '.' && filename[1] == '.' && filename[2] == '\0'))
            return 0;
        else {
            my_putstr(" :\n");
            return ls_dir(args, path, 1);
        }
    }
    return 0;
}

int main_display(args_t args, file_t *files, int nb_files)
{
    int success = 0;
    int total = 0;

    sort_files(args, files, nb_files);
    for (int i = 0; i < nb_files; i++) {
        if (files[i].type != DT_UNKNOWN)
            total += files[i].filestat.st_blocks;
    }
    if (args.l)
        my_printf("total %d\n", total / 2);
    for (int i = 0; i < nb_files; i++) {
        if (files[i].type == DT_UNKNOWN) {
            my_printf("./my_ls: cannot access '%s': No such file or directory",
            files[i].path);
            success = 1;
        } else
            need_display(args, files[i], i, nb_files);
    }
    return success;
}