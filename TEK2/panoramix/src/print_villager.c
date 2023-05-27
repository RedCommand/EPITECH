/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** print.c
*/

#include "panoramix.h"

void print_villager_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

void print_villager_try_drink(int id, int potion_left)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n",
        id, potion_left);
}

void print_villager_call_druid(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        id);
}

void print_villager_fight(int id, int fight_left)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n",
        id, fight_left);
}

void print_villager_stop(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}
