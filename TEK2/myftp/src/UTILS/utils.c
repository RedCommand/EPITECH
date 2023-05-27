/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** utils.c
*/

#include "ftp.h"

bool is_dir(const char *path)
{
    struct stat st;

    if (stat(path, &st) == -1)
        return false;
    return S_ISDIR(st.st_mode);
}

void clean_buf(char *buf, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (!isprint(buf[i]))
            buf[i] = '\0';
    }
}

size_t get_ptr_pos(void **ptrs, void *ptr, size_t size)
{
    if (size == 0 || ptr == NULL || ptrs == NULL || ptrs[0] == NULL)
        return -1;
    for (size_t i = 0; i < size; i++) {
        if (ptrs[i] == ptr)
            return i;
    }
    return -1;
}

bool file_exists(const char *path)
{
    struct stat s;

    if (stat(path, &s) == -1)
        return false;
    return S_ISREG(s.st_mode);
}

int open_file(const char *filepath)
{
    struct stat s;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return -1;
    if (fstat(fd, &s) == -1)
        return -1;
    if (!S_ISREG(s.st_mode))
        return -1;
    return fd;
}
