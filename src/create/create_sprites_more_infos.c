/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

void full_perso(int type, int x, int y)
{
    all_sprites()[type].origin.x = 8;
    all_sprites()[type].origin.y = 16;
    sfSprite_setOrigin(all_sprites()[type].sprite, all_sprites()[type].origin);
    all_sprites()[type].anim = 'a';
    all_sprites()[type].scale.x = 3;
    all_sprites()[type].scale.y = 3;
    sfSprite_setScale(all_sprites()[type].sprite, all_sprites()[type].scale);
    all_sprites()[type].pos.y = y;
    all_sprites()[type].pos.x = x;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    all_sprites()[type].rect.height = 16;
    all_sprites()[type].rect.width = 16;
    all_sprites()[type].rect.top = 16;
    all_sprites()[type].rect.left = 16;
    sfSprite_setTextureRect(all_sprites()[type].sprite,
    all_sprites()[type].rect);
}

void origin_in_8_8_scale(int sprite)
{
    all_sprites()[sprite].origin.x = 8;
    all_sprites()[sprite].origin.y = 8;
    sfSprite_setOrigin(all_sprites()[sprite].sprite,
    all_sprites()[sprite].origin);
    all_sprites()[sprite].scale.x = 1.4;
    all_sprites()[sprite].scale.y = 1.4;
    sfSprite_setScale(all_sprites()[sprite].sprite,
    all_sprites()[sprite].scale);
}

void full_list_sprites_more_infos(void)
{
    full_perso(HUNTER, 10 * 50, 10 * 35);
    full_perso(DEMON, 500, 240);
    full_perso(NINJA, 700, 1000);
    full_perso(NPC, 900, 1000);
    full_perso(NPC2, 1100, 1200);
    full_perso(NPC3, 1300, 1400);
    origin_in_8_8_scale(EMPTY_BOX);
    origin_in_8_8_scale(CHECK_BOX);
    origin_in_8_8_scale(CROSS_BOX);
    origin_in_8_8_scale(SELEC_BOX);
    origin_in_8_8_scale(APPLE);
    all_sprites()[LIFE].origin.x = 8;
    all_sprites()[LIFE].origin.y = 8;
    sfSprite_setOrigin(all_sprites()[LIFE].sprite, all_sprites()[LIFE].origin);
    all_sprites()[LIFE].scale.x = 3.125;
    all_sprites()[LIFE].scale.y = 3.125;
    sfSprite_setScale(all_sprites()[LIFE].sprite, all_sprites()[LIFE].scale);
    // all_sprites()[BALLON].origin.x = 8;
    // all_sprites()[BALLON].origin.y = 8;
    // sfSprite_setOrigin(all_sprites()[BALLON].sprite, all_sprites()[BALLON].origin);
    // all_sprites()[BALLON].scale.x = 3.125;
    // all_sprites()[BALLON].scale.y = 3.125;
    // sfSprite_setScale(all_sprites()[BALLON].sprite, all_sprites()[BALLON].scale);
}

void full_list_sprites_next(void)
{
    all_sprites()[SPRITE_SHEET].rect.height = 16;
    all_sprites()[SPRITE_SHEET].rect.width = 16;
    all_sprites()[SPRITE_SHEET].rect.top = 16;
    all_sprites()[SPRITE_SHEET].rect.left = 16;
    sfSprite_setTextureRect(all_sprites()[SPRITE_SHEET].sprite,
    all_sprites()[SPRITE_SHEET].rect);
    all_sprites()[SPRITE_SHEET].anim = '\0';
    all_sprites()[SPRITE_SHEET].scale.x = SCALE_TILE_SHEET;
    all_sprites()[SPRITE_SHEET].scale.y = SCALE_TILE_SHEET;
    sfSprite_setScale(all_sprites()[SPRITE_SHEET].sprite,
    all_sprites()[SPRITE_SHEET].scale);
    all_sprites()[BANANA].anim = '\0';
    all_sprites()[BANANA].scale.x = 10;
    all_sprites()[BANANA].scale.y = 10;
    sfSprite_setScale(all_sprites()[BANANA].sprite,
    all_sprites()[BANANA].scale);
    full_list_sprites_more_infos();
}
