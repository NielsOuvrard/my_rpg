/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** projectile_manager
*/

#include "my.h"
#include "rpg_header.h"

static projectile_t **projectile_dictionary;
static int dictionary_size;
static int MAX_PROJECTILES = 100000;

void new_projectile_manager(void)
{
    projectile_dictionary = malloc(sizeof(projectile_t *) * MAX_PROJECTILES);
}

projectile_t **get_projectile_dictionary()
{
    return projectile_dictionary;
}

// maybe later w'ell have different types of projectile ?
sprite_pictures get_sprite_by_type(int type)
{
    sprite_pictures result;
    switch (type) {
        case ARROW:
            result = all_sprites()[ARROW];
            result.rect.left = 64;
            result.rect.top = 82;
            result.rect.width = 9;
            result.rect.height = 3;
            result.scale.x = 2.25;
            result.scale.y = 2.25;
            break;
        default:
            my_printf("Unknown sprite type!");
            break;
    }
    return result;
}

projectile_t *new_projectile
(vec2d_t origin_pos, vec2d_t velocity, int damage, int type)
{
    projectile_t *projectile = malloc(sizeof(projectile_t));
    projectile->sprite_picture = get_sprite_by_type(type);
    projectile->velocity = velocity;
    projectile->damage = damage;
    projectile->sprite_picture.pos.x = origin_pos.x;
    projectile->sprite_picture.pos.y = origin_pos.y;
    projectile->should_render = true;
    projectile->from_hunter = false;
    projectile->friction = 0.95;
    projectile->tick_existed = 0;
    projectile->max_existed = 10000;
    return projectile;
}

void shoot_projectile(projectile_t *projectile)
{
    if (dictionary_size > MAX_PROJECTILES - 5) {
        my_printf("%s", "Failed to insert projectile, maximum capacity");
        return;
    }
    projectile_dictionary[dictionary_size++] = projectile;
}
