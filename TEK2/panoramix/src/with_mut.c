/*
** EPITECH PROJECT, 2023
** Project
** File description:
** panoramix.c
*/

#include <semaphore.h>
#include "panoramix.h"

static pthread_mutex_t pot_lock;
static pthread_mutex_t refill_lock;
static pthread_mutex_t refill_end_lock;
static int pot = 0;

void *druid_thread(void *args)
{
    druid_t *druid = args;

    print_druid_start();
    while (druid->nb_refills > 0) {
        pthread_mutex_lock(&refill_lock);
        druid->nb_refills--;
        print_druid_refill(druid->nb_refills);
        pot += druid->pot_size;
        pthread_mutex_unlock(&refill_end_lock);
    }
    print_druid_stop();
    return NULL;
}

void *villager_thread(void *args)
{
    villager_t *villager = args;

    print_villager_start(villager->id);
    while (villager->fights > 0) {
        pthread_mutex_lock(&pot_lock);
        print_villager_try_drink(villager->id, pot);
        if (pot <= 0) {
            print_villager_call_druid(villager->id);
            pthread_mutex_unlock(&refill_lock);
            pthread_mutex_lock(&refill_end_lock);
        }
        pot--;
        pthread_mutex_unlock(&pot_lock);
        villager->fights--;
        print_villager_fight(villager->id, villager->fights);
    }
    print_villager_stop(villager->id);
    return NULL;
}

bool villagers_create(villager_t *villagers, args_t *args)
{
    int status = 0;

    if (villagers == NULL)
        return false;
    for (int i = 0; i < args->nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].fights = args->nb_fights;
        status = pthread_create(
            &(villagers[i].thread), NULL, &villager_thread, &(villagers[i]));
        if (status != 0) {
            free(villagers);
            fprintf(stderr, "pthread_create: %s", strerror(status));
            return false;
        }
    }
    return true;
}

bool druid_create(druid_t *druid, args_t *args)
{
    int status = 0;

    druid->pot_size = args->pot_size;
    druid->nb_refills = args->nb_refills;
    status = pthread_create(&(druid->thread), NULL, &druid_thread, druid);
    if (status != 0) {
        fprintf(stderr, "pthread_create: %s", strerror(status));
        return false;
    }
    return true;
}

bool init_globals(args_t *args)
{
    pot = args->pot_size;
    if (pthread_mutex_init(&refill_lock, NULL) != 0
        || pthread_mutex_init(&refill_end_lock, NULL) != 0
        || pthread_mutex_init(&pot_lock, NULL) != 0)
        return false;
    pthread_mutex_lock(&refill_lock);
    pthread_mutex_lock(&refill_end_lock);
    return true;
}
