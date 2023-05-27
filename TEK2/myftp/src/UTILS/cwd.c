/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** cwd.c
*/

#include "ftp.h"

void clean_path(char *path)
{
    for (size_t index = PATH_MAX - 1; index > 0; index--) {
        if (path[index] == '\0')
            continue;
        if (path[index] == '/') {
            path[index] = '\0';
            continue;
        }
        if (index > 1 && path[index] == '.' && path[index - 1] == '/') {
            path[index] = '\0';
            continue;
        }
        break;
    }
}

static size_t go_back_dir(char *value, size_t i)
{
    size_t tmp;

    if (i < 1)
        return -1;
    for (tmp = i - 1; tmp != -1; tmp--) {
        if (value[tmp] != '/')
            continue;
        memmove(&value[tmp], &value[i + 3], (PATH_MAX - (i + 3)));
        return tmp;
    }
    return -1;
}

static size_t get_base_dir(
    char *dest, const char *home, char *pwd, char *input)
{
    size_t len;

    clean_path(input);
    memset(dest, 0, PATH_MAX);
    if (input[0] == '/') {
        len = strlen(home) - 1;
        strcpy(dest, home);
        strcat(dest, input);
    } else {
        len = strlen(pwd);
        strcpy(dest, pwd);
        strcat(dest, "/");
        strcat(dest, input);
    }
    return len;
}

bool check_path(char *dest, const char *home, char *path)
{
    if (strncmp(home, path, strlen(home)) != 0)
        return false;
    memset(dest, 0, PATH_MAX);
    strcpy(dest, path);
    return true;
}

bool get_current_dir(char *dest, const char *home, char *pwd, char *input)
{
    size_t len;
    bool status = true;
    char value[PATH_MAX];

    len = get_base_dir(value, home, pwd, input);
    for (size_t i = len; status && i < PATH_MAX; i++) {
        if (value[i] == '.' && value[i + 1] == '/' && value[i - 1] == '/') {
            memmove(&value[i], &value[i + 2], (PATH_MAX - (i + 2)));
            i -= 2;
        }
        if (value[i] == '/' && value[i + 1] == '.' && value[i + 2] == '.') {
            i = go_back_dir(value, i);
            status = (i != -1);
            i--;
        }
    }
    if (!status)
        return false;
    clean_path(value);
    return check_path(dest, home, value);
}
