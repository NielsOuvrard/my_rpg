/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** empty_inventory
*/

#include "my.h"
#include "rpg_header.h"

void print_emptyinv(void)
{
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[BALLON].sprite, NULL);
    print_quest(EMPTY_INVENTORY);
}
