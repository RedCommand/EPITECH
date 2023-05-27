/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix.c
*/

#include "panoramix.h"

bool panoramix(args_t *args)
{
    villager_t *villagers = NULL;
    druid_t druid = {0};
    bool status = true;

    if (args == NULL || !init_globals(args))
        return false;
    villagers = calloc(args->nb_villagers, sizeof(villager_t));
    if (villagers == NULL)
        return false;
    if (!druid_create(&druid, args) || !villagers_create(villagers, args)) {
        free(villagers);
        return false;
    }
    status = thread_join(&(druid.thread));
    for (int i = 0; i < args->nb_villagers; i++) {
        if (!thread_join(&(villagers[i].thread)))
            status = false;
    }
    free(villagers);
    return status;
}
