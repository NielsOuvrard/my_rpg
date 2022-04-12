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

void check_all_intecract_map_actual (void)
{
    struct_interact *list = all_maps()[all_infos()->map_actual].interact;
    while (list) {
        if (player_is_on_case(list->x, list->y))
            move_to_map(list->data, list->a_x, list->a_y);
        list = list->next;
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
    check_all_intecract_map_actual();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    sfSprite_setPosition(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].pos);
}
