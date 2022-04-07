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
    if (all_sprites()[HUNTER].rect.top > 16 &&
    all_sprites()[HUNTER].rect.top < 64) {
        all_sprites()[HUNTER].anim = 'f';
        all_sprites()[HUNTER].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
        all_sprites()[HUNTER].rect);
        return;
    }
    if (all_infos()->move != 'c')
        all_sprites()[HUNTER].rect.left = 0;
    all_sprites()[HUNTER].anim = 'a';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
    return;
}

void move_to_salle_une (void)
{
    all_sprites()[HUNTER].pos.y = 50 * 9.95;
    all_sprites()[HUNTER].pos.x = (50 * 5) + 25;
    sfSprite_setPosition(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].pos);
    all_infos()->map_actual = 0;
    sfView_setCenter(all_infos()->view,
    (sfVector2f) {(50 * 5) + 25, 50 * 9.95});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void move_to_exterieure_une (void)
{
    all_sprites()[HUNTER].pos.y = 50 * 4;
    all_sprites()[HUNTER].pos.x = (50 * 10) + 25;
    sfSprite_setPosition(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].pos);
    all_infos()->map_actual = 1;
    sfView_setCenter(all_infos()->view, (sfVector2f) {(50 * 10) + 25, 50 * 4});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void modify_var_move_next(sfEvent event, char a)
{
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
        sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
        all_sprites()[HUNTER].rect);
    }
}

void modify_var_move(sfEvent event)
{
    if (event.type == sfEvtKeyPressed && all_infos()->move != 'c') {
        char a = all_infos()->move;
        if (event.key.code == sfKeyB)
            all_sprites()[BANANA].anim = 'a';
        if (event.key.code == sfKeyUp)
            all_infos()->move = 'u';
        modify_var_move_next(event, a);
    }
    if (event.type == sfEvtKeyReleased && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight) &&
    !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown) && all_infos()->move != 'c') {
        idle_perso();
        all_infos()->move = '\0';
    }
}
