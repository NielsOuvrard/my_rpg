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
    if (event.key.code == all_keys()->zoom_out && all_infos()->nb_of_zoom + 1 != 4) {
        sfView_zoom(all_infos()->view, 0.8);
        all_infos()->nb_of_zoom += 1;
    }
    if (event.key.code == all_keys()->zoom_in && all_infos()->nb_of_zoom - 1 > 0) {
        sfView_zoom(all_infos()->view, 1.2);
        all_infos()->nb_of_zoom -= 1;
    }
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

// E = inventaire
// A = interaction
void event_level_game_pressed_next(sfEvent event)
{
    if (event.key.code == all_keys()->k_sprint)
        all_infos()->sprint = true;;
    if (event.key.code == all_keys()->k_up)
        all_infos()->move_u = true;
    if (event.key.code == all_keys()->k_left)
        all_infos()->move_l = true;
    if (event.key.code == all_keys()->k_down)
        all_infos()->move_d = true;
    if (event.key.code == all_keys()->k_right)
        all_infos()->move_r = true;
    if (event.key.code == all_keys()->k_open_bag)
        all_infos()->level = INVENTORY;
    if (event.key.code == sfKeyP)
        all_infos()->life--;
    if (event.key.code == sfKeyM && all_infos()->life + 1 <= 10)
        all_infos()->life++;
    check_stamina();
}

void event_npc(sfEvent event)
{
    npcs *npcs = all_maps()[all_infos()->map_actual].all_npcs;
    while (npcs) {
        if (event.key.code == sfKeyF && npcs->interaction == 1)
            all_infos()->level = DIALOGUE;
        npcs = npcs->next;
    }
}

void event_level_mission_pressed(sfEvent event)
{
    if (event.key.code == all_keys()->k_open_missions)
        all_infos()->level = MISSIONS;
}

void event_level_game_pressed(sfEvent event)
{
    if (event.key.code == all_keys()->shoot) {
        all_infos()->last_move = all_infos()->move;
        all_infos()->move = 'c';
        if (all_sprites()[HUNTER].rect.top == 16 ||
        all_sprites()[HUNTER].rect.top == 2 * 16)
            all_sprites()[HUNTER].rect.top = 64;
        else
            all_sprites()[HUNTER].rect.top = 80;
        all_sprites()[HUNTER].rect.left = 16 * 3;
    }
    event_level_game_pressed_next(event);
    change_scale(event);
    event_npc(event);
    event_level_mission_pressed(event);
}

// shoot an arrow after all_infos()->move == 'c' &&
// !sfKeyboard_isKeyPressed(all_keyes()->shoot) JF
void event_level_game_relased_next (sfEvent event)
{
    if (!sfKeyboard_isKeyPressed(all_keys()->k_sprint))
        all_infos()->sprint = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_left))
        all_infos()->move_l = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_right))
        all_infos()->move_r = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_up))
        all_infos()->move_u = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_down))
        all_infos()->move_d = false;
    if (!all_infos()->move_u && !all_infos()->move_d &&
    !all_infos()->move_l && !all_infos()->move_r)
        all_infos()->move = '\0';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);

    // shooting arrows example

    // position from where the projectile start
    vec2d_t origin_pos = {all_infos()->pos_player.x, all_infos()->pos_player.y};
    // velocity the projectile is being shot with, matterfor speed and direction
    vec2d_t velocity = {5, 8.5};
    // create the projectile object
    projectile_t *projectile = new_projectile(origin_pos, velocity, 10, ARROW);
    // insert projectile object into projectile_manager, the moment you call this funtion it will
    // start rendering and handling the physics of this projectile object
    shoot_projectile(projectile);
}

void event_level_game_relased(sfEvent event)
{
    if (all_infos()->move == 'c' &&
    !sfKeyboard_isKeyPressed(all_keys()->shoot)) {
        all_sprites()[HUNTER].rect.left = 0;
        all_infos()->move = all_infos()->last_move;
        if (all_infos()->move == 'l' || all_infos()->move == 'd')
            all_sprites()[HUNTER].rect.top = 32;
        else if (all_infos()->move == 'r' || all_infos()->move == 'u')
            all_sprites()[HUNTER].rect.top = 48;
        else
            all_sprites()[HUNTER].rect.top = 16;
    }
    event_level_game_relased_next(event);
}

void event_level_game(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_level_game_pressed(event);
        if (event.type == sfEvtKeyReleased)
            event_level_game_relased(event);
    }
    return;
}