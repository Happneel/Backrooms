/*
** EPITECH PROJECT, 2021
** init_texts.c
** File description:
** init_texts
*/

#include <stdlib.h>
#include "backrooms.h"

static sfText *init_text(char *text, int *position)
{
    sfText *text_back = sfText_create();
    sfFont *font = sfFont_createFromFile("/usr/local/lib/backrooms/assets/font/font.ttf");
    sfFloatRect text_rect = {0, 0, 0, 0};
    sfVector2f text_origin = {0, 0};
    sfVector2f text_pos = {position[0], position[1]};
    int text_size = 50;

    sfText_setFont(text_back, font);
    sfText_setString(text_back, text);
    sfText_setCharacterSize(text_back, text_size);
    text_rect = sfText_getGlobalBounds(text_back);
    text_origin.x = text_rect.left + text_rect.width / 2;
    text_origin.y = text_rect.top + text_rect.height / 2;
    sfText_setOrigin(text_back, text_origin);
    sfText_setPosition(text_back, text_pos);
    return text_back;
}

text_t *init_texts_struct(void)
{
    text_t *text = malloc(sizeof(text_t));

    text->clip = init_text("You clipped.", (int[2]){1920 / 2, 1080 / 2});
    text->welcome = init_text("Welcome to the backrooms.", (int[2]){1920 / 2, 1080 / 2 + 100});
    text->escape = init_text("You cant escape.", (int[2]){1920 / 2, 1080 / 2});
    return text;
}
