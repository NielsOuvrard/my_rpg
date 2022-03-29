/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void disp_tile(int i, int j, int type)
{
    all_sprites()[type].pos.x = (all_sprites()[type].scale.x * 100) *
    all_infos()->zoom * j;
    all_sprites()[type].pos.y = (all_sprites()[type].scale.x * 100) *
    all_infos()->zoom * i;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_map_next(int i, int j)
{
    if (all_infos()->map[i][j] == 'g') {
        disp_tile(i, j, GRASS);
    } else if (all_infos()->map[i][j] == 's') {
        disp_tile(i, j, SAND);
    }
    if (all_infos()->map[i][j] == 'w') {
        disp_tile(i, j, WATHER);
    } else if (all_infos()->map[i][j] == 'd') {
        disp_tile(i, j, DIRT);
    }
}

void disp_map(void)
{
    for (int i = 0; all_infos()->map[i]; i++)
        for (int j = 0; all_infos()->map[i][j]; j++)
            disp_map_next(i, j);
}
