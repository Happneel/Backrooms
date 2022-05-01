/*
** EPITECH PROJECT, 2021
** free_struct.c
** File description:
** free_struct
*/

#include <stdlib.h>
#include "backrooms.h"

void free_struct(backrooms_t *backrooms)
{
    sfSound_destroy(backrooms->sound->sound);
    sfSoundBuffer_destroy(backrooms->sound->buffer);
    sfSprite_destroy(backrooms->sprite);
    sfRenderWindow_destroy(backrooms->window);
    free(backrooms);
}
