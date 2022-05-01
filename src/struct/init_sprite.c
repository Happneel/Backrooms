/*
** EPITECH PROJECT, 2021
** init_sprite.c
** File description:
** init_sprite
*/

#include <SFML/Graphics.h>

sfSprite *init_sprite(char *path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfFloatRect global_bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2f scale = {1920 / global_bounds.width, 1080 / global_bounds.height};
    sfSprite_setScale(sprite, scale);
    return sprite;
}
