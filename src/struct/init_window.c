/*
** EPITECH PROJECT, 2021
** init_window.c
** File description:
** init_window
*/

#include <SFML/Graphics.h>

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Backrooms", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}
