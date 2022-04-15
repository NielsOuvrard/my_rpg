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

    // if (all_sprites()[HUNTER].rect.top > 16 &&
    // all_sprites()[HUNTER].rect.top < 64) {
    // }
    if (all_infos()->move != 'c') {
        all_sprites()[HUNTER].rect.left = 0;
    }
    // if (all_infos()->move)
    //     my_printf("idle perso\n");
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
        if (all_sprites()[SPRITE_SHEET].anim)       // anim eau
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
            move_pos_player();
            check_all_intecract_map_actual();
        } else {
            if (all_infos()->move != 'c')
                idle_perso();
        }
        anim_all_particules();
    }
}
        // int si = 0;
        // struct_particule *p = all_infos()->particules;
        //     p = p->next;
        // }
        // my_printf("nmb part = %d\n", si);

// int can_move_on_this_char (void)
// {
//     if (all_sprites()[HUNTER].pos.x < 0 && all_sprites()[HUNTER].pos.y < 0)
//         return 0;
//     int x = 0, y = 0;
//     if (all_infos()->move == 'u')
//         y -= 20;
//     if (all_infos()->move == 'l')
//         x -= 20;
//     if (all_infos()->move == 'd')
//         y += 20;
//     if (all_infos()->move == 'r')
//         x += 20;
//     x = ((int)all_sprites()[HUNTER].pos.x + x) / 50;
//     y = ((int)all_sprites()[HUNTER].pos.y + y) / 50;
//     if (my_arraylen(all_maps()[all_infos()->map_actual].bg) < y ||
//     my_strlen(all_maps()[all_infos()->map_actual].bg[0]) < x)
//         return 1;
//     char a = all_maps()[all_infos()->map_actual].bg[y][x];
//     if (a != '7' && a != ':' && a != 'G')
//         return 0;
//     return 1;
// }

// void move_pos_player(void)
// {
//     if (all_infos()->move_u)
//         all_infos()->pos_player.y += 10;
//     if (all_infos()->move_l)
//         all_infos()->pos_player.x += 10;
//     if (all_infos()->move_d)
//         all_infos()->pos_player.y -= 10;
//     if (all_infos()->move_l)
//         all_infos()->pos_player.x -= 10;
//     if (all_infos()->move != 'c')                                /// ailleurs
//         add_particules(all_sprites()[HUNTER].pos, 10,
//         sfColor_fromRGBA(255, 255, 255, 200));
// }
        // while (p) {
        //     si++;
