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

void anim_hunter_up_and_down (void)
{
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
    anim_hunter_up_and_down();
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
    // - 25 pour origin du perso
    if (all_sprites()[HUNTER].pos.x >= (50 * 10) - 25 && all_sprites()[HUNTER].pos.x <= 50 * 11 &&
    all_sprites()[HUNTER].pos.y >= 50 * 2 && all_sprites()[HUNTER].pos.y <= 50 * 3 && all_infos()->map_actual == 1)
        move_to_salle_une();
    if (all_sprites()[HUNTER].pos.x >= (50 * 5) - 25 && all_sprites()[HUNTER].pos.x <= 50 * 6 &&
    all_sprites()[HUNTER].pos.y >= 50 * 9 && all_sprites()[HUNTER].pos.y <= 50 * 10 && all_infos()->map_actual == 0)
        move_to_exterieure_une();
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

void level_1_clock(sfEvent event)
{
    if (!(all_infos()->clock_val % 10))
        anim_perso();
    if (all_infos()->move && !(all_infos()->clock_val % 2)) {
        move_pos_player();
        change_look_ghost();
    }
}