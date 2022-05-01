/*
** EPITECH PROJECT, 2021
** init_clock.c
** File description:
** init_clock
*/

#include <stdlib.h>
#include "backrooms.h"

clocks_t *init_clock_struct(void)
{
    clocks_t *clocks = malloc(sizeof(struct clocks_s));

    clocks->main_clock = sfClock_create();
    clocks->main_seconds = 0;
    clocks->escape_clock = sfClock_create();
    clocks->escape_seconds = 0;
    return clocks;
}
