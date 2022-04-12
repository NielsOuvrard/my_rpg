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
    enemies *expl = all_maps()[all_infos()->map_actual].all_ennemis;
    while (expl) {
        if (expl->pos.y > (SIZE_TILE * i) + 16) {
            sfSprite_setPosition(all_sprites()[expl->value].sprite, expl->pos);
            sfRenderWindow_drawSprite(all_infos()->window,
            all_sprites()[expl->value].sprite, NULL);
        }
        expl = expl->next;
    }
    if (all_sprites()[HUNTER].pos.y > (SIZE_TILE * i) +
    VALEURE_APPROXIMATIVE_POUR_PASSER_DERRIER_UNE_TUILE_EN_MG) {
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[HUNTER].sprite, NULL);
    }
}

void disp_mg (void)
{
    for (int i = 0; all_maps()[all_infos()->map_actual].mg[i]; i++) {
        for (int j = 0; all_maps()[all_infos()->map_actual].mg[i][j]; j++)
            disp_map_next(all_maps()[all_infos()->map_actual].mg, i, j);
        disp_mg_next(i);
    }
}
