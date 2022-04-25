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
    if (event.key.code == all_keyes()->zoom_out)
        sfView_zoom(all_infos()->view, 0.8);
    if (event.key.code == all_keyes()->zoom_in)
        sfView_zoom(all_infos()->view, 1.2);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

// E = inventaire
// A = interaction
void event_level_1_pressed_next(sfEvent event)
{
    if (event.key.code == all_keyes()->k_up)
        all_infos()->move_u = true;
    if (event.key.code == all_keyes()->k_left)
        all_infos()->move_l = true;
    if (event.key.code == all_keyes()->k_down)
        all_infos()->move_d = true;
    if (event.key.code == all_keyes()->k_right)
        all_infos()->move_r = true;
    if (event.key.code == all_keyes()->k_open_bag)
        all_infos()->level = INVENTORY;
    if (event.key.code == sfKeyP)
        all_infos()->life--;
    if (event.key.code == sfKeyM && all_infos()->life + 1 <= 10)
        all_infos()->life++;
}

void event_npc(sfEvent event)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    while (expl) {
        if (event.key.code == sfKeyF && expl->interaction == 1)
            all_infos()->level = DIALOGUE;
        expl = expl->next;
    }
}

void event_level_1_pressed(sfEvent event)
{
    if (event.key.code == all_keyes()->shoot) {
        all_infos()->last_move = all_infos()->move;
        all_infos()->move = 'c';
        if (all_sprites()[HUNTER].rect.top == 16 ||
        all_sprites()[HUNTER].rect.top == 2 * 16)
            all_sprites()[HUNTER].rect.top = 64;
        else
            all_sprites()[HUNTER].rect.top = 80;
        all_sprites()[HUNTER].rect.left = 16 * 3;
    }
    event_level_1_pressed_next(event);
    change_scale(event);
    event_npc(event);
}

// shoot an arrow after all_infos()->move == 'c' &&
// !sfKeyboard_isKeyPressed(all_keyes()->shoot) JF
void event_level_1_relased_next (sfEvent event)
{
    if (!sfKeyboard_isKeyPressed(all_keyes()->k_left))
        all_infos()->move_l = false;
    if (!sfKeyboard_isKeyPressed(all_keyes()->k_right))
        all_infos()->move_r = false;
    if (!sfKeyboard_isKeyPressed(all_keyes()->k_up))
        all_infos()->move_u = false;
    if (!sfKeyboard_isKeyPressed(all_keyes()->k_down))
        all_infos()->move_d = false;
    if (!all_infos()->move_u && !all_infos()->move_d &&
    !all_infos()->move_l && !all_infos()->move_r)
        all_infos()->move = '\0';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
}

void event_level_1_relased(sfEvent event)
{
    if (all_infos()->move == 'c' &&
    !sfKeyboard_isKeyPressed(all_keyes()->shoot)) {
        all_sprites()[HUNTER].rect.left = 0;
        all_infos()->move = all_infos()->last_move;
        if (all_infos()->move == 'l' || all_infos()->move == 'd')
            all_sprites()[HUNTER].rect.top = 32;
        else if (all_infos()->move == 'r' || all_infos()->move == 'u')
            all_sprites()[HUNTER].rect.top = 48;
        else
            all_sprites()[HUNTER].rect.top = 16;
    }
    event_level_1_relased_next(event);
}

void event_level_1(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_level_1_pressed(event);
        if (event.type == sfEvtKeyReleased)
            event_level_1_relased(event);
    }
    return;
}
