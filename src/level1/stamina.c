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
    if (all_infos()->stamina < 0 || !all_infos()->sprint)
        return;
    if (all_infos()->move_r || all_infos()->move_d
    || all_infos()->move_l || all_infos()->move_u) {
        all_infos()->stamina -= 0.2;
    }
}

void increase_stamina(void)
{
    sfTime time = sfClock_getElapsedTime(all_infos()->stamina_clock);
    if (sfTime_asMilliseconds(time) > 1000) {
        if (all_infos()->stamina < 10)
            all_infos()->stamina += 0.2;
        sfClock_restart(all_infos()->stamina_clock);
    }
    return;
}