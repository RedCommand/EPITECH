/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** print_druid.c
*/

#include "panoramix.h"

void print_druid_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

void print_druid_refill(int nb_refill)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I "
          "can only make %d more refills after this one.\n",
        nb_refill);
}

void print_druid_stop(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
