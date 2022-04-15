/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void level_1(sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    // my_printf("top : %d\tleft : %d\n", all_sprites()[HUNTER].rect.top, all_sprites()[HUNTER].rect.left);

    // if (all_sprites()[BANANA].anim)
    //     sfRenderWindow_drawSprite(all_infos()->window,
    //     all_sprites()[BANANA].sprite, NULL);
    return;
}
