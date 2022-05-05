/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** velocity_helper
*/

#include "my.h"
#include "rpg_header.h"

vec2d_t create_vector(float x, float y)
{
    vec2d_t vector = {x, y};
    return vector;
}

float get_angle_in_degrees(projectile_t *projectile)
{
    return atan2(projectile->velocity.y, projectile->velocity.x) * 180.0 / PI;
}

float distance_to(sfVector2f origin, sfVector2f other)
{
    float x = origin.x - other.x;
    float y = origin.y - other.y;
    return sqrt(x * x + y * y);
}