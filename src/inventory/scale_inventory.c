/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** scale_inventory
*/

#include "rpg_header.h"
#include "my.h"

void scale_inventorybox(void)
{
    all_sprites()[EMPTY_BOX].scale.x = 3.125;
    all_sprites()[EMPTY_BOX].scale.y = 3.125;
    sfSprite_setScale(all_sprites()[EMPTY_BOX].sprite,
    all_sprites()[EMPTY_BOX].scale);
    all_sprites()[SELEC_BOX].scale.x = 3.125;
    all_sprites()[SELEC_BOX].scale.y = 3.125;
    sfSprite_setScale(all_sprites()[SELEC_BOX].sprite,
    all_sprites()[SELEC_BOX].scale);
}
