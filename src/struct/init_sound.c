/*
** EPITECH PROJECT, 2021
** init_sound.c
** File description:
** init_sound
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "backrooms.h"

sound_t *init_sound(char *path)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->buffer = sfSoundBuffer_createFromFile(path);
    sound->sound = sfSound_create();
    sound->is_playing = false;
    sfSound_setBuffer(sound->sound, sound->buffer);
    return sound;
}
