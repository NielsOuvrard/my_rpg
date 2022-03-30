/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void anim_hunter_left_right (void)
{
    // my_printf("anim : %c\n", all_sprites()[HUNTER].anim);
    if (all_sprites()[HUNTER].anim >= 'a' && all_sprites()[HUNTER].anim <= 'f') {
        if (all_sprites()[HUNTER].anim >= 'f') {
            all_sprites()[HUNTER].rect.left = 4 * 16;
            all_sprites()[HUNTER].anim = 'E';
            return;
        }
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left += 16;
        return;
    }
    if (all_sprites()[HUNTER].anim <= 'A') {
        all_sprites()[HUNTER].anim = 'b';
        all_sprites()[HUNTER].rect.left = 16;
        return;
    }
    all_sprites()[HUNTER].rect.left -= 16;
    all_sprites()[HUNTER].anim--;
}

void anim_hunter (void)
{
    if (all_sprites()[HUNTER].rect.top > 3 * 16) {
        my_printf("Shoot");
        return;
    }
    if (all_sprites()[HUNTER].rect.top > 16) {
        anim_hunter_left_right();
        return;
    }
    if (all_sprites()[HUNTER].anim >= 'a' && all_sprites()[HUNTER].anim <= 'c') {
        if (all_sprites()[HUNTER].anim == 'b') {
            all_sprites()[HUNTER].anim = 'A';
            all_sprites()[HUNTER].rect.left = 0;
            return;
        }
        all_sprites()[HUNTER].anim = 'b';
        all_sprites()[HUNTER].rect.left += 16;
        return;
    }
    if (all_sprites()[HUNTER].anim >= 'A' && all_sprites()[HUNTER].anim <= 'C') {
        if (all_sprites()[HUNTER].anim == 'C') {
            all_sprites()[HUNTER].anim = 'a';
            all_sprites()[HUNTER].rect.left = 0;
            return;
        }
        all_sprites()[HUNTER].anim = 'C';
        all_sprites()[HUNTER].rect.left += 16 * 2;
        return;
    }
    all_sprites()[HUNTER].anim = 'a';
}

void anim_perso(void)
{
    if (all_sprites()[SPRITE_SHEET].anim)
        all_sprites()[SPRITE_SHEET].anim = '\0';
    else
        all_sprites()[SPRITE_SHEET].anim = 'a';
    if (!all_infos()->move)
        return;
    anim_hunter();
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
}

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

void change_look_ghost(void)
{
    // ? all_infos()->pos_player = sfSprite_getPosition(all_sprites()[HUNTER].sprite);
    all_infos()->pos_player = all_sprites()[HUNTER].pos;
    if (all_infos()->move == 'u') {
        all_sprites()[HUNTER].rect.top = 0;
        all_sprites()[HUNTER].pos.y -= 10;
        sfView_move(all_infos()->view, (sfVector2f) {0, -10});
    }
    if (all_infos()->move == 'l') {
        all_sprites()[HUNTER].rect.top = 2 * 16;
        all_sprites()[HUNTER].pos.x -= 10;
        sfView_move(all_infos()->view, (sfVector2f) {-10, 0});
    }
    if (all_infos()->move == 'd') {
        all_sprites()[HUNTER].rect.top = 16;
        all_sprites()[HUNTER].pos.y += 10;
        sfView_move(all_infos()->view, (sfVector2f) {0, 10});
    }
    if (all_infos()->move == 'r') {
        all_sprites()[HUNTER].rect.top = 3 * 16;
        all_sprites()[HUNTER].pos.x += 10;
        sfView_move(all_infos()->view, (sfVector2f) {10, 0});
    }
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    sfSprite_setPosition(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].pos);
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
void level_1_clock(sfEvent event)
{
    if (!(all_infos()->clock_val % 10))
        anim_perso();
    if (all_infos()->move && !(all_infos()->clock_val % 2)) {
        move_pos_player();
        change_look_ghost();
    }
}

void level_1(sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_infos()->map);
    // sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GHOST].sprite, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[HUNTER].sprite, NULL);
    return;
}
