/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** is_onchest
*/

#include "my.h"
#include "rpg_header.h"

void is_onchest(void)
{
    int final_x = (all_sprites()[HUNTER].pos.x) / (SIZE_TILE);
    int final_y = (all_sprites()[HUNTER].pos.y) / (SIZE_TILE);
    if (!all_maps()[all_infos()->map_actual].mg[final_y])
        return;
    if (all_maps()[all_infos()->map_actual].mg[final_y][final_x] == 'P' || all_infos()->level == CHEST) {
        sfSprite_setScale(all_sprites()[INTERACTION_BT].sprite,
        (sfVector2f) {2, 2});
        sfSprite_setPosition(all_sprites()[INTERACTION_BT].sprite,
        (sfVector2f) {all_sprites()[HUNTER].pos.x - 13,
        all_sprites()[HUNTER].pos.y - 85});
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[INTERACTION_BT].sprite, NULL);
        sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    }
    return;
}

void check_interact_chest(sfEvent event)
{
    int final_x = (all_sprites()[HUNTER].pos.x) / (SIZE_TILE);
    int final_y = (all_sprites()[HUNTER].pos.y) / (SIZE_TILE);
    if (!all_maps()[all_infos()->map_actual].mg[final_y])
        return;
    if (all_maps()[all_infos()->map_actual].mg[final_y][final_x] == 'P'
    && event.key.code == sfKeyF) {
        all_maps()[all_infos()->map_actual].mg[final_y][final_x] = 'Q';
        all_infos()->level = CHEST;
    }
    return;
}
