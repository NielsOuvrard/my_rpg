/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"


void anim_enemis_left_right (enemies *enemy)
{
    if (enemy->anim >= 'a' && enemy->anim <= 'c') {
        if (enemy->anim >= 'c') {
            enemy->rect.left = 0;
            enemy->anim = 'A';
            return;
        }
        enemy->anim++;
        enemy->rect.left += 16;
        return;
    }
    if (enemy->anim == 'A') {
        enemy->anim++;
        enemy->rect.left = 3 * 16;
        return;
    }
    if (enemy->anim == 'B') {
        enemy->anim++;
        enemy->rect.left += 16;
        return;
    }
    if (enemy->anim == 'C') {
        enemy->anim = 'a';
        enemy->rect.left = 0;
        return;
    }
}

void anim_enemis_up_and_down (enemies *enemy)
{
    if (enemy->anim >= 'a' && enemy->anim <= 'c') {
        if (enemy->anim == 'b') {
            enemy->anim = 'A';
            enemy->rect.left = 0;
            return;
        }
        enemy->anim = 'b';
        enemy->rect.left += 16;
        return;
    }
    if (enemy->anim >= 'A' && enemy->anim <= 'C') {
        if (enemy->anim == 'C') {
            enemy->anim = 'a';
            enemy->rect.left = 0;
            return;
        }
        enemy->anim = 'C';
        enemy->rect.left += 16 * 2;
        return;
    }
}

void anim_ennemi (enemies *enemy)
{
    if (enemy->rect.top > 16) {
        anim_enemis_left_right(enemy);
        return;
    }
    anim_enemis_up_and_down(enemy);
}

void anim_all_enemies (void)
{
    enemies *expl = all_maps()[all_infos()->map_actual].all_ennemis;
    while (expl) {
        anim_ennemi(expl);
        expl = expl->next;
    }
}
