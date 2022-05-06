/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** projectile_collision
*/

#include "my.h"
#include "rpg_header.h"

bool intersects(sfFloatRect projectile, sfFloatRect target)
{
    bool horizontal = projectile.left >= target.left
    && projectile.left <= target.left + target.width;
    bool vertical = projectile.top >= target.top &&
    projectile.top <= target.top + target.height;
    return horizontal && vertical;
}

void on_enemy_collision(projectile_t *projectile, enemies *enemy)
{
    enemy->health_points -= projectile->damage;
    projectile->should_render = false;
}

void check_hunter_collision(projectile_t *projectile)
{
    if (projectile->from_hunter || !projectile->should_render) {
        return;
    }
    sfSprite_setPosition(projectile->sprite_picture.sprite,
    projectile->sprite_picture.pos);
    sfFloatRect rect_projectile =
    sfSprite_getGlobalBounds(projectile->sprite_picture.sprite);
    sfFloatRect rect_hunter =
    sfSprite_getGlobalBounds(all_sprites()[HUNTER].sprite);
    if (intersects(rect_projectile, rect_hunter)) {
        all_infos()->life -= projectile->damage;
        projectile->should_render = false;
    }
}

void check_enemies_collision(projectile_t *projectile)
{
    if (!projectile->should_render)
        return;
    enemies *enemies = all_maps()[all_infos()->map_actual].all_ennemis;
    sfSprite_setPosition(projectile->sprite_picture.sprite,
    projectile->sprite_picture.pos);
    while (projectile->from_hunter && enemies != NULL) {
        sfSprite_setPosition(all_sprites()[enemies->value].sprite,
        enemies->pos);
        sfFloatRect rect_projectile
        = sfSprite_getGlobalBounds(projectile->sprite_picture.sprite);
        sfFloatRect rect_enemy = sfSprite_getGlobalBounds
        (all_sprites()[enemies->value].sprite);
        rect_enemy.top += 2;
        rect_enemy.height = 40 + projectile->velocity.y;
        rect_enemy.width = 16 + projectile->velocity.x;
        if (intersects(rect_projectile, rect_enemy)) {
            on_enemy_collision(projectile, enemies);
        }
        enemies = enemies->next;
    }
}
