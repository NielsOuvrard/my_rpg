/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void disp_hud (void)
{
    sfVector2f pos = {(1920 * 0.5) * 0.05, (1080 * 0.5) * 0.09};
    sfRectangleShape *rectan = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectan, pos);
    sfRectangleShape_setFillColor(rectan, sfBlack);
    sfRectangleShape_setSize(rectan, (sfVector2f){150, 15});
    sfRenderWindow_drawRectangleShape(all_infos()->window, rectan, NULL);

    sfRectangleShape_setFillColor(rectan, sfRed);
    sfRectangleShape_setSize(rectan, (sfVector2f){all_infos()->life * 15, 15});
    sfRenderWindow_drawRectangleShape(all_infos()->window, rectan, NULL);


    sfRectangleShape_destroy(rectan);

    sfSprite_setPosition(all_sprites()[LIFE].sprite, (sfVector2f){(1920 * 0.5) * 0.05, (1080 * 0.5) * 0.1});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[LIFE].sprite, NULL);
}

void level_1(sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);


    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    // HUD
    disp_hud();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    // my_printf("top : %d\tleft : %d\n", all_sprites()[HUNTER].rect.top, all_sprites()[HUNTER].rect.left);

    // if (all_sprites()[BANANA].anim)
    //     sfRenderWindow_drawSprite(all_infos()->window,
    //     all_sprites()[BANANA].sprite, NULL);
    return;
}
