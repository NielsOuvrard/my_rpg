/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void anim_perso_left_right (int sprite)
{
    // my_printf("anim : %c\n", all_sprites()[HUNTER].anim);
    if (all_sprites()[sprite].anim >= 'a' && all_sprites()[sprite].anim <= 'f') {
        if (all_sprites()[sprite].anim >= 'f') {
            all_sprites()[sprite].rect.left = 4 * 16;
            all_sprites()[sprite].anim = 'E';
            return;
        }
        all_sprites()[sprite].anim++;
        all_sprites()[sprite].rect.left += 16;
        return;
    }
    if (all_sprites()[sprite].anim <= 'A') {
        all_sprites()[sprite].anim = 'b';
        all_sprites()[sprite].rect.left = 16;
        return;
    }
    all_sprites()[sprite].rect.left -= 16;
    all_sprites()[sprite].anim--;
}

void anim_perso_up_and_down (int sprite)
{
    if (all_sprites()[sprite].anim >= 'a' && all_sprites()[sprite].anim <= 'c') {
        if (all_sprites()[sprite].anim == 'b') {
            all_sprites()[sprite].anim = 'A';
            all_sprites()[sprite].rect.left = 0;
            return;
        }
        all_sprites()[sprite].anim = 'b';
        all_sprites()[sprite].rect.left += 16;
        return;
    }
    if (all_sprites()[sprite].anim >= 'A' && all_sprites()[sprite].anim <= 'C') {
        if (all_sprites()[sprite].anim == 'C') {
            all_sprites()[sprite].anim = 'a';
            all_sprites()[sprite].rect.left = 0;
            return;
        }
        all_sprites()[sprite].anim = 'C';
        all_sprites()[sprite].rect.left += 16 * 2;
        return;
    }
}

void anim_perso_according_to_int (int sprite)
{
    if (all_sprites()[sprite].rect.top >= 64 && sprite == HUNTER) {
        if (all_sprites()[HUNTER].rect.left > 0)
            all_sprites()[HUNTER].rect.left -= 16;
        return;
    }
    if (all_sprites()[sprite].rect.top > 16) {
        anim_perso_left_right(sprite);
        return;
    }
    anim_perso_up_and_down(sprite);
}
