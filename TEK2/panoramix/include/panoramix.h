/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix.h
*/

#pragma once

#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct args_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} args_t;

typedef struct villager_s {
    int id;
    pthread_t thread;
    int fights;
} villager_t;

typedef struct druid_s {
    pthread_t thread;
    int pot_size;
    int nb_refills;
} druid_t;

void print_villager_start(int id);
void print_villager_try_drink(int id, int potion_left);
void print_villager_call_druid(int id);
void print_villager_fight(int id, int fight_left);
void print_villager_stop(int id);

void print_druid_start(void);
void print_druid_refill(int nb_refill);
void print_druid_stop(void);

bool get_help(int argc, char **argv);
bool get_args(args_t *args, int argc, char **argv);
bool panoramix(args_t *args);
bool thread_join(pthread_t *thread);
bool init_globals(args_t *args);
bool druid_create(druid_t *druid, args_t *args);
bool villagers_create(villager_t *villagers, args_t *args);
