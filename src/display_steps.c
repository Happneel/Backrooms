/*
** EPITECH PROJECT, 2021
** display_steps.c
** File description:
** display_steps
*/

#include "backrooms.h"

void display_escape(backrooms_t *backrooms)
{
    while (backrooms->clocks->escape_seconds < 0.3) {
        backrooms->clocks->escape_seconds = update_clock(backrooms->clocks->escape_clock);
        sfRenderWindow_clear(backrooms->window, sfBlack);
        sfRenderWindow_drawText(backrooms->window, backrooms->text->escape, NULL);
        sfRenderWindow_display(backrooms->window);
    }
    backrooms->clocks->escape_seconds = 0.0;
}

static void display_first_step(backrooms_t *backrooms)
{
    sfRenderWindow_drawText(backrooms->window, backrooms->text->clip, NULL);
}

static void display_second_step(backrooms_t *backrooms)
{
    sfRenderWindow_drawText(backrooms->window, backrooms->text->clip, NULL);
    sfRenderWindow_drawText(backrooms->window, backrooms->text->welcome, NULL);
}

static void display_final_step(backrooms_t *backrooms)
{
    if (!backrooms->sound->is_playing) {
        sfSound_play(backrooms->sound->sound);
        backrooms->sound->is_playing = true;
    }
    sfRenderWindow_drawSprite(backrooms->window, backrooms->sprite, NULL);
}

void display_steps(backrooms_t *backrooms)
{
    if (backrooms->clocks->main_seconds < 2.0)
        display_first_step(backrooms);
    else if (backrooms->clocks->main_seconds > 2.0 && backrooms->clocks->main_seconds < 4.0)
        display_second_step(backrooms);
    else
        display_final_step(backrooms);
}
