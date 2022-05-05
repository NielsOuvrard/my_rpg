/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** move_ennemies
*/

#include "my.h"
#include "rpg_header.h"

void move_all_ennemies(void)
{
    enemies *enemies = all_maps()[all_infos()->map_actual].all_ennemis;
    while (enemies) {
        sfTime time_anim = sfClock_getElapsedTime(enemies->clock);
        if (time_anim.microseconds > 1000) {
            enemy_shoot_hunter(enemies);
            get_move_val(enemies);
            sfClock_restart(enemies->clock);
        }
        enemies = enemies->next;
    }
}

void get_move_val(enemies *enemy)
{
    enemy->x = (enemy->pos.x / SIZE_TILE);
    enemy->y = (enemy->pos.y / SIZE_TILE);
    get_new_vals(enemy);
}

int can_be_moved(int x, int y, enemies *enemy)
{
    if (x >= (enemy->og_x + enemy->radius) || y >= enemy->og_y + enemy->radius)
        return 0;
    if (y <= 0 || x <= 0)
        return 0;
    char tile = all_maps()[all_infos()->map_actual].bg[y][x];
    if (tile != '7' && tile != 'U' && tile != 'G')
        return 0;
    if (all_maps()[all_infos()->map_actual].mg[y][x] != 'R')
        return 0;
    return 1;
}

void get_new_vals_next(enemies *enemy)
{
    if (enemy->move_type == 3) {
        if (can_be_moved(enemy->x, enemy->y + 1, enemy))
            my_printf("", enemy->pos.y += 1, enemy->y += 1,
            enemy->rect.top = 16);
        else
            my_printf("", enemy->move_type = random_int(1, 3),
            enemy->anim = 'a', enemy->rect.left = 0);
    }
    if (enemy->move_type == 4) {
        if (can_be_moved(enemy->x, enemy->y - 1, enemy)) {
            enemy->pos.y -= 1;
            enemy->y -= 1;
            enemy->rect.top = 0;
        } else {
            enemy->move_type = random_int(1, 3);
            enemy->anim = 'a';
            enemy->rect.left = 0;
        }
    }
}

void get_new_vals(enemies *enemy)
{
    if (enemy->move_type == 1) {
        if (can_be_moved(enemy->x + 1, enemy->y, enemy))
            my_printf("", enemy->pos.x += 1, enemy->x += 1,
            enemy->rect.top = 3 * 16);
        else
            my_printf("", enemy->move_type = random_int(1, 3),
            enemy->anim = 'a', enemy->rect.left = 0);
    }
    if (enemy->move_type == 2) {
        if (can_be_moved(enemy->x - 1, enemy->y, enemy))
            my_printf("", enemy->pos.x -= 1, enemy->x -= 1,
            enemy->rect.top = 2 * 16);
        else
            my_printf("", enemy->move_type = random_int(1, 3),
            enemy->anim = 'a', enemy->rect.left = 0);
    }
    get_new_vals_next(enemy);
}
