/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** move_ennemies
*/

#include "my.h"
#include "rpg_header.h"

void move_all_ennemys (void)
{
    enemies *expl = all_maps()[all_infos()->map_actual].all_ennemis;
    while (expl) {
        sfTime time_anim = sfClock_getElapsedTime(expl->clock);
        if (time_anim.microseconds > 1000) {
            get_move_val(expl);
            sfClock_restart(expl->clock);
        }
        expl = expl->next;
    }
}

void get_move_val(enemies *enemy)
{
    int val = random_int(0, 1);
    int val2 = random_int(0, 1);
    int add = 1;
    if (val2 == 1)
        add = -1;
    //printf("y : %f, x : %f\n", enemy->pos.y / SIZE_TILE, (enemy->pos.x / SIZE_TILE) - 16);
    enemy->x = (enemy->pos.x / SIZE_TILE);
    enemy->y = (enemy->pos.y / SIZE_TILE);
    get_new_vals(enemy);
   // my_putchar(all_maps()[all_infos()->map_actual].bg[enemy->y][enemy->x]);
}

int can_be_moved(int x, int y, enemies *enemy)
{
    if (x >= (enemy->og_x + enemy->radius) || y >= enemy->og_y + enemy->radius)
        return 0;
    if (y <= 0 || x <= 0)
        return 0;
    if (all_maps()[all_infos()->map_actual].bg[y][x] != '7')
        return 0;
    if (all_maps()[all_infos()->map_actual].mg[y][x] != 'R')
        return 0;
    return 1;
}

void get_new_vals(enemies *enemy)
{
    printf("%d", enemy->og_x);
    if (enemy->move_type == 1) {
        if (can_be_moved(enemy->x + 1, enemy->y, enemy)) {
            enemy->pos.x += 1;
            enemy->x += 1;
        } else
            enemy->move_type = random_int(1, 3);
    }
    if (enemy->move_type == 2) {
        if (can_be_moved(enemy->x - 1, enemy->y, enemy)) {
            enemy->pos.x -= 1;
            enemy->x -= 1;
        } else
        enemy->move_type = random_int(1, 3);
    }
    if (enemy->move_type == 3) {
        if (can_be_moved(enemy->x, enemy->y + 1, enemy)) {
            enemy->pos.y += 1;
            enemy->y += 1;
        } else
        enemy->move_type = random_int(1, 3);
    }
    if (enemy->move_type == 4) {
        if (can_be_moved(enemy->x, enemy->y - 1, enemy)) {
            enemy->pos.y -= 1;
            enemy->y -= 1;
        }else
        enemy->move_type = random_int(1, 3);
    }
    return;
}
