/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** bow_shooting
*/

#include "my.h"
#include "rpg_header.h"

void enemy_shoot_hunter(enemies *enemy)
{
    sfSprite_setPosition(all_sprites()[enemy->value].sprite, enemy->pos);
    sfVector2f hunte_pos = sfSprite_getPosition(all_sprites()[HUNTER].sprite);
    sfVector2f pos = sfSprite_getPosition(all_sprites()[enemy->value].sprite);
    if (distance_to(hunte_pos, pos) > 300) {
        enemy->clock_ticks = 0;
        return;
    }
    if (++enemy->clock_ticks % 350 != 0) {
        return;
    }
    vec2d_t origin_pos = {pos.x, (pos.y - 30)};
    double angle = atan2(hunte_pos.y - pos.y, hunte_pos.x - pos.x);
    vec2d_t velocity = {cos(angle) * 3, sin(angle) * 3};
    projectile_t *projectile = new_projectile(origin_pos, velocity, 1, ARROW);
    projectile->friction = 1.0;
    projectile->max_existed = 150;
    shoot_projectile(projectile);
}

void bow_release(void)
{
    bool bow_loaded = all_infos()->loading_bow
    && all_infos()->charging_ticks > 5;
    if (!sfKeyboard_isKeyPressed(all_keys()->shoot) && bow_loaded) {
        all_infos()->move = all_infos()->last_move;
        sfVector2f pos = sfSprite_getPosition(all_sprites()[HUNTER].sprite);
        vec2d_t origin_pos = {pos.x, (pos.y - 30)};
        vec2d_t velocity = {all_infos()->move == 'r' ? 15 : -15, 0};
        projectile_t *projectile =
        new_projectile(origin_pos, velocity, 10, ARROW);
        projectile->from_hunter = true;
        shoot_projectile(projectile);
    }
    all_infos()->charging_ticks = 0;
    all_infos()->loading_bow = false;
}
