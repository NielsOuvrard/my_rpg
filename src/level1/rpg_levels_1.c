/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void change_scale(sfEvent event)
{
    if (event.key.code == sfKeyA) {
        sfView_zoom(all_infos()->view, 0.8);
    }
    if (event.key.code == sfKeyE) {
        sfView_zoom(all_infos()->view, 1.2);
    }
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void event_level_1_pressed(sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        all_infos()->level = 0;
    if (event.key.code == sfKeyC) {
        if (all_sprites()[HUNTER].rect.left != 0)
            all_sprites()[HUNTER].rect.left = 64;
        if (all_infos()->last_move == 'l' || all_infos()->last_move == 'd')
            all_sprites()[HUNTER].rect.top = 64;
        else if (all_infos()->last_move == 'r' ||
        all_infos()->last_move == 'u')
            all_sprites()[HUNTER].rect.top = 80;
    }
    if (event.key.code == sfKeyY)
        move_to_map(--all_infos()->map_actual, 5, 5);
    if (event.key.code == sfKeyT)
        move_to_map(++all_infos()->map_actual, 5, 5);
    change_scale(event);
}

void event_level_1_relased(sfEvent event)
{
    all_sprites()[HUNTER].rect.left = 64;
    all_infos()->move = all_infos()->last_move;
    if (all_infos()->move == 'l' || all_infos()->move == 'd')
        all_sprites()[HUNTER].rect.top = 32;
    else if (all_infos()->move == 'r' || all_infos()->move == 'u')
        all_sprites()[HUNTER].rect.top = 48;
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
}

void event_level_1(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (all_infos()->move != 'c' && all_infos()->move != '\0')
            all_infos()->last_move = all_infos()->move;
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_level_1_pressed(event);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyC)
            event_level_1_relased(event);
        modify_var_move(event);
    }
    return;
}

void level_1(sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    if (all_sprites()[BANANA].anim)
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[BANANA].sprite, NULL);
    return;
}
