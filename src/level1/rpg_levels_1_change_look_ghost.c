/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

int player_is_on_case(int x, int y)
{
    if (all_sprites()[HUNTER].pos.x >= (50 * x) &&
    all_sprites()[HUNTER].pos.x <= 50 * (x + 1) &&
    all_sprites()[HUNTER].pos.y >= 50 * y &&
    all_sprites()[HUNTER].pos.y <= 50 * (y + 1))
        return 1;
    return 0;
}

void change_look_ghost_next(void)
{
    all_infos()->pos_player = all_sprites()[HUNTER].pos;
    if (all_infos()->move == 'e') {
        all_sprites()[HUNTER].rect.top = 0;
        all_sprites()[HUNTER].pos.y -= 10;
        sfView_move(all_infos()->view, (sfVector2f) {0, -10});
    }
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
}

void change_look_ghost(void)
{
    change_look_ghost_next();
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
    if (player_is_on_case(10, 3) && all_infos()->map_actual == 1)
        move_to_salle_une();
    if (player_is_on_case(5, 10) && all_infos()->map_actual == 0)
        move_to_exterieure_une();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    sfSprite_setPosition(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].pos);
}
