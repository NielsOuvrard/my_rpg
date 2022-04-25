/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** stamina
*/

#include "rpg_header.h"
#include "my.h"

void check_stamina(void)
{
    if (all_infos()->move_r || all_infos()->move_d
    || all_infos()->move_l || all_infos()->move_u) {
        all_infos()->stamina -= 0.2;
    }
}
