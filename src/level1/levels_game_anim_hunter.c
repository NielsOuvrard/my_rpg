/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

// on png
// A-B-C-A-D-E
// on code
// a-b-c-A-B-C
// not F
void anim_perso_left_right_next (void)
{
    if (all_sprites()[HUNTER].anim == 'A') {
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left = 3 * 16;
        return;
    }
    if (all_sprites()[HUNTER].anim == 'B') {
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left += 16;
        return;
    }
    all_sprites()[HUNTER].anim = 'a';
    all_sprites()[HUNTER].rect.left = 0;
}

void anim_perso_left_right (void)
{
    char a = all_sprites()[HUNTER].anim;
    if ((a < 'a' && a > 'c') || (a < 'A' && a > 'C'))
        all_sprites()[HUNTER].anim = 'a';
    if (all_sprites()[HUNTER].anim >= 'a' &&
    all_sprites()[HUNTER].anim <= 'c') {
        if (all_sprites()[HUNTER].anim == 'c') {
            all_sprites()[HUNTER].rect.left = 0;
            all_sprites()[HUNTER].anim = 'A';
            return;
        }
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left += 16;
        return;
    }
    anim_perso_left_right_next();
}

// a-b-A-B
void anim_perso_up_and_down_next (void)
{
    if (all_sprites()[HUNTER].anim == 'B') {
        all_sprites()[HUNTER].anim = 'a';
        all_sprites()[HUNTER].rect.left = 0;
        return;
    } else {
        all_sprites()[HUNTER].anim = 'B';
        all_sprites()[HUNTER].rect.left = 16 * 2;
        return;
    }
}

void anim_perso_up_and_down (void)
{
    char a = all_sprites()[HUNTER].anim;
    if ((a < 'a' && a > 'b') || (a < 'A' && a > 'B'))
        all_sprites()[HUNTER].anim = 'a';
    if (all_sprites()[HUNTER].anim >= 'a' &&
    all_sprites()[HUNTER].anim <= 'b') {
        if (all_sprites()[HUNTER].anim == 'a') {
            all_sprites()[HUNTER].anim = 'b';
            all_sprites()[HUNTER].rect.left = 16;
            return;
        } else {
            all_sprites()[HUNTER].anim = 'A';
            all_sprites()[HUNTER].rect.left = 0;
            return;
        }
    }
    anim_perso_up_and_down_next();
}

void anim_perso_according_to_int (void)
{
    if (all_sprites()[HUNTER].rect.top >= 64) {
        if (all_sprites()[HUNTER].rect.left > 0)
            all_sprites()[HUNTER].rect.left -= 16;
        return;
    }
    if (all_sprites()[HUNTER].rect.top > 16) {
        anim_perso_left_right();
        return;
    }
    anim_perso_up_and_down();
    
}
