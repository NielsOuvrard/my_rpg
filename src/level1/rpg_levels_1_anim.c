/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void anim_perso(void)
{
    if (all_sprites()[SPRITE_SHEET].anim)
        all_sprites()[SPRITE_SHEET].anim = '\0';
    else
        all_sprites()[SPRITE_SHEET].anim = 'a';
    if (!all_infos()->move)
        return;
    anim_perso_according_to_int(HUNTER);
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
}

int can_move_on_this_char (void)
{
    if (all_sprites()[HUNTER].pos.x < 0 && all_sprites()[HUNTER].pos.y < 0)
        return 0;
    int x = 0, y = 0;
    if (all_infos()->move == 'u')
        y -= 20;
    if (all_infos()->move == 'l')
        x -= 20;
    if (all_infos()->move == 'd')
        y += 20;
    if (all_infos()->move == 'r')
        x += 20;
    x = ((int)all_sprites()[HUNTER].pos.x + x) / 50;
    y = ((int)all_sprites()[HUNTER].pos.y + y) / 50;
    if (my_arraylen(all_maps()[all_infos()->map_actual].bg) < y ||
    my_strlen(all_maps()[all_infos()->map_actual].bg[0]) < x)
        return 1;
    char a = all_maps()[all_infos()->map_actual].bg[y][x];
    if (a != '7' && a != ':' && a != 'G')
        return 0;
    return 1;
}

void move_pos_player(void)
{
    if (all_infos()->move == 'u')
        all_infos()->pos_player.y += 10;
    if (all_infos()->move == 'l')
        all_infos()->pos_player.x += 10;
    if (all_infos()->move == 'd')
        all_infos()->pos_player.y -= 10;
    if (all_infos()->move == 'r')
        all_infos()->pos_player.x -= 10;
}

void level_1_clock(sfEvent event)
{
    if (!(all_infos()->clock_val % 10)) {
        anim_perso();
        anim_all_enemies();
    }
    if (all_infos()->move && !(all_infos()->clock_val % 2)) {
        move_pos_player();
        change_look_hunter();
    }
}