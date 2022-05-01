/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error_handling
*/

#include "backrooms.h"

int error_handling(int ac, char **av)
{
    UNUSED(av);
    if (ac != 1)
        return 84;
    return 0;
}
