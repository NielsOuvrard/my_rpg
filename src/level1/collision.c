/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** collision
*/

#include "my.h"
#include "rpg_header.h"

int can_move(int x, int y)
{
    int final_x = (all_sprites()[HUNTER].pos.x + x) / (SIZE_TILE);
    int final_y = (all_sprites()[HUNTER].pos.y + y) / (SIZE_TILE);
    if (all_maps()[all_infos()->map_actual].mg[final_y] == NULL)
        return 0;
    if (final_y < 0 || final_x < 0)
        return 0;
    if (final_y > my_arraylen(all_maps()[all_infos()->map_actual].mg))
        return 0;
    my_putchar(all_maps()[all_infos()->map_actual].bg[final_y][final_x]);
    my_putchar(all_maps()[all_infos()->map_actual].mg[final_y][final_x]);
    my_putchar('\n');
    if(!is_movable(all_maps()[all_infos()->map_actual].mg[final_y][final_x],
    all_maps()[all_infos()->map_actual].bg[final_y][final_x]))
        return 0;
    return 1;
}

int is_movable_next(char my_mg, char my_bg)
{
    char mg[] = "Z3<?fg]0MABCiY";
    int i = 0;
    while (mg[i]) {
        if (mg[i] == my_mg)
            return 0;
        i++;
    }
    i = 0;
    char bg[] = "4IHJ@bVN";
    while (bg[i]) {
        if (bg[i] == my_bg)
            return 0;
        i++;
    }
    return 1;
}

int is_movable(char my_mg, char my_bg)
{
    if (!my_mg || !my_bg)
        return 0;
    if (my_bg == 'N' && my_mg == '9')
        return 1;
    if (my_bg == '@' && my_mg == '9')
        return 1;
    if (my_bg == 'V' && my_bg == 'X')
        return 1;
    if (my_bg == 'V' || my_bg == '4' && my_mg == 'X' || my_mg == 'Y')
        return 1;
    if (my_mg == ':' || my_mg == 'm' || my_mg == 's')
        return 1;
    if (my_bg == '@' && my_mg == ':' || my_mg == '9' || my_mg == '\\')
        return 1;
    return is_movable_next(my_mg, my_bg);
}
