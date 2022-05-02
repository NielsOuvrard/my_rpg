/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** projectile_renderer
*/

#include "my.h"
#include "rpg_header.h"

void update_projectile_rotation(projectile_t *projectile)
{
    sfSprite_setRotation(projectile->sprite_picture.sprite, get_angle_in_degrees(projectile));
}

void update_projectile_render_data(projectile_t *projectile)
{
    sfSprite_setScale(projectile->sprite_picture.sprite, projectile->sprite_picture.scale);
    sfSprite_setTextureRect(projectile->sprite_picture.sprite, projectile->sprite_picture.rect);
    sfSprite_setPosition(projectile->sprite_picture.sprite, projectile->sprite_picture.pos);
}

void projectile_render_tick(void)
{
    for (int y = 0; get_projectile_dictionary()[y] != NULL; y++) {
        projectile_t *projectile = get_projectile_dictionary()[y];
        update_projectile_render_data(projectile);
        sfRenderWindow_drawSprite(all_infos()->window, projectile->sprite_picture.sprite, NULL);
    }
}
