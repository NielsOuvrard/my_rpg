/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** life_manager
*/

#include "my.h"
#include "rpg_header.h"

void increase_life(void)
{
    all_infos()->life_size += 15;
}