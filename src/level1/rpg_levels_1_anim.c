/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void idle_perso(void)
{
    if (!all_infos()->move && all_sprites()[HUNTER].rect.top > 16) {
        all_sprites()[HUNTER].anim = 'f';
        all_sprites()[HUNTER].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
        all_sprites()[HUNTER].rect);
        return;
    }
    if (all_infos()->move != 'c')
        all_sprites()[HUNTER].rect.left = 0;
    all_infos()->move = '\0';
    all_sprites()[HUNTER].anim = 'a';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
    return;
}

void anim_perso(void)
{
    if (!all_infos()->move)
        return;
    if (all_infos()->move == 'c')
        my_printf("on anim car %c\n", all_infos()->move);
    anim_perso_according_to_int();
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
}

void find_all_particules_from_mg (void)
{
    for (int i = 0; all_maps()[all_infos()->map_actual].mg[i]; i++) {
        for (int j = 0; all_maps()[all_infos()->map_actual].mg[i][j]; j++) {
            find_tile_particle(all_maps()[
            all_infos()->map_actual].mg[i][j], i, j);
        }
    }
}

void level_1_animations(sfEvent event)
{
    if (!(all_infos()->clock_val % 10)) {
        if (all_sprites()[SPRITE_SHEET].anim)
            all_sprites()[SPRITE_SHEET].anim = '\0';
        else
            all_sprites()[SPRITE_SHEET].anim = 'a';
        anim_perso();
        anim_all_enemies();
        find_all_particules_from_mg();
    }
    if (!(all_infos()->clock_val % 2)) {
        if (all_infos()->move_d || all_infos()->move_u ||
            all_infos()->move_r || all_infos()->move_l) {
            check_all_intecract_map_actual();
            move_pos_player();
        } else if (all_infos()->move != 'c') {
            idle_perso();
        }
        anim_all_particules();
    }
}
