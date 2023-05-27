/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** utils.c
*/

#include "panoramix.h"

bool thread_join(pthread_t *thread)
{
    int status = 0;

    status = pthread_join(*thread, NULL);
    if (status != 0) {
        fprintf(stderr, "pthread_join: %s", strerror(status));
        return false;
    }
    return true;
}
