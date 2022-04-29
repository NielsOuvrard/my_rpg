/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** pick_box
*/

#include "rpg_header.h"
#include "my.h"

void pick_inventorybox(int x, int y, int run)
{
    if (run == all_infos()->inventory_move) {
        sfSprite_setPosition(all_sprites()[SELEC_BOX].sprite,
        (sfVector2f) {(x * SIZE_TILE) + 50, (y * SIZE_TILE) + 250});
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[SELEC_BOX].sprite, NULL);
    } else {
        sfSprite_setPosition(all_sprites()[EMPTY_BOX].sprite,
        (sfVector2f) {(x * SIZE_TILE) + 50, (y * SIZE_TILE) + 250});
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[EMPTY_BOX].sprite, NULL);
    }
    return;
}

int get_nbofelem(void)
{
    
}

void change_val_box(int val)
{
    if (val == 1 && all_keys) {
    }
}