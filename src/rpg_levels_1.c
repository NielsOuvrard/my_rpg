/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void anim_perso(void)
{
    if (all_sprites()[GHOST].anim) {
        all_sprites()[GHOST].rect.left -= 16;
        all_sprites()[GHOST].anim = false;
        all_sprites()[SPRITE_SHEET].anim = false;
    } else {
        all_sprites()[SPRITE_SHEET].anim = true;
        all_sprites()[GHOST].rect.left += 16;
        all_sprites()[GHOST].anim = true;
    }
    sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
}

void modify_var_move(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp)
            all_infos()->move = 'u';
        if (event.key.code == sfKeyLeft)
            all_infos()->move = 'l';
        if (event.key.code == sfKeyDown)
            all_infos()->move = 'd';
        if (event.key.code == sfKeyRight)
            all_infos()->move = 'r';
    }
    if (event.type == sfEvtKeyReleased && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight) && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown))
        all_infos()->move = '\0';
}

void change_look_ghost(void)
{
    all_infos()->pos_player = sfSprite_getPosition(all_sprites()[GHOST].sprite);
    if (all_infos()->move == 'u') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 4 * 16;
        else
            all_sprites()[GHOST].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.y -= 10;
        sfView_move(all_infos()->view, (sfVector2f) {0, -10});
    }
    if (all_infos()->move == 'l') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 2 * 16;
        else
            all_sprites()[GHOST].rect.left = 3 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.x -= 10;
        sfView_move(all_infos()->view, (sfVector2f) {-10, 0});
    }
    if (all_infos()->move == 'd') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 6 * 16;
        else
            all_sprites()[GHOST].rect.left = 7 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.y += 10;
        sfView_move(all_infos()->view, (sfVector2f) {0, 10});
    }
    if (all_infos()->move == 'r') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 0;
        else
            all_sprites()[GHOST].rect.left = 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.x += 10;
        sfView_move(all_infos()->view, (sfVector2f) {10, 0});
    }
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    sfSprite_setPosition(all_sprites()[GHOST].sprite, all_infos()->pos_player);
}

void move_pos_player(void)
{
    if (all_infos()->move == 'u')
        all_infos()->pos_player.y += 10;
    if (all_infos()->move == 'l')
        all_infos()->pos_player.x += 10;
    if (all_infos()->move == 'd')
        all_infos()->pos_player.y -= 10;
    if (all_infos()->move == 'r')
        all_infos()->pos_player.x -= 10;
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
            if (event.key.code == sfKeySpace)
                all_infos()->level = 0;
            change_scale(event);
        }
        modify_var_move(event);
    }
    return;
}
void level_1_clock(sfEvent event)
{
    if (!(all_infos()->clock_val % 50))
        anim_perso();
    if (all_infos()->move && !(all_infos()->clock_val % 2)) {
        move_pos_player();
        change_look_ghost();
    }
}

void level_1(sfEvent event)
{
    // sfVector2f center = {1000, 1000};
    // sfVector2f half_size = {400, 300};
    // sfView view1 = {center, half_size};

    // sfRenderWindow_setView(all_infos()->window, view1);
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;

    disp_map(all_infos()->map);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GHOST].sprite, NULL);
    // sfRenderWindow_drawSprite(all_infos()->window, all_infos()->sprite_difficulty, NULL);
    return;
}
