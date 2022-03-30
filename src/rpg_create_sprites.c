/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static sprite_pictures *value;

void full_list_sprites_next (void)
{

    value[SPRITE_SHEET].rect.height = 16;
    value[SPRITE_SHEET].rect.width = 16;
    value[SPRITE_SHEET].rect.top = 16;  // 0
    value[SPRITE_SHEET].rect.left = 16; // 0
    sfSprite_setTextureRect(value[SPRITE_SHEET].sprite, value[SPRITE_SHEET].rect);
    value[SPRITE_SHEET].anim = '\0';
    value[SPRITE_SHEET].scale.x = 3.125;
    value[SPRITE_SHEET].scale.y = 3.125;
    sfSprite_setScale(value[SPRITE_SHEET].sprite, value[SPRITE_SHEET].scale);

    value[HUNTER].anim = 'a';
    value[HUNTER].scale.x = 3;
    value[HUNTER].scale.y = 3;
    sfSprite_setScale(value[HUNTER].sprite, value[HUNTER].scale);
    value[HUNTER].pos.y = 1080 / 2;
    value[HUNTER].pos.x = 1920 / 2;
    sfSprite_setPosition(value[HUNTER].sprite, value[HUNTER].pos);
    value[HUNTER].rect.height = 16;
    value[HUNTER].rect.width = 16;
    value[HUNTER].rect.top = 16;
    value[HUNTER].rect.left = 16;
    sfSprite_setTextureRect(value[HUNTER].sprite, value[HUNTER].rect);

    value[GHOST].scale.x = 2.50;
    value[GHOST].scale.y = 2.50;
    sfSprite_setScale(value[GHOST].sprite, value[GHOST].scale);
    value[GHOST].pos.y = 1080 / 2;
    value[GHOST].pos.x = 1920 / 2;
    value[GHOST].anim = '\0';
    sfSprite_setPosition(value[GHOST].sprite, value[GHOST].pos);
    value[GHOST].rect.top = (16 * random_int(0, 3));
    value[GHOST].rect.left = 0;
    value[GHOST].rect.width = 15;
    value[GHOST].rect.height = 15;
    sfSprite_setTextureRect(value[GHOST].sprite, value[GHOST].rect);
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
