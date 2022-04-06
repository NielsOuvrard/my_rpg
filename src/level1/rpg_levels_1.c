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
    if (all_sprites()[HUNTER].rect.top > 16 && all_sprites()[HUNTER].rect.top < 64) {
        all_sprites()[HUNTER].anim = 'f';
        all_sprites()[HUNTER].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
        return;
    }
    if (all_infos()->move != 'c')
        all_sprites()[HUNTER].rect.left = 0;
    all_sprites()[HUNTER].anim = 'a';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
    return;
}

void move_to_salle_une (void)
{
    all_sprites()[HUNTER].pos.y = 50 * 9.95;
    all_sprites()[HUNTER].pos.x = (50 * 5) + 25;
    sfSprite_setPosition(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].pos);
    all_infos()->map_actual = 0;
    sfView_setCenter(all_infos()->view, (sfVector2f) {(50 * 5) + 25, 50 * 9.95});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void move_to_exterieure_une (void)
{
    all_sprites()[HUNTER].pos.y = 50 * 4;
    all_sprites()[HUNTER].pos.x = (50 * 10) + 25;
    sfSprite_setPosition(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].pos);
    all_infos()->map_actual = 1;
    sfView_setCenter(all_infos()->view, (sfVector2f) {(50 * 10) + 25, 50 * 4});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void change_map (sfEvent event)
{
    if (event.key.code == sfKeyX) {
        move_to_salle_une();
    }
    if (event.key.code == sfKeyW) {
        move_to_exterieure_une();
    }
}

void modify_var_move(sfEvent event)
{
    if (event.type == sfEvtKeyPressed && all_infos()->move != 'c') {
        char a = all_infos()->move;
        if (event.key.code == sfKeyB)
            all_sprites()[BANANA].anim = 'a';
        change_map(event);
        if (event.key.code == sfKeyUp)
            all_infos()->move = 'u';
        if (event.key.code == sfKeyLeft)
            all_infos()->move = 'l';
        if (event.key.code == sfKeyDown)
            all_infos()->move = 'd';
        if (event.key.code == sfKeyRight)
            all_infos()->move = 'r';
        if (event.key.code == sfKeyC)
            all_infos()->move = 'c';
        if (a != all_infos()->move) {
            all_sprites()[HUNTER].anim = 'A';
            if (all_infos()->move != 'c')
                all_sprites()[HUNTER].rect.left = 0;
            change_look_ghost();
            anim_perso_according_to_int(HUNTER);
            sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
        }
    }
    if (event.type == sfEvtKeyReleased && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight) && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown) && all_infos()->move != 'c') {
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
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
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
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape)
                all_infos()->level = 0;
            if (event.key.code == sfKeyC) {
                if (all_sprites()[HUNTER].rect.left != 0)
                    all_sprites()[HUNTER].rect.left = 64;
                if (all_infos()->last_move == 'l' || all_infos()->last_move == 'd')
                    all_sprites()[HUNTER].rect.top = 64;
                else if (all_infos()->last_move == 'r' || all_infos()->last_move == 'u')
                    all_sprites()[HUNTER].rect.top = 80;
            }
            change_scale(event);
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyC) {
            all_sprites()[HUNTER].rect.left = 64;
            all_infos()->move = all_infos()->last_move;
            if (all_infos()->move == 'l' || all_infos()->move == 'd')
                all_sprites()[HUNTER].rect.top = 32;
            else if (all_infos()->move == 'r' || all_infos()->move == 'u')
                all_sprites()[HUNTER].rect.top = 48;
            sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
        }
        modify_var_move(event);
    }
    return;
}

void level_1(sfEvent event)
{
    enemies *list = NULL;
    create_enemy(&list);
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    disp_map(all_maps()[all_infos()->map_actual].mg);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[HUNTER].sprite, NULL);
    print_enemies(&list);
    //sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[NINJA].sprite, NULL);
   // sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[DEMON].sprite, NULL);
    disp_map(all_maps()[all_infos()->map_actual].fg);
    if (all_sprites()[BANANA].anim)
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[BANANA].sprite, NULL);
    return;
}
