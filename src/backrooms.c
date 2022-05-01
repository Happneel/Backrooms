/*
** EPITECH PROJECT, 2021
** backrooms.c
** File description:
** backrooms
*/

#include <SFML/Graphics.h>
#include "backrooms.h"

static int events_handling(backrooms_t *backrooms)
{
    while (sfRenderWindow_pollEvent(backrooms->window, &backrooms->event)) {
        if (backrooms->event.type == sfEvtKeyPressed && backrooms->event.key.code == sfKeySpace)
            return 1;
        else if (backrooms->event.type == sfEvtKeyPressed && backrooms->event.key.code == sfKeyEscape)
            display_escape(backrooms);
    }
    return 0;
}

int backrooms(int ac, char **av)
{
    backrooms_t *backrooms = NULL;

    if (error_handling(ac, av) >= 84)
        return 84;
    backrooms = init_backrooms_struct();
    while (backrooms->clocks->main_seconds < 7.0 && events_handling(backrooms) == 0) {
        sfClock_restart(backrooms->clocks->escape_clock);
        backrooms->clocks->main_seconds = update_clock(backrooms->clocks->main_clock);
        sfRenderWindow_clear(backrooms->window, sfBlack);
        display_steps(backrooms);
        sfRenderWindow_display(backrooms->window);
    }
    free_struct(backrooms);
    return 0;
}
