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
    } else {
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
    if (all_infos()->move == 'u') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 4 * 16;
        else
            all_sprites()[GHOST].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
    }
    if (all_infos()->move == 'l') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 2 * 16;
        else
            all_sprites()[GHOST].rect.left = 3 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
    }
    if (all_infos()->move == 'd') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 6 * 16;
        else
            all_sprites()[GHOST].rect.left = 7 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
    }
    if (all_infos()->move == 'r') {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 0;
        else
            all_sprites()[GHOST].rect.left = 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
    }
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
        all_infos()->zoom += 0.01;
        all_sprites()[GRASS].scale.x += 0.01;
        all_sprites()[GRASS].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[GRASS].sprite, all_sprites()[GRASS].scale);
        all_sprites()[4].scale.x += 0.01;
        all_sprites()[4].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[4].sprite, all_sprites()[4].scale);
        all_sprites()[6].scale.x += 0.01;
        all_sprites()[6].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[6].sprite, all_sprites()[6].scale);
        all_sprites()[7].scale.x += 0.01;
        all_sprites()[7].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[7].sprite, all_sprites()[7].scale);
    }
    if (event.key.code == sfKeyE) {
        all_infos()->zoom -= 0.01;
        all_sprites()[GRASS].scale.x -= 0.01;
        all_sprites()[GRASS].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[GRASS].sprite, all_sprites()[GRASS].scale);
        all_sprites()[4].scale.x -= 0.01;
        all_sprites()[4].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[4].sprite, all_sprites()[4].scale);
        all_sprites()[6].scale.x -= 0.01;
        all_sprites()[6].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[6].sprite, all_sprites()[6].scale);
        all_sprites()[7].scale.x -= 0.01;
        all_sprites()[7].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[7].sprite, all_sprites()[7].scale);
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

    disp_map();
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GHOST].sprite, NULL);
    // sfRenderWindow_drawSprite(all_infos()->window, all_infos()->sprite_difficulty, NULL);
    return;
}
