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
    projectile->velocity.x *= projectile->friction;
    projectile->velocity.y *= projectile->friction;
}

void clamp_velocity(projectile_t *projectile)
{
    if (ABS(projectile->velocity.x) + ABS(projectile->velocity.y) <= 0.25) {
        projectile->velocity.x = 0;
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

    check_hunter_collision(projectile);
    check_enemies_collision(projectile);

    /*if (collide_with_wall) {
        projectile->velocity.x = 0;
        projectile->velocity.y = 0;
    }*/
}

void projectile_game_tick(void)
{
    for (int y = 0; get_projectile_dictionary()[y] != NULL; y++) {
        projectile_t *projectile = get_projectile_dictionary()[y];
        if (++projectile->tick_existed >= projectile->max_existed) {
            projectile->should_render = false;
        }
        move_projectile(projectile);
        clamp_velocity(projectile);
        apply_air_friction(projectile);
    }
}
