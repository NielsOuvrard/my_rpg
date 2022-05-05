/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** bow_shooting
*/

#include "my.h"
#include "rpg_header.h"

void bow_release(void)
{
    if (!sfKeyboard_isKeyPressed(all_keys()->shoot) && all_infos()->loading_bow && all_infos()->charging_ticks > 5) {
        printf("move: %c lastmove: %c\n", all_infos()->move, all_infos()->last_move);
        all_infos()->move = all_infos()->last_move;
        sfVector2f pos = sfSprite_getPosition(all_sprites()[HUNTER].sprite);
        vec2d_t origin_pos = {pos.x, (pos.y - 30)};
        vec2d_t velocity = {all_infos()->move == 'r' ? 15 : -15, 0};
        projectile_t *projectile = new_projectile(origin_pos, velocity, 10, ARROW);
        shoot_projectile(projectile);
    }
    all_infos()->charging_ticks = 0;
    all_infos()->loading_bow = false;
}