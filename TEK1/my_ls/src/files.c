/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** files
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "my.h"
#include "struct.h"
#include "local.h"

char *generate_filepath(char *filename, char *path, args_t args)
{
    int len_filename = my_strlen(filename);
    int len_path = my_strlen(path);
    char *res = malloc(sizeof(char) * (len_filename + len_path + 2));
    int i = 0;

    if (args.d)
        res = my_strcpy(res, path);
    else {
        for (i = 0; i < len_path; i++)
            res[i] = path[i];
        res[i++] = '/';
        for (int j = 0; j < len_filename; j++)
            res[i++] = filename[j];
        res[i] = '\0';
    }
    return res;
}

char *get_filename(char *path, char *filename, int mode)
{
    if (mode)
        return my_strdup(path);
    else
        return my_strdup(filename);
}

char *get_file_time(file_t file)
{
    char *res = ctime((time_t *)&(file.filestat.st_mtime));
    int length = my_strlen(res);

    for (int i = 0; i < 10; i++)
        res[length - i] = '\0';
    res = &res[4];
    return res;
}

file_t get_file_info(char *path, char *filenam, unsigned char type, args_t ag)
{
    file_t file;

    file.type = type;
    file.path = my_strdup(path);
    if ((path != NULL) && (filenam != NULL) && (type != DT_UNKNOWN)) {
        file.filename = get_filename(path, filenam, ag.d);
        file.filepath = generate_filepath(file.filename, file.path, ag);
        if (stat(file.filepath, &(file.filestat)) < 0) {
            file.type = DT_UNKNOWN;
        } else {
            file.pwd = getpwuid(file.filestat.st_uid);
            file.group = getgrgid(file.filestat.st_gid);
            file.time =  get_file_time(file);
        }
    }
    return file;
}