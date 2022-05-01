/*
** EPITECH PROJECT, 2021
** update_clock.c
** File description:
** update_clock
*/

#include <SFML/Graphics.h>

float update_clock(sfClock *clock)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    return seconds;
}
