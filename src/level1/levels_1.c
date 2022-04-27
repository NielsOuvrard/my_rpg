/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void display_hud(void)
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
    sfSprite_setPosition(all_sprites()[LIFE].sprite, (sfVector2f){(1920 * 0.5)
    * 0.05, (1080 * 0.5) * 0.1});
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[LIFE].sprite, NULL);
    display_stamina();
}

void display_stamina(void)
{
    sfVector2f pos2 = {(1920 * 0.5) * 0.05, (1080 * 0.5) * 0.20};
    sfRectangleShape *stamina = sfRectangleShape_create();
    sfRectangleShape_setPosition(stamina, pos2);
    sfRectangleShape_setFillColor(stamina, sfBlack);
    sfRectangleShape_setSize(stamina, (sfVector2f){150, 15});
    sfRenderWindow_drawRectangleShape(all_infos()->window, stamina, NULL);
    sfRectangleShape_setFillColor(stamina, sfGreen);
    sfRectangleShape_setSize(stamina, (sfVector2f){all_infos()->stamina * 15, 15});
    sfRenderWindow_drawRectangleShape(all_infos()->window, stamina, NULL);
    sfRectangleShape_destroy(stamina);
}

void level_1(sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}
