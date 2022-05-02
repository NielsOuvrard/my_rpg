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
    bool horizontal = projectile.left >= target.left && projectile.left <= target.left + target.width;
    bool vertical = projectile.top >= target.top && projectile.top <= target.top + target.height;
    return horizontal && vertical;
}

void check_enemies_collision(projectile_t *projectile)
{
    enemies *enemies = all_maps()[all_infos()->map_actual].all_ennemis;
    while (enemies != NULL) {
        sfFloatRect rect_projectile = sfSprite_getGlobalBounds(projectile->sprite_picture.sprite);
        // this rect isn't accurate with some enemies for some
        sfFloatRect rect_enemy = sfSprite_getGlobalBounds(all_sprites()[enemies->value].sprite);
        rect_enemy.top += 2;
        rect_enemy.height = 40 + projectile->velocity.y;
        rect_enemy.width = 16 + projectile->velocity.x;
        if (intersects(rect_projectile, rect_enemy)/* || sfFloatRect_intersects(&rect_projectile, &rect_enemy, NULL)*/) {
            enemies->health_points -= projectile->damage;
            projectile->should_render = false;
        }
        enemies = enemies->next;    
    }
}