/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** projectile_physics
*/

#include "my.h"
#include "rpg_header.h"

void apply_air_friction(projectile_t *projectile)
{
    projectile->velocity.x *= 0.96;
    projectile->velocity.x += projectile->velocity.x > 0 ? -0.01 : 0.01;
    projectile->velocity.y *= 0.96;
    projectile->velocity.y += projectile->velocity.y > 0 ? -0.01 : 0.01;
}

// this basically prevent projectile slowly decreasing forever to super small values
void clamp_velocity(projectile_t *projectile)
{
    if (projectile->velocity.x <= 0.25) {
        projectile->velocity.x = 0;
    }
    if (projectile->velocity.y <= 0.25) {
        projectile->velocity.y = 0;
    }
    if (projectile->velocity.y == 0 && projectile->velocity.x == 0) {
        projectile->should_render = false;
    }
}

// TODO: collision with walls?
void move_projectile(projectile_t *projectile)
{
    projectile->sprite_picture.pos.x += projectile->velocity.x;
    projectile->sprite_picture.pos.y += projectile->velocity.y;

    enemies *enemies = all_maps()[all_infos()->map_actual].all_ennemis;
    while (enemies != NULL) {
        sfFloatRect rect_projectile = sfSprite_getGlobalBounds(projectile->sprite_picture.sprite);
        sfFloatRect rect_enemy = sfSprite_getGlobalBounds(all_sprites()[enemies->value].sprite);
        rect_enemy.top += 2;
        rect_enemy.height = 40;
        rect_enemy.width = 16;
        if (sfFloatRect_intersects(&rect_projectile, &rect_enemy, NULL)) {
            enemies->health_points -= projectile->damage;
        }
        enemies = enemies->next;    
    }

    /*if (collide_with_wall) {
        projectile->velocity.x = 0;
        projectile->velocity.y = 0;
    }*/
}

void projectile_game_tick(void)
{
    for (int y = 0; get_projectile_dictionary()[y] != NULL; y++) {
        projectile_t *projectile = get_projectile_dictionary()[y];
        update_projectile_rotation(projectile);
        move_projectile(projectile);
        clamp_velocity(projectile);
        apply_air_friction(projectile);
    }
}
