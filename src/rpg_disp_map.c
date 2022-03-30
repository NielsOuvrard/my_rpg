/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"


void disp_tile_sprite_sheet(int i, int j, int top, int left)
{
    int type = SPRITE_SHEET;
    all_sprites()[type].rect.top = top;
    all_sprites()[type].rect.left = left;
    sfSprite_setTextureRect(all_sprites()[type].sprite, all_sprites()[type].rect);

    all_sprites()[type].pos.x = (all_sprites()[type].scale.x * 16) * all_infos()->zoom * j;
    all_sprites()[type].pos.y = (all_sprites()[type].scale.x * 16) * all_infos()->zoom * i;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_map_next(char **map, int i, int j)
{
    if (!(map[i][j] >= '0' && map[i][j] <= '0' + 30))
        return;
    int x = map[i][j] - '0';
    x *= 16;
    int y = 0;
    while (x >= 96) {
        y += 16;
        x -= 96;
    }
    if (y == 16 * 4 && (x == 0 || x == 16)) {
        x = all_sprites()[SPRITE_SHEET].anim ? 16 : 0;
    }
    disp_tile_sprite_sheet(i, j, y, x);
}

void disp_tile(int i, int j, int type)
{
    all_sprites()[type].pos.x = (all_sprites()[type].scale.x * 100) * j;
    all_sprites()[type].pos.y = (all_sprites()[type].scale.x * 100) * i;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_tile_sprite_seet(int i, int j, int top, int left)
{
    all_sprites()[SPRITE_SHEET].rect.top = top;
    all_sprites()[SPRITE_SHEET].rect.left = left;
    sfSprite_setTextureRect(all_sprites()[SPRITE_SHEET].sprite, all_sprites()[SPRITE_SHEET].rect);

    all_sprites()[SPRITE_SHEET].pos.x = (all_sprites()[SPRITE_SHEET].scale.x * 16) * j;
    all_sprites()[SPRITE_SHEET].pos.y = (all_sprites()[SPRITE_SHEET].scale.x * 16) * i;
    sfSprite_setPosition(all_sprites()[SPRITE_SHEET].sprite, all_sprites()[SPRITE_SHEET].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[SPRITE_SHEET].sprite, NULL);
}

// void disp_map_next(char **map, int i, int j)
// {
//     if (map[i][j] == 'g') {
//         disp_tile_sprite_seet(i, j, 16, 16);
//         // disp_tile(i, j, GRASS);
//     }
//     if (map[i][j] == 's') {
//         disp_tile_sprite_seet(i, j, 16, 2 * 16);
//         // disp_tile(i, j, SAND);
//     }
//     if (map[i][j] == 'w') {
//         int anim = all_sprites()[SPRITE_SHEET].anim ? 16 : 0;
//         disp_tile_sprite_seet(i, j, 4 * 16, anim);
//         // disp_tile(i, j, WATHER);
//     }
//     if (map[i][j] == 'd') {
//         disp_tile_sprite_seet(i, j, 32, 64);
//         // disp_tile(i, j, DIRT);
//     }
// }

void disp_map(char **map)
{
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++)
            disp_map_next(map, i, j);
}
