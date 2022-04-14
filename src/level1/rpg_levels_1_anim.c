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
    if (all_infos()->move != 'c')
        add_particules(all_sprites()[HUNTER].pos, 10,
        sfColor_fromRGBA(255, 255, 255, 200));
}

void find_all_particules_from_mg (void)
{
    for (int i = 0; all_maps()[all_infos()->map_actual].mg[i]; i++) {
        for (int j = 0; all_maps()[all_infos()->map_actual].mg[i][j]; j++) {
            find_tile_particle(all_maps()[
            all_infos()->map_actual].mg[i][j], i, j);
        }
    }
    int si = 0;
    struct_particule *p = all_infos()->particules;
    while (p) {
        si++;
        p = p->next;
    }
    my_printf("nmb part = %d\n", si);
}

void level_1_clock(sfEvent event)
{
    if (!(all_infos()->clock_val % 10)) {
        anim_perso();
        anim_all_enemies();

    }
    if (!(all_infos()->clock_val % 2)) {
        if (all_infos()->move) {
            move_pos_player();
            change_look_hunter();
        }
        anim_all_particules();
        find_all_particules_from_mg();
    }
}