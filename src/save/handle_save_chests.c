/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** handle_save_chests
*/

#include "my.h"
#include "rpg_header.h"

void handle_save_chests(char *buffer, int *type)
{
    if (*type != 5)
        return;
    my_putstr(buffer);
    int i = 0;
    int map_nb = 0, x = 0, y = 0;
    map_nb = my_getnbr(buffer);
    while (my_isdidgit(buffer[0]))
        buffer++;
    buffer++;
    y = my_getnbr(buffer);
    while (my_isdidgit(buffer[0]))
        buffer++;
    buffer++;
    x = my_getnbr(buffer);
    all_maps()[map_nb].mg[y][x] = 'Q';
    return;
}
