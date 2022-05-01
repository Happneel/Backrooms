/*
** EPITECH PROJECT, 2021
** init_struct.c
** File description:
** init_struct
*/

#include <stdlib.h>
#include "backrooms.h"

backrooms_t *init_backrooms_struct(void)
{
    backrooms_t *backrooms = malloc(sizeof(backrooms_t));

    backrooms->window = init_window();
    backrooms->clocks = init_clock_struct();
    backrooms->text = init_texts_struct();
    backrooms->sound = init_sound("/usr/local/lib/backrooms/assets/sound/backrooms.ogg");
    backrooms->sprite = init_sprite("/usr/local/lib/backrooms/assets/backrooms.png");
    return backrooms;
}
