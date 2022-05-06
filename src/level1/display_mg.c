/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void disp_mg_next (int i)
{
    enemies *enemies = all_maps()[all_infos()->map_actual].all_ennemis;
    while (enemies) {
        if (!enemies->printed && enemies->pos.y > (SIZE_TILE * i) + 16) {
            sfSprite_setPosition(all_sprites()[enemies->value].sprite,
            enemies->pos);
            sfSprite_setTextureRect(all_sprites()[enemies->value].sprite,
            enemies->rect);
            sfRenderWindow_drawSprite(all_infos()->window,
            all_sprites()[enemies->value].sprite, NULL);
            enemies->printed = true;
        }
        enemies = enemies->next;
    }
    if (all_sprites()[HUNTER].pos.y > (SIZE_TILE * i) +
    VALEURE_APPROXIMATIVE_POUR_PASSER_DERRIER_UNE_TUILE_EN_MG) {
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[HUNTER].sprite, NULL);
    }
}

void disp_priorit(int i)
{
    for (int j = 0; all_maps()[all_infos()->map_actual].mg[i][j]; j++) {
        char a = all_maps()[all_infos()->map_actual].mg[i][j];
        if (all_maps()[all_infos()->map_actual].is_printed[i][j] == 'N' &&
        ((a >= 'r' && a <= 't') || (a >= 'l' && a <= 'n'))) {
            disp_map_next(all_maps()[all_infos()->map_actual].mg, i, j);
            all_maps()[all_infos()->map_actual].is_printed[i][j] = 'Y';
        }
    }
}

void disp_mg (void)
{
    enemies *expl = all_maps()[all_infos()->map_actual].all_ennemis;
    while (expl) {
        expl->printed = false;
        expl = expl->next;
    }
    for (int i = 0; all_maps()[all_infos()->map_actual].mg[i]; i++)
        for (int j = 0; all_maps()[all_infos()->map_actual].mg[i][j]; j++)
            all_maps()[all_infos()->map_actual].is_printed[i][j] = 'N';
    for (int i = 0; all_maps()[all_infos()->map_actual].mg[i]; i++)
        disp_priorit(i);
    print_all_particules();
    for (int i = 0; all_maps()[all_infos()->map_actual].mg[i]; i++) {
        for (int j = 0; all_maps()[all_infos()->map_actual].mg[i][j]; j++) {
            if (all_maps()[all_infos()->map_actual].is_printed[i][j] == 'N') {
                disp_map_next(all_maps()[all_infos()->map_actual].mg, i, j);
            }
        }
        disp_mg_next(i);
    }
}
