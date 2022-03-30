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
    if (all_sprites()[HUNTER].rect.top > 16) {
        all_sprites()[HUNTER].anim = 'f';
        all_sprites()[HUNTER].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
        return;
    }
    all_sprites()[HUNTER].rect.left = 0;
    all_sprites()[HUNTER].anim = 'a';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
    return;
}

void modify_var_move(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        char a = all_infos()->move;
        if (event.key.code == sfKeyUp)
            all_infos()->move = 'u';
        if (event.key.code == sfKeyLeft)
            all_infos()->move = 'l';
        if (event.key.code == sfKeyDown)
            all_infos()->move = 'd';
        if (event.key.code == sfKeyRight)
            all_infos()->move = 'r';
        if (a != all_infos()->move) {
            all_sprites()[HUNTER].anim = 'A';
            all_sprites()[HUNTER].rect.left = 0;
            change_look_ghost();
            anim_hunter();
            sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
        }
    }
    if (event.type == sfEvtKeyReleased && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight) && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown)) {
        idle_perso();
        all_infos()->move = '\0';
    }
}

void change_scale(sfEvent event)
{
    if (event.key.code == sfKeyA) {
        sfView_zoom(all_infos()->view, 0.8);
    }
    if (event.key.code == sfKeyE) {
        sfView_zoom(all_infos()->view, 1.2);
    }
}

void event_level_1(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape)
                all_infos()->level = 0;
            // if (event.key.code == sfKeySpace)
            //     all_infos()->shoot = 1;
            change_scale(event);
        }
        modify_var_move(event);
    }
    return;
}

void level_1(sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_infos()->map);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[HUNTER].sprite, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[NINJA].sprite, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[DEMON].sprite, NULL);
    return;
}
