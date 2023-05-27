/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** sort
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "local.h"

void swapfile(file_t *file1, file_t *file2)
{
    file_t temp = {0};

    temp = *file1;
    *file1 = *file2;
    *file2 = temp;
}

void sort_files(args_t args, file_t *files, int nb_files)
{
    if (args.r) {
        for (int i = 0; i < nb_files / 2; i++) {
            swapfile(&files[i], &files[nb_files - i - 1]);
        }
    }
}