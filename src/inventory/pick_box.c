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

void change_val_box(int val)
{
    if (val == 1 && all_infos()->inventory_move + 1 < nmb_inv()) {
        all_infos()->inventory_move += 1;
        return;
    }
    if (val == 2 && all_infos()->inventory_move - 1 >= 0) {
        all_infos()->inventory_move -= 1;
        return;
    }
}

void print_infos(int run, struct_inventory *obj, int x, int y)
{
    if (run != all_infos()->inventory_move)
        return;
    all_sprites()[obj->object].scale.x = 5.125;
    all_sprites()[obj->object].scale.y = 5.125;
    sfSprite_setScale(all_sprites()[obj->object].sprite,
    all_sprites()[obj->object].scale);
    sfSprite_setPosition(all_sprites()[INFO].sprite,
    (sfVector2f) {(x * SIZE_TILE) + 50, (y * SIZE_TILE) + 310});
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[INFO].sprite, NULL);
    sfSprite_setPosition(all_sprites()[obj->object].sprite,
    (sfVector2f) {(x * SIZE_TILE) + 115, (y * SIZE_TILE) + 450});
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[obj->object].sprite, NULL);
}