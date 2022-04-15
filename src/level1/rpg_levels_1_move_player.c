/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void recalculate_the_sprite_perso (void)
{
    my_printf("recalculate_the_sprite_perso\n");
    all_sprites()[HUNTER].rect.left = 0;
    if (all_infos()->move_u)
        all_sprites()[HUNTER].rect.top = 0;
    if (all_infos()->move_d)
        all_sprites()[HUNTER].rect.top = 16;
    if (all_infos()->move_l)
        all_sprites()[HUNTER].rect.top = 2 * 16;
    if (all_infos()->move_r)
        all_sprites()[HUNTER].rect.top = 3 * 16;
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].rect);
}

void change_pos_and_views (int x, int y)
{
    all_infos()->pos_player.y += y;
    all_infos()->pos_player.x += x;
    all_sprites()[HUNTER].pos.y += y;
    all_sprites()[HUNTER].pos.x += x;
    sfView_move(all_infos()->view, (sfVector2f) {x, y});
}

void move_pos_player(void)
{
    char a = all_infos()->move;
    if (all_infos()->move_d) {
        all_infos()->move = 'd';
        change_pos_and_views(0, 7);
        if (!all_infos()->move_l && !all_infos()->move_r)
            change_pos_and_views(0, 3);
    }
    if (all_infos()->move_u) {
        all_infos()->move = 'u';
        change_pos_and_views(0, -7);
        if (!all_infos()->move_l && !all_infos()->move_r)
            change_pos_and_views(0, -3);
    }
    if (all_infos()->move_r) {
        all_infos()->move = 'r';
        change_pos_and_views(7, 0);
        if (!all_infos()->move_u && !all_infos()->move_d)
            change_pos_and_views(3, 0);
    }
    if (all_infos()->move_l) {
        all_infos()->move = 'l';
        change_pos_and_views(-7, 0);
        if (!all_infos()->move_u && !all_infos()->move_d)
            change_pos_and_views(-3, 0);
    }
    if (a != all_infos()->move)
        recalculate_the_sprite_perso();
    // my_printf("changé en %c\n", all_infos()->move);
    sfSprite_setPosition(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].pos);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    if (all_infos()->move != 'c')
        add_particules(all_sprites()[HUNTER].pos, 10,
        sfColor_fromRGBA(255, 255, 255, 200));
}
