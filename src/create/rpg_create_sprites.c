/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static sprite_pictures *value;

void full_perso (int type, int x, int y)
{
    value[type].origin.x = 8;
    value[type].origin.y = 16;
    sfSprite_setOrigin(value[type].sprite, value[type].origin);
    value[type].anim = 'a';
    value[type].scale.x = 3;
    value[type].scale.y = 3;
    sfSprite_setScale(value[type].sprite, value[type].scale);
    value[type].pos.y = y;
    value[type].pos.x = x;
    sfSprite_setPosition(value[type].sprite, value[type].pos);
    value[type].rect.height = 16;
    value[type].rect.width = 16;
    value[type].rect.top = 16;
    value[type].rect.left = 16;
    sfSprite_setTextureRect(value[type].sprite, value[type].rect);
}

void origin_in_8_8_scale(int sprite)
{
    value[sprite].origin.x = 8;
    value[sprite].origin.y = 8;
    sfSprite_setOrigin(value[sprite].sprite, value[sprite].origin);
    value[sprite].scale.x = 1.4;
    value[sprite].scale.y = 1.4;
    sfSprite_setScale(value[sprite].sprite, value[sprite].scale);
}

void full_list_sprites_next (void)
{
    value[SPRITE_SHEET].rect.height = 16;
    value[SPRITE_SHEET].rect.width = 16;
    value[SPRITE_SHEET].rect.top = 16;
    value[SPRITE_SHEET].rect.left = 16;
    sfSprite_setTextureRect(value[SPRITE_SHEET].sprite,
    value[SPRITE_SHEET].rect);
    value[SPRITE_SHEET].anim = '\0';
    value[SPRITE_SHEET].scale.x = SCALE_TILE_SHEET;
    value[SPRITE_SHEET].scale.y = SCALE_TILE_SHEET;
    sfSprite_setScale(value[SPRITE_SHEET].sprite, value[SPRITE_SHEET].scale);
    value[BANANA].anim = '\0';
    value[BANANA].scale.x = 10;
    value[BANANA].scale.y = 10;
    sfSprite_setScale(value[BANANA].sprite, value[BANANA].scale);
    full_perso(HUNTER, 10 * 50, 10 * 35);
    full_perso(DEMON, 500, 240);
    full_perso(NINJA, 700, 1000);
    origin_in_8_8_scale(EMPTY_BOX);
    origin_in_8_8_scale(CHECK_BOX);
    origin_in_8_8_scale(CROSS_BOX);
}

void full_list_sprites (void)
{
    char **arr = filepath_to_arr("pictures/pictures.txt");
    int nbr = my_arraylen(arr), i;
    value = malloc(sizeof(sprite_pictures) * (nbr + 1));
    for (i = 0; arr[i]; i++) {
        value[i].sprite = sfSprite_create();
        value[i].texture = sfTexture_createFromFile(arr[i], NULL);
        sfSprite_setTexture(value[i].sprite, value[i].texture, sfTrue);
        value[i].rect.height = 0;
        value[i].rect.top = 0;
        value[i].rect.left = 0;
        value[i].rect.width = 0;
        value[i].scale.x = 1;
        value[i].scale.y = 1;
        value[i].origin.x = 0;
        value[i].origin.y = 0;
        value[i].pos.x = 0;
        value[i].pos.x = 0;
    }
    full_list_sprites_next();
    free_my_arr(arr);
}

sprite_pictures *all_sprites (void)
{
    return value;
}
